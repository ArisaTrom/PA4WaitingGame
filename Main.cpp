#include <fstream>
#include <string>

using namespace std;
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

    while (getline(reader,line)){
        if (line[0] == 'E'){
            break;
        }
    }

    while (reader){
        getline(reader, line);
        R_windowNum = stoi(line);
        getline(reader, line);
        C_windowNum = stoi(line);
        getline(reader, line);
        F_windowNum = stoi(line);
        getline(reader, line);
        arriveTime = stoi(line);
        getline(reader, line);
        studentNum = stoi(line);
        for (int i = 0; i < studentNum; ++i){
            getline(reader, line);
        }
        getline(reader, line);
        arriveTime = stoi(line);
        getline(reader, line);
        studentNum = stoi(line);


    }

    return 0;
}