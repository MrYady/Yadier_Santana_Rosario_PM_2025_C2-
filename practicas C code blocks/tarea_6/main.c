// TAREA 6
/*
// 6.1
 #include <stdio.h>
 // Diagonal principal.
 // El programa, al recibir como dato una matriz de tipo entero, escribe la
 // diagonal principal.
 const int TAM = 10;
 void Lectura(int [][TAM], int);     // Prototipo de funciones
 void Imprime(int [][TAM], int);
 // Observa que siempre es necesario declarar el número de columnas. Si no lo
 // haces, el compilador marcará un error de sintaxis.
 void main(void)
 {
 int MAT[TAM][TAM];
 Lectura(MAT, TAM);
 Imprime(MAT, TAM);
 }
 void Lectura(int A[][TAM], int F)
 // La función Lecturase utiliza para leer un arreglo bidimensional. Observa
 // que sólo se debe pasar como parámetro el número de filas ya que la matriz
 // es cuadrada.
 {
 int I, J;
 for(I=0; I<F; I++)
 for(J=0; J<F; J++)
 {
 printf("Ingrese el elemento %d %d: ", I+1, J+1);
 scanf("%d", &A[I][J]);
 }
 }
 void Imprime(int A[][TAM], int F)
 // La función Imprime se utiliza para escribir un arreglo bidimensional
 // cuadrado de F filas y columnas.
 {
 int I, J;
 for (I=0; I<F; I++)
 for (J=0; J<TAM; J++)
 if (I == J)
 printf("\nDiagonal %d %d: %d ", I, J, A[I][J]);
 }
*/
 // 6.2
/*
 #include <stdio.h>
// Suma matrices.
// El programa, al recibir como datos dos arreglos bidimensionales del mismo
// tamaño, calcula la suma de ambos y la almacena en un tercer arreglo
// bidimensional.
 const int MAX = 50;
 // Prototipo de funciones.
 void Lectura(int [][MAX], int, int);
 void Suma(int[][MAX], int[][MAX], int[][MAX], int, int);
 void Imprime(int [][MAX], int, int);
 void main(void)
 {
 int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
// Declaración de los tres arreglos
 int FIL, COL;
 do
 {
 printf("Ingrese el número de filas de los arreglos: ");
 scanf("%d", &FIL);
 }
  while(FIL> MAX && FIL < 1);
// Se verifica que el número de filas sea correcto.
 do
 {
 printf("Ingrese el número de columnas de los arreglos: ");
 scanf("%d", &COL);
 }
 while (COL > MAX && COL < 1);
// Se verifica que el número de columnas sea correcto.
 printf("\nLectura del Arreglo MA\n");
 Lectura(MA, FIL, COL);
 printf("\nLectura del Arreglo MB\n");
 Lectura(MB, FIL, COL);
 Suma (MA, MB, MC, FIL, COL);
 printf("\nImpresión del Arreglo MC\n");
 Imprime (MC, FIL, COL);
 }
 void Lectura(int A[][MAX], int F, int C)
 // La función Lecturase utiliza para leer un arreglo bidimensional entero de F
 // filas y Ccolumnas.
 {
 int I, J;
 for (I=0; I<F; I++)
 for(J=0; J<C; J++)
 {
 printf("Ingrese el elemento %d %d: ", I+1, J+1);
 scanf("%d", &A[I][J]);
 }
 }
 void Suma(int M1[][MAX],int M2[][MAX],int M3[][MAX], int F, int C)
 // La función Sumase utiliza para sumar los arreglos y almacenar el resultado
 // en un tercer arreglo bidimensional.
 {
 int I, J;
 for (I=0; I<F; I++)
 for (J=0; J<C; J++)
 M3[I][J]= M1[I][J] + M2[I][J];
 }
 void Imprime(int A[][MAX], int F, int C)
 // La función Imprimese utiliza para escribir un arreglo bidimensional de tipo
 // entero de Ffilas y Ccolumnas.
 {
 int I, J;
 for (I=0; I<F; I++)
 for (J=0; J<C; J++)
 printf("\nElemento %d %d: %d ", I, J, A[I][J]);
 }
*/
 // 6.3
/*
 #include <stdio.h>
// Universidad.
// El programa, al recibir información sobre el número de alumnos que han ingresado
// a sus ocho diferentes carreras en los dos semestres lectivos de los últimos
// cinco años, obtiene información útil para el departamento de escolar.
 const int F = 8, C = 2, P = 5;
// Se declaran constantes para la fila, la columna y la profundidad.
void Lectura(int [][C][P], int, int, int);
void Funcion1(int[][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int[][C][P], int, int, int);
// Prototipo de funciones. Cada prototipo de función corresponde a uno de los
// incisos.
 void main(void)
 {
 int UNI[F][C][P];
 Lectura(UNI, F, C, P);
 Funcion1(UNI, F, C, P);
 Funcion2(UNI, F, C, P);
 Funcion3(UNI, 6, C, P);
 Funcion3(UNI, 6, C, P);
// Se coloca el 6como parámetro ya que es la clave de la Ingeniería en
// Computación.
 }
 void Lectura(int A[][C][P], int FI, int CO, int PR)
 // La función Lecturase utiliza para leer un arreglo tridimensional de tipo
 // entero de FIfilas, COcolumnas y PRprofundidad. Observa que al ser
 // tridimensional se necesitan tres ciclos para recorrer el arreglo.
 {
 int K, I, J;
 for(K=0; K<PR; K++)
 for(I=0; I<FI; I++)
 for(J=0; J<CO; J++)
 {
 printf("Año: %d\tCarrera: %d\tSemestre: %d  ", K+1, I+1, J+1);
 scanf("%d", &A[I][J][K]);
 }
 }
 void Funcion1(int A[][C][P],int FI, int CO, int PR)
 // Esta función se utiliza para determinar el año en el que ingresó el mayor
 // número de alumnos a la universidad. Observa que el primer ciclo externo
 // corresponde a los años.
 {
 int K, I, J, MAY = 0, AO = -1, SUM;
 for (K=0; K<PR; K++)
// Por cada año se suma el ingreso de los dos semestres de las ocho carreras.

 {
 SUM = 0;
 for (I=0; I<FI; I++)
 for (J=0; J<CO; J++)
 SUM += A[I][J][K];
 if (SUM > MAY)
 {
 MAY = SUM;
 AO = K;
 }
 }
 printf("\n\nAño con mayor ingreso de alumnos: %d    Alumnos: %d", AO+1, MAY);
 }
 void Funcion2(int A[][C][P],int FI, int CO, int PR)
 // Esta función se utiliza para determinar la carrera que recibió el mayor
 //número de alumnos el último año. Observa que no se utiliza un ciclo para los
 // planos de la profundidad, ya que es un dato (PR).
{
 int I, J, MAY = 0, CAR = -1, SUM;
 for (I=0; I<FI; I++)
 {
 SUM = 0;
 for (J=0; J<CO; J++)
 SUM += A[I][J][PR-1];
 if (SUM > MAY)
 {
 MAY = SUM;
 CAR = I;
 }
 }
 printf("\n\nCarrera con mayor número de alumnos: %d  Alumnos: %d", CAR+1,
MAY);
 }
 void Funcion3(int A[][C][P],int FI, int CO, int PR)
 // Esta función se utiliza para determinar el año en el que la carrera
 // Ingeniería en Computación recibió el mayor número de alumnos. Observa que no
 // se utiliza un ciclo para trabajar con las filas, ya que es un dato (FI).
{
 int K, J, MAY = 0, AO = -1, SUM;
 for (K=0; K<PR; K++)
 {
 SUM = 0;
 for (J=0; J<CO; J++)
 SUM += A[FI-1][J][K];
 if (SUM > MAY)
 {
 MAY = SUM;
 AO = K;
 }
 }
 printf("\n\nAño con mayor ingreso de alumnos: %d   Alumnos: %d", AO+1, MAY);
 }
*/
 // 6.4

/*
  #include <stdio.h>
 // Simétrico.
 //El programa, al recibir como dato un arreglo bidimensional cuadrado, determina
 //si el mismo es simétrico.
 const int MAX = 100;
 void Lectura(int [][MAX], int);      // Prototipos de funciones.
 int Simetrico(int[][MAX], int);
 void main(void)
 {
 int MAT[MAX][MAX], N, RES;
 do
 {
 printf("Ingrese el tamaño del arreglo: ");
 scanf("%d", &N);
 }
 while (N > MAX && N < 1);   // Se verifica que el tamaño del arreglo sea válido.
 Lectura (MAT, N);
 RES = Simetrico(MAT, N);
 if(RES)
 printf("\nEl arreglo bidimensional es simétrico");
 else
 printf("\nEl arreglo bidimensional no es simétrico");
 } void Lectura(int A[][MAX], int T)
 // La función Lectura se utiliza para leer un arreglo bidimensional cuadrado de
 // tipo entero de Tfilas y Tcolumnas.
 {
 int I , J;
 for(I=0; I<T; I++)
 for(J=0; J<T; J++)
 {
 printf("Fila: %d\tColumna: %d", I+1, J+1);
 scanf("%d", &A[I][J]);
 }
 }
 int Simetrico (int A[][MAX], int T)
 // La función Simétricose utiliza para determinar si el arreglo bidimensional
 // cuadrado es simétrico. Si es simétrico regresa 1, en caso contrario, 0.
 // Observa que en el segundo ciclo solamente se recorre la matriz triangular
 // inferior, sin la diagonal principal.
{
 int I = 0, J, F = 1;
 while ((I < T) && F)
 {
 J = 0;
 while((J < I) && F)
 if(A[I][J] == A[J][I])
 J++;
 else
 F = 0;
 I++;
 }
 return (F);
 }
*/

 // 6.5
/*
 #include <stdio.h>
// Alumnos.
// El programa, al recibir un arreglo bidimensional que contiene información
// sobre calificaciones de alumnos en cuatro materias diferentes, obtiene
// resultados estadísticos.
 const int MAX = 50;
 const int EXA = 4;
 void Lectura(float[MAX][EXA], int);
 void Funcion1(float[MAX][EXA], int);          // Prototipos de funciones.
 void Funcion2(float[MAX][EXA], int);
 void main(void)
 {
 int NAL;
 float ALU[MAX][EXA];
 do
 {
 printf("Ingrese el número de alumnos del grupo: ");
 scanf("%d", &NAL);
 }     // Se verifica que el número de alumnos del grupo sea válido.
 while (NAL > MAX || NAL < 1);
 Lectura(ALU, NAL);
 Funcion1(ALU, NAL);
 Funcion2(ALU, NAL);
 }
 void Lectura(float A[][EXA], int N)
 // La función Lecturase utiliza para leer un arreglo bidimensional de tipo
 // real de Nfilas y EXA columnas.
 {
 int I, J;
 for(I=0; I<N; I++)
 for(J=0; J<EXA; J++)
 {
 printf("Ingrese la calificación %d del alumno %d: ", J+1, I+1);
 scanf("%f", &A[I][J]);
 }
 }
 void Funcion1(float A[][EXA], int T)
 // Esta función se utiliza para obtener el promedio de cada estudiante.
 {
 int I, J;
 float SUM, PRO;
 for(I=0; I<T; I++)
 {
 SUM = 0;
 for(J=0; J<EXA; J++)
 SUM += A[I][J];
 PRO = SUM / EXA;
 printf("\nEl promedio del alumno %d es: %5.2f", I+1, PRO);
 }
 }
 void Funcion2(float A[][EXA], int T)
 // Esta función se utiliza tanto para obtener el promedio de cada examen, así
 // como también el examen que obtuvo el promedio más alto.
 {
 int I, J, MAY;
 float SUM, PRO, MPRO = 0;
 printf("\n");
 for(J=0; J<EXA; J++)
 {
 SUM = 0;
 for(I=0; I<T; I++)
 SUM += A[I][J];
 PRO = SUM / T;
 if(PRO > MPRO)
 {
 MPRO = PRO;
 MAY = J;
 }
 printf("\nEl promedio del examen %d es: %f", J+1, PRO);
 }
 printf("\n\nEl examen con mayor promedio es: %d \t Promedio: %5.2f", MAY+1, MPRO);
 }
*/
 // 6.6
/*
  #include <stdio.h>
 // Intercambia.
 // El programa intercambia las columnas de un arreglo bidimensional. Los
 // elementos de la primera columna se intercambian con los de la última,
 // los de la segunda con los de la penúltima, y así sucesivamente.
 const int MAX = 50;
 void Lectura(float[][MAX], int, int);
 void Intercambia(float[][MAX], int, int);       // Prototipos de funciones.
 void Imprime(float[][MAX], int, int);
 void main(void)
 {
 int F, C;
 float MAT[MAX][MAX];
 do
 {
 printf("Ingrese el número de filas: ");
 scanf("%d", & F);
 }
 while (F > MAX && F < 1);  // Se verifica que el número de filas sea correcto.
 do
 {
 printf("Ingrese el número de columnas: ");
 scanf("%d", &C);
 }
  while (C > MAX && C < 1);  // Se verifica que el número de columnas seacorrecto.
 Lectura(MAT, F, C);
 Intercambia(MAT, F, C);
 Imprime(MAT, F, C);
 }
 void Lectura(float A[][MAX], int F, int C)
 // La función Lectura se utiliza para leer un arreglo bidimensional de tipo real de Ffilas y Ccolumnas.
 {
 int I, J;
 for(I=0; I< F; I++)
 for(J=0; J<C; J++)
 {
 printf("Ingrese el elemento %d %d:  ", I+1, J+1);
 scanf("%f", &A[I][J]);
 }
 }
 void Intercambia(float A[][MAX], int F, int C)
// Esta función se utiliza para intercambiar las columnas del arreglo
// bidimensional. Observa que el índice correspondiente a las columnas sólo se
// mueve hasta la mitad del arreglo.
 {
 int I, J;
 float AUX;
 // Observa que en esta función el índice I se utiliza para las columnas, y el índice J para las filas.
 for (I=0; I < (C / 2); I++)
 for (J=0; J< F; J++)
 {
 AUX = A[J][I];
 A[J][I] = A[J][C-I-1];
 A[J][C-I-1]=AUX;
 }
 }
 void Imprime(float A[][MAX], int F, int C)
 // La función Imprime se utiliza para escribir un arreglo bidimensional de tipo real de F filas y C columnas.
 {
 int I, J;
 for (I=0; I< F; I++)
 for (J=0; J<C; J++)
 printf("\nElemento %d %d: %5.2f", I+1, J+1, A[I][J]);
 }
*/
 // 6.7
/*
  #include <stdio.h>
 // Fábrica de lácteos.
 // El programa, al recibir como datos las ventas mensuales de diferentes
 // productos, obtiene información estadística valiosa para la empresa.
 void Lectura1(int [15][12]);
 void Lectura2(float, int);
 void Funcion1(int [][12], int, int, float *, float *);  // Prototipos de funciones.
 void Funcion2(float *, int);
 void Funcion3(float *, int);
 void main(void)
 {
 int FAB[15][12] = {0};                 // Inicialización en 0 del arreglo FAB.
 float COS[15], VEN[15];
 Lectura1(FAB);
 Lectura2(COS, 15);
 Funcion1(FAB, 15, 12, COS, VEN);
 Funcion2(VEN, 15);
 Funcion3(VEN, 15);
 }
 void Lectura1(int A[][12])
 // Esta función se utiliza para almacenar en el arreglo bidimensional las
 // diferentes transacciones que representan las ventas de los diferentes
 // productos. El fin de datos está dado por –1.
 {
 int MES, PRO, CAN;
 printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
 scanf("%d %d %d", &MES, &PRO, &CAN);
 while(MES!= -1 && PRO!= -1 && CAN!=-1)
 {
 A[MES-1][PRO-1] += CAN;
 printf("Ingrese mes, tipo de producto y cantidad vendida: ");
 scanf("%d %d %d", &MES, &PRO, &CAN);
 }
 }
 void Lectura2(float A[], intN)
 // Esta función se utiliza para leer los precios de venta de los diferentes productos.
 {
 int I;
 for(I=0; I<N; I++)
 {
 printf("Ingrese costo del producto %d: ", I+1);
 scanf("%f", &A[I]);
 }
 }
 void Funcion1(int A[][12], int F, int C, float V1[], float V2[])
 // Esta función se utiliza para calcular el monto de venta anual de cada uno
 // de los productos. Observa que el resultado se almacena en un arreglo
 // unidimensional que se utilizará posteriormente.
 {
 int I, J, SUM;
 printf("\n");
 for(I=0; I< F; I++)
 {
 SUM = 0;
 for(J=0; J<C; J++)
 SUM += A[I][J];
 V2[I] = V1[I] * SUM;
 printf("\nTotal de ventas del producto %d: %8.2f", I+1, V2[I]);
 }
 }
 void Funcion2(float A[], int C)
 // Esta función se utiliza para calcular el monto total de ventas de la fábrica.
 {
 int I;
 float SUM = 0.0;
 for(I=0; I<C; I++)
 SUM += A[I];
 printf("\n\nTotal de ventas de la fábrica: %.2f", SUM);
 }
 void Funcion3(float A[], int C)
 // Esta función se utiliza para obtener el tipo de producto que más se ha vendido
 // y el monto de las ventas de dicho producto.
 {
 int I,TPR = 0;
 float VEN = A[0];
 for (I=1; I<C; I++)
 if (VEN < A[I])
 {
 TPR = I;
 VEN = A[I];
 }
 printf("\nTipo de Producto más vendido: %d \t   Ventas: %.2f", TPR + 1, VEN);
 }
*/

 // 6.8
/*

 #include <stdio.h>
 // Traspuesta.
 // El programa calcula la traspuesta de una matriz.
 const int MAX = 50;
 void Lectura(int [][MAX], int, int);
 void Traspuesta(int[][MAX],int [][MAX], int, int);  // Prototipos de funciones.
 void Imprime(int [][MAX], int, int);
 void main(void)
 {
 int MAT[MAX][MAX], TRA[MAX][MAX];
 int FIL, COL;
 do
 {
 printf("{Ingrese el número de filas de la matriz: ");
 scanf("%d", &FIL);
 }
 while (FIL > MAX && FIL < 1);
 // Se verifica que el número de filas sea correcto.
 do
 {
 printf("Ingrese el número de columnas de la matriz: ");
 scanf("%d", &COL);
 }
 while (COL > MAX && COL < 1);
 // Se verifica que el número de columnas sea correcto.
 Lectura(MAT, FIL, COL);
 Traspuesta(MAT, TRA, FIL, COL);
 Imprime(TRA, COL, FIL);
 }
 void Lectura(int A[][MAX], int F , int C)
 // Esta función se utiliza para una matriz de tipo entero de F filas y C
 // columnas.
 {
 int I, J;
 for (I=0; I<F; I++)
 for(J=0; J<C; J++)
 {
 printf("Ingrese el elemento %d %d: ", I+1, J+1);
 scanf("%d", &A[I][J]);
 }
 }
 void Traspuesta(int M1[][MAX],int M2[][MAX],int F, int C)
 // Esta función se utiliza para calcular la traspuesta.
 {
 int I, J;
 for (I=0; I< F; I++)
 for (J=0; J<C; J++)
 M2[J][I] = M1[I][J];
 }
 void Imprime(int A[][MAX], int F, int C)
 // Esta función se utiliza para escribir una matriz de tipo entero de Ffilas
 // y Ccolumnas —en este caso la traspuesta.
 {
 int I, J;
 for (I=0; I<F; I++)
 for (J=0; J<C; J++)
 printf("\nElemento %d %d: %d ", I+1, J+1, A[I][J]);
 }
*/
 // 6.9
/*

  #include <stdio.h>
 // Asigna.
 // El programa, al recibir un arreglo bidimensional cuadrado, asigna elementos en
 // función del módulo (residuo) a un arreglo unidimensional.
 void Lectura(int [][10], int);
 void Calcula(int [][10], float [], int);
 float Mod0(int [][10], int, int);
 float Mod1(int [][10], int);                    // Prototipos de funciones.
 float Mod2(int [][10], int, int);
 void Imprime(float [10], int);
 void main(void)
 {
 int MAT[10][10],TAM;
 float VEC[10];
 do
 {
 printf("Ingrese el tamaño de la matriz: ");
 scanf("%d", &TAM);
 }
 while (TAM >10 && TAM < 1);
 Lectura(MAT, TAM);
 Calcula(MAT, VEC, TAM);
 Imprime(VEC, TAM);
 }
 void Lectura(int A[][10], int N)
 // La función Lecturase utiliza para leer un arreglo bidimensional cuadrado
 // de tipo entero.
 {
 int I, J;
 for(I=0; I<N; I++)
 for(J=0; J<N; J++)
 {
 printf("Ingrese el elemento %d %d: ", I+1, J+1);
 scanf("%d", &A[I][J]);
 }
 }
 void Calcula(int A[][10],float B[], int N)
 // Esta función se utiliza tanto para calcular el módulo entre el índice del
 // arreglo unidimensional y 3, como para llamar a las funciones
 // correspondientes para resolver el problema.
 {
 int I;
 for (I=0; I<N; I++)
 switch(I%3)
 {
 case 1: B[I] = Mod1 (A,I);
 break;
 case 2: B[I] = Mod2 (A,I,N);
 break;
 default: B[I] = Mod0 (A,I,N);
 break;
 }
 }
 float Mod0 (int A[][10],int K, int M)
 // Esta función calcula el cociente entre una productoria y una sumatoria.
 {
 int I;
 float PRO = 1.0, SUM  = 0.0;
 for (I=0; I<M; I++)
 {
 PRO *= A[I][K];
 SUM += A[I][K];
 }
 return (PRO / SUM);
 }
 float Mod1(int A[][10], int N)
 // Esta función obtiene el resultado de una sumatoria.
 {
 int I;
 float SUM = 0.0;
 for (I=0; I<=N; I++)
 SUM += A[N][I];
 return (SUM);
 }
 float Mod2 (int A[][10],int N, int M)
 // Esta función obtiene el resultado de la productoria.
 {
 int I;
 float PRO = 1.0;
 for (I=N; I<M; I++)
 PRO *= A[I][N];
 return (PRO);
 }
 void Imprime(float B[], int N)
 // Esta función se utiliza para escribir un arreglo unidimensional de tipo
 // real de Nelementos.
 {
 int I;
 for (I=0; I<N; I++)
 printf("\nElemento %d: %.2f ", I, B[I]);
 }
/*
 // 6.10
/*
 #include <stdio.h>
 // Cuadrado mágico.
 // El programa genera un cuadrado mágico siguiendo los criterios enunciados
 // anteriormente.
 const int MAX = 50;
 void Cuadrado(int[][MAX], int);
 void Imprime(int [][MAX], int);           // Prototipos de funciones.
 void main(void)
 {
 int CMA[MAX][MAX],TAM;
 do
 {
 printf("Ingrese el tamaño impar de la matriz: ");
 scanf("%d", &TAM);
 }
 while ((TAM > MAX && TAM < 1) && (TAM % 2));
// Se verifica el tamaño del arreglo y el orden (impar) del mismo.
 Cuadrado(CMA, TAM);
 Imprime(CMA, TAM);
 }
 void Cuadrado(int A[][MAX],int N)
 // Esta función se utiliza para formar el cuadrado mágico.
 {
 int I = 1, FIL = 0, COL = N / 2, NUM = N * N;
 while(I <= NUM)
 {
 A[FIL][COL] = I;
 if (I%N != 0)
 {
 FIL = (FIL – 1 + N) % N;
 COL = (COL + 1) % N;
 }
 else
 FIL++;
 I++;
 }
 }
 void Imprime(int A[][MAX], int N)
 // Esta función se utiliza para escribir el cuadrado mágico.
 {
 int I, J;
 for (I=0; I<N; I++)
 for (J=0; J<N; J++)
 printf("\nElemento %d %d: %d",I+1, J+1, A[I][J]);
 }

*/
 // 6.11
/*

  #include <stdio.h>
 // Casa de bolsa.
 // El programa, al recibir como datos los precios mensuales de las acciones de sus
 // cinco fondos de inversión, además del precio de las acciones al 31 de diciembre
 // del 2003, genera información estadística importante para la empresa.
 void LecturaM(float [][12], int, int);
 void LecturaV(float *, int);
 void F1(float [][12], int, int, float *, float *);   // Prototipos de funciones.
 void F2(float [][12], int, int);
 void F3(float *, int);
 void main(void)
 {
 float FON[5][12], PRE[5], REN[5];
 // REN es un arreglo unidimensional de tipo real que se utilizará para almacenar
 //endimiento anual de los fondos de inversión.
 LecturaM(FON, 5, 12);
 LecturaV(PRE, 5);
 F1(FON, 5, 12, PRE, REN);
 F2(FON, 5, 12);
 F3(REN, 5);
 }
 void LecturaM(float A[][12], int F, int C)
 // Esta función se utiliza para leer un arreglo bidimensional de tipo real de F
 // filas y Ccolumnas.
 {
 int I, J;
 for(I=0; I<F; I++)
 for(J=0; J<C; J++)
 {
 printf("Precio fondo %d\t mes %d: ", I+1, J+1);
 scanf("%f", &A[I][J]);
 }
 }
 void LecturaV(float A[], int T)
 // Esta función se utiliza para leer un arreglo unidimensional de tipo real deT
 // elementos.
 {
 int I;
 printf("\n");
 for(I=0; I<T; I++)
 {
 printf("Precio Fondo %d al 31/12/2003:  ", I+1);
 scanf("%f", &A[I]);
 }
 }
 void F1(float A[][12], int F, int C, float B[], float V[])
 {
 // La función F1 se utiliza para calcular el rendimiento anual de los fondos de
 // inversión. El resultado se almacena en el arreglo unidimensional V.
 int I;
 printf("\nRENDIMIENTOS ANUALES DE LOS FONDOS");
 for(I=0; I<F; I++)
 {
 V[I] = (A[I][C-1] - B[I]) / B[I] * 100;
 printf("\nFondo %d:   %.2f", I+1, V[I]);
 }
 }
 void F2(float A[][12], int F, int C)
 {
 // Esta función calcula el promedio anualizado de las acciones de los diferentes
 // fondos.
 int I, J;
 float SUM, PRO;
 printf("\n\nPROMEDIO ANUALIZADO DE LAS ACCIONES DE LOS FONDOS");
 for(I=0; I<F; I++)
 {
 SUM = 0;
 for(J=0; J<C; J++)
 SUM += A[I][J];
 PRO = SUM / C;
 printf("\nFondo %d: %.2f", I+1, PRO);
 }
 }
 void F3(float A[], int F)
 // Esta función permite calcular los fondos con el mejor y peor rendimiento.
 {
 float ME = A[0], PE = A[0];
 int M = 0, P = 0, I;
 for (I=1; I<F; I++)
 {
 if (A[I] > ME)
 {
 ME = A[I];
 M = I;
 }
 if (A[I] < PE)
 {
 PE = A[I];
 P = I;
 }
 }
 printf("\n\nMEJOR Y PEOR FONDO DE INVERSION");
 printf("\nMejor fondo: %d\tRendimiento: %6.2f", M+1, ME);
 printf("\nPeor fondo: %d\tRendimiento: %6.2f", P+1, PE);
 }

*/
 // 6.12
/*
  #include <stdio.h>
 // Lluvias.
 // El programa, al recibir como dato un arreglo tridimensional que contiene
 // información sobre lluvias, genera información estadística.
 const int PRO = 5;
 const int MES = 6;
 const int AÑO = 1;
 void Lectura(float[PRO][MES][AÑO], int, int, int);
 void Funcion1(float[PRO][MES][AÑO], int, int,int);
 void Funcion2(float[PRO][MES][AÑO], int,int,int);  // Prototipos de funciones.
 void Funcion3(float[PRO][MES][AÑO], int, int,int);
 void main(void)
 {
 float LLU[PRO][MES][AÑO];
 Lectura(LLU, PRO, MES, AÑO);
 Funcion1(LLU, PRO, MES, AÑO);
 Funcion2(LLU, PRO, MES, AÑO);
 Funcion3(LLU, 18, MES, 5);
 }
 void Lectura (float A[][MES][AÑO], int F, int C, int P)
 // Esta función se utiliza para leer un arreglo tridimensional de tipo real de
 // F filas, C columnas y P planos de profundidad.
 {
 int K, I, J;
 for(K=0; K<P; K++)
 for(I=0; I<F; I++)
 for (J=0; J<C; J++)
 {
 printf("Año: %d\tProvincia: %d\tMes: %d", K+1, I+1, J+1);
 scanf("%f", &A[I][J][K]);
 }
 }
 void Funcion1(float A[][MES][AÑO],int F, int C, int P)
 // Esta función se utiliza para localizar la provincia que tuvo el mayor registro
 // de precipitación pluvial en los últimos 10 años. Escribe además el registro
 // correspondiente.
 {
 int I, K, J, EMAY = -1;
 float ELLU = -1.0, SUM;
 for (I=0; I<F; I++)
 {
 SUM = 0.0;
 for (K=0; K<P; K++)
 for (J=0; J<C; J++)
 SUM += A[I][J][K];
 SUM /= P * C;
 if (SUM > ELLU)
 {
 ELLU = SUM;
 EMAY = I;
 }
 }
 printf("\nProvincia con mayor registro de lluvias: %d", EMAY+1);
 printf("\nRegistro: %.2f", ELLU);
 }
 void Funcion2(float A[][MES][AÑO],int F, int C, int P)
 // Esta función se utiliza para localizar la provincia que tuvo el menor registro
 // de lluvias en el último año. Escribe además el registro correspondiente.
 {
 int I, J, EMEN;
 float ELLU = 1000, SUM;
 for (I=0; I<F; I++)
 {
 SUM = 0;
 for (J=0; J<C; J++)
 SUM += A[I][J][P-1];
 SUM /= C;
 if (SUM < ELLU)
 {
 ELLU = SUM;
 EMEN = I;
 }
 }
 printf("\n\nProvincia con menor registro anual de lluvias en el último año: %d", EMEN+1);
 printf("\nRegistro anual: %.2f", ELLU);
 }
 void Funcion3(float A[][MES][AÑO],int F, int C, int P)
 // Esta función se utiliza para localizar el mes con mayor registro de lluvias en
 // la provincia 18 en el quinto año. Escribe además el registro correspondiente.
 {
 int J, EMES = -1;
 float ELLU = -1.0;
 for (J=0; J<C; J++)
 {
 if (A[F-1][J][P-1] > ELLU)
 {
 ELLU = A[F-1][J][P-1];
 EMES = J;
 }
 }
 printf("\nMes: %d Lluvias: %.2f", EMES+1, ELLU);
 }
*/
 // 6.13
/*
 #include <stdio.h>
 // Empresa textil.
 // El programa, al recibir un arreglo tridimensional que contiene información
 // sobre las ventas mensuales de tres departamentos en los últimos ocho años,
 // genera información estadística valiosa para la empresa.
 const int MES = 6;
 const int DEP = 3;
 const int AÑO = 2;
 void Lectura(float [MES][DEP][AÑO], int, int, int);
 void Funcion1(float [MES][DEP][AÑO], int, int, int);
 void Funcion2(float[MES][DEP][AÑO], int, int, int);   // Prototipos de funciones.
 void Funcion3(float[MES][DEP][AÑO], int, int, int);
 void main(void)
 {
 float PRO[MES][DEP][AÑO];
 Lectura(PRO, MES, DEP, AÑO);
 Funcion1(PRO, MES, DEP, 2);
 Funcion2(PRO, MES, DEP, AÑO);
 Funcion3(PRO, MES, DEP, AÑO);
 }
 void Lectura(float A[][DEP][AÑO], int F, int C, int P)
 // La función Lecturase utiliza para leer un arreglo tridimensional de tipo
 // real de Ffilas, Ccolumnas y Pplanos de profundidad.
 {
 int K, I, J;
 for(K=0; K<P; K++)
 for (I=0; I<F; I++)
 for(J=0; J<C; J++)
 {
 printf("Año: %d\tMes: %d\tDepartamento: %d  ", K+1, I+1, J+1);
 scanf("%f", &A[I][J][K]);
 }
 }
 void Funcion1(float A[][DEP][AÑO],int F, int C, int P)
 // Esta función se utiliza para obtener las ventas totales de la empresa
 // en el segundo año.
 {
 int I, J;
 float SUM = 0.0;
 for (I=0; I<F; I++)
 for (J=0; J<C; J++)
 SUM += A[I][J][P-1];
 printf("\n\nVentas totales de la empresa en el segundo año: %.2f", SUM);
 }
   void Funcion2(float A[][DEP][AÑO],int F, int C, int P)
 // Esta función se utiliza para obtener el departamento que tuvo las mayores
 // ventas en el último año. Genera además el importe de las ventas.
 {
 int I, J;
 float SUM1 = 0, SUM2 = 0, SUM3 = 0;
 for (I=0; I<F; I++)
 for (J=0; J<C; J++)
 switch (J+1)
 {
 case1: SUM1 += A[I][J][P-1];
 break;
 case2: SUM2 += A[I][J][P-1];
 break;
case3: SUM3 += A[I][J][P-1];
 break;
 }
 if(SUM1 > SUM2)
 if(SUM1 > SUM3)
 {
 printf("\n\nDepartamento con mayores ventas en el último año: Hilos");
 printf("  Ventas:%.2f", SUM1);
 }
 else
 {
 printf("\n\nDepartamento con mayores ventas en el último año: Licra");
 printf(" Ventas:%.2f", SUM3);
 }
 else
 if(SUM2 > SUM3)
 {
 printf("\n\nDepartamento con mayores ventas en el último año: Lanas");
 printf("Ventas:%.2f", SUM2);
 }
 else
 {
 printf("\n\nDepartamento con mayores ventas en el último año: Licra");
 printf("Ventas:%.2f", SUM3);
 }
 }
 void Funcion3(float A[][DEP][AÑO],int F, int C, int P)
 // Esta función se utiliza para obtener el departamento, mes y año con la mayor
 // venta. Escribe también el monto de las ventas.
 {
 int K, I, J, DE, ME, AN;
 float VEN = -1.0;
 for(K=0; K<P; K++)
 for(I=0; I< F; I++)
 for(J=0; J<C; J++)
 if(A[I][J][K] > VEN)
 {
 VEN = A[I][J][K];
 DE = J;
 ME = I;
 AN = K;
 }
 printf("\n\nDepartamento: %d\tMes: %d\tAño: %d", DE+1, ME+1, AN+1);
 printf("\tVentas: %.2f", VEN);
 }
/**/
 // 7.1
/*
 #include <stdio.h>
 // Funciones para el manejo de caracteres de la biblioteca stdio.h
 void main(void)
 {
 char p1, p2, p3 = '$';
 // Declaración de las variables tipo caracter p1, p2 y p3. Observa que a p3 se le
 // asigna el símbolo $.
 printf("\nIngrese un caracter:");
 p1=getchar();         // Se utiliza la función getchar para leer un caracter.
 putchar(p1);          // Se utiliza la función putchar para escribir un
 // caracter.
 printf("\n");
 fflush(stdin);
 // Luego de leer un caracter siempre es conveniente escribir la función fflush
 // para limpiar el búfer, porque generalmente queda con basura y genera un error
 // en la ejecución del programa. El error se produce porque cuando se ingresa un
 // dato se oprime el return y luego cuando volvemos a leer un caracter o una
 // cadena de caracteres se toma a ese return como el nuevo dato ingresado.
printf("\nEl caracter p3 es: ");
 putchar(p3);
// Se utiliza la función putchar para escribir el caracter almacenado en p3.
 printf("\n");
 printf("\nIngrese otro caracter: ");
 fflush(stdin);
 scanf("%c", &p2);
 // Se puede utilizar scanf con el formato de variable %c para leer un caracter.
printf("%c", p2);
 // Se puede utilizar printf con el formato de variable %c para escribir un
 // caracter.
 }
*/
 // 7.2
/*
 # include <stdio.h>
 # include <ctype.h>
 // Funciones para el manejo de caracteres de la biblioteca ctype.h.
 void main(void)
 {
 char p1;
 printf("\nIngrese un caracter para analizar si éste es un dígito:");
 p1 = getchar();
 if(isdigit (p1))
// La función isdigitregresa 1 si p1es un dígito y 0 en caso contrario.
 printf("%c es un dígito \n", p1);
 else
 printf("%c no es un dígito \n", p1);
 fflush(stdin);
 printf("\nIngrese un caracter para examinar si éste es una letra: ");
 p1 = getchar();
 if(isalpha (p1))
// La función isalpharegresa 1 si p1 es una letra y 0 en caso contrario.
 printf("%c es una letra \n", p1);
 else
 printf("%c no es una letra \n", p1);
 fflush(stdin);
 printf("\nIngrese un caracter para examinar si éste es una letra minúscula: ");
 p1 = getchar();
 if(isalpha (p1))
 if (islower (p1))
// La función islowerregresa 1 si p1 es una letra minúscula y 0 en caso
// contrario.
// La función isupper, por otra parte, regresa 1 si p1 es una letra mayúscula
// y 0 en caso contrario.
 printf("%c es una letra minúscula \n", p1);
 else
 printf("%c no es una letra minúscula \n", p1);
 else
 printf("%c no es una letra \n", p1);
 fflush(stdin);
 printf("\nIngrese una letra para convertirla de mayúscula a minúscula: ");
 p1 = getchar();
 if(isalpha (p1))
 if(isupper(p1))
 printf("%c fue convertida de mayúscula a minúscula \n", tolower(p1));
 // La función tolower convierte de mayúscula a minúscula. Si la
 // letra es minúscula no la modifica. La función toupper, por otra parte,
// convierte de minúscula a mayúscula. Si la letra es mayúscula no la
// modifica.
 else
 printf("%c es una letra minúscula \n", p1);
 else
 printf("%c no es una letra \n", p1);
 }
*/
 // 7.3
/*
  #include <stdio.h>
 // Funciones para el manejo de cadenas de caracteres de la biblioteca stdio.h.
 void main(void)
 {
 char*cad0 = "Buenos días";   // En este caso se asignan 11 caracteres más el
 // caracter de terminación '\0' a la posición de memoria a la que apunta la
 // variable cad0 —apuntador del tipo cadena de caracteres.
 char cad1[20] = "Hola";         // Se asignan cuatro caracteres más el caracter
 // de terminación a la variable tipo charcad1. Observa que cad1 tiene espacio
 // para 20 caracteres.
 char cad2[] = "México";         // En este caso se asignan seis caracteres (más
 // el caracter de terminación) a la variable cad2. Observa que cad2 no tiene espacio
 // reservado como cad1; por lo tanto, acepta cualquier número de caracteres.
 char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
 // Observa otra forma de asignación de valores a la variable cad3.
 char cad4[20], cad5[20], cad6[20];
 printf("\nLa cadena cad0 es: ");
 puts(cad0);
 // La función putses la más apropiada para escribir cadenas de caracteres.
 // Observa que esta función baja automáticamente una línea después de imprimir
 // la cadena.
 printf("\nLa cadena cad1 es: ");
 printf("%s", cad1);
// La función printf, con el formato de variable %s,también se puede utilizar
 // para escribir cadenas de caracteres. Baja automáticamente una línea después
 // de escribir la cadena.
 printf("\nLa cadena cad2 es: ");
 puts(cad2);
 printf("\nLa cadena cad3 es: ");
 puts(cad3);
 printf("\nIngrese una línea de texto —se lee con gets—: \n");
 // La función getses la más apropiada para leer cadenas de caracteres.
gets(cad4);
 printf("\nLa cadena cad4 es: ");
 puts(cad4);
 fflush(stdin);
 printf("\nIngrese una línea de texto —se lee con scanf—: \n");
 scanf("%s", cad5);
// La función scanf, con el formato de variable %s, también se puede utilizar
 // para leer una cadena de caracteres, aunque con algunas restricciones. Si la
 // cadena está formada por varias palabras sólo lee la primera. Por ejemplo, si
 // queremos ingresar la cadena “Buenos días”, sólo lee la palabra “Buenos”, por
 // ello esta función únicamente es útil si conocemos con anticipación que la
 // cadena que vamos a leer está formada por una sola palabra.
 printf("\nLa cadena cad5 es: ");
 printf("%s", cad5);
 fflush(stdin);
 char p;
 int i = 0;
// La declaración de variables siempre se debe realizar en la parte inicial del
 // programa. En este caso se colocan en esta sección (char p e inti = 0) para
 // que puedas observar la relación directa con las líneas de programación que se
 // muestran a continuación.
 printf("\nIngrese una línea de texto —se lee cada caracter con getchar—: \n");
 // Se utiliza la función getcharpara leer caracteres de la línea de texto y
 // asignarlos a la variable de tipo cadena de caracteres cad6. Observa que se leen
 // caracteres mientras no se encuentre al caracter que indica fin de línea ‘\n’.
 while((p = getchar())!= '\n')
 cad6[i++] = p;
 cad6[i] = '\0';
// Al final de la cadena se incorpora el caracter de terminación NULL para
 // indicar el fin de la misma.
 printf("\nLa cadena cad6 es: ");
 puts(cad6);
 }
*/

 // 7.4
/*
 #include <stdio.h>
 // Declaración de cadenas de caracteres y asignación de valores.
 void main(void)
 {
 char*cad0;
 cad0 = "Argentina";          // La declaración y la asignación son correctas.
 puts(cad0);
 cad0 = "Brasil";
 // Correcto. Se modifica el contenido de la posición en memoria a la que apunta
 // la variable cad0—apuntador de tipo cadena de caracteres.
 puts(cad0);
 char*cad1;
 gets(*cad1);
 gets(cad1);
 // Incorrecto. Ambas lecturas generan un error en la ejecución del programa.
 // Para que un apuntador de tipo cadena de caracteres se pueda utilizar con la
 // función de lectura gets, es necesario inicializarlo como se hace en la siguiente
 // instrucción.
 char*cad1 = "";
 gets(cad1);
// Correcto. Primero se le asigna un valor a la posición de memoria a la que
 // apunta cad1. Luego podemos modificar el contenido de esta posición de memoria
 // utilizando la función gets.
 charcad1[];
 // Incorrecto. Se genera un error en la compilación del programa, porque no
 // se reserva el espacio correspondiente.
char cad2[20] = "México";    // Correcto.
 puts(cad2);
 gets(cad2);
// El valor de una cadena (declarada como cadena[longitud]) se puede modificar
 // por medio de lecturas o utilizando funciones de la biblioteca string.h
 (ejemplo 7.6).
 puts(cad2);

 cad2[10] = "Guatemala";
 // Incorrecto. Observa cuidadosamente el caso anterior y analiza la diferencia
 // que existe con éste. Aquí se produce un error en la compilación del programa,
 // al tratar de asignar la cadena de caracteres "Guatemala" al caracter 11 de la
 // cadena.
}
/*

// 7.5
/*
 #include <stdio.h>
 #include <stdlib.h>
 // Funciones para el manejo de caracteres de la biblioteca stdlib.h.
 void main(void)
 {
 int i;
 double d;
 long l;
 char cad0[20], *cad1;
printf("\nIngrese una cadena de caracteres: ");
 gets(cad0);
 i = atoi(cad0);
 // La función atoi convierte una cadena de caracteres que contiene números
 // un valor de tipo entero. Si la cadena comienza con otro caracter o no
 // contiene números, regresa 0 o el valor queda indefinido.
 printf("\n%s \t %d", cad0, i+3);
// Se imprime el valor de i+3 para demostrar que i ya fue convertido a un
 // entero.
 printf("\nIngrese una cadena de caracteres: ");
 gets(cad0);
 d = atof(cad0);
 // La función atof convierte una cadena de caracteres que contiene números
 // reales a un valor de tipo double. Si la cadena comienza con otro caracter
 // o no contiene números, regresa 0 o el valor queda indefinido.
 printf("\n%s \t %.2lf ", cad0, d+1.50);
 d = strtod(cad0, &cad1);
 // La función strtod convierte una cadena de caracteres que contiene números
 // reales a un valor de tipo double. El resto de la cadena se almacena en el
 // segundo argumento de la función, &cad1, un apuntador de tipo cadena de
 // caracteres. Si la cadena no contiene números o comienza con otro caracter,
 // regresa 0 o el valor queda indefinido.
 printf("\n%s \t %.2lf", cad0, d+1.50);
 puts(cad1);
 l = atol(cad0);
 // La función atol convierte una cadena de caracteres que contiene números a
 // un valor de tipo long. Si la cadena no contiene números o comienza con
 // otro caracter, regresa 0 o el valor queda indefinido.
 printf("\n%s \t %ld ", cad0, l+10);
 l = strtol(cad0, &cad1, 0);
 // La función strtol convierte una cadena de caracteres que contiene números a
 // un valor de tipo long. El resto de la cadena se almacena en el otro argumento
 // de la función, &cad1. El tercer argumento se utiliza para indicar que la
 // cadena puede estar en formato octal, decimal o hexadecimal. Si la cadena no
 // contiene números o comienza con otro caracter, regresa 0 o el valor queda
 // indefinido.
 printf("\n%s \t %ld", cad0, l+10);
 puts(cad1);
 }
*/


 // 7.6
/*
 #include <stdio.h>
 #include <string.h>
 // Funciones de la biblioteca string.h para el manejo de cadenas de
 // caracteres.
 void main(void)
 {
 char *cad0 = "Hola México";
 char cad1[20], cad2[20], cad3[20] = ", buenos días!!!";
 strcpy(cad1, cad0);
// La función strcpy permite copiar una cadena de caracteres completa. En este
 // caso se copia la cadena cad0 a cad1. Si el espacio reservado para cad1 es
 // menor que el de cad0, se genera un error en la ejecución del programa.
 printf("\nPrueba de la función strcpy. Se copia la cadena cad0 a cad1:%s\n", cad1);
 strcpy(cad1, cad3);
 printf("\nPrueba de la función strcpy. Se copia la cadena cad3 a cad1: %s\n", cad1);
 strcpy(cad1, "XX");
 printf("\nPrueba de la función strcpy. Se copia la cadena XX a cad1: %s\n", cad1);
 strncpy(cad2, cad0, 4);

 cad2[4] = '\0';
 // La función strncpy permite copiar un número determinado de caracteres a
 // otra cadena de caracteres. En este caso se copian 4 caracteres de la cadena
 // cad0—segundo argumento— a cad2—primer argumento. Siempre se debe
 // incorporar al final de la cadena el caracter de terminación. Si el espacio
 // reservado para cad2 es menor que lo que se pretende copiar, se genera
 // un error en la ejecución del programa.
 printf("\nPrueba de la función strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n",
cad2);
 strncpy(cad2, cad3, 3);
 cad2[3] = '\0';
 printf("\nPrueba de la función strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n",
cad2);
 strcat(cad0, cad3);
 // La función strcat permite incorporar una cadena de caracteres a otra
 // cadena dada. En este caso se agrega la cadena cad3 a cad0. Si el espacio
 // reservado para cad0 es menor a lo que se debe almacenar se genera un error
 // de ejecución.
 printf("\nPrueba de la función strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);
 strcat(cad1, " YY");
 printf("\nPrueba de la función strcat. Se incorpora la cadena YY a cad1: %s\n", cad1);
 strcat(cad2, " ");
 strncat(cad2, cad0, 4);
 printf("\nPrueba de la función strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);
 // La función strncat permite incorporar un número determinado de caracteres
 // a una cadena. En este caso se agregan cuatro caracteres de la cadena cad0
 // a cad2. Si el espacio de cad2 es menor a lo que se debe almacenar ocurre
 // un error de ejecución.
 cad0 = strstr(cad0, "México");
 printf("\nPrueba de la función strstr. Se trata de localizar la cadena México dentro de cad0: %s\n", cad0);
 // La función strstr se utiliza para localizar una cadena de caracteres dentro
 // de otra cadena. Si la encuentra, regresa un apuntador al inicio de la
 // primera ocurrencia de la cadena localizada. De otra forma, regresa NULL.
 cad0 = strstr(cad0, "Guatemala");
 printf("\nPrueba de la función strstr. Se trata de localizar la cadena Guatemala dentro de cad0: %s\n", cad0);
 }
*/
 // 7.7
/*

#include <stdio.h>
#include <string.h>
 // Otras funciones de la biblioteca string.h para el manejo de cadenas.
 void main(void)
 {
 int i;
 char cad0[20] = "Hola México";
 char cad1[20] = "Hola Guatemala";
 char cad2[20] = "Hola Venezuela";
 char cad3[20] = "Hola México";
 char *c, c3;
 i = strcmp(cad0, cad1);
 // La función strcmp permite comparar dos cadenas de caracteres. Si la
 // primera cadena —en este caso cad0—es mayor a la segunda —cad1—,
 // regresa un valor positivo; si es menor, un valor negativo y de otra forma,
 // 0.
 printf("\nResultado de la comparación —cad0 y cad1—: %d", i);
 i = strcmp(cad0, cad2);
 printf("\nResultado de la comparación —cad0 y cad2—: %d", i);
 i = strcmp(cad0, cad3);
 printf("\nResultado de la comparación —cad0 y cad3—: %d", i);
 i = strlen(cad0);
 // La función strlen obtiene la longitud —el número de caracteres— de
 // una cadena.
printf("\nLongitud cadena cad0: %d", i);
 i = strlen(cad1);
 printf("\nLongitud cadena cad1: %d", i);
 c = strchr(cad1, 'G');          // c es un apuntador de tipo caracter.

 // La función strchr busca la posición en la que se encuentra un
 // determinado caracter en la cadena de caracteres. Si lo encuentra regresa
 // un apuntador a la primera ocurrencia del caracter en la cadena, de otra
 // forma regresa NULL.
 if (c != NULL)
 {
c3 = *c;       // c3 toma el contenido de la celda de memoria a la
 // que apunta c.
 printf("\nEl valor de c3 es:  %c", c3);
 }
 c = strchr(cad2, 'V');
if (c != NULL)
 {
c3 = *c;
printf("\nEl valor de c3 es:  %c", c3);
 }
 }
/*
 // 7.8

 /*
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 // Minúsculas y mayúsculas.
 //El programa, al recibir como dato un arreglo unidimensional de tipo
 // cadena de caracteres, determina el número de minúsculas y mayúsculas
 // que hay en cada cadena.
 void minymay(char cad);
// Prototipo de función.
 void main(void)
 {
 int i, n;
 char FRA[20][50];
 // Observa cómo se declara el arreglo unidimensional de cadena de
 // caracteres.
 printf("\nIngrese el número de filas del arreglo: ");
 scanf("%d", &n);
 for (i=0; i<n; i++)
 {
 // Para cada fila se lee la cadena correspondiente.
 printf("Ingrese la línea %d de texto: ", i+1);
 fflush(stdin);
 gets(FRA[i]);
 }
 printf("\n\n");
 for (i=0; i<n; i++)
 minymay(FRA[i]);
 }
 void minymay(char *cadena)
 // Esta función se utiliza para calcular el número de minúsculas
 // y mayúsculas que hay en cada cadena.
 {
 int i = 0, mi = 0, ma = 0;
 while(cadena[i] != ‘\0’)
 {
 if (islower(cadena[i]))
 mi++;
 else
 if (isupper(cadena[i]))
 ma++;
 i++;
 }
 printf("\n\nNúmero de letras minúsculas: %d", mi);
 printf("\nNúmero de letras mayúsculas: %d", ma);
 }
/**/
 // 7.9
/*
  #include <stdio.h>
 // Cuenta caracteres.
 // El programa, al recibir como datos una cadena de caracteres y un caracter,
 // cuenta cuántas veces se encuentra el caracter en la cadena.
 int cuenta(char *, char); // Prototipo de función.
 void main(void)
 {
 char car, cad[50];
 int res;
 printf("\nIngrese la cadena de caracteres: ");
 gets(cad);
 fflush(stdin);
 printf("\nIngrese el caracter: ");
 car = getchar();
 res = cuenta(cad, car);
 printf("\n\n%c se encuentra %d veces en la cadena %s", car, res, cad);
 }
 int cuenta(char *cad, char car)
 // Esta función se utiliza para obtener el número de veces que se encuentra
// el caracter en la cadena.
 {
 int i = 0, r = 0;
 while (cad[i] != '\0')
 {
 if (cad[i] == car)
    r++;
    i++;
 }
 return (r);
 }
/**/
 // 7.10
/*
  #include <stdio.h>
 #include <stdlib.h>
 // Suma y promedio.
 // El programa, al recibir como datos varias cadenas de caracteres que
 // contienen reales, los suma y obtiene el promedio de los mismos.
 void main(void)
 {
 char c, cad[10];
 int i = 0;
 float sum = 0.0;
 printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
 c = getchar();
 while (c == 's')
 {
 printf("\nIngrese la cadena de caracteres: ");
 fflush(stdin);
 gets(cad);
 i++,
 sum += atof(cad);
 printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
 c = getchar();
 }
 printf("\nSuma: %.2f", sum);
 printf("\nPromedio: %.2f", sum / i);
 }
*/
 // 7.11
/*

 # include <stdio.h>
 # include <ctype.h>
 // Verifica.
 // El programa, al recibir como datos una cadena de caracteres y una posición es
 // pecífica en la cadena, determina si el caracter correspondiente es una letra minúscula.
 void main(void)
 {
 char p, cad[50];
 int n;
 printf("\nIngrese la cadena de caracteres (máximo 50): ");
 gets(cad);
 printf("\nIngrese la posición en la cadena que desea verificar: ");
 scanf("%d", &n);
 if ((n >= 0) && (n < 50))
 {
 p = cad[n-1];
 if (islower(p))
 printf("\n%c es una letra minúscula", p);
 else
 printf("\n%c no es una letra minúscula", p);
 }
 else
 printf("\nEl valor ingresado de n es incorrecto");
 }
*/
 // 7.12
/*
  #include <stdio.h>
 #include <ctype.h>
 // Cuenta letras minúsculas y mayúsculas.
 // El programa, al recibir como dato una frase, determina el número de letras
 // minúsculas y mayúsculas que existen en la frase.
 void main(void)
 {
 char cad[50];
 int i = 0, mi = 0, ma = 0;
 printf("\nIngrese la cadena de caracteres (máximo 50 caracteres): ");
 gets(cad);
 while(cad[i] != '\0')
 {
 if (islower (cad[i]))
 mi++;
 else
 if (isupper (cad[i]))
 ma++;
 i++;
 }
 printf("\n\nNúmero de letras minúsculas: %d", mi);
 printf("\nNúmero de letras mayúsculas: %d", ma);
 }

*/
 // 7.13

/*
  #include <stdio.h>
 // Calcula longitud.
 // El programa calcula la longitud de la cadena sin utilizar la función strlen.
 int cuenta(char *);             // Prototipo de función.
 void main(void)
 {
 int i;
 char cad[50];
 printf("\nIngrese la cadena de caracteres: ");
 gets(cad);
 i = cuenta(cad);
 printf("\nLongitud de la cadena: %d", i);
 }
 int cuenta(char *cadena)
 // La función calcula la longitud de la cadena.
 {
 int c = 0;
 while(!cadena[c] == '\0')
 c++;
 return (c);
 }
*/

 // 7.14
/*
 #include <stdio.h>
 // Calcula longitud en forma recursiva.
 // El programa calcula de manera recursiva la longitud de la cadena sin utilizar
 // la función strlen.
 int cuenta(char *);                 // Prototipo de función.
 void main(void)
 {
 int i;
 char cad[50];
 printf("\nIngrese la cadena de caracteres: ");
 gets(cad);
 i = cuenta(cad);
 printf("\nLongitud de la cadena: %d", i);
 }
 int cuenta(char *cadena)
 // Esta función calcula la longitud de la cadena en forma recursiva. Es
 // importante tener conocimientos tanto de pilas como de recursividad para
 // comprender la solución propuesta, aunque ésta sea muy simple. Observa que
 // mientras no lleguemos al último caracter de la cadena, incrementamos la
 // cuenta en uno y llamamos a la función con el siguiente caracter.
 {
 if (cadena[0] == '\0')
 return 0;
 else
 return(1 + cuenta (&cadena[1]));
 }
*/
 // 7.15
/*
 # include <stdio.h>
 # include <ctype.h>
 // Decodifica.
 // El programa decodifica una cadena de caracteres compuesta por números y
 // letras.
 void interpreta(char *);                   // Prototipo de función.
 void main(void)
 {
 char cad[50];
 printf("\nIngrese la cadena de caracteres: ");
 gets(cad);
 interpreta(cad);
 }
 void interpreta(char *cadena)
 // Esta función se utiliza para decodificar la cadena de caracteres.
 {
 int i = 0, j, k;
 while(cad[i] != '\0')
 {
 if (isalpha (cad[i]))   // Se utiliza isalpha para observar si el caracter
// es una letra.
 {
 k = cad[i - 1] - 48;
 // En la variable entera kse almacena el ascii del número —convertido
 // en caracter— que nos interesa, menos 48 que corresponde al ascii
// deldígito 0.
for (j = 0; j < k; j++)
 putchar(cad[i]);
 }
 i++;
 }
*/
 // 7.16
/*
 #include <stdio.h>
 #include <string.h>
 // Cuenta cadenas.
 // El programa, al recibir dos cadenas de caracteres, calcula e imprime cuántas
 // veces se encuentra la segunda cadena en la primera.
 void main(void)
 {
 char cad1[50], cad2[50], *cad0 = "";
 int i = 0;
 printf("\n Ingrese la primera cadena de caracteres: ");
 gets(cad1);
 printf("\n Ingrese la cadena a buscar: ");
 gets(cad2);
 strcpy(cad0, cad1);             // Se copia la cadena original a cad0.
 cad0 = strstr (cad0, cad2);
 // En cad0 se asigna el apuntador a la primera ocurrencia de la cadena cad2.
 // Si no existe se almacena NULL.
 while(cad0 != NULL)
 {
 i++;
 cad0 = strstr (cad0 + 1, cad2);
 // Se modifica nuevamente la cadena, moviendo el apuntador una
 // posición.
 }
 printf("\nEl número de veces que aparece la segunda cadena es: %d", i);
 }
*/
 // 7.17
/*
 #include <stdio.h>
 #include <string.h>
 // Cadena invertida.
 // El programa obtiene la cadena invertida.
 char * inverso(char *);                       // Prototipo de función.
 void main(void)
 {
 char fra[50], aux[50];
 printf("\nIngrese la línea de texto: ");
 gets(fra);
 strcpy(aux, inverso(fra));    // Se copia a aux el resultado de la función
 // inverso.
 printf("\nEscribe la línea de texto en forma inversa: ");
 puts(aux);
 }
 char * inverso(char*cadena)
 // La función calcula el inverso de una cadena y regresa el resultado al
 // programa principal.
 {
 int i = 0, j, lon;
 char cad;
 lon = strlen(cadena);
 j = lon-1;
 while(i < ((lon - 1) / 2))
// Observa que el reemplazo de los caracteres se debe realizar solamente
 // hasta la mitad de la cadena.
 {
 cad = cadena[i];
 cadena[i] = cadena[j];
 cadena[j] = cad;
 i++;
 j--;
 }
 return (cadena);
 }
*/
 // 7.18
/*
  #include <stdio.h>
 // Cadena invertida resuelta en forma recursiva.
 void inverso(char*);             // Prototipo de función.
 void main(void)
 {
 char fra[50];
 printf("\nIngrese la línea de texto: ");
 gets(fra);
 printf("\nEscribe la línea de texto en forma inversa: ");
 inverso(fra);
 }
 void inverso(char*cadena)
 // La función inversoobtiene precisamente el inverso de la cadena. La solución
 // presentada es simple, pero para comprenderla es necesario tener conocimientos
 // tanto de pilas como de recursividad. Observa que mientras no se encuentre el
 // caracter de terminación de la cadena, se llama a la función recursiva con
 // el apuntador al siguiente caracter de la cadena. Por otra parte, queda
 // pendiente de ejecutar —almacenado en una pila— el caracter al cual apunta * cadena.
 {
 if(cadena[0]!= '\0')
 {
 inverso(&cadena[1]);
 putchar(cadena[0]);
 }
 }
*/
 // 7.19
/*
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 // Cuenta palabras.
 // El programa calcula el número de palabras que hay en la cadena de caracteres.
 int cuentap(char *);                     // Prototipo de función.
 void main(void)
 {
 int i;
 char fra[50];
 printf("\nIngrese la línea de texto: ");
 gets(fra);
 strcat(fra," ");              // Se agrega un espacio en blanco al final de la
 // cadena.
 i = cuentap(fra);
 printf("\nLa línea de texto tiene %d palabras", i);
 }
 int cuentap(char *cad)
 {
 // La función cuenta el número de palabras que hay en la cadena de
 // caracteres.
 char*cad0 = "";
 int i = 0;
 cad0 = strstr(cad," ");       // Se localiza el primer espacio en blanco en la
 // cadena.
 while(strcmp(cad, " "))
 {
 strcpy(cad, cad0);
 i++;
 cad0 = strstr (cad + 1," ");
// Se busca un espacio en blanco a partir de la siguiente posición.
 }
 return(i);
 }
*/
 // 7.20
/*
 #include <stdio.h>
 #include <string.h>
 int longitud(char cad);         // Prototipo de función.
 void main(void)
 {
 int i, n, l = -1, p, t;
 char cad[50], FRA[20][50];
 printf("\nIngrese el número de filas del arreglo: ");
 scanf("%d", &n);
 for(i=0; i<n; i++)
 {
 printf("Ingrese la línea %d de texto. Máximo 50 caracteres: ", i+1);
 fflush(stdin);
 gets(FRA[i]);      // Se lee la cadena de caracteres dentro del ciclo.
 }
 printf("\n");
 for(i=0; i<n; i++)
 {
 strcpy(cad, FRA[I]);
 t = longitud (cad);
 if(t > l)
 {
 l = t;
 p = i;
 }
 }
 printf("\nLa cadena con mayor longitud es: ");
 puts(FRA[p]);
 printf("\nLongitud: %d", l);
 }
 int longitud(char*cadena)
 // Esta función calcula la longitud de la cadena. Es idéntica a la función
 // cuenta del programa 7.13.
 {
 int cue = 0;
 while(! cadena[cue] ==  ‘\0’)
 cue++;
 return (cue);
 }
*/
 // 7.21
/*
#include <stdio.h>
 #include <string.h>
 void  intercambia(char FRA[][30], int);      // Prototipo de función.
 void main(void)
 {
 int i,n;
 char FRA[20][30];
 printf("\nIngrese el número de filas del arreglo: ");
 scanf("%d", &n);
 for (i=0; i<n; i++)
 {
 printf("Ingrese la línea de texto número %d: ", i+1);
 fflush(stdin);
 gets(FRA[i]);
 }
 printf("\n\n");
 intercambia(FRA, n);
 for(i=0; i<n; i++)
 {
 printf("Impresión de la línea de texto %d: ", i+1);
 puts(FRA[i]);
 }
 }
 void intercambia(char FRA[][30], int n)
 // Esta función intercambia las filas del arreglo.
 {
 int i, j;
 j = n - 1;
 char cad[30];
 for(i=0; i < (n/2); i++)
 {
 strcpy(cad, FRA[i]);
 strcpy(FRA[i], FRA[j]);
 strcpy(FRA[j], cad);
 j--
    }
 }
*/

 // 8.1
/*
  #include <stdio.h>
 #include <string.h>
 // Estructuras-1.
//  El programa muestra la manera en que se declara una estructura, así como la
 // forma en que se tiene acceso a los campos de las variables de tipo estructura
 // tanto para asignación de valores como para lectura y escritura.
 struct alumno                        // Declaración de la estructura.
 {
 int matricula;
 char nombre[20];
 char carrera[20];                 // Campos de la estructura.
 float promedio;
 char direccion[20];
 };        // Observa que la declaración de una estructura termina con punto y
// coma.
 void main(void)
 {
 // Observa que las variables de tipo estructurase declaran como cualquier otra
 // variable. a1, a2y a3 son variables de tipo estructura alumno.
 // structalumno a1 = {120, "María”, "Contabilidad”, 8.9, "Querétaro”}, a2, a3;
 // Los campos de a1reciben valores directamente.
 char nom[20], car[20], dir[20];
 int mat;
 float pro;
 // Los campos de a2reciben valores por medio de una lectura.
 printf("\nIngrese la matrícula del alumno 2: ");
 scanf("%d", &a2.matricula);
 fflush(stdin);
 printf("Ingrese el nombre del alumno 2:");
 gets(a2.nombre);
 printf("Ingrese la carrera del alumno 2: ");
 gets(a2.carrera);
 printf("Ingrese el promedio del alumno 2:");
 scanf("%f", &a2.promedio);
 fflush(stdin);
 printf("Ingrese la dirección del alumno 2: ");
 gets(a2.direccion);
 // Los campos de a3reciben valores por medio de asignaciones.
 printf("\nIngrese la matrícula del alumno 3: ");
 scanf("%d", &mat);
 a3.matricula = mat;
 fflush(stdin);
 printf("Ingrese el nombre del alumno 3: ");
 gets(nom);
 printf("Ingrese la carrera del alumno 3: ");
 gets(car);
 strcpy(a3.carrera, car);
 printf("Ingrese el promedio del alumno 3: ");
 scanf("%f", &pro);
 a3.promedio = pro;
 fflush(stdin);
printf("Ingrese la dirección del alumno 3: ");
 gets(dir);
 strcpy(a3.direccion, dir);
 // Observe la forma en que se imprimen los campos de a1y a2.
 printf("\nDatos del alumno 1\n");
 printf("%d\n", a1.matricula);
 puts(a1.nombre);
 puts(a1.carrera);
 printf("%.2f\n", a1.promedio);
 puts(a1.direccion);
 printf("\nDatos del alumno 2\n");
 printf("%d\n", a2.matricula);
 puts(a2.nombre);
 puts(a2.carrera);
 printf("%.2f\n", a2.promedio);
 puts(a2.direccion);
 // Observa otra forma de escribir los campos de la variable de tipo estructura
 a3.
 printf("\nDatos del alumno 3\n");
 printf("%d \t %s \t %s \t %.2f \t %s", a3.matricula, a3.nombre, a3.carrera,
 a3.promedio, a3.direccion);
 }
*/
 // 8.2

/*
 #include <string.h>
 // Estructuras-2.
 // El programa muestra la manera en que se declara una estructura, así como la
 // forma en que se tiene acceso a los campos de los apuntadores de tipo estructura
 // tanto para lectura como para escritura. Se utiliza además una función que
 // recibe como parámetro un apuntador de tipo estructura.
 struct alumno                            // Declaración de la estructura.
 {
 int matricula;
 char nombre[20];
 char carrera[20];                     // Campos de la estructura alumno.
 float promedio;
 char direccion[20];
 };
 void Lectura(struct alumno *);           // Prototipo de función.
 void main(void)
 {
 struct alumno a0 = {120, "María", "Contabilidad", 8.9, "Querétaro"};
 struct alumno *a3, *a4, *a5, a6;
 // Observa que las variables *a3, *a4y *a5 se declaran como apuntadores de
 // tipo estructura alumno. a6 es una variable de tipo estructura alumno.
 a3 = &a0;          // En este caso al apuntador de tipo estructura alumno a3
 // se le asigna la dirección de la variable de tipo estructura alumno, a0.
 a4 = new(struct alumno);
 // Nota que al apuntador a4 es necesario asignarle una dirección de memoria.
 // Para tener acceso a los campos de un apuntador de tipo estructura, utiliza uno
 // de los dos formatos siguientes:
 apuntador->campo
 o bien
 (*apuntador).campo
 // En la lectura de los campos de la variable a4se utilizan como ejemplo ambos
 // formatos.
 printf("\nIngrese la matrícula del alumno 4: ");
 scanf("%d", &(*a4).matricula);
 fflush(stdin);
 printf("Ingrese el nombre del alumno 4: ");
 gets(a4->nombre);
 printf("Ingrese la carrera del alumno 4: ");
 gets((*a4).carrera);
 printf(”Ingrese promedio del alumno 4: ”);
 scanf("%f", &a4->promedio);
 fflush(stdin);
 printf("Ingrese la dirección del alumno 4: ");
 gets(a4->direccion);
 a5 = new(struct alumno);
 Lectura(a5);     // Eneste caso se pasa el apuntador de tipo estructura alumno
 a5a la función Lectura.
 Lectura(&a6);  // En este caso se pasa la variable de tipo estructura alumno a6,
 // a la función Lectura. Observa que en este caso debemos utilizar el operador de
 // dirección para preceder a la variable.
 printf("\nDatos del alumno 3\n");
 // Observa la forma de escribir los campos de los apuntadores de tipo
 // estructura.
 printf("%d\t%s\t%s\t%.2f\t%s”, a3->matricula, a3->nombre, a3->carrera,
 // a3->promedio, a3->direccion);
 printf("\nDatos del alumno 4\n");
 printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera,
 // a4->promedio, a4->direccion);
 printf("\nDatos del alumno 5\n");
 printf("%d\t%s\t%s\t%f\t%s", a5->matricula, a5->nombre, a5->carrera,
 // a5->promedio, a5->direccion);
 printf("\nDatos del alumno 6\n");
 // Observa la forma de escribir los campos de la variable tipo estructura.
printf("%d\t%s\t%s\t%.2f\t%s", a6.matricula, a6.nombre, a6.carrera,
 // a6.promedio, a6.direccion);
 }
 void Lectura(structalumno *a)
 // Esta función permite leer los campos de un apuntador de tipo estructura
 // alumno.
 {
 printf("\nIngrese la matrícula del alumno:");
 scanf("%d", &(*a).matricula);
 fflush(stdin);
 printf("Ingrese el nombre del alumno: "");
 gets(a->nombre);
 fflush(stdin);
 printf("Ingrese la carrera del alumno: ");
 gets((*a).carrera);
 printf("Ingrese el promedio del alumno: ";
 scanf("%f", &a->promedio);
 fflush(stdin);
 printf("Ingrese la dirección del alumno: ");
 gets(a->direccion);
 }
*/

 // 8.3
/*
  #include <stdio.h>
  #include <string.h>
 // Estructuras-3.
 // El programa muestra la manera en que se declara una estructura anidada, así
 // como la forma de acceso a los campos de las variables o apuntadores de tipo
 // estructura, tanto para lectura como para escritura. Se utiliza además una
 // función que recibe como parámetro un apuntador de tipo estructura.
 typedef struct        // Declaración de la estructura domicilioutilizando untypedef.
 {
 char calle[20];
 int numero;
 int cp;
 char localidad[20];
 } domicilio;
 struct empleado    // Declaración de la estructura anidadaempleado.
 {
 char nombre[20];
 char departamento[20];
 float sueldo;
 domicilio direccion;        // direccion es un campo de tipo estructura
// domicilio de la estructura empleado.
};
 void Lectura(struct empleado *a)
 // Función que permite leer los campos de un apuntador de tipo estructura
 // empleado.
 {
 printf("\nIngrese el nombre del empleado: ");
 gets(a->nombre);
 fflush(stdin);
 printf("Ingrese el departamento de la empresa: ");
 gets(a->departamento);
 printf("Ingrese el sueldo del empleado: ");
 scanf("%f", &a->sueldo);
 fflush(stdin);
 printf("—-Ingrese la dirección del empleado—-");
 printf("\n\tCalle: ");
 gets(a->direccion.calle);
 printf("\tNúmero: ");
 scanf("%d", &a->direccion.numero);
 printf("\tCódigo Postal: ");
 scanf("%d", &a->direccion.cp);
 fflush(stdin);
 printf("\tLocalidad: ");
gets(a->direccion.localidad);
 }
 void main(void)
 {
 struct empleado e0 = {"Arturo", "Compras", 15500.75, "San Jerónimo", 120, 3490, "Toluca"};
 struct empleado *e1, *e2, e3, e4;
 // Se declaran diferentes variables y apuntadores de la estructura empleado
 // para que el lector pueda apreciar también las diferentes formas en que los
 // campos reciben valores.
 // En el programa principal se leen los campos de una variable, e3, y un
 // apuntador de tipo estructura, *e1.
 e1 = new(struct empleado);
 printf("\nIngrese el nombre del empleado 1: ");
 scanf("%s", &(*e1).nombre);
 fflush(stdin);
 printf("Ingrese el departamento de la empresa: ");
 gets(e1->departamento);
 printf("Ingrese el sueldo del empleado: ");
 scanf("%f", &e1->sueldo);
 printf("—-Ingrese la dirección del empleado—-");
 printf("\n\tCalle: ");
 fflush(stdin);
 gets(e1->dirección, calle);
 printf("\tNúmero: ");
 scanf("%d", &e1->direccion.numero);
 printf("\tCódigo Postal: ");
 scanf("%d", &e1->direccion.cp);
 printf("\tLocalidad: ");
 fflush(stdin);
 gets(e1->direccion.localidad);
 printf("\nIngrese el nombre del empleado 3: ");
 scanf("%s", &e3.nombre);
 fflush(stdin);
 printf("Ingrese el departamento de la empresa: ");
 gets(e3.departamento);
 printf("Ingrese el sueldo del empleado: ");
 scanf("%f", &e3.sueldo);
 printf("—-Ingrese la dirección del empleado—-");
 printf("\n\tCalle: ");
 fflush(stdin);
 gets(e3.direccion.calle);
 printf("\tNúmero: ");
 scanf("%d", &e3.direccion.numero);
 printf("\tCódigo Postal: ");
 scanf("%d", &e3.direccion.cp);
 printf("\tLocalidad: ");
 fflush(stdin);
 gets(e3.direccion.localidad);
// En la función Lectura se leen los campos de una variable, e4, y un apuntador
 // de tipo estructura, *e2.
 e2 = new (struct empleado);
 Lectura(e2);
 Lectura(&e4);
 printf("\nDatos del empleado 1\n");
 printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e1->nombre, e1->departamento,
  e1>sueldo,
  e1->direccion.calle, e1->direccion.numero, e1->direccion.cp,
  e1->direccion.localidad);
 printf("\nDatos del empleado 4n");
 printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e4.nombre, e4.departamento, e4.sueldo,
 // e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);
 }
*/
 // 7.4
/*
  #include <stdio.h>
 #include <string.h>
 // Escuela.
 // El programa genera información estadística de los alumnos de una escuela.
 typedef struct            // Declaración de la estructura alumnoutilizando un typedef.
{
 int matricula;
 char nombre[30];
 float cal[5];
 // Observa que el campo de la estructura alumnoes un arreglo
 // unidimensional.
 } alumno;
 void Lectura(alumno,int T);
 void F1(alumno *, int TAM);                 // Prototipos de funciones.
 void F2(alumno *, int TAM);
 void F3(alumno *, int TAM);
 void main(void)
 {
 alumno ARRE[50];     // Se declara un arreglo unidimensional de tipo alumno.
 int TAM;
 do
 {
 printf("Ingrese el tamaño del arreglo: ");
 scanf("%d", &TAM);
 }
 while(TAM > 50 || TAM < 1);  // Se verifica que el tamaño del arreglo sea correcto.
 Lectura(ARRE, TAM);
 F1(ARRE, TAM);
 F2(ARRE, TAM);
 F3(ARRE, TAM);
 }
 void Lectura(alumno A[], int T)
 // La función Lectura se utiliza para leer un arreglo unidimensional de tipo
 // estructura alumno de Telementos.
 {
 int I, J;
 for (I=0; I<T; I++)
 {
 printf("\nIngrese los datos del alumno %d", I+1);
 printf("\nIngrese la matrícula del alumno: ");
 scanf("%d", &A[I].matricula);
 fflush(stdin);
 printf("Ingrese el nombre del alumno:");
 gets(A[I].nombre);
 for (J=0; J<5; J++)
 {
 printf("\tIngrese la calificación %d  del alumno %d: ", J+1, I+1);
 scanf("%f", &A[I].cal[J]);
 }
 }
 }
 void F1(alumno A[], int T)
 // La función F1 obtiene la matrícula y el promedio de cada alumno.
 {
 int I, J;
 float SUM, PRO;
 for (I=0; I<T; I++)
 {
 printf("\nMatrícula del alumno:  %d", A[I].matricula);
 SUM = 0.0;
 for (J=0; J<5; J++)
 SUM = SUM + A[I].cal[J];
 PRO = SUM / 5;
 printf("\t\tPromedio: %.2f", PRO);
 }
 }
 void F2(alumno A[], int T)
 // La función F2 obtiene las matrículas de los alumnos cuya calificación en la
 // tercera materia es mayor a 9.
 {
 intI;
 printf("\nAlumnos con calificación en la tercera materia > 9");
 for (I=0; I<T; I++)
 if (A[I].cal[2] > 9)
 printf("\nMatrícula del alumno: %d", A[I].matricula);
 }
 void F3(alumno A[], int T)
 // Esta función obtiene el promedio general del grupo de la materia 4.
 {
 int I;
 float PRO, SUM = 0.0;
 for (I=0; I<T; I++)
 SUM = SUM + A[I].cal[3];
 PRO = SUM / T;
 printf("\n\nPromedio de la materia 4: %.2f", PRO);
 }
*/
 // 7.5
/*
  #include <stdio.h>
 #include <string.h>
 // Uniones.
 //El programa muestra la manera como se declara una unión, así como la forma de
 // acceso a los campos de las variables de tipo unión tanto para asignación
 // de valores como para lectura y escritura.
 uniondatos                // Declaración de una unión.
 {
 char celular[15];
 char correo[20];
 };
 typedef struct // Declaración de una estructurautilizando typedef.
 {
 int matricula;
 char nombre[20];
 char carrera[20];
 float promedio;
 union datos personales;
// Observa que uno de los campos de la estructura alumno es una unión.
 } alumno;
 void Lectura(alumno a); // Prototipo de función.
 void main(void)
 {
 alumno a1 = {120, "María", "Contabilidad", 8.9, "5-158-40-50"}, a2, a3;
 // Observa que sólo el primer componente de una unión puede recibir valores por
 // medio de este tipo de asignaciones.
 // Para que puedas observar las diferentes formas en que los campos de las
 // variables de tipo estructura alumnoreciben valores, ingresamos los valores
 // de los campos de tres formas diferentes. Los campos de a1reciben valores
 // directamente, los campos de a2se leen en el programa principal, y los campos
 // de a3 reciben valores a través de una función.
 printf("Alumno 2\n");
 printf("Ingrese la matrícula: ");
 scanf("%d", &a2.matricula);
 fflush(stdin);
 printf(”Ingrese el nombre: ”);
 gets(a2.nombre);
 fflush(stdin);
 printf("Ingrese la carrera: ");
 gets(a2.carrera);
 printf("Ingrese el promedio: ");
 scanf("%f", &a2.promedio);
 fflush(stdin);
 printf("Ingrese el correo electrónico: ");
 gets(a2.personales.correo);
 // Observa que en la variable a2de tipo estructura alumnoel segundo campo de la
 // unión recibe un valor.
 printf("Alumno 3\n");
 Lectura(&a3);  // Se llama a una función para leer los campos de la variable a3.
// Impresión de resultados.
 printf("\nDatos del alumno 1\n");
 printf("%d\n", a1.matricula);
 puts(a1.nombre);
 puts(a1.carrera);
 printf("%.2f\n", a1.promedio);
 puts(a1.personales.celular);
// Observa que escribe el valor del teléfono celular asignado.
 // puts(a1.personales.correo);      }
 // Observa que si tratamos de imprimir el campo correo, escribe basura.
 strcpy(a0.personales.correo, "hgimenez@hotmail.com");
 // Se ingresa ahora un valor al segundo campo de la unión de la variable a0.
 puts(a0.personales.celular);
 // Ahora escribe basura en el campo del teléfono celular.
 puts(a0.personales.correo);
 // Escribe el contenido del campo (hgimenez@hotmail.com).
 printf("\nDatos del alumno 2\n");
 printf("%d\n", a2.matricula);
 puts(a2.nombre);
 puts(a2.carrera);
 printf("%.2f\n", a2.promedio);
 puts(a2.personales.celular);        // Escribe basura.
 puts(a2.personales.correo);          // Escribe el contenido del segundo campo.
 printf("Ingrese el teléfono celular del alumno 2: ");
 fflush(stdin);
 gets(a2.personales.celular);
 puts(a2.personales.celular);        // Escribe el teléfono celular ingresado.
 puts(a2.personales.correo);         // Ahora escribe basura.
 printf("\nDatos del alumno 3\n");
 printf("%d\n", a3.matricula);
 puts(a3.nombre);
 puts(a3.carrera);
 printf("%.2f\n", a3.promedio);
 puts(a3.personales.celular);
 puts(a3.personales.correo);         // Escribe basura.
 }

 void Lectura(alumno *a)
 // La función Lectura se utiliza para leer los campos de una variable de tipo
 // estructura alumno.
 {
 printf(”\nIngrese la matrícula: ”);
 scanf(”%d”, &(*a).matricula);
 fflush(stdin);
 printf(”Ingrese el nombre: ”);
 gets(a->nombre);
 fflush(stdin);
 printf(”Ingrese la carrera: ”);
 gets((*a).carrera);
 printf(”Ingrese el promedio: ”);
 scanf(”%f”, &a->promedio);
 printf(”Ingrese el teléfono celular: ”);
 fflush(stdin);
 gets(a->personales.celular);
 }

 // 8.6

 #include <stdio.h>
 #include <string.h>
 // Comercializadora farmacéutica.
 El programa maneja información sobre ventas, inventario, reabastecimiento y
 // nuevos productos de una comercializadora farmacéutica.
 typedef struct
 {
 int clave;
 char nombre[15];
 float precio;
 int existencia;
 } producto;
 void Lectura(producto *, int);
 // Declaración de la estructura producto.
 //
void Ventas(producto *, int);
 void Reabastecimiento(producto *, int);
 void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);
 voidmain(void)
 {
 producto INV[100];
 // Se declara un arreglo unidimensional de tipo estructura producto.
 intTAM, OPE;
 do
 {
 printf(”Ingrese el número de productos: ”);
 scanf(”%d”, &TAM);
 }
 while (TAM > 100  | | TAM < 1);
// Se verifica que el número de productos ingresados sea correcto.
 Lectura(INV, TAM);
 printf(”\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2
// Reabastecimiento \n\t\t
3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t   0 - Salir: ”);
 scanf(”%d”, &OPE);
 while (OPE)
 {
 switch (OPE)
 {
 case1: Ventas(INV, TAM);
 break;
 case2: Reabastecimiento(INV, TAM);
 break;
 case3: Nuevos_Productos(INV, &TAM);
// Se pasa el parámetro por referencia, porque se puede modificar el
 // número
de elementos del arreglo en la función.
 break;
 case4: Inventario(INV, TAM);
 break;
 };
 printf(”\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2
// Reabastecimiento
\n\t\t 3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t   0 - Salir: ”);
 scanf(”%d”, &OPE);
 }
 }
 voidLectura(producto A[], intT)
 // Esta función se utiliza para leer un arreglo unidimensional de tipo
 // estructura productode Telementos.
 {
 intI;
 for (I=0; I<T; I++)
 {
 printf(”\nIngrese información del producto %d”, I+1);
 printf(”\n\tClave: ”);
 scanf(”%d”, &A[I].clave);
 fflush(stdin);
 printf(”\tNombre:”);
 gets(A[I].nombre);
 printf(”\tPrecio:”);
 scanf(”%f”, &A[I].precio);
 printf(”\tExistencia: ”);
 scanf(”%d”, &A[I].existencia);
 }
 }
 voidVentas(producto A[], intT)
 // Esta función se utiliza para manejar las venta a un cliente. Se ingresan
 // productos y cantidades, el fin de datos está dado por el cero. Además de
 // obtener el total de las ventas, se actualiza el inventario.
 {
 intCLA, CAN, I, RES;
 floatTOT, PAR;
 printf(”\nIngrese clave del producto -0 para salir-: ”);
 scanf(”%d”, &CLA);
 TOT = 0.0;
 while(CLA)
 {
 printf(”\tCantidad: ”);
 scanf(”%d”, &CAN);
 I = 0;
 while ((I < T) && (A[I].clave < CLA))
// Se realiza una búsqueda para localizar la clave del producto.
 I++;
 if ((I == T) | | (A[I].clave > CLA))
 printf(”\nLa clave del producto es incorrecta”);
 else
 if(A[I].existencia >= CAN)
 // Se analiza si el stock es suficiente para satisfacer el pedido.
 {
 A[I].existencia -= CAN;    // Se actualiza el stock del producto.
 PAR = A[I].precio * CAN;
 TOT += PAR;
 }
 else
 {
 printf(”\nNo existe en inventario la cantidad solicitada. Solo hay %d”,
 A[I].existencia);
 printf(” \nLos lleva 1 - Si   0 – No?: ”);
scanf(”%d”, &RES);
 if(RES)
 {
 PAR = A[I].precio * A[I].existencia;
 A[I].existencia = 0;          // El stock queda en cero.
 TOT += PAR;
 }
 }
 printf(”\nIngrese la siguiente clave del producto -0 para salir-:);
 scanf(”%d”, &CLA);
 }
 printf(”\nTotal de la venta:  %f”, TOT);
 }
 voidReabastecimiento(producto A[], int T)
 // Esta función se utiliza para reabastecer al inventario.
 {
 intCLA,CAN,I;
 printf(”\nIngrese clave del producto -0 para salir-: ”);
 scanf(”%d”, &CLA);
 while(CLA)
 {
 I = 0;
 while ((I < T) && (A[I].clave < CLA))
 I++;
 if ((I==T) || (A[I].clave > CLA))
 printf(”\nLa clave del producto ingresada es incorrecta”);
 else
 {
 printf(”\tCantidad: ”);
 scanf(”%d”, &CAN);
 A[I].existencia += CAN;
 }
 printf(”\nIngrese otra clave del producto -0 para salir-: ”);
 scanf(”%d”, &CLA);
 }
 }
 voidNuevos_Productos(producto A[], int*T)
 // Esta función se utiliza para incorporar nuevos productos al inventario.
 // Dado que los productos se encuentran ordenados por clave, puede suceder que
 // al insertar un nuevo producto haya que mover los elementos del arreglo para
 // que continúen ordenados.
 {
 intCLA, I, J;
 printf(”\nIngrese clave del producto -0 para salir-: ”);
 scanf(”%d”, &CLA);
 while((*T < 30) && (CLA))
 {
 I=0;
 while ((I < *T) && (A[I].clave < CLA))
// Búsqueda de la posición que le corresponde a CLA en el arreglo.
 I++;
 if (I == *T)      // Se inserta el elemento en la última posición.
 {
 A[I].clave = CLA;
 printf(”\tNombre:”);
 fflush(stdin);
 gets(A[I].nombre);
 printf(”\tPrecio:”);
 scanf(”%f”, &A[I].precio);
 printf(”\tCantidad: ”);
 scanf(”%d”, &A[I].existencia);
 *T = *T + 1;
 }
 else
 if (A[I].clave == CLA)
 printf(”\nEl producto ya se encuentra en el inventario”);
 else
 {
 for (J=*T;  J>I;  J--)
// Se inserta el nuevo producto en el arreglo. Se mueven una posición
 // a la derecha los elementos
del arreglo que tengan una clave de producto mayor a la ingresada.
 A[J] = A[J-1];
 A[I].clave = CLA;
 printf(”\tNombre:”);
 fflush(stdin);
 gets(A[I].nombre);
 printf(”\tPrecio:”);
 scanf(”%f”, &A[I].precio);
 printf(”\tCantidad: ”);
 scanf(”%d”, &A[I].existencia);
 *T = *T + 1;
 }
 printf(”\nIngrese otra clave de producto -0 para salir-: ”);
 scanf(”%d”, &CLA);
 }
 if (*T == 30)
 printf(”\nYa no hay espacio para incorporar nuevos productos”);
 }
 voidInventario(producto A[], intT)
 // Esta función se utiliza para escribir la información almacenada en —el
 // inventario— un arreglo unidimensional de tipo estructura productode T
 // elementos.
 {
 int I;
 for(I=0; I<T; I++)
 {
 printf(”\nClave: %d”, A[I].clave);
 printf(”\tNombre: %s”, A[I].nombre);
 printf(”\tPrecio: %d”, A[I].precio);
 printf(”\tExistencia: %d \n”, A[I].existencia);
 }
 }


 // 8.7


  #include <stdio.h>
 #include <string.h>
 // Escuela.
 El programa genera información importante de los alumnos de una escuela.
 typedef struct // Declaración de la estructuramatpro.
 {
 charmat[20];   // Materia.
 intpro;        // Promedio.
 } matpro;
 typedef struct                // Declaración de la estructura alumno.
 {
 intmatri;      // Matrícula.
 charnom[20];   // Nombre del alumno.
 matpro cal[5];  // Observa que cales un arreglo unidimensional de tipo
 // estructura
 matpro—la estructura definida en primer término.
 } alumno;
 void Lectura(alumno * ,int);
voidF1(alumno *, int);
 voidF2(alumno *, int);                   //Prototipos de funciones.
 voidF3(alumno *, int);
 voidmain(void)
 {
 alumno ALU[50];        // ALUes un arreglo unidimensional de tipo alumno.
 intTAM;
 do
 {
 printf(”Ingrese el tamaño del arreglo: ”);
 scanf(”%d”, &TAM);
 }
 while(TAM > 50 | | TAM < 1);  // Se verifica que el tamaño del arreglo sea
 // correcto.
 Lectura(ALU, TAM);
 F1(ALU, TAM);
 F2(ALU, TAM);
 F3(ALU, TAM);
 }
 voidLectura(alumno A[], intT)
 // Esta función se utiliza para leer la información de un arreglo unidimensional
 // de tipo estructura alumnode Telementos.
 {
 intI, J;
 for(I=0; I<T; I++)
 {
 printf(”\nIngrese los datos del alumno %d”, I+1);
 printf(”\nIngrese la matrícula del alumno: ”);
 scanf(”%d”, &A[I].matri);
 fflush(stdin);
 printf(”Ingrese el nombre del alumno:”);
 gets(A[I].nom);
 for (J=0; J<5; J++)
 {
 printf(”\tMateria %d: ”, J+1);
 fflush(stdin);
 gets(A[I].cal[J].mat);
 printf(”\tPromedio %d: ”, J+1);
 scanf(”%d”, &A[I].cal[J].pro);
 }
 }
 }
 voidF1(alumno A[], intT)
 // Esta función se utiliza para obtener la matrícula y el promedio general de
 // cada alumno.
 {
 intI, J;
 float SUM;
 for (I=0; I<T; I++)
 {
 printf(”\nMatrícula del alumno : %d”, A[I].matri);
 SUM = 0.0;
 for (J=0; J<5; J++)
 SUM = SUM + A[I].cal[J].pro;
 SUM = SUM / 5;
 printf(”\tPromedio: %.2f”, SUM);
 }
 }
 voidF2(alumno A[], intT)
 // Esta función se utiliza para obtener las matrículas de los alumnos cuya
 // calificación en la tercera materia es mayor a 9.
 {
 intI;
 printf(”\nAlumnos con calificación mayor a 9 en la tercera materia”);
 for (I=0; I<T; I++)
 if (A[I].cal[2].pro > 9)
 printf(”\nMatrícula del alumno : %d”, A[I].matri);
 }
 void F3(alumno A[], intT)
 // Esta función se utiliza para obtener el promedio general de la cuarta materia.
 {
 int I;
 float SUM = 0.0;
 for (I=0; I<T; I++)
 SUM = SUM + A[I].cal[3].pro;
 SUM = SUM / T;
 printf(”\n\nPromedio de la cuarta materia: %.2f”, SUM);
 }

 // 8.8

  #include <stdio.h>
 #include <string.h>
 // Hospital.
 El programa genera información acerca de los pacientes de un hospital.
 typedef struct // Declaración de la estructuradomicilio.
 {
 charcal[20];         // Calle.
 intnum;              // Número.
 char col[20];         // Colonia.
 charcp[5];           // Código Postal.
 char ciu[20];         // Ciudad.
 } domicilio;
 typedef struct // Declaración de la estructura paciente.
 {
 charnom[20];         // Nombre y apellido.
 intedad;
 charsexo;
 intcon;              // Condición.
 domicilio dom;          // Observa que el campo dom es de tipo estructura
 // domicilio.
 chartel[10];         // Teléfono.
 } paciente;
 voidLectura(paciente *, int);
voidF1(paciente *, int);
 voidF2(paciente *, int);                //Prototipos de funciones.
 voidF3(paciente *, int);
 voidmain(void)
 {
 paciente HOSPITAL[100];   // Arreglo unidimensional de tipo estructura
 // paciente.
 intTAM;
 do
 {
 printf(”Ingrese el número de pacientes: ”);
 scanf(”%d”, &TAM);
 }
 while(TAM > 50 | | TAM < 1);   // Se verifica que el tamaño del arreglo sea
 // correcto.
 Lectura(HOSPITAL, TAM);
 F1(HOSPITAL, TAM);
 F2(HOSPITAL, TAM);
 F3(HOSPITAL, TAM);
 }
 voidLectura(paciente A[], intT)
 // Esta función se utiliza para leer un arreglo unidimensional de tipo
 // estructura pacientede Telementos.
 {
 intI;
 for (I=0; I<T; I++)
 {
 printf(”\n\t\tPaciente %d”, I+1);
 fflush(stdin);
 printf(”\nNombre: ”);
 gets(A[I].nom);
 printf(”Edad: ”);
 scanf(”%d”, &A[I].edad);
 printf(”Sexo (F-M): ”);
 scanf(”%c”, &A[I].sexo);
 printf(”Condición (1..5): ”);
 scanf(”%d”, &A[I].con);
 fflush(stdin);
 printf(”\tCalle: ”);
 gets(A[I].dom.cal);
 printf(”\tNúmero: ”);
 scanf(”%d”, &A[I].dom.num);
 fflush(stdin);
 printf(”\tColonia: ”);
 gets(A[I].dom.col);
 fflush(stdin);
 printf(”\tCódigo Postal: ”);
 gets(A[I].dom.cp);
 fflush(stdin);
 printf(”\tCiudad: ”);
 gets(A[I].dom.ciu);
 fflush(stdin);
 printf(”Teléfono: ”);
 gets(A[I].tel);
 }
 }
 voidF1(paciente A[], intT)
// Esta función se utiliza para obtener el porcentaje tanto de hombres como de
 // mujeres registrados en el hospital.
 {
 intI,FEM, MAS, TOT;
 for (I=0; I<T; I++)
 switch(A[I].sexo)
 {
 case'F’: FEM++;
 break;
 case'M’: MAS++;
 break;
 }
 TOT = FEM + MAS;
 printf(”\nPorcentaje de Hombres: %.2f%”, (float)MAS / TOT * 100);
 printf(”\nPorcentaje de Mujeres: %.2f%”, (float)FEM / TOT * 100);
 }
 voidF2(paciente A[], intT)
 // Esta función se utiliza para obtener el número de pacientes que ingresaron al
 // hospital en cada una de las categorías de condición.
 {
 intI, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
 for (I=0; I<T; I++)
 switch(A[I].con)
 {
 case1: C1++;
 break;
 case2: C2++;
 break;
 case3: C3++;
 break;
 case4: C4++;
 break;
 case5: C5++;
 break;
 }
 printf(”\nNúmero pacientes en condición 1: %d”, C1);
 printf(”\nNúmero pacientes en condición 2: %d”, C2);
 printf(”\nNúmero pacientes en condición 3: %d”, C3);
 printf(”\nNúmero pacientes en condición 4: %d”, C4);
 printf(”\nNúmero pacientes en condición 5: %d”, C5);
 }
 voidF3(paciente A[], intT)
 // La función F3 se utiliza para generar el nombre y teléfono de todos los
 // pacientes que tuvieron una condición de ingreso de máxima gravedad (5).
{
 intI;
 printf(”\nPacientes ingresados en estado de gravedad”);
 for (I=0; I<T; I++)
 if (A[I].con == 5)
 printf(”\nNombre: %s\tTeléfono: %s”, A[I].nom, A[I].tel);
 }

 // 8.9

  #include <stdio.h>
 #include <string.h>
 // Bienes raíces.
 El programa maneja información sobre las propiedades que tiene una empresa
 // de bienes raíces de la ciudad de Lima, Perú, tanto para venta como para
 // renta.
typedef struct // Declaración de la estructuraubicación.
 {
 charzona[20];
 charcalle[20];
 char colo[20];        // Colonia.
 } ubicacion;
 typedef struct // Declaración de la estructurapropiedades.
 {
 charclave[5];
 floatscu;              // Superficie cubierta.
 floatste;              // Superficie terreno.
 charcar[50];           // Características.
 ubicacion ubi;             // Observa que este campo es de tipo estructura
ubicación.
 floatprecio;
 chardispo;                // Disponibilidad.
 } propiedades;
 voidLectura(propiedades , int);
 voidF1(propiedades *,int); // Prototipos de funciones.
 voidF2(propiedades *, int);
 voidmain(void)
 {
 propiedades PROPIE[100];
// Se declara un arreglo unidimensional de tipo estructurapropiedades.
 intTAM;
 do
 {
 printf(”Ingrese el número de propiedades: ”);
 scanf(”%d”, &TAM);
 }
 while(TAM > 100  | | TAM < 1);
// Se verifica que el tamaño del arreglo sea correcto.
 Lectura(PROPIE, TAM);
 F1(PROPIE, TAM);
 F2(PROPIE, TAM);
 }
 voidLectura(propiedades A[], intT)
 // Esta función se utiliza para leer un arreglo unidimensional de tipo estructura
 // propiedadesde Telementos.
{
 intI;
 for (I=0; I<T; I++)
{
 printf(”\n\tIngrese datos de la propiedad %d”, I + 1);
 printf(”\nClave: ”);
 fflush(stdin);
 gets(A[I].clave);
 printf(”Superficie cubierta: ”);
 scanf(”%f”, &A[I].scu);
 printf(”Superficie terreno: ”);
 scanf(”%f”, &A[I].ste);
 printf(”Características: ”);
 fflush(stdin);
 gets(A[I].car);
 printf(”\tZona: ”);
 fflush(stdin);
 gets(A[I].ubi.zona);
 printf(”\tCalle: ”);
 fflush(stdin);
 gets(A[I].ubi.calle);
 printf(”\tColonia: ”);
 fflush(stdin);
 gets(A[I].ubi.colo);
 printf(”Precio: ”);
 scanf(”%f”, &A[I].precio);
 printf(”Disponibilidad (Venta-V  Renta-R): ”);
scanf(”%c”, &A[I].dispo);
 }
 }
 voidF1(propiedades A[], int T)
 // Esta función se utiliza para generar un listado de las propiedades
 // disponibles para venta en la zona de Miraflores, cuyo valor oscila entre
 // 450,000 y 650,000 nuevos soles.
 {
 intI;
 printf(”\n\t\tListado de Propiedades para Venta en Miraflores”);
 for (I=0; I<T; I++)
 if((A[I].dispo == 'V’) && (strcmp (A[I].ubi.zona, "Miraflores”) == 0))
 if((A[I].precio >= 450000) && (A[I].precio <= 650000))
 {
 printf(”\nClave de la propiedad: ”);
 puts(A[I].clave);
 printf(”\nSuperficie cubierta: %f”, A[I].scu);
 printf(”\nSuperficie terreno: %f”, A[I].ste);
 printf(”\nCaracterísticas: ”);
 puts(A[I].car);
 printf(”Calle: ”);
 puts(A[I].ubi.calle);
 printf(”Colonia: ”);
 puts(A[I].ubi.colo);
 printf(”Precio: %.2f\n”, A[I].precio);
 }
 }
 voidF2(propiedades A[], intT)
 // Al recibir como datos una zona geográfica de Lima, Perú, y un cierto rango
 // respecto al monto, esta función genera un listado de todas las propiedades
 // disponibles para renta.
 {
 intI;
 floatli, ls;
 charzon[20];
 printf(”\n\t\tListado de Propiedades para Renta”);
 printf(”\nIngrese zona geográfica: ”);
fflush(stdin);
 gets(zon);
 printf(”Ingrese el límite inferior del precio:”);
 scanf(”%f”, &li);
 printf(”Ingrese el límite superior del precio:”);
 scanf(”%f”, &ls);
 for (I=0; I<T; I++)
 if((A[I].dispo == 'R’) && (strcmp (A[I].ubi.zona, zon) == 0))
 if((A[I].precio >= li) && (A[I].precio <= ls))
 {
 printf(”\nClave de la propiedad: ”);
 puts(A[I].clave);
 printf(”\nSuperficie cubierta: %d”, A[I].scu);
 printf(”\nSuperficie terreno: %d”, A[I].ste);
printf(”\nCaracterísticas: ”);
 puts(A[I].car);
 printf(”Calle: ”);
 puts(A[I].ubi.calle);
 printf(”Colonia: ”);
 puts(A[I].ubi.colo);
 printf(”Precio: %.2f”, A[I].precio);
 }
 }


 // 8.10

  #include <stdio.h>
 #include <string.h>
 {
 // Vendedores.
 El programa maneja información sobre las ventas que realizan los vendedores de
 // artículos domésticos de una importante empresa de la Ciudad de México.
 typedef struct
 // Declaración de la estructura banco.
 {
 char noba[10];        // Nombre del banco.
 charnucu[10];        // Número de cuenta.
 } banco;
 typedef union // Declaración de la unionfpago.
 {
 banco che;            // Cheque. Campo de tipo estructura banco.
 banco nomi;           // Cómina. Campo de tipo estructura banco.
 charventa;           // Ventanilla.
 } fpago;
 typedef struct // Declaración de la estructuradomicilio.
 {
 charcnu[20];         // Calle y número.
 charcol[20];         // Colonia.
 charcp[5];           // Código Postal.
 charciu[15];         // Ciudad.
 } domicilio;
 typedefstruct // Declaración de la estructuravendedor.
 {
 intnum;             // Número de vendedor.
 charnom[20];        // Nombre del vendedor.
 floatven[12];        // Ventas del año. Arreglo unidimensional de tipo real.
 domicilio domi;      // domies de tipo estructura domicilio.
 floatsal;             // Salario mensual.
 fpago pago;            // pago es de tipo unión fpago.
 intcla;               // Clave forma de pago.
 } vendedor;
 voidLectura(vendedor *,int);
 voidF1(vendedor *, int);
 voidF2(vendedor *, int); //Prototipos de funciones.
 voidF3(vendedor *, int);
 voidF4(vendedor *, int);
 voidmain(void)
 {
 vendedor VENDEDORES[100];
// Declaración del arreglo unidimensional de tipo estructura vendedor.
 intTAM;
 do
 {
 printf(”Ingrese el número de vendedores: ”);
 scanf(”%d”, &TAM);
 }
while(TAM > 100  | | TAM < 1);
 // Se verifica que el número de elementos del arreglo sea correcto.
 Lectura (VENDEDORES, TAM);
 F1 (VENDEDORES, TAM);
 F2 (VENDEDORES, TAM);
F3 (VENDEDORES, TAM);
 F4 (VENDEDORES, TAM);
 printf(”\n\tFIN DEL PROGRAMA”);
 }
 voidLectura(vendedor A[], intT)
 // Esta función se utiliza para leer un arreglo unidimensional de tipo
 // estructura vendedorde Telementos.
 {
 intI, J;
 for (I=0; I<T; I++)
 {
 printf(”\n\tIngrese datos del vendedor %d”, I+1);
 printf(”\nNúmero de vendedor: ”);
 scanf(”%d”, &A[I].num);
 printf(”Nombre del vendedor: ”);
 fflush(stdin);
 gets(A[I].nom);
 printf(”Ventas del año: \n”);
 for (J=0; J<12; J++)
 {
 printf(”\tMes %d: ”, J+1);
 scanf(”%f”, &A[I].ven[J]);
 }
 printf(”Domicilio del vendedor: \n”);
 printf(”\tCalle y número: ”);
 fflush(stdin);
 gets(A[I].domi.cnu);
 printf(”\tColonia: ”);
 fflush(stdin);
 gets(A[I].domi.col);
 printf(”\tCódigo Postal: ”);
 fflush(stdin);
 gets(A[I].domi.cp);
 printf(”\tCiudad: ”);
 fflush(stdin);
 gets(A[I].domi.ciu);
 printf(”Salario del vendedor: ”);
 scanf(”%f”, &A[I].sal);
 printf(”Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ”);
 scanf(”%d”, &A[I].cla);
 switch(A[I].cla)
 {
 case1:{
 printf(”\tNombre del banco: ”);
 fflush(stdin);
 gets(A[I].pago.che.noba);
 printf(”\tNúmero de cuenta: ”);
 fflush(stdin);
 gets(A[I].pago.che.nucu);
 }
break;
 case2:{
 printf(”\tNombre del banco: ”);
 fflush(stdin);
 gets(A[I].pago.nomi.noba);
 printf(”\tNúmero de cuenta: ”);
 fflush(stdin);
 gets(A[I].pago.nomi.nucu);
 }
 break;
 case3: A[I].pago.venta = 'S';
 break;
 }
 }
 }
 void F1(vendedor A[], intT)
 // Esta función se utiliza para generar las ventas totales anuales de cada uno
 // de los vendedores de la empresa.
 {
 intI, J;
 floatSUM;
 printf(”\n\t\tVentas Totales de los Vendedores”);
 for (I=0; I<T; I++)
 {
 printf(”\nVendedor: %d”, A[I].num);
 SUM = 0.0;
 for(J=0; J<12; J++)
 SUM += A[I].ven[J];
 printf(”\nVentas: %.2f\n”, SUM);
 }
 }
 voidF2(vendedor A[], intT)
 // Esta función se utiliza para incrementar 5% el salario de todos aquellos
 // vendedores cuyas ventas anuales superaron $1,500,000.
 {
 intI, J;
 floatSUM;
 printf (”\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$”);
 for (I=0; I<T; I++)
 {
 SUM = 0.0;
 for(J=0; J<12; J++)
 SUM += A[I].ven[J];
 if (SUM > 1500000.00)
 {
 A[I].sal = A[I].sal * 1.05;
 printf(”\nNúmero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f”,
A[I].num, SUM, A[I].sal);
 }
 }
 }
 void F3(vendedor A[], intT)
 // Esta función se utiliza para generar un listado de todos aquellos
 // vendedores que en el año vendieron menos de $300,000.
 {
 intI, J;
 floatSUM;
 printf(”\n\t\tVendedores con Ventas < 300,000”);
 for (I=0; I<T; I++)
 {
 SUM = 0.0;
 for(J=0; J<12; J++)
 SUM += A[I].ven[J];
 if(SUM < 300000.00)
 printf(”\nNúmero de empleado: %d\nNombre: %s\nVentas: %.2f”, A[I].num,
A[I].nom, SUM);
 }
 }
 voidF4(vendedor A[], intT)
 // Esta función se usa para imprimir el número de empleado, el nombre del
 // banco y el número de cuenta de todos aquellos empleados a quienes se les
 // deposita su sueldo en cuenta de cheques.
 {
 int I;
 floatSUM;
 printf(”\n\t\tVendedores con Cuenta en el Banco”);
 for (I=0; I<T; I++)
 if(A[I].cla == 1)
 printf(”\nNúmero de vendedor: %d\n Banco: %s\nCuenta: %s”,
 // A[I].num,
A[I].pago.che.noba, A[I].pago.che.nucu);
 }

*/
