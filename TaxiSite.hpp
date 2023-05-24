#ifndef _TAXISITE_HPP
#define _TAXISITE_HPP

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<vector>
#include<cstring>
#include"./server/server.hpp"
#include"Person.hpp"
#include"Location.hpp"
#include"Trip.hpp"
#include"Exception.hpp"  
#include"func.hpp"




const std::string POST_C = "POST";
const std::string DELETE_C = "DELETE";
const std::string GET_C= "GET";
const std::string TRIPS= "trips";
const std::string SIGNUP = "signup";
const std::string ACCEPT = "accept";
const std::string COST = "cost";
const std::string FINISH = "finish";
const std::string USERNAME = "username";    
const std::string ID = "id";
const std::string SORT_BY_COST = "sort_by_cost";
const std::string DESTINATION = "destination";
const std::string ORIGIN = "origin";
const std::string IN_HURRY = "in_hurry";
const std::string ROLE = "role";
const std::string GOOD_MESSAGE = "OK";
const std::string YES = "yes";
const std::string NO = "no";





class TaxiSite : public Server{
private:
    int last_id_trip;
    std::vector<Person *> users;
    std::vector<Location *> Locations_list;
    std::vector<Trip *> trips_list;
public:
    TaxiSite();
    TaxiSite(std::ifstream &locations , int port = 5000);
    ~TaxiSite();
    void read_location_list(std::ifstream &locations);
    void run_site();
    void signup(std::string username , std::string role);
    void get_trip_list(std::string username ,  std::string &body);
    void get_trip_list_sorted_by_cost(std::string username, std::string &body);
    void print_trips_info();
    void sorted_by_cost(std::vector<Trip *> &trip_list);
    
    int request_trip(std::string username , std::string origin , std::string destination , bool in_hurry);
    double get_cost_trip(std::string username ,std::string origin ,std::string destination ,bool in_hurry);
    void get_a_trip_info(std::string username , int trip_id);
    void delete_trip(std::string username , int id);
    void accept_trip(std::string username , int trip_id);
    void finish_trip(std::string username , int trip_id);
    Person * find_user(std::string username);
    Location * find_location(std::string name);
    Trip * find_trip(int id);

};












#endif