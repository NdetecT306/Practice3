#include <iostream>
#include <iomanip>
#include "Intes.h"
#include "railway.h"
#include "Alien.h"
#include "planes.h"
using namespace std;
enum class TaskNumber {
    Classes= 1,Language,Cofe,CARS,Trains,Serial,Uniq,CONSOLE,Uno,TASK
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
    case TaskNumber::Classes: {
        battleClass();
        break;
    }
    case TaskNumber::Language: 
    { 
        string englishSentence; 
        cout << "Введите текст (на английском): ";
        getline(cin, englishSentence);
        string alienSentence = alienTranslate(englishSentence);
        cout << "Господин переводчик сказал: " << alienSentence << endl;
        break;
    }
    case TaskNumber::Cofe: { 
        CoffeeShop();
        break;
    }
    case TaskNumber::CARS: { 
        Cars();
        break;
    }
    case TaskNumber::Trains:{
        int n;
        cout << "Количество поездов: ";
        cin >> n;
        double totalLoad = AllTrains(n);
        cout << fixed << setprecision(3) << "Итого: " << totalLoad << endl;
        break;
    }
    case TaskNumber::Serial: 
    { 
        Ninjago();
        break;
    }
    case TaskNumber::Uniq: { 
        uniqueString();
        break;
    }
    case TaskNumber::CONSOLE: { 
        Console();
        break;
    }
    case TaskNumber::Uno: {
        UNO();
        break;
    }
    case TaskNumber::TASK: { 
        int num_tasks;
        cout << "Количество заданий: ";
        cin >> num_tasks;
        Tasks(num_tasks);
        break;
    }
    default:
        cout << "Нет такого задания.\n";
        return 1;
    }
}
