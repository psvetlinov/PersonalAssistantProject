#pragma once
#include "Meeting.h"
#include <vector>
#include <string>
using namespace std;
class User
{
	string name;
	vector<Meeting*> meetings;
	int index;
	
public:
	void addMeeting(Meeting&);
	void removeMeeting(Meeting& meet);
	void read();
	void write();
	string getName();
	friend istream& operator >> (istream& in, vector<Meeting*> elem);
	friend ostream& operator<<(ostream& out, vector<Meeting*> elem);
	
};
