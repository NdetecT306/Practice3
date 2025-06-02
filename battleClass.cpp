#include "Alien.h"
struct Student {
    string name;
    string surname;
    int score;
};
struct Class {
    string name;
    vector<Student> students;
};
int battleClass(){
    setlocale(LC_ALL, "rus");
    Class classA = {"11A",{
            {"Ivan", "Petrov", 85},
            {"Petr", "Sidorov", 92},
            {"Elena", "Ivanova", 92},
            {"Sergey", "Kuznetsov", 78}}};
    Class classB = {"11B",{
            {"Maria", "Smirnova", 95},
            {"Dmitry", "Volkov", 88},
            {"Anna", "Popova", 90},
            {"Alexey", "Grachev", 95}}};
    auto get_average_score = [](const Class& c) {
        if (c.students.empty()) return 0.0;
        int sum = 0;
        for (const auto& student : c.students) {
            sum += student.score;
        }
        return (double)sum / c.students.size();
        };
    vector<Class> classes = { classA, classB };
    auto best_class_it = max_element(classes.begin(), classes.end(),
        [&](const Class& a, const Class& b) {
            return get_average_score(a) < get_average_score(b);
        }
    );
    if (best_class_it == classes.end()) {
        cout << "Нет данных о классах." << endl;
        return 0;
    }
    Class& best_class = *best_class_it;
    auto compare_students = [](const Student& a, const Student& b) {
        if (a.score != b.score) {
            return a.score > b.score; 
        }
        return a.surname < b.surname; 
        };
 
    sort(best_class.students.begin(), best_class.students.end(), compare_students);
    cout << "Лучший класс: " << best_class.name << endl;
    if (!best_class.students.empty()) {
        cout << "Лучший ученик: " << best_class.students[0].name << " " << best_class.students[0].surname << endl;
    }
    else {
        cout << "В лучшем классе нет учеников." << endl;
    }
    auto worst_class_it = min_element(classes.begin(), classes.end(),
        [&](const Class& a, const Class& b) {
            return get_average_score(a) < get_average_score(b);
        }
    );
    if (worst_class_it == classes.end()) {
        cout << "Нет данных о классах." << endl;
        return 0;
    }
    Class& worst_class = *worst_class_it;
    auto compare_worst_students = [](const Student& a, const Student& b) {
        if (a.score != b.score) {
            return a.score < b.score; 
        }
        return a.surname < b.surname;
        };
    sort(worst_class.students.begin(), worst_class.students.end(), compare_worst_students);
    cout << "Худший класс: " << worst_class.name << endl;
    if (!worst_class.students.empty()) {
        cout << "Худший ученик: " << worst_class.students[0].name << " " << worst_class.students[0].surname << endl;
    }
    else {
        cout << "В худшем классе нет учеников." << endl;
    }
    return 0;
}
