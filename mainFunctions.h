// Функция для корректного отображения кириллицы
void setConsoleUTF8() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);      // для ввода
    SetConsoleOutputCP(1251); // для вывода
}

// настройка окна консоли
void consoleWindowGeneration(){

    system("mode con:cols=80 lines=20");
    system("title Game Restore Word 2.0.0");
    system("color 000A");
    system("echo %DATE% %TIME%");

    // Получаем дескриптор консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Создаем структуру для информации о шрифте
    CONSOLE_FONT_INFOEX fontInfo;

    // Получаем текущую информацию о шрифте
    GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);


    fontInfo.dwFontSize.X = 20;                             // Устанавливаем размер шрифта

    // Применяем новый шрифт
    SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}

// очистка консоли
void clearScreen(){
    system("cls");
}

// анимация загрузки
void loadingAnimationDefault(int totalTime){
    using namespace std::chrono_literals;

    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 200); // диапазон 2-10 секунд в мс
    std::uniform_int_distribution<> progressStep(1, 14); // диапазон шагов прогресса 1-20

    int progress = 0;
    char bar[] = "|/-\\";
    int barIndex = 0;

    std::cout << "[";

    while (progress <= 100) {
        std::cout << "\r[" << progress << "%] " << bar[barIndex] << " ";
        std::cout.flush();

        // Генерация случайной задержки
        int randomDelay = dis(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomDelay));

        // Генерация случайного приращения прогресса
        int step = progressStep(gen);
        progress += step;
        if (progress >= 10 ) progress ++; // ограничение на максимум

        barIndex = (barIndex + 1) % 8;
    }

    std::cout << "\r[100%]\n";
}

// создание пароля
void creatingPlayerPassword(const std::string& userName) {
    std::string password;
    std::string confirmPassword;
    bool validLength = false;
    restartCreatingFile2:
    do {
        std::cout << "Создайте новый пароль (не менее 6 символов): ";
        std::cin >> password;
        //std::getline(std::cin, password);  // очищаем буфер от переноса строки

        if(password.size() <= 5) {
            std::cout << "Пароль слишком короткий! Введите минимум 6 символов.\n";
        } else {
            validLength = true;
        }
    } while(!validLength);

    std::cout << "Подтвердите пароль: ";
    std::cin >> confirmPassword;

    if(password == confirmPassword) {
        // Формируем путь к папке "Документы"
        std::string basePath = "RWEsave\\" + userName;
        std::string filename = userName + ".pass";
        std::string fullPath = basePath + "\\" + filename;

        // Проверяем существование директории "Документы"
        if (!std::filesystem::exists(basePath)) {
            try {
                std::filesystem::create_directories(basePath);
            } catch (const std::filesystem::filesystem_error& ex) {
                std::cerr << "Ошибка создания директории: " << ex.what() << '\n';
                goto restartCreatingFile2;
            }
        }
        restartCreatingFile:
        // Создаем файл
        std::ofstream file(fullPath);
            file << password;
        if (file.is_open()) {
            file.close();
        } else {
            std::cout << "Ошибка создания файла" << std::endl;
            goto restartCreatingFile;
        }
    }
}

// система авторизаций
void passwordVerificationSystem(const std::string& userName) {
    std::string pass;
    std::string buff;
    bool userCreated = false; // Флаг создания пользователя

    do { // Добавляем цикл для возможности повтора
        // Формируем путь к файлу в папке "
        std::string basePath = "RWEsave\\" + userName;
        std::string filename = userName + ".pass";
        std::string fullPath = basePath + "\\" + filename;


        try {
            // Проверяем существование файла
            std::ifstream file(fullPath);
            if (file.is_open()) {
                // Файл существует, запрашиваем пароль
                std::cout << "Введите пароль: ";
                std::cin >> pass;

                // Читаем сохраненный пароль
                file >> buff;
                file.close();

                // Даем 3 попытки для ввода пароля
                for(int i = 0; i < 3; i++) {
                    if(buff == pass) {
                        std::cout << "Пароль принят!\n";
                        return;
                    } else {
                        if(i < 2) {  // Проверяем, не последняя ли попытка
                            std::cout << "Пароль неверный! Попробуйте снова: ";
                            std::cin >> pass;
                        }
                    }
                }

                std::cout << "Превышено количество попыток ввода пароля\n";
                clearScreen();
                exit(1);  // Безопасный выход при превышении попыток
            } else {
                restartCreatingPlayer:
                // Если файла нет - создаем новый пароль
                std::cout << "Пользователь не найден. Создаем новый аккаунт? 'y' или 'да'\n";
                std::string creatingNewPlayer;
                std::cin >> creatingNewPlayer;

                if(creatingNewPlayer == "y" || creatingNewPlayer == "да"){
                    creatingPlayerPassword(userName);
                    userCreated = true;  // Безопасный выход
                }
                else {
                    clearScreen();
                    goto restartCreatingPlayer; // Устанавливаем флаг создания
                }
                if(creatingNewPlayer == "exit" || creatingNewPlayer == "выход"){
                    clearScreen();
                    system("exit");
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << '\n';
        }
    } while (!userCreated); // Повторяем, если пользователь не был создан
}

// Приветственное сообщение
void printWelcome(const std::string& userName) {
    std::cout << "Привет " << userName << "!" << std::endl;
}

// функция главного меню
void showMainMenu(const std::string& userName){
    clearScreen();
    std::cout << "\t---------------------------------------------------------- \n";
    std::cout << "\t\tДобро пожаловать в игру ' " << userName << " '\n";
    std::cout << "\tВаша задача восстановить слово английского языка\n";
    std::cout << "\tДля завершения игры введите 'exit' либо нажмите на крестик\n";
    std::cout << "\t---------------------------------------------------------- \n";
    std::cout << "\t\t\tПриятной игры!\n";
}
