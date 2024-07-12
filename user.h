#ifndef USER_H
#define USER_H

#include "string"
#include "linklist.h"
#include "list.h"
#include <list>

using namespace std;

class User
{
    friend class MainWindow;
    friend class listsWindow;
    friend class tasksWindow;
    friend class TWindow;
    friend class StarWindow;
    friend class dutiesWindow;

    string username;
    string password;
    string email;
    LinkList <List> lists;
    LinkList <Task> tasks;

public:
    User();
    void setUsername(string username);
    void setPassword(string password);
    void setEmail(string email);

};

#endif // USER_H
