#include"Location.hpp"



Location::Location(){


}



Location::Location(std::string name , double _latitude , double _longitude , int _trraffic){
        loc_name = name;
        latitude = _latitude;
        longitude = _longitude;
        trraffic = _trraffic;
}

double Location::distance_bitween(Location *next_location){
        return DISTANCE_COEFFICIENT * sqrt(pow(latitude - next_location->latitude , 2) +
                                                pow(longitude - next_location->longitude , 2)); 
}


double Location::calc_cost(Location *next_location , bool in_hurry){
        double dist = distance_bitween(next_location);
        double cost = dist * (trraffic + next_location->trraffic) * PRICE_COEFFICIENT;
        if(in_hurry)
                return cost * IN_HURRY_COEFFICIENT;
        return cost;        
}




