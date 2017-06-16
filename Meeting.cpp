#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "Meeting.h"
using namespace std;

Meeting::Meeting()
{
	duration = 0;
}
Meeting::Meeting(string d, string t, int dur, string us, string n)
{
	date = d;
	time = t;
	duration = dur;
	notes = n;
}

string Meeting::getDate() 
{
	return date;
}
string Meeting::getTime() 
{
	return time;
}
int Meeting::getDur() const

{
	return duration;
}
void Meeting::addUser(User& user)
{
	users.push_back(&user);
}

void Meeting::removeUser(User& user)
{
	int idx;
	int size = users.size();
	for (int i = 0;i<size;i++)
	{
		if (users[i] == &user)
		{
			idx = i;break;
		}
	}
	for (int j = idx;j < size - 1;j++)
	{
		users[j] = users[j + 1];
	}
	users.pop_back();
}
ostream& operator<<(ostream& out, vector<User*> elem)
{
	out << elem;
	return out;
}
istream& operator >> (istream& in, vector<User*> elem)
{
	in >> elem;
	return in;
}
void Meeting::read()
{
	ifstream fin("myfile.txt");
	fin >> date;
	fin >> time;
	fin >> duration;
	fin >> users;
	fin >> notes;
	fin.close();
}
void Meeting::write()
{
	ofstream fout("myfile.txt");
	int dSize = date.size();
	fout << date.size() << ' ' << date << ' ';
	fout << time.size() << ' ' << time << ' ';
	fout << duration;
	fout << users << ' ';
	fout << notes.size() << ' ' << notes << ' ';
	fout.close();
}
string Meeting::getUser(int idx)
{
	return users[idx]->getName();
}
string Meeting::getNotes()
{
	return notes;
}
int Meeting::getNumbersU() const
{
	return users.size();
}
bool Meeting::cross(Meeting& meet)
{
	if (meet.time >= time && meet.time <= time + duration)
	{
		return true;
	}
	return false;
}



