#include <iostream>
#include "practice\tester.h"

using namespace std;
using namespace tester;

int main() {

    HelloWorld world;
    int a = 1;
    int b = 2;
    cout << world.ret(a, b) << endl;

    return 0;

}