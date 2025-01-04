#include "todoList.h"
#include <iostream>
#include <sstream>

todoList::todoList(string n) : listName(n) {}

int todoList::addItem(string itemName) {
    listItem* item = new listItem(itemName);
    list.push_back(item);
    this->size += 1;
    return SUCCESS;
}

int todoList::removeItem(int itemNumber) {
    if (itemNumber < 1 || itemNumber > this->size) {
        cout << "the number entered is outside the range of the list" << endl;
        return FAILURE;
    }

    int idx = itemNumber - 1;
    listItem* item_ptr = list[idx];
    list.erase(list.begin() + idx);
    this->size -= 1;
    delete item_ptr; // deallocate the memory that item was using

    return SUCCESS;
}

void todoList::listItems() {
    if (list.size() > 0) {
        cout << "here are the items on your to-do list" << endl;
    }

    cout << endl; // blank line
    for(int i = 0; i < list.size(); ++i) {
        cout << to_string(i + 1) + ". ";
        list[i]->display();
    }
}

void todoList::help() {
    cout << "to add an item, enter 'add <item name>'" << endl;
    cout << "to remove an item, enter 'remove <item name>'" << endl;
}

void todoList::run() {
    cout << "Welcome to your to-do list!" << endl;
    help();
    cout << "if you forget these instructions, just enter HELP" << endl;

    while (true) {

        listItems();

        string userInput;
        getline(cin, userInput);

        if (userInput.find(" ") == string::npos) { // user input was one word
            if (userInput == "HELP") {
                help();
            } else {
                cout << "invalid argument" << endl;
                help();
            }
        }

        else { // user input was more than one word
            istringstream ss(userInput);
            string firstWord;
            ss >> firstWord;
            if (firstWord == "add") {
                string restOfInput;
                getline(ss, restOfInput);
                addItem(restOfInput);

            } else if(firstWord == "remove") {
                int numToRemove;
                ss >> numToRemove;

                if (removeItem(numToRemove) == SUCCESS) {
                    cout << "item removed successfully" << endl;
                } else {
                    cout << "an error occurred while removing that item" << endl;
                }

            } else {
                cout << "invalid argument" << endl;
                help();
            }
        }
    }
}
