# Smart Product Discovery System Using Graphs and Purchase Trails

## Project Overview

The **Smart Product Discovery System** is a C-based product recommendation system that uses Graph Data Structures and Algorithms to identify relationships between products based on customer purchase history.

The system represents products as vertices and their purchase relationships as weighted edges in an undirected graph. It analyzes customer purchase trails to recommend products that are frequently purchased together.

This project demonstrates the practical application of Data Structures and Algorithms in an e-commerce recommendation environment.

## Objectives

- Represent product relationships using an undirected weighted graph.
- Implement graph representation using adjacency lists.
- Analyze customer purchase history to identify related products.
- Apply Breadth First Search (BFS) and Depth First Search (DFS).
- Generate product recommendations based on purchase relationships.
- Rank recommended products using sorting algorithms.
- Understand the efficiency of algorithms through time complexity analysis.

## Technologies Used

| Technology | Purpose |
|---|---|
| C Programming | Core implementation |
| Graph Data Structure | Product relationship representation |
| Adjacency List | Graph representation |
| BFS | Graph traversal |
| DFS | Graph traversal |
| Insertion Sort | Sorting recommendations |
| Quick Sort | Efficient sorting |
| Randomized Quick Sort | Randomized sorting approach |
| CSV | Customer purchase data |
| Git & GitHub | Version control and project hosting |

## Data Structures and Algorithms

### 1. Graph Representation

The system uses an undirected weighted graph.

- Vertices represent products.
- Edges represent relationships between products.
- Edge weights represent the number of customers or transactions in which two products were purchased together.

### 2. Breadth First Search (BFS)

BFS traverses the product graph level by level and identifies products connected to a selected product.

### 3. Depth First Search (DFS)

DFS explores connected product relationships by following one path as deeply as possible before backtracking.

### 4. Product Recommendation

The recommendation score for a candidate product is calculated using the sum of its edge weights with products already purchased by the customer.

Higher scores indicate stronger purchase relationships.

### 5. Sorting Algorithms

The project uses:

- Insertion Sort
- Quick Sort
- Randomized Quick Sort

These algorithms are used to arrange product recommendations based on their scores.

## Project Structure

```text
Smart_Product_Discovery/
│
├── data/
│   └── purchases.csv
│
├── docs/
│   └── project_design.md
│
├── include/
│   ├── graph.h
│   ├── product.h
│   ├── recommendation.h
│   └── sorting.h
│
├── src/
│   ├── graph.c
│   ├── main.c
│   ├── product.c
│   ├── recommendation.c
│   └── sorting.c
│
├── tests/
│   └── test_cases.txt
│
├── test.c
├── README.md
└── .gitignore
```

## Installation and Execution

### Prerequisites

- Windows operating system
- GCC compiler
- MSYS2 UCRT64 or another GCC-compatible environment

### Step 1: Clone the Repository

```bash
git clone https://github.com/RGunaSundari/Smart-Product-Discovery-System-using-Graphs-and-Purchase-Trails.git
```

### Step 2: Navigate to the Project

```bash
cd Smart-Product-Discovery-System-using-Graphs-and-Purchase-Trails
```

### Step 3: Compile the Program

Using MSYS2 UCRT64:

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/product.c src/graph.c src/recommendation.c src/sorting.c -o product_demo.exe
```

### Step 4: Execute the Program

In PowerShell:

```powershell
.\product_demo.exe
```

## Sample Dataset

The system uses customer purchase history stored in a CSV file.

Example format:

```csv
CustomerID,TransactionID,ProductIDs
C001,T001,101 102 103
C002,T002,101 103 104
C003,T003,102 103 105
```

Products purchased together are used to establish relationships in the graph.

## Applications

- E-commerce product recommendation systems
- Customer purchase pattern analysis
- Frequently bought together suggestions
- Product relationship discovery
- Shopping personalization

## Future Enhancements

- Develop a web-based user interface.
- Add interactive graph visualization.
- Integrate a product database.
- Display recommendation performance
