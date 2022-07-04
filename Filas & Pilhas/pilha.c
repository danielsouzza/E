/* Implementação de uma pilha usando lista encadeada simples. */
#include <stdio.h>
#include <stdlib.h>

// Estrutura representante de cada nó
typedef struct No {
	int dado;
	struct No *prox;
} No;

// Topo da pilha
No *topo;

// Inicializar pilha
void Inicializar_Pilha() {
	topo = NULL;
}

// Verificar ser pilha está vazia
char Check_Pilha_Vazia() {
	return topo == NULL;
}

// Inserir elemento à pilha
void Inserir_Elemento(int elemento) {
	No *tmp = (No*) malloc(sizeof(No));
	tmp->dado = elemento;
	tmp->prox = topo;
	topo = tmp;
}

// Remover topo da pilha
int Excluir_Elemento() {
	No *tmp = topo;
	int elemento = topo->dado;
	topo = topo->prox;
	free(tmp);
	return elemento;
}

// Ler elemento do topo da pilha
int Le_Topo_Pilha() {
	if (topo == NULL) return -1;
	return topo->dado;
}

// Excluir elemento específico da pilha
int Excluir_Elemento_Especifico(int elemento) {
	if (Check_Pilha_Vazia()) puts("Pilha vazia");
	else if (topo->dado == elemento) Excluir_Elemento();
	else {
		No *tmp = topo;
		while (tmp != NULL) {
			if (tmp->prox->dado == elemento) {
				int retElemento = tmp->prox->dado;
				tmp->prox = tmp->prox->prox;
				return retElemento;
			}
			tmp = tmp->prox;
		}
	}

	return -1;
}

// Imprimir pilha inteira
void Imprimir_Pilha() {
	if (Check_Pilha_Vazia()) puts("Pilha vazia.");
	else {
		No *tmp = topo;
		while (tmp != NULL) {
			printf("%d ", tmp->dado);
			tmp = tmp->prox;
		}
	}
	getchar();
	getchar();
}

// Controlador
int main() {
	Inicializar_Pilha();
	puts("Pilha inicializada.");

	unsigned int o;
	do {
		system("clear || cls");
		puts("Pilha");
		puts("1) Inserir elemento");
		puts("2) Excluir último elemento");
		puts("3) Ler último elemento");
		puts("4) Excluir elemento especifico");
		puts("5) Imprimir pilha, do topo para base");
		puts("0) Finalizar programa");
		scanf("%u", &o);

		switch (o) {
			case 1:
				int elemento;
				scanf("%d", &elemento);
				Inserir_Elemento(elemento);
				break;
			case 2:
				Excluir_Elemento();
				break;
			case 3:
				elemento = Le_Topo_Pilha();
				elemento >= 0 ? printf("%d", elemento) : puts("Pilha vazia.");
				getchar();
				getchar();
				break;
			case 4:
				scanf("%d", &elemento);
				Excluir_Elemento_Especifico(elemento);
				break;
			case 5:
				Imprimir_Pilha();
				break;
		}
	} while (o != 0);
	
	return 0;
}
