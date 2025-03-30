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

// Função para comparar cartas
void compararCartas(Carta carta1, Carta carta2, int escolha) {
    switch (escolha) {
        case 1: // População
            if (carta1.populacao > carta2.populacao) {
                printf("A carta vencedora é: %s (População: %d)\n", carta1.nome, carta1.populacao);
            } else if (carta1.populacao < carta2.populacao) {
                printf("A carta vencedora é: %s (População: %d)\n", carta2.nome, carta2.populacao);
            } else {
                printf("As cartas têm a mesma população.\n");
            }
            break;
        case 2: // Área
            if (carta1.area > carta2.area) {
                printf("A carta vencedora é: %s (Área: %.2f km²)\n", carta1.nome, carta1.area);
            } else if (carta1.area < carta2.area) {
                printf("A carta vencedora é: %s (Área: %.2f km²)\n", carta2.nome, carta2.area);
            } else {
                printf("As cartas têm a mesma área.\n");
            }
            break;
        case 3: // PIB
            if (carta1.pib > carta2.pib) {
                printf("A carta vencedora é: %s (PIB: %.2f milhões)\n", carta1.nome, carta1.pib);
            } else if (carta1.pib < carta2.pib) {
                printf("A carta vencedora é: %s (PIB: %.2f milhões)\n", carta2.nome, carta2.pib);
            } else {
                printf("As cartas têm o mesmo PIB.\n");
            }
            break;
        case 4: // Pontos turísticos
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("A carta vencedora é: %s (Pontos Turísticos: %d)\n", carta1.nome, carta1.pontos_turisticos);
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                printf("A carta vencedora é: %s (Pontos Turísticos: %d)\n", carta2.nome, carta2.pontos_turisticos);
            } else {
                printf("As cartas têm o mesmo número de pontos turísticos.\n");
            }
            break;
        case 5: // Densidade populacional (menor vence)
            {
                float densidade1 = carta1.populacao / carta1.area;
                float densidade2 = carta2.populacao / carta2.area;
                if (densidade1 < densidade2) {
                    printf("A carta vencedora é: %s (Densidade Populacional: %.2f hab/km²)\n", carta1.nome, densidade1);
                } else if (densidade1 > densidade2) {
                    printf("A carta vencedora é: %s (Densidade Populacional: %.2f hab/km²)\n", carta2.nome, densidade2);
                } else {
                    printf("As cartas têm a mesma densidade populacional.\n");
                }
            }
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int escolha;

    // Cadastro da primeira carta
    printf("Informe os dados da primeira carta:\n");
    printf("Estado (2 letras): ");
    scanf("%2s", carta1.estado);

    printf("Código da carta: ");
    scanf("%d", &carta1.codigo);

    printf("Nome da cidade: ");
    fflush(stdin); // Limpa buffer antes de ler a string completa
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
    printf("Estado (2 letras): ");
    scanf("%2s", carta2.estado);

    printf("Código da carta: ");
    scanf("%d", &carta2.codigo);

    printf("Nome da cidade: ");
    fflush(stdin);
    scanf(" %[^\n]", carta2.nome);

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em milhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Exibir menu interativo
    do {
        printf("\nEscolha a propriedade para comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n0 - Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        if (escolha != 0) {
            compararCartas(carta1, carta2, escolha);
        }
    } while (escolha != 0);

    printf("Programa encerrado.\n");
    return 0;
}
