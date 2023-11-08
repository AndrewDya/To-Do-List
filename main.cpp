#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void printTasks(const std::vector<Task>& tasks) {
    std::cout << "Список задач:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (i + 1) << ". ";
        if (tasks[i].completed) {
            std::cout << "[x] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    std::string command;

    while (true) {
        std::cout << "Введите команду (добавить/удалить/выход): ";
        std::cin >> command;

        if (command == "добавить") {
            std::string description;
            std::cout << "Введите описание задачи: ";
            std::cin.ignore(); // Очистить буфер ввода
            std::getline(std::cin, description);

            Task task;
            task.description = description;
            task.completed = false;
            tasks.push_back(task);
            std::cout << "Задача добавлена." << std::endl;
        } else if (command == "удалить") {
            int index;
            std::cout << "Введите номер задачи для удаления: ";
            std::cin >> index;

            if (index >= 1 && index <= tasks.size()) {
                tasks.erase(tasks.begin() + index - 1);
                std::cout << "Задача удалена." << std::endl;
            } else {
                std::cout << "Ошибка: недопустимый номер задачи." << std::endl;
            }
        } else if (command == "выход") {
            break;
        } else {
            std::cout << "Ошибка: недопустимая команда." << std::endl;
        }

        printTasks(tasks);
    }

    return 0;
}
