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


xmlParser::~xmlParser()
{
}
