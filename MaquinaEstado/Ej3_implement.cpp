#include <iostream>
#include "Ej3.hpp"

using namespace std;

int main(){
    S_Machine Maquina(25);
    Maquina.init();
    while(1){
        Maquina.fsm();
    }
    return 0;
}