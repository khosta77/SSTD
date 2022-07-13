#include <iostream>
#include <vector>
#include "../Vector/stepanvector.h"

using namespace std;

//struct test {
//    int a;
//};

int main(){
//    test A;
//    A.a = 10;
    StepanVector<int> vec;
//    vec.push_back(A);

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    cout << "start\n";
    for (size_t i = 0; i < vec.size(); i++){
        cout << vec[i].x << " ";
    }
//    cout << endl;
//    StepanVector<int> vec2;
//
//    vec2 = vec;
//    cout << "vec2" << endl;
//    cout << vec2.size() << " " << vec.size() << endl;
//    for (size_t i = 0; i < vec2.size(); i++){
//        cout << vec2[i] << " ";
//    }

    StepanVector<int>::iterator it1 = vec.begin();
//    StepanVector<int>::iterator it2 = vec.end();
    cout << it1.data << endl;

//    for (StepanVector<int>::iterator it = vec.begin() ; it != vec.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';

    cout << endl;
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
