#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char findDirection (string line) {
    char direction = line[0];
    return direction;
}

string getTurns (string line) {

    string turns = line.substr(1); // substr(1). If len is not specified, it goes to the end.

    return turns;
}

int findTurns (string line) {

    int value = stoi(line);

    return value;
}

int main() {
    string fileName;
    string fileLine;
    string sTurns;
    int dial = 50; //start dial at 50
    int password = 0; // start password at zero
    int dialHLimit = 100; //upper limit of dial
    int dialLLimit = 0; //lower limit of dial
    char letter;
    int iTurns;

    cout << "Please enter a file name: ";
    cin >> fileName; //filename must have type included in input (text file "example.txt" must include the ".txt")
    ifstream fileRead(fileName);

    while (getline (fileRead, fileLine)) {
        //cout << fileLine << "\n"; // testing file being read
        letter = findDirection(fileLine);
        sTurns = getTurns(fileLine);
        iTurns = findTurns(sTurns);
        //cout << letter << " " << iTurns << " Current dial: " << dial << "\n"; // testing functions

        switch (letter) {
            case 'R':
                for (int i = 0; i < iTurns; i++) {
                dial = (dial + 1) % dialHLimit; //wrap back to zero on hitting 99
                //cout << dial << " ";// testing dial spinning
                }
                break;
            case 'L':
                for (int j = 0; j < iTurns; j++) {
                    if (dial <= 0){
                        dial = 99;
                    } else {
                        dial = (dial - 1);
                    }
                //cout << dial << " ";// testing dial spinning
                }

        //if (letter = 'R') {
            //for (int i = 0; i <= iTurns; ++i) {
                //dial = (dial + 1) % dialHLimit; //wrap back to zero on hitting 99
                //cout << dial << " ";// testing dial spinning
            //}
        //}   else if (letter = 'L') {
            //for (int j = 0; j <= iTurns; ++j) {
                //if (dial > dialLLimit){
                    //dial = 99;
                //} else {
                    //dial = (dial - 1);
                //}
                //cout << dial << " ";// testing dial spinning
            //}

        }

        //if (dial = 0) { //check after dial spin if zero
            //password++;
        //}

        switch (dial) {
            case 0:
            password++;
            break;

        }

        //cout << "Current dial: " << dial << "\n"; //testing
    }

    cout << "Password is: " << password;

    fileRead.close();

    return 0;
}
