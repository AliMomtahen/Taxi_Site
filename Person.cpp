#include"Person.hpp"



Person::Person(){
    is_in_trip = false;
}


Person::Person(std::string _name){
    name = _name;
    is_in_trip = false;

}

void Person::accept_trip(Trip *trip_accept){
    throw My_Exception(PERMISSION_ERROR);
}

void Person::notify_finishing_trip(Trip *trip_finished){
    throw My_Exception(PERMISSION_ERROR);
}

double Person::calc_cost(Location *origin , Location *destination , bool in_hurry){
    throw My_Exception(PERMISSION_ERROR);
}

double Passenger::calc_cost(Location *origin , Location *destination , bool in_hurry){
    double total_cost = origin->calc_cost(destination , in_hurry);
    std::printf("%.2f\n" , total_cost);
    return total_cost;
}



void Person::cancel_trip(std::vector<Trip *> &trip_list , int trip_id){
    for(int i=0 ; i < trip_list.size() ; i++){
        if(trip_id == trip_list[i]->id){
            if(trip_list[i]->has_condition_canceling(this)){
                delete trip_list[i];
                trip_list.erase(trip_list.begin() + i);
                is_in_trip = false;
                return ;
            }
            return ;
        }
    }
    throw My_Exception(FIND_ERROR);
}



void Person::print_info_trip_list(std::vector<Trip *> &trip_list , std::string& body){
    throw My_Exception(PERMISSION_ERROR);
}    

void Person::print_info_a_trip(Trip *trip_wanted){
    throw My_Exception(PERMISSION_ERROR);
}



Passenger::Passenger() : Person(){
    
}


Passenger::Passenger(std::string _name , std::string _role) : Person(_name){
    role = _role;
}

bool Person::is_equal_name(std::string _name){
    if(name == _name)
        return 1;
    return 0;    
}


void Passenger::request_trip(std::vector<Trip *> &trip_list ,
        Location *origin , Location *destination, int trip_id , bool in_hurry){

            if(is_in_trip){
                throw My_Exception(REQUEST_ERROR);
                return;
            }
            trip_list.push_back(new Trip(origin , destination , trip_id , this));
            trip_list[trip_list.size() - 1]->calc_cost_of_trip(in_hurry);
            is_in_trip = true;
            std::cout << trip_id << std::endl;   
}






Driver::Driver() : Person(){

}

Driver::Driver(std::string _name , std::string _role) : Person(_name){
    role = _role;
}




void Driver::request_trip(std::vector<Trip *> &trip_list ,
        Location *origin , Location *destination, int trip_id , bool in_hurry){

    throw My_Exception(PERMISSION_ERROR);
}

void Driver::print_info_trip_list(std::vector<Trip *> &trip_list , std::string& body){
    
    for(int i=0 ; i < trip_list.size() ; i++){
        trip_list[i]->print_my_info(body);    
    }
    
}   

void Driver::accept_trip(Trip *trip_accept){
    if(is_in_trip)
        throw My_Exception(REQUEST_ERROR);

    trip_accept->start_trip();
    my_trip = trip_accept;
    is_in_trip = true;    
}


void Driver::notify_finishing_trip(Trip *trip_finished){
    if(my_trip->id != trip_finished->id)
        throw My_Exception(PERMISSION_ERROR);
    if(is_in_trip == false)
        throw My_Exception(REQUEST_ERROR);

    my_trip->finish_trip();
    is_in_trip = false;

}





void Driver::print_info_a_trip(Trip *trip_wanted){
    std::string body;
    trip_wanted->print_my_info(body);
}






