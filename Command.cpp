#include <iostream>
#include <string>
#include <vector>
#include "CalendarApp.h"
using namespace std;

void help(CalendarApp calendar)
{
	string crrU;
	int command;
	string cDate;
	string cTime;
	int dur;
	string cUserN;
	string cNote;
	string cUser;

	cout << "Username: " << endl;
	cin >> crrU;
	for (int i = 0;i <calendar.getUsize();i++)
	{
		if (crrU == calendar.getUname())
		{
			calendar.setUser(i);
		}
	}
	cout << "1) create meeting" << endl;
	cout << "2) remove meeting" << endl;
	cout << "3) show meetings" << endl;
	cout << "4) create regular meeting" << endl;
	cout << "Enter command: " << endl;

	cin >> command;
	switch (command)
	{
	case 1:
		cin >> cDate;
		cin >> cTime;
		cin >> dur;
		cin >> cUserN;
		cin >> cNote;
		calendar.createMeeting(cDate, cTime, dur, cUserN, cNote);
	case 2:
		cin >> cDate;
		cin >> cTime;
		calendar.removeMeeting(cDate,cTime);
	case 3:
		cin >> cDate;
		calendar.showMeetings(cDate);
	case 4:

	}
}