#include <stdio.h>
#include <stdlib.h>
 
typedef struct node* link;
typedef struct graph* Graph; 
typedef struct{
    int v;
    int w;
}Edge;
typedef struct{
    int qtd, vertice;
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


int Graphsearch(Graph G, Conexus *conexus ){

    int v, conexos=0;
    cnt=0;
    for(v=0;v<G->V;v++) pre[v]=-1;

    for(v=0;v<G->V;v++){
        if(pre[v]==-1){
                dfsr(G,EDGE(v,v));
                conexus[conexos].qtd = getqtd();
                conexus[conexos].vertice = v;       
                conexos++;              
        }
        setqtd(1);
    }
    return conexos;
}


int main(){

    int V,v,w, i=0, ed, tamanho;
    char c, input1[30], input2[30];
    
    for(;;){

    scanf("%d %d", &V, &ed);
    getchar();
    if(V==ed && V==0) break;

    Edge e;
    Graph G = Graphinit(V);

    char **bichos = (char **)malloc(V * sizeof(char*));
    for(int j = 0; j < V; j++) bichos[j] = (char *)malloc(30 * sizeof(char));
        
    for (int j = 0 ; j < V ; j++)
        for(int k = 0 ; k < 30 ; k++){
             scanf("%c", &c);
             if(c=='\n') {
                 bichos[j][k] = c;
                 break;
             }
             else bichos[j][k] = c;
        }

    /*tamanho=0;
    for (int j = 0 ; j < V ; j++){
        for(int k = 0; k < 30 ; k++){

        if(bichos[j][k]=='\n') break;
        else {
            tamanho++;
            printf("%c", bichos[j][k]);
        }
    }
        printf("\ntamanho %d: %d\n", j, tamanho);
        tamanho =0;
    }*/
        
                 

    
    for(int j = 0 ; j < ed ; j++) {

        scanf("%s %s", input1, input2);   
        getchar();

        int ti1, ti2, indice1=-1, indice2=-1;
        for(ti1=0;;ti1++){
            if(input1[ti1]=='\0') break;
        }
        for(ti2=0;;ti2++){
            if(input2[ti2]=='\0') break;
        }

        //printf("ti1:%d ti2:%d\n", ti1, ti2);

        for (int j = 0 ; j < V ; j++){
            if (indice1>-1) break;
            for(int k = 0 ; k < ti1 ; k++){
                if(input1[k]!=bichos[j][k]){
                    indice1=-1;
                    break;
                } else if(k==ti1-1) indice1 = j;
            }
        }

        for (int j = 0 ; j < V ; j++){
            if (indice2>-1) break;
            for(int k = 0 ; k < ti2 ; k++){
                if(input2[k]!=bichos[j][k]){
                    indice2=-1;
                    break;
                } else if(k==ti2-1) indice2 = j;
            }
        }
        
          //printf("v:%d w:%d\n", indice1, indice2);


        e = EDGE(indice1,indice2);
        Graphinsert(G,e);
    }
    Conexus conexus[5000];
    int n =  Graphsearch(G, conexus);

    int maiorqtd=1, fconex=0;
    for(int j = 0 ; j < n ; j++){
        if(conexus[j].qtd>maiorqtd){
            fconex=j;
            maiorqtd = conexus[j].qtd;   
        } 
    }
    printf("%d\n", conexus[fconex].qtd);

    }
    
    return 0;
}
