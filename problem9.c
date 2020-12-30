#include <math.h>
#include <stdio.h>
/*
    Problem:
    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a^2 + b^2 = c^2
    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.

    Approach:
    To find the product of the pythagorean triplet for which a + b + c = 1000,
    we will start with the assumption that a, b and c are all positive
    integers less than 998. This gives us a range to search in.
    To find this product, we will search through all the pythagorean triplets.
    We will first check if all three integers add up to 1000, and upon finding
    integers that do, we will check if they are a pythagorean triplet.
    If this succeeds, multiply the numbers together to get the product.
*/
int main(int argc, char const *argv[])
{
    int a, b, c;
    int answer;
    int answerFound = 0;

    for(a = 1; a < 999; a++)
    {
        for(b = a + 1; b < 999; b++)
        {
            for(c = b + 1; c < 999; c++)
            {
                if(a + b + c == 1000)
                {
                    if(pow(a, 2) + pow(b, 2) == pow(c, 2))
                    {
                        answer = a*b*c;
                        answerFound = 1;
                        break;
                    }
                }
            }

            if(answerFound) break;
        }
        
        if(answerFound) break;
    }

    printf("product is %d", answer);
    return 0;
}
