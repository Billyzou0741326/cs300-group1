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


bool provider::display_provider()
{
    person::display_person();
    cout << "# of Consults: " << num_consults << endl
         << "Total Fee    : " << total_fee << endl << endl;

    return true;
}

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

bool provider::edit(provider & edit_from)
{
    person::edit(edit_from);

    if(edit_from.num_consults != 0)
        num_consults = edit_from.num_consults;
    if(edit_from.total_fee != 0)
        total_fee = edit_from.num_consults;

    return true;
}

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

