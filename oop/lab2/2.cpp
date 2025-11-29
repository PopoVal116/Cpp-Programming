#include <iostream>

using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(){
            day = 1;
            month = 10;
            year = 2001;
        }

        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }

        string getDecade(){
            if (day >= 1 && day <= 10) return "первая декада";
            else if (day >= 11 && day <= 20) return "вторая декада";
            else if (day >= 21 && day <= 31) return "третья декада";
            else return "не определена";
        }

        string getSeason(){
            if (month == 12 || month == 1 || month == 2) return "зима";
            else if (month >= 3 && month <= 5) return "весна";
            else if (month >= 6 && month <= 8) return "лето";
            else return "осень";
        }

        string getVek(){
            if (year >= 1801 && year <= 1900) return "век 19";
            else if (year >= 1901 && year <= 2000) return "век 20";
            else if (year >= 2001 && year <= 2100) return "век 21";
            else return "не определен";
        }

        void outputTo(){
            cout << day<<"."<<month<<"."<<year<<": "<<getDecade()<<", "<<getSeason()<<", "<<getVek()<<endl;
        }
};

int main(){
    int N;
    cout<< "Введите количество человек: ";
    cin >> N;

    Date* people = new Date[N];

    for (int i = 0; i < N; i++){
        int d, m, y;
        cout << "Введите день, месяц, год рождения человека "<< i + 1<< ": ";
        cin >> d>> m >> y;
        people[i] = Date(d, m, y);
    }

    cout<< "Информация о человекке: "<< endl;
    for (int i = 0; i < N; i++){
        cout << "Человек "<< i+1<<": ";
        people[i].outputTo();
    }

    delete[] people;
    return 0;
}