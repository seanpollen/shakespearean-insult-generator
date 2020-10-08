#include "insultgenerator_17smp3.h"

using namespace std;
//C O N S T R U C T O R
InsultGenerator::InsultGenerator() {}

// The text file is read one line at a time, inserting each word in to one of three respective columns
void InsultGenerator::initialize() {
	string readLine;
	stringstream ss; //uses the stringstream class 
	ifstream inputFile("InsultsSource.txt"); //creates an ifstream object to read textfile
	if (inputFile.fail()) { //if no work :(
		throw FileException("Illegal file!");
		return;
	}
	while (!inputFile.eof()) { //loop through input file until the end is reached
		getline(inputFile, readLine);
		ss.clear();
		ss.str(" ");
		ss << readLine;
		while (ss >> readLine) { 
			wordList.push_back(readLine); //every word will be inserted into readLine until the end of the text file is reached
		}
	}
	for (int i = 0; i < wordList.size(); i += 3) { //we want first col + second col+ third col seperated to form a sentence
		c1.push_back(wordList[i]);
		c2.push_back(wordList[i + 1]);
		c3.push_back(wordList[i + 2]);
	}
	inputFile.close();
}

  //uses generateRandNum() to create one insult
string InsultGenerator::talkToMe() {
	int num1, num2, num3;
	num1 = generateRandNum();
	num2 = generateRandNum();
	num3 = generateRandNum();
	string insult;
	insult = "Thou " + c1[num1] + " " + c2[num2] + " " + c3[num3] + "!";
	return insult;
}

// generate i insults, return them as a vector of every generated insults
vector<string> InsultGenerator::generate(const int i) {
	if (i > 10000 || i < 1) { //check if number of insults is within accepted range of 1-10000
		throw NumInsultsOutOfBounds("Illegal number of insults! (from generate)");
		return vector<string>(); 
	}
	set<string> insultSet; //sets are used because they do not contain any duplicates. This ensures unique insults! 
	while (i > insultSet.size()) {
		string temp(talkToMe());
		insultSet.insert(temp);
	}//end while
	vector<string> allInsults(insultSet.begin(), insultSet.end());
	return allInsults;
} 

// this method generates n insults, outputs insults into a specified file, and returns insults as vector of strings
vector<string> InsultGenerator::generateAndSave(string fileName, int i) {
	ofstream outputFile(fileName);
	set<string> insultSet;
	if (i < 1 || i > 10000) {
		throw NumInsultsOutOfBounds("Illegal number of insults! (from generateAndSave)");
		return vector<string>();
	}
	else {
		while (i > insultSet.size()) {
			string insult = talkToMe();
			insultSet.insert(insult);
			outputFile << insult + "\n";
		}
	}
	vector<string> allInsults(insultSet.begin(), insultSet.end());
	return allInsults;
}
//function to generate a random index for 50 vecctor elements

int InsultGenerator::generateRandNum() {
	int number;
	number = rand() % 49;
	return number;
}

FileException::FileException(const string& m) : message(m) {}

string FileException::what() const {
	return message;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}

string NumInsultsOutOfBounds::what() const {
	return message;
}