
// ������� ���� B
void playLevelB(const std::string& userName) {
    int points;
    int loadPointPlayer;
    std::ifstream fin(userName + ".pb");
    if (fin.is_open()) {
        fin >> loadPointPlayer;
        points = loadPointPlayer;
    } else {
        points = 0;
    }
    std::cout << "�������� ������. ���� ����� = " << points << std::endl;
    system("cls");
    std::cout << "\n--------------------\n";
    std::cout << "�� �� ��������� �. ���� ����� = " << points << std::endl;

    enum fields {WORD, TRANSLATION, NUM_FIELDS};
    const int NUM_WORDS = 100;
    const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"voice", "'�����' �� ���� "},
        {"shoulder", "'�����' �� ���� "},
        {"stone", "'������' �� ���� "},
        {"humen", "'�������' �� ���� "},
        {"death", "'������' �� ���� "},
        {"ground", "'�����/�����' �� ���� "},
        {"power", "'���������/����' �� ���� "},
        {"chance", "'����' �� ���� "},
        {"point", "'�����' �� ���� "},
        {"gun", "'��������/�����' �� ���� "},
        {"sense", "'�������' �� ���� "},
        {"thought", "'�����' �� ���� "},
        {"breath", "'�������' �� ���� "},
        {"step", "'���' �� ���� "},
        {"lip", "'����' �� ���� "},
        {"trouble", "'����' �� ���� "},
        {"talk", "'��������' �� ���� "},
        {"couple", "'����' �� ���� "},
        {"fear", "'�����' �� ���� "},
        {"officer", "'������' �� ���� "},
        {"weapon", "'������' �� ���� "},
        {"control", "'��������' �� ���� "},
        {"force", "'�����������' �� ���� "},
        {"master", "'������' �� ���� "},
        {"darkness", "'�������' �� ���� "},
        {"chest", "'�����/������' �� ���� "},
        {"deal", "'������' �� ���� "},
        {"expression", "'���������' �� ���� "},
        {"shot", "'�������/����' �� ���� "},
        {"strength", "'���������' �� ���� "},
        {"agent", "'�����' �� ���� "},
        {"anger", "'����' �� ���� "},
        {"chief", "'���������' �� ���� "},
        {"spirit", "'���' �� ���� "},
        {"cell", "'������' �� ���� "},
        {"movement", "'��������' �� ���� "},
        {"evidence", "'�������������' �� ���� "},
        {"flame", "'�����' �� ���� "},
        {"base", "'����' �� ���� "},
        {"risk", "'����' �� ���� "},
    {"man", " '�������' ��-���������"},
    {"time", " '�����' ��-���������"},
    {"hand", " '����' ��-���������"},
    {"eye", " '����' ��-���������"},
    {"thing", " '����' ��-���������"},
    {"face", " '����' ��-���������"},
    {"door", " '�����' ��-���������"},
    {"head", " '������' ��-���������"},
    {"day", " '����' ��-���������"},
    {"people", " '����' ��-���������"},
    {"room", " '�������' ��-���������"},
    {"woman", " '�������' ��-���������"},
    {"year", " '���' ��-���������"},
    {"place", " '�����' ��-���������"},
    {"life", " '�����' ��-���������"},
    {"night", " '����' ��-���������"},
    {"foot", " '������/����' ��-���������"},
    {"word", " '�����' ��-���������"},
    {"house", " '���' ��-���������"},
    {"world", " '���' ��-���������"},
    {"arm", " '����' ��-���������"},
    {"father", " '����' ��-���������"},
    {"wall", " '�����' ��-���������"},
    {"work", " '������' ��-���������"},
    {"body", " '����' ��-���������"},
    {"water", " '����' ��-���������"},
    {"minute", " '������' ��-���������"},
    {"name", " '���' ��-���������"},
    {"lot", " '������� ����������/������� �����' ��-���������"},
    {"friend", " '����' ��-���������"},
    {"car", " '������' ��-���������"},
    {"girl", " '�������' ��-���������"},
    {"hour", " '���' ��-���������"},
    {"end", " '�����' ��-���������"},
    {"boy", " '�������' ��-���������"},
    {"mother", " '����' ��-���������"},
    {"table", " '����' ��-���������"},
    {"part", " '�����/����' ��-���������"},
    {"window", " '����' ��-���������"},
    {"hair", " '������/�����' ��-���������"},
    {"way", " '����' ��-���������"},
    {"moment", " '������' ��-���������"},
    {"side", " '�������' ��-���������"},
    {"ship", " '�������' ��-���������"},
    {"air", " '������' ��-���������"},
    {"front", " '�������� �����/�����' ��-���������"},
    {"set", " '�����' ��-���������"},
    {"sound", " '����' ��-���������"},
    {"matter", " '������ ��� ������������/����' ��-���������"},
    {"line", " '�����' ��-���������"},
    {"finger", " '�����' ��-���������"},
    {"fire", " '�����' ��-���������"},
    {"idea", " '����' ��-���������"},
    {"case", " '������/��������' ��-���������"},
    {"guy", " '������' ��-���������"},
    {"office", " '����/�������' ��-���������"},
    {"reason", " '�������' ��-���������"},
    {"rest", " '���������� �����/�����' ��-���������"},
    {"heart", " '������' ��-���������"},
    {"fact", " '����' ��-���������"},
    };

    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        int choice = (rand() % NUM_WORDS);
        std::string theWord = WORDS[choice][WORD];
        std::string theTranslation = WORDS[choice][TRANSLATION];

        std::string jumble = theWord;
        int length = jumble.size();

        // ��������� ������������� ����
        do {
            for (int i = 0; i < length; i++) {
                int index1 = (rand() % length);
                int index2 = (rand() % length);
                std::swap(jumble[index1], jumble[index2]);
            }
        } while (jumble == theWord);

  // �������� ����
  std::cout << "--------------------------------------------------------------";
  std::cout << "\n(����� ������������ ��������� ��������� � ������ �� �����\n 'hint1-3' '���������1-3')\n\n";
  std::cout << "--------------------------------------------------------------\n";
std::cout << "( " + jumble + " ) " + theTranslation + "\n��� �������: ";
std::string guess;
std::cin >> guess;

while (guess != theWord) {
    if (guess == "exit") {
        std::cout << "--------------------------------------------------------------";
        std::cout << "\n���� ������������� ��������� �������������!\n������� �� ����\n��� ����: " << points << std::endl;
        std::cout << "--------------------------------------------------------------\n";
        system("timeout /t 3 >nul");
        return;
    }

    if (guess == "hint" || guess == "���������" ) {
        std::cout << "���������: ������ ����� - '" << theWord[0] << "'\n";
        std::cout << "���� �������: ";
        std::cin >> guess;
        continue;
    }
    else if (guess == "hint2" || guess == "���������2" ) {
        std::cout << "���������: ������ ����� - '" << theWord[1] << "'\n";
        std::cout << "���� �������: ";
        std::cin >> guess;
        continue;
    }
    else if (guess == "hint3" || guess == "���������3" ) {
        std::cout << "���������: ������ ����� � ��� ���� ��������� ��������� - '" << theWord[2] << "'\n";
        std::cout << "���� �������: ";
        std::cin >> guess;
        continue;
    }
    else {
        std::cout << "�������! ���������� ��� ���.\n";
        std::cout << "���� �������: ";
        points--;
        std::cout << "������: " << points << std::endl;
        if(points <= -1 ){
            std::cout << "��� ������: " << points << std::endl;
            std::cout << "Game over! " << std::endl;
            std::string restartLevelNew;
            std::cout << "������ �������? y-��_n-���" << std::endl;
            std::cin >> restartLevelNew;
            if (restartLevelNew == "y" || restartLevelNew == "��"){
                clearScreen();
            }else{
                clearScreen();
                return;
            }

        }
        std::cin >> guess;
    }
}
// ���� �������
std::cout << "���������! �� ������� �����!\n";
points++; // ��������� ���� �� ���������� �����
std::cout << "��� ������� ����: " << points << std::endl;
        std::ofstream pointSave(userName + ".pb");
        pointSave << points << std::endl;
        pointSave.close();
        loadingAnimationDefault(10);
        clearScreen();
        }

        // ���� ����� ������
        std::string restart;
        std::cout << "\n����������? y-��, n-���\n����� ������ res\n";
        std::cin >> restart;
        system("cls");
        if (restart == "n") {
            std::cout << "����������\n";
            std::cout << "������� �� ����\n";
            std::cout << "�� ���� ������� �� ������� ( " << points;

            if (points == 1) {
                std::cout << " = ) ����\n";
            } else if (points >= 2 && points <= 4) {
                std::cout << " = ) �����\n";
            } else {
                std::cout << " = ) ������\n";
            }

            std::cout << "\n�����!" << std::endl;
            return;
        }
    }

