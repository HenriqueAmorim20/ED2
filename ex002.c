#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int i, N, soma=0, num;

    scanf("%d", &N);

    for(i = 0 ; i < N ; i++){

        scanf("%d", &num);
        soma+=num;

    }

    printf("%d\n", soma);

    return 0;
}
