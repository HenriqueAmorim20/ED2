//Este algoritmo é baseado em se passar sempre o menor valor do vetor para a primeira posição (ou o maior dependendo da ordem requerida), depois o segundo menor valor para a segunda posição e assim sucessivamente, até os últimos dois elementos.
//Neste algoritmo de ordenação é escolhido um número a partir do primeiro, este número escolhido é comparado com os números a partir da sua direita, quando encontrado um número menor, o número escolhido ocupa a posição do menor número encontrado. Este número encontrado será o próximo número escolhido, caso não for encontrado nenhum número menor que este escolhido, ele é colocado na posição do primeiro número escolhido, e o próximo número à sua direita vai ser o escolhido para fazer as comparações. É repetido esse processo até que a lista esteja ordenada.

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) \
    {              \
        int T = A; \
        A = B;     \
        B = T;     \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(A, B)) \
            exch(A, B); \
    }
void selectionsort();

int main()
{

    Item V[100001] = {}, l = 0, r;

    scanf("%d", &r);
    for (int j = 0; j < r; j++)
    {
        scanf("\n%d", &V[j]);
    }

    selectionsort(V, l, r - 1);

    for (int i = 0; i < r; i++)
    {
        if (i == r - 1)
            printf("%d\n", V[i]);
        else
            printf("%d ", V[i]);
    }
    return 0;
}

void selectionsort(Item *V, int l, int r)
{

    if (l == r)
        return;

    int menor = V[l];

    for (int j = l + 1; j <= r; j++)
    {

        if (less(V[j], menor))
        {
            menor = V[j];
            exch(V[l], V[j]);
        }
    }

    return selectionsort(V, l + 1, r);
}
