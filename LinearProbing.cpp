#include "LinearProbing.h"

void LinearProbing::Sort(std::vector<int> &v) {
        for (int i = 1; i < v.size(); i++) {
            int temp = v[i];
            int j = i - 1;
            
            while (j >= 0 && v[j] > temp) {
                v[j + 1] = v[j];
                j--;
            }
            v[j+1] = temp;
        }
    }
LinearProbing::LinearProbing(){
    int i=0;
        Account account;
        account.id="z";
        while (i<100003){
              bankStorage1d.push_back(account);
              i++;
        }
    }

void LinearProbing::createAccount(std::string id, int count) {
    int i = hash(id);
    Account NewAccount;
    NewAccount.id = id;
    NewAccount.balance = count;
    while (bankStorage1d[i].id != "z" && bankStorage1d[i].id !="-1") {
        i = (i + 1) % 100003; 
    }
    bankStorage1d[i]=NewAccount;
}
std::vector<int> LinearProbing::getTopK(int k) {
    std::vector<int> diary;
    for (int i = 0; i < bankStorage1d.size(); i++){
            if (bankStorage1d[i].id != "z" && bankStorage1d[i].id != "-1"){
            diary.push_back(bankStorage1d[i].balance);
        }
    }
    Sort(diary);
    std::vector<int> topK;
        for (int y = diary.size()-1 ; y>=0 && y>=diary.size()-k ; y--){
            topK.push_back(diary[y]);
        }
    return topK; 
    
}
int LinearProbing::getBalance(std::string id) {
    int i = hash(id); 
    while (bankStorage1d[i].id != "z") {
        if (bankStorage1d[i].id == id) {
            return bankStorage1d[i].balance;
        }
        i = (i + 1) % 100003; 
    }
    return -1;
}
void LinearProbing::addTransaction(std::string id, int count) {
    int i = hash(id);
    if (!doesExist(id) ){
        createAccount(id,count);
    }
    else {
        while(bankStorage1d[i].id != id){
            i = (i + 1) % 100003;
        }
        bankStorage1d[i].balance += count;
    }
}
bool LinearProbing::doesExist(std::string id) {
    int i = hash(id); 
    while (bankStorage1d[i].id != "z") {
        if (bankStorage1d[i].id == id) {
            return true;
        }
        i = (i + 1) % 100003; 
    }
    return false;
}
bool LinearProbing::deleteAccount(std::string id) {
    int i = hash(id); 
    while (bankStorage1d[i].id != "z") {
        if (bankStorage1d[i].id == id) {
            bankStorage1d[i].id="-1";
            return true;
        }
        i = (i + 1) % 100003; 
    }
    return false;
}
int LinearProbing::databaseSize() {
    int x=0;
    for (int i = 0; i < bankStorage1d.size(); i++){
        if (bankStorage1d[i].id != "z" && bankStorage1d[i].id !="-1"){
        x=x+1;
        }
    }
    return x; 
}
int LinearProbing::hash(std::string id) {
    int hashValue=0;
        for (int i=0;i<22;i++) {
        hashValue = hashValue  + (id[i]*i);
    }
     return hashValue%100003;
}
    


