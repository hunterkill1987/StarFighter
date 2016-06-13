#include "stdafx.h"
#include "xmlParser.h"

xmlParser* xmlParser::Instance = 0;

xmlParser* xmlParser::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new xmlParser();
	}

	return Instance;
}


vector<char> xmlParser::GetFile(char* FilePath)
{
	ifstream theFile;
	theFile.open(FilePath);
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	return buffer;
}

xml_node<>* xmlParser::GetRoot(char* Root)
{
	return doc.first_node(Root);
}

xmlParser::~xmlParser()
{
}
