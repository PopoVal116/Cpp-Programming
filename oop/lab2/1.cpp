#include <iostream>
#include <cmath>

using namespace std;

class Chetygolnik {
protected:
    int x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Chetygolnik() {
        x1 = y1 = x2 = y2 = x3 = y3 = x4 = y4 = 0;
    }

    Chetygolnik(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        this->x1 = x1; this->y1 = y1;
        this->x2 = x2; this->y2 = y2;
        this->x3 = x3; this->y3 = y3;
        this->x4 = x4; this->y4 = y4;
    }

    double DlinaStorony(int xa, int ya, int xb, int yb) {
        int dx = xb - xa;
        int dy = yb - ya;
        return sqrt(dx * dx + dy * dy);
    }

    double storonaAB() { return DlinaStorony(x1, y1, x2, y2); }
    double storonaBC() { return DlinaStorony(x2, y2, x3, y3); }
    double storonaCD() { return DlinaStorony(x3, y3, x4, y4); }
    double storonaDA() { return DlinaStorony(x4, y4, x1, y1); }

    double diagonalAC() { return DlinaStorony(x1, y1, x3, y3); }
    double diagonalBD() { return DlinaStorony(x2, y2, x4, y4); }

    double P() {
        return storonaAB() + storonaBC() + storonaCD() + storonaDA();
    }

    virtual double S() {
        return 0.5 * abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
    }

    virtual bool isPryamougolnik() {
        int ab_x = x2 - x1, ab_y = y2 - y1; // AB
        int ad_x = x4 - x1, ad_y = y4 - y1; // AD
        int ba_x = x1 - x2, ba_y = y1 - y2; // BA
        int bc_x = x3 - x2, bc_y = y3 - y2; // BC
        int cb_x = x2 - x3, cb_y = y2 - y3; // CB
        int cd_x = x4 - x3, cd_y = y4 - y3; // CD
        int dc_x = x3 - x4, dc_y = y3 - y4; // DC
        int da_x = x1 - x4, da_y = y1 - y4; // DA

        bool ugolA = (ab_x * ad_x + ab_y * ad_y) == 0;
        bool ugolB = (ba_x * bc_x + ba_y * bc_y) == 0;
        bool ugolC = (cb_x * cd_x + cb_y * cd_y) == 0;
        bool ugolD = (dc_x * da_x + dc_y * da_y) == 0;

        return (ugolA && ugolB && ugolC && ugolD) && (S() > 0);
    }

    virtual void outputTo() {
        cout << "Четырехугольник с координатами: ";
        cout << "A(" << x1 << "," << y1 << "), ";
        cout << "B(" << x2 << "," << y2 << "), ";
        cout << "C(" << x3 << "," << y3 << "), ";
        cout << "D(" << x4 << "," << y4 << ")" << endl;
        cout << "Стороны: AB=" << storonaAB() << ", BC=" << storonaBC() << ", CD=" << storonaCD() << ", DA=" << storonaDA() << endl;
        cout << "Диагонали: AC=" << diagonalAC() << ", BD=" << diagonalBD() << endl;
        cout << "Периметр: " << P() << ", Площадь: " << S() << endl;
        cout << "Является прямоугольником: " << (isPryamougolnik() ? "Да" : "Нет") << endl;
    }
};

class Pryamoygolnik : public Chetygolnik {
public:
    Pryamoygolnik(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
        : Chetygolnik(x1, y1, x2, y2, x3, y3, x4, y4) {}

    bool isPryamougolnik() override {
        return Chetygolnik::isPryamougolnik();
    }

    double S() override {
        if (isPryamougolnik()) {
            return storonaAB() * storonaBC(); 
        }
        return Chetygolnik::S();
    }

    void outputTo() override {
        cout << "Прямоугольник с координатами: ";
        cout << "A(" << x1 << "," << y1 << "), ";
        cout << "B(" << x2 << "," << y2 << "), ";
        cout << "C(" << x3 << "," << y3 << "), ";
        cout << "D(" << x4 << "," << y4 << ")" << endl;
        cout << "Стороны: AB=" << storonaAB() << ", BC=" << storonaBC() << ", CD=" << storonaCD() << ", DA=" << storonaDA() << endl;
        cout << "Диагонали: AC=" << diagonalAC() << ", BD=" << diagonalBD() << endl;
        cout << "Периметр: " << P() << ", Площадь: " << S() << endl;
        cout << "Является прямоугольником: " << (isPryamougolnik() ? "Да" : "Нет") << endl;
    }
};

int main() {
    int K;
    cout << "Введите количество четырехугольников: ";
    cin >> K;

    Chetygolnik* figury[10];
    double sumPloshad = 0.0;
    int countPryamougolnikov = 0;
    int countMensheSredney = 0;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cout << "Четырехугольник " << i + 1 << ":" << endl;
        cout << "Введите координаты A(x1 y1): "; cin >> x1 >> y1;
        cout << "Введите координаты B(x2 y2): "; cin >> x2 >> y2;
        cout << "Введите координаты C(x3 y3): "; cin >> x3 >> y3;
        cout << "Введите координаты D(x4 y4): "; cin >> x4 >> y4;

        figury[i] = new Chetygolnik(x1, y1, x2, y2, x3, y3, x4, y4);

        if (figury[i]->isPryamougolnik()) {
            countPryamougolnikov++;
            sumPloshad += figury[i]->S();
        }
    }

    cout << "\n=== ВСЕ ФИГУРЫ ===" << endl;
    for (int i = 0; i < K; i++) {
        cout << i + 1 << ". ";
        figury[i]->outputTo();
    }

    if (countPryamougolnikov > 0) {
        double srednyayaPloshad = sumPloshad / countPryamougolnikov;

        for (int i = 0; i < K; i++) {
            if (figury[i]->isPryamougolnik() && figury[i]->S() < srednyayaPloshad) {
                countMensheSredney++;
            }
        }

        cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
        cout << "Всего четырехугольников: " << K << endl;
        cout << "Из них прямоугольников: " << countPryamougolnikov << endl;
        cout << "Средняя площадь прямоугольников: " << srednyayaPloshad << endl;
        cout << "Прямоугольников с площадью меньше средней: " << countMensheSredney << endl;
    } else {
        cout << "\nСреди фигур нет прямоугольников!" << endl;
    }

    for (int i = 0; i < K; i++) {
        delete figury[i];
    }

    return 0;
}