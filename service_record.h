#ifndef SERVICE_RECORD_H
#define SERVICE_RECORD_H

#include <iostream>
#include <string>
#include <fstream>

class ServiceRecord {
	public:
        ServiceRecord();
        ServiceRecord(string recordDateAndTime, string dateOfService, int providerNumber, int memberNumber, int serviceCode, string comments, string providerName, string membername, string serviceName, double fees);
        ~ServiceRecord();
        void generateProviderReport(ofstream &OutputFile);
        void generateMemberReport(ofstream &OutputFile);
        int EFTReport();
	private:
		string recordDateAndTime;
        string dateOfService
        int providerNumber;
        int memberNumber;
        int serviceCode;
        string comments;
        string providerName;
        string memberName;
        string serviceName;
        double fees;
        ServiceRecord * next;
};

#endif
