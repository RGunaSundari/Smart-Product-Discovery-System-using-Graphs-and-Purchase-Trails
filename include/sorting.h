#ifndef SORTING_H
#define SORTING_H

typedef struct
{
    int productIndex;
    int score;

} Recommendation;

void mergeSortRecommendations(
    Recommendation arr[],
    int left,
    int right
);

#endif