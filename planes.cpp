#include "planes.h"
struct Airplane {
    string airline;
    string destinationCity;
    string departureTime;
    friend ostream& operator<<(ostream& os, const Airplane& airplane) {
        os << "Авиакомпания: " << airplane.airline << ", Город назначения: " << airplane.destinationCity << ", Время вылета: " << airplane.departureTime;
        return os;
    }
};
Airplane inputAirplaneData() {
    Airplane plane;
    cout << "Введите название авиакомпании: ";
    getline(cin >> ws, plane.airline);
    cout << "Введите город назначения: ";
    getline(cin >> ws, plane.destinationCity);
    cout << "Введите время вылета: ";
    getline(cin >> ws, plane.departureTime);
    return plane;
}
string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}
vector<Airplane> filterAirplanes(const vector<Airplane>& airplanes, const string& criterion, const string& parameter) {
    vector<Airplane> filteredAirplanes;
    function<bool(const Airplane&)> matchCriterion;
    string criterionLower = toLower(criterion);
    string parameterLower = toLower(parameter);
    if (criterionLower == "авиакомпания") {
        matchCriterion = [&](const Airplane& plane) { return toLower(plane.airline) == parameterLower; };
    }
    else if (criterionLower == "город") {
        matchCriterion = [&](const Airplane& plane) { return toLower(plane.destinationCity) == parameterLower; };
    }
    else if (criterionLower == "время") {
        matchCriterion = [&](const Airplane& plane) { return plane.departureTime == parameterLower; };
    }
    else {
        cout << "Неверный критерий." << endl;
        return {};
    }
    copy_if(airplanes.begin(), airplanes.end(), std::back_inserter(filteredAirplanes), matchCriterion);
    return filteredAirplanes;
}
int plain() {
    setlocale(LC_ALL, "Russian");
    vector<Airplane> airplanes;
    int numAirplanes;
    cout << "Введите количество самолетов: ";
    cin >> numAirplanes;
    cin.ignore(); //  Удаляем символ новой строки после ввода числа самолетов
    for (int i = 0; i < numAirplanes; ++i) {
        cout << "Введите данные для самолета " << i + 1 << ":" << endl;
        airplanes.push_back(inputAirplaneData());
    }
    string sortCriterion, sortParameter;
    cout << "Введите критерий сортировки (авиакомпания, город, время): ";
    getline(cin >> ws, sortCriterion);
    cout << "Введите параметр: ";
    getline(cin >> ws, sortParameter);

    vector<Airplane> filteredAirplanes = filterAirplanes(airplanes, sortCriterion, sortParameter);

    if (filteredAirplanes.empty()) {
        cout << "Самолеты, соответствующие критериям, не найдены." << endl;
    }
    else {
        cout << "Самолеты, соответствующие критериям:" << endl;
        for (const auto& plane : filteredAirplanes) {
            cout << plane << endl;
        }
    }
    return 0;
}
 
