#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& desc, int priority, const std::string& dueDate, bool completed = false);

    std::string getDescription() const;
    int getPriority() const;
    std::string getDueDate() const;
    bool isCompleted() const;

    void setDescription(const std::string& desc);
    void setPriority(int prio);
    void setDueDate(const std::string& date);
    void setCompleted(bool state);

    void display() const;

private:
    std::string description;
    int priority;
    std::string dueDate;
    bool completed;
};

#endif // TASK_H
