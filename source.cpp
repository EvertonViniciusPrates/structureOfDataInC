#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct listaChurras {
	char nome[20];
	listaChurras* prox;
};

int main() {
	listaChurras* inicio = NULL;
	listaChurras* fim = NULL;
	listaChurras* aux;
	listaChurras* buffer;
	char encontrado[20];
	char op;
	listaChurras* novo;
	
	do {
		printf("O que deseja fazer? [I]nserir, [L]istar, [E]svaziar Lista, [D]eletar Usuario: \n");
		op = toupper(getchar());
		while (getchar() != '\n');
		switch (op)
		{
		case 'I':
			novo = (listaChurras*)malloc(sizeof(listaChurras));

			if (novo == NULL) {
				printf("Sem espaço de memória!");
				return 1;
			}

			printf("Digite o nome do usuario \n");
			fflush(stdin);
			fgets(novo->nome, 20, stdin);

			if (inicio == NULL) {
				inicio = novo;
			}
			else {
				fim->prox = novo;
			}
			novo->prox = NULL;
			fim = novo;

			printf("Usuario inserido com sucesso! \n");

			novo = NULL;
			break;
		case 'L':
			aux = inicio;
			if (aux == NULL) {
				printf("Lista Vazia!!! \n");
				break;
			}
			while (aux->prox != NULL) {
				printf("%s", aux->nome);
				printf("\n");
				aux = aux->prox;
			}
			printf("%s", aux->nome);
			printf("\n");
			break;
		case 'E':
			free(inicio);
			free(fim);
			inicio = NULL;
			fim = NULL;
			break;
		case 'D':
			aux = inicio;
			printf("Digite o nome do usuario que voce deseja deletar: \n");
			fflush(stdin);
			fgets(encontrado, 20, stdin);
			if (aux == NULL) {
				printf("Lista Vazia!!! \n");
				break;
			}
			if (aux->prox == NULL) {
				if (strcmp(encontrado, aux->nome)) {
					free(inicio);
					free(fim);
					inicio = NULL;
					fim = NULL;
					printf("Usuario deletado com sucesso! \n");
				}
				else {
					printf("O usuario que voce deseja deletar nao existe! \n");
				}
				break;
			}
			while (aux->prox != NULL) {
				if (strcmp(encontrado, aux->prox->nome)) {
					if (aux->prox->prox != NULL) {
						buffer = aux->prox->prox;
						free(aux->prox);
						aux->prox = buffer;
					}
					else {
						free(aux->prox);
					}
				}
				else {
					aux = aux->prox;
				}	
			}
			break;
		default:
			break;
		}

	}while (op);
	
}
