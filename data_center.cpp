#include "data_center.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
int main(){
    DataCenter dataCenter;
    dataCenter.providerMenu();
    //dataCenter.managerMenu();
    return 0;
}*/






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
    managerOptions.append("[1] Manipulate Member List\n");
    managerOptions.append("[2] Manipulate Provider List\n");
    managerOptions.append("[3] Generate Member Report\n");
    managerOptions.append("[4] Generate Provider Report\n");
    managerOptions.append("[5] Generate EFT Report\n");
    managerOptions.append("[6] Generate Accounting Report\n");
    managerOptions.append("[9] Exit\n");
    managerOptions.append("\nEnter the number for your selection");

}




//Provider Menu
void DataCenter::providerMenu(){
    int choice = 0;
    int again = 1;

    cout << "Welcome to the ChocAn Interactive Terminal" << endl;

    do{
        UI(choice, providerOptions);
        
        switch(choice){
            //Verify Member Number
            case 1:
                UI(var, "Enter member number");
                retval = memberList.validate_member(var);
                if(retval == 0)
                    UI("Validated");
                else{
                //Could add a case for an invalid number i.e. >/< 9 digits
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

    cout << "Welcome to the ChocAn Data Center Interactive Terminal" << endl;

    do{
        UI(choice, managerOptions);
        
        switch(choice){
            //Manipulate Member List
            case 1:
                UI("1");
                break;
            //Manipulate Provider List
            case 2:
                UI("2");
                break;
            //Member Report
            case 3:
                UI("3");
                break;
            //Provider Report
            case 4:
                UI("4");
                break;
            //EFT Report
            case 5:
                UI("5");
                break;
            //Accounting Report
            case 6:
                UI("6");
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
int DataCenter::updateLists(){

    return 1;
}

int DataCenter::recordService(){
    int memberNumber = 0;
    string date;
    int serviceCode = 0;
    char confirm = 'N';
    string comments;
    
    UI(memberNumber, "Please enter member number");
    //validate number TODO
    UI(date, "Enter date of service (MM-DD-YYYY)");
    
    //input and verify service code by displaying name
    while(confirm != 'Y'){
        UI(serviceCode, "Enter six digit service code");
        //special message for non-existent service TODO
        UI(confirm, "You provided: [service name]? (y/n)");
        confirm = toupper(confirm);
    }

    UI(confirm, "Would you like to enter comments? (y/n)");
    confirm = toupper(confirm);
    if(confirm == 'Y'){
        UI(comments, "Enter comments (up to 100 characters)");
    }


    //Create and populate service record object TODO


    UI("Service Successfully Recorded!");

    return 1;
}

int DataCenter::generateReport(){

    return 1;
}



//UI Helper Functions
void DataCenter::UIPrompt(string prompt, int flag = 1){
    cout << "-------------------------------------" << endl
         << prompt << endl;
    if(flag) cout << " > ";
}

void DataCenter::UI(string & str, string prompt){
    UIPrompt(prompt);
    getline(cin, str);
}

void DataCenter::UI(int & num, string prompt){
    UIPrompt(prompt);
    cin >> num;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input error, please try again: ";
        cin >> num;
    }
    cin.ignore(100, '\n');
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
