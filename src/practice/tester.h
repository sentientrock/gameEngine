#include <iostream>
using namespace std;

namespace tester
{
    int getBigger(int a, int b) {
        if (a > b) {
            return a;
        } 
        return b;
    }
}

class HelloWorld {
    public:
        int ret(int a, int b) {
            int c = tester::getBigger(a, b);
            return c;
        }
};
