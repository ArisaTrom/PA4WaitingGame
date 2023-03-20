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
            case 2:
                C_windowNum = stoi(line);
            case 3:
                F_windowNum = stoi(line);
            case 4:
                arriveTime = stoi(line);
            case 5:
                studentNum = stoi(line);
            case 6: 
                for (int i = 0; i < studentNum; ++i){
                    collectStudentInfo(line, time1, time2, time3, Ctime, Rtime, Ftime);

                    // do something with the collected values for that one student

                    getline(reader, line);  // gets line for next student // might break the while loop we'll see
                    ++lineCount;
                }
                break;
            default:
                if (lineCount = 6 + studentNum + 1){    // line after student wait values
                    arriveTime = stoi(line);
                } else if (lineCount = 7 + studentNum + 1){
                    tmpLineCount = 7 + studentNum + 1; // saves line because studentNum gets reassigned
                    studentNum = stoi(line);
                } else if (lineCount = tmpLineCount + 1){
                    for (int i = 0; i < studentNum; ++i){
                        collectStudentInfo(line, time1, time2, time3, Ctime, Rtime, Ftime);

                        // do something with the collected values for that one student

                        getline(reader, line);  // gets line for next student // might break
                        ++lineCount;
                    }
                }
                break;
        }
        ++lineCount;
    }
    return 0;
}

void setWaitTime(string value, int time, int Ctime, int Rtime, int Ftime){
    if (value[0] == 'C'){
        Ctime = time;
    } else if (value[0] == 'R'){
        Rtime = time;
    } else if (value[0] == 'F'){
        Ftime = time;
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