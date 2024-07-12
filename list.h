#ifndef LIST_H
#define LIST_H

#include "string"
#include "linklist.h"
#include "task.h"
#include <list>

using namespace std;

class List
{

    friend class MainWindow;
    friend class tasksWindow;
    friend class TWindow;

    string title;
    string color;

public:
    List();
    void setTitle(string title);
    void setColor(string color);
    string getTitle();
    string getColor();

};

#endif // LIST_H
