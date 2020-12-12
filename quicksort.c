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

int separa(Item *V, int l, int r)
{

    Item c = V[r];
    int j = l;

    for (int k = l; k < r; k++)
    {
        if (less(V[k], c))
        {
            exch(V[k], V[j]);
            j++;
        }
    }
    exch(V[j], V[r]);
    return j;
}

void quicksort(int *V, int l, int r)
{

    int j;
    if (r <= l)
        return;

    cmpexch(V[r], V[(r + l) / 2]);
    cmpexch(V[(r + l) / 2], V[l]);
    cmpexch(V[(r + l) / 2], V[r]);

    j = separa(V, l, r);
    quicksort(V, l, j - 1);
    quicksort(V, j + 1, r);
}

int main()
{

    Item V[100000] = {}, l = 0, r = 0;

    scanf("%d\n", &r);
    for (int i = 0; i < r; i++)
        scanf("\n %d", &V[i]);
    quicksort(V, l, r - 1);
    for (int h = 0; h < r; h++)
    {
        if (h == r - 1)
            printf("%d\n", V[h]);
        else
            printf("%d ", V[h]);
    }

    return 0;
}
