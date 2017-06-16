#include <iostream>
#include <cstring>
#include <fstream>
#include "User.h"
using namespace std;

void User::addMeeting(Meeting& meet)
{
	meetings.push_back(&meet);
}

void User::removeMeeting(Meeting& meet)
{
	int idx;
	int size = meetings.size();
	for(int i=0;i<size;i++)
	{
	if (meetings[i] == &meet)
		{
			idx = i;break;
		}
	}
	for (int j = idx;j < size - 1;j++)
	{
		meetings[j] = meetings[j + 1];
	}
	meetings.pop_back();
	
}

istream& operator >> (istream& in, vector<Meeting*> elem)
{
	in >> elem;
	return in;
}
ostream& operator<<(ostream& out, vector<User*> elem)
{
	out << elem;
	return out;
}

void User::read()
{
	ifstream fin("myfile.txt");
	fin >> name;
	fin >> meetings;
	fin >> index;	
	fin.close();
}

void User::write()
{
	ofstream fout("myfile.txt");
	fout << name.size() << ' ' << name << ' ';
	fout << meetings << ' ' << index << ' ';
	fout.close();
}
string User::getName()
{
	return name;
}
