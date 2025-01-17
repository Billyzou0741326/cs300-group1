//CS 300 - W21 - Mack Foggia

#ifndef DATA_CENTER_H 
#define DATA_CENTER_H

#include <string>
#include <iostream>
#include <fstream>
#include "member-provider_list.h"
#include "person.h"
#include "provider_directory.h"


class DataCenter{
    public:
        DataCenter();
        ~DataCenter();

        //Start the program from either perspective
        void providerMenu();
        void managerMenu();

    private:
        //Objects
        member_list memberList;
        provider_list providerList;
        ProviderDirectory providerDirectory;
        //Other things
        std::string providerOptions;
        std::string managerOptions;
        int currentProviderNumber;

        //Internal helper functions
        int manipulateMembers();
        int manipulateProviders();
        int recordService();
        int createPerson(int type);
        int removePerson(int type);
        int editProvider();
        int editMember();

        //UI helper functions
        void UIPrompt(std::string, int flag);
        void UI(std::string);
        void UI(std::string &, std::string, int max = 0);
        void UI(int &, std::string, int max = 0, int min = 0);
        void UI(char &, std::string);
};


#endif