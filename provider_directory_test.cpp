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
  Service svc;
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

  res = dir.validateServiceCode(12345, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 12345);

  res = dir.validateServiceCode(12347, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 12347);

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
  Service svc;
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

  res = dir.validateServiceCode(123123, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 123123);
}


void setupProviderDirectory(ProviderDirectory& dir)
{
  std::istringstream input(
      "ServiceCode: 123123\n"
      "ServiceName: 1 name\n"
      "Fees: 70\n"
      "Description: 1 description\n"
      "----\n"
      "ServiceCode: 123456\n"
      "ServiceName: 2 name\n"
      "Fees: 80\n"
      "Description: 2 description\n"
      "----\n"
      "ServiceCode: 123321\n"
      "ServiceName: 3 name\n"
      "Fees: 90\n"
      "Description: 3 description\n"
      "----\n"
      "ServiceCode: 654321\n"
      "ServiceName: 4 name\n"
      "Fees: 100\n"
      "Description: 4 description\n"
      "----\n"
  );
  dir.load(input);
}


TEST(ProviderDirectoryCodeValidateTest, HandleCorrectCode)
{
  ProviderDirectory dir;
  Service svc;
  bool res = false;
  setupProviderDirectory(dir);

  res = dir.validateServiceCode(123123, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 123123);

  res = dir.validateServiceCode(123456, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 123456);

  res = dir.validateServiceCode(123321, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 123321);

  res = dir.validateServiceCode(654321, svc);
  EXPECT_EQ(res, true);
  EXPECT_EQ(svc.getCode(), 654321);
}


TEST(ProviderDirectoryCodeValidateTest, HandleInvalidCode)
{
  ProviderDirectory dir;
  Service svc;
  bool res = false;
  setupProviderDirectory(dir);

  res = dir.validateServiceCode(23498212, svc);
  EXPECT_EQ(res, false);

  res = dir.validateServiceCode(123455, svc);
  EXPECT_EQ(res, false);

  res = dir.validateServiceCode(123311, svc);
  EXPECT_EQ(res, false);

  res = dir.validateServiceCode(754321, svc);
  EXPECT_EQ(res, false);
}


TEST(ProviderDirectorySendToTest, HandleNormal)
{
  ProviderDirectory dir;
  setupProviderDirectory(dir);
  std::ostringstream outStream;
  std::string expected(
      "Service Code: 123123\n"
      "Service Name: 1 name\n"
      "Service Fees: 70\n"
      "Service Description: 1 description\n"
      "\n"
      "Service Code: 123321\n"
      "Service Name: 3 name\n"
      "Service Fees: 90\n"
      "Service Description: 3 description\n"
      "\n"
      "Service Code: 123456\n"
      "Service Name: 2 name\n"
      "Service Fees: 80\n"
      "Service Description: 2 description\n"
      "\n"
      "Service Code: 654321\n"
      "Service Name: 4 name\n"
      "Service Fees: 100\n"
      "Service Description: 4 description\n"
      "\n"
  );

  dir.sendTo(outStream);

  EXPECT_EQ(outStream.str(), expected);
}


TEST(ProviderDirectorySendToTest, FormatFile)
{
  ProviderDirectory dir;
  std::string filename;
  dir.formatProviderDirectory(filename, 123456789);

  std::cout << filename << '\n';
}
