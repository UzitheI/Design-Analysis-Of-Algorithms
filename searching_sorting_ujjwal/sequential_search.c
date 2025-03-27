#include <stdio.h>

// Function to perform sequential search
int sequentialSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // Return index if element found
        }
    }
    return -1; // Return -1 if element not found
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = sequentialSearch(arr, n, key);

    if (result == -1)
    {
        printf("Element %d not found in array\n", key);
    }
    else
    {
        printf("Element %d found at index %d\n", key, result);
    }

    return 0;
}