#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <set>

using namespace std;
//The header file contains the prototypes ofr all functions used in the insultgenerator.cpp file

class InsultGenerator {
public:
	InsultGenerator();
	void initialize();
	string talkToMe();
	vector<string> generate(const int n);
	vector<string> generateAndSave(const string s, const int n);

private:
	int generateRandNum();
	vector<string> c1, c2, c3, wordList;
	set<string> insultSet;
};

class FileException {
public:
	FileException(const string&);
	string what() const;
private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what() const;
private:
	string message;
};