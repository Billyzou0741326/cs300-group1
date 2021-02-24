#include "person.h"

/* ------ Constructors ------ */

// Default Constructor
person::person()
    : name(),
      ID_number(0),
      street_address(),
      city(),
      state(),
      zipcode(0),
      current_member(true)
{

}

// Constructor with all Args
person::person(string set_name, 
               uint set_ID,
               string set_street, 
               string set_city,
               string set_state,
               uint set_zip,
               bool set_current)
    : name(set_name),
      ID_number(set_ID),
      street_address(set_street),
      city(set_city),
      state(set_state),
      zipcode(set_zip),
      current_member(set_current)
{

}

/* copy constructor
person::person(const person & source) 
{
    if(source.name)
    {
        name = source.name;
        ID_number = source.ID_number;
        street_address = source.street_address;
        city = source.city;
        state = source.state;
        zipcode = source.zipcode;
        current_member = source.current_member;
    }
}
*/


/* ------ Person Functions ------ */


bool person::display_member()
{
    cout << "Name   : " << name << endl
         << "ID #   : " << ID_number << endl
         << "Address: " << street_address << ", " << city << ", " << state << " " << zipcode << endl
         << "Valid  : ";

    (current_member) ? cout << "Yes\n\n": cout << "No\n\n";

    return true;
}

// Copy to the passed in person 
bool person::copy(person & copy_to)
{
    copy_to.name = name;
    copy_to.ID_number = ID_number;
    copy_to.street_address = street_address;
    copy_to.city = city;
    copy_to.state = state;
    copy_to.zipcode = zipcode;
    copy_to.current_member = current_member;
    
    return true;
}

bool person::compare(uint ID_to_compare)
{
    return ID_number == ID_to_compare;
}


bool person::validate_info(uint ID_to_validate)
{
    return (ID_to_validate == ID_number) && current_member;
}


/*
bool person::save(string file_name, bool start); 
{
    ofstream outfile(file_name);

    if(start) // if start is true, then we are appending to the file
    {
        if(outfile.open(file_name, ios::app))
        {
            outfile << 
}
*/




















