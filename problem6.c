#include <math.h>
#include <stdio.h>

int calculateSumOfSquares();
int calculateSquareOfSum();

/*
    Problem:
    The sum of the squares of the first ten natural numbers is,
    1^2 + 2^2 +...+ 10^2 = 385. 
    The square of the sum of the first ten natural numbers is,
    (1 + 2 +...+ 10)^2 = 55^2 = 3025.
    Hence the difference between the sum of the squares of the first
    ten natural numbers and the square of the sum is 3025 - 385 = 2640.
    Find the difference between the sum of the squares of the first one
    hundred natural numbers and the square of the sum.

    Approach:
    Calculate the sum of squares of the first 100 natural numbers.
    Calculate the square of the sum of the first 100 natural numbers.
    Get the difference of these two numbers.
*/

int main(int argc, char const *argv[])
{
    int sumOfSquares = calculateSumOfSquares();
    int squareOfSum = calculateSquareOfSum();
    int difference = squareOfSum - sumOfSquares;
    printf("The difference is %d\n", difference);

    return 0;
}

/*
    Calculates the sum of squares of the natural numbers between 1 and 100.
*/
int calculateSumOfSquares()
{
    int i, sum;
    sum = 0;

    for(i = 1; i < 101; i++)
    {
        sum += pow(i, 2);
    }

    return sum;
}

/*
    Calculates the square of the sum of the natural numbers between 1 and 100.
*/
int calculateSquareOfSum()
{
    int i, sum, squaredSum;
    sum = 0;

    for(i = 1; i < 101; i++)
    {
        sum += i;
    }

    squaredSum = pow(sum, 2);
    return squaredSum;
}
