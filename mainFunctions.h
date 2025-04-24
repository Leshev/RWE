// ������� ��� ����������� ����������� ���������
void setConsoleUTF8() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);      // ��� �����
    SetConsoleOutputCP(1251); // ��� ������
}

// ��������� ���� �������
void consoleWindowGeneration(){

    system("mode con:cols=80 lines=20");
    system("title Game Restore Word 2.0.0");
    system("color 000A");
    system("echo %DATE% %TIME%");

    // �������� ���������� �������
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // ������� ��������� ��� ���������� � ������
    CONSOLE_FONT_INFOEX fontInfo;

    // �������� ������� ���������� � ������
    GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);


    fontInfo.dwFontSize.X = 20;                             // ������������� ������ ������

    // ��������� ����� �����
    SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}

// ������� �������
void clearScreen(){
    system("cls");
}

// �������� ��������
void loadingAnimationDefault(int totalTime){
    using namespace std::chrono_literals;

    // ������������� ���������� ��������� �����
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 200); // �������� 2-10 ������ � ��
    std::uniform_int_distribution<> progressStep(1, 14); // �������� ����� ��������� 1-20

    int progress = 0;
    char bar[] = "|/-\\";
    int barIndex = 0;

    std::cout << "[";

    while (progress <= 100) {
        std::cout << "\r[" << progress << "%] " << bar[barIndex] << " ";
        std::cout.flush();

        // ��������� ��������� ��������
        int randomDelay = dis(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomDelay));

        // ��������� ���������� ���������� ���������
        int step = progressStep(gen);
        progress += step;
        if (progress >= 10 ) progress ++; // ����������� �� ��������

        barIndex = (barIndex + 1) % 8;
    }

    std::cout << "\r[100%]\n";
}

// �������� ������
void creatingPlayerPassword(const std::string& userName) {
    std::string password;
    std::string confirmPassword;
    bool validLength = false;
    restartCreatingFile2:
    do {
        std::cout << "�������� ����� ������ (�� ����� 6 ��������): ";
        std::cin >> password;
        //std::getline(std::cin, password);  // ������� ����� �� �������� ������

        if(password.size() <= 5) {
            std::cout << "������ ������� ��������! ������� ������� 6 ��������.\n";
        } else {
            validLength = true;
        }
    } while(!validLength);

    std::cout << "����������� ������: ";
    std::cin >> confirmPassword;

    if(password == confirmPassword) {
        // ��������� ���� � ����� "���������"
        std::string basePath = "RWEsave\\" + userName;
        std::string filename = userName + ".pass";
        std::string fullPath = basePath + "\\" + filename;

        // ��������� ������������� ���������� "���������"
        if (!std::filesystem::exists(basePath)) {
            try {
                std::filesystem::create_directories(basePath);
            } catch (const std::filesystem::filesystem_error& ex) {
                std::cerr << "������ �������� ����������: " << ex.what() << '\n';
                goto restartCreatingFile2;
            }
        }
        restartCreatingFile:
        // ������� ����
        std::ofstream file(fullPath);
            file << password;
        if (file.is_open()) {
            file.close();
        } else {
            std::cout << "������ �������� �����" << std::endl;
            goto restartCreatingFile;
        }
    }
}

// ������� �����������
void passwordVerificationSystem(const std::string& userName) {
    std::string pass;
    std::string buff;
    bool userCreated = false; // ���� �������� ������������

    do { // ��������� ���� ��� ����������� �������
        // ��������� ���� � ����� � ����� "
        std::string basePath = "RWEsave\\" + userName;
        std::string filename = userName + ".pass";
        std::string fullPath = basePath + "\\" + filename;


        try {
            // ��������� ������������� �����
            std::ifstream file(fullPath);
            if (file.is_open()) {
                // ���� ����������, ����������� ������
                std::cout << "������� ������: ";
                std::cin >> pass;

                // ������ ����������� ������
                file >> buff;
                file.close();

                // ���� 3 ������� ��� ����� ������
                for(int i = 0; i < 3; i++) {
                    if(buff == pass) {
                        std::cout << "������ ������!\n";
                        return;
                    } else {
                        if(i < 2) {  // ���������, �� ��������� �� �������
                            std::cout << "������ ��������! ���������� �����: ";
                            std::cin >> pass;
                        }
                    }
                }

                std::cout << "��������� ���������� ������� ����� ������\n";
                clearScreen();
                exit(1);  // ���������� ����� ��� ���������� �������
            } else {
                restartCreatingPlayer:
                // ���� ����� ��� - ������� ����� ������
                std::cout << "������������ �� ������. ������� ����� �������? 'y' ��� '��'\n";
                std::string creatingNewPlayer;
                std::cin >> creatingNewPlayer;

                if(creatingNewPlayer == "y" || creatingNewPlayer == "��"){
                    creatingPlayerPassword(userName);
                    userCreated = true;  // ���������� �����
                }
                else {
                    clearScreen();
                    goto restartCreatingPlayer; // ������������� ���� ��������
                }
                if(creatingNewPlayer == "exit" || creatingNewPlayer == "�����"){
                    clearScreen();
                    system("exit");
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "������: " << e.what() << '\n';
        }
    } while (!userCreated); // ���������, ���� ������������ �� ��� ������
}

// �������������� ���������
void printWelcome(const std::string& userName) {
    std::cout << "������ " << userName << "!" << std::endl;
}

// ������� �������� ����
void showMainMenu(const std::string& userName){
    clearScreen();
    std::cout << "\t---------------------------------------------------------- \n";
    std::cout << "\t\t����� ���������� � ���� ' " << userName << " '\n";
    std::cout << "\t���� ������ ������������ ����� ����������� �����\n";
    std::cout << "\t��� ���������� ���� ������� 'exit' ���� ������� �� �������\n";
    std::cout << "\t---------------------------------------------------------- \n";
    std::cout << "\t\t\t�������� ����!\n";
}
