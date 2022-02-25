//
//  RetryCode.h
//  CircularDoublyLL
//
//  Created by Jose Saldivar on 10/4/19.
//  Copyright © 2019 Jose Javier Saldivar. All rights reserved.
//

#ifndef RetryCode_h
#define RetryCode_h

class DLL
{
private:
    struct Node
    {
        int value;
        Node *next, *prev;
    };
    Node *first, *last;
    
public:
    DLL();
    void append(int);
    void insert(int);
    void print();
};

DLL::DLL()
{
    first = last = nullptr;
}
void DLL::append(int i)
{
    Node *n = new Node;
    n->value = i;
    n->next = n->prev;
    
    if(first == nullptr)
    {
        first = last = n;
    }
    else
    {
        n->prev = last;
        last->next = n;
        n->next = first->prev;
        first->prev = n->next;
        last = n;
    }
}
void DLL::insert(int i)
{
    Node *n = new Node;
    n->value = i;
    n->next = n->prev;
    
    if(head == nullptr)
    {
        first = last = n;
    }
    else
    {
        i->next = first;
        first->prev = i;
        i->prev = last->next;
        last->next = i->prev;
    }
}
void DLL::print()
{
    Node *p = first;
    if(first == nullptr)
    {
        cout << "Nothing in list";
    }
    do
    {
        cout << p->value << endl;
        p = p->next;
    }
    while(p != first)
}

#endif /* RetryCode_h */
