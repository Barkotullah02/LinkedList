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

    /*
     * using searchHelper() private method to help searching an item in the linked list
     */
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

    /*
     * initializing a list in time of creation
     */
    List():head(NULL),tail(NULL){}

    /*
     * creating a getter for getting head
     */
    Node * getHead() {
        return head;
    }

    /*
     * implepenting push_front() method for unsorted linked list
     */
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

    /*
     * implepenting push_back() method for unsorted linked list
     */
    // void push_back(int data) {
    //     if(head == NULL) {
    //         Node *n = new Node(data);
    //         head = tail = n;
    //     }
    //     else {
    //         Node *n = new Node(data);
    //         tail->next = n;
    //         tail = n;
    //     }
    // }


    /*
     * creating insert() method for unsorted linked list
     */
    // void insert(int data, int pos) {
    //     if(pos == 0) {
    //         push_front(data);
    //         return;
    //     }
    //     Node *temp = head;
    //     for(int i = 1; i <= pos-1; i++) {
    //         temp = temp->next;
    //     }
    //     Node *n = new Node(data);
    //     n->next = temp->next;
    //     temp->next = n;
    // }


    int recursiveSearch(int key) {
        int index = searchHelper(head, key);
        return index;
    }
    /*
     * creating destructor
     */
    ~List() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

    /*
     * inser
     */
    void insert(int data)
    {
        Node* current;
        /* Special case for the head end */
        if(head == NULL) {
            Node *n = new Node(data);
            head = tail = n;
        }
        else if (data < head->data) {
            push_front(data);
        }
        else {
            Node* n = new Node(data);
            /* Locate the node before the
            point of insertion */
            current = head;
            while (current->next != NULL  && current->next->data   < data) {
                current = current->next;
            }
            n->next = current->next;
            current->next = n;
        }
    }

    void deleteHead() {
        if (head != NULL) {
            head = head->next;
        }
    }

    void deleteItem(int item) {
        if(item == head->data) {
            deleteHead();
        }
        /*
        *Detecting if the item is equals to tail. If so then just call the method deleteTail()
        */
        else if(item == tail->data) {
            deleteTail();
        }
        else {
            Node *current = head;
            Node *prev = NULL;
            Node *next = NULL;
            while (current->next != NULL && current->next->data != item) {
                current = current->next;
                prev = current;
                next = current->next->next;
            }
            prev->next = next;
            current = nullptr;

        }
    }
    void deleteTail() {
        Node* second_last = head;
        while (second_last->next->next != nullptr) {
            second_last = second_last->next;
        }
        delete second_last->next;
        second_last->next = nullptr;
    }


};
