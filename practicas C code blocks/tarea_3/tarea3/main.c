
// 3.1
/*
   #include <stdio.h>
    void main()
    {

            // Nómina.
            // El programa, al recibir los salarios de 15 profesores, obtiene el total de la ➥nómina de la universidad.
            // I: variable de tipo entero. SAL y NOM: variables de tipo real.
            int I;
            float SAL, NOM; NOM = 0;

                for (I=1; I<=15; I++){
                printf("\Ingrese el salario del profesor%d:\t", I);
                scanf("%f", &SAL); NOM = NOM + SAL;
                }
                printf("\nEl total de la nómina es: %.2f", NOM);
    }
*/
// 3.2
/*
    #include <stdio.h>
    // Suma positivos.
    // El programa, al recibir como datos N números enteros, obtiene la suma de los ➥enteros positivos.
    // I, N, NUM, SUM: variables de tipo entero.
    void main(void){
        int I, N, NUM, SUM; SUM = 0;
        printf("Ingrese el número de datos:\t");
        scanf("%d", &N); for (I=1; I<=N; I++){
            printf("Ingrese el dato número %d:\t", I);
            scanf("%d", &NUM);
        if (NUM >  0)
            SUM = SUM + NUM;
        }
        printf("\nLa suma de los números positivos es: %d", SUM);
    }

*/
// 3.3
/*
    #include <stdio.h>
    // Suma pagos.
    // El programa, al recibir como datos un conjunto de pagos realizados en el último ➥mes, obtiene la suma de los mismos. PAG y SPA: variables de tipo real.
    void main(void){
        float PAG, SPA; SPA = 0;
        printf("Ingrese el primer pago:\t");
        scanf("%f", &PAG);
        while (PAG)    // Observa que la condición es verdadera mientras el pago es diferente de cero.
        {
            SPA = SPA + PAG;
            printf("Ingrese el siguiente pago:\t ");
            scanf("%f", &PAG);
        // Observa que la proposición que modifica la condición es una lectura.
        }
        printf("\nEl total de pagos del mes es: %.2f", SPA);
    }
*/
//3.4
/*
    #include <stdio.h>
    #include <math.h>
    // Suma cuadrados.
    // El programa, al recibir como datos un grupo de enteros positivos, obtiene el ➥cuadrado de los mismos y la suma correspondiente a dichos cuadrados.
    void main(void){
        int NUM; long CUA, SUC = 0;
        printf("\nIngrese un número entero -0 para terminar-:\t");
        scanf("%d", &NUM);
        while (NUM)// Observa que la condición es verdadera mientras el entero es diferente de cero.
        {
            CUA = pow (NUM, 2);
            printf("%d al cubo es %ld", NUM, CUA); SUC = SUC + CUA; printf("\nIngrese un número entero -0 para terminar-:\t"); scanf("%d", &NUM);
        }
        printf("\nLa suma de los cuadrados es %ld", SUC);
    }
*/
//3.5
/*
    #include <stdio.h>
    // Suma pagos.
    // El programa obtiene la suma de los pagos realizados el último mes. PAG y SPA: variables de tipo real.
    void main(void){
        float PAG, SPA = 0;
        printf("Ingrese el primer pago:\t");
        scanf("%f", &PAG);  //Observa que al utilizar la estructura do-while al menos se necesita un pago.
        do{
            SPA = SPA + PAG;
            printf("Ingrese el siguiente pago  -0 para terminar-:\t "); scanf("%f", &PAG);
        }
        while (PAG);
        printf("\nEl total de pagos del mes es: %.2f", SPA);
    }


*/
//3.6
/*

    #include <stdio.h>
    // Nómina de profesores.
    // El programa, al recibir como datos los salarios de los profesores de una ➥universidad, obtiene la nómina y el promedio de los salarios.
    // I: variable de tipo entero.
    // SAL, NOM y PRO: variables de tipo real.
    void main(void){
        int I = 0;
        float SAL, PRO, NOM = 0;
        printf("Ingrese el salario del profesor:\t");
        // Observa que al menos se necesita ingresar el salario de un profesor para que ➥no ocurra un error de ejecución del programa.
         scanf("%f", &SAL); do
        {
        NOM = NOM + SAL; I = I + 1; printf("Ingrese el salario del profesor -0 para terminar- :\t"); scanf("%f", &SAL);
        } while (SAL); PRO = NOM / I; printf("\nNómina: %.2f \t Promedio de salarios: %.2f", NOM, PRO);
    }
*/
//3.7
/*
    #include <stdio.h>
    // Lanzamiento de martillo.
    // El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio ➥de los lanzamientos de la atleta cubana.
    // I, N: variables de tipo entero. LAN, SLA: variables de tipo real.
    void main(void){
        int I, N; float LAN, SLA = 0;
        do{
            printf("Ingrese el número de lanzamientos:\t"); scanf("%d", &N);
        }
        while (N < 1 || N > 11);             //Se utiliza la estructura do-while para verificar que el valor de N sea ➥correcto.
        for (I=1; I<=N; I++){
            printf("\nIngrese el lanzamiento %d: ", I);
            scanf("%f", &LAN); SLA = SLA + LAN;
        }
        SLA = SLA / N; printf("\nEl promedio de lanzamientos es: %.2f", SLA);
    }
*/
//3.8
/*
    # include <stdio.h>
    // Factorial.
    // El programa calcula el factorial de un número entero. FAC, I, NUM: variables de tipo entero.
    void main(void){
        int I, NUM; long FAC;
        printf("\nIngrese el número: ");
        scanf("%d", &NUM); if (NUM >= 0) {
            FAC = 1; for (I=1; I <= NUM; I++)
            FAC *= I; printf("\El factorial de %d es: %ld", NUM, FAC);
        }
        else printf("\nError en el dato ingresado");
     }

*/
//3.9
/*
    #include <stdio.h>
    // Serie.
    // El programa imprime los términos y obtiene la suma de una determinada serie. I, SSE y CAM: variable de tipo entero.
    void main(void){
        int I = 2, CAM = 1; long SSE = 0; while (I <= 2500)
        {
        SSE = SSE + I; printf("\t %d", I);
        if (CAM)
        {
        I += 5;
        CAM--;
        } else
        {
        I += 3;
        CAM++;
        }
        }
        printf("\nLa suma de la serie es: %ld", SSE);
    }

*/
//3.10

    #include <stdio.h>
    #include <math.h>
    // Pares e impares.
    // El programa, al recibir como datos N números enteros, obtiene la suma de los ➥números pares y calcula el promedio de los impares. I, N, NUM, SPA, SIM, CIM: variables de tipo entero.
    void main(void){
        int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;
        printf("Ingrese el número de datos que se van a procesar:\t");
        scanf("%d", &N); if (N > 0){
            for (I=1; I <= N; I++){
                printf("\nIngrese el número %d: ", I);
                scanf("%d", &NUM);
                if (NUM)if (pow(-1, NUM) > 0)
                    SPA = SPA + NUM;
                else{
                        SIM = SIM + NUM;
                        CIM++;
                    }
            }
            printf("\n La suma de los números pares es: %d",SPA);
            printf("\n El promedio de números impares es: %5.2f",(float)(SIM / CIM);
        }
        else printf("\n El valor de N es incorrecto");
    }



