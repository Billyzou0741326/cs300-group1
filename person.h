#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include "service_record.h"

using namespace std;

class person
{
    public:
        person();                                    // Default Constructor
        person(string set_name,                      // Constructor w/ Args
                int set_ID,
                string set_street, 
                string set_city,
                string set_state,
                int set_zip);

        bool display_basic();                        // Displays name & ID_number
        bool display_person();                       // General formatted display
        bool display_person_edit();			         // Display formatted for Mack
        bool copy(person & copy_to);                 // Copy current person into sent in person
        bool compare(int ID_to_compare);             // Compare the ID of number passed in to current person
        bool edit(person & copy_from);               // Edit the current member's information  
        bool save_info(ofstream & write);            // Write out all person info to file 'write'
        bool save_records(ofstream & write);         // Write out all service records to file 'write' 
        bool load_info(ifstream & load);             // Load info into current member from file 'read'
				
		string & get_name();												//return the name as a string	
		string get_last_name();
        // Need to be looked at
        // bool load_records(ofstream & load)        // Load info into current member services list
        bool add_service(ServiceRecord to_add);      // Add services to the person's list of services
        bool person_report(ofstream &fstream);

    protected:
        string name;
        int ID_number;
        string street_address;
        string city;
        string state;
        int zipcode;
        list <ServiceRecord> services;
		list <ServiceRecord>::iterator it;
};

class member: public person
{
    public:
        member();                                    // Default Constructor
        member(string set_name,                      // Constructor w/ Args
               int set_ID,
               string set_street, 
               string set_city,
               string set_state,
               int set_zip,
               bool set_current_member);
        member(bool set_current_member);            

        bool display_member();					     // General formatted display
        bool display_member_edit();                  // Display formatted for Mack
        bool copy(member & copy_to);                 // Copy current member into passed in member
        bool edit(member & edit_from);               // Updates current member with information from passed in member
        bool validate();                             // Checks the current_member status, returns true if current
        bool save_member(ofstream & write);          // Write out all provider info to file 'write'
        bool load_member(ifstream & load);           // Load values from file 'load' into current member

        bool member_report(ofstream &fstream);      

    protected:
        bool current_member;
};

class provider: public person
{
    public:
        provider();                                  // Default Constructor
        provider(string set_name,                    // Constructor w/ Args
                int set_ID,
                string set_street, 
                string set_city,
                string set_state,
                int set_zip,
                int set_num_consults,
                float set_total_fee,
                bool set_current_provider);

        bool display_provider();                     // General formatted display
        bool display_provider_edit();                // Display formatted for Mack
        bool copy(provider & copy_to);               // Copy current provider into the passed in provider
        bool edit(provider & edit_from);             // Updates current provider with information from passed in provider

        bool validate();                             // , returns true if current
        bool save_provider(ofstream & write);        // Write out all provider info to file 'write'
        bool load_provider(ifstream & load);         // Load values from file 'load' into the current provider

        // Need to be looked at
        bool provider_report(ofstream &fstream);    
        bool accounting_report(ofstream & file, int & consult_total, float & total_amount, int & total_providers);  // note for us
				bool EFT_report(ofstream & file);						//write provider name and ID and the total amount charged to file

    protected:
        int num_consults;
        float total_fee;
        bool current_provider;
};

#endif 
