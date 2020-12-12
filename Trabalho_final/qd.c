#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    int N, i=0, token = 0;
    char email[101];
    char processed[101];
    scanf("%d", &N);
    getchar();

    for( i = 0; i < N ; i++){

        fgets(email, 101, stdin);
        for(int j = 0 ; j < 101 ; j++){

            if(email[j]=='\n') {

                token=0;
                break;

            }
            if(email[j]=='@') token = 2;
            if(email[j]=='')

            if(token==1){

                if(email[])

            }else if(token == 0)

        }

    }

    return 0;
}
