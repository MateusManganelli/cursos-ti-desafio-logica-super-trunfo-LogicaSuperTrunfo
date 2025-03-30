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

// Função para comparar dois atributos simultaneamente
void compararCartas(Carta c1, Carta c2, int escolha1, int escolha2) {
    int pontos_c1 = 0, pontos_c2 = 0;
    
    int atributos[2] = {escolha1, escolha2};
    
    for (int i = 0; i < 2; i++) {
        switch (atributos[i]) {
            case 1:
                (c1.populacao > c2.populacao) ? pontos_c1++ : (c1.populacao < c2.populacao) ? pontos_c2++ : 0;
                break;
            case 2:
                (c1.area > c2.area) ? pontos_c1++ : (c1.area < c2.area) ? pontos_c2++ : 0;
                break;
            case 3:
                (c1.pib > c2.pib) ? pontos_c1++ : (c1.pib < c2.pib) ? pontos_c2++ : 0;
                break;
            case 4:
                (c1.pontos_turisticos > c2.pontos_turisticos) ? pontos_c1++ : (c1.pontos_turisticos < c2.pontos_turisticos) ? pontos_c2++ : 0;
                break;
            case 5: {
                if (c1.area > 0 && c2.area > 0) {
                    float densidade1 = c1.populacao / c1.area;
                    float densidade2 = c2.populacao / c2.area;
                    (densidade1 < densidade2) ? pontos_c1++ : (densidade1 > densidade2) ? pontos_c2++ : 0;
                } else {
                    printf("\nErro: Área não pode ser zero para calcular a densidade populacional!\n");
                    return;
                }
                break;
            }
            default:
                printf("\nOpção inválida!\n");
                return;
        }
    }
    
    printf("\n==== Resultado ====");
    if (pontos_c1 > pontos_c2) {
        printf("\nVencedor: %s com %d pontos!\n", c1.nome, pontos_c1);
    } else if (pontos_c2 > pontos_c1) {
        printf("\nVencedor: %s com %d pontos!\n", c2.nome, pontos_c2);
    } else {
        printf("\nEmpate! Ambas as cidades são incríveis!\n");
    }
}

int main() {
    Carta c1, c2;
    int escolha1, escolha2;

    // Cadastro das cartas
    printf("Informe os dados da primeira cidade:\n");
    printf("Nome: "); scanf(" %[^\n]", c1.nome);
    printf("População: "); scanf("%d", &c1.populacao);
    printf("Área: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%f", &c1.pib);
    printf("Pontos turísticos: "); scanf("%d", &c1.pontos_turisticos);
    
    getchar(); // Consumir o '\n' restante para evitar erro na leitura da segunda cidade

    printf("\nInforme os dados da segunda cidade:\n");
    printf("Nome: "); scanf(" %[^\n]", c2.nome);
    printf("População: "); scanf("%d", &c2.populacao);
    printf("Área: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%f", &c2.pib);
    printf("Pontos turísticos: "); scanf("%d", &c2.pontos_turisticos);

    // Escolha dos atributos para comparação
    printf("\nEscolha dois atributos para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
    printf("Digite o primeiro atributo: "); scanf("%d", &escolha1);
    printf("Digite o segundo atributo: "); scanf("%d", &escolha2);
    
    // Comparação
    compararCartas(c1, c2, escolha1, escolha2);
    
    return 0;
}
