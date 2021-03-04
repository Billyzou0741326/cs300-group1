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
    person();
    person(string set_name, 
           uint set_ID,
           string set_street, 
           string set_city,
           string set_state,
           uint set_zip);

    bool display();             // Display for testing
		bool display_member();			//Display Formatted for Mack
    bool copy(person & copy_to);        // copy current person into sent in person
    bool compare(uint ID_to_compare);     // compare the ID of number passed in to current person
    bool validate_info(uint ID_number); // checks ID number with member directory and returns status
		bool edit(person & copy_from);      // edit the current member's information



   bool save(string file_name, bool start); // 
   bool add_service(ServiceRecord to_add); // Add services to the person's list of services
   // bool load(string file_name);             // not sure need papa jergson
   // bool save(string file_name, bool start); // I believe this is a duplicate
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
    member();
		member(bool set_current_member);
    ~member();
	
			
		bool display_member(); //display the current members information MACK FORMATTED
		bool display();					//display for testing format
		bool copy(member & copy_to); //copy current person into sent in person
		bool validate_info(uint ID_number); // checks ID number with member directory and returns status
        bool member_report(ofstream &fstream);

    //bool edit();

  protected:
	
    bool current_member;
};


class provider: public person
{
  public:
    provider();
    ~provider();

    bool edit();
    bool provider_report(ofstream &fstream);

  protected:
    uint num_consultations;
    double total_fee;
};
