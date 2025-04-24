#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <random>
#include "mainFunctions.h"
#include "levelA.h"
#include "levelB.h"
#include "levelC.h"

#ifndef SHARED_VARS_H
#define SHARED_VARS_H

extern int globalInt;
extern double globalDouble;
extern std::string globalString;

#endif

using namespace std;


// Основная функция
int main() {
    setConsoleUTF8();
    consoleWindowGeneration();
    loadingAnimationDefault(70);

    // Основной игровой процесс
    std::string userName;
    std::cout << "Добро пожаловать в игру!\n";
    std::cout << "Введите ваше имя: ";
    std::cin >> userName;

    passwordVerificationSystem(userName);
    loadingAnimationDefault(50);
    showMainMenu(userName);

    // Система уровней
    enum Difficulty { EASY, MEDIUM, HARD };
    Difficulty selectedDifficulty;

    while (true) {
        std::cout << "\nВыберите сложность:\n";
        std::cout << "a) Легко\n";
        std::cout << "b) Средне\n";
        std::cout << "c) Сложно\n";
        std::cout << "exit или выход для выхода\n";

        std::string choice;
        std::cin >> choice;
        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower); // приводим к нижнему регистру

        if (choice == "a" || choice == "а") {
            selectedDifficulty = EASY;
            break;
        } else if (choice == "b" || choice == "б") {
            selectedDifficulty = MEDIUM;
            break;
        } else if (choice == "c" || choice == "с") {
            selectedDifficulty = HARD;
            break;
        } else if (choice == "exit" || choice == "выход") {
            std::cout << "До свидания!\n";
            return 0;
        } else {
            std::cout << "Ошибка: неверный выбор. Попробуйте снова.\n";
        }
    }

    // Запуск уровня
    switch (selectedDifficulty) {
        case EASY:
            playLevelA(userName);
            break;
        case MEDIUM:
            playLevelB(userName);
            break;
        case HARD:
            playLevelC(userName);
            break;
    }

    FreeConsole();
    return 0;
}
