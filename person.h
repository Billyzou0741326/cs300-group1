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
           uint set_zip,
           bool set_current);

    bool display_member();             // fill out later, this display for mack specific
    bool copy(person & copy_to);        // copy current person into sent in person
    bool compare(uint ID_to_compare);     // compare the ID of number passed in to current person
    bool validate_info(uint ID_number); // checks ID number with member directory and returns status
   // virtual bool edit() = 0;          // edit the current member's information


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
    bool current_member;
};

/*
class member: public person
{

  public:
    member();
    ~member();

    bool edit();

  protected:
};

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
