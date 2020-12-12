#include <stdio.h>

int main(int argc, char const *argv[])
{

    int v[1000], i = 0, k = 0, j = 0, temp=1;

    while (scanf(" %d", &v[i]) == 1)
    {
        i++;
    }

    for (k = 0; k < i-1; k++)
    {
        for (j = k + 1; j > 0; j--)
        {
            if (v[j] < v[j - 1])
            {
                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
            }
        }
    }

    for (k = 0; k < i; k++)
    {
        printf("%d", v[k]);
        if(k<i-1) printf(" ");
    }
    printf("\n");

    return 0;
}
