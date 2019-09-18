#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string>

struct listaSimples {
	char nome[20];
	listaSimples* prox;
};
void add(listaSimples** inicio, listaSimples** fim);
listaSimples* registro();
void list(listaSimples* inicio);
void removerRegistro(listaSimples** inicio);
listaSimples* remove(char removido[20], listaSimples** inicio);

void main() {
	listaSimples* inicio = NULL;
	listaSimples* fim = NULL;
	char op;

	do {
		printf("O que deseja fazer? [I]nserir, [E]xcluir, Es[V]aziar, [L]istar ou [Sair]?: \n");
		op = toupper(getchar());
		while (getchar() != '\n');
		switch (op)
		{
		case 'I':
			add(&inicio, &fim);
			break;
		case 'E':
			registro();
			break;
		case 'D':
			removerRegistro(&inicio);
			break;
		case 'V':
			registro();
			break;
		case 'L':
			list(inicio);
			break;
		default:
			break;
		}

	} while (op != 'S');
}

void list(listaSimples* lista) {
	if (lista == NULL)
		printf("Lista Vazia!!!");

	while(lista != NULL) {
		printf("Nome : %s \n", lista->nome);
		lista = lista->prox;
	}
}

void add(listaSimples** inicio, listaSimples** fim) {
	listaSimples* novo = registro();
	if (*inicio == NULL) {
		*inicio = novo;
	}
	else {
		(*fim)->prox = novo;
	}
	*fim = novo;
	novo = NULL;
}

listaSimples* registro() {
	listaSimples* novo = (listaSimples *)malloc(sizeof(listaSimples));
	if (novo == NULL) {
		printf("Sem espaço de memória: \n");
		return NULL;
	}
	printf("Digite o nome do usuario: \n");	
	fflush(stdin);
	fgets(novo->nome, 20, stdin);

	novo->prox = NULL;
	return novo;
};

listaSimples* remove(char removido[20], listaSimples* inicio) {
	
	if (inicio == NULL) {
	
	}

	if (inicio != NULL && inicio->prox == NULL) {
		if (strcmp(inicio->nome, removido) == 0) {
			free(inicio);
			inicio = NULL;
		}
		return inicio;
	}
	while (inicio->prox != NULL) {
		inicio = inicio->prox;
	}
	
	return inicio;
}

void removerRegistro(listaSimples** inicio) {
	char removido[20];
	if (*inicio == NULL) {
		printf("Sem dado para ser removido!");
		return;
	}
	printf("Digite o nome do usuario a ser deletado!");
	fflush(stdin);
	fgets(removido, 20, stdin);

	*inicio = remove(removido, *inicio);
}
