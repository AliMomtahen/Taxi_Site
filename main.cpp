#include<bits/stdc++.h>
#include"TaxiSite.hpp"
#include"./handler/handler.hpp"

#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iostream>




int main(int argc , char *argv[]){
    srand(time(NULL));
    std::string name_file_of_location = (std::string) argv[1];
    std::ifstream file_locs;

    file_locs.open(name_file_of_location);
    TaxiSite utaxi(file_locs , 5000);
    
    
    utaxi.setNotFoundErrPage("static/not_found_error.html");
    utaxi.get("/" , new ShowPage("static/home.html"));
    utaxi.get("/taxi2.png" , new ShowImage("static/taxi2.png"));
    utaxi.get("/classes.css" , new ShowFile("static/classes.css"  ,".css"));
    utaxi.get("/signuppage" , new ShowPage("static/signup.html"));
    utaxi.post("/signuppage" , new SignupHandler(&(utaxi)));
    utaxi.get("/request" , new ShowPage("static/request_trip.html"));
    utaxi.post("/request" , new TripRequestHandler(&(utaxi)));
    utaxi.post("/cancle" , new CancleTripHandler(&(utaxi)));
    utaxi.get("/accept" , new AcceptTripHandler(&(utaxi)));
    utaxi.get("/finish" , new FinishTripHandler(&(utaxi)));
    utaxi.get("/list" , new ShowTripListHandler(&(utaxi)));
    utaxi.get("/login" , new ShowPage("static/login.html"));
    utaxi.get("/static/bad_request" , new ShowPage("static/bad_request_error.html"));
    utaxi.get("/static/permission" , new ShowPage("static/permission_error.html"));
    utaxi.get("/static/not_found" , new ShowPage("static/not_found_error.html"));

    utaxi.get(SIGNUP_PAGE_SUCCSFULL ,new ShowPage("static/signup_success.html"));
    utaxi.run();
        
    return 0;
}