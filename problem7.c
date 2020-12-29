#include <stdio.h>
#include <math.h>

int isPrime(int number);
/*
    Problem:
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
    we can see that the 6th prime is 13. What is the 10 001st prime number?

    Approach:
    Iterate through positive numbers and testing each to see if it 
    is prime. A counter variable keeps track of prime numbers counted.
    Upon reaching the 10,001st prime, we break the loop and print
    the 10,001st prime number.
*/
int main(int argc, char const *argv[])
{
    int i;
    int primesCounted = 0;
    for(i = 2; ; i++)
    {
        if(isPrime(i))
        {
            primesCounted++;
            if(primesCounted == 10001)
            {
                break;
            }
        }
    }
    printf("10001st prime is %d\n", i);
    return 0;
}

/*
    Method that determines if a number is prime. Returns 1 if a number is 
    prime, 0 otherwise.
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
