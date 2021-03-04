#include "person.h"

member::member()
			:current_member(true)
{
}

member::member(bool set_current_member)
			:current_member(set_current_member)
{
}

member::~member()
{
}

bool member::display_member()
{
	person::display_member();
	cout<< "[4] Valid  : ";
    
	(current_member) ? cout << "Yes\n\n": cout << "No\n\n";
	return true;
}

bool member::display()
{

	person::display();
	cout<< "Valid  : ";
    
	(current_member) ? cout << "Yes\n\n": cout << "No\n\n";
	return true;
}

bool member::copy(member & copy_to)
{
	person::copy(copy_to);
  copy_to.current_member = current_member;

	return true;
}

bool member::validate_info(uint ID_to_validate)
{
  return (ID_to_validate == ID_number) && current_member;
}

bool member::member_report(ofstream &fstream) {
    bool loopControl = true;
    //Deal with the boolean return value TODO
    person_report(fstream);
    for(list<ServiceRecord>::iterator it = services.begin(); it != services.end(); ++it) {
        loopControl = it->generateMemberReport(fstream);
        if(loopControl == false) {
            break;
        }
    }
    return false;
}
