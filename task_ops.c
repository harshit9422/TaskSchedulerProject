#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_ops.h"

Task taskList[MAX_TASKS];
int taskCount = 0;

void add_task() {
    if (taskCount >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }

    printf("Enter task description: ");
    getchar(); // clear buffer
    fgets(taskList[taskCount].description, MAX_LENGTH, stdin);
    taskList[taskCount].description[strcspn(taskList[taskCount].description, "\n")] = '\0';

    printf("Enter task priority (1–5): ");
    scanf("%d", &taskList[taskCount].priority);

    taskCount++;
    printf("Task added successfully!\n");
}

void view_tasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- Task List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [Priority: %d]\n", i + 1, taskList[i].description, taskList[i].priority);
    }
}

void update_task() {
    if (taskCount == 0) {
        printf("No tasks to update.\n");
        return;
    }

    int index;
    printf("Enter task number to update: ");
    scanf("%d", &index);
    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // to 0-based
    getchar(); // clear buffer
    printf("Enter new description: ");
    fgets(taskList[index].description, MAX_LENGTH, stdin);
    taskList[index].description[strcspn(taskList[index].description, "\n")] = '\0';

    printf("Enter new priority (1–5): ");
    scanf("%d", &taskList[index].priority);

    printf("Task updated!\n");
}

void save_tasks() {
    FILE *fp = fopen("tasks.txt", "w");
    if (!fp) {
        printf("Error saving tasks.\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(fp, "%s,%d\n", taskList[i].description, taskList[i].priority);
    }

    fclose(fp);
    printf("Tasks saved to file.\n");
}

void load_tasks() {
    FILE *fp = fopen("tasks.txt", "r");
    if (!fp) {
        printf("No saved tasks found.\n");
        return;
    }

    taskCount = 0;
    while (fscanf(fp, " %99[^,],%d\n", taskList[taskCount].description, &taskList[taskCount].priority) == 2) {
        taskCount++;
    }

    fclose(fp);
    printf("Tasks loaded from file.\n");
}