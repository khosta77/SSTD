#include <iostream>
#include <vector>
#include "../Vector/stepanvector.h"

using namespace std;

int main(){
    StepanVector<int> vec(5);

    int* p = vec.data();

    *p = 10;
    ++p;
    *p = 20;
    p[2] = 100;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<vec.size(); ++i)
        std::cout << ' ' << vec[i];
    std::cout << '\n';

    return 0;
}
