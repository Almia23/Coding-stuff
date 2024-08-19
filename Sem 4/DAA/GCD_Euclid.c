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

    start = clock();
    while (b != 0)
    {
        if (a % b == 0)
        {
            break;
        }
        opcount++;
        t = a % b;
        a = b;
        b = t;
    }
    end = clock();
    printf("GCD= %d\n", b);
    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time= %e\n", tot);
    printf("Opcount= %d", opcount);
    return 0;
}