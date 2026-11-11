#include <stdio.h>
#include "product.h"

// Display all products
void displayProducts(const Product products[], int count)
{
    printf("\n========== PRODUCT LIST ==========\n");

    printf("%-10s %-20s %-20s\n",
           "ID", "Product Name", "Category");

    for (int i = 0; i < count; i++)
    {
        printf("%-10d %-20s %-20s\n",
               products[i].productID,
               products[i].name,
               products[i].category);
    }

    printf("==================================\n");
}

// Search product using ID
int findProductByID(const Product products[],
                    int count,
                    int productID)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].productID == productID)
        {
            return i;
        }
    }

    return -1;
}
