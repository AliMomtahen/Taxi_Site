#include"func.hpp"



void split(std::string str, char spliter ,std::vector< std::string >& list_name){
       
    int counter =0; 
    int begin  = 0 ;
    while(1){
               
        if(str[counter] ==  spliter || str[counter] == END_STRING){


            list_name.push_back(str.substr(begin , counter - begin));
            
            begin = counter + 1;
        }
        if(str[counter] == END_STRING)
            break;

        counter++;
    }
}


bool not_valid(Trip* trip , Person *person ){
    if(trip == NULL || trip->id == -1 || person == NULL )
        return 1;
    return 0;    
} 

bool not_valid(Person *person , Location *first_loc , Location *second_loc){
    if(!person || !first_loc || !second_loc)
        return 1;
    return 0;    
}

bool is_empty_input(std::string input_1 = "1" , std::string input_2 = "1" ,
     std::string input_3 = "1" , bool input_bool = true){

        if(input_1.size() == 0 || input_2.size() == 0 || input_3.size() == 0 || !input_bool)
            return 1;
        return 0;   
}




std::string flout_chang_to_string(double number){
    int new_num = 100 * number;
    std::string str_number;
    str_number += std::to_string((int) number) + "." + std::to_string(new_num % 100);
    return str_number;
}
