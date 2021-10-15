#include<bits/stdc++.h>
#include "intSLLst.h"
using namespace std;
    IntSLList::~IntSLList(){
        for(IntNode *p; !isEmpty();){
            p = head -> next;
            delete head;
            head = p;
        }
    }
    void IntSLList::addToHead(int el){
        head = new IntNode(el,head);
        if(tail == 0)
            tail = head;
    }
    void IntSLList::addToTail(int el){
        if(tail != 0){
            tail->next = new IntNode(el);
            tail = tail->next;
        }else{
            head = tail = new IntNode(el);
        }
    }
    int IntSLList::deleteFromHead(){
        int el = head->info;
        IntNode *temp = head;
        if(head == temp) head = tail= 0;
        else head = head->next;
        delete temp;
        return el;
    }
    int IntSLList::deleteFromTail(){
        int el = tail->info;
        if(head == tail){
            delete head;
            head = tail = 0;
        }else{
            IntNode *temp;
            for(temp=head; temp->next != tail; temp=temp->next);
            delete tail;
            tail = temp;
            tail->next = 0;
        }
        return el;
    }
    void IntSLList::deleteNode(int el){
        if(head != 0){
            if(head == tail && el == head->info){
                delete head;
                head = tail =0;
            }else if(el == head->info){
                IntNode *temp = head->next;
                head = head->next;
                delete temp;
            }else{
                IntNode *pred, *temp;
                for(pred = head,temp = head->next;temp !=0 && !(temp -> info == el);pred = pred->next,temp = temp->next);
                if(temp != 0) {
                    pred->next = temp->next;
                    if(temp == tail) {
                        tail = pred;
                    }
                    delete temp;
                }
            }
        }
}
bool IntSLList::isInList(int el) const{
        IntNode *temp;
        for(temp = head;temp != 0 && !(temp -> info == el);temp = temp->next);
        return temp!=0;
}

void IntSLList::printSL(){
    while (head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
    
}

// void printList(Node* n)
// {
//     while (n != NULL) {
//         cout << n->data << " ";
//         n = n->next;
//     }
// }