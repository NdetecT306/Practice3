#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct Technics {
    string name;
    double price;
    string manufacturer;
    string type; 
};

int Console() {
    vector<Technics> Mvideo = {
        {"Atlant ХМ-4613-101", 299.0, "ATLANT", "Refrigerator"},
        {"Nintendo 64", 199.0, "Nintendo", "Console"},
        {"PlayStation 2", 299.0, "Sony", "Console"},
        {"Xbox", 299.0, "Microsoft", "Console"},
        {"ATLANT ХМ 4623-159-ND", 199.0, "ATLANT", "Refrigerator"},
        {"PlayStation 3", 499.0, "Sony", "Console"},
        {"Xbox 360", 299.0, "Microsoft", "Console"},
        {"Nintendo Wii", 249.0, "Nintendo", "Console"},
        {"PlayStation 4", 399.0, "Sony", "Console"},
        {"Xbox One", 499.0, "Microsoft", "Console"},
        {"Beko B3DRCNK402HW", 299.0, "Beko", "Refrigerator"},
        {"PlayStation 5", 499.0, "Sony", "Console"},
        {"Xbox Series X", 499.0, "Microsoft", "Console"},
        {"Samsung QN90A",1499.0, "Samsung", "TV"},
        {"LG OLED C1", 1799.0, "LG", "TV"},
        {"iPhone 13", 999.0, "Apple", "Phone"},
        {"Samsung Galaxy S22", 899.0, "Samsung", "Phone"},
        {"Dyson V15 Detect", 699.0, "Dyson", "Vacuum"},
        {"iRobot Roomba i7+", 549.0, "iRobot", "Vacuum"}
    };
    vector<Technics> Eldorado = {
        {"ХМ-4613-101", 299.0, "ATLANT", "Refrigerator"},
        {"Nintendo 64", 199.0, "Nordfrost", "Console"},
        {"PlayStation 2", 299.0, "Sony", "Console"},
        {"Xbox", 299.0, "Microsoft", "Console"},
        {"GameCube", 199.0, "Nintendo", "Console"},
        {"PlayStation 3", 499.0, "Sony", "Console"},
        {"Xbox 360", 299.0, "ATLANT", "Console"},
        {"Nintendo Wii", 249.0, "Nordfrost", "Console"},
        {"PlayStation 4", 399.0, "Sony", "Console"},
        {"Xbox One", 499.0, "Microsoft", "Console"},
        {"Nintendo Switch", 299.0, "ATLANT", "Console"},
        {"PlayStation 5", 499.0, "Sony", "Console"},
        {"Xbox Series X", 499.0, "Microsoft", "Console"},
        {"Samsung AU8000", 799.0, "Samsung", "TV"},
        {"Xiaomi Mi TV P1", 499.0, "Xiaomi", "TV"},
        {"Xiaomi Redmi Note 11",249.0, "Xiaomi", "Phone"},
        {"Realme GT Master Edition", 349.0, "Realme", "Phone"},
        {"Shark IQ Robot Self-Empty", 499.0, "Shark", "Vacuum"},
        {"Bissell CleanView Swivel Rewind Pet Reach", 199.0, "Bissell", "Vacuum"}
    };
    vector<Technics> allRefrigerators;
    copy_if(Mvideo.begin(), Mvideo.end(), back_inserter(allRefrigerators),
             [](const Technics& item) { return item.type == "Refrigerator"; });
    copy_if(Eldorado.begin(), Eldorado.end(), back_inserter(allRefrigerators),
             [](const Technics& item) { return item.type == "Refrigerator"; });
    Technics mostExpensiveItem = Mvideo[0]; 
    vector<Technics> allTechnics;
    allTechnics.insert(allTechnics.end(), Mvideo.begin(), Mvideo.end()); //
    allTechnics.insert(allTechnics.end(), Eldorado.begin(), Eldorado.end()); 
    auto minMaxResult = minmax_element(allTechnics.begin(), allTechnics.end(),
                                       [](const Technics& a, const Technics& b) {
                                           return a.price < b.price;
                                       });
    if (allTechnics.empty()) {
        cout << "No items to compare.\n";
    } else {
        cout << "Самый дешевый товар:\n";
        cout << "  " << minMaxResult.first->name << " - $" << minMaxResult.first->price << endl;
        cout << "\nСамый дорогой товар:\n";
        cout << "  " << minMaxResult.second->name << " - $" << minMaxResult.second->price << endl;
    }
    cout << "\nВсе холодильники:\n";
    for (const auto& refrigerator : allRefrigerators) {
        cout << "  " << refrigerator.name << " - $" << refrigerator.price << endl;
    }
    return 0;
}
