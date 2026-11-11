#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include "graph.h"

void recommendProducts(
    const Graph *graph,
    const Product products[],
    int count,
    const int purchasedIDs[],
    int purchasedCount
);

#endif