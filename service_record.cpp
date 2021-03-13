//Service Record Implementation
//Bennett Desmond

#include "service_record.h"

using namespace std;

//int main() {
    //ofstream stream;
    //stream.open("providerRecord.txt");

    //if(!stream) {
        //cout << "The file was not opened" << endl;
    //}

    //ServiceRecord record;
    //string date = "03-01-2021";
    //record.weekVerification(date);

    //ServiceRecord record("03-03-2021",789789789,789789789,789789,"This is a comment","Jeff Johnson","Bennett Desmond","Elbow Gris",5.00);

    //record.save(stream);


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

ServiceRecord::ServiceRecord(string dateOfService, int providerNumber, int memberNumber, int serviceCode, string comments, string providerName, string memberName, string serviceName, float fees) {
    time_t rawTime;
    struct tm * timeInfo;
    char buffer[80];
    time (&rawTime);
    timeInfo = localtime(&rawTime);
    strftime(buffer,sizeof(buffer),"%m-%d-%Y %H:%M:%S",timeInfo);
    string tempRecordDateAndTime(buffer);
    this->recordDateAndTime = tempRecordDateAndTime;
    this->dateOfService = dateOfService;
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

bool ServiceRecord::generateProviderReport(ofstream &outputFile, int &numOfConsultations, float &totalFees) {
    //if(weekVerification(dateOfService)) {
    if(outputFile){
        outputFile << endl;
        outputFile << "Date of service: " << dateOfService << endl;
        outputFile << "Date of record: " << recordDateAndTime << endl;
        outputFile << "Member name: " << memberName << endl;
        outputFile << "Member number: " << memberNumber << endl;
        outputFile << "Service code: " << serviceCode << endl;
        outputFile << "Fees: " << fees << endl << endl;
        numOfConsultations++;
        totalFees += fees;
        return true;
    } else {
        return false;
    }
}

bool ServiceRecord::generateMemberReport(ofstream &outputFile) {
    //if(weekVerification(dateOfService)) {
    if(outputFile){
        outputFile << endl;
        outputFile << "Date of service: " << dateOfService << endl;
        outputFile << "Provider name: " << providerName << endl;
        outputFile << "Service name: " << serviceName << endl << endl;
        return true;
    } else {
        return false;
    }
}

bool ServiceRecord::EFTReport(float &totalFees) {
    if(weekVerification()) {
        totalFees += fees;
        return true;
    } else {
        return false;
    }
}

bool ServiceRecord::weekVerification() {
    string month = dateOfService.substr(0,2);
    string day = dateOfService.substr(3,2);
    string year = dateOfService.substr(6,4);
    
    /*string convDateOfService = year + month + day;
    tm tmTime;
    memset(&tmTime, 0, sizeof(tmTime));
    strptime(convDateOfService.c_str(), "%Y%m%d", &tmTime);
    const time_t dateOfServiceTimeVar = mktime(&tmTime);
    //const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string delimiter = "-";*/

    tm convert;
    convert.tm_sec = convert.tm_min = convert.tm_hour = 0;
    convert.tm_mday = stoi(day);
    convert.tm_mon = stoi(month) - 1;
    convert.tm_year = stoi(year) - 1900;
    time_t converted = mktime(&convert);

    std::time_t current_time;
    current_time = time(NULL);
    if((current_time - converted) <= 604800) {
        return true;
    }
    return false;
}

void ServiceRecord::save(ofstream & write) {
    write << "\t" << recordDateAndTime << "," << dateOfService << "," << providerNumber << "," << memberNumber << "," << serviceCode << "," << comments << "," << providerName << "," << memberName << "," << serviceName << "," << fees << endl;
}

bool ServiceRecord::load(ifstream & read) {
    if(read.peek() == '\t') {
        char temp[100];
        read.get();
        read.getline(temp,100,',');
        recordDateAndTime = temp;
        read.getline(temp,100,',');
        dateOfService = temp;
        read >> providerNumber;
        read.get();
        read >> memberNumber;
        read.get();
        read >> serviceCode;
        read.get();
        read.getline(temp,100,',');
        comments = temp;
        read.getline(temp,100,',');
        providerName = temp;
        read.getline(temp,100,',');
        memberName = temp;
        read.getline(temp,100,',');
        serviceName = temp;
        read >> fees;
        read.get();
    } else {
        return false;
    }
    return true;
}

float ServiceRecord::getFee() {
    return fees;
}

bool ServiceRecord::weekVerificationWrapper() {
    return weekVerification();
}

bool ServiceRecord::accountingReport(int &numOfConsulations, float &totalFees) {
    if(weekVerification()) {
        numOfConsulations++;
        totalFees += fees;
    } else {
        return false;
    }
    return true;
}
