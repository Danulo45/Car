#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    float engineSize;
    float price;
};

void addCar(vector<Car>& cars) {
    Car car;
    cout << "Введіть дані про автомобіль:\n";
    cout << "Назва: ";
    cin >> car.name;
    cout << "Рік випуску: ";
    cin >> car.year;
    cout << "Об'єм двигуна: ";
    cin >> car.engineSize;
    cout << "Ціна: ";
    cin >> car.price;
    cars.push_back(car);
    cout << "Автомобіль успішно додано.\n";
}

void removeCar(vector<Car>& cars) {
    if (cars.empty()) {
        cout << "Немає автомобілів для видалення.\n";
        return;
    }

    string name;
    cout << "Введіть назву автомобіля для видалення: ";
    cin >> name;

    auto it = remove_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.name == name;
        });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "Автомобіль успішно видалено.\n";
    }
    else {
        cout << "Автомобіль не знайдено.\n";
    }
}

void displayCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "Немає автомобілів для відображення.\n";
        return;
    }

    cout << "Автомобілі:\n";
    for (const auto& car : cars) {
        cout << "Назва: " << car.name << ", Рік випуску: " << car.year
            << ", Об'єм двигуна: " << car.engineSize << ", Ціна: " << car.price << "\n";
    }
}

bool sortByYear(const Car& car1, const Car& car2) {
    return car1.year < car2.year;
}

bool sortByPrice(const Car& car1, const Car& car2) {
    return car1.price < car2.price;
}

void sortCars(vector<Car>& cars) {
    cout << "Сортувати автомобілі за:\n";
    cout << "1. Рік випуску\n";
    cout << "2. Ціною\n";
    cout << "Введіть ваш вибір: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        sort(cars.begin(), cars.end(), sortByYear);
        cout << "Автомобілі відсортовані за роком випуску.\n";
    }
    else if (choice == 2) {
        sort(cars.begin(), cars.end(), sortByPrice);
        cout << "Автомобілі відсортовані за ціною.\n";
    }
    else {
        cout << "Неправильний вибір.\n";
    }
}

void searchCars(const vector<Car>& cars) {
    cout << "Пошук автомобілів за:\n";
    cout << "1. Назвою\n";
    cout << "2. Роком випуску\n";
    cout << "3. Об'ємом двигуна\n";
    cout << "Введіть ваш вибір: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        string name;
        cout << "Введіть назву автомобіля: ";
        cin >> name;

        auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.name == name;
            });

        if (it != cars.end()) {
            cout << "Автомобіль знайдено:\n";
            cout << "Назва: " << it->name << ", Рік випуску: " << it->year
                << ", Об'єм двигуна: " << it->engineSize << ", Ціна: " << it->price << "\n";
        }
        else {
            cout << "Автомобіль не знайдено.\n";
        }
    }
    else if (choice == 2) {
        int year;
        cout << "Введіть рік випуску автомобіля: ";
        cin >> year;

        auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.year == year;
            });

        if (it != cars.end()) {
            cout << "Автомобіль знайдено:\n";
            cout << "Назва: " << it->name << ", Рік випуску: " << it->year
                << ", Об'єм двигуна: " << it->engineSize << ", Ціна: " << it->price << "\n";
        }
        else {
            cout << "Автомобіль не знайдено.\n";
        }
    }
    else if (choice == 3) {
        float engineSize;
        cout << "Введіть об'єм двигуна автомобіля: ";
        cin >> engineSize;

        auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.engineSize == engineSize;
            });

        if (it != cars.end()) {
            cout << "Автомобіль знайдено:\n";
            cout << "Назва: " << it->name << ", Рік випуску: " << it->year
                << ", Об'єм двигуна: " << it->engineSize << ", Ціна: " << it->price << "\n";
        }
        else {
            cout << "Автомобіль не знайдено.\n";
        }
    }
    else {
        cout << "Неправильний вибір.\n";
    }
}

int main() {
    vector<Car> cars;
    int choice;

    do {
        cout << "\nСистема управління автосалоном\n";
        cout << "1. Додати автомобіль\n";
        cout << "2. Видалити автомобіль\n";
        cout << "3. Відобразити автомобілі\n";
        cout << "4. Сортувати автомобілі\n";
        cout << "5. Пошук автомобілів\n";
        cout << "6. Вийти\n";
        cout << "Введіть ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCar(cars);
            break;
        case 2:
            removeCar(cars);
            break;
        case 3:
            displayCars(cars);
            break;
        case 4:
            sortCars(cars);
            break;
        case 5:
            searchCars(cars);
            break;
        case 6:
            cout << "Завершення програми.\n";
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 6);

    return 0;
}
