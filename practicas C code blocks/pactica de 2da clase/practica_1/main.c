#include <stdio.h>
 #include <math.h>

 /* Función matemática. El programa obtiene el resultado de una función.
 OP y T: variables de tipo entero. RES: variable de tipo real. */

int main()
{
    printf("Hello world!\n");

     int OP, T;
     float RES;

     printf("Ingrese la opción del cálculo y el valor entero: ");
     scanf("%d %d", &OP, &T);


    if(OP == 1){
        RES = T / 5;
        printf("\nResultado division: %1.2f", RES);
    }else if(OP == 2){
            RES = pow(T,T);
            printf("\nResultado division: %1.2f", RES);
        }else if(OP == 3){
                printf(":)");
            }else if(OP == 4){
                     RES = 6 * T / 2;
                     printf("\nResultado division: %1.2f", RES);
                }else{
                    RES = 1 ;
                    printf("\nResultado division: %1.2f", RES);
                    }


     /*

         switch(OP){
            case 1: RES = T / 5;
                  break; //rompe el switch
            case 2: RES = pow(T,T);
                 /* La función pow está definida en la biblioteca math.h
                 break;
            case 3:
            case 4: RES = 6 * T/2;
                 break;
            default: RES = 1;
                break;
             }
      */

 //printf("\nResultado:   %7.2f", RES);

 return 0;
}

