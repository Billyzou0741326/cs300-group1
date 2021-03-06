#include "person.h"

member::member()
			:current_member(true)
{

}

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

member::member(bool set_current_member)
			:current_member(set_current_member)
{
}


// Display the derived member information in a formatted view - Used for general display purposes
// Calls base class display then outputs inhereted class information
bool member::display_member()
{

	person::display_person();
	cout<< "Valid Member : ";
    
	(current_member) ? cout << "Yes\n\n": cout << "No\n\n";
	return true;
}

// Display enumerated derived member information - Used by Mack for editing purposes
// Calls base class display_person_edit before outputting inhereted class information
bool member::display_member_edit()
{
	person::display_person_edit();
	cout<< "[7] Valid Member : ";
    
	(current_member) ? cout << "Yes\n\n": cout << "No\n\n";

	return true;
}


// Copy current member information into the passed in member object
// Calls base class edit, then edits the derived class information
bool member::copy(member & copy_to)
{
    person::copy(copy_to);
    copy_to.current_member = current_member;

	return true;
}

// Checks if the member status. Returns true if current
bool member::validate()
{
  return current_member;
}

bool member::save_info(ofstream & write)
{
   if(person::save_info(write))
   {
       write << current_member << "\n";

       // for(auto : list)
       //     list.save_info(write)
       return true;
   }

   return false;
}


bool member::member_report(ofstream &fstream) {
    bool loopControl = true;
    //Deal with the boolean return value TODO
    person_report(fstream);
    for(list<ServiceRecord>::iterator it = services.begin(); it != services.end(); ++it) {
        loopControl = it->generateMemberReport(fstream);
        if(loopControl == false) {
            break;
        }
    }
    return false;
}
