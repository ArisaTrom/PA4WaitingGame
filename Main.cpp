
#include <string>
#include <iostream>
#include "ServiceCenter.h"

using namespace std;


int main(int argc, char **argv){
    string inFile = argv[1];

    std::cout << "hw" << std::endl;

    ServiceCenter* sc = new ServiceCenter(inFile);
    sc->serviceCenterSimulation();

    
    delete sc;

    return 0;
}

