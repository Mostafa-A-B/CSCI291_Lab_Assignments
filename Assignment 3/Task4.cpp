#include <iostream>
#include <iomanip>
using namespace std;


template <typename S>
S calibrateValue(const S &x, char factor) {
    return x * factor;//uses ASCII value of factor
}

void adjustReading(double *value, double offset = 1.25) {
    *value += offset;
}

void clampReading(double &r) {
    if (r < 0)
        r = 0;
    else if (r > 100)
        r = 100;
}

double computeDifference(int a, double b) {
    return a - b;
}

int main() {
    cout << fixed << setprecision(4);//sets the percision of any printed number to 4 decimal places

    int sensorInt;
    double sensorDouble;

    cout << "Enter integer sensor reading: ";
    cin >> sensorInt;//reads user input

    cout << "Enter double sensor reading: ";
    cin >> sensorDouble;

    int calibratedInt = calibrateValue(sensorInt, '2');
    double calibratedDouble = calibrateValue(sensorDouble, '2');

    cout << "\nCalibrated values:\n";
    cout << setw(10) << calibratedInt << endl;
    cout << setw(10) << calibratedDouble << endl;

    double intAsDouble = static_cast<double>(calibratedInt);

    adjustReading(&intAsDouble);//calling function using default offset value
    adjustReading(&calibratedDouble, 3.4);//valling function with custom offset value

    cout << "\nAdjusted values:\n";
    cout << setw(10) << intAsDouble << endl;//setw() assigns spaces to the printed variable, in this case 10 spaces
    cout << setw(10) << calibratedDouble << endl;

    clampReading(intAsDouble);
    clampReading(calibratedDouble);

    cout << "\nClamped values:\n";
    cout << setw(10) << intAsDouble << endl;
    cout << setw(10) << calibratedDouble << endl;

    int finalIntReading = static_cast<int>(intAsDouble);

    cout << "\nInteger sensor reading after conversion back:\n";
    cout << setw(10) << finalIntReading << endl;

    double diff = computeDifference(finalIntReading, calibratedDouble);

    cout << "\nDifference (integer − double):\n";
    cout << setw(10) << diff << endl;

    return 0;
}