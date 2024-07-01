#include <iostream>
#include "stack_a.h"
#include <stdexcept>
using namespace std;

Stack_A :: Stack_A(){
    size=0;
}

void Stack_A :: push(int data){
 if(size==1024){
    throw runtime_error("Stack Full");
 }else{
    stk[size++]=data;
 }
}

int Stack_A :: pop(){
    if(size==0){
        throw runtime_error("Empty Stack");
    }else{
      return stk[--size];
    }
}

int Stack_A :: get_element_from_top(int idx){
    if(size<=idx || idx<0){
        throw runtime_error("Index out of range");
    }else{
    return stk[size-idx-1];
    }
}

int Stack_A :: get_element_from_bottom(int idx){
    if(size<=idx || idx<0){
        throw runtime_error("Index out of range");
    }else{
    return stk[idx];
    }
}

void Stack_A :: print_stack(bool top_or_bottom){
    if(!top_or_bottom){
        for(int i=0;i<size;i++){
            cout<<stk[i]<<"\n";
        }
    }else{
        for(int i=0;i<size;i++){
            cout<<stk[size-i-1]<<"\n";
        }
    }
}
int Stack_A :: add(){
    if(size>=2){
    stk[size-2]=stk[size-1]+stk[size-2];
    size=size-1;
    return stk[size-1];
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_A :: subtract(){
    if(size>=2){
    stk[size-2]=stk[size-2]-stk[size-1];
    size=size-1;
    return stk[size-1];
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_A :: multiply(){
    if(size>=2){
    stk[size-2]=stk[size-1]*stk[size-2];
    size=size-1;
    return stk[size-1];
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_A :: divide(){
    if(size>=2){
    int x=pop();
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

int* Stack_A :: get_stack(){
    int* p= stk;
    return p;
}

int Stack_A :: get_size(){
    return size;
}