#include "person.h"

/* ------ Constructors ------ */

// Default Constructor
provider::provider()
    : num_consults(0),
      total_fee(0)
{

}

// Constructor with Args
provider::provider(string set_name, 
                   int set_ID,
                   string set_street, 
                   string set_city,
                   string set_state,
                   int set_zip,
                   int set_num_consults,
                   float set_total_fee)
    : person(set_name,
             set_ID,
             set_street,
             set_city,
             set_state,
             set_zip),
      num_consults(set_num_consults),
      total_fee(set_total_fee)
{

}

/* ------ Provider Functions ------ */


// Displays the provider information in a general format.
// Should always return true as of current.
bool provider::display_provider()
{
    person::display_person();
    cout << "# of Consults: " << num_consults << endl
         << "Total Fee    : " << total_fee << endl << endl;

    return true;
}

// Displays the provider information in an enumerated format, 
// used during editing of a provider. Returns true if the display
// of it's superclass is successful, otherwise returns false.
bool provider::display_provider_edit()
{
    if(person::display_person_edit())
    {
        cout << "[7] # of Consult : " << num_consults << endl
             << "[8] Total Fee    : " << total_fee << endl << endl;

        return true;
    }
    return false;
}

// Copies the passed in provider info into the current provider info.
// Returns true if the copy of the superclass and provider inhereted class
// is successful, otherwise returns false.
bool provider::copy(provider & copy_to)
{
    if(person::copy(copy_to))
    {
        copy_to.num_consults = num_consults;
        copy_to.total_fee = total_fee;

        return true;
    }
    return false;
}

// Alters any found non-zero values from the edit_from object into
// the current provider. Currently always returns true.
bool provider::edit(provider & edit_from)
{
    person::edit(edit_from);

    if(edit_from.num_consults != 0)
        num_consults = edit_from.num_consults;
    if(edit_from.total_fee != 0)
        total_fee = edit_from.num_consults;

    return true;
}

// Saves the provider information to the ofstream 'write' variable.
// Returns true if the superclass save_info is successful, the provider
// information is written, and the provider list is written. Otherwise
// returns false
bool provider::save_provider(ofstream & write)
{
    if(person::save_info(write))
    {
        write << num_consults << ":"
              << total_fee << "\n";

        // all service records could start with \t
        // while(auto : list)
        //     list.save(write)

        return true;
    }
    return false;
}

// Loads the provider information from the file 'load' into the current
// provider. It first calls the superclass load_info, then copies the data
// from 'load' into its own members, then needs to call the load_person_
// service_record function to finish the copy. Returns true if successful, 
// false if something went wrong.
bool provider::load_provider(ifstream & load)
{
    char temp[100];

    if(person::load_info(load))
    {
        load >> num_consults;
        load.get();
        load >> total_fee;
        load.get();

        // while(auto : list)
        //     list.load(load) <- while loop iterate over all service records
        return true;
    }
    return false;
}

/*
bool provider::provider_report(ofstream &fstream) {
    bool loopControl = true;
    //Deal with the boolean return value TODO
    person_report(fstream);
    //The iterator that adds the provider information also changes the consults and fee numbers,
    //this might need to change TODO
    for(list<ServiceRecord>::iterator it = services.begin(); it != services.end(); ++it) {
        loopControl = it->generateProviderReport(fstream, num_consults, total_fee);
        if(loopControl == false) {
            break;
        }
    }
    fstream << "Total Number of Consulations: " << num_consults << endl;
    fstream << "Total Fees: " << total_fee << endl;
    return true;
}
*/

