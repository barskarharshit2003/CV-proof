#include "Comp.h"

void Comp::Sort(std::vector<int> &v) {
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
Comp::Comp(){
        int i=0;
        std::vector<Account> account;
        while (i<1000){
              bankStorage2d.push_back(account);
              i++;
        }
    }

void Comp::createAccount(std::string id, int count) {
    int i = hash(id);
    Account NewAccount;
    NewAccount.id = id;
    NewAccount.balance = count;
    bankStorage2d[i].push_back(NewAccount);
}

std::vector<int> Comp::getTopK(int k) {
    std::vector<int> diary;
    for (int i = 0; i < bankStorage2d.size(); i++){
        for (int j = 0; j < bankStorage2d[i].size(); j++){
            diary.push_back(bankStorage2d[i][j].balance);
            }
        }
        Sort(diary);
        std::vector<int> topK;
        for (int y = diary.size()-1 ; y>=0 && y>=diary.size()-k ; y--){
            topK.push_back(diary[y]);
        }
    return topK; 
}

int Comp::getBalance(std::string id) {
    int i = hash(id);
    for (int j = 0; j < bankStorage2d[i].size(); j++)
    {
        if (bankStorage2d[i][j].id == id){
            return bankStorage2d[i][j].balance;
        }
    }
    return -1;
}

void Comp::addTransaction(std::string id, int count) {
    int i = hash(id);
    if (!doesExist(id)){
        createAccount(id,count);
    }
    else {
    for (int j = 0; j < bankStorage2d[i].size(); j++)
        {
            if (bankStorage2d[i][j].id == id ){
                bankStorage2d[i][j].balance += count;
            }
        }
    }
}

bool Comp::doesExist(std::string id) {
    int i = hash(id);
    for (int j = 0; j < bankStorage2d[i].size(); j++)
    {
        if (bankStorage2d[i][j].id == id){
            return true;
        }
    }
    return false;
}

bool Comp::deleteAccount(std::string id) {
    int i = hash(id);
    for (int j = 0; j < bankStorage2d[i].size(); j++)
    {
        if (bankStorage2d[i][j].id == id){
            bankStorage2d[i].erase(bankStorage2d[i].begin()+j);
            return true;
        }
    }
    return false; 
}
int Comp::databaseSize() {
   int x = 0;
    for (int i = 0; i < bankStorage2d.size(); i++){
        x=x+bankStorage2d[i].size();
    }
    return x; 
}

int Comp::hash(std::string id) {
        int hashValue=0;
        for (int i=0;i<22;i++) {
        hashValue = hashValue  + (id[i]*i);
    }
    return hashValue%1000;
    }
   