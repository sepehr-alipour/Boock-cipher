#pragma once

#include "FileTools.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
namespace sdds {
	class Cipher
	{
	public:
		void endcode(FileTools* base, FileTools *input, FileTools* output);
		void decode(FileTools base, FileTools input, FileTools output);

	};
}

