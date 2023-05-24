#ifndef _LOCATION_HPP
#define _LOCATION_HPP


#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cfloat>




const double DISTANCE_COEFFICIENT = 110.5;
const double IN_HURRY_COEFFICIENT = 1.2;
const int PRICE_COEFFICIENT = 10000;


class Location
{
private:    
    std::string loc_name;
    double latitude;
    double longitude;
    int  trraffic;
public:
    Location();
    Location(std::string name , double _latitude , double _longitude , int _traffic);
    std::string get_name(){ return loc_name;}
    double calc_cost(Location *next_location , bool in_hurry);
    double distance_bitween(Location *next_location);
    
};














#endif


