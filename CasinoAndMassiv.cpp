#include "Intes.h"
using namespace std;
struct Car {
    string make;
    string model;
    int mileage;
    string color;
    Car(string make, string model, int mileage, string color) :
        make(make), model(model), mileage(mileage), color(color) {}
    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Make: " << car.make << ", Model: " << car.model << ", Mileage: " << car.mileage << ", Color: " << car.color;
        return os;
    }
};
int Cars() {
    vector<Car> cars = {
        {"Toyota", "Camry", 50000, "Silver"},
        {"Honda", "Civic", 8000, "Red"},
        {"Ford", "Mustang", 15000, "White"},
        {"BMW", "X5", 20000, "Black"},
        {"Mercedes", "C-Class", 5000, "White"},
        {"Audi", "A4", 30000, "Gray"},
        {"Toyota", "Corolla", 9000, "Blue"},
        {"Ford", "F-150", 60000, "White"},
        {"Nissan", "Altima", 12000, "Silver"},
        {"Honda", "CR-V", 7000, "White"}
    };
    cars.erase(remove_if(cars.begin(), cars.end(), [](const Car& car) {
        return car.mileage < 10000;
    }), cars.end());
    cout << "Машины с пробегом >= 10000 km:" << endl;
    for (const auto& car : cars) {
        cout << car << endl;
    }
    cout << endl;
    rotate(cars.begin(), cars.begin() + cars.size() - 1, cars.end());
    cout << "Машины после ротации:" << endl;
    for (const auto& car : cars) {
        cout << car << endl;
    }
    cout << endl;
    int whiteCarCount = count_if(cars.begin(), cars.end(), [](const Car& car) {
        return car.color == "White";
    });
    cout << "Число белых машин: " << whiteCarCount << endl;
    set<string> whiteCarMakes;
    for_each(cars.begin(), cars.end(), [&whiteCarMakes](const Car& car) {
        if (car.color == "White") {
            whiteCarMakes.insert(car.make);
        }
    });
    cout << "Уникальные белые машины:" << endl;
    for (const auto& make : whiteCarMakes) {
        cout << make << endl;
    }
    return 0;
}
struct Season {
    int number;          
    string title;   
    double rating;       
    int episodeCount;    
    double avgEpisodeLength; 
};
int Ninjago() {
    vector<Season> ninjagoSeasons = {
        {1, "Пилоты", 7.8, 6, 22.5},
        {2, "Наследие Зеленого ниндзя", 8.2, 13, 22.5},
        {3, "Возрождение змей", 8.5, 10, 22.5},
        {4, "Турнир стихий", 8.3, 10, 22.5},
        {5, "Отряд титанов", 7.9, 10, 22.5},
        {6, "Небесные границы", 8.0, 10, 22.5},
        {7, "Руки времени", 8.1, 10, 22.5},
        {8, "Сыны Гармадона", 7.5, 30, 22.5},
        {9, "Они", 8.7, 10, 22.5},
        {10, "Марш Они", 7.7, 10, 22.5},
        {11, "Секреты запрещенного Кружитцу", 8.4, 30, 22.5},
        {12, "Последний фильм", 8.6, 16, 22.5},
        {13, "Огненные Горы", 8.9, 16, 22.5},
        {14, "Путешествия в сердце моря", 9.1, 16, 22.5},
        {15, "Кристализованный", 9.3, 30, 22.5}
    };
    cout << "Сезоны Ниндзяго с рейтингом больше 8:" << std::endl;
    double totalWatchTimeFiltered = 0.0; 
    double totalWatchTimeAll = 0.0; 
    for (const auto& season : ninjagoSeasons) {
        totalWatchTimeAll += season.episodeCount * season.avgEpisodeLength;
    }
    for_each(ninjagoSeasons.begin(), ninjagoSeasons.end(), [&](const Season& season) {
        if (season.rating > 8.0) {
            std::cout << "Сезон " << season.number << ": " << season.title << " - Рейтинг: " << season.rating
                      << " - Серий: " << season.episodeCount << " - Время серии: " << season.avgEpisodeLength << " мин" << std::endl;
            totalWatchTimeFiltered += season.episodeCount * season.avgEpisodeLength; 
        }
    });
    cout << endl << "Сезоны, в которых больше 10 серий (запаситесь попкорном): " << endl; 
    for_each(ninjagoSeasons.begin(), ninjagoSeasons.end(), [&](const Season& season) {
        if (season.episodeCount >10) {
            cout << "Сезон " << season.number << ": " << season.title << " - Рейтинг: " << season.rating
                      << " - Серий: " << season.episodeCount << " - Время серии: " << season.avgEpisodeLength << " мин" << std::endl;
        }
    });
    cout << endl << "Общее время просмотра всего сериала: " << totalWatchTimeAll << " минут" << endl; 
    return 0;
}
