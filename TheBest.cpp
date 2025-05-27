#include "thebest.h"
#include <map>
#include <stdexcept>
#include <algorithm>
using namespace std;
vector<Student> inputStudents(int count)
{
    vector<Student> students;
    for (int i = 0; i < count; ++i) {
        Student s;
        cout << "Введите данные ученика " << i + 1 << " (Фамилия, баллы): ";
        cin >> s.lastName >> s.score;
        if (s.score < 0 || s.score > 100) {
            cout << "Неправильные баллы." << endl;
            return {};
        }
        students.push_back(s);
    }
    return students;
}
vector<Student> filterStudents(const vector<Student>& students, int threshold) {
    vector<Student> filtered;
    auto isAboveThreshold = [threshold](const Student& s) { 
        return s.score > threshold; 
    };
    copy_if(students.begin(), students.end(), back_inserter(filtered), isAboveThreshold);
    return filtered;
}
void theBest(int count1) {
    vector<Student> class1;
    class1 = inputStudents(count1);
    if(class1.empty()) return;
    vector<Student> class1Filtered = filterStudents(class1, 90);
    map<string, int> studentMap;
    for (const auto& student : class1Filtered) {
        if (studentMap.find(student.lastName) == studentMap.end() || student.score > studentMap[student.lastName]) {
            studentMap[student.lastName] = student.score;
        }
    }
    cout << "\nСтуденты, у которых больше 90 баллов:" << endl;
    if (studentMap.empty()) {
        cout << "Not Found." << endl;
    } 
    else {
        for (const auto& pair : studentMap) {
            cout << "Фамилия: " << pair.first << " Баллы: " << pair.second << endl;
        }
    }
}
