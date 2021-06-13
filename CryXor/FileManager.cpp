#include "FileManager.h"
#include <bitset>

FileManager::FileManager() {}

FileManager::~FileManager() {
	if (!input) input.close(); //close the file
	if (remove(path.c_str()) != 0)
		perror("Error deleting old file");
	else
		puts("Old file successfully deleted");
}

string FileManager::TextToBinaryString(string text) {
	string binaryString = "";
	for (char& _char : text) {
		binaryString += bitset<8>(_char).to_string();
	}
	return binaryString;
}


bool FileManager::loadFile(string param_path) {
	try {
		path = param_path;
		input.open(path, std::ios::binary);
		if (!input.is_open() || input.fail()) throw "Warning during the file search : Couldn't open the file. (maybe wrong path?)";
	}
	catch (std::exception const& e)
	{
		cerr << "ERROR in file loading : " << e.what() << endl;
		return false;
	}
	return true;
}

bool FileManager::encryptFile(string key, bool isAlreadyEncrypted) {
	if (path != "" && input.is_open() && !input.fail()) {
		if (isAlreadyEncrypted) {
			path.erase(path.end() - 7, path.end()); //We erase the 7 letter : .CryXor
			output.open(path, std::ios::binary);
		} else output.open(path + ".CryXor", std::ios::binary);

		string binaryKey = TextToBinaryString(key);
		string bufferSpace = TextToBinaryString(key);
		size_t bufferSize = key.length();
		char* buffer = &bufferSpace[0]; //Get exactly the space wanted for the char*

		for (size_t i = 0; i < bufferSize; i++) { //NULL the memory
			buffer[i] = NULL;
		}

		try {
			while (!input.eof()) {
				input.read(buffer, bufferSize);
				for (size_t i = 0; i < bufferSize; i++) {
					buffer[i] ^= ( binaryKey[i] - '0' ); //number in ASCII start from '0'
				}
				output.write(buffer, input.gcount());
			}
		}
		catch (std::exception const& e)
		{
			cerr << "ERROR during encryption : " << e.what() << endl;
			return false;
		}

	}
	else { cerr << "ERROR in init encryption : input file not initialized" << endl; return false; }

	return true;
}

