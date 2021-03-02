#ifndef SERVICE_RECORD_H
#define SERVICE_RECORD_H

#include <iostream>
#include <string>
#include <fstream>

class ServiceRecord {
	public:
        ServiceRecord();
        ServiceRecord(std::string recordDateAndTime, std::string dateOfService, int providerNumber, int memberNumber, int serviceCode, std::string comments, std::string providerName, std::string memberName, std::string serviceName, double fees);
        ~ServiceRecord();
        bool generateProviderReport(std::ofstream &OutputFile, int &numOfConsultations, double &totalFees);
        bool generateMemberReport(std::ofstream &OutputFile);
        bool EFTReport(double &totalFees);
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
