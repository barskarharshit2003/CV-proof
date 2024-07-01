#include "node.h"

Node :: Node(bool sentinel){
    is_sentinel=sentinel;
}

Node :: Node(int v, Node* nxt, Node* prv){
    value=v;
    next=nxt;
    prev=prv;
    is_sentinel=false;
}

bool Node :: is_sentinel_node(){
    if(is_sentinel){
        return true;
    } else{
        return false;
    }
}
int Node :: get_value(){
    return value;
}