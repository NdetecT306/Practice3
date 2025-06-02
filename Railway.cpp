#include "railway.h"
struct Railway
{
    double length;
    int trainCount;
    double weight;
    double factor;
};
double AllTrains(int n)
{
    vector<Railway> sec(n);
    for (int i = 0; i < n; ++i) {
        cout << "Данные поезда " << i + 1 << ":" << endl;
        try {
            cout << "  Длина участка (км): ";
            cin >> sec[i].length;
            if (sec[i].length <= 0) {
                throw runtime_error("Длина участка должна быть больше нуля.");
            }
            cout << "  Количество составов: ";
            cin >> sec[i].trainCount;
            if (sec[i].trainCount <= 0) {
                throw runtime_error("Количество составов должно быть больше нуля.");
            }
            cout << "  Средний вес состава (тонн): ";
            cin >> sec[i].weight;
            if (sec[i].weight <= 0) {
                throw runtime_error("Средний вес состава должен быть больше нуля.");
            }
            cout << "  Коэффициент износа: ";
            cin >> sec[i].factor;
            if (sec[i].factor <= 0) {
                throw runtime_error("Коэффициент износа должен быть больше нуля.");
            }
        }
        catch (const runtime_error& error)
        {
            cerr << "Ошибка: " << error.what() << endl;
            return 1;
        }
    }
    auto calculate_section_load = [](const Railway& section) {
        return section.length * section.trainCount * section.weight * section.factor;
        };
    vector<double> section_loads(n);
    transform(sec.begin(), sec.end(), section_loads.begin(), calculate_section_load);
    double total_load = inner_product(section_loads.begin(), section_loads.end(), vector<double>(n, 1.0).begin(), 0.0);
    return total_load;
}
