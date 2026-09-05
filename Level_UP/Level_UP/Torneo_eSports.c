#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_JUGADORES 4
#define MAX_GAMERTAG 16  
#define MAX_NOMBRE   100
#define MAX_VIDEOJUEGO 20
#define MAX_TELEFONO 11  

typedef struct {
    int  id;
    char gamertag[MAX_GAMERTAG];
    char nombre[MAX_NOMBRE];
    int  edad;
    char videojuego[MAX_VIDEOJUEGO];
    char telefono[MAX_TELEFONO];
    int  activo;
} Jugador;

Jugador jugadores[MAX_JUGADORES];
int totalRegistrados = 0;  
int siguienteID = 1; 

void mostrarDatosEstudiante(void);
void mostrarMenu(void);
void limpiarBufferEntrada(void);
void registrarJugador(void);
void buscarJugador(void);
void eliminarJugador(void);
int  leerEntero(const char *mensaje);
int  validarSoloDigitos(const char *cadena);

int main(void) {
    int opcion;

    mostrarDatosEstudiante();

    do {
        mostrarMenu();
        opcion = leerEntero("Seleccione una opcion (1-4): ");

        switch (opcion) {
            case 1:
                registrarJugador();
                break;
            case 2:
                buscarJugador();
                break;
            case 3:
                eliminarJugador();
                break;
            case 4:
                printf("\n****************************************\n");
                printf("           SALIENDO DEL SISTEMA\n");
                printf("******************************************\n");
                printf("Gracias por usar el sistema de registro de\n");
                printf("Level Up Arena. Nos vemos en la arena!\n");
                break;
            default:
                printf("\nOpcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}

void mostrarDatosEstudiante(void) {
    printf("******************************************\n");
    printf("           DATOS DEL ESTUDIANTE\n");
    printf("******************************************\n");
    printf("Nombre completo: \n");
    printf("Matricula: \n");  //PON AQUI TAMBIEN TUS DATOS POR FIS :)
    printf("Grupo: \n");
    printf("******************************************\n\n");
}

void mostrarMenu(void) {
    printf("\n******************************************\n");
    printf("               MENU PRINCIPAL\n");
    printf("********************************************\n");
    printf("1. Registro de jugadores\n");
    printf("2. Buscar jugador\n");
    printf("3. Eliminar jugador\n");
    printf("4. Salir\n");
    printf("*******************************************\n");
}

void limpiarBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int leerEntero(const char *mensaje) {
    int valor;
    printf("%s", mensaje);
    while (scanf("%d", &valor) != 1) {
        printf("Entrada invalida. Ingrese un numero: ");
        limpiarBufferEntrada();
    }
    limpiarBufferEntrada();
    return valor;
}

int validarSoloDigitos(const char *cadena) {
    if (strlen(cadena) == 0) return 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isdigit((unsigned char)cadena[i])) {
            return 0;
        }
    }
    return 1;
}

void registrarJugador(void) {
    if (totalRegistrados >= MAX_JUGADORES) {
        printf("\n******************************************\n");
        printf("   NO SE PUEDE REGISTRAR MAS JUGADORES\n");
        printf("********************************************\n");
        printf("El torneo ya alcanzo el limite de %d jugadores.\n", MAX_JUGADORES);
        return;
    }

    int indiceLibre = -1;
    for (int i = 0; i < MAX_JUGADORES; i++) {
        if (jugadores[i].activo == 0) {
            indiceLibre = i;
            break;
        }
    }

    if (indiceLibre == -1) {
        printf("\nNo hay espacios disponibles.\n");
        return;
    }

    Jugador nuevo;
    nuevo.activo = 1;
    nuevo.id = siguienteID;

    printf("\n******************************************\n");
    printf("         REGISTRO DE NUEVO JUGADOR\n");
    printf("********************************************\n");
    printf("ID asignado: %d\n", nuevo.id);

    char bufferGamertag[100];
    do {
        printf("Gamertag (max. 15 caracteres): ");
        fgets(bufferGamertag, sizeof(bufferGamertag), stdin);
        bufferGamertag[strcspn(bufferGamertag, "\n")] = '\0';
        if (strlen(bufferGamertag) == 0 || strlen(bufferGamertag) > 15) {
            printf("Error: el gamertag debe tener entre 1 y 15 caracteres.\n");
        }

    } while (strlen(bufferGamertag) == 0 || strlen(bufferGamertag) > 15);
    strcpy(nuevo.gamertag, bufferGamertag);

    printf("Nombre completo: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

    int edad;
    do {
        edad = leerEntero("Edad (12 en adelante): ");
        if (edad < 12) {
            printf("Error: la edad debe ser 12 o mayor.\n");
        }

    } while (edad < 12);
    nuevo.edad = edad;

    int opcionVideojuego;
    do {
        opcionVideojuego = leerEntero(
            "Videojuego (1.FreeFire 2.FIFA 3.Valorant 4.Otro): ");
        if (opcionVideojuego < 1 || opcionVideojuego > 4) {
            printf("Error: seleccione una opcion entre 1 y 4.\n");
        }

    } while (opcionVideojuego < 1 || opcionVideojuego > 4);

    switch (opcionVideojuego) {
        case 1: strcpy(nuevo.videojuego, "FREE FIRE"); break;
        case 2: strcpy(nuevo.videojuego, "FIFA");      break;
        case 3: strcpy(nuevo.videojuego, "VALORANT");  break;
        case 4: strcpy(nuevo.videojuego, "OTRO");      break;
    }

    char bufferTelefono[50];
    do {
        printf("Telefono de contacto (10 digitos): ");
        fgets(bufferTelefono, sizeof(bufferTelefono), stdin);
        bufferTelefono[strcspn(bufferTelefono, "\n")] = '\0';
        if (strlen(bufferTelefono) != 10 || !validarSoloDigitos(bufferTelefono)) {
            printf("Error: el telefono debe contener exactamente 10 digitos numericos.\n");
        }
    
    } while (strlen(bufferTelefono) != 10 || !validarSoloDigitos(bufferTelefono));
    strcpy(nuevo.telefono, bufferTelefono);

    jugadores[indiceLibre] = nuevo;
    totalRegistrados++;
    siguienteID++;

    printf("\n******************************************n");
    printf("             REGISTRO EXITOSO\n");
    printf("******************************************\n");
    printf("Jugador registrado con ID: %d\n", nuevo.id);
}

void buscarJugador(void) {
    if (totalRegistrados == 0) {
        printf("\nNo hay jugadores registrados actualmente.\n");
        return;
    }

    printf("\n******************************************\n");
    printf("              BUSCAR JUGADOR\n");
    printf("******************************************\n");
    printf("Criterios de busqueda:\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por gamertag\n");

    int criterio = leerEntero("Seleccione el criterio de busqueda (1-2): ");
    int encontrado = -1;

    if (criterio == 1) {
        int idBuscado = leerEntero("Ingrese el ID: ");
        for (int i = 0; i < MAX_JUGADORES; i++) {
            if (jugadores[i].activo == 1 && jugadores[i].id == idBuscado) {
                encontrado = i;
                break;
            }
        }

    } else if (criterio == 2) {
        char gamertagBuscado[100];
        printf("Ingrese el gamertag: ");
        fgets(gamertagBuscado, sizeof(gamertagBuscado), stdin);
        gamertagBuscado[strcspn(gamertagBuscado, "\n")] = '\0';
        for (int i = 0; i < MAX_JUGADORES; i++) {
            if (jugadores[i].activo == 1 &&
                strcmp(jugadores[i].gamertag, gamertagBuscado) == 0) {
                encontrado = i;
                break;
            }
        }

    } else {
        printf("\nCriterio invalido.\n");
        return;
    }

    if (encontrado == -1) {
        printf("\n******************************************\n");
        printf("        JUGADOR NO ENCONTRADO\n");
        printf("******************************************\n");
        return;
    }

    printf("\n******************************************\n");
    printf("           INFORMACION DEL JUGADOR\n");
    printf("******************************************\n");
    printf("ID: %d\n", jugadores[encontrado].id);
    printf("Gamertag: %s\n", jugadores[encontrado].gamertag);
    printf("Nombre: %s\n", jugadores[encontrado].nombre);
    printf("Edad: %d anios\n", jugadores[encontrado].edad);
    printf("Videojuego: %s\n", jugadores[encontrado].videojuego);
    printf("Telefono: %s\n", jugadores[encontrado].telefono);
    printf("******************************************\n");
}

void eliminarJugador(void) {
    if (totalRegistrados == 0) {
        printf("\nNo hay jugadores registrados actualmente.\n");
        return;
    }

    printf("\n******************************************\n");
    printf("             ELIMINAR JUGADOR\n");
    printf("******************************************\n");
    printf("Eliminar por:\n");
    printf("1. ID\n");
    printf("2. Gamertag\n");

    int criterio = leerEntero("Seleccione opcion (1-2): ");
    int encontrado = -1;

    if (criterio == 1) {
        int idBuscado = leerEntero("Ingrese el ID: ");
        for (int i = 0; i < MAX_JUGADORES; i++) {
            if (jugadores[i].activo == 1 && jugadores[i].id == idBuscado) {
                encontrado = i;
                break;
            }
        }

    } else if (criterio == 2) {
        char gamertagBuscado[100];
        printf("Ingrese el gamertag: ");
        fgets(gamertagBuscado, sizeof(gamertagBuscado), stdin);
        gamertagBuscado[strcspn(gamertagBuscado, "\n")] = '\0';
        for (int i = 0; i < MAX_JUGADORES; i++) {
            if (jugadores[i].activo == 1 &&
                strcmp(jugadores[i].gamertag, gamertagBuscado) == 0) {
                encontrado = i;
                break;
            }
        }

    } else {
        printf("\nCriterio invalido.\n");
        return;
    }

    if (encontrado == -1) {
        printf("\n******************************************\n");
        printf("        JUGADOR NO ENCONTRADO\n");
        printf("******************************************\n");
        return;
    }

    printf("\nJugador encontrado para eliminar:\n");
    printf("ID: %d  Gamertag: %s  Videojuego: %s\n",
           jugadores[encontrado].id,
           jugadores[encontrado].gamertag,
           jugadores[encontrado].videojuego);

    char confirmacion;
    printf("Esta seguro de eliminar este registro? (S/N): ");
    scanf(" %c", &confirmacion);
    limpiarBufferEntrada();

    if (toupper(confirmacion) == 'S') {
        jugadores[encontrado].activo = 0;
        totalRegistrados--;
        printf("\n******************************************\n");
        printf("            ELIMINACION EXITOSA\n");
        printf("******************************************\n");
        printf("Registro eliminado correctamente.\n");
        printf("Total de jugadores restantes: %d\n", totalRegistrados);
    } else {
        printf("\nOperacion cancelada. El registro no fue eliminado.\n");
    }
}