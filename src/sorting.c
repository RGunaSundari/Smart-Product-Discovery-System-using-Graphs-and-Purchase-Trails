#include "sorting.h"

// Merge two sorted portions
void merge(
    Recommendation arr[],
    int left,
    int mid,
    int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Recommendation L[n1];
    Recommendation R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Descending order
    while (i < n1 && j < n2)
    {
        if (L[i].score >= R[j].score)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort
void mergeSortRecommendations(
    Recommendation arr[],
    int left,
    int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortRecommendations(arr, left, mid);

        mergeSortRecommendations(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}