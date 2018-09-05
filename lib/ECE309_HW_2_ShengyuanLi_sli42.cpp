/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Shengyuan Li
 *
 * Created on 2018年8月22日, 下午3:31
 */

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


class List {
private:
    class ListNode{
        private:
             string item; // data in the list
             ListNode *next;	
        public:
          ListNode(string a){

                item = a; 
                next=NULL; // automatically serves as a list tail
          }
          ListNode *getNext(){ 

            return next; 
          }
          void setNext(ListNode *n){ 

            next = n; 
          }
          string getItem(){ 

            return item; 
          }
    };
    ListNode *head;
    ListNode *tail;
public: 
   
    //empty list 
    List(){
        head = NULL;
        tail = NULL;
    }
    //Add a string to the tail of a list
    void push_back(string a){
        ListNode *node = new ListNode(a);
        if (head == NULL){
            head = node;
            tail = node;
        }
        else{
            tail -> setNext(node);
            tail = node;
        }
    }
    //Get the number of items in the list
    int length(){
        int i=0;
        ListNode *p = head;
        if (head == NULL)
            return 0;
        while (p != NULL){
            i++;
            p = p -> getNext();
                 
        }
        return i;
    }
    //Return a copy of the n-th item in the list
    string get(int n){
        int i ;//counter 
        string copy;
        int index = n-1;//make n an index for list
        ListNode *p = head;
        if (head == NULL || index<0 || n > length() )
            return NULL;
        
        for(i=0; i<index; i++){
            p = p->getNext();   
        }
        copy = p->getItem();
        return copy;
        
       
    }
    
    //Remove the head of the list and return a copy of the data that was removed
    string remove_front(){
        if (head == NULL)
            return NULL;
        else{
            string copy = head->getItem(); 
            ListNode *tmp = head->getNext();
            delete head;
            head = tmp;//update the head
            if (tmp == NULL)//removed the last element
                tail = NULL;
            return copy;
        }
    }
    //Deletes all of the nodes in the list 
    ~List(){
        ListNode *p = head;
        while(head != NULL){
            remove_front();
        }
    }
    
};
/*
 * 
 */

int main() {
   // List *a = new List ();
    //a -> push_back ("abc");
    //a -> push_back ("cat");
    //cout << a->get(2);
    //cout << a->remove_front();
    
    //a->~List();
    //cout << a->get(1);
    
    return 0;
    
   

}


