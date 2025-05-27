#include <vector>
#include <iostream>
using namespace std;
struct Student {
    string lastName;
    int score;
};
vector<Student> inputStudents(int count);
vector<Student> filterStudents(const vector<Student>& students, int threshold);
void theBest(int count1);
