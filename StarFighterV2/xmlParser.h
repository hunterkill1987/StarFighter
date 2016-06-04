#pragma once
#include "rapidxml\rapidxml.hpp"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace rapidxml;
using namespace std;

class xmlParser
{

private:
	xml_document<> doc;
	xml_node<> * root_node;
	char* FilePath;

	static xmlParser* Instance;

public:
	xmlParser() {};

	static xmlParser* GetInstance();
	xml_node<>* GetRoot(char* Root);
	void GetFile(char* File);
	~xmlParser();
};

