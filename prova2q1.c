#include <stdio.h>

typedef struct
{
    int codigo, nota;
} rest;

int main(int argc, char const *argv[])
{

    int dia = 1, restaurantes;
    rest atual;
    rest best;

    while (scanf("\n%d", &restaurantes) != EOF)
    {

        best.codigo = -1;
        best.nota = -1;
        for (int i = 0; i < restaurantes ; i++)
        {

            scanf(" %d %d", &atual.codigo, &atual.nota);
            if ((atual.nota > best.nota)||(atual.nota==best.nota&&atual.codigo<best.codigo))
            {
                best.codigo = atual.codigo;
                best.nota = atual.nota;

            }else continue;
        
        }

        printf("Dia %d\n%d\n\n", dia,best.codigo);
        dia++;
    }

    return 0;
}
