// 20. Trapping Rain Water Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
/*
Explanation -

    Input : height = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ]
    Output : 6
    Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.
                     _
             _      | |_   _      3
         _  | |_   _|   |_| |_    2
        |_|_|_ _|_|_ _ _ _ _ _|   1
*/
// TODO
#include <stdio.h>
// water will be trapped if the next elevation is greater than previous elevation
int trapWater(int height[], int heightSize)
{
    int a, b;
    int result = 0;
    int layerNum = 1;
    int layerWater;
    do
    {
        layerWater = 0;
        a = 0;
        b = 0;
        for (int i = 0; i < heightSize; i++)
        {
            printf("(%d < %d) && (%d >= %d) && (%d == 0) && (%d < %d)\n", i, heightSize - 1, height[i], layerNum, a, height[i + 1], height[i]);
            if ((i < (heightSize - 1)) && (height[i] >= layerNum) && (a == 0) && (height[i + 1] < height[i]))
            {
                a = i;
                printf("1 a = %d b = %d\n", a, b);
                continue;
            }
            printf("(%d >= %d) && (%d != 0) && ((%d - %d)>0)\n", height[i], layerNum, a, b, a);
            if ((height[i] >= layerNum) && (a != 0) && ((i - a) > 0))
            {
                b = i;
                layerWater += b - a - 1;
                printf("2 a = %d b = %d lw=%d \n", a, b, layerWater);
                a = 0;
                b = 0;
            }
        }
        printf("%d\n", layerWater);
        result += layerWater;
        layerNum++;
    } while (layerWater != 0);
    return result;
}
int main()
{
    // int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int arr[] = {4, 2, 0, 3, 2, 5};
    // printf("%d\n", trapWater(arr, 12));
    printf("%d\n", trapWater(arr, 6));
    return 0;
}
