#include <stdio.h>

typedef struct {
    unsigned long int populacao;  // A população da cidade (tipo long int, mas sem números negativos)
    float area;                   // A área da cidade em quilômetros quadrados
    float pib;                    // O PIB da cidade em milhões de unidades monetárias
    int pontos_turisticos;        // O número de pontos turísticos da cidade
    float densidade_populacional; // Densidade populacional (calculado automaticamente)
    float pib_per_capita;         // PIB per capita (calculado automaticamente)
    float super_poder;            // Super Poder (soma de todos os atributos)
} Carta;

float calcular_super_poder(Carta carta) {
    return carta.populacao + carta.area + carta.pib + carta.pontos_turisticos + (1 / carta.densidade_populacional) + carta.pib_per_capita;
}

int comparar_atributos(Carta carta1, Carta carta2) {
    int vitoria_carta1 = 0;
    
    // Comparação dos atributos (com base no maior valor para todos, exceto densidade populacional)
    if (carta1.populacao > carta2.populacao) {
        vitoria_carta1++;
    } else if (carta1.populacao < carta2.populacao) {
        vitoria_carta1--;
    }

    if (carta1.area > carta2.area) {
        vitoria_carta1++;
    } else if (carta1.area < carta2.area) {
        vitoria_carta1--;
    }

    if (carta1.pib > carta2.pib) {
        vitoria_carta1++;
    } else if (carta1.pib < carta2.pib) {
        vitoria_carta1--;
    }

    if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
        vitoria_carta1++;
    } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
        vitoria_carta1--;
    }

    // Para densidade populacional, vence a carta com a menor densidade
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        vitoria_carta1++;
    } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
        vitoria_carta1--;
    }

    // Comparação de Super Poder
    if (carta1.super_poder > carta2.super_poder) {
        vitoria_carta1++;
    } else if (carta1.super_poder < carta2.super_poder) {
        vitoria_carta1--;
    }

    return vitoria_carta1;
}

int main() {
    Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Informe a Populacao: ");
    scanf("%lu", &carta1.populacao);
    printf("Informe a Area: ");
    scanf("%f", &carta1.area);
    printf("Informe o PIB: ");
    scanf("%f", &carta1.pib);
    printf("Informe o Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cálculos automáticos da Carta 1
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta1.super_poder = calcular_super_poder(carta1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Informe a Populacao: ");
    scanf("%lu", &carta2.populacao);
    printf("Informe a Area: ");
    scanf("%f", &carta2.area);
    printf("Informe o PIB: ");
    scanf("%f", &carta2.pib);
    printf("Informe o Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculos automáticos da Carta 2
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;
    carta2.super_poder = calcular_super_poder(carta2);

    // Exibição dos resultados
    printf("\nCarta 1:\n");
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta1.densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta1.pib_per_capita);
    printf("Super Poder: %.2f\n", carta1.super_poder);

    printf("\nCarta 2:\n");
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta2.densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta2.pib_per_capita);
    printf("Super Poder: %.2f\n", carta2.super_poder);

    // Comparação e exibição do vencedor
    int resultado_comparacao = comparar_atributos(carta1, carta2);
    if (resultado_comparacao > 0) {
        printf("\nCarta 1 venceu!\n");
    } else if (resultado_comparacao < 0) {
        printf("\nCarta 2 venceu!\n");
    } else {
        printf("\nAs cartas empataram!\n");
    }

    return 0;
}
