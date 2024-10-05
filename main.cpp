#include <iostream>
#include "list.h";
using namespace std;

int main() {
    List L;
    L.push_front(1);
    L.push_front(0);
    L.push_back(3);
    L.push_back(4);
    L.insert(2, 2);

    Node *h = L.getHead();
    while (h != NULL) {
        cout<<h->getData()<<" ";
        h = h->next;
    }
    cout<<endl;

    cout<<L.recursiveSearch(3);
    return 0;
}
