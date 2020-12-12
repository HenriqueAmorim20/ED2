#include <stdio.h>

#define MAXL 1000 
#define MAXC 11

char matrix[MAXL][MAXC];
void initMatrix(int L);
void printMatrix(int L);
void setTree(char G_lado, int G_linha);
char trocar_lenhador(char Lado_lenhador, int L);
int quebrar_tronco(char Lado_lenhador, int L);
void attMatrix(char Lado_lenhador, int L);
void setLenhador(char Lado_lenhador);

int main(int argc, char const *argv[]){
    
    int L, G, G_linha, i=0, quebrado=0 ;
    char comandos[2000], G_lado, Lado_lenhador;

    scanf("%d", &L);
    getchar();

    initMatrix(L);

    scanf("%d", &G);
    getchar();

    for(int i = 0 ; i < G ; i++){

        scanf("%c %d", &G_lado, &G_linha);
        getchar();

        setTree(G_lado,G_linha);

    }

    scanf("%c", &Lado_lenhador);
    getchar();

    setLenhador(Lado_lenhador);

    printMatrix(L);

    scanf("%s", comandos);

    while(comandos[i]!='\0'){

        if(comandos[i] == 'T') Lado_lenhador = trocar_lenhador(Lado_lenhador, L);

        if( comandos[i] == 'B' ) quebrado = quebrar_tronco(Lado_lenhador, L);

        if(quebrado == 1 ){

            printf("**morreu**\n");
            return 0;

        }

        i++;

    } 
    

    return 0;
}

//---------------------------------------

void initMatrix(int L){

    for(int i = 0 ; i < MAXL ; i++){

        for(int j = 0 ; j < MAXC ; j++){

            if( j >= 4 && j <=6 && i >= MAXL - L) matrix[i][j] = '|';

            else matrix[i][j] = ' ';

        }

    }

}

void printMatrix(int L){

    printf("~~~~~~~~~~~\n");

    for(int i = MAXL - 5  ; i < MAXL ; i++){

        for(int j = 0 ; j < MAXC ; j++){

            printf("%c", matrix[i][j]);

        }

        printf("\n");

    }

    printf("~~~~~~~~~~~\n");

}

void setTree (char G_lado, int G_linha) {

    if ( G_lado == 'D'){

        matrix[MAXL-G_linha][8] = '-';
        matrix[MAXL-G_linha][9] = '-';
        matrix[MAXL-G_linha][10] = '-';

    } else if ( G_lado == 'E' ){

        matrix[MAXL-G_linha][0] = '-';
        matrix[MAXL-G_linha][1] = '-';
        matrix[MAXL-G_linha][2] = '-';

    }

}

void setLenhador(char Lado_lenhador){

    if ( Lado_lenhador == 'D' ) {

        matrix[MAXL-2][8] = 'L';
        matrix[MAXL-1][8] = 'L';

    } else if ( Lado_lenhador == 'E' ) {

        matrix[MAXL-2][2] = 'L';
        matrix[MAXL-1][2] = 'L';

    }

}

char trocar_lenhador(char Lado_lenhador, int L){

        if( Lado_lenhador == 'D'){

            if( matrix[MAXL-2][2] == '-' || matrix[MAXL-1][2] == '-' ){

                printf("**beep**\n");
                return Lado_lenhador;

            } else {
                
                matrix[MAXL-2][2] = 'L';
                matrix[MAXL-1][2] = 'L';
                matrix[MAXL-1][8] = ' ';
                matrix[MAXL-2][8] = ' ';
                Lado_lenhador = 'E';
                printMatrix(L);
                return Lado_lenhador;

            }

        } else if( Lado_lenhador == 'E'){

            if( matrix[MAXL-2][8] == '-' || matrix[MAXL-1][8] == '-' ){

                printf("**beep**\n");
                return Lado_lenhador;

            } else {

                matrix[MAXL-2][8] = 'L';
                matrix[MAXL-1][8] = 'L';
                matrix[MAXL-1][2] = ' ';
                matrix[MAXL-2][2] = ' ';
                Lado_lenhador = 'D';
                printMatrix(L);
                return Lado_lenhador;

            }
        } 

}

int quebrar_tronco(char Lado_lenhador, int L){

        if(Lado_lenhador == 'D' && matrix[MAXL-1][6] == '|') matrix[MAXL-1][6] = '<';

        else if(Lado_lenhador == 'E' && matrix[MAXL-1][4] == '|') matrix[MAXL-1][4] = '>';

        else if(Lado_lenhador == 'D' && matrix[MAXL-1][6] == ' ') return 0;

        else if(Lado_lenhador == 'E' && matrix[MAXL-1][4] == ' ') return 0;

        else if(Lado_lenhador == 'D' && matrix[MAXL-1][6] == '<' && matrix[MAXL-3][10]!='-') attMatrix(Lado_lenhador, L);

        else if(Lado_lenhador == 'E' && matrix[MAXL-1][4] == '>' && matrix[MAXL-3][1]!='-') attMatrix(Lado_lenhador, L);
        
        else return 1;

        printMatrix(L);

    return 0;

}

void attMatrix(char Lado_lenhador, int L){

    for(int i = MAXL ; i > MAXL - L -1; i--) {

        for(int j = 0 ; j < MAXC ; j++){

            matrix[i][j] = matrix[i-1][j];


        }

    }

    setLenhador(Lado_lenhador);

}