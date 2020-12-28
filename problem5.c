#include <stdio.h>

int isSmallestMultiple(int number);

/*
    Problem:
    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

    Approach:
    Starting with the number 2521, test each number to see if it is evenly 
    divisible by all numbers 1 through 20. If the test fails, increment to
    the next positive number. We can deduce that the result will be a
    multiple of 10, since for every other digit through 1 - 9, there is a 
    digit which will cause it to divide unevenly.
*/
int main(int argc, char const *argv[])
{
    int i, smallestMultiple;
    smallestMultiple = 0;
    for(i = 2520; ; i+=10)
    {
        if(isSmallestMultiple(i))
        {
            smallestMultiple = i;
            break;
        }
    }

    printf("The smallest multiple to divide 1 through 20 is %d\n", smallestMultiple);
    return 0;
}

/*
    Method that determines if a number divides evenly by the integers 1 to 20.
*/
int isSmallestMultiple(int number)
{
    int i;
    for(i = 1; i < 21; i++)
    {
        if(number % i != 0)
        {
            return 0;
        }
    }

    return 1;
}
