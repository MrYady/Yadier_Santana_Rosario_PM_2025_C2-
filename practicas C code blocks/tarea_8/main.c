#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100
#define FILE_NAME "arc.txt"

typedef struct {
    char nombre[MAX_NAME];
    int edad;
    int matricula;
} Alumno;

void guardarAlumnos(Alumno *alumnos, int cantidad) {
    FILE *f = fopen(FILE_NAME, "wb");
    if (!f) {
        perror("No se pudo abrir el archivo para escribir");
        exit(1);
    }

    fwrite(&cantidad, sizeof(int), 1, f);  // Escribimos cantidad de alumnos
    fwrite(alumnos, sizeof(Alumno), cantidad, f);  // Escribimos los alumnos
    fclose(f);
}

Alumno* leerAlumnos(int *cantidad) {
    FILE *f = fopen(FILE_NAME, "rb");
    if (!f) {
        perror("No se pudo abrir el archivo para leer");
        exit(1);
    }

    fread(cantidad, sizeof(int), 1, f);  // Leemos cantidad de alumnos

    Alumno *alumnos = (Alumno*) malloc(sizeof(Alumno) * (*cantidad));
    if (!alumnos) {
        perror("No se pudo asignar memoria");
        exit(1);
    }

    fread(alumnos, sizeof(Alumno), *cantidad, f);  // Leemos los alumnos
    fclose(f);
    return alumnos;
}

int main() {
    int cantidad, i;
    Alumno *alumnos;

    printf("Cuantos alumnos desea ingresar?");
    scanf("%d", &cantidad);

    alumnos = (Alumno*) malloc(sizeof(Alumno) * cantidad);

    for (i = 0; i < cantidad; i++) {
        printf("Alumno #%d \n", i + 1);
        printf("Nombre: ");
        getchar();  // Limpiar buffer
        fgets(alumnos[i].nombre, MAX_NAME, stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0';  // Quitar salto de línea

        printf("Edad: ");
        scanf("%d", &alumnos[i].edad);
        printf("Matricula: ");
        scanf("%d", &alumnos[i].matricula);
    }

    // Guardar en disco
    guardarAlumnos(alumnos, cantidad);
    free(alumnos);

    // Leer desde disco usando memoria dinámica
    Alumno *copia = leerAlumnos(&cantidad);
    printf("\n--- Alumnos leídos desde disco ---\n");

    Alumno *ptr = copia;
    for (i = 0; i < cantidad; i++, ptr++) {
        printf("Nombre: %s\n", ptr->nombre);
        printf("Edad: %d\n", ptr->edad);
        printf("Matricula: %d\n\n", ptr->matricula);
    }

    free(copia);
    return 0;
}
