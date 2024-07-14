#include <stdio.h>
#include <time.h>
#include <string.h>

#define CONSOLE_WIDTH 40

void printCentered(char *str) 
{
    int len = strlen(str);
    int padding = (CONSOLE_WIDTH - len) / 2;

    for (int i = 0; i < padding; i++) 
    {
        putchar(' ');
    }

    printf("%s\n", str);
}

void printLines()
{
    int padding = CONSOLE_WIDTH;   
    for (int i = 0; i < padding; i++) 
    {
        putchar('-');
    }
    printf("\n");
}

void printHeaders() 
{
    const char* left = "Items";
    const char* center = "Qty";
    const char* right = "Total";

    int lenLeft = strlen(left);
    int lenCenter = strlen(center);
    int lenRight = strlen(right);

    int paddingLeft = 0;
    int paddingCenter = (CONSOLE_WIDTH - lenCenter) / 2;
    int paddingRight = CONSOLE_WIDTH - lenRight;

    printf("%s", left);
    
    for (int i = lenLeft; i < paddingCenter; i++) 
    {
        putchar(' ');
    }
    
    printf("%s", center);
    
    for (int i = paddingCenter + lenCenter; i < paddingRight; i++) 
    {
        putchar(' ');
    }
    
    printf("%s\n", right);
}

int main() 
{
    char customer_name[100];
    int item_quantity;
    char item_name[100][100];
    float unit_price[100], unit_quantity[100], price[100];

    printf("Enter the name of customer: ");
    scanf("%s", customer_name);
    printf("Enter the number of items ordered by %s: ", customer_name);
    scanf("%d", &item_quantity);

    for (int i = 0; i < item_quantity; i++) {
        printf("Enter the name of item-%d: ", i + 1);
        scanf("%s", item_name[i]);
        printf("Enter the unit price: ");
        scanf("%f", &unit_price[i]);
        printf("Enter the unit quantity: ");
        scanf("%f", &unit_quantity[i]);
        price[i] = unit_price[i] * unit_quantity[i]; // Calculate price for each item
    }

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    
    printf("\n\n");
    printCentered("Advani Hotel");
    printf("\nDate: %02d-%02d-%04d\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
    printf("Time: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
    printf("Invoice to: %s\n", customer_name);
    printLines();
    printHeaders();
    printLines();


    for (int i = 0; i < item_quantity; i++) {
        printf("%s", item_name[i]);
        int lenLeft = strlen(item_name[i]);
        int paddingCenter = (CONSOLE_WIDTH - lenLeft) / 2;
        for (int j = lenLeft; j < paddingCenter; j++) {
            putchar(' ');
        }
        printf("%.2f", unit_quantity[i]);
        int lenCenter = snprintf(NULL, 0, "%.2f", unit_quantity[i]);
        int paddingRight = CONSOLE_WIDTH - lenCenter - 7;
        for (int k = lenCenter + 1; k < paddingRight; k++) {
            putchar(' ');
        }
        printf("%.2f\n", price[i]);
    }

    return 0;
}
