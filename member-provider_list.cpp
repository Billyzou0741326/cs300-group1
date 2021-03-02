// Member and Provider Lists - Class Implementations
// Group 1, ChocAn Project
// Jeffrey Jernstrom
// =============================================================================

#include "member-provider_list.h"
#include "person.h"

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
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      mptr->copy(found);
      return true;  // Success
    }
  }
  return false;  // Fail
}

bool member_list::display_all()
{
  if(mList.empty())
    return false;  // Fail - Empty list

  for(mptr = mList.begin(); mptr != mList.end(); ++mptr)
    //mptr->display_member_basic();

  return true;
}

bool member_list::add_member(member &toadd)
{
  mList.push_front(toadd);

  return true;
  // Not sure this can fail...
}
bool member_list::edit_member(int member_id, member &toupdate)
{
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      mptr->edit(toupdate);
      return true;  // Success
    }
  }
  return false;  // Fail - Empty List / No Match
}

bool member_list::remove_member(int member_id)
{
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      //mList.erase(mptr);  // I think I need a previous ptr or reg list
      return true;  // Success
    } 
  }

  return false;  // Fail - Empty List / No Match
}

int member_list::validate_member(int member_id)
{
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      if(mptr->validate_info(0))  // Don't need to pass member_id
        return 0;  // Validated
      else 
        return 1;  // Not Validated
    }
  }

  return 2; // Fail - Empty List / No Match

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