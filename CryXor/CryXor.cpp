#include <fstream>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;


int main(int argc, char** argv) {

    string path = "../texte.txt";

    std::ifstream input(path, std::ios::binary);
    std::ofstream output(path + ".CryXor", std::ios::binary);

    const size_t bufferSize = 8;
    char buffer[bufferSize];

    while (!input.eof()){
        input.read(buffer, bufferSize);
        for (size_t i = 0; i < bufferSize; i++) {
            buffer[i] ^= 1;
        }
        output.write(buffer, input.gcount());
    }

    // Close the file
    input.close();

    return EXIT_SUCCESS;
}


