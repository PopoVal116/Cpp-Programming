#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LibraryReader {
private:
    string name;
    string profession;
    string idNumber;

public:
    LibraryReader() {
        name = "";
        profession = "";
        idNumber = "";
    }

    LibraryReader(string n, string p, string id) {
        name = n;
        profession = p;
        idNumber = id;
    }

    void print() {
        cout << "Имя: " << name << endl;
        cout << "Профессия: " << profession << endl;
        cout << "Идентификационный номер: " << idNumber << endl;
    }

    string getName() { return name; }
    string getProfession() { return profession; }
    string getId() { return idNumber; }

    void setName(string n) { name = n; }
    void setProfession(string p) { profession = p; }
    void setId(string id) { idNumber = id; }

    void input() {
        cout << "Введите имя: ";
        getline(cin, name);
        cout << "Введите профессию: ";
        getline(cin, profession);
        cout << "Введите ID: ";
        getline(cin, idNumber);
    }
};

void bubbleSort(vector<LibraryReader>& vec, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vec[j].getName() > vec[j + 1].getName()) {
                LibraryReader temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Введите размер вектора: ";
    cin >> size;
    cin.ignore();

    vector<LibraryReader> readers(size);

    cout << "Введите " << size << " читателей:\n";
    for (int i = 0; i < size; i++) {
        readers[i].input();
    }

    vector<LibraryReader> newReaders;

    for (int i = 0; i < size; i++) {
        string currentName = readers[i].getName();
        string firstChar = currentName.substr(0, 1);
        cout << "Проверка имени '" << currentName << "', первый символ: '" << firstChar << "'\n";
        if (currentName.length() > 0 && (firstChar == "I" || firstChar == "i")) {
            cout << "Добавлен: " << currentName << endl;
            newReaders.push_back(readers[i]);
        }
    }

    if (newReaders.size() == 0) {
        cout << "Новый вектор пуст.\n";
        return 0;
    }

    bubbleSort(newReaders, newReaders.size());

    LibraryReader newOne;
    cout << "Введите нового читателя:\n";
    newOne.input();

    newReaders.push_back(newOne); 
    bubbleSort(newReaders, newReaders.size());

    cout << "\nИсходный вектор:\n";
    for (int i = 0; i < size; i++) {
        cout << "Читатель " << i + 1 << ":" << endl;
        readers[i].print();
    }

    cout << "\nНовый вектор:\n";
    for (int i = 0; i < newReaders.size(); i++) {
        cout << "Читатель " << i + 1 << ":" << endl;
        newReaders[i].print();
    }

    return 0;
}