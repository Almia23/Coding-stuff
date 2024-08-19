#include <stdio.h>
#include <time.h>
int opcount = 0;
int fib(int n)
{
    if (n <= 2)
    {
        return n - 1;
    }
    opcount += 2;
    return fib(n - 2) + fib(n - 1);
}
int main()
{
    clock_t start, end;
    double tot;
    printf("Enter n: \n");
    int n;
    scanf("%d", &n);

    start = clock();
    printf("The %d fibonacci num is %d\n", n, fib(n));
    end = clock();

    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time= %e\n", tot);
    printf("Opcount= %d", opcount);

    return 0;
}
