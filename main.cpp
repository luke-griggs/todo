#include <iostream>
#include "todoList.h"

int main()
{
    cout << "please enter the name of your list" << endl;
    string name;

    getline(cin, name);
    todoList* list = new todoList(name);

    list->run();

    delete list;

    return 0;
}

