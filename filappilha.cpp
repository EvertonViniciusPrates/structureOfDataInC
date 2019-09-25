#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Pessoa {
	char nome[20];
	unsigned long long int ra;
	char pagoNaoPago[4];
	Pessoa* prox;
};
void cadastrar(Pessoa** inicio, Pessoa** fim);
void listar(Pessoa* inicio);
void esvaziar(Pessoa** inicio);
void transformar(Pessoa** inicio, Pessoa **topo);
void removerProximo(Pessoa **inicio);
Pessoa* novoElemento(Pessoa *elemento);
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
		case 'T':
			transformar(&inicio, &topo);
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
	Pessoa* novo = novoElemento(NULL);
	if (*inicio == NULL) {
		*inicio = novo;
	}
	else {
		(*fim)->prox = novo;
	}
	*fim = novo;
}

Pessoa* novoElemento(Pessoa *aux) {
	Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
	if (novo == NULL) {
		printf("Impossivel alocar espaco de memoria \n");
		return NULL;
	}
	if (aux == NULL) {
		printf("Digite o nome do convidado: \n");
		fflush(stdin); while (getchar() != '\n');
		fgets(novo->nome, 20, stdin);
		printf("Digite o ra do convidado: \n");
		scanf("%llu", &novo->ra);
		fflush(stdin); while (getchar() != '\n');
		printf("Digite o se o convidado pagou: \n");
		fflush(stdin);
		fgets(novo->pagoNaoPago, 4, stdin);
		novo->prox = NULL;
		return novo;
	}
	novo->prox = NULL;
	strcpy(novo->nome, aux->nome);
	novo->ra = aux->ra;
	strcpy(novo->pagoNaoPago, aux->pagoNaoPago);
	return novo;
}

void listar(Pessoa *inicio) {
	if (inicio == NULL) {
		printf("Impossivel listar uma fila vazia! Por favor adicione novos elementos \n");
		return;
	}
	while (inicio != NULL) {
		printf("Nome: %s \n", inicio->nome);
		printf("Ra: %llu \n", inicio->ra);
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
Pessoa* filaEmPilha(Pessoa**topo, Pessoa*aux) {
	Pessoa* novo = novoElemento(aux);
	if (*topo == NULL)
		*topo = novo;
	else {
		(*topo)->prox = novo;
	}
	*topo = novo;
	
	return *topo;
}
void transformar(Pessoa** inicio, Pessoa** topo) {
	Pessoa* aux = *inicio;
	if (*topo == *inicio) {
		printf("Sua fila esta vazia!, Insira ao menos um elemento para a transformacao para pilha!");
		return;
	}
	while (aux != NULL) {	
		*topo = filaEmPilha(&*topo, aux);
		removerProximo(&*inicio);
		aux = *inicio;
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
