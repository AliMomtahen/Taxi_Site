#ifndef _TRIP_HPP
#define _TRIP_HPP


#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cfloat>
#include"Location.hpp"

class Person;

const std::string FINISH_MODE = "finished";
const std::string TRAVEL_MODE = "traveling";
const std::string WAIT_MODE = "waiting";


class Trip{
private:
    Person *user_trip;
    Location *origin;
    Location *destination;
    std::string mode;
    double cost;
public:
    int id;
    Trip();
    Trip(Location *_origin , Location *_destination , int _id , Person *user);
    void calc_cost_of_trip(bool in_hurry);
    void print_my_info(std::string& body);
    void start_trip();
    void finish_trip();
    Person * get_user_trip(){ return user_trip;}
    bool has_condition_canceling(Person *person_orded);
    bool is_less_cost(Trip *trip_wanted);


};


const Trip EMPTY_TRIP(NULL , NULL, -1 , NULL);









#endif