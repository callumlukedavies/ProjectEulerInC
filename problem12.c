#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int countDivisors(int dividend);
int isPrime(int number);

/*
    Problem:
    The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
    Let us list the factors of the first seven triangle numbers:

    1: 1
    3: 1,3
    6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28
    
    We can see that 28 is the first triangle number to have over five divisors.
    What is the value of the first triangle number to have over five hundred divisors?

    Approach:
    To find how many divisors a number has, we can run a for loop that 
    tests if a dividend has divisor, and if it does we can add this to a
    counter variable.
*/

int main(int argc, char const *argv[])
{
    int i, value, step;
    step = 1;
    value = 0;

    for(i = 1; ; i+=step)
    {
        step++;
        int divisors = countDivisors(i);
        if(divisors > 500)
        {
            value = i;
            break;
        }
    }

    printf("first integer with 500 divisors is %d", value);
    return 0;
}

/*
    Method which counts how many divisors a number has using the divisor
    algorithm. It returns the number of divisors of the dividend provided.
*/
int countDivisors(int dividend)
{
    int i;
    int divisors = 1;
    int answer = dividend;

    for(i = 2; i < sqrt(dividend); i++)
    {
        if(isPrime(i) && answer % i == 0)
        {
            answer /= i;
            int powers = 1;

            while(answer % i == 0 && answer > 1)
            {
                answer /= i;
                powers++;
            }

            divisors *= powers + 1;
            if(answer == 1) break;
        }
    }

    return divisors;
}

/*
    Method which determines whether a number is prime or not, and 
    returns 1 if it is prime, 0 otherwise.
*/
int isPrime(int number)
{
    int i;
    double squareRoot = sqrt(number);

    for(i = squareRoot; i > 1; i--)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
