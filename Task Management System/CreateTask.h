#pragma once
#include <string>
using namespace std;
	class CreateTask
	{
	public:
		CreateTask(string name, int day, int month, int year, string description);
		int getday();
		int getmonth();
		int getyear();
		string getname();
		string getdescription();
		void setday(int newday);
		void setdescription(string newdescription);
		void setyear(int newyear);
		void setmonth(int newmonth);
		void setname(string newname);
	private:
		string name, description;
		int day, month, year;
	};

