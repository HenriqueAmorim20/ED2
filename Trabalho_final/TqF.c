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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(int *A, int left, int right){
    int pivot = A[right], i = left, x;
    for (x = left; x < right; x++){
        if (A[x] <= pivot){
            swap(&A[i], &A[x]);
            i++;
        }
    }
    swap(&A[i], &A[right]);
    return i;
}

void quicksort(int *V, int l, int r)
{

    int j;
    if (r <= l)
        return;

    cmpexch(V[r], V[(r + l) / 2]);
    cmpexch(V[(r + l) / 2], V[l]);
    cmpexch(V[(r + l) / 2], V[r]);

    j = partition(V, l, r);
    quicksort(V, l, j - 1);
    quicksort(V, j + 1, r);
}
 
void quickselect(int *A, int left, int right, int k){
    int p = partition(A, left, right);
    if (p == k-1) return;
    else if (k - 1 < p) return quickselect(A, left, p - 1, k);
    else return quickselect(A, p + 1, right, k);
}
 
int main(){
    int n, p, x, primeiro, ultimo, menor1, menor2, h = 0, temp, j, l = 0;
    scanf("%d", &n);
    scanf(" %d", &p);
    scanf(" %d", &x);
    getchar();
    if(n==0) return 0;
    Item *V = malloc(sizeof(int) * n), *Vfinal = malloc(sizeof(int) * x);
    for (int i = 0; i < n; i++) scanf("\n%d", &V[i]);  
    primeiro = p * x;
    ultimo = primeiro + x - 1;
    if(ultimo > n-1 ){
        quickselect(V,0, n-1, primeiro+1);
        int i;
        for(i = 0, j = primeiro ; j < n ; i++, j++){
        Vfinal[i] = V[j];
        }
        quicksort(Vfinal,0,i-1);
        for(int j=0;j<i;j++) printf("%d\n",Vfinal[j]);
    } else{
        quickselect(V,0, n-1, primeiro+1);
        quickselect(V,primeiro, n-1, ultimo+1);
        for(int i = 0, j = primeiro ; i < x ; i++, j++){
        Vfinal[i] = V[j];
        }
        quicksort(Vfinal, 0 ,x-1);
        for(int j=0;j<x;j++) printf("%d\n", Vfinal[j]);
    }


       
    return 0;
}



