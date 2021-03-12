#include "person.h"

/* ------ Constructors ------ */

// Default Constructor
provider::provider()
    : num_consults(0),
      total_fee(0),
	  current_provider(true)
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
                   float set_total_fee,
				   bool set_current_provider)
    : person(set_name,
             set_ID,
             set_street,
             set_city,
             set_state,
             set_zip),
      num_consults(set_num_consults),
      total_fee(set_total_fee),
			current_provider(set_current_provider)
{

}

/* ------ Provider Functions ------ */


// Displays the provider information in a general format.
// Should always return true as of current.
bool provider::display_provider()
{
    if(person::display_person())
    {
        cout << "# of Consults: " << num_consults << endl
             << "Total Fee    : " << total_fee << endl
             << "Valid Provider : ";
    
		(current_provider) ? cout << "Yes\n": cout << "No\n";
		cout << endl;
        return true;
    }
    return false;
}

// Displays the provider information in an enumerated format, 
// used during editing of a provider. Returns true if the display
// of it's superclass is successful, otherwise returns false.
bool provider::display_provider_edit()
{
    if(person::display_person_edit())
    {
        cout << "[7] Valid Prov.  : ";

        (current_provider) ? cout << "Yes\n": cout << "No\n" << endl;
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
			copy_to.current_provider = current_provider;

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

    current_provider = edit_from.current_provider;

    return true;
}

bool provider::validate(){
	return current_provider;
};
// Saves the provider information to the ofstream 'write' variable.
// Returns true if the superclass save_info is successful, the provider
// information is written, and the provider list is written. Otherwise
// returns false
bool provider::save_provider(ofstream & write)
{
    if(person::save_info(write))
    {
        write << num_consults << ":"
              << total_fee << ":" 
			  << current_provider <<"\n";

		for(it = services.begin(); it != services.end(); ++it){
			it->save(write);
		}
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
    if(person::load_info(load))
    {
        load >> num_consults;
        load.ignore(100, '\n');
        load >> total_fee;
        load.ignore(100, '\n');
		load >> current_provider;
		load.ignore(100, '\n');

		for(it = services.begin(); it != services.end(); ++it){
			it->load(load);
		}
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

bool provider::provider_report(ofstream & write){
	int numConsultations;
	float totalFees;
	it = services.begin();
	if(person::person_report(write)){
		if(!it->weekVerificationWrapper()){
			write << "No services this week" << "\n";
		}
		for(it = services.begin(); it != services.end(); ++it){
			if(it->weekVerificationWrapper()){
				save_provider(write);
				it->generateProviderReport(write, numConsultations, totalFees);
			}		
		}
		write << "Number of Consultations: " << numConsultations << "\n";
		write << "Total Fees: " << totalFees << "\n";
		return true;
	}
	else{
	return false;
	}
}

bool provider:: accounting_report(ofstream & file, int & consult_total, float & total_amount, int & total_providers){
	it = services.begin();
	if(it ->weekVerificationWrapper()){
		file<< "Name: " << person::name <<"\n";
		file <<"ID: " << person::ID_number <<"\n";
		++total_providers;
	}
	for(it; it != services.end() || !it->accountingReport(consult_total, total_amount); ++it){}
	return 1;
}

bool provider::EFT_report(ofstream & file){
	float total_amount = 0;

	file << "Name: " << person::name <<"\n";
	file <<"ID: " << person::ID_number << "\n";
	for(it = services.begin(); it != services.end()|| !it->EFTReport(total_amount); ++it){}
	file << "Total Fee: " << total_amount << "\n";
	return 1;
}
