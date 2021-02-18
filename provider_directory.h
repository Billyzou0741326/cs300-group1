#ifndef _PROVIDER_DIRECTORY_H
#define _PROVIDER_DIRECTORY_H

#include <string>
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
    std::string getName() const;
    std::string getDescription() const;

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

    bool loadFromFile(const std::string& filename);
    bool sendTo(const std::string& email) const;
    bool validateServiceCode(int serviceCode) const;

  private:
    TreeMap<int, Service*> serviceByCode;

};

#endif
