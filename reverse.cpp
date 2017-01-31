/*
 * Rev.cpp
 *
 *  Created on: 19-Jan-2017
 *      Author: cmrit-ise
 *		Geetha S
 *		Sheetal R
 *		Prasad M S
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class NameList
{
	vector<string> names;
	static string reverse1(vector<string>);
public:
	void readinput(istream & ist);
	void writeoutput(ostream & ost);
};

//Function to display the reversed string
void NameList::writeoutput(ostream & ost)
{
	string revstr;
	revstr.erase();
	revstr=reverse1(names);
	ost<<revstr;

}

//Function to read the string to be reversed
void NameList::readinput(istream & ist)
{
	string line;
	if(ist)
	{
		while(!ist.eof())
		{
			getline(ist,line);
			names.push_back(line);
		}
	}
}

//static function for reversing the strings
//An iterator iterate through the elements in names vector
string NameList::reverse1(vector<string> x)
{
	string s2,str;
	for(vector<string>::iterator it=x.begin();it!=x.end();++it)
	{
		s2=*it;
		int len=s2.length();
		int read=len;
		for (int j=len-1;j>=0 ; --j)
		{
			str +=s2[j];
			read--;
		}
		if(read<len)
			str+="\n";
		cout<<endl;
	}
	return str;
}

//main function
int main()
{
	ifstream stream1 ("list1.txt");
	fstream stream2 ("list4.txt",ios::out|ios::app);
	NameList nl1,nl2;
	cout<<"Enter the name";
	nl1.readinput(cin);
	cout<<"The reverse string is: ";
	nl1.writeoutput(cout);
	cout<<"File operations: ";
	nl2.readinput(stream1);
	nl2.writeoutput(stream2);
	stream2.close();
	return 0;
}
