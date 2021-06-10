#include "FileManager.h"

FileManager::FileManager() {}

FileManager::~FileManager() {
	if (!input) input.close(); //close the file
}

bool FileManager::loadFile(string param_path) {
	try {
		path = param_path;
		input.open(path, std::ios::binary);
		if (!input.is_open() || input.fail()) throw "Warning in loadFile : Couldn't open the file.";
	}
	catch (std::exception const& e)
	{
		cerr << "ERROR in loadFile: " << e.what() << endl;
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

		const size_t bufferSize = 8;
		char buffer[bufferSize];

		try {
			while (!input.eof()) {
				input.read(buffer, bufferSize);
				for (size_t i = 0; i < bufferSize; i++) {
					buffer[i] ^= 1;
				}
				output.write(buffer, input.gcount());
			}
		}
		catch (std::exception const& e)
		{
			cerr << "ERROR in encryptFile: " << e.what() << endl;
			return false;
		}

	}
	else { cerr << "error in encryption : input file not initialized" << endl; return false; }

	return true;
}

