#include <stdio.h>
#include <time.h>
int opcount = 0;
int main()
{
    clock_t start, end;
    double tot;
    int a, b, t;
    printf("Enter nums: \n");
    scanf("%d%d", &a, &b);
    if (a < b)
        t = a;
    else
        t = b;

    start = clock();
    while (1)
    {
        opcount++;
        if (a % t == 0)
        {
            opcount++;
            if (b % t == 0)
            {
                printf("GCD= %d\n", t);
                break;
            }
        }
        t--;
    }
    end = clock();

    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time= %e\n", tot);
    printf("Opcount = %d", opcount);

    return 0;
}