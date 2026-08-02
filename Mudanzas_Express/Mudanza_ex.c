#include <stdio.h>
#include <ctype.h>

//INICIO DEL PROGRAMA
int main() {
    char nombreEstudiante[] = "Tania Guadalupe Murcia Rojas";
    char matricula[] = "ES261115882";
    char grupo[] = "Fundamentos de Programación-DFPR";

    int numeroServicio = 0;
    int cantEstudiantes = 0;
    int cantProfesores = 0;
    int cantPublicoGeneral = 0;
    float totalRecaudadoNeto = 0.0;
    float mayorCotizacion = 0.0;
    float menorCotizacion = 0.0;

    char opcion;

    printf("=== BIENVENIDO A MUDANZAS EXPRESS ===\n\n");
    printf("Unidad didactica: Fundamentos de programacion\n\n");
    printf("Nombre del estudiante: %s\n\n", nombreEstudiante);
    printf("Matricula: %s\n\n", matricula);
    printf("Grupo: %s\n\n", grupo);

    do {
        numeroServicio++;
        float distancia = 0.0;
        int tipoCliente = 0;
        int numeroMaletas = 0;

        printf("--- Registro de Servicio #%d ---\n", numeroServicio);
        do {
            printf("Distancia del viaje en km (mayor a 0): ");
            scanf("%f", &distancia);
            if (distancia <= 0) {
                printf("Error: La distancia debe ser un valor positivo mayor a 0.\n");
            }
        } while (distancia <= 0);

        do {
            printf("Tipo de cliente (1: Estudiante, 2: Profesor, 3: Publico General): ");
            scanf("%d", &tipoCliente);
            if (tipoCliente < 1 || tipoCliente > 3) {
                printf("Error: Tipo de cliente invalido. Ingrese 1, 2 o 3.\n");
            }
        } while (tipoCliente < 1 || tipoCliente > 3);

        do {
            printf("Numero de maletas a trasladar (no puede ser negativo): ");
            scanf("%d", &numeroMaletas);
            if (numeroMaletas <= 0) {
                printf("Error: El numero de maletas debe ser mayor a 0.\n");
            }
        } while (numeroMaletas <= 0);

        float subtotalMaletas = numeroMaletas * 150.0;
        float costoTrayecto = distancia * 500.0;
        float totalBase = subtotalMaletas + costoTrayecto;

        float porcentajeDescuento = 0.0;
        if (tipoCliente == 1) {
            porcentajeDescuento = 0.20; // 20%
            cantEstudiantes++;
        } else if (tipoCliente == 2) {
            porcentajeDescuento = 0.10; // 10%
            cantProfesores++;
        } else if (tipoCliente == 3) {
            porcentajeDescuento = 0.0;  // Sin ningun descuento
            cantPublicoGeneral++;
        }

        float descuentoAplicado = totalBase * porcentajeDescuento;
        float totalNeto = totalBase - descuentoAplicado;

        printf("\n--- Resumen de Cotizacion ---\n");
        printf("Subtotal maletas (%d x $150.00): $%.2f\n", numeroMaletas, subtotalMaletas);
        printf("Costo por trayecto (distancia x $500): $%.2f\n", costoTrayecto);
        printf("Total base antes de descuento: $%.2f\n", totalBase);
        printf("Descuento aplicado (%.0f%%): $%.2f\n", porcentajeDescuento * 100, descuentoAplicado);
        printf("Total NETO a pagar: $%.2f\n", totalNeto);
        printf("-----------------------------------------\n");
        totalRecaudadoNeto += totalNeto;

        if (numeroServicio == 1) {
            mayorCotizacion = totalNeto;
            menorCotizacion = totalNeto;
        } else {
            if (totalNeto > mayorCotizacion) {
                mayorCotizacion = totalNeto;
            }
            if (totalNeto < menorCotizacion) {
                menorCotizacion = totalNeto;
            }
        }

        printf("\n¿Desea registrar otro servicio de mudanza? (S/N): ");
        scanf(" %c", &opcion);
        opcion = toupper(opcion);
        printf("\n");

    } while (opcion == 'S');

    float promedioGasto = totalRecaudadoNeto / numeroServicio;

    printf("=========================================\n");
    printf("     REPORTE FINAL - MUDANZAS EXPRESS    \n");
    printf("=========================================\n");
    printf("Total de servicios realizados: %d\n", numeroServicio);
    printf("Cantidad de clientes Estudiantes: %d\n", cantEstudiantes);
    printf("Cantidad de clientes Profesores: %d\n", cantProfesores);
    printf("Cantidad de clientes Publico General: %d\n", cantPublicoGeneral);
    printf("-----------------------------------------\n");
    printf("Total recaudado neto: $%.2f\n", totalRecaudadoNeto);
    printf("Promedio de gasto por servicio: $%.2f\n", promedioGasto);
    printf("Mayor cotizacion realizada: $%.2f\n", mayorCotizacion);
    printf("Menor cotizacion realizada: $%.2f\n", menorCotizacion);
    printf("=========================================\n");

    return 0;
}
//FIN DEL PROGRAMA