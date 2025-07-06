#include <stdio.h>
#include <stdlib.h>
#include "task_ops.h"

void menu() {
    printf("\n=== TASK SCHEDULER ===\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Update Task\n");
    printf("4. Save Tasks\n");
    printf("5. Load Tasks\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                update_task();
                break;
            case 4:
                save_tasks();
                break;
            case 5:
                load_tasks();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}