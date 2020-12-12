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

typedef struct
{
    int nota;
    int codigo;

} semente;

int separa(Item *V, int l, int r)
{

    Item c = V[r].nota;
    int j = l;

    for (int k = l; k < r; k++)
    {
        if (less(V[k].nota, c))
        {
            exch(V[k].nota, V[j].nota);
            j++;
        }
    }
    exch(V[j].nota, V[r].nota);
    return j;
}

void quicksort(int *V, int l, int r)
{

    int j;
    if (r <= l)
        return;

    cmpexch(V[r].nota, V[(r + l) / 2].nota);
    cmpexch(V[(r + l) / 2].nota, V[l].nota);
    cmpexch(V[(r + l) / 2].nota, V[r].nota);

    j = separa(V, l, r);
    quicksort(V, l, j - 1);
    quicksort(V, j + 1, r);
}

int main()
{

    int n, i = 0;
    scanf("%d", &n);
    semente *Vfinal = malloc(sizeof(semente) * n);
    semente V[1000001] = {};

    while (scanf("\n%d %d", &V[i].codigo, &V[i].nota) != EOF) i++;

    quicksort(V,0,i-1);

    printf("\ni:%d\n\n",i);

    for (int j = 0; j < i; j++)
    {
        printf("V[%d]: \n", j, V[j]);
    }

    return 0;
}