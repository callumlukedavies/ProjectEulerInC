#include <stdio.h>

int calculateMultiples();

/*
    If we list all the natural numbers below 10 that are multiples of 3 or 5,
    we get 3, 5, 6 and 9. The sum of these multiples is 23.

    Find the sum of all the multiples of 3 or 5 below 1000.
*/
int main(int argc, char const *argv[])
{
    int total = calculateMultiples();
    printf("The total of the multiples of 3 or 5 under 1000 is %d\n", total);

    return 0;
}

/*
    If variable count is divisible by 3 or 5, add it to temp.
*/ 
 int CalculateMultiples()
 {
    int count;
    int temp = 0;
    for(count = 0; count < 1000; count++)
    {
        if(count % 3 == 0 || count % 5 == 0)
        {
            temp += count;
        }
    }
    return temp;
}
