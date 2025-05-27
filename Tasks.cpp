#include <iostream>
#include <algorithm>
#include <vector>
#include "tasks.h"
using namespace std;
struct Task {
    string type;
    int number;
    int status;
};
int Tasks(int num_tasks)
{
    vector<Task> tasks;
    tasks.resize(num_tasks);
    for (int i = 0; i < num_tasks; ++i)
    {
        cout << "Задание номер " << i + 1 << endl;
        cout << "Вид: ";
        cin >> tasks[i].type;
        cout << "Номер: ";
        cin >> tasks[i].number;
        cout << "Статус (0 - не сделано, 1 - сделано): ";
        cin >> tasks[i].status;
        try {
            if (tasks[i].status != 0 && tasks[i].status != 1)
            {
                throw invalid_argument("Недопустимый статус выполнения. Допустимые значения: 0 или 1.");
            }
        }
        catch (const invalid_argument& error) {
            cerr << error.what() << endl;
            return 1;
        }
    }
    vector<Task> completed_tasks;
    vector<Task> incomplete_tasks;
    auto is_completed = [](const Task& task) {
        return task.status == 1;
        };
    partition_copy(tasks.begin(), tasks.end(), back_inserter(completed_tasks), back_inserter(incomplete_tasks), is_completed);
    cout << "\nЗавершенные задания:\n";
    for (const auto& el: completed_tasks) {
        cout << "Вид: " << el.type << " " << "Номер: " << el.number << endl;
    }
    cout << "\nНезавершенные задания:\n";
    for (const auto& el : incomplete_tasks)
    {
        cout << "Вид: " << el.type << " " << "Номер: " << el.number << endl;
    }
    return 0;
}
