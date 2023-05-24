#ifndef _PERSON_HPP
#define _PERSON_HPP

#include<iostream>
#include<string>
#include<vector>
#include"Trip.hpp"
#include"Exception.hpp"


const std::string DRIVER = "driver";
const std::string PASSENGER = "passenger";







class Person{
protected:
    std::string name;
    std::string role;
    bool is_in_trip;
public:
    Person();
    Person(std::string _name);
    std::string get_name(){ return name;}
    bool is_equal_name(std::string _name);
    void print_name(){ std::cout << name;}
    virtual void request_trip(std::vector<Trip *> &trip_list ,
        Location *origin , Location *destination, int trip_id , bool in_hurry) = 0;

    virtual void print_info_trip_list(std::vector<Trip *> &trip_list , std::string& body);    
    virtual void print_info_a_trip(Trip *trip_wanted);
    virtual void cancel_trip(std::vector<Trip *> &trip_list , int trip_id);
    virtual void accept_trip(Trip *trip_accept);
    virtual double calc_cost(Location *origin , Location *destination , bool in_hurry);
    void start_trip(){ is_in_trip = true;}
    void finish_trip(){is_in_trip = false;}
    virtual void notify_finishing_trip(Trip *trip_wanted);
};



class Driver: public Person{
private:
    Trip *my_trip;


public:
    Driver();
    Driver(std::string _name , std::string _role);
    virtual void request_trip(std::vector<Trip *> &trip_list ,
        Location *origin , Location *destination, int trip_id , bool in_hurry);
    
    virtual void print_info_trip_list(std::vector<Trip *> &trip_list , std::string& body);    
    virtual void print_info_a_trip(Trip *trip_wanted);
    virtual void accept_trip(Trip *trip_accept);
    virtual void notify_finishing_trip(Trip *trip_wanted);

};





class Passenger: public Person{
private:


public:
    Passenger();
    Passenger(std::string _name  , std::string _role);
    virtual void request_trip(std::vector<Trip *> &trip_list ,
        Location *origin , Location *destination , int trip_id , bool in_hurry);
    
    virtual double calc_cost(Location *origin , Location *destination , bool in_hurry);


};














#endif
