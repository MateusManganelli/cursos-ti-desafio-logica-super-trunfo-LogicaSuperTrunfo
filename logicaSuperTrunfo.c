#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta de uma cidade
typedef struct {
    char estado[3];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void compararCartas(Carta carta1, Carta carta2, int escolha) {
    if (escolha == 1) { // Comparar população
        if (carta1.populacao > carta2.populacao) {
            printf("A carta vencedora é: %s\n", carta1.nome);
        } else if (carta1.populacao < carta2.populacao) {
            printf("A carta vencedora é: %s\n", carta2.nome);
        } else {
            printf("As cartas têm a mesma população.\n");
        }
    } else if (escolha == 2) { // Comparar área
        if (carta1.area > carta2.area) {
            printf("A carta vencedora é: %s\n", carta1.nome);
        } else if (carta1.area < carta2.area) {
            printf("A carta vencedora é: %s\n", carta2.nome);
        } else {
            printf("As cartas têm a mesma área.\n");
        }
    } else if (escolha == 3) { // Comparar PIB
        if (carta1.pib > carta2.pib) {
            printf("A carta vencedora é: %s\n", carta1.nome);
        } else if (carta1.pib < carta2.pib) {
            printf("A carta vencedora é: %s\n", carta2.nome);
        } else {
            printf("As cartas têm o mesmo PIB.\n");
        }
    } else if (escolha == 4) { // Comparar pontos turísticos
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
            printf("A carta vencedora é: %s\n", carta1.nome);
        } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
            printf("A carta vencedora é: %s\n", carta2.nome);
        } else {
            printf("As cartas têm o mesmo número de pontos turísticos.\n");
        }
    } else { // Comparar densidade populacional (menor vence)
        float densidade1 = (float)carta1.populacao / carta1.area;
        float densidade2 = (float)carta2.populacao / carta2.area;
        if (densidade1 < densidade2) {
            printf("A carta vencedora é: %s\n", carta1.nome);
        } else if (densidade1 > densidade2) {
            printf("A carta vencedora é: %s\n", carta2.nome);
        } else {
            printf("As cartas têm a mesma densidade populacional.\n");
        }
    }
}

int main() {
    Carta carta1, carta2;
    int escolha;

    // Cadastro da primeira carta
    printf("Informe os dados da primeira carta:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código da carta: ");
    scanf("%d", &carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em milhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da segunda carta
    printf("\nInforme os dados da segunda carta:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código da carta: ");
    scanf("%d", &carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em milhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Escolha da propriedade para comparação
    printf("\nEscolha a propriedade para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
    scanf("%d", &escolha);

    // Comparar as cartas
    compararCartas(carta1, carta2, escolha);

    return 0;
}
