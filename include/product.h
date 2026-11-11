#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 30

typedef struct
{
    int productID;
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];

} Product;

// Function declarations

void displayProducts(
    const Product products[],
    int count
);

int findProductByID(
    const Product products[],
    int count,
    int productID
);

#endif
