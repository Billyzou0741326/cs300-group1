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
        ServiceRecord();
        ServiceRecord(std::string dateOfService, int providerNumber, int memberNumber, int serviceCode, std::string comments, std::string providerName, std::string memberName, std::string serviceName, double fees);
        ~ServiceRecord();
        bool generateProviderReport(std::ofstream &OutputFile,int &numOfConsultations, float &totalFees);
        
        bool generateMemberReport(std::ofstream &OutputFile);
        bool EFTReport(double &totalFees);
        bool weekVerification(std::string dateOfService); //This function verifies that the date passed to it is within seven days of the current date
        void save(std::ofstream & write); //Saves a record to the file passed to it
        bool load(std::ifstream & read); //Load a service record if one exists, otherwise returns false
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
        double fees;
};

#endif
