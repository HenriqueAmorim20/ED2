#include <stdio.h>

int main(int argc, char const *argv[])
{
    int string[96], num, ind;
    char a;
    for (int i = 0; i < 96; i++)
        string[i] = 0;
    while(scanf("%c", &a) != EOF)
    {
        if (a == '\n')
        {
            for (int i = 1;i < 1001; i++)
            {
                for (int j = 0; j < 96; j++)
                {
                    if (string[j] != 0 && string[j] == i)
                    {
                        printf("%d %d\n", j + 32, string[j]);
                        string[j] = 0;
                    }
                }
            }
        }
        else
        {
            num = a - 32;
            string[num] += 1;
        }
    }

    return 0;
}
