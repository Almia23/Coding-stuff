#include <stdio.h>
#include <string.h>

#define MAX_ORDERS 100

typedef struct {
    int order_number;
    char customer_name[50];
} Order;

int main() {
    Order orders[MAX_ORDERS];
    int front = 0, rear = 0, order_number = 1;

    int M;
    printf("Enter the maximum number of orders (M): ");
    scanf("%d", &M);

    while (order_number <= M) {
        printf("Enter customer name for order #%d (or 'exit' to stop accepting orders): ", order_number);
        scanf("%s", orders[rear].customer_name);

        if (strcmp(orders[rear].customer_name, "exit") == 0)
            break;

        orders[rear].order_number = order_number;
        rear = (rear + 1) % MAX_ORDERS;
        order_number++;
    }

    printf("List of Orders:\n");
    for (int i = front; i != rear; i = (i + 1) % MAX_ORDERS) {
        printf("Order #%d: %s\n", orders[i].order_number, orders[i].customer_name);
    }

    return 0;
}
