#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

struct Pessoa {
	char nome[20];
	char ra[9];
	char pagoNaoPago[4];
	Pessoa* prox;
};
void cadastrar(Pessoa** inicio, Pessoa** fim);
void listar(Pessoa* inicio);
void esvaziar(Pessoa** inicio);
void transformar(Pessoa** inicio, Pessoa **topo);
void removerProximo(Pessoa **inicio);
Pessoa* novoElemento();
void main() {
	Pessoa* inicio = NULL; Pessoa* fim = NULL; Pessoa* topo = NULL;
	char op;
	
	do
	{
		printf("O que deseja fazer ? [I]nserir, [L]istar, [E]svaziar ou [S]air? \n");
		op = toupper(getchar());
		switch (op)
		{
		case 'I':
			cadastrar(&inicio, &fim);
			break;
		case 'L':
			listar(inicio);
			break;
		case 'E':
			esvaziar(&inicio);
			break;
		case 'R':
			removerProximo(&inicio);
			break;
		case 'S':
			printf("Estamos finalizando o sistema \n");
			esvaziar(&inicio);
			break;
		default: 
			break;
		}
	} while (op != 'S');
}

void cadastrar(Pessoa** inicio, Pessoa** fim) {
	Pessoa* novo = novoElemento();
	if (*inicio == NULL) {
		*inicio = novo;
	}
	else {
		(*fim)->prox = novo;
	}
	*fim = novo;
}

Pessoa* novoElemento() {
	Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
	while (getchar() != '\n');
	if (novo == NULL) {
		printf("Impossivel alocar espaco de memoria \n");
		return NULL;
	}
	printf("Digite o nome do convidado: \n");
	fflush(stdin);
	fgets(novo->nome, 20, stdin);
	printf("Digite o ra do convidado: \n");
	fflush(stdin);
	fgets(novo->ra, 9, stdin);
	printf("Digite o se o convidado pagou: \n");
	fflush(stdin);
	fgets(novo->pagoNaoPago, 4, stdin);
	novo->prox = NULL;
	return novo;
}

void listar(Pessoa *inicio) {
	if (inicio == NULL) {
		printf("Impossivel listar uma fila vazia! Por favor adicione novos elementos \n");
		return;
	}
	while (inicio != NULL) {
		printf("Nome: %s \n", inicio->nome);
		printf("Ra: %s \n", inicio->ra);
		printf("Pagou?: %s \n", inicio->pagoNaoPago);
		printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		inicio = inicio->prox;
	}
}

void esvaziar(Pessoa **inicio) {
	if (*inicio == NULL) {
		printf("Impossivel esvaziar uma fila vazia! \n");
		return;
	}
	Pessoa* aux = *inicio;
	while (aux != NULL) {
		aux = (*inicio)->prox;
		free(*inicio);
		*inicio = aux;
	}
}

void  transformar(Pessoa** inicio, Pessoa** topo) {
	if (*topo == *inicio) {
		printf("Sua fila esta vazia!, Insira ao menos um elemento para a transformacao para pilha!");
		return;
	}
	
};

void removerProximo(Pessoa** inicio) {
	if (*inicio == NULL) {
		printf("Impossivel remover de uma estrutura vazia!");
		return;
	}
	Pessoa* aux = (*inicio)->prox;
	free(*inicio);
	*inicio = aux;
}
