#include <iostream>
using namespace std;

class ABC{
    public:
     int x;

    protected:
     int y;

    private:
     int z;
}

class Child1: public ABC{
    //x will remain public
    //y will be protected
    //z will ve inaccessible
};
class Child2: protected ABC{
    //x will be protected
    //y will be protected
    //z will be inaccessible
};
class Child3: private ABC{
    //x will be private
    //y will be private
    //z will be inaccessible
}
int main(){
    ABC onj;
    onj.x //can be accesible as it is public specifiers
}