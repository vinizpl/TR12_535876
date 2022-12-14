#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP *HEAP_create(int n, COMP *compara)
{
    HEAP *heap = malloc(sizeof(HEAP));        // aloca o tamanho do ponteiro na memoria
    heap->comparador = compara;               // comparador recebe a funcao de compara
    heap->N = n;                              // recebe o tamanho do vetor
    heap->P = 0;                              // P recebe o valor 0
    heap->elems = malloc(n * sizeof(void *)); // aloca memoria para o vetor de elementos
    for (int i = 0; i < n; i++)
        heap->elems[i] = NULL; // todas as casas do vetor recebe o valor NULL

    return heap; // retorna um ponteiro para  HEAP
}

void HEAP_add(HEAP *vetor, void *newelem)
{ // adiciona ao HEAP
    if (vetor->P < vetor->N)
    { // se o valor p for menor q N então o if é realizado
        if (vetor->P == 0)
        {                              // se P for 0 então
            vetor->elems[0] = newelem; // ele adiciona na primeira casa
            vetor->P++;                // P soma mais um
        }
        else
        {
            vetor->elems[vetor->P] = newelem; // o newelem vai pra ultima casa oculpada
            vetor->P++;                       // P soma mais um
            for (int i = vetor->P - 1; i > 0; i = i / 2)
            { // ira se repetir enquanto o menor não for encontrado
                if (vetor->comparador(vetor->elems[i], vetor->elems[i / 2]) == 1)
                {                                          // se vetor->elems[i] for menor que vetor->elems[i/2])
                    void *aux = vetor->elems[i];           // um endereço auxiliar
                    vetor->elems[i] = vetor->elems[i / 2]; // vetor->elems[i] vira vetor->elems[i/2];
                    vetor->elems[i / 2] = aux;             // vetor->elems[i/2] recebe o endereço do auxiliar
                }
            }
        }
    }
}

void descer(HEAP *veto, int pos)
{
    int P = pos;                   // int com valor 0
    int N = veto->P;               // int com o valor de veto->P
    void **vet = veto->elems;      // ponteiro pra veto->elems
    COMP *comp = veto->comparador; // ponteiro pra veto->comparador

    if (2 * P < N)
    {                    // se o dobro de P for menor que N então
        int son = 2 * P; // int pra o filho da heap recebe 2 multiplicado com P
        if (2 * P + 1 < N)
        { // se filho somado a 1 for menor que N então
            if (comp(vet[2 * P], vet[2 * P + 1]) == 1)
                son = 2 * P; // se vet[2*P] for menor que vet[2*P+1]) o son recebe 2*P
            else
                son = 2 * P + 1; // senão ele recebe 2*P+1
        }
        if (comp(vet[son], vet[P]) == 1)
        {                         // se vet[son] for menor que vet[P] então
            void *aux = vet[son]; // o auxiliar recebe vet[son]
            vet[son] = vet[P];    // o vet[son] recebe o valor de vet[P]
            vet[P] = aux;         // e o vet[P] recebe o ponteiro do aux
            descer(veto, son);    // e chama o void descer dnv
        }
    }
}

void *HEAP_remove(HEAP *vetor)
{
    void *aux = vetor->elems[0];                  // um auxiliar pra entcontrar o endereço
    vetor->elems[0] = vetor->elems[vetor->P - 1]; // vetor->elems[0] recebe o penultimo valor
    vetor->elems[vetor->P - 1] = aux;             // o penultimo recebe o ponteiro aux
    vetor->P--;                                   // valor p do vetorord remove um
    descer(vetor, 0);                             // chama a void descer
    void *ret = vetor->elems[vetor->P];           // o ponteiro ret recebe o valor de vetor->elems[vetor->P]

    return ret; // retorna um ponteiro para o elemento que foi removido do vetor
}