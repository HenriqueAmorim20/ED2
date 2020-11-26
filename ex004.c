#include <stdio.h>

int main(int argc, char const *argv[])
{

    int i = 0, j = 0, N, linha, coluna, tam_col = 0;
    char texto[1000][1000], comando, car;

    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++)
    {

        for (j = 0;; j++)
        {
            scanf("%c", &car);
            if (car == '\n' && j > 0)
            {
                texto[i][j] = '\n';
                break;
            }
            else
                texto[i][j] = car;
        }
    }

    scanf("%d %d", &linha, &coluna);

    while (scanf("\n%c", &comando) == 1)
    {
        if (comando == 'k')
        {
            if (linha - 1 == 0)
            {
                for (tam_col = 0;; tam_col++)
                {
                    if (texto[linha - 1][tam_col] == '\n')
                        break;
                }


                if (tam_col < coluna )
                {
                    printf("%d %d %c\n", linha, tam_col, texto[linha - 1][tam_col - 1]);
                }
                else
                {
                    printf("%d %d %c\n", linha, coluna, texto[linha - 1][coluna - 1]);
                }
            }
            else
            {
                linha--;
                for (tam_col = 0;; tam_col++)
                {
                    if (texto[linha - 1][tam_col] == '\n')
                        break;
                }


                if (tam_col < coluna )
                {
                    printf("%d %d %c\n", linha, tam_col, texto[linha - 1][tam_col - 1]);
                }
                else
                {
                    printf("%d %d %c\n", linha, coluna, texto[linha - 1][coluna - 1]);
                }
            }
        }

        else if (comando == 'j')
        {
            if (linha == N)
            {
                for (tam_col = 0;; tam_col++)
                {
                    if (texto[linha - 1][tam_col] == '\n')
                        break;
                }


                if (tam_col < coluna )
                {
                    printf("%d %d %c\n", linha, tam_col, texto[linha - 1][tam_col - 1]);
                }
                else
                {
                    printf("%d %d %c\n", linha, coluna, texto[linha - 1][coluna - 1]);
                }
            }
            else
            {
                linha++;
                for (tam_col = 0;; tam_col++)
                {
                    if (texto[linha - 1][tam_col] == '\n')
                        break;
                }


                if (tam_col < coluna)
                {
                    printf("%d %d %c\n", linha, tam_col, texto[linha - 1][tam_col - 1]);
                }
                else
                {
                    printf("%d %d %c\n", linha, coluna, texto[linha - 1][coluna - 1]);
                }
            }
        }
    }

    return 0;
}
