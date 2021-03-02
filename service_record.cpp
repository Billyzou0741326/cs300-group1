//Service Record Implementation
//Bennett Desmond

#include "service_record.h"

using namespace std;


ServiceRecord::ServiceRecord() {
    recordDateAndTime = "00-00-0000 00:00:00";
    dateOfService = "00-00-0000";
    providerNumber = 000000000;
    memberNumber = 000000000;
    serviceCode = 000000;
    comments = "None";
    providerName = "";
    memberName = "";
    serviceName = "";
    fees = 00.00;
}

ServiceRecord::ServiceRecord(string dateOfService, int providerNumber, int memberNumber, int serviceCode, string comments, string providerName, string memberName, string serviceName, double fees) {
    //Figure out how to populate recordDateAndTime TODO
    this->dateOfService;
    this->providerNumber = providerNumber;
    this->memberNumber = memberNumber;
    this->serviceCode = serviceCode;
    this->comments = comments;
    this->providerName = providerName;
    this->memberName = memberName;
    this->serviceName = serviceName;
    this->fees = fees;
}

ServiceRecord::~ServiceRecord() {

}

bool ServiceRecord::generateProviderReport(ofstream &outputFile, int &numOfConsultations, double &totalFees) {
    //Add functionality for checking the date so that only the last seven days are displayed TODO
    outputFile << endl;
    outputFile << "    " << dateOfService << endl;
    outputFile << "    " << recordDateAndTime << endl;
    outputFile << "    " << memberName << endl;
    outputFile << "    " << memberNumber << endl;
    outputFile << "    " << serviceCode << endl;
    outputFile << "    " << fees << endl;
    numOfConsultations++;
    totalFees += fees;
    return true;
}

bool ServiceRecord::generateMemberReport(ofstream &outputFile) {
    //Add functionality to check the date TODO
    outputFile << endl;
    outputFile << "    " << dateOfService << endl;
    outputFile << "    " << providerName << endl;
    outputFile << "    " << serviceName << endl;
    return true;
}

bool ServiceRecord::EFTReport(double &totalFees) {
    //add date check TODO
    totalFees += fees;
    return true;
}

bool ServiceRecord::weekVerification(string dateOfService) {
    //Check date TODO
    return true;
}

ServiceRecord *& ServiceRecord::goNext() {
    return next;
}
