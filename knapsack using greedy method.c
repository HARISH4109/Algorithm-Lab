#include <stdio.h>

// Structure for an item
struct Item {
    int weight;
    int profit;
    float ratio;
};

void knapsack(int n, struct Item items[], int capacity) {
    int i, j;
    float totalProfit = 0.0, remaining = capacity;

    // Sort items by profit/weight ratio (descending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Greedy selection
    for (i = 0; i < n; i++) {
        if (items[i].weight <= remaining) {
            // Take full item
            totalProfit += items[i].profit;
            remaining -= items[i].weight;
        } else {
            // Take fraction of item
            totalProfit += items[i].ratio * remaining;
            break;
        }
    }

    printf("\nMaximum profit: %.2f\n", totalProfit);
}

int main() {
    int n, capacity, i;
    struct Item items[20];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i < n; i++) {
        printf("\nEnter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    knapsack(n, items, capacity);

    return 0;
}
