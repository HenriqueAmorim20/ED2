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
         for(int j=0;j<V;j++){
             mat2[i][j]=0;
             mat[i][j]=0;
         }
            
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

    int V, J,v ,w, p, t, x;

    for(;;){
        repeat:
        scanf("%d %d", &V, &J);   
        getchar();

        if(V==0) break;
    

        Edge e;
        Graph G = Graphinit(V);
        

        for(int i = 0 ; i < J ; i++){

            scanf("%d %d %d", &v, &w, &p);
            getchar();

            e = EDGE(v-1,w-1);

            Graphinsert(G, e, p); 

        }
        Graphtc(G,V);
        
        for(int i = 0 ; i < V ; i++){

            for(int j = 0 ; j < V ; j++){

                if(j!=i)
                    
                    if(Graphreach(G,i,j)==0) {
                        printf("0\n");
                        goto repeat;
                    }

            }
            
        }
     printf("1\n");
    }
   
    return 0;

}
