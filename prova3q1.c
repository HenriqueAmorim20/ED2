#include <stdio.h>
#include <stdlib.h>
 
typedef struct node* link;
typedef struct graph* Graph; 
typedef struct{
    int v;
    int w;
}Edge;

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

int cnt, pre[5000];

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

int Graphedges(Edge a[],Graph G){
    int v, E=0;
    link t;
    for(v=0;v<G->V;v++)
        for(t=G->adj[v];t!=NULL;t=t->next)
            if(v<t->v) a[E++] = EDGE(v,t->v);
    return E;
}

void dfsr(Graph G, Edge e){

    int t, w = e.w;
    link l;
    pre[w]=cnt++;
    for(l=G->adj[w];l!=NULL;l=l->next){
        t=l->v;
        if(pre[t]==-1) dfsr(G,EDGE(w,t));
    }

}

int Graphsearch(Graph G){

    int v, conexos=0;
    cnt=0;
    for(v=0;v<G->V;v++) pre[v]=-1;
    for(v=0;v<G->V;v++){
        if(pre[v]==-1){
            dfsr(G,EDGE(v,v));
            conexos++;
        }
    }
    return conexos;

}



int main(){

    int V,v,w, i=0;
    scanf("%d", &V);
    getchar();
    Edge e;
    Graph G = Graphinit(V);
    while(scanf("%d %d", &v, &w)!=EOF) {
        getchar();
        e = EDGE(v,w);
        Graphinsert(G,e);
    }
    printf("%d\n", Graphsearch(G));

    return 0;
}
