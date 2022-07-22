#include <iostream>
#include <list>
#include "../List/stepandoublelist.h"

using namespace std;

int main(){
    SList<int> obj;
    const int SIZE = 10;
    for (int i = 0; i < SIZE; i++) {
        obj.push_back(i);
    }
    obj.print();

    obj.pop_back();

    obj.print();
    cout << endl;
    return 0;
}
