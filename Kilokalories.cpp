#include <iostream>
#include <algorithm>
#include <vector>
#include "kilokalories.h"
using namespace std;
struct Person{
    string gender;
    double height;
    double weight;
    int age;
};
int KilKal(){
    Person person;
    cout << "Введите пол (на английском): ";
    cin >> person.gender;
    transform(person.gender.begin(), person.gender.end(), person.gender.begin(), ::tolower);
    if (person.gender != "male" && person.gender != "female"){
        cerr << "Мы здесь за 2 гендера." << endl;
        return 1;
    }
    cout << "Введите возраст: ";
    cin >> person.age;
    if (person.age <= 0){
        cerr << "Возраст должен быть положительным числом." << endl;
        return 1;
    }
    cout << "Введите рост в сантиметрах: ";
    cin >> person.height;
    if (person.height <= 0){
        cerr << "Рост должен быть положительным числом." << endl;
        return 1;
    }
    cout << "Введите вес в килограммах: ";
    cin >> person.weight;
    if (person.weight <= 0){
        cerr << "Вес должен быть положительным числом." << endl;
        return 1;
    }
    auto calculate_bmr = [](const Person& p) -> double {
        if (p.gender == "male"){
            return 88.362 + (13.397 * p.weight) + (4.799 * p.height) - (5.677 * p.age);
        }
        else{
            return 447.593 + (9.247 * p.weight) + (3.098 * p.height) - (4.330 * p.age);
        }
    };
    try{
        double bmr = calculate_bmr(person);
        cout << "Ваш BMR (основной обмен веществ): " << bmr << " ккал" << endl;
    }
    catch (const runtime_error& error){
        cerr << error.what() << endl;
        return 1;
    }
    return 0;
}
