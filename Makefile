CC=g++
CXXFLAGS=-Wall
object_files=member.o provider.o person.o member-provider_list.o \
			 service_record.o provider_directory.o data_center.o
tests=provider_directory_test


all: data_center
test: provider_directory_test


data_center: $(object_files)
	$(CC) $(CXXFLAGS) -o data_center $(object_files)
data_center.o: data_center.h data_center.cpp
	$(CC) $(CXXFLAGS) -g -c data_center.cpp
service_record.o: service_record.h service_record.cpp
	$(CC) $(CXXFLAGS) -g -c service_record.cpp
provider_directory.o: provider_directory.h provider_directory_internal.h provider_directory.cpp
	$(CC) $(CXXFLAGS) -g -c provider_directory.cpp
person.o: person.h person.cpp
	$(CC) $(CXXFLAGS) -g -c person.cpp
member.o: person.h member.cpp
	$(CC) $(CXXFLAGS) -g -c member.cpp
provider.o: person.h provider.cpp
	$(CC) $(CXXFLAGS) -g -c provider.cpp
member-provider_list.o: member-provider_list.h person.h service_record.h member-provider_list.cpp
	$(CC) $(CXXFLAGS) -g -c member-provider_list.cpp

provider_directory_test: provider_directory.h provider_directory.o provider_directory_test.cpp
	$(CC) $(CXXFLAGS) -g -o provider_directory_test \
		provider_directory_test.cpp                 \
		provider_directory.o                        \
		-lgtest_main -lgtest -lpthread

.PHONY: clean
clean:
	rm -rf $(object_files) data_center $(tests)
