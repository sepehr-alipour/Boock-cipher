#include "FileTools.h"

FileTools::FileTools(std::string path) : path(path), istream(path)
{
	//ifstream file(path);

	std::string line;
	while (istream) // Is the file is considered "false" (https://en.cppreference.com/w/cpp/io/basic_ios/operator_bool)
	{
		char c = istream.get();
		if (istream.eof()) // has the file read the EOF character
		{
			break;
		}

		line.push_back(c);

		if (c == '\n')
		{
			text.push_back(line);
			line.clear();
		}
	}

	text.push_back(line);
}

FileTools::~FileTools() // Destructor. Called when the variable goes out of scope
{
	// Not really needed because of https://www.cplusplus.com/reference/fstream/ifstream/close
	// Here for an example of a destructor for you
	istream.close();
}

char FileTools::at(size_t lineIndex, size_t characterIndex) const // The method is const. It promises the state won't change
{
	std::string line = text[lineIndex];
	char character = line[characterIndex];
	return character;
}

char& FileTools::at(size_t lineIndex, size_t characterIndex)
{
	return text[lineIndex][characterIndex];
}

std::string& FileTools::operator[](size_t lineIndex)
{
	return text[lineIndex];
}

void FileTools::update()
{
	std::ofstream fileToWrite(path); // Creating a out-stream file object
	FileTools& self = *this; // 'this' is a pointer to the instance. 
	fileToWrite << self; // Use the overloaded << to stream the contents of 'text' into the out-stream (could be cout or a file)
}
int FileTools::size() const {
	return text.size();
}
std::vector<std::string>& FileTools::get() {
	return text;
}

std::ostream& operator<< (std::ostream& os, FileTools const& file)
{
	for (std::string line : file.text)
	{
		os << line;
	}

	return os;
}