// ProviderDirectory Implementation
// Original author: Billy Zou

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

    // For more specific error reporting
    enum LoadResult
    {
      Ok             = 0,
      ErrOpenFile    = 1,
      ErrIO          = 2,
      ErrFormat      = 3,
      ErrFieldName   = 4,
      ErrDataType    = 5,
      ErrInternal    = 6,
    };

    /** load reads service entries from arbitrary input streams
     *
     *  @returns LoadResult
     *
     *  *Note: failure may happen due to invalid types, invalid
     *         field name, incomplete entries, invalid separator,
     *         etc.
     */
    enum LoadResult load(std::istream& inStream);

    /** loadFromFile reads service entries from the specified file
     *
     *  @returns LoadResult
     *
     *  See `bool load(std::istream& inStream)`.
     */
    enum LoadResult loadFromFile(const std::string& filename);

    /** sendTo writes service entries to an arbitrary out stream.
     *
     *  @returns true on success, false on failure
     */
    bool sendTo(std::ostream& outStream) const;

    /** sendTo writes service entries to a file
     *
     *  @returns true on success, false on failure
     */
    bool sendTo(int providerId) const;

    /** validateServiceCode checks if a service code is present
     *
     *  @returns true on found, false on absent
     *  @params  targetService will be set if the service is found
     */
    bool validateServiceCode(int serviceCode, Service& targetService) const;

    /** size returns the number of entries in the provider directory
     */
    int size() const;

    void formatProviderDirectory(std::string& str, int providerId) const;

  private:
    TreeMap<int, Service*> serviceByCode;

    /** readEntry reads one service entry from an arbitrary 
     *  input stream and stores it in `s`.
     *
     *  @returns LoadResult
     */
    enum LoadResult readEntry(std::istream& inFile, Service *s);
};

#endif
