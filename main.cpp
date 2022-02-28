#include <iostream>
#include <stepanvector.h>

using namespace std;

int main(){
    StepanVector lst;
    cout << "start\n";
    for (int i = 0; i < 10; i++){
        lst.push_first(i);
    }
    lst.print();
    lst.print(false);
    cout << endl;
    for (int i = 9; i >= 0; i--){
        cout << lst.at(i)->data << " ";
    }

//    for (int i = 0; i < 10; i++){
//        lst.push_last(i);
//    }
//    lst.print();
//    lst.print(false);
    cout << "end\n";
    return 0;
}
