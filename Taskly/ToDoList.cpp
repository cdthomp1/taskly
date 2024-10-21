#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void ToDoList::addTask(const Task& task) {
    tasks.push_back(task);
    std::cout << "Task added successfully!\n";
}

void ToDoList::deleteTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + index);
    std::cout << "Task deleted successfully!\n";
}

void ToDoList::updateTask(int index, const std::string& desc, int priority, const std::string& dueDate) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks[index].setDescription(desc);
    tasks[index].setPriority(priority);
    tasks[index].setDueDate(dueDate);
    std::cout << "Task updated successfully!\n";
}

void ToDoList::displayTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << std::left << std::setw(5) << "No."
        << std::setw(30) << "Description"
        << std::setw(10) << "Priority"
        << std::setw(15) << "Due Date"
        << std::setw(12) << "Completed" << "\n";
    std::cout << std::string(75, '-') << "\n";

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << std::left << std::setw(5) << i + 1
            << std::setw(30) << tasks[i].getDescription()
            << std::setw(10) << tasks[i].getPriority()
            << std::setw(15) << tasks[i].getDueDate()
            << std::setw(12) << (tasks[i].isCompleted() ? "Yes" : "No") << "\n";
    }
}

void ToDoList::markTaskCompleted(int index, bool completed) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks[index].setCompleted(completed);
    std::cout << "Task " << (completed ? "marked as complete" : "marked as incomplete") << " successfully!\n";
}

void ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Could not open file for writing.\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.getDescription() << "\n"
            << task.getPriority() << "\n"
            << task.getDueDate() << "\n"
            << task.isCompleted() << "\n"; // Save completed state
    }
    file.close();
    std::cout << "Tasks saved to file successfully!\n";
}

void ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Could not open file for reading.\n";
        return;
    }

    tasks.clear();
    std::string desc, dueDate;
    int priority;
    bool completed;
    while (std::getline(file, desc)) {
        file >> priority;
        file.ignore();
        std::getline(file, dueDate);
        file >> completed;
        file.ignore();
        tasks.emplace_back(desc, priority, dueDate, completed);
    }
    file.close();
    std::cout << "Tasks loaded from file successfully!\n";
}

Task ToDoList::getTask(int index) const {
    return tasks.at(index); 
}

int ToDoList::getTaskCount() const {
    return tasks.size();
}
