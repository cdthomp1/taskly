#include "Task.h"
#include <iostream>

Task::Task(const std::string& desc, int priority, const std::string& dueDate, bool completed)
    : description(desc), priority(priority), dueDate(dueDate), completed(completed) {}

std::string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
std::string Task::getDueDate() const { return dueDate; }
bool Task::isCompleted() const { return completed; }

void Task::setDescription(const std::string& desc) { description = desc; }
void Task::setPriority(int prio) { priority = prio; }
void Task::setDueDate(const std::string& date) { dueDate = date; }
void Task::setCompleted(bool state) { completed = state; }

void Task::display() const {
    std::cout << "Description: " << description << "\n"
              << "Priority: " << priority << "\n"
              << "Due Date: " << dueDate << "\n"
              << "Completed: " << (completed ? "Yes" : "No") << "\n";
}
