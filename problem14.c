#include <stdio.h>
#include <inttypes.h>
/*
    Problem:

    The following iterative sequence is defined for the set of positive integers:
    n → n/2 (n is even)
    n → 3n + 1 (n is odd)
    Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
    It can be seen that this sequence (starting at 13 and finishing at 1) 
    contains 10 terms. Although it has not been proved yet (Collatz Problem), 
    it is thought that all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?

    Solution:
    Using a for loop we will iterate from 0 to 1000000, and counting each 
    chaining number from the initial value down to one. We will then compare
    each number chain length with the highest recorded, until we
    have exhausted the list and found the largest collatz number.
*/

int main(int argc, char const *argv[])
{
    long i;
    long largestCollatz = 0;
    long largestCounter = 0;
    int counter;
    long long int copy;

    for (i = 0; i < 1000000; i++)
    {
        counter = 1;
        copy = i;
        while (copy > 1)
        {
            if (copy % 2 == 0)
            {
                copy /= 2;
            } 
            else 
            {
                copy = (copy * 3) + 1;
            }

            counter++;
        }
        if(counter >= largestCounter)
        {
            largestCounter = counter;
            largestCollatz = i;
        }
    }

    printf("Largest collatz number under 1000000 is %ld, with a chain of length %ld \n", largestCollatz, largestCounter);
    return 0;
}
