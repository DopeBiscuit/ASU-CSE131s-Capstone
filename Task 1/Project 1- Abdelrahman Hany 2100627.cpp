#include <iostream>
#include <string>
using namespace std;

int main() {
    // Get the circuit info as a string using the getline function.
    string circuitSpecs;
    cout << "Circuit Description: ";
    getline(cin, circuitSpecs);

    // Make an array for the values of the resistances.
    double resistances[3];
    for(int i{0};i < 3;i++)
    {
        resistances[i] = stod(circuitSpecs.substr(2 + 2*i, 1));
    }


    // Make an equivalent resistance variable and calculate it depending on the type of connection.
    double totalResistance{};
    if(circuitSpecs[0] == 'S'){
        for(int i{0};i < 3;i++)
        {
            totalResistance += resistances[i];
        }
    }
    else
    {
        for(int i{0};i < 3;i++)
        {
            totalResistance += (1/resistances[i]);
        }
        totalResistance = 1/totalResistance;
    }

    // Read the voltage applied to the circuit.
    double voltage{};
    cout << "Voltage Applied: ";
    cin >> voltage;

    // Print out the calculated equivalent resistance and circuit current.
    cout << "Equivalent Resistance: " << totalResistance << endl;
    cout << "Current in the Circuit: " << voltage / totalResistance << endl;
}
