#include <string>
#include <vector>


class person
{
  public:
    person();
    virtual ~person();

    int validate_info(int ID_number); //checks ID number with member directory and returns status
    virtual bool edit() = 0; //edit this info

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
    ~member();

    bool edit();

  protected:
    vector </*service record*/> member_services;
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
    vector </*service record*/> provider_services;
};
