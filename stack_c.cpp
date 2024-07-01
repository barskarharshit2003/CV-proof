#include "stack_c.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_C :: Stack_C(){
    try{
    stk= new List();
    } catch(bad_alloc){
        throw runtime_error("Out of Memory");
    }
}

void Stack_C :: push(int data){
  stk->insert(data);
}

int Stack_C :: pop(){
  if(stk->get_size()==0){
    throw runtime_error( "Empty Stack");
  }else{
  return stk->delete_tail();
  }
}

int Stack_C :: get_element_from_top(int idx){
  int x=stk->get_size();
  if(idx<(x) && idx>=0){
   Node* p = stk->get_head();
   int y=0;
   while(y!=x-idx){
    p=p->next;
    y=y+1;
   }
   return p->get_value();
}else{
    throw runtime_error("Index out of range");
}
}

int Stack_C :: get_element_from_bottom(int idx){
  if(idx<(stk->get_size()) && idx>=0){
   Node* p = stk->get_head();
   int x=0;
   while(x!=idx+1){
    p=p->next;
    x=x+1;
   }
   return p->get_value();
} else{
    throw runtime_error("Index out of range");
}
}

void Stack_C :: print_stack(bool top_or_bottom){
  if(!top_or_bottom){
    Node* temp=stk->get_head();
    temp=temp->next;
    while(!temp->is_sentinel_node()){
       cout<<temp->get_value()<<"\n";
       temp=temp->next;
    }
}else{
    Node* temp=stk->get_head();
    temp=temp->next;
    while(!temp->is_sentinel_node()){
       temp=temp->next;
    }
    temp=temp->prev;
     while(!temp->is_sentinel_node()){
       cout<<temp->get_value()<<"\n";
       temp=temp->prev;
    }
}
}

int Stack_C :: add(){
    int size=stk->get_size();
    if(size>=2){
    int x= pop();
    int y=pop();
    push(x+y);
    return x+y;
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_C :: subtract(){
    int size=stk->get_size();
    if(size>=2){
    int x= pop();
    int y=pop();
    push(y-x);
    return y-x;
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_C :: multiply(){
   int size=stk->get_size();
   if(size>=2){
    int x= pop();
    int y=pop();
    push(x*y);
    return x*y;
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_C :: divide(){
    int size=stk->get_size();
    if(size>=2){
    int x= pop();
    int y=pop();
    if(x*y<0){
        push(int(y/x)-1);
        return int(y/x)-1;
    }else if (x==0){
        throw runtime_error("Divide by Zero Error");
    }else{
        push(int(y/x));
        return int(y/x);
    }
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

List* Stack_C :: get_stack(){
    List* p=stk;
    return p;
}

int Stack_C :: get_size(){
    return stk->get_size();
}

Stack_C :: ~Stack_C(){
    while(get_size()!=0){
        int x = pop();
    }
    delete stk;
}



