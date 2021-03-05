CC=g++
CXXFLAGS=-Wall -Werror

all: service_record.o       \
	provider_directory.o    \
	data_center.o

test: provider_directory_test


data_center.o: data_center.h data_center.cpp
	$(CC) $(CXXFLAGS) -g -c data_center.cpp
service_record.o: service_record.h service_record.cpp
	$(CC) $(CXXFLAGS) -g -c service_record.cpp
provider_directory.o: provider_directory.h provider_directory_internal.h provider_directory.cpp
	$(CC) $(CXXFLAGS) -g -c provider_directory.cpp

provider_directory_test: provider_directory.h provider_directory.o provider_directory_test.cpp
	$(CC) $(CXXFLAGS) -g -o provider_directory_test \
		provider_directory_test.cpp                 \
		provider_directory.o                        \
		-lgtest_main -lgtest -lpthread
