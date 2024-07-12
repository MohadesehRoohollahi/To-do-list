#include "list.h"

List::List() {
}

void List::setTitle(string title)
{
    this->title = title;
}

void List::setColor(string color)
{
    this->color = color;
}

string List::getTitle()
{
    return this->title;
}

string List::getColor()
{
    return this->color;
}
