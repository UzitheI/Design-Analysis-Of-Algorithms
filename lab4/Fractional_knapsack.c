#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int value;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b)
{
    float r1 = ((struct Item *)a)->ratio;
    float r2 = ((struct Item *)b)->ratio;
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    return 0;
}

float fractionalKnapsack(int W, struct Item arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    qsort(arr, n, sizeof(struct Item), compare);
    float finalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
            printf("Added item with weight %d and value %d completely\n",
                   arr[i].weight, arr[i].value);
        }
        else
        {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((float)remainingWeight / arr[i].weight);
            printf("Added %.2f%% of item with weight %d and value %d\n",
                   ((float)remainingWeight / arr[i].weight) * 100,
                   arr[i].weight, arr[i].value);
            break;
        }
    }

    return finalValue;
}

int main()
{
    int W = 50;
    struct Item arr[] = {
        {60, 10},
        {100, 20},
        {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum value we can obtain = %.2f\n",
           fractionalKnapsack(W, arr, n));
    return 0;
}