#include <stdio.h>
#include <string.h>

int isPalindrome(int number);

/*
    Problem:
    A palindromic number reads the same both ways. The largest palindrome 
    made from the product of two 2-digit numbers is 9009 = 91 × 99. Find 
    the largest palindrome made from the product of two 3-digit numbers.

    Approach:
    Start with the largest 3 digit number: 999.
    Using a for loop and a nested for loop, we can multiply numbers together
    until we find the largest palindromic number. We will verify a 
    palindromic number by converting it into a string, and comparing the 
    first half of the characters with the second half.
*/

int main(int argc, char const *argv[])
{
    int i, j;
    int largestPalindrome = 0;

    for(i = 999; i > 99; i--)
    {
        for(j = 999; j > 99; j--)
        {
            int newNum = i*j;
            if(isPalindrome(newNum))
            {
                if(newNum > largestPalindrome)
                {
                    largestPalindrome = newNum;
                }
                break;
            }
        }
    }

    printf("Largest palindrome is %d", largestPalindrome);
    return 0;
}


/*
    Method which determines if a number is palindromic by comparing
    each character in the first half of the string to the character
    that mirrors its position in the second half of the string.
*/
int isPalindrome(int number)
{
    char str[12];
    int i;

    sprintf(str, "%d", number);

    for(i = 0; i < strlen(str)/2; i++)
    {
        if(str[i] == str[(strlen(str)-i)-1])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}
