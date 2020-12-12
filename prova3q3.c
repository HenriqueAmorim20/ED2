#include <stdio.h>
#include <stdlib.h>
 
typedef struct graph* Graph; 
typedef struct{
    int v;
    int w;
}Edge;

Edge EDGE(int v, int w){
    Edge e = {v,w};
    return e;
}

struct graph{
    
    int V;
    int E;
    int **adj;
    int **tc;  

};

Graph Graphinit(int V){

    Graph G = malloc(sizeof(*G));
    G->V=V;
    G->E=0;

    int **mat = (int **)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++)
        mat[i] = (int *)malloc(V * sizeof(int));

        
    int **mat2 = (int **)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++)
        mat2[i] = (int *)malloc(V * sizeof(int));

    for(int i=0; i<V;i++)
         for(int j=0;j<V;j++)
            mat[i][j]=0;

    G->adj = mat; 
    G->tc = mat2; 
       
    return G;

}

void Graphinsert(Graph G, Edge e, int d){
    
    int v = e.v , w = e.w;  
    if(G->adj[v][w]==0) G->E++;

    G->adj[v][w]=1;
    if(d==2)
    G->adj[w][v]=1;

} 

void Graphtc(Graph G, int V){

    int i, s, t;

    for(s=0;s<G->V;s++)
        for(t=0;t<G->V;t++)
            G->tc[s][t]=G->adj[s][t];

    for(s=0;s<G->V;s++) G->tc[s][s]=1;

    for(i=0;i<G->V;i++)
        for(s=0;s<G->V;s++)
            if(G->tc[s][i]==1)
                for(t=0;t<G->V;t++)
                    if(G->tc[i][t]==1) G->tc[s][t]=1;

}

int Graphreach(Graph G, int s, int t){
    return G->tc[s][t];
}

int main(int argc, char const *argv[]){

    int V,v=1,w=1, d=1,t,x;
    scanf("%d", &V);
    getchar();
    Edge e;
    Graph G = Graphinit(V);
    for(;;){
        scanf("%d %d %d", &v, &w, &d);
        getchar();
        if(v==0&&w==0&&d==0) break;
        e = EDGE(v,w);              
        Graphinsert(G, e, d);
    }

    Graphtc(G,V);

    while(scanf("%d %d", &t, &x)!=EOF){
        getchar();
        int ida = Graphreach(G,t,x) , volta = Graphreach(G,x,t);
        if(ida == 1 && volta == 1){
            printf("Ida e Volta\n");
        }else if (ida == 1 && volta == 0){
            printf("Apenas Ida\n");
        }else if (ida == 0 && volta == 1){
            printf("Apenas Volta\n");
        }else if (ida == 0 && volta == 0){
            printf("Impossibru\n");
        }

    }

    return 0;

}
