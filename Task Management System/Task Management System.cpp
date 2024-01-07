#include <iostream>
#include <vector>
#include "CreateTask.h"
//#define DEBUG
using namespace std; 
int main()
{
    bool close = true;
    int choose;
    vector<CreateTask>task;
    while (close) {
        cout << "\t 1: create a new task \t 2: view tasks \t 3: edit task \t 4: delete task \t 5: close" << endl;
        while (!(cin >> choose)) {
            cout << "error.enter again" << endl;;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choose) {
        case 1: {
            cin.ignore();
            cout << "task name " << endl;
            string name;
            getline(cin, name);
            cout << "enter the date : first the day, then the month and year" << endl;
            int day, month, year;
            while (!(cin >> day)) {
                cout << "error.enter again" << endl;;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            while (!(cin >> month)) {
                cout << "error.enter again" << endl;;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            while (!(cin >> year)) {
                cout << "error.enter again" << endl;;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
                if (day > 31)
                    day = 1;
                if (month > 12)
                    month = 1;
                string description;
                cout << "enter a description" << endl;
                cin.ignore();
                getline(cin, description);
                CreateTask newtask(name, day, month, year, description);
                task.push_back(newtask);
#ifdef DEBUG
                cout << task.size() << endl;
#endif // DEBUG
                break;
            }
        case 2: {
            if (task.size() == 0) {
                cout << "you have 0 tasks" << endl;
            }
            for (auto& taskItem : task) {

                cout << taskItem.getname() << " " << taskItem.getday() << "." << taskItem.getmonth() << "." << taskItem.getyear() << "\t";
            }
            cout << endl;
            break; }
        case 3: {
            cout << "you have " << task.size() << " task" << endl;
            int count = 0;
            for (auto& taskItem : task) {
                ++count;
                cout << count << " " << taskItem.getname() << "\t";
            }
            cout << "Which task do you want to change?" << endl;
            int numoftusk;
            while (!(cin >> numoftusk)) {
                std::cout << "error.enter again" << endl;;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            --numoftusk;
            if (numoftusk > task.size()&&numoftusk<=0) {
                break;
            }
            cout << task[numoftusk].getname() << " " << task[numoftusk].getday() << " " << task[numoftusk].getmonth() << " " << task[numoftusk].getyear() << " " << task[numoftusk].getdescription();
            cout << "if you want to change name:1,date:2,description:3" << endl;
            int whichtask;
            cin >> whichtask;
            switch (whichtask) {
            case 1: {
                string newname;
                cout << "write a new name" << endl;
                cin.ignore();
                getline(cin, newname);

                task[numoftusk].setname(newname);
                break; }
            case 2: {
                int newday, newmonth, newyear;
                cout << "write a new data" << endl;
                while (!(cin >> newday)) {
                    cout << "error.enter again" << endl;;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                while (!(cin >> newmonth)) {
                    cout << "error.enter again" << endl;;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                while (!(cin >> newyear)) {
                    cout << "error.enter again" << endl;;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                if (newday > 31)
                    newday = 1;
                if (newmonth > 12)
                    newmonth = 1;
                task[numoftusk].setday(newday); task[numoftusk].setmonth(newmonth); task[numoftusk].setyear(newyear);
                break; }
            case 3: {
                string newdescription;
                cout << "write a new description" << endl;
                cin.ignore();
                getline(cin, newdescription);
                task[numoftusk].setdescription(newdescription);
                break; }
            default: {
                break; }
            }
            break; }
        case 4: {
            cout << "you have " << task.size() << " task" << endl;
            int count = 0;
            for (auto& taskItem : task) {
                ++count;
                cout << count << " " << taskItem.getname() << "\t";
            }
            cout << "Which task do you want to delete?" << endl;
            int numoftusk;
            while (!(cin >> numoftusk)) {
                cout << "error.enter again" << endl;;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (numoftusk > task.size()&&numoftusk<=0)break;
            --numoftusk;
            auto it = task.begin();
            it += numoftusk;
            task.erase(it);
#ifdef DEBUG
            cout << task.size() << endl;
#endif // DEBUG
            break; }
        case 5: {
            close = false;
            break; }
        default:
            break;
        }
    }
}
