#include <stdio.h>

/*
Problem:
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?

Solution:
To solve this problem we can use a 2d array, where each element in the array
corresponds to a corner/intersection of the grid. The array will be of length
21X21. Starting at the last item in the array, we will incrementally fill each
position with the number of routes to the end square by adding up the number
of routes from the indices to the right and below (if applicable).
*/

const int GRID_SIZE = 20;

int main(int argc, char const *argv[])
{
    long long int array[GRID_SIZE+1][GRID_SIZE+1];

    int i,j;
    for(i = 0; i < GRID_SIZE + 1; i++)
    {
        for(j = 0; j < GRID_SIZE + 1; j++)
        {
            if((j == GRID_SIZE && i != GRID_SIZE) || (i == GRID_SIZE && j != GRID_SIZE))
            {
                array[i][j] = 1;
            }
            else
            {
                array[i][j] = 0;
            }
        }
    }

    for(i = GRID_SIZE - 1; i > -1; i--)
    {
        for(j = GRID_SIZE - 1; j > -1; j--)
        {
            long long int right = array[i][j+1];
            long long int bottom = array[i+1][j];
            array[i][j] = right + bottom;
        }
    }

    printf("There are %lld possible routes in a %dx%d grid\n",
     array[0][0], GRID_SIZE, GRID_SIZE);

    return 0;
}
