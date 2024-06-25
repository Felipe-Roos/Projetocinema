#ifndef CINEMA2_H
#define CINEMA2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void editarFilme(char filmesCadastrados[10][2][50], int quantidadeFilmes, char filmeEscolhido[50], char dataFilmeEscolhido[5]) {
    char filmeEditado[50], novaDataExibicao[5];
    int i;

    system("cls");
    if (quantidadeFilmes > 0) {
        printf("Filmes cadastrados: \n");
        for (i = 0; i < quantidadeFilmes; i++) { // percorre todos os filmes cadastrados e mostra eles
            printf(" - Filme: %s - Data de exibicao: %s\n", filmesCadastrados[i][0], filmesCadastrados[i][1]);
        }

        printf("\nDigite o nome do filme para editar!\n");
        printf("Nome: ");
        scanf(" %[^\n]%*c", filmeEditado); // Lê a string incluindo espaços

        int filmeEncontrado = 0;
        for (i = 0; i < quantidadeFilmes; i++) {
            if (strcmp(filmesCadastrados[i][0], filmeEditado) == 0) { // verifica se o nome do filme já foi cadastrado
                printf("Digite a nova data de exibicao do filme: ");
                scanf("%s", novaDataExibicao);
                strcpy(filmesCadastrados[i][1], novaDataExibicao); // adiciona a nova data digitada na data anterior do filme cadastrado

                if (strcmp(filmesCadastrados[i][0], filmeEscolhido) == 0) { // verifica se o filme escolhido é igual ao filme editado
                    strcpy(dataFilmeEscolhido, novaDataExibicao); // adiciona a nova data digitada na data anterior do filme escolhido
                }

                filmeEncontrado = 1;
                printf("\nFilme editado com sucesso!\n");
            }
        }

        if (filmeEncontrado == 0) {
            printf("\nFilme nao encontrado!\n");
        }

    } else {
        printf("\nNao ha nenhum filme cadastrado!\n");
    }
}

void escolherFilme(char filmesCadastrados[10][2][50], int quantidadeFilmes, char filmeEscolhido[50], char dataFilmeEscolhido[5]) {
    int i;

    system("cls");
    if (quantidadeFilmes > 0) {
        printf("\nEscolha seu filme!\n");
        for (i = 0; i < quantidadeFilmes; i++) { // percorre todos os filmes cadastrados e mostra eles
            printf(" - Filme: %s - Data de exibicao: %s\n", filmesCadastrados[i][0], filmesCadastrados[i][1]);
        }

        printf("\nDigite o nome do filme para assistir!\n");
        printf("Nome: ");
        scanf(" %[^\n]%*c", filmeEscolhido); // Lê a string incluindo espaços

        int filmeEncontrado = 0;
        for (i = 0; i < quantidadeFilmes; i++) {
            if (strcmp(filmesCadastrados[i][0], filmeEscolhido) == 0) { // verifica se o filme escolhido é igual a algum filme já cadastrado
                strcpy(dataFilmeEscolhido, filmesCadastrados[i][1]); // copia a data do filme cadastrado na data do filme escolhido
                filmeEncontrado = 1;
                printf("\nFilme escolhido com sucesso!\n");
            }
        }

        if (filmeEncontrado == 0) {
            printf("\nFilme escolhido nao esta em cartaz!\n");
        }

    } else {
        printf("\nNao ha filmes em cartaz!\n");
    }
}

void excluirFilme(char filmesCadastrados[10][2][50], int *quantidadeFilmes, char filmeEscolhido[50], char dataFilmeEscolhido[5]) {
    char filmeExcluido[50];
    int i, j;

    system("cls");
    if (*quantidadeFilmes > 0) {
        printf("Filmes cadastrados: \n");
        for (i = 0; i < *quantidadeFilmes; i++) { // percorre todos os filmes cadastrados e mostra eles
            printf(" - Filme: %s - Data de exibicao: %s\n", filmesCadastrados[i][0], filmesCadastrados[i][1]);
        }

        printf("\nDigite o nome do filme para excluir!");
        printf("\nNome: ");
        scanf(" %[^\n]%*c", filmeExcluido); // Lê a string incluindo espaços

        int filmeEncontrado = 0;
        for (i = 0; i < *quantidadeFilmes; i++) {
            if (strcmp(filmesCadastrados[i][0], filmeExcluido) == 0) { // verifica se o filme excluido é igual a algum filme já cadastrado
                for (j = i; j < *quantidadeFilmes - 1; j++) {
                    strcpy(filmesCadastrados[j][0], filmesCadastrados[j + 1][0]); // remove o nome do filme cadastrado
                    strcpy(filmesCadastrados[j][1], filmesCadastrados[j + 1][1]); // remove a data do filme cadastrado
                }
                (*quantidadeFilmes)--;
                strcpy(filmeEscolhido, ""); // remove o nome do filme escolhido
                strcpy(dataFilmeEscolhido, ""); // remove a data do filme escolhido
                filmeEncontrado = 1;
                printf("\nFilme removido com sucesso!\n");
            }
        }

        if (filmeEncontrado == 0) {
            printf("\nFilme nao encontrado!\n");
        }

    } else {
        printf("\nNao ha nenhum filme cadastrado!\n");
    }
}

#endif // CINEMA2_H
