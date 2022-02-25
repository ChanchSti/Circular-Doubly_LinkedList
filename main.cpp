// Jose Javier Saldivar
//  main.cpp
//  CircularDoublyLL
//
//  Created by Jose Saldivar on 10/3/19.
//  Copyright © 2019 Jose Javier Saldivar. All rights reserved.
//

#include <iostream>
using namespace std;

class DoublyLL {
    
private:
    struct Node {
        
        int value;
        Node *next, *prev;
    };
    Node *first, *last;
    
public:
    DoublyLL();
    void append(int);
    void insert(int);
    void print();
};

DoublyLL::DoublyLL()
{
    first = last = nullptr;
}
void DoublyLL::append(int n)      // appends new node to end of the list
{
    Node *i = new Node;
    i -> value = n;
    i -> next = i -> prev;
    
   if (first == nullptr)
   {
       first = last = i;
   }
   else
   {
       i -> prev = last;
       last -> next = i;
       i -> next = first -> prev;
       first -> prev = i -> next;
       last = i;
   }
    
}
void DoublyLL::insert(int n)      // inserts new node in the front of list
{
    
    Node *i = new Node;
    i -> value = n;
    i -> next = i -> prev;
    //i -> next = i -> prev  = nullptr;
    
    if(first == nullptr)
    {
        first = last = i;
    }
    else
    {
        /*  test 1
        Node *i = new Node;
        i -> value = n;
        i -> next = first;      // 1
        first -> prev = i -> next;
        i -> prev = last;
        last -> next = i -> prev;
        first = i;
         */
        i -> next = first;
        first -> prev = i;
        i -> prev = last -> next;
        last -> next = i -> prev;
        first = i;
    }
}
void DoublyLL::print()
{
    Node *pointer = first;
    if(first == nullptr)
    {
        cout << "Nothing to print" << endl;
    }
    do
    {
        cout << pointer -> value << endl;
        pointer = pointer -> next;
    }
    while(pointer != first);
}






int main() {
    
    DoublyLL run;
    
    run.append(8);
    run.insert(6);
    run.append(4);      // 4 does not get appended because its looping
    run.insert(2);
    

    run.print();
    
}
