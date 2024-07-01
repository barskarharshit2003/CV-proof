#include "list.h"
#include <stdexcept>
using namespace std;

List :: List(){
    try{
    sentinel_head=new Node();
    sentinel_tail=new Node();
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
    size=0;
    } catch(bad_alloc){
        throw runtime_error("Out of Memory");
    }
}

void List :: insert(int v){
    try{
    Node* x= new Node(v,sentinel_tail,sentinel_tail->prev);
    (sentinel_tail->prev)->next=x;
    sentinel_tail->prev=x;
    size=size+1;
    } catch(bad_alloc){
        throw runtime_error("Out of Memory");
    }
}

int List :: delete_tail(){
   Node* t=sentinel_tail->prev;
   int x= t->get_value();
   sentinel_tail->prev=t->prev;
   (t->prev)->next=sentinel_tail;
   delete t;
   size=size-1;
   return x;
}

int List :: get_size(){
     return size;
}

Node* List :: get_head(){
    Node* p= sentinel_head;
    return p;
}

List :: ~List(){
   while(sentinel_tail->prev!=sentinel_head){
    delete_tail();
   }
   delete sentinel_head;
   delete sentinel_tail;
}