#include"Exception.hpp"





My_Exception::My_Exception(std::string _message){
    message = _message;
}



void My_Exception::print_message(){ 
    std::cout << message  << std::endl;
}


