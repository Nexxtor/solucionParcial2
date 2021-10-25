/**
 * Crea un programa en C, que calcule la temperatura promedio de cada uno de N
 * estudiantes de la UCA, dado sus registros de todo el mes (30).
 * @author Néstor Aldana**/

#include <stdio.h>

#define NUMERO_DIAS_MES 31

struct estudianteTemp {
    char carnet[9];  // 8 + '\0'
    float tempPromedio;
};

int main(int argc, char const *argv[]) {
    int n = 0;  // Cantidad de estudiantes

    printf("Ingrese la cantidad de estudiantes:");
    scanf("%d", &n);

    struct estudianteTemp estudiantes[n];

    for (int i = 0; i < n; i++) {
        printf("Ingrese el carnet:");
        scanf("%s", estudiantes[i].carnet);
        // Solicitando la temperatura del estudiante
        float suma = 0;
        for (int j = 0; j < NUMERO_DIAS_MES; j++) {
            printf("Ingrese temperatura %d:", j + 1);
            float temp = 0;
            scanf("%f", &temp);
            suma += temp;
        }
        estudiantes[i].tempPromedio = suma / NUMERO_DIAS_MES;
    }

    // Mostrar datos

    printf("Carnet\tPromedio\n");
    float suma = 0;
    for (int i = 0; i < n; i++) {
        struct estudianteTemp e = estudiantes[i];
        printf("%s\t%.1f\n", e.carnet, e.tempPromedio);
        suma+= e.tempPromedio;
    }
    printf("Promedio\t%.1f\n", suma / n);

    return 0;
}
