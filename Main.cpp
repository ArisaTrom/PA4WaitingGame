#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Customer.h"

using namespace std;

char getOfficeChar(string value, int time, int Ctime, int Rtime, int Ftime);
Customer* collectStudentInfo(string line, int time1, int time2, int time3, int Ctime, int Rtime, int Ftime, int arriveTime);

int main(int argc, char **argv){
    ifstream reader;
    string line;
    string inFile = argv[1];
    reader.open(inFile);

    int R_windowNum;
    int C_windowNum;
    int F_windowNum;
    int arriveTime;
    int studentNum;
    int lineCount = 1;
    int time1;
    int time2;
    int time3;
    int Rtime;
    int Ctime;
    int Ftime;
    int tmpLineCount;

    // WIP
    while (getline(reader,line)){
        if (line[0] == 'E'){
            break;
        }
        switch(lineCount){
            case 1:
                R_windowNum = stoi(line);
                break;
            case 2:
                C_windowNum = stoi(line);
                break;
            case 3:
                F_windowNum = stoi(line);
                break;
            case 4:
                arriveTime = stoi(line);
                break;
            case 5:
                studentNum = stoi(line);
                break;
            case 6: 
                cout << R_windowNum << " is R window \n" << C_windowNum << " is C window \n" << F_windowNum << " is F window \n";
                cout << arriveTime << " is arrive time \n" << studentNum << " is studetn num " << endl;
                for (int i = 0; i < studentNum; ++i){
                    Customer* customer = collectStudentInfo(line, time1, time2, time3, Ctime, Rtime, Ftime, arriveTime);
                    // add customer to listqueue 


                    if (i != studentNum - 1){
                        getline(reader, line);   // gets line for next student
                        ++lineCount;
                        // cout << lineCount << " is current Line Count" << endl;
                    }
                }
                lineCount;
                break;
            default:
                if (lineCount == 6 + studentNum){    // line after student wait values
                    cout << lineCount << " is lineCount here" << endl;
                    arriveTime = stoi(line);
                    cout << arriveTime << " is new Arrive time" << endl;
                } else if (lineCount == 7 + studentNum){
                    tmpLineCount = 7 + studentNum; // saves line because studentNum gets reassigned
                    studentNum = stoi(line);
                    cout << studentNum << " is new student num" << endl;
                } else if (lineCount == tmpLineCount + 1){
                    for (int i = 0; i < studentNum; ++i){
                        Customer* customer = collectStudentInfo(line, time1, time2, time3, Ctime, Rtime, Ftime, arriveTime);

                        // do something with the collected values for that one student

                        if (i != studentNum - 1){
                            getline(reader, line);   // gets line for next student
                            ++lineCount;
                        }
                    }
                }
                break;
        }
        ++lineCount;
        // cout << lineCount << " is current Line Count" << endl;
    }
    return 0;
}

char getOfficeChar(string value, int time, int Ctime, int Rtime, int Ftime){
    if (value[0] == 'C'){
        return 'C';
    } else if (value[0] == 'R'){
        return 'R';
    } else if (value[0] == 'F'){
        return 'F';
    }
}

Customer* collectStudentInfo(string line, int time1, int time2, int time3, int Ctime, int Rtime, int Ftime, int arriveTime){
    Customer* customer = new Customer(arriveTime);
    stringstream ss(line);
    string value;
    int valueCount = 1;
    while (ss >> value){
        switch(valueCount){
            case 1:
                time1 = stoi(value);
                break;
            case 2:
                time2 = stoi(value);
                break;
            case 3:
                time3 = stoi(value);
                break;
            case 4:
                customer->setOffice1(getOfficeChar(value, time1, Ctime, Rtime, Ftime), time1);
                break;
            case 5:
                setWaitTime(value, time2, Ctime, Rtime, Ftime);
                customer->setOffice2(getOfficeChar(value, time1, Ctime, Rtime, Ftime), time2);
                break;
            case 6:
                setWaitTime(value, time3, Ctime, Rtime, Ftime);
                customer->setOffice3(getOfficeChar(value, time1, Ctime, Rtime, Ftime), time3);
                break;
            default:
                break;
        }
        ++valueCount;
    }
    return customer;
}