#include <iostream>
#include "list.h";
using namespace std;

int main() {
    List L;
    L.insert(10);
    L.insert(5);
    L.insert(9);
    L.insert(7);
    L.insert(6);
    L.insert(30);
    L.insert(33);
    L.insert(25);

    cout<<"printing list before any operation"<<endl;

    Node *h = L.getHead();
    while (h != nullptr) {
        cout<<h->getData()<<" ";
        h = h->next;
    }
    cout<<endl;

    L.deleteItem(7);
    L.deleteItem(5);

    cout<<"printing list after deleting 5 and 7 from the list"<<endl;

    h = L.getHead();
    while (h != nullptr) {
        cout<<h->getData()<<" ";
        h = h->next;
    }
    cout<<endl;

    L.deleteTail();
    cout<<"printing list after deleting tail from the list"<<endl;

    h = L.getHead();
    while (h != nullptr) {
        cout<<h->getData()<<" ";
        h = h->next;
    }
    cout<<endl;

    L.deleteHead();
    cout<<"printing list after deleting head from the list"<<endl;

    h = L.getHead();
    while (h != nullptr) {
        cout<<h->getData()<<" ";
        h = h->next;
    }
    cout<<endl;

    cout<<endl;

    cout<<"printing result for searching 3 in the list"<<endl;
    if (L.recursiveSearch(3) == 1) {
        cout<<"found"<<endl;
    }
    else {
        cout<<"not found"<<endl;
    }

    cout<<"printing result for searching 10 in the list"<<endl;
    if (L.recursiveSearch(10) == 1) {
        cout<<"found"<<endl;
    }
    else {
        cout<<"not found"<<endl;
    }
    return 0;
}
