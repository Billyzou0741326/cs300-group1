#include "person.h"


/* ------ Constructors ------ */

// Default Constructor
member::member()
			:current_member(true)
{

}

// Constructor with Args
member::member(string set_name, 
               int set_ID,
               string set_street, 
               string set_city,
               string set_state,
               int set_zip,
               bool set_current_member)
    : person(set_name,
             set_ID,
             set_street,
             set_city,
             set_state,
             set_zip),
             current_member(set_current_member)
{

}

/* ------ Member Functions ------ */


// Display the derived member information in a formatted view - 
// Used for general display purposes. Should always return true as of current.
bool member::display_member()
{
	if(person::display_person())
    {
        cout<< "Valid Member : ";
        (current_member) ? cout << "Yes\n": cout << "No\n";
        return true;
    }

    return false;
}

// Display enumerated derived member information - Used by Mack for editing purposes
// Calls base class display_person_edit before outputting inhereted class information.
// Should always return true as of current.
bool member::display_member_edit()
{
	if(	person::display_person_edit()){
		cout<< "[7] Valid Member : ";
    
		(current_member) ? cout << "Yes\n": cout << "No\n";
	}

	return true;
}

// Copy current member information into the passed in member object
// Calls base class edit, then edits the derived class information. Returns
// true always as of current.
bool member::copy(member & copy_to)
{
    person::copy(copy_to);
    copy_to.current_member = current_member;

	return true;
}

// Alters any found non-zero values from the edit_from object into
// the current member. Currently always returns true
bool member::edit(member & edit_from)
{
    person::edit(edit_from);

    current_member = edit_from.current_member;

    return true;
}

// Checks if the member status. Returns true if current.
bool member::validate()
{
  return current_member;
}

// Saves the member information to the ofstream 'write' variable. 
// Returns true if the superclass save_info is successful, the member
// information is written, and the provider list is written. Otherwise
// returns false.
bool member::save_member(ofstream & write)
{
   if(person::save_info(write))
   {
      write << current_member << "\n";

	    for(it = services.begin(); it != services.end(); ++it){
		    it->save(write);
	    }

	   return true;
   }

   return false;
}

// Loads the member information from the file 'load' into the current
// member. First calls the superclass load_info, then copies data from 
// 'load' into its own members, then needs to call load_person_service_
// record function to finish the load. Returns true if successful, false
// if something went wrong.
bool member::load_member(ifstream & load)
{
	if(person::load_info(load))
	{
		load >> current_member;
        load.ignore(100, '\n');

		for(it = services.begin(); it != services.end(); ++it){
			it ->load(load);
		}
		return true;
	}
	return false;
}

bool member::member_report(ofstream &write) {
	
	if(services.empty()){
		return false;
	}
	it = services.begin();
	if(person::person_report(write)){
		if(!it->weekVerificationWrapper()){
			write <<"NO services this week " << "\n";
		}
		for(it = services.begin(); it != services.end(); ++it){
			if(it ->weekVerificationWrapper()){
				save_member(write);
				it->generateMemberReport(write);
				write << "Valid Member : ";

				(current_member) ? write<< "Yes\n": write<< "No\n";
			}
		}
		return true;
	}
	else{
	return false;
	}
}
