# makefile for openssl tests

# compiler settings
CXX = clang++

# compiler flags
CXXFLAGS = -Wall -Wextra -O2

# paths to openssl include and lib directories
OPENSSL_INCLUDE = /opt/homebrew/opt/openssl@3/include
OPENSSL_LIB = /opt/homebrew/opt/openssl@3/lib

#libraries
LIBS = -lssl -lcrypto

# name of executable
TARGET = openssl_sha256_simple

# source files
SOURCES = openssl_sha256_test.cpp

# build target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -I$(OPENSSL_INCLUDE) -L$(OPENSSL_LIB) $(SOURCES) -o $(TARGET) $(LIBS)

# for clean
.PHONY: clean

# clean artifacts
clean:
	rm -f $(TARGET)