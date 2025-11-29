#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Employee {
public:
    string lastName;
    string initials;
    int birthYear;
    string position;
    char gender;

    Employee(string last = "", string init = "", int year = 0, string pos = "", char gen = ' ')
        : lastName(last), initials(init), birthYear(year), position(pos), gender(gen) {}

    bool operator<(const Employee& other) const {
        return lastName < other.lastName;
    }

    void print() const {
        cout << lastName << " " << initials << " (" << birthYear << "), " << position << endl;
    }
};

int main() {
    int n;
    cout << "Сколько сотрудников? ";
    cin >> n;
    cin.ignore();

    vector<Employee> allEmployees;

    for (int i = 0; i < n; i++) {
        string last, init, pos;
        int year;
        char gen;

        cout << "Фамилия: "; getline(cin, last);
        cout << "Инициалы: "; getline(cin, init);
        cout << "Год: "; cin >> year; cin.ignore();
        cout << "Должность: "; getline(cin, pos);
        cout << "Пол (M/F): "; cin >> gen; cin.ignore();

        allEmployees.push_back(Employee(last, init, year, pos, gen));
    }

    sort(allEmployees.begin(), allEmployees.end());

    stack<Employee> womenStack, menStack;

    for (const auto& emp : allEmployees) {
        if (emp.gender == 'F' && emp.birthYear <= 1970) {
            womenStack.push(emp);
        } else if (emp.gender == 'M' && emp.birthYear <= 1965) {
            menStack.push(emp);
        }
    }

    cout << "\nЖенщины 1970 г.р. и старше:\n";
    while (!womenStack.empty()) {
        womenStack.top().print();
        womenStack.pop();
    }

    cout << "\nМужчины 1965 г.р. и старше:\n";
    while (!menStack.empty()) {
        menStack.top().print();
        menStack.pop();
    }

    return 0;
}