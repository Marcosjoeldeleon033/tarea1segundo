#include <stdio.h>

//https://github.com/Marcosjoeldeleon033/tarea1segundo

char personas[4] = {'A', 'B', 'C', 'D'};

int votos[5][4] = {
    {194, 48, 206, 45},
    {180, 20, 320, 16},
    {221, 90, 140, 20},
    {432, 50, 821, 14},
    {820, 61, 946, 18}
};


void imprime() {
    printf("Seccion\tA\tB\tC\tD\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%d\t", votos[i][j]);
        }
        printf("\n");
    }
}

void calcular(int *totales, int *totalGeneral) {
    for (int i = 0; i < 4; i++) totales[i] = 0; 
    *totalGeneral = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            totales[j] += votos[i][j];
            *totalGeneral += votos[i][j];
        }
    }
}

void ganador(int *totales, int totalGeneral) {
    int max1 = -1, max2 = -1; 
    float porcentaje;
    
    for (int i = 0; i < 4; i++) {
        porcentaje = (totales[i] * 100.0) / totalGeneral;
        if (max1 == -1 || totales[i] > totales[max1]) {
            max2 = max1;
            max1 = i;
        } else if (max2 == -1 || totales[i] > totales[max2]) {
            max2 = i;
        }

        printf("Candidato %c: %d votos (%.2f%%)\n", personas[i], totales[i], porcentaje);
    }
    
    porcentaje = (totales[max1] * 100.0) / totalGeneral;
    if (porcentaje > 50.0) {
        printf("El ganador es el candidato %c con %.2f%% de los votos.\n", personas[max1], porcentaje);
    } else {
        printf("Segunda ronda entre los candidatos %c y %c.\n", personas[max1], personas[max2]);
    }
}

int main() {
    int totales[4], totalGeneral;    
    imprime();    
    calcular(totales, &totalGeneral);
    printf("\nTotal de votos emitidos: %d\n", totalGeneral);    
    ganador(totales, totalGeneral);
    return 0;
}
