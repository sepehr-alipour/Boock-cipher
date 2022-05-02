#pragma once // same as #ifndef _FILE_HEADER_ 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// using namespace std; // NEVER EVER EVER EVER put a "using" in a header file

/*
	Represents a file as a set of lines (rows) and columns (char at line) of chars
*/
class FileTools
{
	std::string path;
	std::ifstream istream;
	std::vector<std::string> text;

	friend std::ostream& operator<< (std::ostream& os, FileTools const& file); // Allows this function to see the class' private space

public:

	FileTools(std::string path);
	~FileTools();

	char at(size_t lineIndex, size_t characterIndex) const;  // The method is const. It promises the state won't change
	char& at(size_t lineIndex, size_t characterIndex);
	std::string& operator[](size_t lineIndex);
	void update();
	int size() const;
	std::vector<std::string>& get();
};

std::ostream& operator<< (std::ostream& os, FileTools const& file);