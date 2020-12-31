#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int isPrime(int number);

/*
    Problem:
    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
    Find the sum of all the primes below two million.

    Approach:
    Check each number 2-2000000 for primality and add
    primes to a sum variable.
*/
int main(int argc, char const *argv[])
{
    int i;
    int64_t sum = 0;
    int numOfPrimes = 0;
    for(i = 2; i < 2000000; i++)
    {
        if(isPrime(i))
        {
            // printf("%d\n", i);
            sum += i;
            numOfPrimes++;
        }
    }

    printf("sum is %" PRId64 "\n", sum);
    printf("num of primes = %d\n", numOfPrimes);
    return 0;
}

/*
    Method which checks if a number is prime.
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
