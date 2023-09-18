#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

double calcEquivalentResistance(string circuit) {
    // Split the circuit string into individual resistors
    vector<string> connections;
    stringstream ss(circuit);
    string connection;
    while (getline(ss, connection, 'e')) {
        connections.push_back(connection);
    }

    // Calculate the equivalent resistance of the circuit
    double equivalentResistance = 0;
    for (int i = 0; i < connections.size(); i++) {
        vector<string> resistors;
        stringstream ss(connections[i]);
        string resistor;
        while (getline(ss, resistor, ' ')) {
            resistors.push_back(resistor);
        }

        double connectionResistance = 0;
        for (int j = 1; j < resistors.size(); j++) {
            double resistorValue = stod(resistors[j]);
            if (resistors[0] == "S") {
                connectionResistance += resistorValue;
            } else if (resistors[0] == "P") {
                connectionResistance += 1.0 / resistorValue;
            }
        }
        connectionResistance = 1.0 / connectionResistance;

        equivalentResistance += connectionResistance;
    }
    return equivalentResistance;
}

double calcTotalCurrent(double voltage, double equivalentResistance) {
    // Calculate the total current in the circuit using Ohm's law
    double totalCurrent = voltage / equivalentResistance;
    return totalCurrent;
}

int main() {
    string circuit;
    cout << "Enter the circuit description (connections separated by 'e'): ";
    getline(cin, circuit);

    double voltage;
    cout << "Enter the voltage applied to the circuit: ";
    cin >> voltage;

    double equivalentResistance = calcEquivalentResistance(circuit);
    double totalCurrent = calcTotalCurrent(voltage, equivalentResistance);

    cout << "Equivalent resistance: " << equivalentResistance << endl;
    cout << "Total current: " << totalCurrent << endl;

    return 0;
}
