#pragma once
#include "User.h"
#include <vector>
#include <string>
using namespace std;
class Meeting
{
	string date;
	string time;
	int duration;
	vector <User*> users;
	string notes;
public:
	Meeting();
	Meeting(string, string, int, string, string);
	string getDate();
	string getTime();
	string getNotes();
	string getUser(int idx);
	int getNumbersU() const;
	int getDur() const;
	void addUser(User&);
	void removeUser(User&);
	bool cross(Meeting& meet);
	void read();
	void write();
	friend ostream& operator<<(ostream& out, vector<User*> elem);
	friend istream& operator >> (istream& in, vector<User*> elem);
};
