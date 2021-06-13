#include <string>
#include <iostream>
#include <bitset>
#include "FileManager.h"

using namespace std;


void usage() {
    std::cerr << "Usage : CryXor.exe [encrypt/decrypt] [path] [key] " << endl;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        usage();
        return EXIT_FAILURE;
    }

    string arg2(argv[1]);
    string path(argv[2]);
    string key(argv[3]);

    cout << "encryption ? : " << arg2 << endl;
    cout << "path : " << path << endl;
    cout << "key : " << key << endl;

    if ((arg2 != "encrypt" && arg2 != "decrypt")) {
        usage();
        return EXIT_FAILURE;
    }

    bool isAlreadyEncrypted;
    if (arg2 == "encrypt") isAlreadyEncrypted = false;
    else isAlreadyEncrypted = true;

    FileManager* fm = new FileManager();
    fm->loadFile(path);
    fm->encryptFile(key, isAlreadyEncrypted);
    delete fm;

    return EXIT_SUCCESS;
}


