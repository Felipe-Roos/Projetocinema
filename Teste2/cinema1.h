#ifndef CINEMA1_H
#define CINEMA1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarFilme(char filmesCadastrados[10][2][50], int *quantidadeFilmes) {
    char filmeCadastrado[50], dataExibicao[5];

    system("cls");
    printf("\nCadastre seu filme!\n");
    printf("Nome: ");
    scanf(" %s",filmeCadastrado);

    if (strcmp(filmeCadastrado, " ") != 0) { // Verifica se o nome do filme não é vazio
        printf("\nCadastre a data de exibicao do filme, digite 01/02 para 01 (dia) 02 (mes)!\n");
        printf("Data: ");
        scanf("%s", dataExibicao);

        if (strcmp(dataExibicao, " ") != 0) { // Verifica se a data de exibição não é vazia
            strcpy(filmesCadastrados[*quantidadeFilmes][0], filmeCadastrado); // adiciona o filme digitado no array de filmes cadastrados
            strcpy(filmesCadastrados[*quantidadeFilmes][1], dataExibicao); // adiciona a data digitada no array de filmes cadastrados
            (*quantidadeFilmes)++;
            printf("\nFilme cadastrado com sucesso!\n");
        } else {
            printf("Data invalida!\n");
            strcpy(filmesCadastrados[*quantidadeFilmes][0], filmeCadastrado); // adiciona o filme digitado no array de filmes cadastrados
            strcpy(filmesCadastrados[*quantidadeFilmes][1], "0000"); // adiciona uma data padrão no array de filmes cadastrados
            (*quantidadeFilmes)++;
            filmeCadastrado[0] = '\0';
        }
    } else {
        printf("\nDigite o nome de um filme existente!\n");
    }
}
void relatorio(int compra, char filmesCadastrados[10][2][50], int quantidadeFilmes, char filmeEscolhido[50], char dataFilmeEscolhido[5], int acompanhamentos, char nomeAcompanhamentos[50], int pagamento, char formaPagamento[50]) {
    int i;

    system("cls");
    FILE *arquivo = fopen("relatorio.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\nForam vendidas %d poltrona(s)\n", compra);
    fprintf(arquivo, "Foram vendidas %d poltrona(s)\n", compra);

    if (quantidadeFilmes > 0) {
        printf("Filmes em cartaz:");
        fprintf(arquivo, "Filmes em cartaz:");
        for (i = 0; i < quantidadeFilmes; i++) { // percorre todos os filmes cadastrados e mostra eles
            printf("\n - Filme: %s - Data de exibicao: %s", filmesCadastrados[i][0], filmesCadastrados[i][1]);
            fprintf(arquivo, "\n - Filme: %s - Data de exibicao: %s", filmesCadastrados[i][0], filmesCadastrados[i][1]);
        }
    } else {
        printf("Nenhum filme em cartaz");
        fprintf(arquivo, "Nenhum filme em cartaz");
    }

    if (strcmp(filmeEscolhido, "") != 0) { // verifica se o nome do filme escolhido não é vazio
        printf("\nO filme escolhido foi %s na data %s \n", filmeEscolhido, dataFilmeEscolhido);
        fprintf(arquivo, "\nO filme escolhido foi %s na data %s \n", filmeEscolhido, dataFilmeEscolhido);
    } else {
        printf("\nNenhum filme foi escolhido\n");
        fprintf(arquivo, "\nNenhum filme foi escolhido\n");
    }

    if (acompanhamentos > 0 && acompanhamentos < 4) {
        printf("Foi comprado %s como acompanhamento\n", nomeAcompanhamentos);
        fprintf(arquivo, "Foi comprado %s como acompanhamento\n", nomeAcompanhamentos);
    } else {
        printf("Nao foi comprado nenhum combo como acompanhamento\n");
        fprintf(arquivo, "Nao foi comprado nenhum combo como acompanhamento\n");
    }

    if (pagamento > 0 && pagamento < 4) {
        printf("Foi escolhido %s como forma de pagamento\n", formaPagamento);
        fprintf(arquivo, "Foi escolhido %s como forma de pagamento\n", formaPagamento);
    } else {
        printf("Nao foi escolhido nenhuma forma de pagamento\n");
        fprintf(arquivo, "Nao foi escolhido nenhuma forma de pagamento\n");
    }

    fclose(arquivo);
    printf("\nRelatório salvo em 'relatorio.txt'\n");
}
#endif // CINEMA1_H
