#include <iostream>

using namespace std;

void print_result_test(int valid, char* name) {
    if(valid)
        cout << "[\033[1;32mOK\033[0m]" << name << endl;
    else
        cout << "[\033[1;31mKO\033[0m]" << name << endl;
}