#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

class Airport {
private:
    string flightNumber;
    double ticketPrice;
    int totalSeats;
    int soldTickets;

public:
    Airport() : flightNumber(""), ticketPrice(0.0), totalSeats(0), soldTickets(0) {}
    
    Airport(string number, double price, int total, int sold)
        : flightNumber(number), ticketPrice(price), totalSeats(total), soldTickets(sold) {}

    double calculateRevenue() const {
        return ticketPrice * soldTickets;
    }

    void print() const {
        cout << "Рейс: " << flightNumber
             << ", Цена билета: " << ticketPrice
             << ", Всего мест: " << totalSeats
             << ", Продано билетов: " << soldTickets
             << ", Выручка: " << calculateRevenue() << endl;
    }
};

int main() {
    int N;
    cout << "Введите количество объектов N: ";
    cin >> N;

    ifstream file("aport.txt");
    
    queue<Airport> allAirports; 
    double totalRevenue = 0.0;

    cout << "\nВсе рейсы:" << endl;
    string flightNumber;
    double ticketPrice;
    int totalSeats;
    int soldTickets;

    for (int i = 0; i < N && file >> flightNumber >> ticketPrice >> totalSeats >> soldTickets; i++) {
        Airport airport(flightNumber, ticketPrice, totalSeats, soldTickets);
        allAirports.push(airport);
        totalRevenue += airport.calculateRevenue();
        
        airport.print();
    }
    file.close();

    double averageRevenue = totalRevenue / N;
    cout << "\nСредняя выручка: " << averageRevenue << endl;

    queue<Airport> highRevenueQueue;  
    queue<Airport> lowRevenueQueue;  

    while (!allAirports.empty()) {
        Airport airport = allAirports.front();
        allAirports.pop();
        
        if (airport.calculateRevenue() > averageRevenue) {
            highRevenueQueue.push(airport);
        } else {
            lowRevenueQueue.push(airport);
        }
    }

    cout << "\nОчередь с выручкой ВЫШЕ среднего (" << highRevenueQueue.size() << " объектов):" << endl;
    queue<Airport> temp = highRevenueQueue;
    while (!temp.empty()) {
        temp.front().print();
        temp.pop();
    }

    cout << "\nОчередь с выручкой НИЖЕ или РАВНОЙ среднему (" << lowRevenueQueue.size() << " объектов):" << endl;
    temp = lowRevenueQueue;
    while (!temp.empty()) {
        temp.front().print();
        temp.pop();
    }

    return 0;
}