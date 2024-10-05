#include<iostream>
using namespace std;
#include <__stddef_null.h>
class List;
class Node{
    int data;
    public:
    Node* next;
    Node(int d):data(d),next(NULL){}
    int getData() {
        return data;
    }

    friend class List;
    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};
class List {
    Node *head;
    Node *tail;


    int searchHelper(Node * start, int key) {
        if (start == NULL) {
            return -1;
        }
        if(start->data == key) {
            return 0;
        }
        int subIndex = searchHelper(start->next, key);
        if (subIndex == -1) {
            return -1;
        }
        return subIndex + 1;
    }
    public:
    List():head(NULL),tail(NULL){}
    Node * getHead() {
        return head;
    }
    void push_front(int data) {
        if(head == NULL) {
            Node *n = new Node(data);
            head = tail = n;
        }
        else {
            Node *n = new Node(data);
            n->next = head;
            head = n;

        }
    }
    void push_back(int data) {
        if(head == NULL) {
            Node *n = new Node(data);
            head = tail = n;
        }
        else {
            Node *n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    void insert(int data, int pos) {
        if(pos == 0) {
            push_front(data);
            return;
        }
        Node *temp = head;
        for(int i = 1; i <= pos-1; i++) {
            temp = temp->next;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }


    int recursiveSearch(int data) {
        int index = searchHelper(head, data);
        return index;
    }
    ~List() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }
};
