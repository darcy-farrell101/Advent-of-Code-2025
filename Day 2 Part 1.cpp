#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> findRanges(const string &s, char delimiter) {
    vector<string> values;
    string value;
    stringstream ss(s);
    while (getline(ss, value, delimiter)) {
        values.push_back(value);
    }
    return values;
}

int main() {
    string fileName;
    string fileLine;
    string sRange;
    string sRangeStart;
    string sRangeEnd;
    string sID;
    string sIDFirstHalf;
    string sIDSecondHalf;
    long long int startPoint; // int or long int or long long int?
    long long int endPoint;
    long long int invalidIDTotal = 0;// long long causing issues? init to zero?
    char delimiter1 = ',';
    char delimiter2 = '-';
    vector<string> vRanges;
    vector<string> vRangeMaxAndMin;
    vector<long long int> invalidIDs;


    cout << "Please enter a file name: ";
    cin >> fileName;//filename must have type included in input (text file "example.txt" must include the ".txt")
    ifstream fileRead(fileName);

    while (getline (fileRead, fileLine)) {
        //cout << fileLine << "\n"; // testing file being read
        vRanges = findRanges(fileLine, delimiter1);

        for (int i = 0; i < vRanges.size(); i++) {
            //cout << vRanges[i] << "\n"; //test values being split
            sRange = vRanges[i];
            //cout << vRanges[i] << "\n"; // test sRange being overwritten
            vRangeMaxAndMin = findRanges(sRange, delimiter2);
            //for (int j = 0; j < vRangeMaxAndMin.size(); j++) { // test values being split
                //cout << vRangeMaxAndMin[j] << " "; // test values being split
            //}
            sRangeStart = vRangeMaxAndMin[0];
            sRangeEnd = vRangeMaxAndMin[1];
            //cout << sRangeStart << " " << sRangeEnd << "\n";// test ranges being transferred
            startPoint = stoll(sRangeStart);
            endPoint = stoll(sRangeEnd); //stoi or stoll
            //cout << startPoint << " " << endPoint << "\n"; //test
            for (long long int j = startPoint; j <= endPoint; ++j) {
                sID = to_string(j);
                sIDFirstHalf = sID.substr(0, sID.length() / 2);
                sIDSecondHalf = sID.substr(sID.length() / 2);
                //cout << sIDFirstHalf << " " << sIDSecondHalf << "\n";// test ID split
                if (sIDFirstHalf == sIDSecondHalf) {
                    invalidIDs.push_back(j);
                }

            }

        }

    }

    for (long long int number : invalidIDs) {
        invalidIDTotal += number;
    }

    cout << "Total of invalidIDs: " << invalidIDTotal;

    fileRead.close();

    return 0;
}
