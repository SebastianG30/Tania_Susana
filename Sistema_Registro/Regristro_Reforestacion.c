#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOLUNTARIOS 6
#define MAX_POR_ZONA 2
#define TOTAL_ZONAS 3
#define EDAD_MINIMA 15

typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    int edad;
    int zona;
} Voluntario;

const char *NOMBRES_ZONAS[TOTAL_ZONAS + 1] = {
    "Zona sin asignar",
    "Parque Bicentenario",
    "Cerro del Aguila",
    "Rio Chiquito"
};

void mostrarEncabezado(void);
void pausar(void);
void registrarVoluntario(Voluntario lista[], int *total);
void asignarZona(Voluntario lista[], int total);
void reporteAsignacion(const Voluntario lista[], int total);

int main(void) {
    Voluntario listaVoluntarios[MAX_VOLUNTARIOS];
    int totalVoluntarios = 0;
    int opcion = 0;

    do {
        system("cls");
        mostrarEncabezado();
        printf("1. Registrar voluntario\n");
        printf("2. Asignar zona de reforestacion\n");
        printf("3. Reporte de asignacion por zonas\n");
        printf("4. Salir\n");
        printf("----------------------------------------------------------------------\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                registrarVoluntario(listaVoluntarios, &totalVoluntarios);
                break;
            case 2:
                asignarZona(listaVoluntarios, totalVoluntarios);
                break;
            case 3:
                reporteAsignacion(listaVoluntarios, totalVoluntarios);
                break;
            case 4:
                system("cls");
                mostrarEncabezado();
                printf("Gracias por utilizar el Sistema\n");
                printf("de Registro para Reforestacion.\n");
                printf("======================================================================\n\n");
                pausar();
                break;
            default:
                break;
        }
    } while (opcion != 4);

    return 0;
}

void mostrarEncabezado(void) {
    printf("======================================================================\n");
    printf(" Estudiante: Tania Guadalupe Murcia Rojas\n");
    printf(" Matricula: TuMatriculaAqui\n");
    printf(" Grupo: DS-DFPR-2602-B1-009\n");
    printf("======================================================================\n");
    printf(" SISTEMA DE REGISTRO PARA REFORESTACION\n");
    printf("======================================================================\n");
}

void pausar(void) {
    printf("Presione ENTER para continuar...");
    getchar();
}

void registrarVoluntario(Voluntario lista[], int *total) {
    system("cls");
    printf("======================================================================\n");
    printf(" 1. REGISTRAR VOLUNTARIO\n");
    printf("======================================================================\n");

    if (*total >= MAX_VOLUNTARIOS) {
        printf("ERROR: Se ha alcanzado el limite maximo de voluntarios (%d).\n\n", MAX_VOLUNTARIOS);
        pausar();
        return;
    }

    Voluntario v;
    v.id = *total + 1;
    v.zona = 0;

    printf("Id asignado: %d\n", v.id);
    
    printf("Ingresa el nombre: ");
    fgets(v.nombre, sizeof(v.nombre), stdin);
    v.nombre[strcspn(v.nombre, "\n")] = 0;

    printf("Ingresa el apellido paterno: ");
    fgets(v.apellido, sizeof(v.apellido), stdin);
    v.apellido[strcspn(v.apellido, "\n")] = 0;

    do {
        printf("Ingresa la edad (mayor de 15 años): ");
        if (scanf("%d", &v.edad) != 1) {
            while (getchar() != '\n');
            v.edad = -1;
            continue;
        }
        while (getchar() != '\n');

        if (v.edad < EDAD_MINIMA) {
            printf("\nERROR: La edad minima permitida es %d años.\n", EDAD_MINIMA);
        }
    } while (v.edad < EDAD_MINIMA);

    lista[*total] = v;
    (*total)++;

    printf("----------------------------------------------------------------------\n");
    printf("Voluntario registrado correctamente\n");
    printf("----------------------------------------------------------------------\n\n");
    pausar();
}

void asignarZona(Voluntario lista[], int total) {
    system("cls");
    printf("======================================================================\n");
    printf(" 2. ASIGNAR ZONA DE REFORESTACION\n");
    printf("======================================================================\n");

    if (total == 0) {
        printf("No hay voluntarios registrados.\n\n");
        pausar();
        return;
    }

    int idBuscado = 0;
    printf("Ingrese el identificador del voluntario: ");
    if (scanf("%d", &idBuscado) != 1) {
        while (getchar() != '\n');
    } else {
        while (getchar() != '\n');
    }

    int indice = -1;
    for (int i = 0; i < total; i++) {
        if (lista[i].id == idBuscado) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nNo se encontro el voluntario.\n\n");
        pausar();
        return;
    }

    printf("\nDatos del voluntario\n");
    printf("----------------------------------------------------------------------\n");
    printf(" Id: %d - %s %s\t%d años - Zona: %s\n",
           lista[indice].id, lista[indice].nombre, lista[indice].apellido,
           lista[indice].edad, NOMBRES_ZONAS[lista[indice].zona]);
    printf("----------------------------------------------------------------------\n");

    printf("Seleccione una zona\n");
    for (int i = 1; i <= TOTAL_ZONAS; i++) {
        printf("%d - %s\n", i, NOMBRES_ZONAS[i]);
    }
    printf("\nOpcion: ");

    int opcionZona = 0;
    if (scanf("%d", &opcionZona) != 1) {
        while (getchar() != '\n');
        opcionZona = 0;
    } else {
        while (getchar() != '\n');
    }

    if (opcionZona < 1 || opcionZona > TOTAL_ZONAS) {
        printf("\nOpcion de zona invalida.\n\n");
        pausar();
        return;
    }

    int asignadosEnZona = 0;
    for (int i = 0; i < total; i++) {
        if (lista[i].zona == opcionZona) {
            asignadosEnZona++;
        }
    }

    if (asignadosEnZona >= MAX_POR_ZONA) {
        printf("ZONA SIN CUPO\n\n");
        pausar();
        return;
    }

    lista[indice].zona = opcionZona;
    printf("ASIGNACION EXITOSA\n");
    printf(" Id: %d - %s %s\t%d años - Zona: %s\n",
           lista[indice].id, lista[indice].nombre, lista[indice].apellido,
           lista[indice].edad, NOMBRES_ZONAS[lista[indice].zona]);
    printf("----------------------------------------------------------------------\n\n");
    pausar();
}

void reporteAsignacion(const Voluntario lista[], int total) {
    system("cls");
    printf("======================================================================\n");
    printf(" 3. REPORTE DE ASIGNACION POR ZONAS\n");
    printf("======================================================================\n");

    for (int z = 1; z <= TOTAL_ZONAS; z++) {
        int conteo = 0;
        for (int i = 0; i < total; i++) {
            if (lista[i].zona == z) {
                conteo++;
            }
        }

        printf("%d - %s: total asignado: %d\n", z, NOMBRES_ZONAS[z], conteo);


        for (int i = 0; i < total; i++) {
            if (lista[i].zona == z) {
                printf("  Id: %d - %s %s\t%d años\tZona: %s\n",
                       lista[i].id, lista[i].nombre, lista[i].apellido,
                       lista[i].edad, NOMBRES_ZONAS[z]);
            }
        }
        printf("\n");
    }

    pausar();
}