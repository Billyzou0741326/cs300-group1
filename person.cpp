#include "person.h"

/* ------ Constructors ------ */

// Default Constructor
person::person()
    : name(),
      ID_number(0),
      street_address(),
      city(),
      state(),
      zipcode(0)
{
	services.clear();
	it = services.begin();
}

// Constructor with all Args
person::person(string set_name, 
               int set_ID,
               string set_street, 
               string set_city,
               string set_state,
               int set_zip)
    : name(set_name),
      ID_number(set_ID),
      street_address(set_street),
      city(set_city),
      state(set_state),
      zipcode(set_zip)
{

}

/* ------ Person Functions ------ */

bool person::display_basic()
{
    cout << name << ", " << ID_number << endl;
    return true;

}

// Display the base class information in a formatted view - Used for general display purposes
bool person::display_person()
{
    cout << "Name         : " << name << endl
         << "ID #         : " << ID_number << endl
         << "Address      : " << street_address << ", " << city << ", " << state << ". " << zipcode << endl;
    return true;
}

// Display enumerated base class information - Used by Mack for editing purposes
bool person::display_person_edit()
{
    cout << "[1] Name         : " << name << endl
         << "[2] ID #         : " << ID_number << endl
         << "[3] Street       : " << street_address << endl
         << "[4] City         : " << city << endl
         << "[5] State        : " << state << endl
         << "[6] Zip          : " << zipcode << endl;

		return true;
}

// Copy current member information into the passed in person object
bool person::copy(person & copy_to)
{
    copy_to.name = name;
    copy_to.ID_number = ID_number;
    copy_to.street_address = street_address;
    copy_to.city = city;
    copy_to.state = state;
    copy_to.zipcode = zipcode;
    
    return true;
}

// Compare person ID to passed in ID_to_compare. Return true if match.
bool person::compare(int ID_to_compare)
{
    return ID_number == ID_to_compare;
}

// Edit function: Any fields that aren't default values in the passed in 
// person object overwrite the calling person object values
bool person::edit(person & edit_from)
{
		if(!edit_from.name.empty())
			name = edit_from.name;
		if(edit_from.ID_number)
			ID_number = edit_from.ID_number;
		if(!edit_from.street_address.empty())
			street_address = edit_from.street_address;
		if(!edit_from.city.empty())
			city = edit_from.city;
		if(!edit_from.state.empty())
			state = edit_from.state;
		if(edit_from.zipcode)
			zipcode = edit_from.zipcode;

		return true;
}


// TODO *** in progress *** 
bool person::save_info(ofstream & write)
{
    write << name << ":"
          << ID_number << ":"
          << street_address << ":"
          << city << ":"
          << state << ":"
          << zipcode << ":";

    return true;
}

bool person::save_records(ofstream & write)
{
    // while(auto: list)
    //     list.save(write)

    return true;
}

// TODO *** end of save ***

bool person::load_info(ifstream & load)
{
    char temp[100]; 
    load.getline(temp, 100, ':');
    name = temp;

    load >> ID_number;
    load.get(); // clear buff

    load.getline(temp, 100, ':');
    street_address = temp;

    load.getline(temp, 100, ':');
    city = temp;

    load.getline(temp, 100, ':');
    state = temp;

    load >> zipcode;
    load.get();
    
    return true;
}


bool person::add_service(ServiceRecord to_add) {
    //Figure out return case for false TODO
    //if(to_add != nullptr) {
        services.push_back(to_add);
        return true;
    //} else {
        //return false;
    //}
}

bool person::person_report(ofstream &fstream) {
    //Deal with the return value TODO
    fstream << name << endl;
    fstream << ID_number << endl;
    fstream << street_address << endl;
    fstream << city << endl;
    fstream << state << endl;
    fstream << zipcode << endl;
    return true;
}

string & person::get_name()
{
<<<<<<< HEAD
  return name;
}


=======
    return name;
}
>>>>>>> f66d8e2dddeb4bc42acb9c2a37db2f1e7171fc45




















