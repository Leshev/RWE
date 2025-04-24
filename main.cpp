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


// �������� �������
int main() {
    setConsoleUTF8();
    consoleWindowGeneration();
    loadingAnimationDefault(70);

    // �������� ������� �������
    std::string userName;
    std::cout << "����� ���������� � ����!\n";
    std::cout << "������� ���� ���: ";
    std::cin >> userName;

    passwordVerificationSystem(userName);
    loadingAnimationDefault(50);
    showMainMenu(userName);

    // ������� �������
    enum Difficulty { EASY, MEDIUM, HARD };
    Difficulty selectedDifficulty;

    while (true) {
        std::cout << "\n�������� ���������:\n";
        std::cout << "a) �����\n";
        std::cout << "b) ������\n";
        std::cout << "c) ������\n";
        std::cout << "exit ��� ����� ��� ������\n";

        std::string choice;
        std::cin >> choice;
        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower); // �������� � ������� ��������

        if (choice == "a" || choice == "�") {
            selectedDifficulty = EASY;
            break;
        } else if (choice == "b" || choice == "�") {
            selectedDifficulty = MEDIUM;
            break;
        } else if (choice == "c" || choice == "�") {
            selectedDifficulty = HARD;
            break;
        } else if (choice == "exit" || choice == "�����") {
            std::cout << "�� ��������!\n";
            return 0;
        } else {
            std::cout << "������: �������� �����. ���������� �����.\n";
        }
    }

    // ������ ������
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
