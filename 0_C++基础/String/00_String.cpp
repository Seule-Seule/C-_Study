#include "00_String.h"


String::String()
{
	StringLen = 0;
	pString = new char[StringLen + 1];
	strcpy(pString, "");
}
String::String(const char* pS)
{
	StringLen = strlen(pS);
	pString = new char[StringLen + 1];
	strcpy(pString, pS);
}
String::String(const String& s)
{
	StringLen = s.StringLen;
	pString = new char[StringLen + 1];
	strcpy(pString, s.pString);
}
String::~String()
{
	if (pString != NULL)
	{
		delete[]pString;
		//pString = 0;
		//StringLen = 0;
	}
}

void String::Print()
{
	cout << pString << endl;
}

String& String::operator=(String& sObj)
{
	// 释放资源
	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
		StringLen = 0;
	}
	StringLen = sObj.StringLen;
	pString = new char[StringLen + 1];
	strcpy(pString, sObj.pString);
	return *this;
}

bool  String::operator>(String& sObj)
{
	if (strcmp(pString, sObj.pString) > 0)
	{
		return true;
	}
	return false;
}

bool  String::operator<(String& sObj)
{
	if (strcmp(pString, sObj.pString) < 0)
	{
		return true;
	}
	return false;
}

void  String::operator()(const char* pS)
{
	// 释放资源
	if (pString != NULL)
	{
		delete[]pString;
		pString = NULL;
		StringLen = 0;
	}
	StringLen = strlen(pS);
	pString = new char[StringLen + 1];
	strcpy(pString, pS);
}

bool String::operator==(String& sObj)
{
	if (strcmp(pString, sObj.pString) == 0)
	{
		return true;
	}
	return false;
}

bool String::operator!=(String& sObj)
{
	return !(*this == sObj);
}

ostream& operator<<(ostream& out, String& sObj)
{
	out << "sObj.StringLen: " << sObj.StringLen << "    sObj.pString: " << sObj.pString << endl;
	return out;
}
istream& operator>>(istream& in, String& sObj)
{
	int tmp;
	cout << "Please input len of String:";
	in >> tmp;
	sObj.StringLen = tmp;
	sObj.pString = new char[tmp + 1];
	cout << "Please input String:";
	in >> sObj.pString;
	cout << "Input success!" << endl;
	return in;
}

String& String::operator+(String& sObj)
{
	char* ptmp = NULL;
	ptmp = new char[StringLen + 1];
	strcpy(ptmp, pString);
	delete[]pString;
	pString = NULL;
	StringLen = StringLen + sObj.StringLen;
	pString = new char[StringLen + 1];
	strcpy(pString, ptmp);
	strcat(pString, sObj.pString);
	delete[]ptmp;
	return *this;
}

String& String::operator-(String& sObj)
{
	if (StringLen < sObj.StringLen)
	{
		cout << "ERRO: StringLen < sObj.StringLen" << endl;
		return *this;
	}
	char* ptmp = NULL;
	ptmp = strstr(pString, sObj.pString);
	if (NULL == ptmp)
	{
		cout << "ERRO: pString haven\'t same as sObj.pString" << endl;
		return *this;
	}
	StringLen = StringLen - strlen(ptmp);
	ptmp = new char[StringLen];
	memcpy(ptmp, pString, StringLen);
	delete[]pString;
	pString = new char[StringLen + 1];
	memcpy(pString, ptmp, StringLen);
	memcpy(pString + StringLen, "\0", 1);
	delete[]ptmp;
	return *this;
}

char* String::GetpSting()
{
	return pString;
}


int String::GetStringLen()
{
	return StringLen;
}