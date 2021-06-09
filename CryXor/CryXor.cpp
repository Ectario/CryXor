#include <fstream>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString += bitset<8>(_char).to_string();
    }
    return binaryString;
}


int main() {
    //// Create a text file
    //ofstream MyWriteFile("../texte.txt");

    //// Write to the file
    //MyWriteFile << "Files can be tricky, but it is fun enough!";

    //// Close the file
    //MyWriteFile.close();

    // Create a text string, which is used to output the text file
    string myText;
    string myLine;


    // Read from the text file
    ifstream MyReadFile("../texte.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myLine)) {
        // Output the text from the file
        myText += myLine;
    }

    cout << TextToBinaryString(myText);

    // Close the file
    MyReadFile.close();
}


