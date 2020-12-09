#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;
	int s,t;

public:
	File() {}
	~File() {}

	void readData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("configuration.txt", ios::out);
			fileWrite << "2" << endl;
			fileWrite << "100" << endl;
			fileWrite.close();

			fileRead.open("configuration.txt", ios::in);
		}

		getline(fileRead, text);
		s = atoi(text.c_str());
		getline(fileRead, text);
		t = atoi(text.c_str());

		fileRead.close();
	}

	int getS() { return s; }
	int gett() { return t; }

};