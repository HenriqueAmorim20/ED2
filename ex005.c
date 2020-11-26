#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int i=1, j=0, temp=0, limite=0, soma=0, intermed, k=1;
    int *nums = (int *) malloc((sizeof(int))); 
    int *imp = (int *) malloc(sizeof(int));
    imp = 0;
    nums = 0;

    while(scanf(" %d", &temp)==1){

        if(temp == 0) break;
        nums = (int *) realloc(nums, (i+1)*sizeof(int));
        nums[i] = temp;
        i++;
        
    }

    scanf("%d", &limite);

    for(j=1;j<i; j++){

        soma = soma + nums[j]; 
        if(soma > limite){
            imp = (int *) realloc(imp, (k+1)*sizeof(int));
            imp[k] = nums[j];
            k++;  
            soma = 0;
          
        }
    }
    
    for(i=k-1;i>=1;i--){

        printf("%d\n", imp[i]);

    }

    return 0;
}


//33 51 23 94 66 28 11 73 19 8 31 0
//90

