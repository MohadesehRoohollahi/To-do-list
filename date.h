#ifndef DATE_H
#define DATE_H

class Date
{
    friend class tasksWindow;
    friend class Task;
    int day;
    int month;
    int year;

public:
    Date();
};

#endif // DATE_H
