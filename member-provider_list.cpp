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
  // I don't think these steps are nessesarry, but I'm in the habit of
  // initializing class data members in the constructor.
  mList.clear();
  mptr = mList.begin();
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
    mptr->display_basic();  // maybe just display_basic?

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
  // Check member_id bounds
  if (member_id < 0 || member_id > 999999999)
    return 3;  // Fail - member_id out of range
    
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {
      if(mptr->validate()) 
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



int member_list::load_list(string filename)
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



int member_list::generate_member_report(int member_id)
{
  // Find Member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Match!

      //TODO: generate filename
      // Generate filename and open file
      string filename = "addFileName";
      ofstream write;
      write.open(filename);

      // Ensure Connection and write report 
      if(write) { 
      //TODO: generate header info
      write << "Header Info";
      mptr->member_report(write);
      }

      write.close();  // Close the file
      write.clear();  // Recycle var

      return 0;  // Success  
    } 

    return 1;  // Fail - File open error
  }

  return 2;  // Fail - No match
}

 

// Provider List Implementation ==================================================

provider_list::provider_list()
{
  // I don't think these steps are nessesarry, but I'm in the habit of
  // initializing class data members in the constructor.
  pList.clear();
  pptr = pList.begin();
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
    pptr->display_basic();

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
  // Find provider
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Found!
      // Edit provider
      pptr->edit(toupdate);
      return true;  // Success
    }
  }
  return false;  // Fail - Empty List / No Match
}



bool provider_list::remove_provider(int provider_id)
{ 
  // Find provider  
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Found!
      // Remove provider
      pList.erase(pptr);
      return true;  // Success
    } 
  }

  return false;  // Fail - Empty List / No Match
}
 


int provider_list::validate_provider(int provider_id)
{
  // Check provider_id bounds
  if (provider_id < 0 || provider_id > 999999999)
    return 3;  // Fail - provider_id out of range

  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {
      // Tell Kevin/Nicki to add this
      //if(pptr->validate())
      if(true)
        return 0;  // Validated
      else 
        return 1;  // Not Validated
    }
  }

  return 2; // Fail - Empty List / No Match
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



int provider_list::load_list(string filename)
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



int provider_list::generate_provider_report(int provider_id)
{
  // Find Provider 
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Match!

      //TODO: generate filename
      // Generate filename and open file
      string directory = "Provider_Reports/";
      string filename = "addFilename";
      ofstream write;
      write.open(directory + filename);

      // Ensure Connection and write report 
      if(write) { 
      //TODO: generate header info
      write << "Header Info";
      // pptr->provider_report(write);
      }

      write.close();  // Close the file
      write.clear();  // Recycle var

      return 0;  // Success  
    } 

    return 1;  // Fail - File open error
  }

  return 2;  // Fail - No match / empty list
}



bool provider_list::generate_ETF_report() 
{

  return false;
}



bool provider_list::generate_accounting_report()
{
  int consult_total = 0;
  float total_amout = 0;
  int total_providers = 0;

  //TODO: generate filename
  // Generate filename and open file
  string directory = "Accounting_Reports/";
  string filename = "addFilename";
  ofstream write;
  write.open(directory + filename);

  if(write) {
    write << "Header Info";
    
    for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
       pptr->accounting_report(write, consult_total, total_amout, total_providers);
    }

    write << "Summery Inteview"; 
  }
  return false;
}