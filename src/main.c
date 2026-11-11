#include <stdio.h>
#include "product.h"
#include "graph.h"
#include "recommendation.h"

int main()
{
    Product products[] =
    {
        {101, "Laptop", "Electronics"},
        {102, "Mouse", "Accessories"},
        {103, "Keyboard", "Accessories"},
        {104, "Headphones", "Electronics"},
        {105, "Mobile", "Electronics"},
        {106, "Charger", "Accessories"},
        {107, "Earphones", "Accessories"}
    };

    int count = sizeof(products) / sizeof(products[0]);

    Graph graph;

    initializeGraph(&graph, count);

    // Load transactions from CSV
    int loaded = loadTransactionsFromCSV(
        &graph,
        products,
        count,
        "data/purchases.csv"
    );

    if (loaded < 0)
    {
        freeGraph(&graph);
        return 1;
    }

    printf("\nTransactions Loaded: %d\n", loaded);

    int choice;

    do
    {
        printf("\n====================================\n");
        printf("  SMART PRODUCT DISCOVERY SYSTEM\n");
        printf("====================================\n");

        printf("1. Display All Products\n");
        printf("2. Search Product\n");
        printf("3. Display Product Graph\n");
        printf("4. BFS Traversal\n");
        printf("5. DFS Traversal\n");
        printf("6. Smart Recommendations\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            choice = 0;
            continue;
        }

        switch (choice)
        {
            case 1:
                displayProducts(products, count);
                break;

            case 2:
            {
                int searchID;

                printf("Enter Product ID: ");
                scanf("%d", &searchID);

                int result = findProductByID(
                    products, count, searchID
                );

                if (result != -1)
                {
                    printf("\nProduct Found!\n");
                    printf("ID: %d\n",
                           products[result].productID);
                    printf("Name: %s\n",
                           products[result].name);
                    printf("Category: %s\n",
                           products[result].category);
                }
                else
                {
                    printf("\nProduct Not Found!\n");
                }

                break;
            }

            case 3:
                displayGraph(&graph, products);
                break;

            case 4:
            {
                int productID;

                printf("Enter starting Product ID: ");
                scanf("%d", &productID);

                int start = findProductByID(
                    products, count, productID
                );

                if (start != -1)
                    BFS(&graph, start);
                else
                    printf("Invalid Product ID!\n");

                break;
            }

            case 5:
            {
                int productID;

                printf("Enter starting Product ID: ");
                scanf("%d", &productID);

                int start = findProductByID(
                    products, count, productID
                );

                if (start != -1)
                    DFS(&graph, start);
                else
                    printf("Invalid Product ID!\n");

                break;
            }

            case 6:
            {
                int purchasedIDs[MAX_PRODUCTS];
                int purchasedCount;

                printf("Enter number of purchased products: ");
                scanf("%d", &purchasedCount);

                if (purchasedCount <= 0 ||
                    purchasedCount > count)
                {
                    printf("Invalid number of products!\n");
                    break;
                }

                printf("Enter purchased Product IDs:\n");

                for (int i = 0; i < purchasedCount; i++)
                {
                    scanf("%d", &purchasedIDs[i]);
                }

                recommendProducts(
                    &graph,
                    products,
                    count,
                    purchasedIDs,
                    purchasedCount
                );

                break;
            }

            case 7:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 7);

    freeGraph(&graph);

    return 0;
}