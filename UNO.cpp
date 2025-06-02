#include "planes.h"
using namespace std;
struct Card {
    string color;
    string value;
    friend ostream& operator<<(ostream& os, const Card& card) {
        os << card.color << " " << card.value;
        return os;
    }
    bool operator<(const Card& other) const {
        if (color != other.color) {
            return color < other.color;
        }
        return value < other.value;
    }
    bool operator==(const Card& other) const {  
        return (color == other.color && value == other.value);
    }
};
vector<Card> createDeck() {
    vector<Card> deck;
    vector<string> colors = { "red", "green", "blue", "yellow" };
    vector<string> values = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "skip", "reverse", "draw2" };
    for (const string& color : colors) {
        for (const string& value : values) {
            deck.push_back({ color, value });
            if (value != "0") {
                deck.push_back({ color, value });
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        deck.push_back({ "black", "wild" });
        deck.push_back({ "black", "wild_draw4" });
    }
    return deck;
}
vector<vector<Card>> dealCards(int numPlayers, vector<Card>& deck, int cardsPerPlayer = 7) {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
    vector<vector<Card>> hands(numPlayers);
    for (int i = 0; i < numPlayers; ++i) {
        for (int j = 0; j < cardsPerPlayer; ++j) {
            hands[i].push_back(deck.back());
            deck.pop_back();
        }
    }
    return hands;
}
int UNO() {
    setlocale(LC_ALL, "rus");
    int numPlayers = 4;
    vector<Card> deck = createDeck();
    vector<vector<Card>> hands = dealCards(numPlayers, deck);
    auto countUniqueCards = [](vector<Card>& hand) {
        sort(hand.begin(), hand.end()); 
        auto last = unique(hand.begin(), hand.end()); 
        hand.erase(last, hand.end()); 
        return hand.size();
        };
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Игрок " << i + 1 << ":\n";
        for (const auto& card : hands[i]) {
            cout << card << "  ";
        }
        cout << "\nУникальных карт: " << countUniqueCards(hands[i]) << std::endl;
        cout << endl;
    }
    string targetColor;
    cout << "Введите цвет для анализа (red, green, blue, yellow): ";
    cin >> targetColor;
    int maxColorCount = 0;
    int playerWithMaxColor = -1;
    for (int i = 0; i < numPlayers; ++i) {
        int colorCount = 0;
        for (const auto& card : hands[i]) {
            if (card.color == targetColor) {
                colorCount++;
            }
        }
        if (colorCount > maxColorCount) {
            maxColorCount = colorCount;
            playerWithMaxColor = i;
        }
    }
    if (playerWithMaxColor != -1) {
        cout << "У игрока " << playerWithMaxColor + 1 << " больше всего карт цвета " << targetColor << " (" << maxColorCount << ")" << endl;
    }
    else {
        cout << "Ни у одного игрока нет карт цвета " << targetColor << "." << endl;
    }
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Игрок " << i + 1 << endl;
        sort(hands[i].begin(), hands[i].end());
        for (const auto& card : hands[i]) {
            cout << card << "  ";
        }
        cout << endl;
    }
    map<string, int> colorCounts;
    for (const auto& hand : hands) {
        for (const auto& card : hand) {
            colorCounts[card.color]++;
        }
    }
    cout << "Суммарное количество карт каждого цвета:" << endl;
    for (const auto& pair : colorCounts) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
