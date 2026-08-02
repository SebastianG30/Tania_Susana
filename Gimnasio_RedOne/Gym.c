#include <stdio.h>

//INICIO DEL PROGRAMA
int main() {
    
    char matricula[] = "ES261115882";
    char nombre[] = "Tania Guadalupe Murcia Rojas";
    char grupo[] = "Fundamentos de Programación-DFPR";

    const int CLAVE_CORRECTA = 1234;
    int claveIngresada;
    int accesoConcedido = 0;

    printf("Matricula: %s\n", matricula);
    printf("Nombre: %s\n", nombre);
    printf("Grupo: %s\n\n", grupo);

    printf("========================================");
    printf("\n       GIMNASIO REDONE - ACCESO\n");
    printf("========================================\n\n");

    for (int intento = 1; intento <= 3; intento++) {
        printf("Ingrese su clave de acceso (4 digitos): ");
        scanf("%d", &claveIngresada);

        if (claveIngresada == CLAVE_CORRECTA) {
            accesoConcedido = 1;
            break;
        } else {
            printf("Clave incorrecta. Intento %d de 3.\n\n", intento);
        }
    }

    if (accesoConcedido) {
        printf("\nAcceso concedido. Bienvenido a Gimnasio RedOne, disfruta tu entrenamiento.\n");
    } else {
        printf("\nAcceso denegado. Has agotado tus 3 intentos.\n");
        printf("Por favor, acude a recepcion para verificar tu clave.\n");
    }

    return 0;
}
// FIN DEL PROGRAMA