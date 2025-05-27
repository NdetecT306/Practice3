#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <math.h>
#include "headWithStrVec.h"
using namespace std;
string reverseWord(const string& word)
{
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}
string alienTranslate(const string& sentence)
{
    stringstream ss(sentence);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    transform(words.begin(), words.end(), words.begin(), [](string w) {  
        return reverseWord(w);
    });
    reverse(words.begin(), words.end());
    string translatedSentence;
    for (const string& w : words) {
        translatedSentence += w + " ";
    }
    if (!translatedSentence.empty()) 
    {
        translatedSentence.pop_back();
    }
    return translatedSentence;
}
vector<double> PayInMonth(double summa, int month, double p) {
    const double P = p / 12;
    double summInMonth = (summa * P) / (1 - pow(1 + P, -month));
    vector<double> ItogoSumma(month);
    double peremSumma = summa;
    for (int i = 0; i < month; ++i) {
        double interest = peremSumma * P;
        double needen = summInMonth - interest;
        ItogoSumma[i] = summInMonth; 
        peremSumma -= needen;
    }
    return ItogoSumma;
}
