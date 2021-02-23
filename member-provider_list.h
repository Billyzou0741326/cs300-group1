// Member and Provider Lists
#include <vector>
#include <string>
#include "person.h"

class member_list
{
public:
  member_list();
  ~member_list();

  bool retrieve_member(int id, member &found);

  // Displays the Names and IDs of all the members in the list
  // Returns true for success, false for no match / empty list
  bool display_all();

  // Adds a member to the list
  // Returns true for success, false if a member of the same Name or ID exists
  bool add_member(member &toadd);

  bool add_service(int member_id, service_record &toadd);

  // Edits a member from the list
  // Returns true for success, false for no match / empty list
  bool edit(int member_id, member &toupdate);

  // Removes a member from the list given a name or ID
  // Returns true for success, false for no match / empty list
  bool remove(int member_id);

  // Determines if a member in the list has a valid membership
  // given a Name or ID
  // Returns 0 if valid, 1 for invalid, 2 for no match / empty list
  int validate(int member_id);

  // Save the member list to file with then given filename
  // Returns true for success, false for failure
  bool save_list(string filename);

  // Load the member list from a file with the given filename
  // Returns true for success, false for bad filename
  bool load_list(string filename);

  // Member service report
  bool generate_report(int member_id);

private:
  vector member;
};

class provider_list
{
public:
  provider_list();
  ~provider_list();

  bool retrieve_provider(int id, provider &found);

  // Displays the Names and IDs of all the provider in the list
  // Returns true for success, false for no match / empty list
  bool display_all();

  // Adds a member to the list
  // Returns true for success, false if a provider of the same Name or ID exists
  bool add_member(provider &toadd);

  bool add_service(int provider_id, service_record &toadd);

  // Edits a provider from the list
  // Returns true for success, false for no match / empty list
  bool edit(int provider_id, provider &toupdate);

  // Removes a member from the list given a name or ID
  // Returns true for success, false for no match / empty list
  bool remove(int provider_id);

  // Determines if a member in the list has a valid membership
  // given a Name or ID
  // Returns 0 if valid, 1 for invalid, 2 for no match / empty list
  int validate(int provider_id);

  // Save the provider list to file with then given filename
  // Returns true for success, false for failure
  bool save_list(string filename);

  // Load the provider list from a file with the given filename
  // Returns true for success, false for bad filename
  bool load_list(string filename);

  // EFT Report - List of privider name, ID Number, Total Amout Charged for the
  // past seven days. Text file in ETF_Reports directory.
  
  // Accounting Report - List of providers that providing servies in the past
  // seven days. Plus, the number of providers in this list, the total number
  // of consultations, and the total dollar amout for all services provided.
  // Text file in Accounting_Reports directory 

  private:
    vector provider;
};