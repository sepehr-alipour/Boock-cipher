#include "tester.h"
#include "Cipher.h"
#include "FileTools.h"
#include <string>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	string baseFileName = argv[1];
	string flag = argv[2];
	string inputFileName = argv[3];
	string outputFileName = argv[4];

	sdds::Cipher cipher;
	FileTools baseFile(baseFileName);
	FileTools inputFile(inputFileName);
	FileTools outputFile(outputFileName);
	string outputChars;
	if (flag[0] != '-')
	{
		cout << "[ERROR] Invalid flag. Use -e for (e)ncoding or -d for (d)coding ";
		return 0;
	}
	ifstream baseFileIfstr(baseFileName);
	ifstream inputFileIfstr(inputFileName);
	ifstream outputFileIfstr(outputFileName);

	if (!baseFileIfstr.is_open()|| !inputFileIfstr.is_open()|| !outputFileIfstr.is_open())
	{
		cout << "[ERROR] Failed to open file" << endl;
		return 0;
	}
	if ((flag.substr(1) == "e" || flag.substr(2) == "e"))
	{
		bool checked;
		for (int i = 0; i < inputFile.size(); i++)
		{
			for (int j = 0; inputFile.at(i, j) != '\0'; j++)
			{
				for (int k = 0; k < baseFile.size(); k++)
				{
					for (int l = 0; baseFile.at(k, l) != '\0'; l++)
					{

						if (inputFile.at(i, j) == baseFile.at(k, l)) {
							outputChars += to_string(k) + " " + to_string(l) + "\n";
							checked = true;
							break;
						}
						else checked = false;

					}
					if (checked)
						break;
				}
			}
		}
		outputFile[0] = outputChars;
		outputFile.update();
	}
	else if (flag.substr(1) == "d" || flag.substr(2) == "d") {
		outputChars = "";
		for (int i = 0; i < inputFile.size(); i++)
		{
			int spacePos = inputFile[i].find(" ")+1;
			int returnPos = inputFile[i].find("\n")-1;
	
			int row = stoi(inputFile[i].substr(0, spacePos));
			int col = stoi(inputFile[i].substr(spacePos, returnPos));
			outputChars += baseFile.at(row, col);
		}
		outputFile[0] = outputChars;
		outputFile.update();
	}

	return 1;
}