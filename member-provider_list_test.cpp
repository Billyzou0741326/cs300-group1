#include <gtest/gtest.h>
#include <string>
#include "person.h"
#include "member-provider_list.h"


void setupList(provider_list& l)
{
  provider p(
      "Provider 1",
      123456789,
      "Street X",
      "Portland",
      "OR",
      97201,
      3,
      900,
      true
  );
  l.add_provider(p);
}


TEST(MemberProviderList, AddProviderTest)
{
  bool found = false;
  provider_list l;
  provider p_result;

  setupList(l);
  found = l.retrieve_provider(123456789, p_result);

  EXPECT_TRUE(found);
  EXPECT_TRUE(p_result.get_name() == std::string("Provider 1")) << "expecting Provider 1, got " << p_result.get_name();
}


TEST(MemberProviderList, DeleteProviderTest)
{
  bool success = false;
  bool found = false;
  provider_list l;
  provider p_result;

  setupList(l);
  success = l.remove_provider(123456789);
  EXPECT_TRUE(success);

  found = l.retrieve_provider(123456789, p_result);
  EXPECT_FALSE(found);
}


TEST(MemberProviderList, EditProviderTest)
{
  bool success = false;
  bool found = false;
  provider_list l;
  provider p_result;
  provider p_edit(
      "Provider 2",
      123456789,
      "Street X",
      "Portland",
      "OR",
      97201,
      3,
      900,
      true
  );

  setupList(l);
  success = l.edit_provider(123456789, p_edit);
  EXPECT_TRUE(success) << ".edit_provider failed";

  found = l.retrieve_provider(123456789, p_result);
  EXPECT_TRUE(found) << ".retrieve_provider reports not found";
  EXPECT_TRUE(p_result.get_name() == p_edit.get_name());
}
