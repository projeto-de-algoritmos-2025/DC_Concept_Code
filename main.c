#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long power_of_10(int exp) {
    long long resultado = 1;
    for (int i = 0; i < exp; i++) {
        resultado *= 10;
    }
    return resultado;
}

int main() {
    system("cls");
    printf("=====================================\n");
    printf("     Calculadora Karatsuba     \n");
    printf("=====================================\n\n");

    char x_original[100], y_original[100];

    printf(" Insira o primeiro numero: ");
    scanf("%s", x_original);
    printf(" Insira o segundo numero: ");
    scanf("%s", y_original);

    printf("\n--- Etapa de Preparacao ---\n\n");

    int len_x = strlen(x_original);
    int len_y = strlen(y_original);
    
    int n_max = (len_x > len_y) ? len_x : len_y;
    int n = (n_max % 2 != 0) ? n_max + 1 : n_max;

    char* x_str = (char*)calloc(n + 1, sizeof(char));
    char* y_str = (char*)calloc(n + 1, sizeof(char));

    sprintf(x_str, "%0*s", n, x_original);
    sprintf(y_str, "%0*s", n, y_original);
    
    printf(" Para o calculo, os numeros foram padronizados para %d digitos:\n", n);
    printf(" x = %s\n", x_str);
    printf(" y = %s\n\n", y_str);
    
    return 0;
}
