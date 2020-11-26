henrique amorim costa melo - 170144488

T1: Um algorítmo estável é aquele que preserva a ordem de elementos que possuem o mesmo valor, ou seja, no Vetor V[1,3,4,5,5,7] o elemento da terceira posição (5) sempre ficará em uma posição anterios ao elemento da quarta posição (também 5), pois no vetor inicial o terceiro vem primeiro que o quarto.
    
    Tendo como base o algorítmo de insertion sort abaixo:

void insertionsort(Item *V, int l, int r){
    int i, j,temp;
    for (i = r; i > l; i--)
        cmpexch(V[i], V[i - 1]);
    for (i = l + 1; i <= r; i++){
        j = i;
        temp = V[j];
        while (less(temp, V[j - 1])){
            V[j] = V[j - 1];
            j--;
        }
        V[j] = temp;
    }
}

    Podemos observar que ele não faz a troca de elementos menores ou iguais, faz apenas de elemenos menores. Dessa forma um elemento de mesmo valor ja ordenado sempre respeitará a ordem do vetor inicial, quando ocorre um deslocamento de vários elementos e existe a comparação de um elemento com outro igual já ordenado, o elemento analisado ocupará a posição posterior ao que já tinha sido ordenado. 
        Exemplo: V[5,4,3*,3#] * e # para indentificar os elementos melhor, mas eles tem o mesmo valor;
            V[4,5,3*,3#] -> V[4,3*,5,3#] -> V[3*,4,5,3#] -> V[3*,4,3#,5] -> V[3*,3#,4,5] vetor ordenado.


T2: Tendo como exemplo um vetor simples V[6] = {3 4 1 5 0 2}; a função retorna 2 como valor de i e o vetor fica da seguinte maneira {0 1 4 5 3 2}, podemos observar que o elemento da posição v[3] não é o pivo correto, que seria o 1, já que na função separa ele escolhe o meio do vetor como pivo. Ela retorna o valor da posição do pivo correta, mas faz uma troca errada e deixa o elemento que deveria ser o pivo na posição errada. Podemos concluir, então, que essa função separa não funciona para vetores com numero de elementos pares, pois a escolha do pivo fica errada. Trocando o return por i-1 o problema ainda se mantém, pois o erro não é o valor do pivo retornado, mas sim uma troca de elementos errada em um vetor de tamanho par. é possivel corrigir a função da seguinte forma:

int separa(Item *V, int l, int r)
{

    Item c = V[r];
    int j = l;

    for (int k = l; k < r; k++)
    {
        if (V[k]< c))
        {
            V[k]=temp;
            V[k]=V[j];
            V[j]=temp;
            j++;
        }
    }
    V[j]=temp;
    V[j]=V[r];
    V[r]=temp;
  
