
// уровень игры А
void playLevelA(const std::string& userName) {
    int points;
    int loadPointPlayer;
    std::ifstream fin(userName + ".pa");
    if (fin.is_open()) {
        fin >> loadPointPlayer;
        points = loadPointPlayer;
    } else {
        points = 0;
    }

    std::cout << "Загрузка уровня. Ваши баллы = " << points << std::endl;
    system("cls");
    std::cout << "\n--------------------\n";
    std::cout << "Вы на сложности А. Ваши баллы = " << points << std::endl;

    enum fields {WORD, TRANSLATION, NUM_FIELDS};
    const int NUM_WORDS =60;
    const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {
    {"man", " 'Мужчина' по-английски"},
    {"time", " 'Время' по-английски"},
    {"hand", " 'Рука' по-английски"},
    {"eye", " 'Глаз' по-английски"},
    {"thing", " 'Вещь' по-английски"},
    {"face", " 'Лицо' по-английски"},
    {"door", " 'Дверь' по-английски"},
    {"head", " 'Голова' по-английски"},
    {"day", " 'День' по-английски"},
    {"people", " 'Люди' по-английски"},
    {"room", " 'Комната' по-английски"},
    {"woman", " 'Женщина' по-английски"},
    {"year", " 'Год' по-английски"},
    {"place", " 'Место' по-английски"},
    {"life", " 'Жизнь' по-английски"},
    {"night", " 'Ночь' по-английски"},
    {"foot", " 'Ступня/нога' по-английски"},
    {"word", " 'Слово' по-английски"},
    {"house", " 'Дом' по-английски"},
    {"world", " 'Мир' по-английски"},
    {"arm", " 'Рука' по-английски"},
    {"father", " 'Папа' по-английски"},
    {"wall", " 'Стена' по-английски"},
    {"work", " 'Работа' по-английски"},
    {"body", " 'Тело' по-английски"},
    {"water", " 'Вода' по-английски"},
    {"minute", " 'Минута' по-английски"},
    {"name", " 'Имя' по-английски"},
    {"lot", " 'Большое количество/участок земли' по-английски"},
    {"friend", " 'Друг' по-английски"},
    {"car", " 'Машина' по-английски"},
    {"girl", " 'Девушка' по-английски"},
    {"hour", " 'Час' по-английски"},
    {"end", " 'Конец' по-английски"},
    {"boy", " 'Мальчик' по-английски"},
    {"mother", " 'Мама' по-английски"},
    {"table", " 'Стол' по-английски"},
    {"part", " 'Часть/роль' по-английски"},
    {"window", " 'Окно' по-английски"},
    {"hair", " 'Волосы/волос' по-английски"},
    {"way", " 'Путь' по-английски"},
    {"moment", " 'Момент' по-английски"},
    {"side", " 'Сторона' по-английски"},
    {"ship", " 'Корабль' по-английски"},
    {"air", " 'Воздух' по-английски"},
    {"front", " 'Передняя часть/фасад' по-английски"},
    {"set", " 'Набор' по-английски"},
    {"sound", " 'Звук' по-английски"},
    {"matter", " 'Вопрос для рассмотрения/дело' по-английски"},
    {"line", " 'Линия' по-английски"},
    {"finger", " 'Палец' по-английски"},
    {"fire", " 'Огонь' по-английски"},
    {"idea", " 'Идея' по-английски"},
    {"case", " 'Случай/ситуация' по-английски"},
    {"guy", " 'Парень' по-английски"},
    {"office", " 'Офис/кабинет' по-английски"},
    {"reason", " 'Причина' по-английски"},
    {"rest", " 'Оставшаяся часть/отдых' по-английски"},
    {"heart", " 'Сердце' по-английски"},
    {"fact", " 'Факт' по-английски"},
    };

    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        int choice = (rand() % NUM_WORDS);
        std::string theWord = WORDS[choice][WORD];
        std::string theTranslation = WORDS[choice][TRANSLATION];

        std::string jumble = theWord;
        int length = jumble.size();

        // Генератор перемешивания букв
        do {
            for (int i = 0; i < length; i++) {
                int index1 = (rand() % length);
                int index2 = (rand() % length);
                std::swap(jumble[index1], jumble[index2]);
            }
        } while (jumble == theWord);

  // Основная игра
  std::cout << "--------------------------------------------------------------";
  std::cout << "\n(Можно использовать подсказку командами и числом на конце\n 'hint1-3' 'подсказка1-3')\n\n";
  std::cout << "--------------------------------------------------------------\n";
std::cout << "( " + jumble + " ) " + theTranslation + "\nВаш вариант: ";
std::string guess;
std::cin >> guess;

while (guess != theWord) {
    if (guess == "exit") {
        std::cout << "--------------------------------------------------------------";
        std::cout << "\nИгра принудительно завершена пользователем!\nСпасибо за игру\nВаш счет: " << points << std::endl;
        std::cout << "--------------------------------------------------------------\n";
        system("timeout /t 3 >nul");
        return;
    }

    if (guess == "hint" || guess == "подсказка" ) {
        std::cout << "Подсказка: первая буква - '" << theWord[0] << "'\n";
        std::cout << "Ваши догадки: ";
        std::cin >> guess;
        continue;
    }
    else if (guess == "hint2" || guess == "подсказка2" ) {
        std::cout << "Подсказка: вторая буква - '" << theWord[1] << "'\n";
        std::cout << "Ваши догадки: ";
        std::cin >> guess;
        continue;
    }
    else if (guess == "hint3" || guess == "подсказка3" ) {
        std::cout << "Подсказка: третья буква и это ваша последняя подсказка - '" << theWord[2] << "'\n";
        std::cout << "Ваши догадки: ";
        std::cin >> guess;
        continue;
    }
    else {
        std::cout << "Неверно! Попробуйте еще раз.\n";
        std::cout << "Ваши догадки: ";
        points--;
        std::cout << "Баланс: " << points << std::endl;
        if(points <= -1 ){
            std::cout << "Ваш баланс: " << points << std::endl;
            std::cout << "Game over! " << std::endl;
            std::string restartLevelNew;
            std::cout << "Начать сначала? y-да_n-нет" << std::endl;
            std::cin >> restartLevelNew;
            if (restartLevelNew == "y" || restartLevelNew == "да"){
                clearScreen();
            }else{
                clearScreen();
                return;
            }

        }
        std::cin >> guess;
    }
}
// Если угадали
std::cout << "Правильно! Вы угадали слово!\n";
points++; // Добавляем очко за правильный ответ
std::cout << "Ваш текущий счет: " << points << std::endl;
        std::ofstream pointSave(userName + ".pa");
        pointSave << points << std::endl;
        pointSave.close();
        loadingAnimationDefault(10);
        clearScreen();
        }

        // Меню после уровня
        std::string restart;
        std::cout << "\nПродолжаем? y-да, n-нет\nвыбор уровня res\n";
        std::cin >> restart;
        system("cls");
        if (restart == "n") {
            std::cout << "Завершение\n";
            std::cout << "Спасибо за игру\n";
            std::cout << "За этот уровень вы набрали ( " << points;

            if (points == 1) {
                std::cout << " = ) Балл\n";
            } else if (points >= 2 && points <= 4) {
                std::cout << " = ) Балла\n";
            } else {
                std::cout << " = ) Баллов\n";
            }

            std::cout << "\nУдачи!" << std::endl;
            return;
        }
    }

