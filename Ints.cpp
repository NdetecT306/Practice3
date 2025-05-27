#include "Intes.h"
#include "random.h"
#include "headWithStrVec.h"
#include <array>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
const int N = 10;
using namespace std;
using namespace std;
const double p1 = 0.25;
const double p2 = 0.49;
int Casino(int numParties){
    vector<int> initialVal;
    vector<int> transformedVal;
    set<int> doubledVal;
    for (int i = 0; i < numParties; ++i){
        int inputValue;
        cout << "Введите число: ";
        cin >> inputValue;
        if (inputValue <= 0) {
            cout << "It is not a right number" << endl;
            return 1;
        }
        initialVal.push_back(inputValue);
    }
    for (int value : initialVal) {
        int choice = RandomNumbers(0, 2);
        switch (choice) {
        case 0:
            transformedVal.push_back(value * 2);
            break;
        case 1:
            transformedVal.push_back(value / 2);
            break;
        case 2:
            transformedVal.push_back(value);
            break;
        }
    }
    auto isDoubled = [&](int transformedVal, int originalValue) {
        return transformedVal == originalValue * 2;
        };
    for (int i = 0; i < initialVal.size(); ++i) {
        if (isDoubled(transformedVal[i], initialVal[i])) {
            doubledVal.insert(initialVal[i]);
        }
    }
    int initialSum = accumulate(initialVal.begin(), initialVal.end(), 0);
    int transformedSum = accumulate(transformedVal.begin(), transformedVal.end(), 0);
    cout << "Сумма твоих чисел: " << initialSum << endl << "Итоговая сумма: " << transformedSum << endl << "Удвоенные значения (исходные):" << endl;
    for (int e : doubledVal) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
int Credit(double summa, int month) {
    vector<double> monthlyPay1 = PayInMonth(summa, month, p1);
    vector<double> monthlyPay2 = PayInMonth(summa, month, p2);
    double pay1 = monthlyPay1[0], pay2 = monthlyPay2[0]; 
    auto minMax1 = minmax_element(monthlyPay1.begin(), monthlyPay1.end());
    auto minMax2 = minmax_element(monthlyPay2.begin(), monthlyPay2.end());
    double maxPay = *minMax2.second, minPay = *minMax1.first;;
    auto calculateTotalPayment = [&](const vector<double>& payments) -> double {
        double total = 0.0;
        for (double payment : payments) {
            total += payment;
        }
        return total;
    };
    double totSumma1 = calculateTotalPayment(monthlyPay1), totSumma2 = calculateTotalPayment(monthlyPay2);
    cout << fixed << setprecision(5) << "Ежемесячный платеж при минимальной ставке - " << minPay << " руб., а при максимальной - " << maxPay << " руб." << endl;
    cout << "Кроме самого кредита, нужно будет выплатить " << totSumma1 - summa << " руб. при минимальной и " << totSumma2 - summa << " руб. при максимальной." << endl;
    return 0;
}
int ProstoeChislo()
{
    array<int, N> numbers;
    cout << "Введите 10 чисел: " << endl;
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    vector<int> prostNum(numbers.begin(), numbers.end());
    auto is_not_prime = [](int n) {
        if (n <= 1) return true;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) return true;
        }
        return false;
        };
    prostNum.erase(remove_if(prostNum.begin(), prostNum.end(), is_not_prime), prostNum.end());
    cout << "Простые числа: ";
    for (int e : prostNum) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}

int String()
{
    string sequence;
    string target;
    cout << "Введите последовательность цифр: ";
    cin >> sequence;
    try {
        for (char c : sequence) {
            if (!isdigit(c)) {
                throw invalid_argument("Читать умеешь? Нужны только цифры.");
            }
        }
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
    cout << "Введите строку, которую нужно найти (цифры): ";
    cin >> target;
    try {
        for (char c : target) {
            if (!isdigit(c)) {
                throw invalid_argument("Как ты в строке из цифр найдешь не цифру?");
            }
        }
    }
    catch (const invalid_argument& error)
    {
        cerr << error.what() << endl;
        return 1;
    }
    auto findStr = [&](const string& seq, const string& sub) -> int {
        int count = 0;
        string::const_iterator it = seq.begin();
        while (it != seq.end()) {
            it = find(it, seq.end(), sub[0]); 
            if (it != seq.end()) {
                if (distance(it, seq.end()) >= sub.length()) {
                    if (string(it, it + sub.length()) == sub) {
                        count++;
                    }
                }
                it++;
            }
            else {
                break;
            }
        }
        return count;
        };
    int actual_count = findStr(sequence, target);
    cout << "Количество повторений: " << actual_count << endl;
    return 0;
}
