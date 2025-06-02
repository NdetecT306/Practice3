#include "random.h"
int RandomNumbers(int start, int end){
    int num;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    ranlux24_base generation(seed);
    uniform_int_distribution<int> distribution(start, end);
    num = distribution(generation);
    return num;
}
