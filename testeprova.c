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

  int separa( Item *v, int p, int r) {
     int q, i, j, t;
     i = p; q = (p + r) / 2; j = r;
     printf("i:%d q:%d j:%d\n\n\n", i,q,j);
     do {
        while (v[i] < v[q]) {
++i;
printf("i:%d q:%d j:%d\n", i,q,j);

        }
        while (v[j] > v[q]) {
--j;
printf("i:%d q:%d j:%d\n", i,q,j);
        }
       
        if (i <= j) {
           t = v[i], v[i] = v[j], v[j] = t;
           ++i, --j;
        }
     } while (i <= j);
     return i-1;
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

    Item V[100000] = {}, l = 0, r = 0,j;

    scanf("%d\n", &r);
    for (int i = 0; i < r; i++)
        scanf("\n %d", &V[i]);
    j = separa(V, l, r - 1);
    printf("jaa:%d\n",j);
    for (int h = 0; h < r; h++)
    {
        if (h == r - 1)
            printf("%d\n", V[h]);
        else
            printf("%d ", V[h]);
    }

    return 0;
}
