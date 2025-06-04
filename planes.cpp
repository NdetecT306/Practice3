#include "planes.h"
struct Coffee {
    string name;
    double originalPrice;
    double discountedPrice;
    Coffee(const string& n, double original, double discounted) : name(n), originalPrice(original), discountedPrice(discounted) {}
    double getDiscountPercentage() const {
        return (1 - discountedPrice / originalPrice) * 100;
    }
};
int CoffeeShop() {
    vector<Coffee> coffeeMenu = {
        {"Arabica Blend (250g)", 12.50, 9.00},
        {"Espresso Dark Roast (1kg)", 35.00, 30.00},
        {"Ethiopian Yirgacheffe (200g)", 18.00, 15.00},
        {"Sumatra Mandheling (500g)", 28.00, 21.00},
        {"Colombian Supremo (1kg)", 40.00, 38.00},
        {"Decaf Blend (250g)", 14.00, 10.00}
    };
    auto isDiscountedMoreThan15 = [](const Coffee& coffee) {
        return coffee.getDiscountPercentage() > 15.0;
    };
    vector<Coffee> discountedCoffee;
    copy_if(coffeeMenu.begin(), coffeeMenu.end(), std::back_inserter(discountedCoffee), isDiscountedMoreThan15);
    if (discountedCoffee.empty()) {
        cout << "На данный момент кофе со скидкой более 15% отсутствует в меню." << endl;
    } 
    else {
        cout << "Специальное предложение на кофе! Скидка более 15%:" << endl;
        cout << setw(30) << left << "Название сорта"<< setw(15) << "Цена (ориг.)" << setw(15) << "Цена (со скидкой)"<< setw(10) << "Скидка %" << endl;
        cout << string(70, '-') << endl;
        for (const auto& coffee : discountedCoffee) {
            cout << setw(30) << left << coffee.name << fixed << setprecision(2)
                      << setw(15) << coffee.originalPrice << setw(15) << coffee.discountedPrice
                      << setw(9)  << fixed << setprecision(1) << coffee.getDiscountPercentage() << "%" << endl;
        }
        if (!discountedCoffee.empty()) {
            double totalDiscount = std::accumulate(discountedCoffee.begin(), discountedCoffee.end(), 0.0,
                                                   [](double sum, const Coffee& coffee) {
                                                       return sum + coffee.getDiscountPercentage();
                                                   });
            double averageDiscount = totalDiscount / discountedCoffee.size();
            cout << endl << "Средняя скидка на кофе: " << fixed << setprecision(1) << averageDiscount << "%" << endl;
            auto isDiscountGreaterThan20 = [](const Coffee& coffee) {
                return coffee.getDiscountPercentage() > 10.0;
            };
            bool allAbove10 = all_of(discountedCoffee.begin(), discountedCoffee.end(), isDiscountGreaterThan20);
            if (allAbove10) {
                cout << "Все сорта кофе по акции имеют скидку более 10%!" << endl;
            } 
            else {
                cout << "Не все сорта кофе по акции имеют скидку более 10%." << endl;
            }
        }
    }
    return 0;
}
