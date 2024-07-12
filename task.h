#ifndef TASK_H
#define TASK_H

#include "string"
#include "date.h"

using namespace std;

class Task
{
    friend class tasksWindow;
    friend class TWindow;
    string title;
    string List;
    string description;
    Date deadline;
    bool isDone;
    bool isStarred;
public:
    Task();
    void setTitle(string name);
    void setDescription(string des);
    void setList(string name);
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setIsDone(string b);
    void setIsStarred(string b);
    string getTitle();
    string getList();
    string getDescription();
    int getYear();
    int getMonth();
    int getDay();
    bool getIsDone();
    bool getIsStarred();
};

#endif // TASK_H
