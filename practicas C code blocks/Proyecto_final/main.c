/*
Programa de gestion de gastos de vehículo por kilómetros (pueden usar IA):
Gestion de vehículo Crear
    Placa
    Marca
    Modelo
    Tipo Combustible
    Km x galón Carretera
    Km x Galon Ciudad

    Costo Gomas y Km de gomas
    Costo Seguro por 12 meses
    Costo mantenimiento y cuantos kilómetros
    Costo vehículo Vida util Depreciación Km por agno promedio

    Borrar
    Modificar

    Gestion de datos generales

    Costo Combustible Gasolina
    Costo combustible Gasoil

    Calculo costo viaje

    Selección vehículo
    Selección kilómetros del viaje
    Porcentaje de km en ciudad

    Resultado desglosado

    Costo de gomas
    Costo de seguro
    Costo de combustible
    Costo mantenimiento
    Costo vehículo

    Resultado:

    costo por km Resultado
    costo total viaje
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICULOS 100

typedef struct {
    char placa[20];
    char marca[20];
    char modelo[20];
    char tipoCombustible[15]; // Gasolina o Gasoil
    float kmGalonCarretera;
    float kmGalonCiudad;
    float costoGomas;
    float kmVidaGomas;
    float costoSeguroAnual;
    float costoMantenimiento;
    float kmMantenimiento;
    float costoVehiculo;
    float vidaUtilKm;
} Vehiculo;

typedef struct {
    float costoGasolina;
    float costoGasoil;
} DatosGenerales;

Vehiculo vehiculos[MAX_VEHICULOS];
int totalVehiculos = 0;
DatosGenerales datos;

// Guardar vehículos en archivo
void guardarDatos() {
    FILE *f = fopen("vehiculos.dat", "wb");
    if (f) {
        fwrite(&totalVehiculos, sizeof(int), 1, f);
        fwrite(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
        fclose(f);
    }
    FILE *dg = fopen("datos_generales.dat", "wb");
    if (dg) {
        fwrite(&datos, sizeof(DatosGenerales), 1, dg);
        fclose(dg);
    }
}

// Cargar datos desde archivo
void cargarDatos() {
    FILE *f = fopen("vehiculos.dat", "rb");
    if (f) {
        fread(&totalVehiculos, sizeof(int), 1, f);
        fread(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
        fclose(f);
    }
    FILE *dg = fopen("datos_generales.dat", "rb");
    if (dg) {
        fread(&datos, sizeof(DatosGenerales), 1, dg);
        fclose(dg);
    }
}

// Crear vehículo
void crearVehiculo() {
    if (totalVehiculos >= MAX_VEHICULOS) {
        printf("No se pueden agregar más vehículos.\n");
        return;
    }
    Vehiculo v;
    printf("Placa: "); scanf(" %[^\n]", v.placa);
    printf("Marca: "); scanf(" %[^\n]", v.marca);
    printf("Modelo: "); scanf(" %[^\n]", v.modelo);
    printf("Tipo Combustible (Gasolina/Gasoil): "); scanf(" %[^\n]", v.tipoCombustible);
    printf("Km por galón carretera: "); scanf("%f", &v.kmGalonCarretera);
    printf("Km por galón ciudad: "); scanf("%f", &v.kmGalonCiudad);
    printf("Costo gomas: "); scanf("%f", &v.costoGomas);
    printf("Km vida útil gomas: "); scanf("%f", &v.kmVidaGomas);
    printf("Costo seguro anual: "); scanf("%f", &v.costoSeguroAnual);
    printf("Costo mantenimiento: "); scanf("%f", &v.costoMantenimiento);
    printf("Km entre mantenimientos: "); scanf("%f", &v.kmMantenimiento);
    printf("Costo del vehículo: "); scanf("%f", &v.costoVehiculo);
    printf("Vida útil del vehículo (km): "); scanf("%f", &v.vidaUtilKm);

    vehiculos[totalVehiculos++] = v;
    guardarDatos();
    printf("Vehículo agregado correctamente.\n");
}

// Mostrar vehículos
void listarVehiculos() {
    for (int i = 0; i < totalVehiculos; i++) {
        printf("[%d] %s - %s %s (%s)\n", i + 1, vehiculos[i].placa, vehiculos[i].marca, vehiculos[i].modelo, vehiculos[i].tipoCombustible);
    }
}

// Modificar vehículo
void modificarVehiculo() {
    listarVehiculos();
    int idx;
    printf("Seleccione número de vehículo a modificar: ");
    scanf("%d", &idx);
    idx--;
    if (idx < 0 || idx >= totalVehiculos) {
        printf("Índice inválido.\n");
        return;
    }
    printf("Modificando vehículo %s\n", vehiculos[idx].placa);
    crearVehiculo();
}

// Borrar vehículo
void borrarVehiculo() {
    listarVehiculos();
    int idx;
    printf("Seleccione número de vehículo a borrar: ");
    scanf("%d", &idx);
    idx--;
    if (idx < 0 || idx >= totalVehiculos) {
        printf("Índice inválido.\n");
        return;
    }
    for (int i = idx; i < totalVehiculos - 1; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }
    totalVehiculos--;
    guardarDatos();
    printf("Vehículo borrado.\n");
}

// Gestionar datos generales
void gestionarDatosGenerales() {
    printf("Costo gasolina: "); scanf("%f", &datos.costoGasolina);
    printf("Costo gasoil: "); scanf("%f", &datos.costoGasoil);
    guardarDatos();
}

// Calcular costo de viaje
void calcularCostoViaje() {
    listarVehiculos();
    int idx;
    printf("Seleccione vehículo: ");
    scanf("%d", &idx);
    idx--;
    if (idx < 0 || idx >= totalVehiculos) {
        printf("Índice inválido.\n");
        return;
    }
    float kmViaje, porcCiudad;
    printf("Kilómetros del viaje: "); scanf("%f", &kmViaje);
    printf("Porcentaje en ciudad (0-100): "); scanf("%f", &porcCiudad);

    Vehiculo v = vehiculos[idx];

    // Costo combustible
    float kmCiudad = kmViaje * (porcCiudad / 100.0);
    float kmCarretera = kmViaje - kmCiudad;
    float galones = (kmCiudad / v.kmGalonCiudad) + (kmCarretera / v.kmGalonCarretera);
    float precioCombustible = (strcmp(v.tipoCombustible, "Gasolina") == 0) ? datos.costoGasolina : datos.costoGasoil;
    float costoCombustible = galones * precioCombustible;

    // Costo gomas
    float costoGomas = (kmViaje / v.kmVidaGomas) * v.costoGomas;
    // Costo seguro proporcional
    float costoSeguro = (v.costoSeguroAnual / 12.0) * (kmViaje / (v.vidaUtilKm / 12.0));
    // Costo mantenimiento
    float costoMantenimiento = (kmViaje / v.kmMantenimiento) * v.costoMantenimiento;
    // Depreciación vehículo
    float costoVehiculo = (kmViaje / v.vidaUtilKm) * v.costoVehiculo;

    float costoTotal = costoCombustible + costoGomas + costoSeguro + costoMantenimiento + costoVehiculo;
    float costoPorKm = costoTotal / kmViaje;

    printf("\n--- Resultado ---\n");
    printf("Costo combustible: %.2f\n", costoCombustible);
    printf("Costo gomas: %.2f\n", costoGomas);
    printf("Costo seguro: %.2f\n", costoSeguro);
    printf("Costo mantenimiento: %.2f\n", costoMantenimiento);
    printf("Costo vehículo (depreciación): %.2f\n", costoVehiculo);
    printf("Costo total viaje: %.2f\n", costoTotal);
    printf("Costo por km: %.2f\n", costoPorKm);
}

int main() {
    cargarDatos();
    int opcion;
    do {
        printf("\n--- Gestión de Vehículos ---\n");
        printf("1. Crear vehículo\n");
        printf("2. Listar vehículos\n");
        printf("3. Modificar vehículo\n");
        printf("4. Borrar vehículo\n");
        printf("5. Gestionar datos generales\n");
        printf("6. Calcular costo viaje\n");
        printf("0. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: crearVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: modificarVehiculo(); break;
            case 4: borrarVehiculo(); break;
            case 5: gestionarDatosGenerales(); break;
            case 6: calcularCostoViaje(); break;
            case 0: guardarDatos(); printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
    return 0;
}
