#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Cinema {
protected:
    string name, number, address, working_hours;
    int number_of_cinemas;

public:
    Cinema() : number_of_cinemas(0) {}
    Cinema(string _name, string _num, string _address, string w_k, int num_of_cinema)
        : name(_name), number(_num), address(_address), working_hours(w_k), number_of_cinemas(num_of_cinema) {}

    virtual void print() const {
        cout << "Название: " << name << "\nТелефон: " << number << "\nАдрес: " << address
             << "\nВремя работы: " << working_hours << "\nКинозалов: " << number_of_cinemas << endl;
    }

    bool is_24h() const { return working_hours == "круглосуточно"; }
};

class Cinemas : public Cinema {
    int capacity;

public:
    Cinemas() : capacity(0) {}
    Cinemas(string _name, string _num, string _address, string w_k, int num_of_cinema, int _cap)
        : Cinema(_name, _num, _address, w_k, num_of_cinema), capacity(_cap) {}

    void print() const override {
        Cinema::print();
        cout << "Вместимость: " << capacity << endl;
    }
};

int main() {
    ifstream kino_file("Kino.txt");
    if (!kino_file) {
        cout << "Ошибка открытия Kino.txt" << endl;
        return 1;
    }

    int n;
    cout << "Введите количество кинотеатров: ";
    cin >> n;
    cin.ignore();

    Cinema* cinemas = new Cinema[n];
    for (int i = 0; i < n; ++i) {
        if (kino_file) {
            string name, number, address, working_hours;
            int number_of_cinemas;
            kino_file >> name >> number >> address >> working_hours >> number_of_cinemas;
            cinemas[i] = Cinema(name, number, address, working_hours, number_of_cinemas);
        } else {
            break; 
        }
    }
    kino_file.close();

    ifstream zal_file("Zal.txt");
    if (!zal_file) {
        cout << "Ошибка открытия Zal.txt" << endl;
        delete[] cinemas;
        return 1;
    }

    int k;
    cout << "Введите количество кинозалов: ";
    cin >> k;
    cin.ignore();

    Cinemas* halls = new Cinemas[k];
    for (int i = 0; i < k; ++i) {
        if (zal_file) {
            string name, number, address, working_hours;
            int number_of_cinemas, capacity;
            zal_file >> name >> number >> address >> working_hours >> number_of_cinemas >> capacity;
            halls[i] = Cinemas(name, number, address, working_hours, number_of_cinemas, capacity);
        } else {
            break; 
        }
    }
    zal_file.close();

    vector<Cinema> round_the_clock_cinemas;
    
    for (int i = 0; i < n; ++i) {
        if (cinemas[i].is_24h()) {
            round_the_clock_cinemas.push_back(cinemas[i]);
        }
    }

    cout << "\n=== КРУГЛОСУТОЧНЫЕ КИНОТЕАТРЫ (из вектора) ===\n";
    if (!round_the_clock_cinemas.empty()) {
        for (const auto& cinema : round_the_clock_cinemas) {
            cinema.print();
            cout << "--------------------\n";
        }
    } else {
        cout << "Круглосуточных кинотеатров не найдено.\n";
    }

    vector<Cinemas> round_the_clock_halls;
    
    for (int i = 0; i < k; ++i) {
        if (halls[i].is_24h()) {
            round_the_clock_halls.push_back(halls[i]);
        }
    }

    cout << "\n=== КРУГЛОСУТОЧНЫЕ КИНОЗАЛЫ (из вектора) ===\n";
    if (!round_the_clock_halls.empty()) {
        for (const auto& hall : round_the_clock_halls) {
            hall.print();
            cout << "--------------------\n";
        }
    } else {
        cout << "Круглосуточных кинозалов не найдено.\n";
    }

    cout << "\n=== СВОДКА ===\n";
    cout << "Всего кинотеатров: " << n << endl;
    cout << "Круглосуточных кинотеатров в векторе: " << round_the_clock_cinemas.size() << endl;
    cout << "Всего кинозалов: " << k << endl;
    cout << "Круглосуточных кинозалов в векторе: " << round_the_clock_halls.size() << endl;

    delete[] cinemas;
    delete[] halls;
    return 0;
}