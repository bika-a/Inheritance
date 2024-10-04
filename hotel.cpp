#include <iostream>
#include <string>

using namespace std;

// Base class HOTEL
class HOTEL {
protected:
    string hotel_name;
    string hotel_type;
    string city;
    double hotel_rate;

public:
    HOTEL(string name, string type, string ct, double rate) : hotel_name(name), hotel_type(type), city(ct), hotel_rate(rate) {}

    void displayHotelInfo() {
        cout << "Hotel Name: " << hotel_name << endl;
        cout << "Hotel Type: " << hotel_type << endl;
        cout << "City: " << city << endl;
        cout << "Hotel Rate: $" << hotel_rate << endl;
    }
};

// Base class FLIGHT
class FLIGHT {
protected:
    string flight_no;
    string source_city;
    string destination_city;
    int seat_no;

public:
    FLIGHT(string no, string source, string dest, int seat) : flight_no(no), source_city(source), destination_city(dest), seat_no(seat) {}

    void displayFlightInfo() {
        cout << "Flight Number: " << flight_no << endl;
        cout << "Source City: " << source_city << endl;
        cout << "Destination City: " << destination_city << endl;
        cout << "Seat Number: " << seat_no << endl;
    }
};

// Subclass PASSENGER derived from HOTEL and FLIGHT
class PASSENGER : public HOTEL, public FLIGHT {
private:
    string name;
    int age;

public:
    PASSENGER(string hotel_name, string hotel_type, string city, double rate, string flight_no, string source_city, string destination_city, int seat, string nm, int ag) : HOTEL(hotel_name, hotel_type, city, rate), FLIGHT(flight_no, source_city, destination_city, seat), name(nm), age(ag) {}

    void displayPassengerInfo() {
        cout << "Passenger Name: " << name << endl;
        cout << "Passenger Age: " << age << endl;
        cout << "City: " << city << endl;
    }
};

int main() {
    PASSENGER passenger("Grand Hotel", "Five Star", "New York", 5000, "ABC123", "New York", "Los Angeles", 23, "John Doe", 30);

    passenger.displayHotelInfo();
    passenger.displayFlightInfo();
    passenger.displayPassengerInfo();

    return 0;
}