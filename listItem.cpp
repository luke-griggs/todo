#include "listItem.h"
#include <string>
#include <iostream>

listItem::listItem(string n) : name(n){}


void listItem::display() {
    cout << name << endl;
}

string listItem::getName() {
    return this->name;
}

