#include <iostream>
#include <set>
using namespace std;

int main(){
    // set<int> set1; //by default set store value in inc value
    set<int,greater<int>> set1; //to store value in dec order

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);

    cout<<set1.size()<<endl;

    // set<int>::iterator itr;
    //******printing element with for loop****
    // for(itr = set1.begin();itr != set1.end();itr++){
    //     cout<<*itr<<" ";
    // }
    
    //******printing element with for each loop******
    for(auto value:set1){
        cout<<value<<" ";
    }cout<<endl;

    
    //******deleating the element******
    //1
    // set1.erase(4); 
    //2
    // auto itr = set1.begin();
    // advance(itr,3); //to move poiter 3 step ahead
    // set1.erase(itr);
    //3
    // auto start_itr = set1.begin();
    // start_itr++;

    // auto end_itr = set1.begin();
    // advance(end_itr,3);

    // set1.erase(start_itr,end_itr);

    //*****search operation******
    if(set1.find(7)!= set1.end()){
        cout<<"present";
    }else{
        cout<<"absent";
    }
    
    
}