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

};

int pre[2001];

Graph Graphinit(int N){

    Graph G = malloc(sizeof(*G));
    G->V=N;
    G->E=0;

    int **mat = (int **)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++)
        mat[i] = (int *)malloc(N * sizeof(int));

    for(int i=0; i<N;i++)
         for(int j=0;j<N;j++)
            mat[i][j]=0;

    G->adj = mat; 
       
    return G;

}

void Graphinsert(Graph G, Edge e){
    
    int v = e.v , w = e.w;  
    if(G->adj[v][w]==0) G->E++;

    G->adj[v][w]=1;
    G->adj[w][v]=1;

} 



int main(int argc, char const *argv[]){

    int N, M, J, A, v, w, input, y, temp,j,k,h,i,z;
    Graph G;
    Edge e;
      
    scanf("%d %d %d", &N, &M, &J);
    getchar();

    G = Graphinit(N);
    for(v=0;v<G->V;v++) pre[v]=-1;
    

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
        
    for( k = 0 ; k < M ; k++) {

        scanf("%d", &temp);
        getchar();  
        pre[temp]=0;
        for( v = 0 ; v < G->V ; v++){

            if(G->adj[temp][v]==1) pre[v] = 0;

        }

    }  

    for( h = 0 ; h < J ; h++) {

          scanf("%d",&input);
          getchar();

          if(pre[input]!=-1) printf("Eu vou estar la\n");

          else printf("Nao vou estar la\n");

    }

    return 0;

}
