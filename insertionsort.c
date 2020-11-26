//O Insertion sort é um algoritmo simples e eficiente quando aplicado em pequenas listas. Neste algoritmo a lista é percorrida da esquerda para a direita, à medida que avança vai deixando os elementos mais à esquerda ordenados.
//O algoritmo funciona da mesma forma que as pessoas usam para ordenar cartas em um jogo de baralho como o pôquer.
//No caso desse código o algoritmo faz um primeiro loop para colocar o menor elemento do vetor na primeira posição

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

void insertionsort(Item *V, int l, int r)
{

    int i, j;
    int temp;

    for (i = r; i > l; i--)
        cmpexch(V[i], V[i - 1]);

    for (i = l + 1; i <= r; i++)
    {
        j = i;
        temp = V[j];

        while (less(temp, V[j - 1]))
        {

            V[j] = V[j - 1];
            j--;
        }

        V[j] = temp;
    }
}
int main()
{

    Item V[50001] = {}, l = 0, r = 0;

    while (scanf("\n%d", &V[r]) == 1)
        r++;
    insertionsort(V, l, r - 1);
    for (int h = 0; h < r; h++)
    {
        if (h == r - 1)
            printf("%d\n", V[h]);
        else
            printf("%d ", V[h]);
    }

    return 0;
}
