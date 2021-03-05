// ProviderDirectory Implementation
// Original author: Billy Zou

#include <sstream>
#include <string>
#include <gtest/gtest.h>
#include "provider_directory.h"


/** HandleCorrectInput
 *
 *  Test for loading correct input
 */
TEST(ProviderDirectoryLoadTest, HandleCorrentInput)
{
  ProviderDirectory dir;
  ProviderDirectory::LoadResult status = ProviderDirectory::Ok;
  bool res = false;
  std::istringstream input(
      "ServiceCode: 12345\n"
      "ServiceName: Sample Service\n"
      "Fees: 47.40\n"
      "Description: Sample Service description\n"
      "----\n"
      "ServiceCode: 12347\n"
      "ServiceName: Sample Service 2\n"
      "Fees: 82.7\n"
      "Description: Sample Service 2 description\n"
      "----\n"
  );

  status = dir.load(input);
  EXPECT_EQ(status, ProviderDirectory::Ok);

  res = dir.validateServiceCode(12345);
  EXPECT_EQ(res, true);

  res = dir.validateServiceCode(12347);
  EXPECT_EQ(res, true);

  EXPECT_EQ(2, dir.size());
}


/** HandleIncompleteInput
 *
 *  Test for graceful failure on incomplete input
 */
TEST(ProviderDirectoryLoadTest, HandleIncompleteInput)
{
  ProviderDirectory dir;
  ProviderDirectory::LoadResult status = ProviderDirectory::Ok;
  std::istringstream input(
      "ServiceCode: 12345\n"
      "ServiceName: SampleService\n"
      "Fees: "
  );

  status = dir.load(input);
  EXPECT_EQ(status, ProviderDirectory::ErrFormat);

  EXPECT_EQ(0, dir.size());
}


/** HandleInvalidFieldName
 * 
 *  Test for graceful failure on invalid field names
 */
TEST(ProviderDirectoryLoadTest, HandleInvalidFieldName)
{
  ProviderDirectory dir;
  ProviderDirectory::LoadResult status = ProviderDirectory::Ok;
  std::istringstream input(
      "ServiceCode: 12345\n"
      "servicename: invalid field name\n"
      "Fees: 12.0\n"
      "Description: Description\n"
      "----\n"
  );

  status = dir.load(input);
  EXPECT_EQ(status, ProviderDirectory::ErrFieldName);
  EXPECT_EQ(0, dir.size());
}


/** HandleInvalidType
 *
 *  Test for graceful failure on invalid type (expecting int, got string)
 */
TEST(ProviderDirectoryLoadTest, HandleInvalidType)
{
  ProviderDirectory dir;
  ProviderDirectory::LoadResult status = ProviderDirectory::Ok;
  std::istringstream input(
      "ServiceCode: invalid\n"
      "ServiceName: Sample Service\n"
      "Fees: invalid\n"
      "Description: Sample Service Description\n"
      "----\n"
  );

  status = dir.load(input);
  EXPECT_EQ(status, ProviderDirectory::ErrDataType);
  EXPECT_EQ(0, dir.size());
}


/** HandleDuplicateServiceCode
 *
 *  Test for conflict resolution on duplicate entries
 */
TEST(ProviderDirectoryLoadTest, HandleDuplicateServiceCode)
{
  ProviderDirectory dir;
  ProviderDirectory::LoadResult status = ProviderDirectory::Ok;
  bool res = false;
  std::istringstream input(
      "ServiceCode: 123123\n"
      "ServiceName: name\n"
      "Fees: 70.0\n"
      "Description: description\n"
      "----\n"
      "ServiceCode: 123123\n"
      "ServiceName: another name\n"
      "Fees: 70.0\n"
      "Description: description\n"
      "----\n"
  );

  status = dir.load(input);
  EXPECT_EQ(status, ProviderDirectory::Ok);
  EXPECT_EQ(1, dir.size());

  res = dir.validateServiceCode(123123);
  EXPECT_EQ(res, true);
}


TEST(ProviderDirectoryCodeValidateTest, HandleCorrectCode)
{
}


TEST(ProviderDirectoryCodeValidateTest, HandleInvalidCode)
{
}


TEST(ProviderDirectorySendToTest, HandleNormal)
{
}
