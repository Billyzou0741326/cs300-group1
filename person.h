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
        person();                                   // Default Constructor
        person(string set_name,                     // Constructor w/ Args
                uint set_ID,
                string set_street, 
                string set_city,
                string set_state,
                uint set_zip);

        bool display_person();                      // General formatted display
        bool display_person_edit();			        // Display formatted for Mack
        bool copy(person & copy_to);                // Copy current person into sent in person
        bool compare(uint ID_to_compare);           // Compare the ID of number passed in to current person
        bool validate_info(uint ID_number);         // Checks ID number with member directory and returns status
        bool edit(person & copy_from);              // Edit the current member's information


        // TODO
        bool save(string file_name, bool start);    
        bool add_service(ServiceRecord to_add);     // Add services to the person's list of services
        bool person_report(ofstream &fstream);

    protected:
        string name;
        uint ID_number;
        string street_address;
        string city;
        string state;
        uint zipcode;
        list <ServiceRecord> services;
};

class member: public person
{
    public:
        member();                                   // Default Constructor
        member(string set_name,                     // Constructor w/ Args
               uint set_ID,
               string set_street, 
               string set_city,
               string set_state,
               uint set_zip,
               bool set_current_member);
        member(bool set_current_member);            
        ~member();

        bool display_member();					    // General formatted display
        bool display_member_edit();                 // Display formatted for Mack
        bool copy(member & copy_to);                // Copy current member into passed in member
        bool edit(member & edit_from);              // 
        bool validate();                            // Checks the current_member status, returns true if current
        bool member_report(ofstream &fstream);   

    protected:
        bool current_member;
};

class provider: public person
{
    public:
        provider();                                  // Default Constructor
        provider(string set_name,                    // Constructor w/ Args
                uint set_ID,
                string set_street, 
                string set_city,
                string set_state,
                uint set_zip,
                uint set_num_consults,
                float set_total_fee);

        bool display_provider();                     // General formatted display
        bool display_provider_edit();                // Display formatted for Mack
        bool copy(provider & copy_to);               // Copy current provider into the passed in provider
        bool edit(provider & edit_from);             // Updates current provider with information from passed in provider
        bool provider_report(ofstream &fstream);     

    protected:
        uint num_consults;
        float total_fee;
};


