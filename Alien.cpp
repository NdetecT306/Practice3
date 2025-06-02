#include "Alien.h"
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
