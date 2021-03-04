//Service Record Implementation
//Bennett Desmond

#include "service_record.h"

using namespace std;

//int main() {
    //ofstream fstream;
    //fstream("providerRecord.txt");
    //ServiceRecord record;
    //string date = "03-01-2021";
    //record.weekVerification(date);

    //ServiceRecord record("03-03-2021",789789789,789789789,789789,"This is a comment","Jeff Johnson","Bennett Desmond","Elbow Gris",5.00);
    //return 0;
//}


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
    time_t rawTime;
    struct tm * timeInfo;
    char buffer[80];
    time (&rawTime);
    timeInfo = localtime(&rawTime);
    strftime(buffer,sizeof(buffer),"%m-%d-%Y %H:%M:%S",timeInfo);
    string recordDateAndTime(buffer);
    //cout << "The time is: " << recordDateAndTime << endl;
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

bool ServiceRecord::generateProviderReport(ofstream &outputFile, uint &numOfConsultations, float &totalFees) {
    if(weekVerification(dateOfService)) {
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
    } else {
        return false;
    }
}

bool ServiceRecord::generateMemberReport(ofstream &outputFile) {
    if(weekVerification(dateOfService)) {
        outputFile << endl;
        outputFile << "    " << dateOfService << endl;
        outputFile << "    " << providerName << endl;
        outputFile << "    " << serviceName << endl;
        return true;
    } else {
        return false;
    }
}

bool ServiceRecord::EFTReport(double &totalFees) {
    if(weekVerification(dateOfService)) {
        totalFees += fees;
        return true;
    } else {
        return false;
    }
}

bool ServiceRecord::weekVerification(string dateOfService) {
    string month = dateOfService.substr(0,2);
    string day = dateOfService.substr(3,2);
    string year = dateOfService.substr(6,4);
    string convDateOfService = "20210301";
    tm tmTime;
    memset(&tmTime, 0, sizeof(tmTime));
    strptime(convDateOfService.c_str(), "%Y%m%d", &tmTime);
    const time_t dateOfServiceTimeVar = mktime(&tmTime);
    const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string delimiter = "-";
    std::time_t current_time;
    current_time = time(NULL);
    if((current_time - dateOfServiceTimeVar) <= 604800) {
        return true;
    }
    return false;
}
