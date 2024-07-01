#include <iostream>
#include "stack_b.h"
#include <stdexcept>
using namespace std;

Stack_B :: Stack_B(){
    try{
    stk=new int[1024];
    capacity=1024;
    size=0;
    }
    catch(bad_alloc){
      throw runtime_error("Out of Memory");
}
    }
Stack_B :: ~Stack_B(){
    delete[] stk;
}

void Stack_B :: push(int data){
 try{
 if(size==capacity){
    int* temp=new int[capacity*2];
    for(int i=0;i<capacity;i++){
        temp[i]=stk[i];
    }
    capacity=capacity*2;
    delete[] stk;
    stk=temp;
 }
    stk[size++]=data;
} catch(bad_alloc){
   throw runtime_error("Out of Memory");
}
}

int Stack_B :: pop(){
    try{
    if(size==0){
        throw runtime_error("Empty Stack");
    }else{
      int x=stk[size-1];
      if(size>=1024 && size==(capacity/2)+1){
        int* temp=new int[capacity/2];
        for(int i=0;i<(capacity/2);i++){
            temp[i]=stk[i];
        }
        capacity=capacity/2;
        delete[] stk;
        stk=temp;
      }
        size=size-1;
      return x;
    }
} catch(bad_alloc){
    throw runtime_error("Out of Memory");
}
}

int Stack_B :: get_element_from_top(int idx){
    if(size<=idx || idx<0){
        throw runtime_error("Index out of range");
    }else{
    return stk[size-idx-1];
    }
}

int Stack_B :: get_element_from_bottom(int idx){
    if(size<=idx || idx<0){
        throw runtime_error("Index out of range");
    }else{
    return stk[idx];
    }
}

void Stack_B :: print_stack(bool top_or_bottom){
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

int Stack_B :: add(){
    if(size>=2){
    int x= pop();
    int y=pop();
    push(x+y);
    return x+y;
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_B :: subtract(){
    if(size>=2){
    int x= pop();
    int y=pop();
    push(y-x);
    return y-x;
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_B :: multiply(){
    if(size>=2){
    int x= pop();
    int y=pop();
    push(x*y);
    return x*y;
    }else{
        throw runtime_error("Not Enough Arguments");
    }
}

int Stack_B :: divide(){
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

int* Stack_B :: get_stack(){
    int* p= stk;
    return p;
}

int Stack_B :: get_size(){
    return size;
}


