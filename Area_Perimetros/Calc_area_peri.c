#include <stdio.h>

#define PI 3.14159265358979323846
//INICIO DEL PROGRAMA
int main() {

    printf("Calculadora de áreas y perímetros\n\n");
    printf("Unidad didáctica: Fundamentos de Programación\n");
    printf("Nombre del Estudiante: Tania Guadalupe Murcia Rojas\n");
    printf("Matrícula: ES261115882\n");
    printf("Grupo: DS-DFPR-2602-B1-011\n\n");

    printf("====== CALCULADORA DE AREAS Y PERÍMETROS ======\n");

    float lado, base, altura, lado2, lado3;
    float radio, diag_mayor, diag_menor;
    float area, perimetro;

    printf("1. Cuadrado\n");
    printf("Ingrese el lado: ");
    scanf("%f", &lado);

    area = lado * lado;
    perimetro = 4 * lado;

    printf("Área del cuadrado = %.2f\n", area);
    printf("Perímetro del cuadrado = %.2f\n\n", perimetro);

    printf("2. Triángulo\n");
    printf("Ingrese la base (lado 1): ");
    scanf("%f", &base);
    printf("Ingrese la altura: ");
    scanf("%f", &altura);

    area = (base * altura) / 2.0;
    printf("Área del triángulo = %.2f\n", area);

    printf("Para calcular el perímetro del triángulo\n");
    printf("Ingrese el lado 2: ");
    scanf("%f", &lado2);
    printf("Ingrese el lado 3: ");
    scanf("%f", &lado3);

    perimetro = base + lado2 + lado3;
    printf("Perímetro del triángulo = %.2f\n\n", perimetro);

    printf("3. Círculo\n");
    printf("Ingrese el radio: ");
    scanf("%f", &radio);

    area = PI * radio * radio;
    perimetro = 2 * PI * radio;

    printf("Área del circulo = %.2f\n", area);
    printf("Perímetro del circulo = %.2f\n\n", perimetro);

    printf("4. Rombo\n");
    printf("Ingrese la diagonal mayor: ");
    scanf("%f", &diag_mayor);
    printf("Ingrese la diagonal menor: ");
    scanf("%f", &diag_menor);

    area = (diag_mayor * diag_menor) / 2.0;
    printf("Área del rombo = %.2f\n", area);

    printf("Para calcular el perímetro del rombo\n");
    printf("Ingrese el valor de un lado: ");
    scanf("%f", &lado);

    perimetro = 4 * lado;
    printf("Perímetro del rombo = %.2f\n", perimetro);

    return 0;
}
//FIN DEL PROGRAMA