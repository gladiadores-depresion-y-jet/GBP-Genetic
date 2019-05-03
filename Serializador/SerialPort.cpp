//
// Created by sebas211288 on 02/05/19.
//

#include "SerialPort.h"

SerialPort::SerialPort() = default;

void SerialPort::sendMessage(std::string message) {

    //open arduino device file (linux)
    std::ofstream arduino;
    arduino.open("/dev/ttyACM0");
    if(arduino.is_open()){
        std::cout<<"abierto"<<std::endl;
        std::cout<<"mensaje: "<<message<<std::endl;
    }else{
        std::cout<<"no abierto"<<std::endl;
    }

    //write to it

    arduino << message;
    arduino.close();

}
