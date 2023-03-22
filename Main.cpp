#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void setWaitTime(string value, int time, int Ctime, int Rtime, int Ftime);
void collectStudentInfo(string line, int time1, int time2, int time3, int Ctime, int Rtime, int Ftime);

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
                    collectStudentInfo(line, time1, time2, time3, Ctime, Rtime, Ftime);

                    // TO DO: might have to create an array that holds each student info at this arrive time with the order they are listed (priority list queue ?)
                    // do something with the collected values for that one student

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
                        collectStudentInfo(line, time1, time2, time3, Ctime, Rtime, Ftime);

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

void setWaitTime(string value, int time, int Ctime, int Rtime, int Ftime){
    if (value[0] == 'C'){
        Ctime = time;
        cout << Ctime << " is Ctime" << endl;
    } else if (value[0] == 'R'){
        Rtime = time;
        cout << Rtime << " is Rtime" << endl;
    } else if (value[0] == 'F'){
        Ftime = time;
        cout << Ftime << " is Ftime" << endl;
    }
}

void collectStudentInfo(string line, int time1, int time2, int time3, int Ctime, int Rtime, int Ftime){
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
                setWaitTime(value, time1, Ctime, Rtime, Ftime);
                break;
            case 5:
                setWaitTime(value, time2, Ctime, Rtime, Ftime);
                break;
            case 6:
                setWaitTime(value, time3, Ctime, Rtime, Ftime);
                break;
            default:
                break;
        }
        ++valueCount;
    }
}