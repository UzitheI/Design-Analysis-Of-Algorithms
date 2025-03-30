#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Job
{
    char id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b)
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void jobSequencing(struct Job arr[], int n)
{
    qsort(arr, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].deadline > maxDeadline)
        {
            maxDeadline = arr[i].deadline;
        }
    }

    char result[maxDeadline];
    bool slot[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
    {
        slot[i] = false;
    }

    int totalProfit = 0;
    printf("\nFollowing is maximum profit sequence of jobs:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = min(maxDeadline - 1, arr[i].deadline - 1); j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = arr[i].id;
                slot[j] = true;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i])
        {
            printf("%c ", result[i]);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main()
{
    struct Job arr[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given Jobs with (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c %d %d\n", arr[i].id, arr[i].deadline, arr[i].profit);
    }

    jobSequencing(arr, n);
    return 0;
}