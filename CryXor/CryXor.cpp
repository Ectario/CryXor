#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

//texte.txt is in ASCII !
string TextToBinaryString(string words) {
	string binaryString = "";
	for (char& _char : words) {
		binaryString += bitset<8>(_char).to_string();
	}
	return binaryString;
}


int main() {
	// Create and open a text file
	ifstream MyFile("../texte.txt");

	// Create a text string, which is used to output the text file
	string myText;
	string myLine;

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyFile, myLine)) {
		// Output the text from the file
		myText+=myLine;
	}
	
	cout << TextToBinaryString(myText);

	// Close the file
	MyFile.close();

	return EXIT_SUCCESS;
}
