#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 3

typedef struct {
    int matricula;
    char nombre[50];
    float calificacion1;
    float calificacion2;
    float calificacion3;
    float promedio;
} Estudiante;

void mostrarEncabezado(void);
void mostrarMenu(void);
void capturarDatos(Estudiante lista[], int *datosCapturados);
void mostrarTodos(const Estudiante lista[], int datosCapturados);
void mostrarAprobados(const Estudiante lista[], int datosCapturados);
void mostrarEnRiesgo(const Estudiante lista[], int datosCapturados);
void mostrarReprobados(const Estudiante lista[], int datosCapturados);

int main(void) {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int datosCapturados = 0;
    int opcion = 0;

    mostrarEncabezado();
    do {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1:
                capturarDatos(estudiantes, &datosCapturados);
                break;
            case 2:
                mostrarTodos(estudiantes, datosCapturados);
                break;
            case 3:
                mostrarAprobados(estudiantes, datosCapturados);
                break;
            case 4:
                mostrarEnRiesgo(estudiantes, datosCapturados);
                break;
            case 5:
                mostrarReprobados(estudiantes, datosCapturados);
                break;
            case 6:
                printf("\nGracias por utilizar el Sistema de Captura de Calificaciones\n");
                break;
            default:
                printf("\nOpción no válida. Intentelo de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}

void mostrarEncabezado(void) {
    printf("Sistema de Captura de Calificaciones\n");
    printf("Unidad didactica: Fundamentos de Programacion\n");
    printf("Nombre del Estudiante: Sebastián García Trejo\n");
    printf("Matricula: TuMatriculaAqui\n");
    printf("Grupo: DS-DFPR-2602-B1-011\n\n");
}

void mostrarMenu(void) {
    printf("**************************************************\n");
    printf("         MENU DE SISTEMA DE REGISTRO\n");
    printf("**************************************************\n");
    printf("1. Capturar datos\n");
    printf("2. Mostrar todos los estudiantes\n");
    printf("3. Estudiantes aprobados\n");
    printf("4. En riesgo de reprobar\n");
    printf("5. Estudiantes reprobados\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
}

void capturarDatos(Estudiante lista[], int *datosCapturados) {
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        printf("\nEstudiante %d\n", i + 1);
        
        printf("Matricula: ");
        scanf("%d", &lista[i].matricula);
        
        while (getchar() != '\n');
        
        printf("Nombre: ");
        fgets(lista[i].nombre, sizeof(lista[i].nombre), stdin);
        lista[i].nombre[strcspn(lista[i].nombre, "\n")] = '\0';

        printf("Calificacion 1: ");
        scanf("%f", &lista[i].calificacion1);
        
        printf("Calificacion 2: ");
        scanf("%f", &lista[i].calificacion2);
        
        printf("Calificacion 3: ");
        scanf("%f", &lista[i].calificacion3);

        lista[i].promedio = (lista[i].calificacion1 + lista[i].calificacion2 + lista[i].calificacion3) / 3.0f;
    }
    *datosCapturados = 1;
    printf("\n¡Datos capturados exitosamente!\n");
}

void mostrarTodos(const Estudiante lista[], int datosCapturados) {
    if (!datosCapturados) {
        printf("\nPrimero debe capturar los datos (Opcion 1).\n");
        return;
    }

    printf("\n***** TODOS LOS ESTUDIANTES *****\n");
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        printf("\nMatricula: %d\n", lista[i].matricula);
        printf("Nombre: %s\n", lista[i].nombre);
        printf("Promedio: %.2f\n", lista[i].promedio);
    }
}

void mostrarAprobados(const Estudiante lista[], int datosCapturados) {
    if (!datosCapturados) {
        printf("\nPrimero debe capturar los datos (Opcion 1).\n");
        return;
    }

    printf("\n***** ESTUDIANTES APROBADOS *****\n");
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        if (lista[i].promedio >= 6.0f) {
            printf("\nMatricula: %d\n", lista[i].matricula);
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Promedio: %.2f\n", lista[i].promedio);
        }
    }
}

void mostrarEnRiesgo(const Estudiante lista[], int datosCapturados) {
    if (!datosCapturados) {
        printf("\nPrimero debe capturar los datos (Opcion 1).\n");
        return;
    }

    printf("\n***** ESTUDIANTES EN RIESGO *****\n");
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        if (lista[i].promedio >= 6.0f && lista[i].promedio < 7.0f) {
            printf("\nMatricula: %d\n", lista[i].matricula);
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Promedio: %.2f\n", lista[i].promedio);
        }
    }
}

void mostrarReprobados(const Estudiante lista[], int datosCapturados) {
    if (!datosCapturados) {
        printf("\nPrimero debe capturar los datos (Opcion 1).\n");
        return;
    }

    printf("\n***** ESTUDIANTES REPROBADOS *****\n");
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        if (lista[i].promedio < 6.0f) {
            printf("\nMatricula: %d\n", lista[i].matricula);
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Promedio: %.2f\n", lista[i].promedio);
        }
    }
}