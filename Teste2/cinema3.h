#ifndef CINEMA3_H
#define CINEMA3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCadeiras(int assento[5][5]) {
    printf("\n");
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (assento[i][j] == 0) {
                printf("[ %d%d ]", i, j); // imprime a posição das cadeiras
            } else if (assento[i][j] == 1) {
                printf("[ VE ]"); // imprime as cadeiras vendidas
            }
        }
        printf("\n");
    }
}



void comprarPoltrona(int assento[5][5], int *compra) {
    int fila, coluna;

    system("cls");
    imprimirCadeiras(assento);
    printf("\nDigite o codigo da Fila: ");
    scanf("%d", &fila);
    printf("Digite o codigo da Coluna: ");
    scanf("%d", &coluna);

    if (assento[fila][coluna] == 0) {
        assento[fila][coluna] = 1;
        system("cls");
        imprimirCadeiras(assento);
        (*compra)++;
    } else {
        printf("\nPoltrona ja comprada, escolha outra!\n");
    }
}

void comprarAcompanhamentos(int *acompanhamentos, char nomeAcompanhamentos[50]) {
    system("cls");
    printf("\nEscolha seus acompanhamentos: \n");
    printf("1 = Refrigerante com pipoca\n");
    printf("2 = Refrigerante com chocolate\n");
    printf("3 = Pipoca e chocolate\n");
    printf("Resposta: ");
    scanf("%d", acompanhamentos);

    if (*acompanhamentos == 1) {
        strcpy(nomeAcompanhamentos, "Refrigerante com pipoca"); // copia a opção escolhida para a variavel nomeAcompanhamentos
    } else if (*acompanhamentos == 2) {
        strcpy(nomeAcompanhamentos, "Refrigerante com chocolate"); // copia a opção escolhida para a variavel nomeAcompanhamentos
    } else if (*acompanhamentos == 3) {
        strcpy(nomeAcompanhamentos, "Pipoca e chocolate"); // copia a opção escolhida para a variavel nomeAcompanhamentos
    }
}

void escolherFormaPagamento(int *pagamento, char formaPagamento[50]) {
    system("cls");
    printf("\nEscolha a forma de pagamento: \n");
    printf("1 = PIX\n");
    printf("2 = Cartao de debito\n");
    printf("3 = Cartao de credito\n");
    printf("Resposta: ");
    scanf("%d", pagamento);

    if (*pagamento == 1) {
        strcpy(formaPagamento , "PIX"); // copia a opção escolhida para a variavel pagamento
    } else if (*pagamento == 2) {
        strcpy(formaPagamento, "Cartao de debito"); // copia a opção escolhida para a variavel pagamento
    } else if (*pagamento == 3) {
        strcpy(formaPagamento, "Cartao de credito"); // copia a opção escolhida para a variavel pagamento
    }
}

#endif // CINEMA3_H
