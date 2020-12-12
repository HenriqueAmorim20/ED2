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

int cnt, pre[5000];
int qtd=1;
void setqtd(int n){
    qtd=n;  
} 
int getqtd(){
    return qtd;
} 


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
            dfsr(G,EDGE(w,t));
            setqtd(getqtd()+1);
        }
    }

}


int Graphsearch(Graph G, int J, Conexus *conexus ){

    int v, conexos=0;
    cnt=0;
    for(v=0;v<G->V;v++) pre[v]=-1;

    dfsr(G,EDGE(J,J));
    conexus[conexos].qtd = getqtd();
    conexus[conexos].vertice = J;
    conexus[conexos].contem = 1;
    setqtd(1); 
    conexos++;


    for(v=0;v<G->V;v++){
        if(pre[v]==-1){
                dfsr(G,EDGE(v,v));
                conexus[conexos].qtd = getqtd();
                conexus[conexos].vertice = v;
                conexus[conexos].contem = 0;        
                conexos++;              
        }
        setqtd(1);
    }
    return conexos;
}


int main(){

    int V,v,w, i=0, J;
    scanf("%d %d", &V, &J);
    getchar();
    Graph G = Graphinit(V);
    while(scanf("%d %d", &v, &w)!=EOF) {
        getchar();
        Edge e = EDGE(v,w);
        Graphinsert(G,e);
    }
    Conexus conexus[5000];
    int n =  Graphsearch(G, J, conexus);

    int maiorqtd=1, menorvertice= V, temp, fconex=0;
    for(int j = 0 ; j < n ; j++){
        if(conexus[j].qtd>maiorqtd){
            fconex=j;
            maiorqtd = conexus[j].qtd;
            menorvertice = conexus[j].vertice;
        } else if(conexus[j].qtd==maiorqtd){
            if(conexus[fconex].contem==1){
                
            }
            else if(conexus[j].vertice < menorvertice){
                fconex=j;
                menorvertice = conexus[j].vertice;
            } 
        }

    }
    if (conexus[fconex].contem==1 && conexus[fconex].qtd==1) printf("Fique em casa\n");
    else if(conexus[fconex].contem==1) printf("Bora pra estrada\n");
    else printf("Vamos para %d\n", conexus[fconex].vertice);

    return 0;
}
