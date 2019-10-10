// C4996_containers.cpp
// compile with: cl /c /W4 /D_DEBUG C4996_containers.cpp
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

//@Author Everton Prates
//RA:215213412
struct lista
{
	char ra[10];
	lista* prox;
};

void inserir(lista** ini, lista** fim);
lista* inserirInicio(lista* inicio);
void inserirMeio(lista* inicio, char procurado[10], char procuradoDepois[10]);
lista* localizar(lista* inicio, char procurado[10], char procuradoDepois[10]);
lista* novoElemento();
void listar(lista* inicio);
void excluir(lista** ini, lista** fim);
void removeMeio(lista* inicio, char procurado[10]);
lista* removeInicio(lista* inicio);
void esvaziar(lista** inicio);
int main() {
	char op;
	lista* fim;
	lista* inicio = fim = NULL;

	do {
		printf("O que deseja fazer? [I]nserir, [L]istar, [E]xcluir, [X]Esvaziar\n");
		op = toupper(getchar());
		while (getchar() != '\n');
		switch (op)
		{
		case 'I': inserir(&inicio, &fim);break;
		case 'L': listar(inicio); break;
		case 'E': excluir(&inicio, &fim); break;
		case 'X': esvaziar(&inicio); break;
		default:
			break;
		}
	} while (op);
}

void listar(lista* inicio) {
	if (inicio == NULL) {
		printf("Lista Vazia!\n");
	}
	else {
		while (inicio != NULL) {
			printf("RA: %s \n", inicio->ra);
			inicio = inicio->prox;
		}
	}
}

void inserir(lista** ini, lista** fim) {
	char op;
	if (*ini == *fim) {
		*ini = inserirInicio(*ini);
	}
	else if ((*ini)->prox == NULL) {
		*ini = inserirInicio(*ini);
	}
	else {
		char procurado[10];
		printf("Deseja Inserir [A]ntes ou [D]epois?");
		op = toupper(getchar());
		switch (op)
		{
		case 'A':			
			printf("Inserir Antes De:\n");
			fflush(stdin); while (getchar() != '\n');
			fgets(procurado, 10, stdin);
			if (strcmp(procurado, (*ini)->ra) == 0)
				* ini = inserirInicio(*ini);
			else {
				inserirMeio(*ini, procurado, NULL);
			}
			break;
		case 'D':
			printf("Inserir Depois De:\n");
			fflush(stdin); while (getchar() != '\n');
			fgets(procurado, 10, stdin);
			if (strcmp(procurado, (*ini)->ra) == 0)
				* ini = inserirInicio(*ini);
			else {
				inserirMeio(*ini, NULL, procurado);
			}
			break;
		default: *ini = inserirInicio(*ini);
			break;
		}
	}
}

lista* inserirInicio(lista* inicio) {
	lista* novo = novoElemento();
	novo->prox = inicio;
	inicio = novo;
	return inicio;
}

lista* novoElemento() {
	lista* novo = (lista*)malloc(sizeof(lista));
	if (novo == NULL) {
		printf("Sem espaço de memória suficiente!\n");
	}
	else {
		printf("Digite o valor a ser inserido!\n");
		fflush(stdin);
		fgets(novo->ra, 10, stdin);
	}
	return novo;
}

void inserirMeio(lista* inicio, char procuradoAntes[10], char procuradoDepois[10]) {
	lista* novo = novoElemento();
	lista* enc = localizar(inicio, procuradoAntes, procuradoDepois);
	if (enc == NULL) {
		if (procuradoAntes == NULL)
			printf("Esse valor nao existe para ser iserido algo antes dele! Valor:%s \n", procuradoDepois);
		else
			printf("Esse valor nao existe para ser iserido algo depois dele! Valor:%s \n", procuradoAntes);
	}
	else {
		if (procuradoAntes == NULL) {
			lista* aux = enc->prox;
			novo->prox = aux;
			enc->prox = novo;
		}
		else {
			novo->prox = enc->prox;
			enc->prox = novo;
		}
	}
}

void excluir(lista** ini, lista** fim) {
	if (*ini == *fim) {
		printf("Sua lista está vazia, por favor insira novos elementos!\n");
	}
	else if ((*ini)->prox == NULL) {
		*ini = removeInicio(*ini);
	}
	else {
		char procurado[10];
		printf("Digite o elemento a ser excluido!\n");
		fflush(stdin);
		fgets(procurado, 10, stdin);

		if (strcmp((*ini)->ra, procurado) == 0) {
			*ini = removeInicio(*ini);
		}
		else {
			removeMeio(*ini, procurado);
		}
	}
}

lista* removeInicio(lista* inicio) {
	lista* aux = inicio->prox;
	if (inicio == NULL) {
		printf("Sua lista está vazia, insira ao menos 1 elemento!\n");
	}
	else {
		free(inicio);
		inicio = NULL;
		inicio = aux;
	}
	return inicio;
}

void removeMeio(lista* inicio, char procurado[10]) {
	lista* enc = localizar(inicio, procurado, NULL);
	lista* aux = enc->prox->prox;
	free(enc->prox);
	enc->prox = aux;
}

lista* localizar(lista* inicio, char procuradoAntes[10], char procuradoDepois[10]) {
	while (procuradoAntes != NULL && inicio->prox != NULL && strcmp(procuradoAntes, inicio->prox->ra) != 0)
		inicio = inicio->prox;

	while(procuradoDepois != NULL && inicio != NULL && strcmp(procuradoDepois, inicio->ra) != 0)
		inicio = inicio->prox;

	return inicio;
}

void esvaziar(lista * *inicio) {
	lista* aux = *inicio;
	if (*inicio == NULL) {
		printf("Impossivel esvaziar uma lista vazia!\n");
	}
	else
		while (*inicio != NULL) {
			aux = (*inicio)->prox;
			free(*inicio);
			*inicio = aux;
		}
}
