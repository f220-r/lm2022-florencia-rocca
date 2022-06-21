#include <stdint.h>
#include <iostream>

uint16_t sgn[] = {
#include "sgn.h"
};

using namespace std;

int main(){
    for(int i = 0; i < 63; i++)
        cout << sgn[i] <<endl;
    return 0;
}