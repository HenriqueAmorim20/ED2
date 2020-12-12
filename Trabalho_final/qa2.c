#include <stdio.h>
#include <stdlib.h>
 
typedef struct node* link;
typedef struct graph* Graph; 
typedef struct{
    int v;
    int w;
}Edge;
typedef struct{
    int qtd, vertice, contem;
}Conexus;

Edge EDGE(int v, int w){
    Edge e = {v,w};
    return e;
}
   
struct node{
    int v;
    link next;
};

struct graph{
    int V, E;
    link* adj;
};

int cnt, pre[2001];

link new(int v, link next){
    link x = malloc(sizeof(*x));
    x->v=v;
    x->next=next;
    return x;
}

Graph Graphinit(int V){
    int v;
    Graph G = malloc(sizeof(*G));
    G->V=V;
    G->E=0;
    G->adj = malloc(V*sizeof(link));
    for(v=0;v<V;v++) G->adj[v] = NULL;
    return G; 
}

void Graphinsert(Graph G, Edge e){
    int v = e.v, w = e.w;
    G->adj[v] = new(w,G->adj[v]);
    G->adj[w] = new(v,G->adj[w]);
    G->E++;
}

void dfsr(Graph G, Edge e){

    int t, w = e.w;
    link l;
    pre[w]=cnt++;
    for(l=G->adj[w];l!=NULL;l=l->next){
        t=l->v;
        if(pre[t]==-1) {
            pre[t] = cnt++;
        }
    }

}


int main(int argc, char const *argv[]){

    int N, M, J, A, v, w, input,j,k,h,i,z,temp;
    int *V, *V2;
    Graph G;
    Edge e;
      
    scanf("%d %d %d", &N, &M, &J);
    getchar();

    G = Graphinit(N);   

    for( i = 0 ; i < N ; i++ ){

        scanf("%d", &A);
        for( j = 0 ; j < A ; j++){
             
             scanf(" %d", &w);
             v = i;
             e = EDGE(v,w);
             Graphinsert(G, e);
        
        }
        getchar();

    }

    for(v=0;v<N;v++) pre[v]=-1;

    for( k = 0 ; k < M ; k++){

        scanf("%d", &temp);
        getchar();
        dfsr(G, EDGE(temp,temp));

    } 

    for( h = 0 ; h < J ; h++) {

          scanf("%d",&input);
          getchar();

          if(pre[input]!=-1) printf("Eu vou estar la\n");

          else printf("Nao vou estar la\n");

    }

    return 0;

}
