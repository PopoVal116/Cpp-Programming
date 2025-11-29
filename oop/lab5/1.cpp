#include <iostream>
#include <list>
#include <string>

using namespace std;

class Kvartira {
private:
    int kol_komnat;
    int etazh;
    double ploshad;
    string adres;

public:
    Kvartira(int k, int e, double p, string a) {
        kol_komnat = k;
        etazh = e;
        ploshad = p;
        adres = a;
    }

    int getKomnat() { return kol_komnat; }
    int getEtazh() { return etazh; }
    double getPloshad() { return ploshad; }
    string getAdres() { return adres; }

    void setKomnat(int k) { kol_komnat = k; }
    void setEtazh(int e) { etazh = e; }
    void setPloshad(double p) { ploshad = p; }
    void setAdres(string a) { adres = a; }

    void outputTo() {
        cout << "Адрес: " << adres << ", Комнат: " << kol_komnat 
             << ", Этаж: " << etazh << ", Площадь: " << ploshad << " кв.м" << endl;
    }
};


int main() {
    list<Kvartira> kartoteka;
    int choice;

    kartoteka.push_back(Kvartira(2, 3, 45.5, "ул. Ленина, 10"));
    kartoteka.push_back(Kvartira(3, 5, 67.8, "ул. Мира, 25"));
    kartoteka.push_back(Kvartira(2, 3, 52.0, "пр. Победы, 15"));
    kartoteka.push_back(Kvartira(1, 2, 35.2, "ул. Садовая, 8"));
    kartoteka.push_back(Kvartira(1, 2, 32, "ул. Садовая, 18"));

    do {
        cout << "\nКартотека бюро обмена квартир" << endl;
        cout << "1. Вывести всю картотеку" << endl;
        cout << "2. Добавить заявку на обмен" << endl;
        cout << "3. Найти подходящий вариант" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nВся картотека" << endl;
                if (kartoteka.empty()) {
                    cout << "Картотека пуста." << endl;
                } else {
                    list<Kvartira>::iterator it;
                    for (it = kartoteka.begin(); it != kartoteka.end(); ++it) {
                        it->outputTo();
                    }
                }
                break;
            }

            case 2: {
                cout << "\nДобавление заявки" << endl;
                int komnati, etazh;
                double ploshad;
                string adres;

                cout << "Введите количество комнат: ";
                cin >> komnati;
                cout << "Введите этаж: ";
                cin >> etazh;
                cout << "Введите площадь: ";
                cin >> ploshad;
                cout << "Введите адрес: ";
                cin.ignore();
                getline(cin, adres);

                kartoteka.push_back(Kvartira(komnati, etazh, ploshad, adres));
                cout << "Заявка добавлена в картотеку!" << endl;
                break;
            }

            case 3: {
                cout << "\nПоиск варианта" << endl;
                int isk_komnati, isk_etazh;
                cout << "Введите желаемое количество комнат: ";
                cin >> isk_komnati;
                cout << "Введите желаемый этаж: ";
                cin >> isk_etazh;

                list<Kvartira> naydeno;
                list<Kvartira>::iterator it;

                for (it = kartoteka.begin(); it != kartoteka.end(); ++it) {
                    if (it->getKomnat() == isk_komnati && it->getEtazh() == isk_etazh) {
                        naydeno.push_back(*it);
                    }
                }

                if (naydeno.empty()) {
                    cout << "Подходящих вариантов не найдено." << endl;
                } else if (naydeno.size() == 1) {
                    cout << "Найден подходящий вариант (удален из картотеки):" << endl;
                    naydeno.front().outputTo();
                    
                    for (it = kartoteka.begin(); it != kartoteka.end(); ) {
                        if (it->getKomnat() == isk_komnati && it->getEtazh() == isk_etazh) {
                            it = kartoteka.erase(it);
                            break;
                        } else {
                            ++it;
                        }
                    }
                } else {
                    cout << "Найдено несколько подходящих вариантов:" << endl;
                    list<Kvartira>::iterator nit;
                    for (nit = naydeno.begin(); nit != naydeno.end(); ++nit) {
                        nit->outputTo();
                    }
                }
                break;
            }

            case 0:
                cout << "Выход из программы." << endl;
                break;

            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}