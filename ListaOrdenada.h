#ifndef LISTA_SEQUENCIAL_ORDENADA_H
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdio.h>
#include <stdlib.h> // Para malloc, realloc, free

#define ERRO -1
#define bool int
#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
  REGISTRO *A;    // Ponteiro para os elementos da lista
  int nroElem;    // Número de elementos atuais na lista
  int capacidade; // Capacidade atual da lista
} LISTA;

// Declaração das funções
void inicializarLista(LISTA *l);
void exibirLista(LISTA *l);
int tamanho(LISTA *l);
int capacidade(LISTA *l);
void reinicializarLista(LISTA *l);
int buscaSequencial(LISTA *l, TIPOCHAVE ch);
int buscaSentinela(LISTA *l, TIPOCHAVE ch);
int buscaBinaria(LISTA *l, TIPOCHAVE ch);
bool excluirElemLista(LISTA *l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA *l, REGISTRO reg);

// Funções de redimensionamento para a atividade proposta.
void resize(LISTA *l);

#endif // LISTA_SEQUENCIAL_ORDENADA_H
