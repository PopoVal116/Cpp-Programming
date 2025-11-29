#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person {
    string surname, name, zodiac;
    int day, month, year;
public:
    Person(string s = "", string n = "", string z = "",
           int d = 1, int m = 1, int y = 2000)
        : surname(s), name(n), zodiac(z), day(d), month(m), year(y) {}

    string getSurname() const { return surname; }
    string getName()    const { return name; }
    string getZodiac()  const { return zodiac; }
    int    getDay()     const { return day; }
    int    getMonth()   const { return month; }
    int    getYear()    const { return year; }

    void setSurname(string s) { surname = s; }
    void setName(string n)    { name = n; }
    void setZodiac(string z)  { zodiac = z; }
    void setDay(int d)        { day = d; }
    void setMonth(int m)      { month = m; }
    void setYear(int y)       { year = y; }

    void print() const {
        cout << "ФИ: " << surname << " " << name
             << ", Знак: " << zodiac
             << ", День рождения: " << day << "." << month << "." << year << endl;
    }
};

int main() {
    queue<Person> q;
    int n;
    cout << "Сколько человек? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s, name, z;
        int d, m, y;
        cout << "Фамилия Имя: ";
        cin >> s >> name;
        cout << "Знак Зодиака: ";
        cin >> z;
        cout << "День Месяц Год: ";
        cin >> d >> m >> y;
        q.push(Person(s, name, z, d, m, y));
    }

    int search;
    cout << "Искать день рождения: ";
    cin >> search;

    queue<Person> res;
    queue<Person> tmp = q;
    while (!tmp.empty()) {
        if (tmp.front().getDay() == search)
            res.push(tmp.front());
        tmp.pop();
    }

    if (res.empty())
        cout << "Таких людей нет.\n";
    else {
        cout << "Найдены:\n";
        while (!res.empty()) {
            res.front().print();
            res.pop();
        }
    }

    return 0;
}