#include <iostream>
#include <string>

using namespace std;

class LibraryReader {
private:
    string name;
    string profession;
    string idNumber;

public:
    LibraryReader(string n, string p, string id) {
        name = n;
        profession = p;
        idNumber = id;
    }

    void outputTo() {
        cout << "Имя: " << name << endl;
        cout << "Профессия: " << profession << endl;
        cout << "Идентификационный номер: " << idNumber << endl;
    }

    string get_Name() {
        return name;
    }

    string get_Profession() {
        return profession;
    }

    string get_IdNumber() {
        return idNumber;
    }


    void set_Name(string n) {
        name = n;
    }

    void set_Profession(string p) {
        profession = p;
    }

    void set_IdNumber(string id) {
        idNumber = id;
    }

};

int main() {
    LibraryReader reader1("Иванов Иван Иванович", "Инженер", "123456");

    LibraryReader* reader2 = new LibraryReader("Петрова Анна Сергеевна", "Врач", "789012");

    cout << "Читатель 1 до изменений:" << endl;
    reader1.outputTo();
    
    cout << "Читатель 2 до изменений:" << endl;
    reader2->outputTo();

    reader1.set_Profession("Программист");
    
    reader2->set_Profession("Учитель");

    cout << "Читатель 1 после изменений:" << endl;
    reader1.outputTo();
    
    cout << "Читатель 2 после изменений:" << endl;
    reader2->outputTo();

    delete reader2;

    return 0;
}
