#include <stdio.h>
#include <stdlib.h>

int main(){

    int edad = 0;

    printf("ingrese su edad: ");
    scanf("%d", &edad);



                 if ((edad > 0) && (edad <= 1)){
                            printf("Usted es recien un nacido");
                    } else if((edad >= 1) && (edad <= 12)){
                                printf("Usted es un infante");
                        }else if((edad >= 12) && (edad <= 18)){
                                printf("Usted es recien un Adolecente");
                            }else if((edad >= 18) && (edad <= 35)){
                                    printf("Usted es recien un Joven mayor");
                                }else if((edad >= 35) && (edad <= 65)){
                                        printf("Usted es recien un Adulto mayor");
                                    }else if((edad >= 65) && (edad <= 125)){
                                        printf("Usted es recien un Adulto de la 3ra edad");
                                    }else{
                                            printf("Usted escribio un disparate.");
                                        }

    return 0;


}
