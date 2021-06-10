#include <string>
#include <iostream>
#include <bitset>
#include "FileManager.h"

using namespace std;

string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString += bitset<8>(_char).to_string();
    }
    return binaryString;
}


void usage() {
    std::cerr << "Usage : CryXor.exe [crypt/decrypt] [path] [key] ";
}

int main(int argc, char** argv) {

    string path = "../texte.txt.CryXor";
    FileManager* fm = new FileManager();

    fm->loadFile(path);
    fm->encryptFile("ff", true); //ff is not yet used
    delete fm;

    return EXIT_SUCCESS;
}


