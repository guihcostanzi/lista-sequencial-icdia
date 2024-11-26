# Descritivo da Implementação - Lista Sequencial Dinâmica

### Alterações realizadas

1. Alteração do atributo A que estava definido de forma estática para um ponteiro;
2. Adequação das funções que envolviam esse atributo estático, seguindo o novo modelo adotado;
3. Implementação de função resize;
  - Quando ocorre inserção, checa se o número de elementos atingiu a capacidade máxima. Se sim, dobra a capacidade da lista;
  - Quando ocorre inserção, checa se o número de elementos é menor que 25% da capacidade da lista, se sim, reduz a capacidade pela metade;
  - Quando ocorre exclusão, faz a mesma checagem, e também reduz a capacidade pela metade caso a condição seja atendida;
4. Implementação de função capacidade(), que retorna a capacidade da lista;
5. Adequações e melhorias no arquivo de testes para melhor acompanhamento da lista e de seu comportamento pelo terminal;
  - Divisão por setores e ações;
  - Status da lista a medida que cada etapa acontece;
  - Indicativos de resize() para verificação do comportamento dinâmico da lista;

### Descrição Geral da Lista

Programa implementado em Linguagem C, que contém a implementação de uma lista sequencial dinâmica;
  - Atributos da lista:
    
      ```
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
      ```
  - Capacidade inicial da lista: 50;
  - Aplicação da função resize após cada operação de inserção e exclusão;
  - Função de inicialização (Iniciar a lista para que se possa operar sobre ela):
    
      ```
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
      ```
  - Função de reinicialização (Liberar o espaço na memória e limpar a lista, utilização de função free()):
    
      ```
     /* Reinicializar a estrutura */
      void reinicializarLista(LISTA *l)
      {
        free(l->A); // Libera a memória alocada
        l->A = NULL;
        l->nroElem = 0;
        l->capacidade = 0;
      } 

      ```
