#ifndef TASK_OPS_H
#define TASK_OPS_H

#define MAX_TASKS 100
#define MAX_LENGTH 100

typedef struct {
    char description[MAX_LENGTH];
    int priority;
} Task;

extern Task taskList[MAX_TASKS];
extern int taskCount;

void add_task();
void view_tasks();
void update_task();
void save_tasks();
void load_tasks();

#endif