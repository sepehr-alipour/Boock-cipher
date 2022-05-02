#include "Cipher.h"
#include "FileTools.h"
#include <iostream>
#include <string>

using namespace std;
namespace sdds {
	void Cipher::endcode(FileTools* base, FileTools* input, FileTools* output) {
		string outputChars;


		bool checked;
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < input.at(i, j) != '\0'; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < base.at(k, l) != '\0'; l++)
					{

						if (input.at(i, j) == base.at(k, l)) {
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
		output[0] = outputChars;
		output.update();
	}


}
