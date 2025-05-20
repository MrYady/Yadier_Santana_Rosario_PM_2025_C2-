#include <stdio.h>
#include <stdlib.h>

int main(){

    float x = 0;
    float b = 0;
    printf("Ingresa el numero:\n");
    scanf("%f", &x);

    b = x;

    while(!(b == (x/b))){
        b = (0.5 *((x/b)+b));
    };

    printf("\n Raiz de %f es: ",x,b);
    return 0;
};
