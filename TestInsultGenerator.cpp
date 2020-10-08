/*
 * TestInsultGenerator.cpp
 *
 *      Author: Alan McLeod
 *      A testing program for CISC320 assignment 1.
 */

#include "insultgenerator_17smp3.h"

using namespace std;

int main() {

	InsultGenerator ig; //initialize the InsultGenerator class
	vector<string> insults; 
	clock_t start = 0, finish = 0;

	// The initialize() method should load all the source phrases from the InsultsSource.txt file into the attributes.
	// If the file cannot be read, the method should throw an exception.
	try {
		ig.initialize();
	}
	catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}

	// talkToMe() returns a single insult, generated at random.
	cout << "A single insult:" << endl;
	cout << ig.talkToMe() << endl;

	// generate() generates the requested number of unique insults.
	cout << "\n100 insults, all different:" << endl;
	insults = ig.generate(100);
	if (insults.size() > 0)
		for (int i = 0; i < 100; i++)
			cout << insults[i] << endl;
	else
		cerr << "Insults could not be generated!" << endl;

	// generateAndSave() generates the requested number of unique insults and saves them to the filename
	// supplied.  If the file cannot be written, the method should throw an exception.  Note that the
	// insults in the file should be in alphabetical order!
	// Check the number to generate limits first:
	
	cout << "\nSaving 1000 unique insults to a file...";
	try {
		ig.generateAndSave("SavedInsults.txt", 1000);
	}
	catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}
	cout << "done." << endl;

	// Test ability to generate the maximum number of insults and how long it takes.
	try {
		start = clock();
		insults = ig.generate(10000);
		finish = clock();
	}
	catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	cout << "\n" << insults.size() << " insults generated." << endl;
	cout << (1e3 * (finish - start) / CLOCKS_PER_SEC) << " msec to complete." << endl;

	return 0;

} // end main
