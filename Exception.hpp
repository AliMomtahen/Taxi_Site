#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP

#include<iostream>
#include<string>



const std::string SIGNUP_ERROR = "/static/bad_request";
const std::string PERMISSION_ERROR = "/static/permission";
const std::string REQUEST_ERROR = "/static/bad_request";
const std::string FIND_ERROR = "/static/not_found";
const std::string EMPTY = "EMPTY";




class My_Exception : public std::exception{
public:
    My_Exception(){}
    My_Exception(std::string _message);
    std::string message;
    void print_message();
    std::string show_message(){ return message;};
};












#endif