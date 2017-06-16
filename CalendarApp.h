#pragma once
#include "Meeting.h"
#include "User.h"
#include <string>
using namespace std;

class CalendarApp
{
	vector <User*> users;
	vector<Meeting*> meets;
	User* currUser;
public:
	void setUser(int idx);
	int getUsize() const;
	string getUname();
	void createMeeting(string dat, string tim, int dur,
		string nam, string note);
	void removeMeeting(string, string);
	void showMeetings(string);
	//void createRegMeet();
	//void suggestMeet();
	void load();
	void save();
};
