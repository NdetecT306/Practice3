#include "Intes.h"
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
int Massiv() {
    auto is_prime = [](int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
        };
    array<int, 10> arr1;
    array<int, 10> arr2;
    cout << "Введите 10 чисел для первого массива:\n";
    for (int i = 0; i < 10;) { 
        try {
            cout << "Введите число " << i+1 << ": ";
            cin >> arr1[i];
            if (cin.fail()) { 
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                throw runtime_error("Не число. Введите еще раз.");
            }
            ++i; 
        }
        catch (const std::runtime_error& e) {
            cerr << e.what() << std::endl;
        }
    }
    cout << "Введите 10 чисел для второго массива:\n";
    for (int i = 0; i < 10; ) { 
        try {
            cout << "Введите число " << i + 1 << ": ";
            cin >> arr2[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw runtime_error("Не число. Введите еще раз.");
            }
            ++i; 
        }
        catch (const std::runtime_error& e) {
            cerr << e.what() << endl;
        }
    }
    array<int, 20> combined_arr;
    copy(arr1.begin(), arr1.end(), combined_arr.begin());
    copy(arr2.begin(), arr2.end(), combined_arr.begin() + 10);
    sort(combined_arr.begin(), combined_arr.end(), greater<int>());
    cout << "\nОбщий массив в порядке убывания:\n";
    for (int num : combined_arr) cout << num << " ";
    cout << endl;
    double sum = accumulate(combined_arr.begin(), combined_arr.end(), 0.0);
    double average = sum / combined_arr.size();
    array<int, 20> less_than_average;
    int less_count = 0;
    for (int num : combined_arr) {
        if (num < average) {
            less_than_average[less_count++] = num;
        }
    }
    cout << "\nМассив чисел, меньших среднего арифметического (" << average << "):\n";
    for (int i = 0; i < less_count; ++i) cout << less_than_average[i] << " ";
    cout << endl;
    int prime_count = 0;
    for (int num : combined_arr) {
        if (is_prime(num)) prime_count++;
    }
    cout << "\nКоличество простых чисел: " << prime_count << endl;
    return 0;
}
