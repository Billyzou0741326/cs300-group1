// Member and Provider Lists - Class Implementations
// Group 1, ChocAn Project
// Jeffrey Jernstrom
// =============================================================================

#include "member-provider_list.h"

// Testing =====================================================================

int main()
{
  return 0;
}

// Member List Implementation ==================================================

member_list::member_list()
{

}

member_list::~member_list()
{

}

bool member_list::retrieve_member(int member_id, member &found)
{
  for (int i = 0; i <= mList.size(); ++i) {
    if (i == member_id) {
      // mList[i].copy(found);
      return true;
    }
  }
  
  return false;
}

bool member_list::display_all()
{

  return false;
}

bool member_list::add_member(member &toadd)
{

  return false;
}
bool member_list::edit_member(int member_id, member &toupdate)
{

  return false;
}

bool member_list::remove_member(int member_id)
{

  return false;
}

int member_list::validate_member(int member_id)
{

  return 2;
}

int member_list::save_list(string filename)
{
  ofstream write;
  write.open(filename);

  // Ensure Connection
  if(write) { 
    /*  
    for(it = mlist.begin(); mit != mlist.end(); ++it) {
      if(!it->save(write))
        return false; // Fail - Write error
    }
    */

    write.close();  // Close the file
    write.clear();  // Recycle var

    return true;  // Success  
  } 
  return false;  // Fail - File open error
}

bool member_list::load_list(string filename)
{
  ifstream read;
  read.open(filename);
  
  // Ensure Connection
  if(read) {
    member temp;

    /*
    while(temp.load(read)) {
      mlist.add_member(temp);
    }
    */

    read.close();  // Close the file
    read.clear();  // Recycle var
    
    return true;  //Success
  }
  
  return false;  // Fail - File open error
}

bool generate_member_report(int member_id)
{
  return false;
}

// Provider List Implementation ================================================