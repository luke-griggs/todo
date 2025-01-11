#ifndef TODOLIST_H
#define TODOLIST_H
#include <string>
#include <vector>
#include "listItem.h"

using namespace std;

enum status {
    SUCCESS = 0,
    FAILURE = 1
};

class todoList {
public:
    todoList(string name);
    ~todoList() = default;
    int addItem(string itemName);
    int removeItem(int itemNumber);
    int editItem(int itemNumber, string newTaskName);
    void listItems();
    void run();
    void help();


private:
    vector<listItem*> list;
    string listName;
    int size;
};

#endif //TODOLIST_H