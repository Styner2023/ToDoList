#include <iostream>
#include "ToDoList.h"

void displayMenu() {
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. View Tasks\n";
    std::cout << "4. Save Tasks\n";
    std::cout << "5. Load Tasks\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;
    std::string desc;
    int index;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // to ignore the newline character after the integer input

        switch (choice) {
        case 1:
            std::cout << "Enter task description: ";
            std::getline(std::cin, desc);
            todoList.addTask(desc);
            break;
        case 2:
            std::cout << "Enter task number to remove: ";
            std::cin >> index;
            todoList.removeTask(index - 1);
            break;
        case 3:
            todoList.displayTasks();
            break;
        case 4:
            todoList.saveToFile("tasks.txt");
            break;
        case 5:
            todoList.loadFromFile("tasks.txt");
            break;
        case 6:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
