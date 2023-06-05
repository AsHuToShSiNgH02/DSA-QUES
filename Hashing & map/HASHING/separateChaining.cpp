#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Hashing{
    vector<list<int>> hashtable;
    int bucket;
    public:
    Hashing(int size){
        bucket = size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key%10; //division method
    }

    void addKey(int key){
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);
    }

    void deleteKey(int key){
        int idx = hashvalue(key);
        if(searchKey(key)!=hashtable[idx].end()){
            hashtable[idx].erase(searchKey(key));
            cout<<"Key is deleated"<<endl;
        }else{
            cout<<"key is not present";
        }
    }
};
int main(){
    Hashing h(10);

    h.addKey(5);
    h.addKey(9);
    h.addKey(8);

    h.deleteKey(5);
    h.deleteKey(5);

    return 0;

}