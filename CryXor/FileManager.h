#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManager {
public:
	FileManager();
	bool loadFile(string path);

	//Encrypt the current input and save it in the current directory (with .CryXor extension), for the decryption it's the same algorithm cause it's XOR encryption (just put isAlreadyEncrypted = true)
	bool encryptFile(string key, bool isAlreadyEncrypted);

	~FileManager();
private:
	std::ifstream input;
	std::ofstream output;
	string path = "";
};

#endif //FILEMANAGER_H
