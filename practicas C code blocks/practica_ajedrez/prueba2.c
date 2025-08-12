
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void main()
{

        char *comandos_blancas[8] = {"tqb","cqb","aqb","qb","rb","arb","crb","trb"};
        char *peones_blancas[8] = {"pb1","pb2","pb3","pb4","pb5","pb6","pb7","pb8"};

        char *comandos_negros[8] = {"tqn","cqn","aqn","qn","rn","arn","crn","trn"};
        char *peones_negros[8] = {"pn1","pn2","pn3","pn4","pn5","pn6","pn7","pn8"};
        char *f_asignadas[8] = {"a","b","c","d","e","f","g","h"};
        char *c_asignacion[8] ={"1","2","3","4","5","6","7","8"};
        char *tableroDeJuego[8][8];
        char *tablero[8][8] = {"a1","a2","a3","a4","a5","a6","a7","a8"
                                ,"b1","b2","b3","b4","b5","b6","b7","b8"
                                    ,"c1","c2","c3","c4","c5","c6","c7","c8"
                                        ,"d1","d2","d3","d4","d5","d6","d7","d8"
                                            ,"e1","e2","e3","e4","e5","e6","e7","e8"
                                                ,"f1","f2","f3","f4","f5","f6","f7","f8"
                                                    ,"g1","g2","g3","g4","g5","g6","g7","g8"
                                                        ,"h1","h2","h3","h4","h5","h6","h7","h8"};

        char from[3];
        char to[3];


        int historial_blancas = 0;
        int historial_negras = 0;
        int f,c,a,b,cb,pb,cn,pn;

        srand(time(NULL)); //Generamos numero aleatorio en base al tiempo
        	int numero_random = rand() % 2; //Variable donde se guardará nuestro numero aleatorio, Le indicamos que el numero será entre 0-10


void mover_piezas(){



    int stop = 1;
    f=0;c=0;
    float algo = 1;

    printf("Mover (ej: e2 e4): ");
    scanf("%s %s", from, to);

    printf("\n empezamos\n");


    if(from != NULL){
        for(f = 0; stop ==1;f++){
            for(c = 0; stop ==1;c++){
                printf("\n %s \n %s \n", tablero[f][c], from);
                if(from != tablero[f][c]){
                    printf("\n no encontre semejanza \n");

                }else if(from == tablero[f][c]){
                    stop = 0;
                    printf("\n pieza encontrada\n");
                    printf("\n %s \n", tablero[f][c]);

                    printf("\n %s \n", from);
                    printf("\n idiota\n");
                }

            }
        }
    }else{ printf("pieza no encontrada");}
}











void imprimir_piesas(){
      if (numero_random != 0){
       tablero[0][0] = comandos_negros[0];
       tablero[0][1] = comandos_negros[1];
       tablero[0][2] = comandos_negros[2];
       tablero[0][3] = comandos_negros[3];
       tablero[0][4] = comandos_negros[4];
       tablero[0][5] = comandos_negros[5];
       tablero[0][6] = comandos_negros[6];
       tablero[0][7] = comandos_negros[7];

       tablero[1][0] = peones_negros[0];
       tablero[1][1] = peones_negros[1];
       tablero[1][2] = peones_negros[2];
       tablero[1][3] = peones_negros[3];
       tablero[1][4] = peones_negros[4];
       tablero[1][5] = peones_negros[5];
       tablero[1][6] = peones_negros[6];
       tablero[1][7] = peones_negros[7];

       tablero[7][0] = comandos_blancas[0];
       tablero[7][1] = comandos_blancas[1];
       tablero[7][2] = comandos_blancas[2];
       tablero[7][3] = comandos_blancas[3];
       tablero[7][4] = comandos_blancas[4];
       tablero[7][5] = comandos_blancas[5];
       tablero[7][6] = comandos_blancas[6];
       tablero[7][7] = comandos_blancas[7];

       tablero[6][0] = peones_blancas[0];
       tablero[6][1] = peones_blancas[1];
       tablero[6][2] = peones_blancas[2];
       tablero[6][3] = peones_blancas[3];
       tablero[6][4] = peones_blancas[4];
       tablero[6][5] = peones_blancas[5];
       tablero[6][6] = peones_blancas[6];
       tablero[6][7] = peones_blancas[7];
     }else{
       tablero[0][0] = comandos_blancas[0];
       tablero[0][1] = comandos_blancas[1];
       tablero[0][2] = comandos_blancas[2];
       tablero[0][3] = comandos_blancas[3];
       tablero[0][4] = comandos_blancas[4];
       tablero[0][5] = comandos_blancas[5];
       tablero[0][6] = comandos_blancas[6];
       tablero[0][7] = comandos_blancas[7];

       tablero[1][0] = peones_blancas[0];
       tablero[1][1] = peones_blancas[1];
       tablero[1][2] = peones_blancas[2];
       tablero[1][3] = peones_blancas[3];
       tablero[1][4] = peones_blancas[4];
       tablero[1][5] = peones_blancas[5];
       tablero[1][6] = peones_blancas[6];
       tablero[1][7] = peones_blancas[7];

       tablero[7][0] = comandos_negros[0];
       tablero[7][1] = comandos_negros[1];
       tablero[7][2] = comandos_negros[2];
       tablero[7][3] = comandos_negros[3];
       tablero[7][4] = comandos_negros[4];
       tablero[7][5] = comandos_negros[5];
       tablero[7][6] = comandos_negros[6];
       tablero[7][7] = comandos_negros[7];

       tablero[6][0] = peones_negros[0];
       tablero[6][1] = peones_negros[1];
       tablero[6][2] = peones_negros[2];
       tablero[6][3] = peones_negros[3];
       tablero[6][4] = peones_negros[4];
       tablero[6][5] = peones_negros[5];
       tablero[6][6] = peones_negros[6];
       tablero[6][7] = peones_negros[7];
     }

    printf("ESTE SON LAS POSICIONES DEL TABLERO \n\n\n");
        for(f = 0; f<8; f++){
            for(c = 0; c<8; c++){
                    printf("%s" , tablero[f][c]);
                    printf("  ");
            }printf("\n");
        }printf("\n\n");
        printf("recuerda las piezas");
        printf("precione una tecla para continuar...");
        _sleep(1);

    mover_piezas();
}

void imprimir_tablero(){
    printf("ESTE SON LAS POSICIONES DEL TABLERO \n\n\n");
        for(f = 0; f<8; f++){
                for(c = 0; c<8; c++){
                    printf("%s" , tablero[f][c]);
                    printf("  ");
                }printf("\n");
        }printf("\n\n");
    system("pause");
    printf("precione una tecla para continuar...");

    system("clear");
    imprimir_piesas();
}

imprimir_tablero();

}
