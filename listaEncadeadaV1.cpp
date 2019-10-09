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

void inserir(lista** ini, lista ** fim);
lista* inserirInicio(lista* inicio);
void inserirMeio(lista* inicio);
lista* localizar(lista* inicio, char procurado[10]);
lista* novoElemento();
void listar(lista* inicio);
int main() {
	char op;
	lista* fim;
	lista* inicio = fim = NULL;

	do {
		printf("O que deseja fazer? [I]nserir, [L]istar");
		op = toupper(getchar());
		while (getchar() != '\n');
		switch (op)
		{
		case 'I' : inserir(&inicio, &fim);
			break;
		case 'L': listar(inicio);
		default:
			break;
		}
	} while (op);
}

void listar(lista *inicio) {
	if (inicio == NULL) {
		printf("Lista Vazia!");
	}
	else {
		while (inicio != NULL) {
			printf("RA: %s \n", inicio->ra);
			inicio = inicio->prox;
		}
	}
}

void inserir(lista** ini, lista** fim) {
	if (*ini == *fim) {
		*ini = inserirInicio(*ini);
	}
	else if ((*ini)->prox == NULL) {
		*ini = inserirInicio(*ini);
	} else {
		inserirMeio(*ini);
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
		printf("Sem espaço de memória suficiente!");
	}
	else {
		printf("Digite o valor a ser inserido!");
		fflush(stdin);
		fgets(novo->ra, 10, stdin);
	}
	return novo;
}

void inserirMeio(lista* inicio) {
	lista* novo = novoElemento();
	char procurado[10];
	printf("Inserir Antes De:");
	fflush(stdin);
	fgets(procurado, 10, stdin);
	lista* enc = localizar(inicio, procurado);

	novo->prox = enc->prox;
	enc->prox = novo;
}

lista* localizar(lista* inicio, char procurado[10]) {
	if (strcmp(procurado, inicio->ra) == 0) {
		return inicio;
	}
	while (inicio->prox != NULL && strcmp(procurado, inicio->prox->ra) == 1) {
		inicio = inicio->prox;
	}
	return inicio;
}