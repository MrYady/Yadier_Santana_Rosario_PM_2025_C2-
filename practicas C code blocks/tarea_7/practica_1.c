
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "alumnos.dat"
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    int matricula;
    float promedio;
} Alumno;

// Guardar arreglo en archivo binario
void guardarEnArchivo(Alumno *alumnos, int cantidad) {
    FILE *f = fopen(FILE_NAME, "wb");
    if (!f) {
        perror("Error al abrir archivo");
        exit(1);
    }

    fwrite(&cantidad, sizeof(int), 1, f); // guarda cantidad
    fwrite(alumnos, sizeof(Alumno), cantidad, f);
    // La función fwrite envía, desde el array apuntado por
    // puntero, hasta nmemb de elementos cuyo tamaño es
    // especificado por tamanyo, al stream apuntado por stream.
    fclose(f);
}

// Leer arreglo desde archivo binario
Alumno* leerDesdeArchivo(int *cantidad) {
    FILE *f = fopen(FILE_NAME, "rb");
    if (!f) {
        perror("Error al abrir archivo");
        exit(1);
    }

    fread(cantidad, sizeof(int), 1, f);
    // fread devuelve el número de elementos completos que lee la funció.
    Alumno *alumnos = (Alumno*) malloc(sizeof(Alumno) * (*cantidad));
    // malloc es una función que se utiliza para asignar un bloque de memoria
    // dinámica en el montón (heap) durante la ejecución del programa.
    if (!alumnos) {
        perror("No hay memoria");
        exit(1);
    }

    fread(alumnos, sizeof(Alumno), *cantidad, f);
    // fread devuelve el número de elementos completos
    // que lee la función, en este caso devuelve el numero de alumnos.
    fclose(f);
    return alumnos;
}

// Mostrar lista de alumnos
void mostrarAlumnos(Alumno *alumnos, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Matricula: %d\n", alumnos[i].matricula);
        printf("Promedio: %.2f\n\n", alumnos[i].promedio);
    }
}

// Ordenar por nombre (A-Z)
void ordenarPorNombre(Alumno *alumnos, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
                Alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

// Ordenar por promedio (mayor a menor)
void ordenarPorPromedio(Alumno *alumnos, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (alumnos[j].promedio < alumnos[j + 1].promedio) {
                Alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

int main() {
    int cantidad;
    Alumno *alumnos;
      void AgregarAlumnos(){

            for (int i = 0; i < cantidad; i++) {
                printf("\nAlumno #%d:\n", i + 1);
                printf("Nombre: ");
                fgets(alumnos[i].nombre, MAX_NOMBRE, stdin);
                alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0';

                printf("Edad: ");
                scanf("%d", &alumnos[i].edad);
                printf("Matricula: ");
                scanf("%d", &alumnos[i].matricula);
                printf("Promedio: ");
                scanf("%f", &alumnos[i].promedio);
                getchar(); // limpiar buffer
                printf("\nGuardando alumno\n");
                _sleep(2000);


            }

        }

     void agregarCantidad(){
        printf("Cuantos alumnos desea ingresar? ");
        scanf("%d", &cantidad);
        printf("\nPreparando todo para ingresar alumnos... \n");
        _sleep(3000);
        getchar(); // limpiar buffer

        Alumno *alumnos = (Alumno*) malloc(sizeof(Alumno) * cantidad);
        AgregarAlumnos();
     }
    agregarCantidad();
    // Ingreso de datos


    // Guardar en archivo binario
    guardarEnArchivo(alumnos, cantidad);
    free(alumnos);

    // Leer desde archivo
    alumnos = leerDesdeArchivo(&cantidad);

    int opcion;
    do {
        printf("\n--- MENU ---\n");
        printf("1.- Mostrar alumnos en orden alfabetico.\n");
        printf("2.- Mostrar alumnos por promedio (mayor a menor).\n");
        printf("3.- Agregar alumnos.\n");
        printf("4.- Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nUn momento, Buscando archivo...");
                _sleep(2000);
                ordenarPorNombre(alumnos, cantidad);
                mostrarAlumnos(alumnos, cantidad);
                break;
            case 2:
                printf("\nUn momento, Buscando archivo...");
                _sleep(2000);
                ordenarPorPromedio(alumnos, cantidad);
                mostrarAlumnos(alumnos, cantidad);
                break;
            case 3:
                printf("\nUn momento, estamos preparando el archivo...\n");
                _sleep(2500);
                agregarCantidad();
                break;

            case 4:
                printf("\nSaliendo...\n");
                _sleep(4000);

                break;
            default:
                printf("Opción inválida.\n");
        }
    } while(opcion != 3);

    free(alumnos);
    return 0;
}
