#include "ListaOrdenada.h"
#include <stdlib.h>
#include <stdio.h>

/* Inicialização da lista sequencial dinâmica */
void inicializarLista(LISTA *l)
{
  l->nroElem = 0;
  l->capacidade = 50;                                          // Capacidade inicial
  l->A = (REGISTRO *)malloc(l->capacidade * sizeof(REGISTRO)); // Alocação dinâmica inicial
  if (l->A == NULL)
  {
    printf("Erro ao alocar memória!\n");
    exit(ERRO);
  }
} 

/* Função para redimensionar a lista (aumentar ou diminuir a capacidade) */
void resize(LISTA *l)
{
  if (l->nroElem == l->capacidade)
  {
    // Se a lista estiver cheia, dobra a capacidade
    l->capacidade *= 2;
  }
  else if (l->nroElem <= l->capacidade / 4)
  {
    // Se o número de elementos cair para 25% da capacidade, reduz a capacidade pela metade
    l->capacidade /= 2;
  }

  // Redimensiona a lista usando realloc
  l->A = (REGISTRO *)realloc(l->A, l->capacidade * sizeof(REGISTRO));
  if (l->A == NULL)
  {
    printf("Erro ao redimensionar memória!\n");
    exit(ERRO);
  }
} 

/* Exibição da lista sequencial */
void exibirLista(LISTA *l)
{
  int i;
  printf("Lista: \" ");
  for (i = 0; i < l->nroElem; i++)
  {
    printf("%i ", l->A[i].chave);
  }
  printf("\"\n");
} 

/* Retornar o tamanho da lista (número de elementos válidos) */
int tamanho(LISTA *l)
{
  return l->nroElem;
}

/* Retornar a capacidade da lista (número de elementos que podem ser inseridos) */
int capacidade(LISTA *l)
{
  return l->capacidade;
}

/* Retornar o tamanho em bytes da lista. Neste caso, depende do tamanho do vetor dinâmico */
int tamanhoEmBytes(LISTA *l)
{
  return sizeof(LISTA) + (l->capacidade * sizeof(REGISTRO));
} 

/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO caso a lista esteja vazia */
TIPOCHAVE primeiroElem(LISTA *l)
{
  if (l->nroElem > 0)
    return l->A[0].chave;
  else
    return ERRO; // lista vazia
}

/* Retornar a chave do último elemento da lista sequencial (caso haja) e ERRO caso a lista esteja vazia */
TIPOCHAVE ultimoElem(LISTA *l)
{
  if (l->nroElem > 0)
    return l->A[l->nroElem - 1].chave;
  else
    return ERRO; // lista vazia
} 

/* Retornar a chave do elemento que está na posição n da LISTA */
TIPOCHAVE enesimoElem(LISTA *l, int n)
{
  if ((n >= 0) && (n < l->nroElem))
    return l->A[n].chave;
  else
    return ERRO;
} 

/* Reinicializar a estrutura */
void reinicializarLista(LISTA *l)
{
  free(l->A); // Libera a memória alocada
  l->A = NULL;
  l->nroElem = 0;
  l->capacidade = 0;
} 

/* Busca sequencial em lista ordenada ou não SEM SENTINELA */
int buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
  int i = 0;
  while (i < l->nroElem)
  {
    if (ch == l->A[i].chave)
      return i; // achou
    else
      i++;
  }
  return ERRO; // não achou
}

/* Busca sequencial em lista COM SENTINELA */
int buscaSentinela(LISTA *l, TIPOCHAVE ch)
{
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while (l->A[i].chave != ch)
    i++;
  if (i > l->nroElem - 1)
    return ERRO; // não achou
  else
    return i;
}

/* Busca sequencial em lista COM SENTINELA considerando o arranjo ordenado */
int buscaSentinelaOrdenada(LISTA *l, TIPOCHAVE ch)
{
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while (l->A[i].chave < ch)
    i++;
  if (i == l->nroElem || l->A[i].chave != ch)
    return ERRO; // não achou
  else
    return i;
}

/* Busca binária em lista ordenada */
int buscaBinaria(LISTA *l, TIPOCHAVE ch)
{
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem - 1;
  while (esq <= dir)
  {
    meio = ((esq + dir) / 2);
    if (l->A[meio].chave == ch)
      return meio; // achou
    else
    {
      if (l->A[meio].chave < ch)
        esq = meio + 1;
      else
        dir = meio - 1;
    }
  }
  return ERRO;
} 

/* Exclusão do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA *l, TIPOCHAVE ch)
{
  int pos, j;
  pos = buscaSequencial(l, ch);
  if (pos == ERRO)
    return false; // não existe
  for (j = pos; j < l->nroElem - 1; j++)
    l->A[j] = l->A[j + 1];
  l->nroElem--;

  // Redimensiona a lista após a exclusão, se necessário
  resize(l);
  return true;
} 

/* Exclusão do elemento cuja chave seja igual a ch em lista ordenada */
bool excluirElemListaOrd(LISTA *l, TIPOCHAVE ch)
{
  int pos, j;
  pos = buscaBinaria(l, ch);
  if (pos == ERRO)
    return false; // não existe
  for (j = pos; j < l->nroElem - 1; j++)
    l->A[j] = l->A[j + 1];
  l->nroElem--;

  // Redimensiona a lista após a exclusão, se necessário
  resize(l);
  return true;
} 

/* Inserção em lista ordenada usando busca binária permitindo duplicação */
bool inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
  if (l->nroElem >= l->capacidade || l->nroElem <= (l->capacidade/4))
    resize(l); // Redimensiona se a capacidade for atingida, e também se estiver sendo usado muito pouco espaço.
  int pos = l->nroElem;
  while (pos > 0 && l->A[pos - 1].chave > reg.chave)
  {
    l->A[pos] = l->A[pos - 1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
}

/* Inserção em lista ordenada usando busca binária sem duplicação */
bool inserirElemListaOrdSemDup(LISTA *l, REGISTRO reg)
{
  if (l->nroElem >= l->capacidade)
    resize(l); // Redimensiona se a capacidade for atingida
  int pos = buscaBinaria(l, reg.chave);
  if (pos != ERRO)
    return false; // elemento já existe
  pos = l->nroElem - 1;
  while (pos > 0 && l->A[pos].chave > reg.chave)
  {
    l->A[pos + 1] = l->A[pos];
    pos--;
  }
  l->A[pos + 1] = reg;
  l->nroElem++;
  return true;
} 
