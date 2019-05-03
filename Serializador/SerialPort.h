//
// Created by sebas211288 on 02/05/19.
//

#ifndef GENETIC_SERIALPORT_H
#define GENETIC_SERIALPORT_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

class SerialPort {
    public:
        SerialPort();
        void sendMessage(std::string message);

};


#endif //GENETIC_SERIALPORT_H
