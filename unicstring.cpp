#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "Alien.h"
using namespace std;
struct RoundData {
    char symbol;
    string myString;
};
int uniqueString() {
    setlocale(LC_ALL, "rus");
    cout << "Введите количество: ";
    int N;
    cin >> N;
    cin.ignore(); 
    vector<RoundData> rounds(N);
    for (int i = 0; i < N; ++i) {
        cin >> rounds[i].symbol;
        getline(cin >> ws, rounds[i].myString);
    }
    string allstring = "";
    for (const auto& e : rounds) {
        string tempString = e.myString; 
        tempString.erase(remove_if(tempString.begin(), tempString.end(),[&](char c) 
            { 
                return c == e.symbol;
            }),
            tempString.end());
        allstring += tempString;
    }
    vector<char> charsVector(allstring.begin(), allstring.end());
    sort(charsVector.begin(), charsVector.end());
    charsVector.erase(unique(charsVector.begin(), charsVector.end()), charsVector.end());
    string answer(charsVector.begin(), charsVector.end());
    cout << answer << endl;
    return 0;
}
 
