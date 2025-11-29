#include <iostream>
#include <list>
#include <string>

using namespace std;

class Flight {
private:
    string flightNumber;
    double ticketPrice;
    int totalSeats;
    int soldTickets;

public:
    Flight(string number = "", double price = 0.0, int total = 0, int sold = 0)
        : flightNumber(number), ticketPrice(price), totalSeats(total), soldTickets(sold) {}

    string getFlightNumber() const { return flightNumber; }
    double getTicketPrice() const { return ticketPrice; }
    int getTotalSeats() const { return totalSeats; }
    int getSoldTickets() const { return soldTickets; }

    void setFlightNumber(const string& number) { flightNumber = number; }
    void setTicketPrice(double price) { ticketPrice = price; }
    void setTotalSeats(int total) { totalSeats = total; }
    void setSoldTickets(int sold) { soldTickets = sold; }

    double getRevenue() const { return ticketPrice * soldTickets; }

    bool operator<(const Flight& other) const {
        return totalSeats > other.totalSeats;
    }

    void print() const {
        cout << "Рейс: " << flightNumber
             << ", Цена: " << ticketPrice
             << ", Мест: " << totalSeats
             << ", Продано: " << soldTickets
             << ", Выручка: " << getRevenue() << endl;
    }
};

int main() {
    list<Flight> flights = {
        Flight("SU123", 1500.0, 180, 120),
        Flight("AA456", 2500.0, 150, 95),
        Flight("DL789", 1800.0, 200, 200),
        Flight("BA101", 2200.0, 160, 50),
        Flight("LH202", 3000.0, 140, 140)
    };

    flights.sort();

    cout << "Рейсы, отсортированные по числу проданных билетов:\n";

    for (const auto& f : flights) {
        f.print();
    }

    return 0;
}