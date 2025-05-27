#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <stdexcept>
#include "Intes.h"
#include "kilokalories.h"
#include "railway.h"
#include "tasks.h"
#include "random.h"
#include "thebest.h"
#include "headWithStrVec.h"
#include "rating.h" 
using namespace std;
enum class TaskNumber {
    TASK1 = 1,TASK2,TASK3,TASK4,TASK5,TASK6,TASK7,TASK8,TASK9,TASK10
};
int main() 
{
    setlocale(LC_ALL, "rus");
    int task;
    cout << "Номер задания (1-10): ";
    cin >> task;
    cin.ignore();
    TaskNumber tasks = static_cast<TaskNumber>(task);
    switch (tasks) 
    {
    case TaskNumber::TASK1: //  Расчет килокалориев
        KilKal();
        break;
    case TaskNumber::TASK2: { // Расчет кредита
        double summa;
        int month;
        try {
            cout << "Введите размер кредита в рублях: ";
            cin >> summa;
            if (summa <= 0) {
                throw runtime_error("Сумма не положительное число.");
            }
            cout << "Введите срок для оплаты кредита в месяцах: ";
            cin >> month;
            if (month <= 0) {
                throw runtime_error("Число месяцев не положительное число.");
            }
        }
        catch (const exception& error) {
            cerr << error.what() << endl;
            return 1;
        }
        Credit(summa, month);
        break;
    }
    case TaskNumber::TASK3: { // Расчет рейтинга студентов
        set<pair<string, double>> studentsSet;
        Rating(studentsSet);
        break;
    }
    case TaskNumber::TASK4: { //задания по программированию 
        int num_tasks;
        cout << "Количество заданий: ";
        cin >> num_tasks;
        Tasks(num_tasks);
        break;
    }
    case TaskNumber::TASK5: //Найди в строке строку
        String();
        break;
    case TaskNumber::TASK6: { //Расчет нагрузки на рельсы
        int n;
        cout << "Количество поездов: ";
        cin >> n;
        double totalLoad = AllTrains(n);
        cout << fixed << setprecision(3) << "Итого: " << totalLoad << endl;
        break;
    }
    case TaskNumber::TASK7: { //Игра с числами
        int numParties;
        cout << "Количество игр: ";
        cin >> numParties;
        if (numParties <= 0) {
            cout << "Это не положительное число." << endl;
            return 1;
        }
        Casino(numParties);
        break;
    }
    case TaskNumber::TASK8: { //Найди простые
        ProstoeChislo();
        break;
    }
    case TaskNumber::TASK9: {//Переводчик на инопланетный
        string englishSentence; 
        cout << "Введите текст (на английском): ";
        getline(cin, englishSentence);
        string alienSentence = alienTranslate(englishSentence);
        cout << "Господин переводчик сказал: " << alienSentence << endl;
        break;
    }
    case TaskNumber::TASK10: { //90 баллов
        int count1;
        cout << "Введите число сдающих: ";
        cin >> count1;
        if (count1 < 0) {
            cout << "Где ты видел такое количество учеников?" << endl;
            return 1;
        }
        theBest(count1);
        break;
    }
    default:
        cout << "Нет такого задания.\n";
        return 1;
    }
}
