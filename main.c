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

    printf("--- Desenvolvimento Karatsuba ---\n\n");

    int meio = n / 2;

    char a_str[50], b_str[50];
    char c_str[50], d_str[50];

    strncpy(a_str, x_str, meio); a_str[meio] = '\0';
    strncpy(b_str, x_str + meio, meio); b_str[meio] = '\0';
    strncpy(c_str, y_str, meio); c_str[meio] = '\0';
    strncpy(d_str, y_str + meio, meio); d_str[meio] = '\0';

    long long a = atoll(a_str);
    long long b = atoll(b_str);
    long long c = atoll(c_str);
    long long d = atoll(d_str);

    printf(" Divisao: n=%d  meio=%d:\n\n", n, meio);
    printf(" a = %-10lld b = %lld\n", a, b);
    printf(" c = %-10lld d = %lld\n\n", c, d);

    long long p1 = a * c;
    long long p2 = b * d;
    long long p3 = (a + b) * (c + d);
    long long p4 = p3 - p1 - p2;

    printf("--- Calculos Intermediarios ---\n");
    printf("p1 = a * c          = %lld\n", p1);
    printf("p2 = b * d          = %lld\n", p2);
    printf("p3 = (a+b)*(c+d)    = %lld\n", p3);
    printf("p4 = p3 - p1 - p2   = %lld\n\n", p4);

    long long termo1 = p1 * power_of_10(n);
    long long termo2 = p4 * power_of_10(meio);
    long long resultado = termo1 + termo2 + p2;

    printf("--- Combinacao Final (p1 * 10^%d + p4 * 10^%d + p2) ---\n\n", n, meio);
    printf("= %lld * %lld + %lld * %lld + %lld\n", p1, power_of_10(n), p4, power_of_10(meio), p2);
    printf("= %lld + %lld + %lld\n", termo1, termo2, p2);

    printf("\n----------------------------------------------------------\n");
    printf("Resultado Karatsuba: %lld\n", resultado);

    long long verificacao = atoll(x_original) * atoll(y_original);
    printf("Verificacao Direta : %lld\n", verificacao);
    
    if (resultado == verificacao) {
        printf("\nO resultado esta CORRETO.\n");
    } else {
        printf("\nATENCAO: O resultado esta INCORRETO.\n");
    }
    printf("----------------------------------------------------------\n");

    free(x_str);
    free(y_str);

    return 0;
}
