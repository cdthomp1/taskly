#include "ToDoList.h"
#include <iostream>
#include "Taskly.h"

int main() {
    ToDoList todoList;
    int choice;

    todoList.loadFromFile("tasks.txt");
    std::cout << "\n";
    todoList.displayTasks();

    do {
        std::cout << "\nTo-Do List Manager\n"
            << "1. Add Task\n"
            << "2. Delete Task\n"
            << "3. Update Task\n"
            << "4. Mark Task as Complete\n"
            << "5. Mark Task as Incomplete\n"
            << "6. Save Tasks to File\n"
            << "7. Load Tasks from File\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            addTask(todoList);

            break;
        }
        case 2: {
            deleteTask(todoList);

            break;
        }
        case 3: {
            updateTask(todoList);

            break;
        }
        case 4: {
            completeTask(todoList);
            break;
        }
        case 5: {
            uncompleteTask(todoList);

            break;
        }
        case 6:
            todoList.saveToFile("tasks.txt");
            std::cout << "\n";

            break;
        case 7:
            todoList.loadFromFile("tasks.txt");
            std::cout << "\n";

            break;
        case 8:
            std::cout << "Exiting the application.\n";
            std::cout << "\n";

            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            std::cout << "\n";

            break;
        }

        todoList.displayTasks();
    } while (choice != 0);

    return 0;
}

void uncompleteTask(ToDoList& todoList)
{
    int index;
    std::cout << "Enter task number to mark as incomplete: ";
    std::cin >> index;
    todoList.markTaskCompleted(index - 1, false);
    std::cout << "\n";
}

void completeTask(ToDoList& todoList)
{
    int index;
    std::cout << "Enter task number to mark as complete: ";
    std::cin >> index;
    todoList.markTaskCompleted(index - 1, true);
    std::cout << "\n";
}

void updateTask(ToDoList& todoList) {
    int index;
    std::cout << "Enter task number to update: ";
    std::cin >> index;
    std::cin.ignore(); // Clear input buffer
    index -= 1; // Adjust for zero-based index

    // Check if the index is valid
    if (index < 0 || index >= todoList.getTaskCount()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    // Display the current task details
    const Task& currentTask = todoList.getTask(index);
    std::string desc = currentTask.getDescription();
    int priority = currentTask.getPriority();
    std::string dueDate = currentTask.getDueDate();

    // Ask user which field to update
    std::cout << "\nCurrent description: " << desc << "\n";
    std::cout << "Enter new description (or press Enter to keep current): ";
    std::string newDesc;
    std::getline(std::cin, newDesc);
    if (!newDesc.empty()) {
        desc = newDesc;
    }

    std::cout << "\nCurrent priority: " << priority << "\n";
    std::cout << "Enter new priority (1-5) (or press Enter to keep current): ";
    std::string priorityInput;
    std::getline(std::cin, priorityInput);
    if (!priorityInput.empty()) {
        priority = std::stoi(priorityInput); // Convert input to int
    }

    std::cout << "\nCurrent due date: " << dueDate << "\n";
    std::cout << "Enter new due date (or press Enter to keep current): ";
    std::string newDueDate;
    std::getline(std::cin, newDueDate);
    if (!newDueDate.empty()) {
        dueDate = newDueDate;
    }

    // Update the task with the new information
    todoList.updateTask(index, desc, priority, dueDate);
    std::cout << "\n";
}


void deleteTask(ToDoList& todoList)
{
    int index;
    std::cout << "Enter task number to delete: ";
    std::cin >> index;
    todoList.deleteTask(index - 1);
    std::cout << "\n";
}

void addTask(ToDoList& todoList)
{
    std::string desc, dueDate;
    int priority;

    std::cout << "Enter task description: ";
    std::getline(std::cin, desc);
    std::cout << "Enter task priority (1-5): ";
    std::cin >> priority;
    std::cin.ignore();
    std::cout << "Enter task due date: ";
    std::getline(std::cin, dueDate);

    Task newTask(desc, priority, dueDate);
    todoList.addTask(newTask);
    std::cout << "\n";
}
