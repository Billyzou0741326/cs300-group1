//Service Record class overview
//Bennett Desmond

#ifndef SERVICE_RECORD_H
#define SERVICE_RECORD_H

#include <iostream>
#include <string>
#include <fstream>

class ServiceRecord {
	public:
        ServiceRecord();
        ServiceRecord(std::string dateOfService, int providerNumber, int memberNumber, int serviceCode, std::string comments, std::string providerName, std::string memberName, std::string serviceName, double fees);
        ~ServiceRecord();
        bool generateProviderReport(std::ofstream &OutputFile, int &numOfConsultations, double &totalFees);
        bool generateMemberReport(std::ofstream &OutputFile);
        bool EFTReport(double &totalFees);
        //This function verifies that the date passed to it
        //is whithin a week of the current day.
        //This function returns true if the date is within a
        //week of the current date and false otherwise.
        bool weekVerification(std::string dateOfService);
        //This is the getter for the next pointer member.
        //There are no parameters to this function, but a
        //referernce poointer is returned.
        ServiceRecord *& goNext();
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
        ServiceRecord * next;
};

#endif