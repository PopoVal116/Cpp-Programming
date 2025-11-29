#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s1, s2;
    int n;
    cout << "Сколько символов ввести? ";
    cin >> n;
    
    cout << "Вводите символы по одному:\n";
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s1.push(c);
        if ((i + 1) % 3 == 0) {
            s2.push(c);
        }
    }

    stack<char> rev1, rev2;
    while (!s1.empty()) {
        rev1.push(s1.top());
        s1.pop();
    }
    while (!s2.empty()) {
        rev2.push(s2.top());
        s2.pop();
    }

    cout << "\nСтек 1 (снизу вверх):\n";
    while (!rev1.empty()) {
        cout << rev1.top() << " ";
        rev1.pop();
    }

    cout << "\n\nСтек 2 (каждый 3-й элемент, снизу вверх):\n";
    while (!rev2.empty()) {
        cout << rev2.top() << " ";
        rev2.pop();
    }
    cout << endl;

    return 0;
}