#pragma once
#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace System;
using namespace std;
class archivos {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;
	int fx,fy,fn,ft;
public:
	archivos() {}
	~archivos() {}
	void readData() {

		fileRead.open("configuration.txt", ios::in);
		if (fileRead.fail()) {
			fileRead.close();
			fileWrite.open("configuration.txt", ios::out); //Cambiar variables en el bloc de notas para configurar
			fileWrite << "25" << endl;
			fileWrite << "25" << endl;    
			fileWrite << "5" << endl;
			fileWrite << "10" << endl;
			fileWrite.close();
			fileRead.open("configuration.txt", ios::in);
		}
		getline(fileRead, text);
		fx = atoi(text.c_str());
		getline(fileRead, text);
		fy = atoi(text.c_str());
		getline(fileRead, text);
		fn = atoi(text.c_str());
		getline(fileRead, text);
		ft = atoi(text.c_str());
		fileRead.close();
	}
	int getfn() { return fn; }
	int getfx() { return fx; }
	int getfy() { return fy; }
	int getft() { return ft; }
};