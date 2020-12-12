#include <stdio.h>

int main(int argc, char const *argv[])
{
    int desfile[1000001], N, ind, maior = -1, maiorind = 0;
    for (;;) {
        for (int i = 0; i < 1000001; i++) desfile[i] = 0;
        scanf("%d", &N);
        if (N == 0) break;
        for (int i = 0; i < N; i++){
            scanf("%d", &ind);
            if(i==0) maior = desfile[ind];
            desfile[ind] += 1;
            if (desfile[ind] >= maior){
                maior = desfile[ind];
                maiorind = ind;
            }
        }
        printf("%d\n", maiorind);
    }
    return 0;
}
