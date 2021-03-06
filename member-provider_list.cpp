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
    mptr->display_person_basic();  // maybe just display_basic?

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
      //mptr->edit(toupdate);
      return true;  // Success
    }
  }
  return false;  // Fail - Empty List / No Match
}

bool member_list::remove_member(int member_id)
{
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      mList.erase(mptr); // Delete
      return true;  // Success
    } 
  }

  return false;  // Fail - Empty List / No Match
}

int member_list::validate_member(int member_id)
{
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      if(mptr->validate())  // Don't need to pass member_id
        return 0;  // Validated
      else 
        return 1;  // Not Validated
    }
  }

  return 2; // Fail - Empty List / No Match
}

int member_list::save_list(string filename)
{
  ofstream write;
  write.open(filename);

  // Ensure Connection
  if(write) { 
      
    for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
      if(!mptr->save_info(write))
        return false; // Fail - Write error
    }

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
    // 3 fail modes

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

// Provider List Implementation ==================================================

provider_list::provider_list()
{

}

provider_list::~provider_list()
{

}

bool provider_list::retrieve_provider(int provider_id, provider &found)
{
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {
      pptr->copy(found);
      return true;  // Success
    }
  }
  return false;  // Fail
}

bool provider_list::display_all()
{
  if(pList.empty())
    return false;  // Fail - Empty list

  for(pptr = pList.begin(); pptr != pList.end(); ++pptr)
    pptr->display_person_basic();

  return true;
}

bool provider_list::add_provider(provider &toadd)
{
  pList.push_front(toadd);

  return true;
  // Not sure this can fail...
}

bool provider_list::edit_provider(int provider_id, provider &toupdate)
{
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {
      pptr->edit(toupdate);
      return true;  // Success
    }
  }
  return false;  // Fail - Empty List / No Match
}

bool provider_list::remove_provider(int provider_id)
{
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {
      pList.erase(pptr);
      return true;  // Success
    } 
  }

  return false;  // Fail - Empty List / No Match
}

bool provider_list::save_list(string filename)
{
  ofstream write;
  write.open(filename);

  // Ensure Connection
  if(write) { 
      
    for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
      if(!pptr->save_info(write))
        return false; // Fail - Write error
    }

    write.close();  // Close the file
    write.clear();  // Recycle var

    return true;  // Success  
  } 
  return false;  // Fail - File open error
}

bool provider_list::load_list(string filename)
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
    // 3 fail modes

    read.close();  // Close the file
    read.clear();  // Recycle var
    
    return true;  //Success
  }
  
  return false;  // Fail - File open error
}

bool provider_list::generate_provider_report(int provider_id)
{

  return false;
}

bool provider_list::generate_ETF_report() 
{

  return false;
}

bool generate_accounting_report()
{

  return false;
}