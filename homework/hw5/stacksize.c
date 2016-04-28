#include <stdio.h>

//#define N 20        /* plug something in here */
//#define XSIZE (0x01<<N)

#define M 16        /* plug something in here */
#define MAXREC (0x01<<M)

double big_array(void)
{
    int i, x[XSIZE];
    double result = 0.0;
    for (i = 0; i < XSIZE; i++)
	x[i] = i;
    for (i = 0; i < XSIZE; i++)
	result += x[i];
    return result;
}

double max_recursion(int val)
{
    if (val <= 1)
	return 1;
    return val + max_recursion(val-1);
}

int main()
{
//    printf("Result returned by big_array() is %e\n", big_array());
    printf("Result returned by max_recursion() is %e\n", max_recursion(MAXREC));
}
