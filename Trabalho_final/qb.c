#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int nota;
    int codigo;

} semente;
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

int partition(semente *V, int l, int r)
{

    int c = V[r].nota;
    int n = V[r].codigo;
    int j = l;

    for (int k = l; k < r; k++)
    {
        if (less(V[k].nota, c))
        {
            exch(V[k].nota, V[j].nota);
            exch(V[k].codigo, V[j].codigo);
            j++;
        } 
        if(V[k].nota==c && V[k].codigo<n){

            exch(V[k].nota, V[j].nota);
            exch(V[k].codigo, V[j].codigo);
            j++;
                 
        }
    }
    exch(V[j].nota, V[r].nota);
    exch(V[j].codigo, V[r].codigo);
    return j;

}

int partition2(semente *V, int l, int r)
{

    int c = V[r].nota;
    int n = V[r].codigo;
    int j = l;

    for (int k = l; k < r; k++)
    {
        if (less(V[k].codigo, n))
        {
            exch(V[k].nota, V[j].nota);
            exch(V[k].codigo, V[j].codigo);
            j++;
        } 
    }
    exch(V[j].nota, V[r].nota);
    exch(V[j].codigo, V[r].codigo);
    return j;

}



void quicksort(semente *V, int l, int r){

    int j;
    if (r <= l)
        return;

    if(less(V[r].codigo, V[(r+l)/2].codigo)){

        exch(V[r].codigo, V[(r+l)/2].codigo);
        exch(V[r].nota, V[(r+l)/2].nota);

    }
    if(less(V[(r+l)/2].codigo, V[l].codigo)){

        exch(V[(r+l)/2].codigo, V[l].codigo);
        exch(V[(r+l)/2].nota, V[l].nota);

    }
    if(less(V[(r+l)/2].codigo, V[r].codigo)){

        exch(V[(r+l)/2].codigo, V[r].codigo);
        exch(V[(r+l)/2].nota, V[r].nota);

    }


    j = partition2(V, l, r);
    quicksort(V, l, j - 1);
    quicksort(V, j + 1, r);

}

void quickselect(semente *A, int left, int right, int k){

    int p = partition(A, left, right);
    if (p == k-1) return;
    else if (k - 1 < p) return quickselect(A, left, p - 1, k);
    else return quickselect(A, p + 1, right, k);

}


int main(){

    int n, i = 0, k;

    scanf("%d\n", &k);

    semente V[10000001];

    while (scanf("%d %d\n", &V[i].codigo, &V[i].nota) != EOF) i++;

    clock_t tic = clock();

    quickselect(V, 0, i-1, k);

    quicksort(V,0,k-1);

    clock_t toc = clock();

   // printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    for (int j = 0; j < k; j++) printf("%d %d\n", V[j].codigo,V[j].nota);

    return 0;
}