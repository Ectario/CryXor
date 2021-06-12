#include <string>
#include <iostream>
#include <bitset>
#include "FileManager.h"

using namespace std;


void usage() {
    std::cerr << "Usage : CryXor.exe [crypt/decrypt] [path] [key] ";
}

int main(int argc, char** argv) {

    string path = "../texte.txt.CryXor";
    FileManager* fm = new FileManager();

    fm->loadFile(path);
    fm->encryptFile("testt", true); 
    delete fm;

    return EXIT_SUCCESS;
}


