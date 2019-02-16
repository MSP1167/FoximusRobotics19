#pragma once
#include <iostream>
#include <string>
//other includes needed should be put here

//You NEED namespace std for stings otherwise you have to type std::string
using namespace std;
class UDP {
public:
	UDP();
	void Send(string msg);
	string Receive();

	//private: //if you need private vars uncomment this and put them below
};
