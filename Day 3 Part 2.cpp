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
    string sBatteryCellValue;
    string sMaxBatteryJoltage;
    string sMinBatteryJoltage;
    string sBankJoltage;
    string sMaxJoltage;
    int bankLen = 0;
    int stringLen = 0;
    int bankCellPlace = 0;
    int cellsToBeRemoved = 0;
    long long int iBatteryCellValue = 0;
    long long int iMinBatteryJoltage = 9;// max cell value is 9 find lower than that
    long long int iMaxBatteryJoltage = 0;
    long long int iMaxJoltage = 0;
    long long int joltageTotal = 0;
    vector<char> batteryVec;
    vector<long long int> bankTotals;

    cout << "Please enter a file name: ";
    cin >> fileName; //filename must have type included in input (text file "example.txt" must include the ".txt")
    ifstream fileRead(fileName);
    while (getline (fileRead, fileLine)) {
        batteryVec.clear(); //clear at start of line

        batteryBank = fileLine;
        //sMaxBatteryJoltage = "";//reset value to empty
        //cout << batteryBank << "\n"; //testing file being read
        cellsToBeRemoved = batteryBank.length() - 12;

        for (char cha : batteryBank) {
            while (!batteryVec.empty() && cellsToBeRemoved > 0 && batteryVec.back() < cha) {
                batteryVec.pop_back();
                cellsToBeRemoved--;
            }
            batteryVec.push_back(cha);
        }

        while (batteryVec.size() > 12) {
            batteryVec.pop_back();
        }

        //stringLen = batteryBank.length();
        //while (stringLen > 12) {
            //bankLen = batteryBank.length();
            //for (int j = 0; j < bankLen; j++) {
                //sBatteryCellValue = batteryBank[j];
                //iBatteryCellValue = stoi(sBatteryCellValue);

                //if (iBatteryCellValue < iMinBatteryJoltage) {
                    //iMinBatteryJoltage = iBatteryCellValue;
                    //bankCellPlace = j;
                //}

            //}


            //sMinBatteryJoltage = sMinBatteryJoltage + to_string(iMaxBatteryJoltage);
            //batteryBank.erase(bankCellPlace, 1); //remove used cell from battery
            //iMinBatteryJoltage = 9; //reset to zero
            //stringLen = batteryBank.length(); // reduce stringLen
        //}


        //for (int i = 0; i < 12; i++) { //cycle through battery 12 times

            //bankLen = batteryBank.length();
            //for (int j = 0; j < bankLen; j++) {
                //sBatteryCellValue = batteryBank[j];
                //iBatteryCellValue = stoi(sBatteryCellValue);

                //if (iBatteryCellValue > iMaxBatteryJoltage) {
                    //iMaxBatteryJoltage = iBatteryCellValue;
                    //bankCellPlace = j;
                //}

            //}

            //sMaxBatteryJoltage = sMaxBatteryJoltage + to_string(iMaxBatteryJoltage);
            //batteryBank.erase(bankCellPlace, 1); //remove used cell from battery
            //iMaxBatteryJoltage = 0; //reset to zero
        //}
        //sMaxJoltage = sMaxBatteryJoltage;
        //iMaxJoltage = stoll(batteryBank);
        sMaxJoltage = string(batteryVec.begin(), batteryVec.end());
        iMaxJoltage = stoll(sMaxJoltage);

        cout << iMaxJoltage << "\n";
        bankTotals.push_back(iMaxJoltage);
        //iMinBatteryJoltage = 9; //reset to max value
    }

    for (long long int number : bankTotals) {
        joltageTotal += number;
    }

    cout << "Joltage total: " << joltageTotal;

    fileRead.close();

    return 0;
}
