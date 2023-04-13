#include <iostream>
#include <memory>

using namespace std;
class City {
public:
    string name;
    int population;

    City(const string &name, int population) : name(name), population(population) {}

    void showInfo() const {
        cout << "City: " << name << ", Population: " << population << endl;
    }
};

int main() {
    shared_ptr<City> city = make_shared<City>("New York", 8600000);
    city->showInfo();

    return 0;
}
