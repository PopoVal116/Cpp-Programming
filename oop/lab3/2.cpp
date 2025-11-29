#include <iostream>
#include <fstream>
#include <string>

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

    cout << "\n=== КРУГЛОСУТОЧНЫЕ КИНОТЕАТРЫ ===\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (cinemas[i].is_24h()) {
            cinemas[i].print();
            cout << "--------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Круглосуточных кинотеатров не найдено.\n";

    cout << "\n=== КРУГЛОСУТОЧНЫЕ КИНОЗАЛЫ ===\n";
    found = false;
    for (int i = 0; i < k; ++i) {
        if (halls[i].is_24h()) {
            halls[i].print();
            cout << "--------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Круглосуточных кинозалов не найдено.\n";

    delete[] cinemas;
    delete[] halls;
    return 0;
}