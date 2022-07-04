#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  char caracter;
  struct no *proximo;
} No;

No *empilhar(No *pilha, char valor)
{
  No *novo = malloc(sizeof(No));

  if (novo)
  {
    novo->caracter = valor;
    novo->proximo = pilha;
    return novo;
  }
  else
    printf("\tErro ao alocar memoria!\n");
  return NULL;
}

No *desempilhar(No **pilha)
{
  No *remover = NULL;

  if (*pilha)
  {
    remover = *pilha;
    *pilha = remover->proximo;
  }
  else
    printf("\tEXPRESSAO MAL FORMADA!\n");
  return remover;
}

void imprimir(No *pilha)
{
  printf("\n\tPILHA\n");
  while (pilha)
  {
    printf("\t%c\n", pilha->caracter);
    pilha = pilha->proximo;
  }
  printf("\tFIM PILHA\n\n");
}

int forma_par(char f, char d)
{
  switch (f)
  {
  case ')':
    if (d == '(')
      return 1; // bem formada
    else
      return 0; // mal formada
    break;
  }
}

void identifica_formacao(char x[])
{
  int i = 0;
  No *remover, *pilha = NULL;

  while (x[i] != '\0')
  {
    if (x[i] == '(')
    {
      pilha = empilhar(pilha, x[i]);
    }
    else if (x[i] == ')')
    {
      remover = desempilhar(&pilha);
      if (forma_par(x[i], remover->caracter) == 0)
      {
        printf("\tEXPRESSAO MAL FORMADA!");
      }
      free(remover);
    }
    i++;
  }

  if (pilha)
  {
    printf("\tEXPRESSAO MAL FORMADA!");
  }
  else
  {
    printf("\tEXPRESSAO BEM FORMADA!");
  }
}

int main()
{
  /*
  EXEMPLO:
  (1+2(4-2))*1  ->  BEM FORMADA
  (1+5/(2)      ->  MAL FORMADA
  */
  char exp[100];
  printf("\tDigite uma Expressão: ");
  scanf("%99[^\n]", exp);
  identifica_formacao(exp);
  printf("\n \tExpressão: %s", exp);
}
