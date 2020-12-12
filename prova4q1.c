#include <stdio.h>

int main(){ 
    long N=2147483648 , j=0, i=0;
    char *mensagem = malloc(sizeof(char)*N), C;
    while(scanf("%ld %c\n", &N, &C)!=EOF){mensagem[N] = C;j++;}
    for(i = N-j ; i < N+j ; i++) if(mensagem[i]!='\0' && i>0 ) printf("%c", mensagem[i]);
    return 0;
}