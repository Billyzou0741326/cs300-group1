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
                UI("1");
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
    UI("Service Recording");
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
    cin.ignore(100, '\n');
}

void DataCenter::UI(string prompt){
    UIPrompt(prompt, 0);
}
