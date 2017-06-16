#include <iostream>
#include <fstream>
#include <string>
#include "CalendarApp.h"
using namespace std;

void CalendarApp::setUser(int idx)
{
	currUser = users[idx];
}
int CalendarApp::getUsize() const
{
	return users.size();
}
string CalendarApp::getUname()
{
	for (int i = 0;i < users.size();i++)
	{
		return users[i]->getName();
	}
}

void CalendarApp::createMeeting(string dat, string tim, int dur, string nam,
	string note)
{
	for (int i = 0;i < users.size();i++)
	{
		if (users[i])
		{
			Meeting* meet = new Meeting(dat,tim,dur,nam,note);
			users[i]->addMeeting(&meet);
			meet->addUser(*users[i]);
			meets.push_back(meet);
		}
		else cout << users[i]->getName() << " is not free!" << endl;
	}
}

void CalendarApp::removeMeeting(string dat, string tim)
{
	for (int i = 0;i < meets.size();i++)
	{
		if (meets[i]->getDate == dat && meets[i]->getTime() == tim)
		{
			for (int j = 0;j < meets[i]->getNumbersU();j++)
			{
				users[j]->removeMeeting(meets[i]);
			}
			int idx;
			int size = meets.size();
			for (int k = 0;k<size;k++)
			{
				if (meets[k] == meets[i])
				{
					idx = i;break;
				}
			}
			for (int j = idx;j < size - 1;j++)
			{
				meets[j] = meets[j + 1];
			}
			meets.pop_back();
		}
	}
}

void CalendarApp::showMeetings(string Date)
{
	string crrD;
	cout << "Enter date to see meetings:";
	cin >> crrD;
	cout << "Meetings for: " << crrD << endl;
	for (int i = 0;i < meets.size();i++)
	{
		if (crrD == meets[i]->getDate())
		{
			cout << "Meetings for " << crrD << endl;
			cout << meets[i]->getTime() << ", duration: " << " - " << meets[i]->getDur();
			for (int j = 0;j < meets[i]->getNumbersU();j++)
			{
				cout<<meets[i]->getUser(j);
			}
			cout << meets[i]->getNotes() << endl;
		}
	}
}

void CalendarApp::load()
{
	int usNumber;
	for (int i = 0;i < usNumber;i++)
	{
		users[i]->read();
	}
	int metNumber;
	for (int i = 0;i < metNumber;i++)
	{
		meets[i]->read();
	}
}
void CalendarApp::save()
{
	for (int i = 0;i < users.size();i++)
	{
		users[i]->write();
	}
	for (int i = 0;i < meets.size();i++)
	{
		meets[i]->write();
	}
}