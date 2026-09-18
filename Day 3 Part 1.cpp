#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string fileName;
    string fileLine;
    string batteryBank;
    string batteryBank2;
    string sBankJoltage;
    string sBatteryCellValue;// char instad of string?
    string sMaxBatteryJoltage1;
    string sMaxBatteryJoltage2;
    string sMaxJoltage;
    int bankLen = 0;
    int bankCellPlace = 0;//used to save place of 1st largest cell
    int iMaxBatteryJoltage1 = 0;
    int iMaxBatteryJoltage2 = 0;
    int iMaxJoltage = 0;
    int iBatteryCellValue = 0;
    int iBankJoltage = 0;
    int joltageTotal = 0;
    vector<int> bankTotals;

    cout << "Please enter a file name: ";
    cin >> fileName; //filename must have type included in input (text file "example.txt" must include the ".txt")
    ifstream fileRead(fileName);
    while (getline (fileRead, fileLine)) {
        batteryBank = fileLine;
        //cout << batteryBank << "\n"; //testing file being read
        bankLen = batteryBank.length();

        for (int i = 0; i < bankLen - 1; i++) {
            sBatteryCellValue = batteryBank[i];// char instad of string?
            iBatteryCellValue = stoi(sBatteryCellValue);

            if (iBatteryCellValue > iMaxBatteryJoltage1) {
                iMaxBatteryJoltage1 = iBatteryCellValue;
                bankCellPlace = i;
            }

        }

        batteryBank2 = batteryBank.substr(bankCellPlace + 1);// find remainded of cell
        //cout << batteryBank2 << "\n";
        bankLen = batteryBank2.length();

        for (int j = 0; j < bankLen; j++) {
            sBatteryCellValue = batteryBank2[j];
            iBatteryCellValue = stoi(sBatteryCellValue);

            if (iBatteryCellValue > iMaxBatteryJoltage2) {
                iMaxBatteryJoltage2 = iBatteryCellValue;
            }

        }

        sMaxBatteryJoltage1 = to_string(iMaxBatteryJoltage1);
        sMaxBatteryJoltage2 = to_string(iMaxBatteryJoltage2);

        sMaxJoltage = sMaxBatteryJoltage1 + sMaxBatteryJoltage2;
        iMaxJoltage = stoi(sMaxJoltage);
        //cout << iMaxJoltage << "\n";//testing
        bankTotals.push_back(iMaxJoltage);

        iMaxBatteryJoltage1 = 0; // attempt to reset maxBatteryJoltage between lines
        iMaxBatteryJoltage2 = 0;
    }

    for (int number : bankTotals) {
        joltageTotal += number;
    }

    cout << "Joltage total: " << joltageTotal;

    fileRead.close();

    return 0;
}
