#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <vector>
#include <string>

class ToDoList {
public:
    void addTask(const Task& task);
    void deleteTask(int index);
    void updateTask(int index, const std::string& desc, int priority, const std::string& dueDate);
    void displayTasks() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void markTaskCompleted(int index, bool completed);
    Task getTask(int index) const;
    int getTaskCount() const;

private:
    std::vector<Task> tasks;
};

#endif // TODOLIST_H
