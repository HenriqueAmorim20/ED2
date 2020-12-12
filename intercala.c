#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A)<Key(B))
#define exch(A,B) {int T=A;A=B;B=T;}
#define cmpexch(A,B) {if(less(A,B))exch(A,B);}

void merge(Item *V, int l, int r1, int r2){ 

    Item *V2;
    V2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0,i=l,j=r1+1;
   // printf("l: %d, k: %d, i: %d, j: %d, r1: %d, r2: %d\n", l,k,i,j,r1,r2);

    while(i<=r1&&j<=r2){
        if(less(V[i],V[j]))
            V2[k++]=V[i++];
        else V2[k++]=V[j++];
    }

    while(i<=r1) V2[k++]=V[i++];
    
    while(j<=r2) V2[k++]=V[j++];

    k=0;

    for(i=l;i<=r2;i++) {    
    V[i]=V2[k++];
   // printf("V2[%d]:%d, V[%d]:%d\n",i,V2[k],i,V[k]);

    }
    
    free(V2);
    
    
}

void mergesort(Item *V, int l, int r){
    
    if(l>=r) return;
    int meio = (r+l)/2;
    mergesort(V, l, meio);
    mergesort(V, meio+1, r);
    merge(V,l,meio,r);

}


int main(){
    
    Item V[800001] = {}, l=0, r=0,n,pos=0;

    for(int i=0;i<8;i++){
        scanf("\n%d", &n);
        for(int j=0;j<n;j++){
            scanf(" %d",&V[pos++]);
        }
    }    

    mergesort(V,l,pos-1);

    for(int i = 0 ; i <pos ; i++){

        if(i==pos-1) printf("%d\n", V[i]);
        else printf("%d ", V[i]);

    }

    return 0;
}


