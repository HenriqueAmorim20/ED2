#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A)<Key(B))
#define exch(A,B) {int T=A;A=B;B=T;}
#define cmpexch(A,B) {if(less(A,B))exch(A,B);}
void bubblesort();


int main(int argc, char const *argv[]){
    
    Item V[5]= {-40,3230,130,-3220,1235};
    int l=0, r=4;
    bubblesort(V, l, r);
    for(int i=0;i<5;i++){
        printf(" %d", V[i]);
    }
    printf("\n");

    return 0;
}

void bubblesort(Item *V, int l, int r){

    for(int j = l; j<r;j++){
        for(int i=l; i <r ; i++){

        cmpexch(V[i+1],V[i]);

    }
    }
    return;
}