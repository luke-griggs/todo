#ifndef LISTITEM_H
#define LISTITEM_H

#include <string>
using namespace std;

class listItem {
public:
    listItem(string name);
    ~listItem() = default;
    void display();
    string getName();

private:
    string name;
    string priority;
};

#endif //LISTITEM_H
