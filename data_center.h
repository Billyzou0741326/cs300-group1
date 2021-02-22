#ifndef DATA_CENTER_H 
#define DATA_CENTER_H

#include <string>
//#include "member-provider_list.h"
//#include "provider_directory.h"


class DataCenter{
    public:
        DataCenter();

        //Start the program from either perspective
        void providerMenu();
        void managerMenu();

    private:
        //Objects
//        member_list memberList;
//        provider_list providerList;
//        ProviderDirectory providerDirectory;
        //Other things
        std::string providerOptions;
        std::string managerOptions;

        //Internal helper functions
        int updateLists();
        int recordService();
        int generateReport();

        //UI helper functions
        void UIPrompt(std::string, int);
        void UI(std::string);
        void UI(std::string &, std::string);
        void UI(int &, std::string);
};


#endif