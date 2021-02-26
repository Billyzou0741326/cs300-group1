#include <iostream>
#include <string>
#include <fstream>

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
   // bool add_service(service_record to_add); // can't do this without Bennett 
   // bool load(string file_name);             // not sure need papa jergson
   // bool save(string file_name, bool start); // 
    

  protected:
    string name;
    uint ID_number;
    string street_address;
    string city;
    string state;
    uint zipcode;
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

    //bool edit();

  protected:
	
    bool current_member;
};

/*
class provider: public person
{
  public:
    provider();
    ~provider();

    bool edit();

  protected:
    uint num_consultations;
    uint total_fee;
};

*/
