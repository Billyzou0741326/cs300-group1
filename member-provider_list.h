// Member and Provider Lists
#include <vector>
#include <string>
#include "person.h"

class member_list
{
  public:
    member_list();
    ~member_list();

    // Displays a member from the list given a name or ID
    // Returns true for success, false for no match / empty list
    bool display_member(string name);
    bool display_member(int id);

    // Displays the Names and IDs of all the members in the list
    // Returns true for success, false for no match / empty list
    bool display_all();

    // Adds a member to the list
    // Returns true for success, false if a member of the same Name or ID exists
    bool add(member & toadd);

    // Edits a member from the list
    // Returns true for success, false for no match / empty list
    bool edit(member & toupdate);
    
    // Removes a member from the list given a name or ID
    // Returns true for success, false for no match / empty list
    bool remove(string name);
    bool remove(int id);
    
    // Determines if a member in the list has a valid membership
    // given a Name or ID
    // Returns 0 if valid, 1 for invalid, 2 for no match / empty list 
    int validate(string key, int id);

    // Report

    // Accounting Report

    // Save the member list to file with then given filename
    // Returns true for success, false for failure
    bool save_list(string filename);

    // Load the member list from a file with the given filename 
    // Returns true for success, false for bad filename
    bool load_list(string filename);

  private:
    vector member;
};

class provider_list
{
  public:

  private:
    vector provider;
};