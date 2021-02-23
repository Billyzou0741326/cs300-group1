// Member and Provider Lists
#include <vector>
#include <string>
#include "person.h"

class member_list
{
public:
  member_list();
  ~member_list();

  // Searches for a member with the given ID and if found populates the
  // member object passed to the function
  // Returns true for success, false for no match / empty list
  bool retrieve_member(int id, member &found);

  // Displays the Names and IDs of all the members in the list
  // Returns true for success, false for no match / empty list
  bool display_all();

  // Adds a member to the list
  // Returns true for success, false if a member of the same ID exists -
  // nothing is added
  bool add_member(member &toadd);

  // Adds a service record to a member in the list with the given ID
  // Returns 0 for success, 1 for no match / empty list, 2 if a service record
  // with the same ID exist - nothing is added
  bool add_service(int member_id, service_record &toadd);

  // Replaces a member from the list
  // Returns true for success, false for no match / empty list
  bool edit(int member_id, member &toupdate);

  // Removes a member from the list given a member ID
  // Returns true for success, false for no match / empty list
  bool remove(int member_id);

  // Determines if a member in the list has a valid membership given an ID
  // Returns 0 if valid, 1 for invalid, 2 for no match / empty list
  int validate(int member_id);

  // Save the member list to file with the given filename
  // Returns true for success, false for failure
  bool save_list(string filename);

  // Load the member list from a file with the given filename
  // Returns true for success, false for bad filename
  bool load_list(string filename);

  // Member service report - List of a member's service record for the past 
  // seven days. Creates a text file in Member_Reports directory.
  // Returns true for success, false otherwise.
  bool generate_report(int member_id);

private:
  vector member;

};

class provider_list
{
public:
  provider_list();
  ~provider_list();

  // Searches for a provider with the given ID and if found populates the
  // provider object passed to the function
  // Returns true for success, false for no match / empty list
  bool retrieve_provider(int provider_id, provider &found);

  // Displays the Names and IDs of all the providers in the list
  // Returns true for success, false for empty list
  bool display_all();

  // Adds a provider to the list
  // Returns true for success, false if a provider of the same ID exists - 
  // nothing is added
  bool add_provider(provider &toadd);

  // Adds a service record to a provider in the list with the given ID
  // Returns 0 for success, 1 for no match / empty list, 2 if a service record
  // of the same ID exist - nothing is added
  bool add_service(int provider_id, service_record &toadd);

  // Replaces a provider from the list
  // Returns true for success, false for no match / empty list
  bool edit_provider(int provider_id, provider &toupdate);

  // Removes a provider from the list with the given ID
  // Returns true for success, false for no match / empty list
  bool remove_provider(int provider_id);

  // Save the provider list to file with the given filename
  // Returns true for success, false for failure
  bool save_list(string filename);

  // Load the provider list from a file with the given filename
  // Returns true for success, false for bad filename
  bool load_list(string filename);

  // EFT Report - List of privider names, ID Numbers, Total Amout Charged for
  // the past seven days 
  // Creates a text file in ETF_Reports directory.
  // Returns true for success, false otherwise.
  bool generate_ETF_report();
  
  // Accounting Report - List of providers having provided services in the past
  // seven days plus the number of providers in this list, the total number
  // of consultations, and the total dollar amount for all services provided.
  // Creates a text file in Accounting_Reports directory 
  // Returns true for success, false otherwise
  bool generate_accounting_report();

private:
  vector provider;

};