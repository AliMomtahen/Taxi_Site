#include"TaxiSite.hpp"



TaxiSite::TaxiSite(){
    last_id_trip = 1;
}

TaxiSite::TaxiSite(std::ifstream& locations , int port) : Server(port) {
    last_id_trip = 1;
    read_location_list(locations);
}







void TaxiSite::read_location_list(std::ifstream& locations){
    std::string str_of_input;
    getline(locations , str_of_input);
    while(getline(locations , str_of_input)){
        std::vector<std::string> input;
        split(str_of_input , SPLITER_IN_FILE , input);
        std::string loc_name = input[0];
        double latitiude = stod(input[1]);
        double longitiude = stod(input[2]);
        int traffic = stoi(input[3]);
        Locations_list.push_back(new Location(loc_name , latitiude , longitiude , traffic));
    }

}

TaxiSite::~TaxiSite(){
    for(int i=0 ; i < users.size() ; i++){
        delete users[i];
    }
    for(int i=0 ; i < Locations_list.size() ; i++){
        delete Locations_list[i];
    }
    for(int i=0 ; i < trips_list.size() ; i++){
        delete trips_list[i];
    }
}





  

void TaxiSite::sorted_by_cost(std::vector<Trip *> &trip_list){
    for(int i=0 ; i < trip_list.size() - 1 ; i++){
        for(int j = i + 1; j < trip_list.size() ; j++){
            if(trip_list[i]->is_less_cost(trip_list[j])){
                std::swap(trip_list[i] , trip_list[j]);
                
            }
        }
    }
}


void TaxiSite::get_trip_list_sorted_by_cost(std::string username , std::string &body){
    Person * driver = find_user(username);
    
    if(!driver)
        throw My_Exception(FIND_ERROR);
    std::vector<Trip *> trips_sorted_by_cost = trips_list;
    sorted_by_cost(trips_sorted_by_cost);    
    driver->print_info_trip_list(trips_sorted_by_cost , body);    
}










double TaxiSite::get_cost_trip(std::string username ,std::string origin ,
    std::string destination ,bool in_hurry){

        Person *user = find_user(username);
        Location *origin_place = find_location(origin);
        Location *destination_place = find_location(destination);
        
        if(not_valid(user , origin_place , destination_place))
            throw My_Exception(FIND_ERROR);
        double cost = user->calc_cost(origin_place , destination_place , in_hurry);    
        return cost;
        
}



Person * TaxiSite::find_user(std::string username){
    for(int i=0 ; i < users.size() ; i++){
        if(users[i]->is_equal_name(username)){
            return users[i];
        }
    }
    return NULL;
}

Trip * TaxiSite::find_trip(int id){
    for(int i=0 ; i < trips_list.size() ; i++){
        if(id == trips_list[i]->id){
            return trips_list[i];
        }
    }
    throw My_Exception(FIND_ERROR);
    
}
 



void TaxiSite::get_trip_list(std::string username, std::string &body){
    Person * driver = find_user(username);
    

    
    if(!driver)
        throw My_Exception(FIND_ERROR);
    driver->print_info_trip_list(trips_list , body);
        
}
 
void TaxiSite::get_a_trip_info(std::string username , int trip_id){
    Person *driver = find_user(username);
    Trip *trip_wanted = find_trip(trip_id);

    if(not_valid(trip_wanted , driver)){
        throw My_Exception(FIND_ERROR);
    }
    driver->print_info_a_trip(trip_wanted);


}

void TaxiSite::delete_trip(std::string username , int id){
    Person *user = find_user(username);
    Trip *trip_wanted = find_trip(id);
    if(not_valid(trip_wanted , user)){
        throw My_Exception(FIND_ERROR);
    }
    user->cancel_trip(trips_list , id);
    std::cout << GOOD_MESSAGE << '\n';
}







Location * TaxiSite::find_location(std::string name){
    for(int i=0 ; i < Locations_list.size() ; i++){
        if(name == Locations_list[i]->get_name())
            return Locations_list[i];
    }
    return NULL;
}



int TaxiSite::request_trip(std::string username ,std::string origin ,
    std::string destination ,bool in_hurry){
        Person *user = find_user(username);
        Location *origin_place = find_location(origin);
        Location *destination_place = find_location(destination);
        if(not_valid(user , origin_place , destination_place))
            throw My_Exception(FIND_ERROR);
        user->request_trip(trips_list , origin_place , destination_place , last_id_trip , in_hurry);
        last_id_trip++;
        return last_id_trip - 1;
}


void TaxiSite::finish_trip(std::string username , int trip_id){
    Person *driver = find_user(username);
    Trip *trip_wanted = find_trip(trip_id);
    
    if(not_valid(trip_wanted , driver))
        throw My_Exception(FIND_ERROR);

    driver->notify_finishing_trip(trip_wanted);
    std::cout << GOOD_MESSAGE << std::endl;
            
}



void TaxiSite::accept_trip(std::string username , int trip_id){
    Person *driver = find_user(username);
    Trip *trip_wanted = find_trip(trip_id);
    if(not_valid(trip_wanted , driver))
        throw My_Exception(FIND_ERROR);
    driver->accept_trip(trip_wanted);
    std::cout << GOOD_MESSAGE << std::endl;

}



void TaxiSite::signup(std::string username , std::string role){
    Person *user = find_user(username);

    
    if(user != NULL)
        throw My_Exception(SIGNUP_ERROR);
    if(role == DRIVER){
        users.push_back(new Driver(username , role));            
    }
    else if(role == PASSENGER){
        users.push_back(new Passenger(username , role));
    }
    else{
        throw My_Exception(SIGNUP_ERROR);
    }
    std::cout << GOOD_MESSAGE << std::endl;

    

}


















