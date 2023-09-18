#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Get the user input
    cout << "Circuit Description: ";
    string circuitDesc;
    getline(cin, circuitDesc);

    // Define the voltage and Equivalent resistance variables
    double voltage{}, req{0};

    // Read the voltage applied
    cout << "Voltage Applied: ";
    cin >> voltage;

    int len{circuitDesc.length()};

    if(circuitDesc[0] == 'P')
    {
        // Iterate through the string using spaces as delimiters and converting the substrings to doubles
        for(int i{1}, j{};i < len;i=j)
        {
            j = circuitDesc.find(" ", i+1);

            if (j != string::npos)
                req +=  1 / stod(circuitDesc.substr(i, j-i));
            else
                break;
        }
        // Invert the value to get R equivalent
        req = 1 / req;
    }
    else if (circuitDesc[0] == 'S')
    {
        for(int i{1}, j{};i < len;i=j)
        {
            j = circuitDesc.find(" ", i+1);

            if (j != string::npos)
                req += stod(circuitDesc.substr(i, j-i));
            else
                break;
        }
    }
    else
    {
        cout << "Wrong Circuit Description" << endl;
        return 0;
    }

    // Print out the Results.
    cout << "Equivalent Resistance: " << req << endl;
    cout << "Current: " << voltage / req << endl;
}
