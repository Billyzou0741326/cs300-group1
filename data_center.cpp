#include "data_center.h"
using namespace std;


int main(){
    DataCenter dataCenter;
    //dataCenter.providerMenu();
    dataCenter.managerMenu();


    return 0;
}






//Constructors
DataCenter::DataCenter(){
    //call functions of various objects to read in data from save file
    providerOptions = "Menu Options:\n\n";
    providerOptions.append("[1] Verify Member Number\n");
    providerOptions.append("[2] Request Provider Directory\n");
    providerOptions.append("[3] Record Service\n");
    providerOptions.append("[9] Exit\n");
    providerOptions.append("\nEnter the number for your selection");
   
    managerOptions = "Menu Options:\n\n";
    managerOptions.append("[1] Display Members\n");
    managerOptions.append("[2] Display Providers\n");
    managerOptions.append("[3] Manipulate Member List\n");
    managerOptions.append("[4] Manipulate Provider List\n");
    managerOptions.append("[5] Generate Member Report\n");
    managerOptions.append("[6] Generate Provider Report\n");
    managerOptions.append("[7] Generate EFT Report\n");
    managerOptions.append("[8] Generate Accounting Report\n");
    managerOptions.append("[9] Exit\n");
    managerOptions.append("\nEnter the number for your selection");

    currentProviderNumber = -1;
}




//Provider Menu
void DataCenter::providerMenu(){
    int choice = 0;
    int again = 1;
    int retval = 0;
    int var = 0;

    cout << "Welcome to the ChocAn Interactive Terminal" << endl;
    
    UI(var, "Enter your provider number", 9, 9);
/*    do{
        if(!providerList.validate_provider(var)){
            again = 0;
            UI("Successfully validated");
        }
        else{
            UI(var, "Number could not be validated, please try again", 9, 9);
        }
    }while(again);*/
    currentProviderNumber = var;

    again = 1;
    do{
        UI(choice, providerOptions);
        
        switch(choice){

            //Verify Member Number
            case 1:
                UI(var, "Enter member number", 9, 9);
                retval = memberList.validate_member(var);
                if(retval == 0)
                    UI("Validated");
                else{
                    if(retval == 2)
                        UI("Member not found");
                    if(retval == 1)
                        UI("Member suspended");
                }
                break;

            //Request Provider Directory
            case 2:
                UI("2");
                break;

            //Record Service
            case 3:
                recordService();
                break;

            //Exit
            case 9:
                UI("Thanks for using the program.");
                UI("");
                again = 0;
                break;
            default:
                UI("Sorry, I didn't understand your input.");
                break;
        }

    } while(again);

}

//Manager Menu
void DataCenter::managerMenu(){
    int choice = 0;
    int again = 1;
    int retval = 0;
    int var = 0;

    cout << "Welcome to the ChocAn Data Center Interactive Terminal" << endl;

    do{
        UI(choice, managerOptions);
        
        switch(choice){
            //Display Members
            case 1:
                memberList.display_all();
                break;

            //Display Providers
            case 2:
                providerList.display_all();
                break;

            //Manipulate Member List
            case 3:
                manipulateMembers();
                break;

            //Manipulate Provider List
            case 4:
                manipulateProviders();
                break;

            //Member Report
            case 5:
                UI(var, "Enter member number", 9, 9);
                //if(!memberList.generate_member_report(var))
                //    UI("Report generation failure! Check input.");
                //else UI("Report successfully generated.");
                break;

            //Provider Report
            case 6:
                UI(var, "Enter provider number", 9, 9);
                //if(!memberList.generate_provider_report(var))
                //    UI("Report generation failure! Check input.");
                //else UI("Report successfully generated.");
                break;

            //EFT Report
            case 7:
                //if(!providerList.generate_ETF_report())
                //    UI("Record generation failure! Check input.");
                //else UI("EFT record successfully generated.");
                break;

            //Accounting Report
            case 8:
                //if(!providerList.generate_accounting_report())
                //    UI("Report generation failure! Check input.");
                //else UI("Accounting report successfully generated.");
                break;

            //Exit
            case 9:
                UI("Thanks for using the program.");
                UI("");
                again = 0;
                break;

            default:
                UI("Sorry, I didn't understand your input.");
                break;
        }

    } while(again);
}



//Internal Helpers
int DataCenter::manipulateMembers(){
    string options = "Member List Manipulation Options:\n";
    options.append("[1] Add Member\n");
    options.append("[2] Remove Member\n");
    options.append("[3] Edit Member\n");
    options.append("[4] Display Members\n");
    options.append("[9] Back");

    int choice = 9;
    int again = 1;

    do{
        UI(choice, options);

        switch(choice){
            //Add Member
            case 1:
                createPerson(1);
                break;
            //Remove Member
            case 2:
                removePerson(1);
                break;
            //Edit Member
            case 3:
                editMember();
                break;
            //Display Members
            case 4:
                memberList.display_all();
                break;
            //Back
            case 9:
                again = 0;
                break;
            default:
                UI("Sorry, I didn't understand your input.");
                break;
        }
    }while(again);

    return 1;
}

int DataCenter::manipulateProviders(){
    string options = "Provider List Manipulation Options:\n";
    options.append("[1] Add Provider\n");
    options.append("[2] Remove Provider\n");
    options.append("[3] Edit Provider\n");
    options.append("[4] Display Providers\n");
    options.append("[9] Back");

    int choice = 9;
    int again = 1;

    do{
        UI(choice, options);

        switch(choice){
            //Add Provider
            case 1:
                createPerson(0);
                break;
            //Remove Provider 
            case 2:
                removePerson(0);
                break;
            //Edit Provider
            case 3:
                editProvider();
                break;
            //Display Provider
            case 4:
                providerList.display_all();
                break;
            //Back
            case 9:
                again = 0;
                break;
            default:
                UI("Sorry, I didn't understand your input.");
                break;
        }
    }while(again);

    return 1;
}

//Prompt user for information about a new person. Type refers
//to member vs provider, provider = 0, member = 1
int DataCenter::createPerson(int type){
    int check = 0;

    string name;
    int ID = 0;
    string address;
    string city;
    string state;
    int zip = 0;

    UI(name, "Name");

    //Prompt for number and verify it isn't taken
    UI(ID, "ChocAn ID Number", 9, 9);
    check = memberList.validate_member(ID);
    while(check == 0 || check == 1){
        UI(ID, "That ID is already taken, enter another", 9, 9);
        check = memberList.validate_member(ID);
    }

    UI(address, "Street Address");
    UI(city, "City");
    UI(state, "State");
    UI(zip, "Zip Code", 5, 5);



//TODO catch failures
    //If member
    if(type == 1){
        member thing(name, ID, address, city, state, zip, true);
        memberList.add_member(thing);
    }

    //If provider
    if(type == 0){
        provider thing(name, ID, address, city, state, zip, 0, 0, true);
        providerList.add_provider(thing);
    }

    return 1;
}

//Prompt user for ID number and initiate removal from appropriate list
//provider = 0, member = 1
int DataCenter::removePerson(int type){
    int ID = 0;

    //Provider
    if(type == 0){
        UI(ID, "Enter Provider ID", 9, 9);
        if(!providerList.remove_provider(ID)){
            UI("No matching provider found.");
        }
        else UI("Provider successfully removed.");
    }

    //Member
    if(type == 1){
        UI(ID, "Enter Member ID", 9, 9);
        if(!memberList.remove_member(ID)){
            UI("No matching member found.");
        }
        else UI("Member successfully removed.");
    }

    return 1;
}

//Prompt user for ID number and allow them to edit whatever
//fields they like. For providers. 
int DataCenter::editProvider(){
    int oldID = 0;
    provider prov;

    UI(oldID, "Enter Provider ID", 9, 9);
    if(!providerList.retrieve_provider(oldID, prov)){
        UI("No matching provider found.");
        return 0;
    }

    string name;
    int ID = 0;
    string address;
    string city;
    string state;
    int zip = 0;

    int choice = 0;
    int again = 1;
    do{
        prov.display_provider_edit();
        cout << "[9] Save and close" << endl;
        UI(choice, "Enter the number of the field you'd like to edit");
        
        switch(choice){

            //Edit name
            case 1:
                UI(name, "Enter new name");
                break;

            //Edit ID
            case 2:
                UI(ID, "Enter new ID", 9, 9);
                int check = 0;
                check = providerList.validate_provider(ID);
                while(check == 0 || check == 1){
                    UI(ID, "That ID is already taken, enter another", 9, 9);
                    check = providerList.validate_provider(ID);
                }
                break;

            //Street Address
            case 3:
                UI(address, "Enter new address");
                break;

            //City
            case 4:
                UI(city, "Enter new city");
                break;

            //State
            case 5:
                UI(state, "Enter new state");
                break;

            //Zip
            case 6:
                UI(zip, "Enter new zip", 5, 5);
                break;

            //Save and close
            case 9:
                again = 0;
                break;

            default:
                UI("Sorry, I didn't understand that");
                break;
        }
    }while(again);
        
    provider edited(name, ID, address, city, state, zip, 0, 0, true);
    providerList.edit_provider(oldID, edited);
    
    return 1;
}


//Prompt user for ID number and allow them to edit whatever
//fields they like. For members.
int DataCenter::editMember(){
    int oldID = 0;
    member memb;

    UI(oldID, "Enter Member ID", 9, 9);
    if(!memberList.retrieve_member(oldID, memb)){
        UI("No matching member found.");
        return 0;
    }

    string name;
    int ID = 0;
    string address;
    string city;
    string state;
    int zip = 0;
    bool status = true;

    int choice = 0;
    int again = 1;
    char statusChoice = 'Y';
    do{
        memb.display_member_edit();
        cout << "[9] Save and close" << endl;
        UI(choice, "Enter the number of the field you'd like to edit");
        
        switch(choice){

            //Edit name
            case 1:
                UI(name, "Enter new name");
                break;

            //Edit ID
            case 2:
                UI(ID, "Enter new ID", 9, 9);
                int check = 0;
                check = memberList.validate_member(ID);
                while(check == 0 || check == 1){
                    UI(ID, "That ID is already taken, enter another", 9, 9);
                    check = memberList.validate_member(ID);
                }
                break;

            //Street Address
            case 3:
                UI(address, "Enter new address");
                break;

            //City
            case 4:
                UI(city, "Enter new city");
                break;

            //State
            case 5:
                UI(state, "Enter new state");
                break;

            //Zip
            case 6:
                UI(zip, "Enter new zip");
                break;

            //Membership Status
            case 7:
                UI(statusChoice, "Are they a current member? (y\n)");
                statusChoice = toupper(statusChoice);
                if(statusChoice == 'N') status = false;
                break;

            //Save and close
            case 9:
                again = 0;
                break;

            default:
                UI("Sorry, I didn't understand that");
                break;
        }
    }while(again);
        
    member edited(name, ID, address, city, state, zip, status);
    memberList.edit_member(oldID, edited);

    return 1;
}



int DataCenter::recordService(){
    int memberNumber = 0;
    string date;
    int serviceCode = 0;
    char confirm = 'N';
    string comments;
    
    UI(memberNumber, "Please enter member number", 9, 9);
    //validate number TODO
    UI(date, "Enter date of service (MM-DD-YYYY)");
    
    //input and verify service code by displaying name
    while(confirm != 'Y'){
        UI(serviceCode, "Enter six digit service code", 6, 6);
        //special message for non-existent service TODO
        UI(confirm, "You provided: [service name]? (y/n)");
        confirm = toupper(confirm);
    }

    UI(confirm, "Would you like to enter comments? (y/n)");
    confirm = toupper(confirm);
    if(confirm == 'Y'){
        UI(comments, "Enter comments (up to 100 characters)", 100);
    }


    //Create and populate service record object TODO
    //I have a constructor that will accept all the necessary
    //data in order to create a service record object. Here is the function prototype:
    //ServiceRecord(string dateOfService, int providerNumber, int memberNumber, int serviceCode, string comments, string providerName, string memberName, string serviceName, double fees)
    //I will populate the time of record creation in the contructor. BTW this is Bennett


    UI("Service Successfully Recorded!");

    return 1;
}




//UI Helper Functions
void DataCenter::UIPrompt(string prompt, int flag = 1){
    cout << "-------------------------------------" << endl
         << prompt << endl;
    if(flag) cout << " > ";
}

void DataCenter::UI(string & str, string prompt, int max){
    UIPrompt(prompt);
    getline(cin, str);
    if(max){
        while(str.length() > max){
            cout << "Input too large, max acceptable: " << max << endl;
            cout << "Please try again: ";
            getline(cin, str);
        }
    }
}

void DataCenter::UI(int & num, string prompt, int max, int min){
    UIPrompt(prompt);
    cin >> num;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input error, please try again: ";
        cin >> num;
    }
    cin.ignore(100, '\n');

    if(min || max){
        string test = to_string(num);
        while((min && test.length() < min) || (max && test.length() > max)){
            if(min){
                if(test.length() < min)
                    cout << "Input to short, minimum acceptable: " << min << endl;
            }
            if(max){
                if(test.length() > max)
                    cout << "Input too long, max acceptable: " << max << endl;
            }
            cout << "Please try again: ";
            cin >> num;
            while(cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Input error, please try again: ";
                cin >> num;
            }
            cin.ignore(100, '\n');
            test = to_string(num);
        }
    }

}

void DataCenter::UI(char & value, string prompt){
    UIPrompt(prompt);
    cin >> value;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input error, please try again: ";
        cin >> value;
    }
    cin.ignore(100, '\n');
}

void DataCenter::UI(string prompt){
    UIPrompt(prompt, 0);
}
