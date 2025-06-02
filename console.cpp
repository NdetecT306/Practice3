#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct GameConsole {
    string name;         
    int releaseYear;    
    double price;       
    string manufacturer; 
};
int Console() {
    vector<GameConsole> consoles = {
        {"PlayStation 1", 1994, 299.0, "Sony"},
        {"Nintendo 64", 1996, 199.0, "Nintendo"},
        {"PlayStation 2", 2000, 299.0, "Sony"},
        {"Xbox", 2001, 299.0, "Microsoft"},
        {"GameCube", 2001, 199.0, "Nintendo"},
        {"PlayStation 3", 2006, 499.0, "Sony"},
        {"Xbox 360", 2005, 299.0, "Microsoft"},
        {"Nintendo Wii", 2006, 249.0, "Nintendo"},
        {"PlayStation 4", 2013, 399.0, "Sony"},
        {"Xbox One", 2013, 499.0, "Microsoft"},
        {"Nintendo Switch", 2017, 299.0, "Nintendo"},
        {"PlayStation 5", 2020, 499.0, "Sony"},
        {"Xbox Series X", 2020, 499.0, "Microsoft"}
    };
    int searchYear = 2010;
    vector<GameConsole> consolesAfterYear;
    copy_if(consoles.begin(), consoles.end(), back_inserter(consolesAfterYear),
             [searchYear](const GameConsole& console) { return console.releaseYear > searchYear; });
    cout << "\nКонсоли, выпущенные после " << searchYear << " года:\n";
    for (const auto& console : consolesAfterYear) {
        cout << "  " << console.name << " (" << console.releaseYear << ") - $" << console.price << endl;
    }
    vector<GameConsole> sortedConsoles = consoles;
    sort(sortedConsoles.begin(), sortedConsoles.end(),
         [](const GameConsole& a, const GameConsole& b) { return a.price < b.price; });
    cout << "\nКонсоли, отсортированные по цене (от дешевых к дорогим):\n";
    for (const auto& console : sortedConsoles) {
        cout << "  " << console.name << " - $" << console.price << endl;
    }
    string manufacturerToCount = "Sony";
    int sonyConsolesCount = count_if(consoles.begin(), consoles.end(),
                                   [manufacturerToCount](const GameConsole& console) {
                                       return console.manufacturer == manufacturerToCount;
                                   });
    cout << "\nКоличество консолей " << manufacturerToCount << ": " << sonyConsolesCount << endl;
    vector<GameConsole> updatedPriceConsoles;
    transform(consoles.begin(), consoles.end(), back_inserter(updatedPriceConsoles),
              [](const GameConsole& console) {
                  GameConsole updatedConsole = console;
                  if (console.releaseYear > 2010) {
                      updatedConsole.price *= 1.1;
                  }
                  return updatedConsole;
              });
    cout << "\nКонсоли с обновленной ценой (цена увеличена на 10% для выпущенных после 2010):\n";
    for (const auto& console : updatedPriceConsoles) {
        cout << "  " << console.name << " (" << console.releaseYear << ") - $" << console.price << endl;
    }
    return 0;
}
