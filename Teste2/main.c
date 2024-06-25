#include <stdio.h>
#include <stdlib.h>
#include "cinema1.h"
#include "cinema2.h"
#include "cinema3.h"

void confirmar(int compra, char filmesCadastrados[10][2][50], int quantidadeFilmes, char filmeEscolhido[50], char dataFilmeEscolhido[5], int acompanhamentos, char nomeAcompanhamentos[50], int pagamento, char formaPagamento[50], int *resposta);

int main() {
    int assento[5][5] = {{0}};
    int acompanhamentos = 0, pagamento = 0, resposta = 0, quantidadeFilmes = 0, compra = 0;

    char dataFilmeEscolhido[5] = "";
    char filmeEscolhido[50] = "", nomeAcompanhamentos[50] = "", formaPagamento[50] = "";
    char filmesCadastrados[10][2][50] = {0}; // Inicializa o array de filmes cadastrados

    printf("\n** BEM VINDO AO CINEMA BPK! **\n");
    printf("\nCadeiras disponiveis: \n");
    imprimirCadeiras(assento);

    while (resposta != 10) {
        printf("\nEscolha as seguintes opcoes abaixo: \n");
        printf("1 = Cadastrar Filme\n");
        printf("2 = Editar Filme\n");
        printf("3 = Excluir Filme\n");
        printf("4 = Relatorio\n");
        printf("5 = Escolher filme\n");
        printf("6 = Comprar Poltrona\n");
        printf("7 = Comprar Acompanhamentos\n");
        printf("8 = Escolher forma de pagamento\n");
        printf("Resposta: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                cadastrarFilme(filmesCadastrados, &quantidadeFilmes);
                break;
            case 2:
                editarFilme(filmesCadastrados, quantidadeFilmes, filmeEscolhido, dataFilmeEscolhido);
                break;
            case 3:
                excluirFilme(filmesCadastrados, &quantidadeFilmes, filmeEscolhido, dataFilmeEscolhido);
                break;
            case 4:
                relatorio(compra, filmesCadastrados, quantidadeFilmes, filmeEscolhido, dataFilmeEscolhido, acompanhamentos, nomeAcompanhamentos, pagamento, formaPagamento);
                break;
            case 5:
                escolherFilme(filmesCadastrados, quantidadeFilmes, filmeEscolhido, dataFilmeEscolhido);
                break;
            case 6:
                comprarPoltrona(assento, &compra);
                break;
            case 7:
                comprarAcompanhamentos(&acompanhamentos, nomeAcompanhamentos);
                break;
            case 8:
                escolherFormaPagamento(&pagamento, formaPagamento);
                break;
            default:
                system("cls");
                printf("\nOpcao invalida, digite outra!\n");
        }
    }

    return 0;
}
