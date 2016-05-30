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

	static xmlParser* Instance;

public:
	xmlParser() {};

	static xmlParser* GetInstance();

	~xmlParser();
};

