#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 3

void mostrarEncabezado(void);
void mostrarMenuLibros(void);
int obtenerMaxDias(int opcionLibro);
void asignarRecordatorio(int totalLibros, char recordatorio[]);
void capturarPrestamo(void);

int main(void) {
    int opcionPrincipal;

    do {
        mostrarEncabezado();
        printf("MENU PRINCIPAL\n");
        printf("1. Capturar préstamo\n");
        printf("2. Cerrar préstamo\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcionPrincipal);
        getchar();

        switch (opcionPrincipal) {
            case 1:
                capturarPrestamo();
                break;
            case 2:
                printf("\nSaliendo del sistema... Gracias por visitar Biblioteca Lectura Viva, ¡Hasta luego!\n");
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n\n");
        }
    } while (opcionPrincipal != 2);

    return 0;
}

void mostrarEncabezado(void) {
    printf("******************************************\n");
    printf("BIENVENIDO A LECTURA VIVA\n");
    printf("Unidad didáctica: Fundamentos de programación\n");
    printf("Nombre del estudiante: Tania Guadalupe Murcia Rojas\n");
    printf("Matrícula: \n"); //PON TU NUMERO DE MATRICULA QUE NO ME LA SE JEJEJE y REVISA QUE TUS DATOS ESTEN BIEN :)
    printf("Grupo: DS-DEPR-2602-81-005\n");
    printf("****************************************\n\n");
}

void mostrarMenuLibros(void) {
    printf("\nMENU DE LIBROS\n");
    printf("1. Cien años de soledad (max 7 dias)\n");
    printf("2. El Principito (max 5 dias)\n");
    printf("3. Don Quijote (max 10 dias)\n");
    printf("4. Cerrar préstamo\n");
}

int obtenerMaxDias(int opcionLibro) {
    switch (opcionLibro) {
        case 1: return 7;  
        case 2: return 5;  
        case 3: return 10;
        default: return 0;
    }
}

void asignarRecordatorio(int totalLibros, char recordatorio[]) {
    if (totalLibros == 1) {
        strcpy(recordatorio, "Recordatorio por correo.");
    } else if (totalLibros >= 2 && totalLibros <= MAX_LIBROS) {
        strcpy(recordatorio, "Llamada telefónica.");
    } else {
        strcpy(recordatorio, "Sin recordatorio.");
    }
}

void capturarPrestamo(void) {
    char nombreCliente[100];
    char numeroSocio[20];
    char recordatorio[50];
    
    int totalLibros = 0;
    int totalDias = 0;
    int opcionLibro;
    int diasSolicitados;
    int maxDiasPermitidos;

    printf("\n**** CAPTURA DE CLIENTE ****\n");
    printf("Ingrese nombre del cliente: ");
    fgets(nombreCliente, sizeof(nombreCliente), stdin);
    nombreCliente[strcspn(nombreCliente, "\n")] = '\0';

    printf("Ingrese número de socio: ");
    fgets(numeroSocio, sizeof(numeroSocio), stdin);
    numeroSocio[strcspn(numeroSocio, "\n")] = '\0';

    do {
        mostrarMenuLibros();
        printf("Seleccione opción: ");
        scanf("%d", &opcionLibro);

        if (opcionLibro == 4) {
            break; 
        }

        if (opcionLibro < 1 || opcionLibro > 3) {
            printf("Opción inválida. Seleccione una opción del 1 al 4.\n");
            continue;
        }

        if (totalLibros >= MAX_LIBROS) {
            printf("Ya tiene registrados %d libros. No puede agregar mas.\n", MAX_LIBROS);
            continue;
        }

        maxDiasPermitidos = obtenerMaxDias(opcionLibro);
        printf("Ingrese dias de préstamo: ");
        scanf("%d", &diasSolicitados);

        if (diasSolicitados > maxDiasPermitidos || diasSolicitados <= 0) {
            printf("Error: dias exceden el máximo permitido.\n");
        } else {
            totalLibros++;
            totalDias += diasSolicitados;
            printf("Libro %d registrado correctamente. Total de libros: %d\n", totalLibros, totalLibros);
        }

    } while (1);

    if (totalLibros > 0) {
        asignarRecordatorio(totalLibros, recordatorio);

        printf("\n******** RESUMEN DEL PRÉSTAMO ********\n");
        printf("Cliente: %s\n", nombreCliente);
        printf("Número de socio: %s\n", numeroSocio);
        printf("Total de libros: %d\n", totalLibros);
        printf("Total de días de préstamo: %d\n", totalDias);
        printf("Recordatorio: %s\n", recordatorio);
        printf("**************************************\n\n");
    } else {
        printf("\nNo se registraron libros en este préstamo.\n\n");
    }
}
