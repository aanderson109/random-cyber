# makefile for aes256-ctr in cpp

# compiler settings
CXX = clang++

# compiler flags
CXXFLAGS = -Wall -Wextra -O2

# openssl paths
OPENSSL_INCLUDE = /opt/homebrew/opt/openssl@3/include
OPENSSL_LIB = /opt/homebrew/opt/openssl@3/lib

# libraries
LIBS = -lssl -lcrypto

# name of executable
TARGET = aes256ctr_plus

# source file
SOURCES = ossl-aes256-ctr.cpp

# build target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -I$(OPENSSL_INCLUDE) -L$(OPENSSL_LIB) $(SOURCES) -o $(TARGET) $(LIBS)

# clean
.PHONY: clean

# clean artifacts
clean:
	rm -f $(TARGET)