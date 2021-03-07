#include "person.h"

/* ------ Constructors ------ */

// Default Constructor
provider::provider()
    : num_consults(0),
      total_fee(0),
			current_provider(0)
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
    person::display_person();
    cout << "# of Consults: " << num_consults << endl
         << "Total Fee    : " << total_fee << endl;

		cout<< "Valid Provider : ";
    
		(current_provider) ? cout << "Yes\n\n": cout << "No\n\n";
		cout << endl;

    return true;
}

// Displays the provider information in an enumerated format, 
// used during editing of a provider. Returns true if the display
// of it's superclass is successful, otherwise returns false.
bool provider::display_provider_edit()
{
<<<<<<< HEAD
  if(person::display_person_edit())
  {  
    cout << “[7] Valid Prov. : “;
    (current_provider) ? cout << “Yes\n\n”: cout << “No\n\n” << endl;
    return true;
  }  
  return false;
=======
    if(person::display_person_edit())
    {
        cout << "[7] Valid Prov.  : ";
    
        (current_provider) ? cout << "Yes\n\n": cout << "No\n\n" << endl;
        return true;
    }
    return false;
>>>>>>> f66d8e2dddeb4bc42acb9c2a37db2f1e7171fc45
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
				load >>current_provider;
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

bool provider::provider_report(ofstream & write){
	//TODO "No services available for this week" message 
/*
	for(it = services.begin(); it != services.end; ++it){
		if(it->verify_date()){
			save_provider(write);
			it->generate_service_report(write);
		}		
	}
	*/
}

bool provider:: accounting_report(ofstream & file, int & consult_total, float & total_amount, int & total_providers){
	for(it = services.begin(); it != services.end(); ++it){
		if(true/*it->verify_date()*/){
			file>> "Name: " >> name >>"\n";
			file.get();
			file >>"ID: " >> ID_number >>"\n";
			file.get();
			total_amount += /*it->get_fee()*/ 0;
			++consult_total;
		}
		++total_providers;
		return 1;
	}
	return 1;
}


bool EFT_report(ofstream & file){
	
			file>> "Name: " >> name >>"\n";
			file.get();
			file >>"ID: " >> ID_number >>"\n";
			file.get();
	for(it = services.begin(); it != services.end(); ++it){
		if(/*it->verify_date()*/true){
			total_amount += /*it->get_fee()*/ 0;
		}
	}
		file >> "Total Fee: " << total_amount << "\n";
		file.get();
		return 1;
}
