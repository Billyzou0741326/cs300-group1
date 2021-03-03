//Service Record Implementation
//Bennett Desmond

#include "service_record.h"

using namespace std;

//int main() {
    //ServiceRecord record;
    //string date = "03-01-2021";
    //record.weekVerification(date);


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
    //cout << "month " << month << endl;
    string day = dateOfService.substr(3,2);
    //cout << "day " << day << endl;
    string year = dateOfService.substr(6,4);
    //cout << "year " << year << endl;
    //string convDateOfService = year + month + day;
    string convDateOfService = "20210301";
    //const string format = "%Y-%m-%d";
    tm tmTime;
    memset(&tmTime, 0, sizeof(tmTime));
    strptime(convDateOfService.c_str(), "%Y%m%d", &tmTime);
    const time_t dateOfServiceTimeVar = mktime(&tmTime);
    //cout << "Date of service: " << dateOfServiceTimeVar << endl;
    
    const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string delimiter = "-";
    //size_t pos = 0;
    //stringstream monthString(month);
    //stringstream dayString(day);
    //stringstream yearString(year);
    //int monthInt = 0;
    //int dayInt = 0;
    //int yearInt = 0;

    //monthString >> monthInt;
    //dayString >> dayInt;
    //yearString >> yearInt;
    //int monthDays;
    //for(int i = 0; i < monthInt; i++) {
        
    //}

    //int dateOfServiceFrom1970 = () + (dayInt * 24 * 60 * 60) + ((yearInt - 1 + 30) * 365 * 24 * 60 * 60);

    std::time_t current_time;

    current_time = time(NULL);
    //cout << "The current time is: " << current_time << endl;
    //cout << "The time differnece is: " << current_time - dateOfServiceTimeVar << endl;
    if((current_time - dateOfServiceTimeVar) <= 604800) {
        return true;
    }
    return false;
}

ServiceRecord *& ServiceRecord::goNext() {
    return next;
}
