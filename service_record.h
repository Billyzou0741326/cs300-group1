//Service Record class overview
//Bennett Desmond

#ifndef SERVICE_RECORD_H
#define SERVICE_RECORD_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstring>

class ServiceRecord {
	public:
        ServiceRecord(); //Dwefault contructor
        ServiceRecord(std::string dateOfService, int providerNumber, int memberNumber, int serviceCode, std::string comments, std::string providerName, std::string memberName, std::string serviceName, float fees); //Parameterized constructor
        ~ServiceRecord(); //Destructor
        bool generateProviderReport(std::ofstream &OutputFile,int &numOfConsultations, float &totalFees); //Writes the necessary information for a provider. This function returns false when a record is outside of a week and true otherwise.
        
        bool generateMemberReport(std::ofstream &OutputFile); //Writed the necessary information for a meber report. This function returns false when a record is outside of a week and true otherwise.
        bool EFTReport(float &totalFees); //This function accumulates the total fees for an EFT report. This function returns false if the record is outside of week and true otherwise.
        bool weekVerification(std::string dateOfService); //This function verifies that the date passed to it is within seven days of the current date
        void save(std::ofstream & write); //Saves a record to the file passed to it
        bool load(std::ifstream & read); //Load a service record if one exists, otherwise returns false
        float getFee();
        bool weekVerificationWrapper(); //This fucntion is a wrapper function for the week verification function
	private:
        std::string recordDateAndTime;
        std::string dateOfService;
        int providerNumber;
        int memberNumber;
        int serviceCode;
        std::string comments;
        std::string providerName;
        std::string memberName;
        std::string serviceName;
        float fees;
};

#endif
