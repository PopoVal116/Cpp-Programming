#include <iostream>
#include <string>

using namespace std;

class Drob{
private:
    int chislitel;
    int znamenatel;
public:
    Drob(int a, int b){
        if (b == 0) {
            cout << "Ошибка: знаменатель не может быть равен 0! Начни заново." << endl;
        } else {
            znamenatel = b;
        }
        chislitel = a;
    }
    
    int get_Chislitel() {
        return chislitel;
    }

    int get_Znamenatel() {
        return znamenatel;
    }

    void set_Chislitel(int c) {
        chislitel = c;
    }

    void set_Znamenatel(int z) {
        if (z == 0) {
            cout << "Ошибка: знаменатель не может быть равен 0!" << endl;
        } else {
            znamenatel = z;
        }
    }

    void outputTo() {
        cout << chislitel << "/" << znamenatel;
    }
    
    void umnozhenie(Drob drugaia) {
        int noviy_chislitel = chislitel * drugaia.chislitel;
        int noviy_znamenatel = znamenatel * drugaia.znamenatel;
        cout << "Умножение: " << chislitel << "/" << znamenatel << " * " 
             << drugaia.chislitel << "/" << drugaia.znamenatel << " = " 
             << noviy_chislitel << "/" << noviy_znamenatel << endl;
    }
    
    void delenie(Drob drugaia) {
        int noviy_chislitel = chislitel * drugaia.znamenatel;
        int noviy_znamenatel = znamenatel * drugaia.chislitel;
        cout << "Деление: " << chislitel << "/" << znamenatel << " / " 
             << drugaia.chislitel << "/" << drugaia.znamenatel << " = " 
             << noviy_chislitel << "/" << noviy_znamenatel << endl;
    }
};

int main() {
    Drob drob1(2, 3);
    Drob drob2(3, 4);

    cout << "Дробь 1: " << drob1.get_Chislitel() << "/" << drob1.get_Znamenatel() << endl;
    cout << "Дробь 2: " << drob2.get_Chislitel() << "/" << drob2.get_Znamenatel() << endl;
    
    drob1.umnozhenie(drob2);
    drob1.delenie(drob2);

    
    return 0;
}