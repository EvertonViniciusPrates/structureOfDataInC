#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Pessoa {
	char nome[20];
	char ra[12];
	char pagoNaoPago[4];
	Pessoa* prox;
};
void cadastrar(Pessoa** inicio, Pessoa** fim, Pessoa** topo);
void listar(Pessoa* inicio, Pessoa*topo);
void esvaziar(Pessoa** inicio);
void transformar(Pessoa** inicio, Pessoa** topo);
Pessoa* removerProximo(Pessoa** inicio, Pessoa**topo);
Pessoa* novoElemento(Pessoa* elemento);
void main() {
	Pessoa* inicio = NULL; Pessoa* fim = NULL; Pessoa* topo = NULL;
	char op;

	do
	{
		printf("O que deseja fazer ? [I]nserir, [L]istar, [T]ransformar, [E]svaziar ou [S]air? \n");
		op = toupper(getchar());
		switch (op)
		{
		case 'I':
			cadastrar(&inicio, &fim, &topo);
			break;
		case 'L':
			listar(inicio, topo);
			break;
		case 'E':
			esvaziar(&inicio);
			break;
		case 'R':
			removerProximo(&inicio, &topo);
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

void cadastrar(Pessoa * *inicio, Pessoa * *fim, Pessoa** topo) {
	Pessoa* novo = novoElemento(NULL);
	if (*topo != NULL) {
		(*topo)->prox = novo;
	}
	else {
		if (*inicio == NULL) {
			*inicio = novo;
		}
		else {
			(*fim)->prox = novo;
		}
		*fim = novo;
	}
}

Pessoa* novoElemento(Pessoa * aux) {
	Pessoa* novo = (Pessoa*)malloc(sizeof(Pessoa));
	if (novo == NULL) {
		printf("Impossivel alocar espaco de memoria \n");
	}
	else {
		if (aux == NULL) {
			printf("Digite o nome do convidado: \n");
			fflush(stdin); while (getchar() != '\n');
			fgets(novo->nome, 20, stdin);
			printf("Digite o ra do convidado: \n");
			fflush(stdin);
			fgets(novo->ra, 12, stdin);
			printf("Digite o se o convidado pagou: \n");
			fflush(stdin);
			fgets(novo->pagoNaoPago, 4, stdin);
		} else {
			strcpy_s(novo->nome, aux->nome);
			strcpy_s(novo->ra, aux->ra);
			strcpy_s(novo->pagoNaoPago, aux->pagoNaoPago);
		}
		novo->prox = NULL;
		return novo;
	}
}

void listar(Pessoa * inicio, Pessoa *topo) {
	Pessoa* aux;
	if (topo != NULL) 
		aux = topo;	
	else 
		aux = inicio;
	
	if (aux == NULL) {
		printf("Impossivel listar uma fila vazia! Por favor adicione novos elementos \n");
		return;
	}
	while (aux != NULL) {
		printf("Nome: %s \n", aux->nome);
		printf("Ra: %s \n", aux->ra);
		printf("Pagou?: %s \n", aux->pagoNaoPago);
		printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		aux = aux->prox;
	}
}

void esvaziar(Pessoa * *inicio) {
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

Pessoa* filaEmPilha(Pessoa *topo, Pessoa * aux) {
	Pessoa* novo = novoElemento(aux);
	novo->prox = topo;
	return novo;
}

void transformar(Pessoa **inicio, Pessoa **topo) {
	Pessoa* objNulo = NULL;
	if (*topo == *inicio) {
		printf("Sua fila esta vazia!, Insira ao menos um elemento para a transformacao para pilha! \n");
	}
	else if (*inicio != NULL) {
		while (*inicio != NULL) {
			*topo = filaEmPilha(*topo, *inicio);
			*inicio = removerProximo(inicio, &objNulo);
		}
	}
};

Pessoa* removerProximo(Pessoa** inicio, Pessoa** topo) {
	Pessoa* aux;
	if (*topo != NULL) {
		aux = (*topo)->prox;
		free(*topo);
		return aux;
	} else {
		if (*inicio == NULL) {
			printf("Impossivel remover de uma estrutura vazia!");
			return NULL;
		}
		else {
			aux = (*inicio)->prox;
			free(*inicio);
			return aux;
		}
	}
}

