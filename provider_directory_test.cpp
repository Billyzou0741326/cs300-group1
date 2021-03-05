#include <sstream>
#include <string>
#include <gtest/gtest.h>
#include "provider_directory.h"


TEST(ProviderDirectoryLoadTest, HandleCorrentInput)
{
  ProviderDirectory dir;
  bool status = false;
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
  EXPECT_EQ(status, true);

  status = dir.validateServiceCode(12345);
  EXPECT_EQ(status, true);

  status = dir.validateServiceCode(12347);
  EXPECT_EQ(status, true);
}


TEST(ProviderDirectoryLoadTest, HandleIncompleteInput)
{
  ProviderDirectory dir;
  bool status = false;
  std::istringstream input(
      "ServiceCode: 12345\n"
      "ServiceName: SampleService\n"
      "Fees: "
  );

  status = dir.load(input);
  EXPECT_EQ(status, false);
}


TEST(ProviderDirectoryLoadTest, HandleInvalidFieldName)
{
  ProviderDirectory dir;
  bool status = false;
  std::istringstream input(
      "ServiceCode: 12345\n"
      "servicename: invalid field name\n"
      "Fees: 12.0\n"
      "Description: Description\n"
      "----\n"
  );

  status = dir.load(input);
  EXPECT_EQ(status, false);
}


TEST(ProviderDirectoryLoadTest, HandleInvalidType)
{
  ProviderDirectory dir;
  bool status = false;
  std::istringstream input(
      "ServiecCode: invalid\n"
      "ServiceName: Sample Service\n"
      "Fees: invalid\n"
      "Description: Sample Service Description\n"
      "----\n"
  );

  status = dir.load(input);
  EXPECT_EQ(status, false);
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
