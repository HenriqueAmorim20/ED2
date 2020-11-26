#include <stdio.h>

cria_fila(){

char *fila = (char *) malloc(sizeof(char));

}

ad_elemento(value, i,u){
    fila = (char *) realloc(fila, (i+1)*sizeof(char));
    fila[i-1] = value;
    i++;
    u++;
}

r_elemento(i,u){
    if(i==u){
        printf("Fila vazia!");
        return;
    }

    value = fila[i-u];
    fila = (char *) realloc(fila, (i-1)*sizeof(char));
    i--;
    u++;
    return value;
}

exclui_fila(){

    free(fila);

}

int main(int argc, char const *argv[])
{
    int resposta = 1, i=1, u=0;
    char value;

    cria_fila();

    while(resposta!=0){

        scanf("\n%d", &resposta);
        printf("Deseja realizar outra operação?\n1-sim\n0-não\n");

        if(resposta == 1){

            printf("1-Adicionar elemento\n2-remover elemento\n");
            scanf("\n%d", &respota);

            if(resposta == 1){

                printf("Digite o elemento a ser adicionado:\n");
                scanf("\n%c", %value);
                ad_elemento(value);

            } else if (resposta==0){

                char temp = r_elemento();
                printf("Elemento removido: %c\n", temp);

            }else{

            printf("Entrada inválida, digite novamente!");

            }

        } else if (resposta==0){

        }else{

            printf("Entrada inválida, digite novamente!");

        }


    }
    
    
    return 0;
}
