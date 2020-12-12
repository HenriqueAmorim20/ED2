#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, M, SUM=0, RES;
    scanf("%d\n", &N);
    for(int i=0 ; i<N ; i++) {
        scanf("%d ", &M);
        SUM+=M;
    }
    scanf("\n%d", &RES);
    if(RES==SUM) printf("Acertou\n");
    else printf("Errou\n");
    return 0;
}
