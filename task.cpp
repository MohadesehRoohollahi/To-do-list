#include "task.h"

Task::Task() {
    isDone = false;
    isStarred = false;
}

void Task::setTitle(string name)
{
    this->title = name;
}

void Task::setDescription(string des)
{
    this->description = des;
}

void Task::setList(string name)
{
    this->List = name;
}

void Task::setYear(int year)
{
    this->deadline.year = year;
}

void Task::setMonth(int month)
{
    this->deadline.month = month;
}

void Task::setDay(int day)
{
    this->deadline.day = day;
}

void Task::setIsDone(string b)
{
    if(b == "1")
        this->isDone = true;
    else
        this->isDone = false;
}

void Task::setIsStarred(string b)
{
    if(b == "1")
        this->isStarred = true;
    else
        this->isStarred = false;
}

string Task::getTitle()
{
    return this->title;
}

string Task::getList()
{
    return this->List;
}

string Task::getDescription()
{
    return this->description;
}

int Task::getYear()
{
    return this->deadline.year;
}

int Task::getMonth()
{
    return this->deadline.month;
}

int Task::getDay()
{
    return this->deadline.day;
}

bool Task::getIsDone()
{
    return this->isDone;
}

bool Task::getIsStarred()
{
    return this->isStarred;
}

