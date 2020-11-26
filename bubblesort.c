//Bubble sort é o algoritmo mais simples, mas o menos eficientes. Neste algoritmo cada elemento da posição i será comparado com o elemento da posição i + 1, ou seja, um elemento da posição 2 será comparado com o elemento da posição 3. Caso o elemento da posição 2 for maior que o da posição 3, eles trocam de lugar e assim sucessivamente. Por causa dessa forma de execução, o vetor terá que ser percorrido quantas vezes que for necessária, tornando o algoritmo ineficiente para listas muito grandes.

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) \
    {              \
        int T = A; \
        A = B;     \
        B = T;     \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(A, B)) \
            exch(A, B); \
    }
#define N 6

void bubblesort(Item *V, int l, int r)
{
    int j, i;
    for (i = l; i < r; i++)
    {
        for (j = l; j < r; j++)
        {
            cmpexch(V[j + 1], V[j]);
        }
    }
}

int main()
{

    Item V[N] = {350, 0, 2534, 5, 320, 35}, l = 0, r = N - 1;
    bubblesort(V, l, r);
    for (int h = 0; h < N; h++)
    {
        printf(" V[%d]: %d", h, V[h]);
    }
    printf("\n");

    return 0;
}
