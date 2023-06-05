#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, string>record;

    record.insert(make_pair(1,"ria"));
    record[3] = "pia";
    record[2] = "sia";

    for(auto elem:record){
        cout<<"Roll No - "<<elem.first<<endl;
        cout<<"Name - "<<elem.second<<endl;
    }

    return 0;
}