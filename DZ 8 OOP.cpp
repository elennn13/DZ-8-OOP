#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

class Hospital {
private:
    std::vector<std::string> patients; // вектор пациентов
    int capacity; // вместительность больницы

public:
    // Конструктор по умолчанию
    Hospital() : capacity(10) {} // начальная вместительность больницы равна 10

    // Параметрический конструктор с инициализацией именами пациентов
    Hospital(std::initializer_list<std::string> names) : patients(names), capacity(10) {}

    // Конструктор копирования
    Hospital(const Hospital& other) : patients(other.patients), capacity(other.capacity) {}

    // Метод добавления пациента
    void put(const std::string& name) {
        if (patients.size() < capacity) {
            patients.push_back(name);
        }
        else {
            std::cout << "Больница заполнена. Невозможно добавить пациента." << std::endl;
        }
    }

    // Метод выписки пациента по индексу
    void discharge(int index) {
        if (index >= 0 && index < patients.size()) {
            patients.erase(patients.begin() + index);
        }
        else {
            std::cout << "Неверный индекс пациента." << std::endl;
        }
    }

    // Метод поиска пациента и возвращения его позиции
    int find(const std::string& name) {
        auto it = std::find(patients.begin(), patients.end(), name);
        if (it != patients.end()) {
            return std::distance(patients.begin(), it);
        }
        else {
            return -1; // Если пациент не найден
        }
    }

    // Метод формирования отчета со всеми именами пациентов
    std::string report() {
        std::string result;
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            result += *it;
            if (std::next(it) != patients.end()) {
                result += ", ";
            }
        }
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Hospital hospital({ "Иван", "Мария", "Петр" }); // Создание больницы с начальными пациентами

    hospital.put("Елена"); // Добавление нового пациента
    hospital.put("Анна"); // Добавление еще одного пациента

    hospital.discharge(1); // Выписка второго пациента

    int position = hospital.find("Иван"); // Поиск пациента Ивана
    if (position != -1) {
        std::cout << "Пациент Иван находится на позиции: " << position << std::endl;
    }
    else {
        std::cout << "Пациент Иван не найден." << std::endl;
    }

    std::cout << "Список всех пациентов: " << hospital.report() << std::endl;

    return 0;
}