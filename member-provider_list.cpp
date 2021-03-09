// Member and Provider Lists - Class Implementations
// Group 1, ChocAn Project
// Jeffrey Jernstrom
// =============================================================================

#include "member-provider_list.h"

// Testing =====================================================================

/*
int main()
{
  return 0;
}
*/


// General Helper Functions ====================================================

// Return the current date mm-dd-yyyy in string form
//string get_date();
string get_date()
{
  time_t current_time;
  struct tm * timeinfo;
  time(&current_time);
  timeinfo = localtime(&current_time);
  
  string date = to_string(timeinfo->tm_mon + 1) + "-"
              + to_string(timeinfo->tm_mday) + "-"
              + to_string(timeinfo->tm_year + 1900);
  
  return date;
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
  // Find Member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Found!
      mptr->copy(found);  // Copy
      return true;  // Success
    }
  }
  return false;  // Fail - Empty list / no match
}



bool member_list::display_all()
{
  // Check empty
  if(mList.empty())
    return false;  // Fail - Empty list

  // Display all
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr)
    mptr->display_basic(); 

  return true;  // Success
}



bool member_list::add_member(member &toadd)
{
  // Add member
  mList.push_front(toadd);

  return true;  // Success
  // Not sure this can fail...
}



bool member_list::add_service(int member_id, ServiceRecord &toadd)
{
  // Find member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Found!
      mptr->add_service(toadd);  // Add service
      return true;  // Success
    }
  }

  return false;  // Fail - Empty List / No Match
}



bool member_list::edit_member(int member_id, member &toupdate)
{
  // Find member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Found!
      mptr->edit(toupdate);  // Update
      return true;  // Success
    }
  }
  return false;  // Fail - Empty List / No Match
}



bool member_list::remove_member(int member_id)
{
  // Find member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Found!
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
    
  // Find member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Found!
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
  // Open File
  ofstream write;
  write.open(filename);

  // Ensure Connection
  if(write) { 
      
    // Write
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
  // Open File
  ifstream read;
  read.open(filename);
  
  // Ensure Connection
  if(read) {
    member temp;  // Hold data to add to the list

    // Read - How could we get out of this loop in an emergancy? 
    while(temp.load_member(read)) {
      if(!add_member(temp) || read.eof())  // Add to list
        return 1;  // Fail - File read error
    }
    
    read.close();  // Close the file
    read.clear();  // Recycle var
    
    return 0;  //Success
  }

  read.close();
  read.clear();
  
  return 2;  // Fail - File open error
}



int member_list::generate_member_report(int member_id)
{
  // Find Member
  for(mptr = mList.begin(); mptr != mList.end(); ++mptr) {
    if(mptr->compare(member_id)) {  // Match!

      // Generate filename and open file
      string directory = "Member_Reports/";
      string filename = mptr->get_last_name() + "-" + get_date() + ".txt";
      ofstream write;
      write.open(directory + filename);

      // Ensure Connection and write report 
      if(write) { 
      
      // Write Header
      write << "Member Report\n"
            << "Date: " << get_date() << endl
            << "----------------------------------------\n\n";

      // Write Report
      mptr->member_report(write);
      }

      write.close();  // Close the file
      write.clear();  // Recycle var

      return 0;  // Success  
    } 

    return 1;  // Fail - File open error
  }

  return 2;  // Fail - No Match / Empty List
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
  // Find Provider
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Found!
      pptr->copy(found);
      return true;  // Success
    }
  }
  return false;  // Fail - Empty List / No match
}



bool provider_list::display_all()
{
  // Check empty
  if(pList.empty())
    return false;  // Fail - Empty list

  // Display all
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr)
    pptr->display_basic();

  return true;  // Success
}



bool provider_list::add_provider(provider &toadd)
{
  // Add Provider
  pList.push_front(toadd);

  return true;  // Success
  // Not sure this can fail...
}



bool provider_list::add_service(int provider_id, ServiceRecord &toadd)
{
  // Find provider
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Found!
      pptr->add_service(toadd);  // Add service
      return true;  // Success
    }
  }

  return false;  // Fail - Empty List / No Match
}



bool provider_list::edit_provider(int provider_id, provider &toupdate)
{
  // Find provider
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Found!
      pptr->edit(toupdate);  // Update
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
      pList.erase(pptr);  // Delete
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

  // Find provider
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Found!
      if(pptr->validate())
        return 0;  // Validated
      else 
        return 1;  // Not Validated
    }
  }

  return 2; // Fail - Empty List / No Match
}



bool provider_list::save_list(string filename)
{
  // Open File
  ofstream write;
  write.open(filename);

  // Ensure Connection
  if(write) { 
      
    // Write 
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
  // Open File
  ifstream read;
  read.open(filename);
  
  // Ensure Connection
  if(read) {
    provider temp;  // Hold data to add to the list

    // Read
    while(temp.load_provider(read)) {
      if(!add_provider(temp) || read.eof());  // Add to the list
      return 1;  // Fail - File read error
    }
    
    read.close();  // Close the file
    read.clear();  // Recycle var
    
    return 0;  //Success
  }

  read.close();  // Close the file
  read.clear();  // Recycle var
  
  return 1;  // Fail - File open error
}



int provider_list::generate_provider_report(int provider_id)
{
  // Find Provider 
  for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
    if(pptr->compare(provider_id)) {  // Match!

      // Generate filename and open file
      string directory = "Provider_Reports/";
      string filename = pptr->get_last_name() + "-" + get_date() + ".txt";
      ofstream write;
      write.open(directory + filename);

      // Ensure Connection
      if(write) { 

      // Write Header
      write << "Provider Report\n"
            << "Date: " << get_date() << endl
            << "----------------------------------------\n\n";

      // Write Report
      pptr->provider_report(write);
      }

      write.close();  // Close the file
      write.clear();  // Recycle var

      return 0;  // Success  
    } 

    return 1;  // Fail - File open error
  }

  return 2;  // Fail - No Match / Empty List
}



int provider_list::generate_ETF_report() 
{
  // Generate filename and open file
  string directory = "ETF_Reports/";
  string filename = get_date() + "-ETF_Report.txt";
  ofstream write;
  write.open(directory + filename);

  // Ensure Connection and write report 
  if(write) {

    // Write Header
    write << "EFT Report\n"
          << "Date: " << get_date() << endl
          << "----------------------------------------\n\n";

    // Write Report
    for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
      if(!pptr->EFT_report(write))
        return 1;  // Fail - File write error
    }

  }

  write.close();  // Close the file
  write.clear();  // Recycle var
    
  return 0;  // Success 

}



int provider_list::generate_accounting_report()
{
  int total_consult = 0;
  float total_amount = 0;
  int total_providers = 0;

  // Generate filename and open file
  string directory = "Accounting_Reports/";
  string filename = get_date() + "-accounting_report";
  ofstream write;
  write.open(directory + filename);

  if(write) {
    // Write Header Info
    write << "Date: " << get_date() << endl
          << "----------------------------------------\n\n";
    
    // Write Provider Data and update summary info
    for(pptr = pList.begin(); pptr != pList.end(); ++pptr) {
       if(!pptr->accounting_report(write, total_consult, total_amount, 
                                   total_providers))
         return 2;  // Fail - File write error
    }

    // Write Summary Info
    write << "\n\nSummary:\n"
          << "Total number of Providers: " << total_providers << endl
          << "Total number of Consultaions: " << total_consult << endl
          << "Total dollar amout of all Services Provided: $" << total_amount;

    write.close();  // Close the file
    write.clear();  // Recycle var

  }
  return 1;  // Fail - File open error
}