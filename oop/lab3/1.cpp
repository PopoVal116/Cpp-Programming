#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Tea {
public:
    char type[20];
    char packaging[20];
    char manufacturer[20];
    double price;
    int quantity;
    double sum;
};

int main() {
    // Создание бинарного файла
    cout << "Программа 1: Создание бинарного файла" << endl;
    
    ifstream txtFile("tea.txt");
    ofstream binFile("tea_binary.dat", ios::binary);
    
    int count;
    txtFile >> count;
    
    Tea tea;
    for (int i = 0; i < count; i++) {
        txtFile >> tea.type >> tea.packaging >> tea.manufacturer >> tea.price >> tea.quantity;
        tea.sum = tea.price * tea.quantity;
        binFile.write((char*)&tea, sizeof(Tea));
    }
    
    txtFile.close();
    binFile.close();
    cout << "Бинарный файл создан!" << endl;
    
    // Обработка бинарного файла
    cout << "\nПрограмма 2: Обработка бинарного файла" << endl;
    
    ifstream binFileRead("tea_binary.dat", ios::binary);
    Tea teas[100];
    int teaCount = 0;
    
    while (binFileRead.read((char*)&teas[teaCount], sizeof(Tea))) {
        teaCount++;
    }
    binFileRead.close();
    
    // Сортировка
    for (int i = 0; i < teaCount - 1; i++) {
        for (int j = 0; j < teaCount - i - 1; j++) {
            if (teas[j].sum < teas[j + 1].sum) {
                Tea temp = teas[j];
                teas[j] = teas[j + 1];
                teas[j + 1] = temp;
            }
        }
    }
    
    double totalSum = 0;
    for (int i = 0; i < teaCount; i++) {
        cout << "Тип чая: " << teas[i].type<< endl;
        cout << "Упаковка: " << teas[i].packaging<< endl;
        cout << "Производитель: " << teas[i].manufacturer<< endl;
        cout << "Цена: " << teas[i].price<< endl;
        cout << "Количество: " << teas[i].quantity<< endl;
        cout << "Сумма: " << teas[i].sum<< endl<< endl;
        totalSum += teas[i].sum;
    }
    cout << "Всего: " << totalSum << " руб" << endl;
    
    return 0;
}