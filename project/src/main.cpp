#include <iostream>
#include "../include/stepanvector.h"

using namespace std;

struct test {
    int a;
};

int main(){
    test A; A.a = 10;
    StepanVector<test> lst;
    cout << "start\n";
    lst.push_back(A);
    cout << lst[0].a << endl;
//    for (int i = 0; i < 10; i++){
//        lst.push_first(i);
//    }
//    lst.print();
//    lst.print(false);
//    cout << endl;
//    for (int i = 9; i >= 0; i--){
//        cout << lst.at(i)->data << " ";
//    }

//    for (int i = 0; i < 10; i++){
//        lst.push_last(i);
//    }
//    lst.print();
//    lst.print(false);
    cout << "end\n";
    return 0;
}
