#include <stdio.h>

struct Food {
    char name[50];
    double unitPrice;
    int numberOfDaysSold;
    int AmountSoldPerDay[100];
};

int main() {
    struct Food foodItems[3];
    int i, j;

    for (i = 0; i < 3; i++) {
        printf("Enter details for Food %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", foodItems[i].name);

        printf("Unit price: ");
        scanf("%lf", &foodItems[i].unitPrice);

        printf("Number of days sold: ");
        scanf("%d", &foodItems[i].numberOfDaysSold);

        printf("Enter amount sold per day: ");
        for (j = 0; j < foodItems[i].numberOfDaysSold; j++) {
            scanf("%d", &foodItems[i].AmountSoldPerDay[j]);
        }
        
        printf("\n");
    }

    printf("--- Average Sales Calculation ---\n");

    for (i = 0; i < 3; i++) {
        double totalSales = 0.0;

        for (j = 0; j < foodItems[i].numberOfDaysSold; j++) {
            double salesForOneDay = foodItems[i].unitPrice * foodItems[i].AmountSoldPerDay[j];
            totalSales = totalSales + salesForOneDay;
        }

        double averageSalesPerDay = 0.0;
        
        if (foodItems[i].numberOfDaysSold > 0) {
            averageSalesPerDay = totalSales / foodItems[i].numberOfDaysSold;
        }

        printf("Average sales per day for %s: %.2f\n", foodItems[i].name, averageSalesPerDay);
    }

    return 0;
}