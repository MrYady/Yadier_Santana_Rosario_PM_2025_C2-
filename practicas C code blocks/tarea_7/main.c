/* TAREA 7

/* 9.1 */
/*
 #include <stdio.h>
 // Archivos y caracteres.
 // El programa escribe caracteres en un archivo.
 void main(void){
  char p1;
  FILE *ar;
  ar = fopen("arc.txt", "w");    // Se abre el archivo arc.txt para escritura.
  if (ar != NULL){
    while ((p1=getchar()) !=  '\n')
        // Se escriben caracteres en el archivo mientras no se detecte el caracter
        //// que indica el fin de la línea.
        fputc(p1, ar);
        fclose(ar);                            // Se cierra el archivo.
    }
    else
        printf("No se puede abrir el archivo");
 }
*/
 // 9.2
 /*
#include <stdio.h>
 // Archivos y caracteres.
 // El programa lee caracteres de un archivo.
 void main(void){
    char p1;
    FILE *ar;
    if((ar = fopen("arc.txt", "r")) != NULL)  // Se abre el archivo para lectura.
    // Observa que las dos instrucciones del programa 9.1 necesarias para abrir un
    // archivo y verificar que éste en realidad se haya abierto, se pueden agrupar
    // en una sola instrucción.
    {
    while (!feof(ar))
        // Se leen caracteres del archivo mientras no se detecte el fin del
        // archivo.
    {
        p1 = fgetc(ar);      // Lee el caracter del archivo.
        putchar(p1);         // Despliega el caracter en la pantalla.
    }
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
 }
*/
 // 9.3
/*
#include <stdio.h>
 // Archivos y cadenas de caracteres.
 // El programa escribe cadenas de caracteres en un archivo.
 void main(void)
 {
    char cad[50];
    int res;
    FILE *ar;
    if ((ar = fopen("arc.txt", "w")) != NULL)
        // Se abre el archivo para escritura. En la misma instrucción se verifica si se
        // pudo abrir.
    {
        printf("\n¿Desea ingresar una cadena de caracteres?  Sí-1 No-0:");
        scanf("%d", &res);
    while  (res){
        fflush(stdin);
        printf("Ingrese la cadena: ");
        gets(cad);
        fputs(cad, ar);     // Observa la forma como se escribe la cadena en el archivo.
        printf("\n¿Desea ingresar otra cadena de caracteres?  Sí-1  No-0:");
        scanf("%d", &res);
        if (res)
            fputs("\n", ar);
            // Se indica un salto de línea, excepto en la última cadena. Si no
            // se hiciera esta indicación, la función ffppuuttsspegaría las cadenas y
            // luego tendríamos dificultades en el momento de leerlas. Por otra
            // parte, si realizáramos este salto de línea al final de la última
            // cadena, en la escritura se repetiría la última cadena.
    }
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
 }
*/
 // 9.4
/*
#include <stdio.h>
 // Archivos y cadenas de caracteres.
 //El programa lee cadenas de caracteres de un archivo.
 void main(void){
    char cad[50];
    FILE *ap;
    if ((ap=fopen ("arc.txt", "r")) != NULL)
        // Se abre el archivo para lectura y se verifica si se abrió correctamente.
    {
        while  (!feof(ap))
        // Mientras no se detecte el fin de archivo se siguen leyendo cadenas de
        // caracteres.
        {
            fgets(cad, 50, ap);
            // Observa que la instrucción para leer cadenas requiere de tres
            // argumentos.
            puts(cad);       // Despliega la cadena en la pantalla.
        }
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");
 }
*/

 // 9.5
/*
  #include <stdio.h>
 // Archivos con variables enteras y reales.
 //El programa almacena datos de un grupo de alumnos en un archivo.
 void main(void) {
    int i, j, n, mat;
    float cal;
    FILE *ar;
    printf("\nIngrese el número de alumnos: ");
    scanf("%d", &n);
    // Se asume que el valor que ingresa el usuario está comprendido entre 1 y 35.
    if ((ar = fopen("arc8.txt", "w")) != NULL)
    {
        fprintf(ar,"%d ", n);            // Se escribe el número de alumnos en el
        // archivo.
        for (i=0; i<n; i++)
        {
            printf("\nIngrese la matrícula del alumno %d: ", i+1);
            scanf("%d", &mat);
            fprintf(ar,"\n%d ", mat);   // Se escribe la matrícula en el
            // archivo.
            for (j=0; j<5; j++)
            {
                printf("\nCalificación %d: ", j+1);
                scanf("%f", &cal);
                fprintf(ar,"%.2f ", cal);   // Se escriben las calificaciones en
                // el archivo.
            }
        }
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
 }
*/
 // 9.6
/*
  #include <stdio.h>
 // Archivos con variables enteras y reales.
 // El programa lee datos de alumnos almacenados en un archivo y escribe la
 // matrícula y el promedio de cada alumno.
 void main(void)
 {
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        fscanf(ar, "%d", &n);             // Se lee el valor de nn.
        for  (i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat);       // Se lee la matrícula de cada alumno.
            printf("%d\t", mat);
            pro = 0;
            for (j=0; j<5; j++)
            {
                fscanf(ar, "%f", &cal);      // Se leen las cinco calificaciones
                // del alumno.
                pro += cal;
            }
            printf("\t %.2f  ", pro / 5);   // Se escribe el promedio de cada alumno.
            printf("\n");
        }
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
 }
*/
 // 9.7
/*
 #include <stdio.h>
 // Archivos con variables enteras y reales.
 // El programa lee información de los alumnos de una escuela, almacenada en un
 // archivo. Utiliza una función para realizar la lectura, pero el archivo se abre
 // y cierra desde el programa principal.
 void promedio(FILE *);
 // Prototipo de función. Se pasa un archivo como parámetro.
 void main(void)
 {
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) !=  NULL)
    {
        promedio(ar);        // Se llama a la función pprroommeeddiioo. Observe la forma como se pasa el archivo como parámetro.
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
}
void promedio(FILE *ar1) // Observa la forma como se recibe el archivo.Esta función lee los datos de los alumnos desde un archivo, e imprime tanto la matrícula como el promedio de cada alumno.
{
    int i, j, n, mat;
    float pro, cal;
    fscanf(ar1, "%d", &n);

    for  (i=0; i<n; i++)
    { fscanf(ar1, "%d", &mat);
        printf("%d\t", mat);
        pro = 0;

        for (j = 0; j < 5; j++)
        {
            fscanf(ar1, "%f", &cal);
            pro += cal;
        }
        printf("\t %.2f ", pro / 5);
        printf("\n");
    }
 }
*/
 // 9.8
/*
 #include <stdio.h>
 // Alumnos.
 // El programa almacena variables de tipo estructura alumno en un archivo.
 typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}alumno;
 // Declaración de la estructura alumno.
 void escribe(FILE *);         // Prototipo de función.
 void main(void)
 {
    FILE *ar;
    if  ((ar = fopen ("ad1.dat", "w")) != NULL)
        escribe(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
 }
 void escribe(FILE *ap)
 // Esta función sirve para leer los datos de los alumnos utilizando una
 // estructura  tipo  alumno, que se almacenará posteriormente en un archivo.
 {
    alumno alu;
    int i = 0, r;
    printf("\n¿Desea ingresar informacion sobre alumnos? (Si-1  No-0):  ");
    scanf("d", &r);
    while(r)
    {
        i++;
        printf("Matrícula del alumno %d: ", i);
        scanf("%d", &alu.matricula);
        printf("Nombre del alumno %d: ", i);
        fflush(stdin);
        gets(alu.nombre);
        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);
        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);
        fwrite(&alu, sizeof(alumno), 1, ap);
        // Observa que la función ffwwrriittee tiene cuatro argumentos. El primero se
        // utiliza para indicar la variable tipo estructura que se desea almacenar; el
        // segundo muestra el tamaño de esa variable en términos de bytes; el tercero
        // señala el número de variables que se leerán o almacenarán en el dispositivo
        // de almacenamiento secundario, y el último representa el apuntador al inicio de
        // la estructura FILE.
        printf("\n¿Desea ingresar informacion sobre mas alumnos? (Si-1 No-0):  ");
        scanf("%d", &r);
    }
 }
*/
 // 9.9
/*
 #include <stdio.h>
 // Alumnos.
 //El programa lee bloques —variables de tipo eessttrruuccttuurraa  aalluummnnoo— de un archivo
 // de acceso directo.
 typedef struct {           // Declaración de la eessttrruuccttuurraa  aalluummnnoo.
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
 } alumno;
 void  lee(FILE *);    // Prototipo de función.
 void  main(void)
 {
    FILE *ar;
    if((ar = fopen ("ad1.dat", "r")) != NULL)
        escribe(ar);
    else
        printf("\nEl archivo no se puede abrir");
        fclose(ar);
 }
 void lee(FILE *ap)// Esta función se utiliza para leer bloques de un archivo de acceso directo.
 {
    alumno alu;
    read(&alu, sizeof(alumno), 1, ap);
     // Observa que la función ffrreeaadd tiene los mismos argumentos que la función
     // ffwwrriittee del programa anterior. También es importante tomar nota de que cuando
     // tenemos que leer los registros de un archivo utilizando una estructura
     // repetitiva como el wwhhiillee, debemos realizar una primera lectura antes de
     // ingresar al ciclo y luego las siguientes dentro del ciclo, pero como última
     // instrucción del mismo. Esto se debe a que la lógica que siguen las
     // instrucciones ffwwrriittee  yy ffrreeaadd  es moversey leer o escribir, según sea el caso.
     // Si no lo hiciéramos de esta forma, terminaríamos escribiendo la información
     // del último registro dos veces. Vamos a realizar un ejemplo sencillo para
     // comprobar esto.
     while (!feof(ap))
     {
        printf("\nMatrícula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %f\t ", alu.promedio);
        puts(alu.nombre);
        fread(&alu, ssiizzeeooff(alumno), 1, ap);
     }
 }
*/
 // 9.10
/*
  #include <stdio.h>
 // Alumnos.
 // El programa pregunta al usuario el número de registro que desea
 // modificar, obtiene el nuevo promedio del alumno y modifica tanto el
 // registro como el archivo correspondiente.
 typedef  struct // Declaración de la eessttrruuccttuurraa  aalluummnnoo.
 {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
 } alumno;
 void modifica(FILE *);    // Prototipo de función.
 void main(void)
 {
    FILE *ar;
    if ((ar = fopen ("ad1.dat", "r+")) != NULL)
        modifica(ar);
    else
        printf("\nEl archivo no se puede abrir");
        fclose(ar);
 }
 void modifica(FILE *ap) // Esta función se utiliza para modificar el promedio de un alumno.
 {
    int d;
        alumno alu;
        printf("\nIngrese el número de registro que desea modificar: ");
     // Observa que el lenguaje C almacena el primer registro en la
     // posición cero. Por lo tanto, si desea modificar el registro n,
     // debe buscarlo en la posición n-1.
     // scanf(”%d”, &d);
        fseek(ap, (d-1)*sizeof(alumno), 0);
     // Observa que la instrucción ffsseeeekktiene tres argumentos. El primero
     // indica que el apuntador se debe posicionar al inicio del FILE.
     // El segundo señala el número de bloques que debe moverse, en términos
     // de bytes, para llegar al registro correspondiente. Nota que el
     // primer registro ocupa la posición 0. Finalmente, el tercer argumento
     // muestra a partir de qué posición se debe mover el bloque de bytes:
     // se utiliza el 0 para indicar el inicio del archivo, 1 para expresar
     // que se debe mover a partir de la posición en la que actualmente se
     // encuentra y 2 para indicar que el movimiento es a partir del fin del
     // archivo.
        fread(&alu, sizeof(alumno), 1, ap);
     // Luego de posicionarnos en el registro que nos interesa, lo
     // leemos.
        printf("\nIngrese el promedio correcto del alumno: ");
        scanf("%f", &alu.promedio);   // Modificamos el registro con el
     // nuevo promedio.
        fseek(ap, (d-1)*sizeof(alumno), 0);
     // Nos tenemos que posicionar nuevamente en el lugar correcto para
     // escribir el registro modificado. Observa que si no hacemos este
     // reposicionamiento escribiríamos el registro actualizado en la
     // siguiente posición.
        fwrite(&alu, sizeof(alumno), 1, ap);
 }
*/
 // 9.11
/*
  #include <stdio.h>
 // Incrementa salarios.
 // El programa incrementa el salario de los empleados de una empresa
 // actualiza el archivo correspondiente— si sus ventas son superiores al millón de pesos anuales.
 typedef  struct        // Declaración de la eessttrruuccttuurraa  eemmpplleeaaddoo.
 {
    int  clave;
    int departamento;
    float salario;
    float ventas[12];
 }empleado;
 void incrementa(FILE *);    // Prototipo de función.
 void main(void)
 {
     FILE *ar;
     if  ((ar = fopen("ad.dat", "r+")) != NULL)
        // El archivo se abre en la modalidad para leer y escribir.
         incrementa(ar);
    else
         printf("\nEl archivo no se puede abrir");
         rewind(ar);
         // La función rreewwiinndd se utiliza para posicionarnos en el inicio del
         // archivo cada vez que sea necesario. En este programa no tiene ninguna
         // utilidad, sólo se escribió para explicar su uso.
         fclose(ar);
 }
 void  incrementa(FILE *ap)
     // Esta función se utiliza para incrementar el salario de todos aquellos
     // empleados que hayan tenido ventas anuales por más de $1,000,000.
     // Actualiza además el archivo correspondiente.
 {
    int i, j, t;
    float sum;
    empleado emple;
    t = sizeof(empleado);
    // La función ssiizzeeooff se utiliza para conocer el tamaño de la eessttrruuccttuurraa
    // eemmpplleeaaddoo.
     fread(&emple, sizeof(empleado), 1, ap);   // Se lee el primer registro
     // del archivo.
     while(!feof(ap))
     {
         i = ftell(ap) / t;
         // La función fftteellll se utiliza para conocer la posición de nuestro
         // apuntador en el archivo. La variable ii nos proporciona en este caso
         // eltamaño de todos los bloques que existen debajo de nuestra
         // posición. Siconocemos el tamaño de cada bloque, entonces podemos
         // obtener el númerode bloques que hay exactamente debajo de nuestra
         // posición.
         sum = 0;
         for (j=0; j<12; j++)
         sum += emple.ventas[j];  // Se calculan las ventas de cada
         // vendedor.
        if  (sum > 1000000)
        {
             emple.salario = emple.salario * 1.10;  // Se incrementa el
             // salario.
             fseek(ap, (i-1)*sizeof(empleado), 0);
            // Nos posicionamos para escribir el registro actualizado.
             fwrite(&emple, sizeof(empleado), 1, ap);
             fseek(ap, i*sizeof(empleado), 0);
             // Nos posicionamos nuevamente para leer el siguiente registro.
             // Esta instrucción no debería ser necesaria, pero la función
             // ffwwrriittee se comporta a veces de manera inestable en algunos
             // compiladores de CC. Para asegurarnos que siempre funcione
             // correctamente, realizamos este nuevo reposicionamiento.
        }
        fread(&emple, sizeof(empleado), 1, ap);
    }
 }

*/
 // 9.12
/*
  #include <stdio.h>
 // Incorpora caracteres.
 // El programa agrega caracteres al archivo libro.txt.
 void main(void)
 {
     char p1;
     FILE *ar;
     ar = fopen("libro.txt", "a");
     // Se abre el archivo con la opción para incorporar caracteres.
     if (ar != NULL)
     {
         while ((p1 = getchar()) != '\n')
         fputc(p1, ar);
         fclose(ar);
     }
     else
        printf("No se puede abrir el archivo");
 }
*/
 // 9.13
/*
  #include <stdio.h>
 // Cuenta caracteres.
 // El programa, al recibir como dato un archivo de texto y un caracter, cuenta
 // el número de veces que se encuentra el caracter en el archivo.
 int cuenta(char);                // Prototipo de función.
 void main(void)
 {
     int res;
     char car;
     printf("\nIngrese el caracter que se va a buscar en el archivo: ");
     car = getchar();
     res = cuenta(car);
     if  (res != -1)
        printf("\n\nEl caracter %c se encuentra en el archivo %d veces", car, res);
    else
        printf("No se pudo abrir el archivo");
 }

int cuenta(char car)
     // Esta función determina cuántas veces se encuentra el caracter en el
     // archivo.
 {
    int res, con = 0;
     char  p;
     FILE *ar;
     if ((ar = fopen ("arc.txt", "r")) != NULL)    // Se abre el archivo para lectura.
        {
            while (!feof(ar))    // Se trabaja con el archivo mientras no se llegue
             // al fin de éste.
             {
                p = getc(ar);
                 if  (p == car)   // Se realiza la comparación de los caracteres.
                    con++;
             }
             fclose(ar);
             res = con;
        }
        else
            res = -1;
            return  (res);
 }
*/
 // 9.14
/*
 #include <stdio.h>
 #include <ctype.h>
 // Letras minúsculas y mayúsculas.
 // El programa, al recibir como dato un archivo formado por cadenas de caracteres,
 // determina el número de letras minúsculas y mayúsculas que hay en el archivo.
 void minymay(FILE *);                  // Prototipo de función.
 // Observa que esta función va a recibir un archivo como parámetro.
 void main(void)
 {
     char p;
     FILE *ar;
     if ((ar = fopen("arc.txt", "r")) != NULL)
     {
         minymay(ar);
        // Se llama a la función mmiinnyymmaayy. Se pasa el archivo aarr como parámetro.
         fclose(ar);
     }
     else
        printf("No se pudo abrir el archivo");
 }
 void minymay(FILE *arc)
 // Esta función cuenta el número de minúsculas y mayúsculas que hay en el archivo arc.
 {
     int  min = 0, may = 0;
     char p;
     while (!feof(arc))
     {
         p = fgetc(arc);   // Se utiliza la función ffggeettcc(()) para leer caracteres
         // del archivo.
         if  (islower(p))
            min++;
         else
             if (isupper(p))
             may++;
     }
    printf("\nNúmero de minúsculas: %d", min);
    printf("\nNúmero de mayúsculas: %d", may);
 }
*/

 // 9.15
/*
  #include <stdio.h>
 #include <ctype.h>
 // Letras minúsculas y mayúsculas.
 // El programa, al recibir como dato un archivo formado por cadenas de
 // caracteres, determina el número de letras minúsculas y mayúsculas que hay
 // en el archivo.
 void minymay(FILE *);             // Prototipo de función.
 void main(void)
 {
     FILE *ap;
     if  ((ap = fopen ("arc.txt", "r")) != NULL)
     {
         minymay(ap);
         fclose(ap);
     }
     else
        printf("No se puede abrir el archivo");
     }
void minymay(FILE *ap1)
     // Esta función se utiliza para leer cadenas de caracteres de un archivo
     // y contar el número de letras minúsculas y mayúsculas que existen en el
     // archivo.
 {
     char cad[30];
     int i, mi = 0, ma = 0;
     while  (!feof(ap1))
     {
        fgets(cad,30,ap1);
        // Se utiliza la función ffggeettss(())  para leer cadenas de caracteres del
        // archivo.
        i=0;
         while  (cad[i] != '\0')
         {
            if  (islower(cad[i]))
                mi++;
            else
                if (isupper(cad[i]))
                ma++;
                i++;
         }
     }
     printf("\n\nNúmero de letras minúsculas: %", mi);
     printf("\nNúmero de letras mayúsculas: %d", ma);
 }

*/
 // 9.16
/*
 #include <stdio.h>
 #include <stdlib.h>
 // Suma reales.
 // El programa lee cadenas de caracteres de un archivo, detecta aquellas que
 // comienzan con números, los suma y calcula el promedio de los mismos.
 void sumypro(FILE *);                 // Prototipo de función.
 void main(void)
 {
     FILE *ap;
     if ((ap=fopen("arc.txt", "r")) != NULL)
     {
         sumypro(ap);
        // Se llama a la función ssuummyypprroo. Se pasa el archivo aapp como parámetro.
         fclose(ap);
     }
     else
        printf("No se puede abrir el archivo");
     }
 void sumypro(FILE *ap1)
     // Esta función lee cadenas de caracteres de un archivo, detecta aquellas
     // que comienzan con números, y obtiene la suma y el promedio de dichos
     // números.
 {
     char cad[30];
     int i = 0;
     float sum = 0.0, r;

     while  (!feof (ap1))
     {
         fgets(cad,30,ap1);            // Se lee la cadena del archivo.
         r = atof(cad);
         // Recuerda que la función aattooff convierte una cadena de caracteres que
         // contiene números reales a un valor de tipo ddoouubbllee. Si la cadena comienza
         // con otro caracter o no contiene números, regresa 0 o el valor queda
         // indefinido.
         if  (r)
         {
            i++;
            sum += r;
         }
     }
 printf("\nSuma: %.2f", sum);
    if (i)  // Si el valor de ii  es distinto de cero, calcula el promedio.
    printf("\nPromedio: %.2f", sum/i);
 }

*/
 // 9.17
/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
 // Reemplaza palabras.
 // El programa lee cadenas de caracteres de un archivo y cada que vez que
 // encuentra la palabra México escrita en forma incorrecta —la primera con
 // minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
 // archivo.
 void cambia(FILE *, FILE *);
 // Prototipo de función. Se pasan dos archivos como parámetros.
 void main(void)
 {
     FILE *ar;
     FILE *ap;
     ar = fopen("arc.txt", "r");   // Se abre el archivo aarrcc..ttxxtt para lectura.
     ap = fopen("arc1.txt", "w");  // Se abre el archivo aarrcc11..ttxxtt para escritura.
     if  ((ar != NULL) && (ap != NULL))
     {
         cambia(ar, ap);
         fclose(ar);
         fclose(ap);
     }
     else
         printf("No se pueden abrir los archivos");
 }
 void  cambia(FILE *ap1, FILE *ap2)
 {
     // Esta función reemplaza en la cadena de caracteres la palabra mmééxxiiccoo escrita
     // con minúsculas —la primera letra— por su forma correcta y escribe la cadena
     // de caracteres en un nuevo archivo.
     int i, j, k;
     char cad[30], *cad1="", *cad2="", aux[30];

     while  (!feof(ap1))
     {
         fgets(cad, 30, ap1);
         strcpy(cad1, cad);
         cad2 = strstr(cad1, "méxico");     // Localiza la subcadena mmééxxiiccoo
         // en ccaadd11.
         while  (cad2!=NULL)
         {
             cad2[0]='M';           // Reemplaza la letra minúscula por la mayúscula.
             i = strlen(cad1);
             j = strlen(cad2);
             k = i - j;    // En kkse almacena la diferencia de las longitudes de
             // las cadenas cad1 y cad2.
             if  (k)
             {
                 strncpy(aux, cad1, k);
                 // Se copia la subcadena de kkcaracteres de ccaadd11 a aauuxx—desde el
                 // inicio de cad1 hasta el caracter anterior a mmééxxiiccoo.
                 aux[k] = '\0';
                 strcat(aux, cad2);
                 strcpy(cad1, aux);
             }
             else
                 strcpy(cad1, cad2);
                 cad2 = strstr(cad1, "méxico");
         }
         fputs(cad1, ap2);     // Se escribe la cadena correcta en el archivo aapp22.
     }
 }
*/
 // 9.18
/*
#include <stdio.h>
 // Mezcla.
 // El programa mezcla, respetando el orden, dos archivos que se encuentran
 // ordenados en forma ascendente considerando la matrícula de los alumnos.
 void mezcla(FILE *, FILE *, FILE *);          // Prototipo de función.
 void main(void)
 {
     FILE *ar, *ar1, *ar2;
     ar = fopen("arc9.dat", "r");
     ar1 = fopen("arc10.dat", "r");
     ar2 = fopen("arc11.dat", "w");

     if (((ar != NULL) && (ar1 != NULL)) && (ar2 != NULL))
     {
         mezcla(ar, ar1, ar2);
         fclose(ar);
         fclose(ar1);
         fclose(ar2);
     }
     else
        printf("No se pueden abrir los archivos");
 }
 void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
   // Esta función mezcla, respetando el orden, dos archivos que se encuentran
   // ordenados en función de la matrícula.
     {
     int i, mat, mat1, b=1, b1=1;
     float ca[3], ca1[3], cal;
     while (((!feof(ar)) || !b) && ((!feof(ar1)) || !b1))
     {
         if (b)
         // Si la bandera b está encendida, se lee del archivo ar la
         // matrícula y las tres calificaciones del alumno.
         {
             fscanf(ar, "%d", &mat);
             for (i=0; i<3; i++)
             fscanf(ar, "%f", &ca[i]);
             b = 0;
         }
         if (b1)  // Si la bandera b1 está encendida, se lee del archivo ar
         // la matrícula y las tres calificaciones del alumno.
         {
             fscanf(ar1, "%d", &mat1);
             for (i=0; i<3; i++)
             fscanf(ar1, "%f", &ca1[i]);
             b1 = 0;
         }
         if (mat < mat1)
         {
             fprintf(ar2, "%d\t", mat);
             for (i=0; i<3; i++)
             fprintf(ar2, "%f\t", ca[i]);
             fputs("\n", ar2);
             b = 1;
         }
         else
         {
             fprintf(ar2, "%d\t", mat1);
             for (i=0; i<3; i++)
             fprintf(ar2, "%f\t", ca1[i]);
             fputs("\n", ar2);
             b1 = 1;
         }
     }
     if  (!b)
     {
         fprintf(ar2, "%d\t", mat);
         for (i=0; i<3; i++)
         fprintf(ar2, "%f\t", ca[i]);
         fputs("\n", ar2);
         while  (!feof(ar))
         {
             fscanf(ar, "%d", &mat);
             fprintf(ar2, "%d\t", mat);
             for (i=0; i<3; i++)
             {
                 fscanf(ar, "%f", &cal);
                 fprintf(ar2, "%f\t", cal);
             }
             fputs("\n", ar2);
         }
     }
     if(!b1)
     {
         fprintf(ar2, "%d\t", mat1);
         for  (i=0; i<3; i++)
             fprintf(ar2, "%f\t", ca1[i]);
             fputs("\n", ar2);
         while  (!feof(ar1))
         {
             fscanf(ar1, "%d", &mat1);
             fprintf(ar2, "%d\t", mat1);
         for (i=0; i<3; i++)
         {
             fscanf(ar1, "%f", &cal);
             fprintf(ar2, "%f\t", cal);
         }
             fputs("\n", ar2);
         }
     }
 }
*/
 // 9.19
/*
  #include <stdio.h>
 // Ordena de menor a mayor.
 // El programa ordena de menor a mayor en función de la matrícula, creando un
 // nuevo archivo, un archivo de acceso directo compuesto por estructuras y
 // ordenado de mayor a menor.
 typedef  struct                                      // Declaración de la eessttrruuccttuurraa  aalluummnnoo.
 {
     int matricula;
     char nombre[20];
     int carrera;
     float promedio;
 } alumno;
 void ordena(FILE *, FILE *);    // Prototipo de función. .
 void main(void)
 {
     FILE *ar1, *ar2;
     ar1 = fopen("ad5.dat", "r");
     ar2 = fopen("ad6.dat", "w");
     if ((ar1 != NULL) && (ar2 != NULL))
        ordena(ar1, ar2);
     else
        printf("\nEl o los archivos no se pudieron abrir");
        fclose(ar1);
        fclose(ar2);
 }
void ordena(FILE *ap1, FILE *ap2)
   // Esta función ordena de menor a mayor un archivo compuesto por estructuras,
   // en función de su matrícula, y genera un nuevo archivo.
{
     alumno alu;
     int t, n, i;
     t = sizeof(alumno);
     fseek (ap1, sizeof(alumno), 2);
     n = (ftell(ap1) / t) - 1;
     // Se obtiene el número de registros que componen el archivo. El valor de n,
     // a su vez, se utilizará para posicionarnos en el archivo.
     rewind(ap1);
     for (i = (n-1); i >= 0; i--)           // Se utiliza un ciclo descendente.
     {
         fseek(ap1, i * sizeof(alumno), 0);
         fread(&alu, sizeof(alumno), 1, ap1);
         fwrite(&alu, sizeof(alumno), 1, ap2);
     }
 }
*/
 //9.20
/*
  #include <stdio.h>
 // Escuela.
 // El programa, al recibir como dato un archivo de acceso directo que contiene
 // información de los alumnos de una escuela, genera información estadística
 // importante.
 typedef  struct                                  // Declaración de la eessttrruuccttuurraa mmaattccaall.
 {
    char materia[20];
    int  calificacion;
 } matcal;
typedef  struct                    // Declaración de la eessttrruuccttuurraa aalluummnnoo.
 {
    int  matricula;
    char  nombre[20];
    matcal cal[5];
    // Observa que un campo de esta estructura es a su vez estructura.
 } alumno;
 void F1(FILE *);
 void  F2(FILE *);               // Prototipos de funciones.
 float F3(FILE *);
 void main(void)
 {
    float pro;
    FILE *ap;
    if  ((ap = fopen("esc.dat", "r")) != NULL)
    {
        F1(ap);
        F2(ap);
        pro = F3(ap);
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %f", pro);
    }
    else
        printf("\nEl archivo no se puede abrir");
        fclose(ap);
    }
 void  F1(FILE *ap) // La función escribe la matrícula y el promedio general de cada alumno.
 {
    alumno alu;
    int j;
    float sum, pro;
    printf("\nMATRÍCULA y PROMEDIOS");
    fread (&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        printf("\nMatrícula: %d", alu.matricula);
        sum = 0.0;
        for  (j=0; j<5; j++)
            sum += alu.cal[j].calificacion;
            pro = sum / 5;
            printf("\tPromedio: %f", pro);
            fread(&alu, sizeof(alumno), 1, ap);
    }
 }
 void F2(FILE *ap)
 // La función escribe la matrícula de los alumnos cuya calificación en la
 // tercera materia es mayor a 9.
 {
    alumno alu;
    int j;
    rewind(ap);
    printf("\n\nALUMNOS CON CALIFICACIÓN > 9 EN MATERIA 3");
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        if  (alu.cal[2].calificacion > 9)
            printf("\nMatrícula del alumno: %d", alu.matricula);
            fread(&alu, sizeof(alumno), 1, ap);
    }
 }
 float F3(FILE *ap)
 // Esta función obtiene el promedio general de la materia 4.
 {
    alumno alu;
    int i = 0;
    float sum = 0, pro;
    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while(!feof(ap))
    {
        i++;
        sum += alu.cal[3].calificacion;
        fread(&alu, sizeof(alumno), 1, ap);
    }
    pro = (float)sum / i;
    return  (pro);
 }
*/

 // 9.21
/*
  #include <stdio.h>
 // Examen de admisión.
 // El programa, al recibir como dato un archivo de acceso directo que contiene
 // información sobre los alumnos que presentaron el examen de admisión a una
 // universidad, genera información importante para el Departamento de Control
 // Escolar.
 typedef struct
{
     int clave;
     char nombre[20];
     int carrera;
     float promedio;
     float examen;
     char telefono[12];
 } alumno;
    // Declaración de la estructura alumno.
 float F1(FILE *);
 void F2(FILE *,FILE *, FILE *, FILE *, FILE *, FILE *);
 void F3(FILE *, FILE *, FILE *, FILE *, FILE *);  // Prototipos de funciones.
 void main(void)
 {
     float pro;
     FILE *ap, *c1, *c2, *c3, *c4, *c5;
     ap = fopen("alu1.dat", "r");
     // Observa que los archivos car1.dat, car2.dat, car3.dat, car4.dat y car5.dat
     // se abren en la modalidad para escribir y leer.
     c1 = fopen("car1.dat", "w+");
     c2 = fopen("car2.dat", "w+");
     c3 = fopen("car3.dat", "w+");
     c4 = fopen("car4.dat", "w+");
     c5 = fopen("car5.dat", "w+");
     if ((ap!=NULL) && (c1!=NULL) && (c2!=NULL) && (c3!=NULL) &&
     (c4!=NULL) && (c5!=NULL))
     {
     pro = F1(ap);
     printf("\nPROMEDIO EXAMEN DE ADMISIÓN: %.2f", pro);
     F2(ap, c1, c2, c3, c4, c5);
     F3(c1, c2, c3, c4, c5);
     }
     else
         printf("\nEl o los archivos no se pudieron abrir");
         fclose(ap);
         fclose(c1);
         fclose(c2);
         fclose(c3);
         fclose(c4);
         fclose(c5);
 }
float F1(FILE *ap)
 // Esta función obtiene el promedio del examen de admisión.
 {
    alumno alu;
    float sum = 0, pro;
    int i = 0;
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        i++;
        sum += alu.examen;
        fread(&alu, sizeof(alumno), 1, ap);
    }
    pro = sum / i;
    return (pro);
 }
 void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
 // Esta función genera un archivo de los alumnos admitidos en cada una de
 // las carreras de la universidad.
 {
    alumno alu;
    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap))
    {
        // Se analiza si el candidato es admitido a la universidad.
        if (((alu.examen >= 1300) && (alu.promedio >= 8)) ((alu.examen >=
        // 1400) &&
        (alu.promedio >= 7)))
        {
            switch (alu.carrera)
            {
                 case 1:  fwrite(&alu, sizeof(alumno), 1, c1);
                 break;
                 case 2:  fwrite(&alu, sizeof(alumno), 1, c2);
                 break;
                 case 3:  fwrite(&alu, sizeof(alumno), 1, c3);
                 break;
                 case 4:  fwrite(&alu, sizeof(alumno), 1, c4);
                 break;
                 case 5:  fwrite(&alu, sizeof(alumno), 1, c5);
                 break;
            }
        }
    fread(&alu, sizeof(alumno), 1, ap);
    }
 }
 void F3 (FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
 // Esta función se utiliza para obtener el promedio que consiguieron los
 // alumnos admitidos en cada una de las carreras.
 {
    alumno alu;
    float cal[5], sum;
    int i, j;
    i = 0;
    sum = 0;
    rewind(c1);     // Es importante posicionarse al inicio del archivo, pues
    // de lo contrario se generaría un error al ejecutar el programa.
    fread(&alu, sizeof(alumno), 1, c1);
    while (!feof(c1))
    {
        i++;
        sum += alu.examen;
        fread(&alu, sizeof(alumno), 1, c1);
    }
    if (i)
        cal[0] = (sum / i);
    else
        cal[0] = 0;
        rewind(c2);
        sum = 0;
        i = 0;
        fread(&alu, sizeof(alumno), 1, c2);
    while (!feof(c2))
    {
        i++;
        sum += alu.examen;
        fread(&alu, sizeof(alumno), 1, c2);
    }
    if (i)
        cal[1] = (sum / i);
    else
        cal[1] = 0;
        rewind(c3);
        sum = 0;
        i = 0;
        fread(&alu, sizeof(alumno), 1, c3);
        while (!feof(c3))
        {
            i++;
            sum += alu.examen;
            fread(&alu, sizeof(alumno), 1, c3);
        }
        if (i)
            cal[2] = (sum / i);
        else
            cal[2] = 0;
            rewind(c4);
            sum = 0;
            i = 0;
            fread(&alu, sizeof(alumno), 1, c4);
            while (!feof(c4))
            {
                i++;
                sum += alu.examen;
                fread(&alu, sizeof(alumno), 1, c4);
            }
            if  (i)
                cal[3] = (sum / i);
            else
                cal[3] = 0;
                rewind(c5);
                sum = 0;
                i = 0;
                fread(&alu, sizeof(alumno), 1, c5);
            while (!feof(c5))
            {
                i++;
                sum += alu.examen;
                fread(&alu, sizeof(alumno), 1, c5);
            }
            if  (i)
                cal[4] = (sum / i);
            else
                cal[4] = 0;
                // Se imprimen los promedios de los alumnos admitidos en cada carrera.
                for (i=0; i<5; i++)
                printf("\nPromedio carrera %d: %.2f", i+1, cal[i]);
 }
*/


