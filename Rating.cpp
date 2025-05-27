#include <iostream>
#include <algorithm>
#include <iomanip>
#include <array>
#include "rating.h" 
const int St = 3;
using namespace std;
struct StudentRating
{
    string lastName;
    double mark;
};
int Rating(set<pair<string, double>>& studentsSet)
{
    cout << "Всего в борьбе участвуют " << St << " студентов." << endl;
    try
    {
        for (int i = 0; i < St; ++i) {
            string lastName;
            double mark;
            cout << "Введите фамилию студента: ";
            cin >> lastName;
            cout << "Его средний балл: ";
            cin >> mark;
            if (mark < 0 || mark > 100) {
                throw invalid_argument("Средний балл должен быть в диапазоне от 0 до 100.");
            }
            studentsSet.insert({ lastName, mark });
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    vector<StudentRating> students;
    for (const auto& e : studentsSet) {
        students.push_back({e.first, e.second});
    }
    sort(students.begin(), students.end(), [](const StudentRating& a, const StudentRating& b) {
        return a.mark > b.mark; 
    });
    cout << "\nОтсортированный список студентов:\n";
    for (const auto& student : students) { 
        cout << "Фамилия: " << student.lastName << ", Средний балл: " << student.mark << endl;
    }
    return 0;
}
