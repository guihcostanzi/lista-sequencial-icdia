// main.c
#include "ListaOrdenada.h"
#include "ListaOrdenada.c"

int main() {
  LISTA lista;
  REGISTRO reg;

  // Inicializar a lista
  inicializarLista(&lista);

  // Exibir lista vazia

  printf("\n-- Lista inicial -- \n\n");

  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Inserir elementos na lista e mostrar valores e tamanhos

  printf("\n-- Inserindo elementos e acompanhamento da lista --\n");

  reg.chave = 9;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  reg.chave = 3;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  reg.chave = 4;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  reg.chave = 1;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  reg.chave = 12;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  reg.chave = 19;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  printf("\n-- Observe o aumento da capacidade a partir desse ponto:  \n");
  reg.chave = 50;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  reg.chave = 52;
  printf("\nAdicionando elemento ... \n");
  inserirElemListaOrd(&lista, reg);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Buscar um elemento na lista

  printf("\n-- Buscando elementos na lista -- \n\n ");

  int pos = buscaSequencial(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaBinaria(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaSentinela(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);

  // Excluir alguns elementos da lista

  printf("\n-- Excluindo elementos da lista -- \n\n");

  if (excluirElemLista(&lista, 4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista, 8)) printf("Exclusao bem sucedida: 8 (não existe na lista).\n");
  if (excluirElemLista(&lista, 9)) printf("Exclusao bem sucedida: 9.\n");
  if (excluirElemLista(&lista, 19)) printf("Exclusao bem sucedida: 19.\n");
  if (excluirElemLista(&lista, 50)) printf("Exclusao bem sucedida: 50.\n");
  if (excluirElemLista(&lista, 52)) printf("Exclusao bem sucedida: 52.\n");

  // Exibir lista após exclusões

  printf("\n-- Novo status da lista depois de excluir os elementos --\n\n");

  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Reinicializar a lista
  printf("\n-- Reinicializando a lista --\n\n");
  reinicializarLista(&lista);
  exibirLista(&lista);
  printf("Capacidade da lista: %i.\n", capacidade(&lista));
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  printf("\n\nATENCAO: Depois de reiniciar a lista, ocorre o uso da funcao free para liberar o espaco alocado na memoria.\n\n");

  return 0;
}
