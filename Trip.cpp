#include"Trip.hpp"
#include"Person.hpp"
#include"func.hpp"





Trip::Trip(){
}

Trip::Trip(Location * _origin , Location *_destination , int _id , Person *user){
    origin = _origin;
    destination = _destination;
    mode = WAIT_MODE;
    id = _id;
    user_trip = user;
    
}




void Trip::print_my_info(std::string& body){

    

    body+= "\n<tr>";
    body+= "\n    <td>" + std::to_string(id) + "</td>";
    body+= "\n    <td>" + user_trip->get_name() + "</td>";
    body+= "\n    <td>" + origin->get_name() + "</td>";
    body+= "\n    <td>" + destination->get_name() + "</td>";
    body+= "\n    <td>" + mode + "</td>";
    body+= "\n    <td>" + flout_chang_to_string(cost)  +"</td>";
    if(mode == WAIT_MODE){
        body+= "\n    <td class='td_hover'><a  href='/accept?id=" ;
        body +=  std::to_string(id) ;
        body += "'>Accept</a></td>";
    }
    else if(mode == TRAVEL_MODE){
        body+= "\n    <td class='td_hover'><a  href='/finish?id=" ;
        body +=  std::to_string(id) ;
        body += "'>Finish</a></td>";
    }
    else{
        body+= "\n    <td class='td_hover'>";
       
        body += "Finished</td>";
    }
    body+= "\n</tr>";
}


void Trip::calc_cost_of_trip(bool in_hurry){
    cost = origin->calc_cost(destination , in_hurry);
}


bool Trip::has_condition_canceling(Person *person_order){
    if(mode != WAIT_MODE){
        throw My_Exception(REQUEST_ERROR);
        return 0;
    }    
    if(person_order != user_trip){
        throw My_Exception(PERMISSION_ERROR);
        return 0;
    }    
    return 1;            
}

bool Trip::is_less_cost(Trip *trip_wanted){
    if(cost < trip_wanted->cost)
        return 1;
    return 0;    
}


void Trip::finish_trip(){
    if(mode != TRAVEL_MODE)
        throw My_Exception(REQUEST_ERROR);
    
    user_trip->finish_trip();
    mode = FINISH_MODE;    
}



void Trip::start_trip(){
    if(mode != WAIT_MODE)
        throw My_Exception(REQUEST_ERROR);

    mode = TRAVEL_MODE;
    user_trip->start_trip();    
}





