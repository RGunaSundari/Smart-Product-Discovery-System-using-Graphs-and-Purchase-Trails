#include <stdio.h>
#include "recommendation.h"
#include "sorting.h"

void recommendProducts(
    const Graph *graph,
    const Product products[],
    int count,
    const int purchasedIDs[],
    int purchasedCount)
{
    int purchased[MAX_PRODUCTS] = {0};
    int score[MAX_PRODUCTS] = {0};

    // Identify purchased products
    for (int i = 0; i < purchasedCount; i++)
    {
        int index = findProductByID(
            products, count, purchasedIDs[i]
        );

        if (index != -1)
            purchased[index] = 1;
    }

    // Calculate recommendation scores
    for (int i = 0; i < count; i++)
    {
        if (purchased[i])
            continue;

        Node *current = graph->head[i];

        while (current != NULL)
        {
            int connectedProduct = current->destination;

            if (purchased[connectedProduct])
                score[i] += current->weight;

            current = current->next;
        }
    }

    // Store recommendations
    Recommendation recommendations[MAX_PRODUCTS];

    int recommendationCount = 0;

    for (int i = 0; i < count; i++)
    {
        if (!purchased[i] && score[i] > 0)
        {
            recommendations[recommendationCount].productIndex = i;

            recommendations[recommendationCount].score = score[i];

            recommendationCount++;
        }
    }

    // Sort by score
    if (recommendationCount > 0)
    {
        mergeSortRecommendations(
            recommendations,
            0,
            recommendationCount - 1
        );
    }

    // Display ranked recommendations
    printf("\n======= SMART PRODUCT RECOMMENDATIONS =======\n");

    if (recommendationCount == 0)
    {
        printf("No recommendations available.\n");
    }

    for (int i = 0; i < recommendationCount; i++)
    {
        int index = recommendations[i].productIndex;

        printf("Rank %d: %-15s Score: %d\n",
               i + 1,
               products[index].name,
               recommendations[i].score);
    }

    printf("=============================================\n");
}