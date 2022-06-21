#include <stdint.h>
#include <button.hpp>

using namespace button;

typedef enum {ACUMULAR, PROMEDIAR} states;

uint16_t sgn[] = {
#include "Python/sgn.h"
};

class S_Machine {
    private:
    uint32_t count;
    uint64_t adder;
    states state;
    uint32_t N;
    uint16_t size;

    public:
    S_Machine(uint32_t _N): N(_N){}
    ~S_Machine(){}

    void init(){
        adder = 0;
        count = 0;
        state = ACUMULAR;
        size = my_sizeof(sgn)/my_sizeof(sgn[0]);
        if(N > size)
            {
                printf("El numero de muestras solicitado supera el tamaño del archivo, se tomara como N el tamaño del array \n");
                N = size;
            }
    }

    void fsm(){
        switch (state)
        {
        case ACUMULAR:
            adder  += sgn[count];
            if(count == N)
                {
                    count = 0;
                    state = PROMEDIAR;
                }
            else
                count++;
            break;
        case PROMEDIAR:
            int avg = adder/N;
            printf("El promedio de las muestras para N=%d es: %2.f", N,avg);
            count = 0;
            state = ACUMULAR;
        }
    }
}