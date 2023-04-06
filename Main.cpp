/*
Arisa Trombley, Carina Chan
2375446, 2367721
trombley@chapman.edu, carchan@chapman.edu
CPSC 350-02, CPSC 350-03
Programming Assignment 4 - Waiting Game
*/

/* DESCRIPTION
Main method to simulate a service center session.
*/


#include <string>
#include <iostream>
#include "ServiceCenter.h"

using namespace std;

int main(int argc, char **argv){
    string inFile = argv[1];

    ServiceCenter* sc = new ServiceCenter(inFile); //ServiceCenter object.
    sc->serviceCenterSimulation(); //Executing a simulation of service center.
    
    delete sc;

    return 0;
}