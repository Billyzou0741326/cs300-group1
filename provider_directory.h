#ifndef _PROVIDER_DIRECTORY_H
#define _PROVIDER_DIRECTORY_H

#include <string>
#include <fstream>
#include "provider_directory_internal.h"


class Service
{
  public:
    Service();
    Service(int code, double fees, const std::string& name, const std::string& desc);
    Service(const Service&);
    ~Service();

    int getCode() const;
    double getFees() const;
    const std::string& getName() const;
    const std::string& getDescription() const;

    void setCode(int code);
    void setFees(double fees);
    void setName(const std::string& name);
    void setDescription(const std::string& desc);

  private:
    int code;
    double fees;
    std::string name;
    std::string description;
};


class ProviderDirectory
{
  public:
    ProviderDirectory();
    ProviderDirectory(const ProviderDirectory&);
    ~ProviderDirectory();

    bool load(std::istream& inStream);
    bool loadFromFile(const std::string& filename);
    bool sendTo(const std::string& email) const;
    bool sendTo(std::ostream& outStream);
    bool validateServiceCode(int serviceCode) const;

  private:
    TreeMap<int, Service*> serviceByCode;

    int readEntry(std::istream& inFile, Service *s);
};

#endif
