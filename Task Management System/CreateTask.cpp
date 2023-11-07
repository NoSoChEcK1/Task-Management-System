#include "CreateTask.h"
using namespace std;
CreateTask::CreateTask(string name, int day, int month, int year, string description) {
	this->name = name;
	this->day = day;
	this->month = month;
	this->year = year;
};
std::string CreateTask::getname() {
 return this->name;
}
int CreateTask::getday() {
	return this->day;
}
int CreateTask::getmonth() {
	return this->month;
}int CreateTask::getyear() {
	return this->year;
}
string CreateTask::getdescription() {
	return this->description;
}
void CreateTask::setday(int newday) {
	this->day = newday;
}
void CreateTask::setdescription(string newdescription) {
	this->description = newdescription;
}
void CreateTask::setmonth(int newmonth) {
	this->month = newmonth;
}
void CreateTask::setyear(int newyear) {
	this->year = newyear;
}
void CreateTask::setname(string newname) {
	this->name = newname;
}