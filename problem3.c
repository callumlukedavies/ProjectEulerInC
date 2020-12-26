#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int isPrime(unsigned long long int number);
/*
    Problem Statement:
    The prime factors of 13195 are 5, 7, 13 and 29.
    What is the largest prime factor of the number 600851475143 ?

    Approach:
    Check if the given number (600851475143) is divisible by a number,
    and if it is, check if that number is prime. 
*/
int main(int argc, char const *argv[])
{
    unsigned long long int number = (unsigned long long) 600851475143L;
    unsigned long int largestPrime = (unsigned long) 0;
    unsigned long long int i;
    double square = sqrt(number);

    for(i = square; i > 1; i--)
    {
        if((number % i) == 0)
        {
            if(isPrime(i))
            {
                largestPrime = i;
                break;
            }
        }
    }

    printf("The largest prime number is %ld \n", largestPrime);
    
    return 0;
}

int isPrime(unsigned long long int number)
{
    int i;
    int isPrimeNumber = 1;
    double squareRoot = sqrt(number);

    for(i = squareRoot; i > 1; i--)
    {
        if(number % i == 0)
        {
            isPrimeNumber = 0;
            break;
        }
    }
    return isPrimeNumber;
}
