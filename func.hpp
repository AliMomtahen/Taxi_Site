#ifndef _FUNC_HPP
#define _FUNC_HPP

#include<string>
#include<vector>
#include"Person.hpp"
#include"Trip.hpp"


const char SPLITER_IN_FILE = ',';
const char END_STRING = '\0';



void split(std::string str, char spliter ,std::vector< std::string >& list_name);
bool not_valid(Trip* trip , Person *person );
bool not_valid(Person *person , Location *first_loc , Location *second_loc);
bool is_empty_input(std::string input_1 , std::string input_2  ,
     std::string input_3, bool input_bool);

std::string flout_chang_to_string(double number);







#endif