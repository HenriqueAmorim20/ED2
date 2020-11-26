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

void quickselect(Item *V, int l, int r, int k)
{

    int i;
    if (r <= l)
        return;
    i = separa(V, l, r);

    if (i > k)
        quickselect(V, l, i - 1, k);
    if (i < k)
        quickselect(V, l, i + 1, k);
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

    int n, p, x, primeiro, ultimo, menor1, menor2, h = 0, temp, j, l = 0;
    scanf("%d %d %d\n", &n, &p, &x);
    Item *V = malloc(sizeof(int) * n), *Vfinal = malloc(sizeof(int) * x);
    for (int i = 0; i < n; i++)
        scanf("\n%d", &V[i]);
    primeiro = p * x;
    ultimo = primeiro + x - 1;

    if (ultimo > n - 1)
    {

        for (int i = primeiro; i < n; i++)
        {
            quickselect(V, l, n - 1, i);
        }
    }
    else
    {
        for (int i = primeiro; i < ultimo; i++)
        {
            quickselect(V, l, n - 1, i);
        }
    }

    if (ultimo > n - 1)
    {   
        for (int j = 0; j < x; j++, primeiro++)
        {
            if (primeiro == n)
                break;
            Vfinal[j] = V[primeiro];
        }
        quicksort(Vfinal, 0, n-primeiro);
        for (int i = 0; i < n-(p*x); i++)
        {

            printf("%d\n", Vfinal[i]);
        }
    }
    else
    {

        for (int j = 0; j < x; j++, primeiro++)
        {
            Vfinal[j] = V[primeiro];
        }
        quicksort(Vfinal, 0, x);
        for (int i = 0; i <= x; i++)
        {

            printf("%d\n", Vfinal[i]);
        }
    }




    return 0;
}
