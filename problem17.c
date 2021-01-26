#include <stdio.h>

int calculateOverNine(int i);
int calculateOverOneHundred(int i);

/*
    Problem:
    If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

    If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

    Solution:
    We will store the number of characters used to spell each number in
    an array, using four different arrays for units, tens, hundreds,
    and also numbers between 11 and 19 inclusive. Then using a for loop,
    add the number of characters for each number to a counter.
*/

int units[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int tens[10] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
int hundreds[10] = {0, 10, 10, 12, 11, 11, 10, 12, 12, 11};
int teens[10] = {0, 6, 6, 8, 8, 7, 7, 9, 8, 8};

int main(int argc, char const *argv[])
{
    int i;
    int count = 0;

    for(i = 1; i < 1000; i++)
    {
        if(i >= 100)
        {
            count += calculateOverOneHundred(i);   
        }
        else if(i > 9)
        { 
            count += calculateOverNine(i);
        }
        else if (i <= 9)
        {
            count += units[i];
        }
    }

    count+=11;
    printf("count is %d\n", count);
    return 0;
}


int calculateOverNine(int i)
{
    int noChars = 0;
    int unitIndex = i % 10;
    int tenIndex = (i % 100) / 10;
    if(tenIndex == 1 && unitIndex > 0)
    {
        noChars += (teens[unitIndex]);
    }
    else
    {
        noChars += (units[unitIndex] + tens[tenIndex]);
    }

    return noChars;
}

int calculateOverOneHundred(int i)
{
    int noChars = 0;
    int unitIndex = i % 10;
    int tenIndex = (i % 100) / 10;
    int hundredIndex = i / 100;
    if(tenIndex == 1 && unitIndex > 0)
    {
        noChars += hundreds[hundredIndex] + teens[unitIndex];
    }
    else
    {
        noChars += (units[unitIndex] + tens[tenIndex] + hundreds[hundredIndex]);
    }

    if(tenIndex != 0 || unitIndex != 0)
    {
        noChars += 3;
    }

    return noChars;
}