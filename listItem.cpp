#include "listItem.h"
#include <string>
#include <iostream>

#include "todoList.h"

listItem::listItem(string n) : name(n){}


void listItem::display() {
    cout << name << endl;
}

int listItem::setName(string newName) {
    this->name = newName;
    return SUCCESS;
}


string listItem::getName() {
    return this->name;
}


