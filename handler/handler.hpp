#ifndef _HANDLER_HPP
#define _HANDLER_HPP

#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<string.h>
#include"../TaxiSite.hpp"
#include"../server/server.hpp"


const std::string SIGNUP_PAGE_SUCCSFULL = "/login_success";

class SignupHandler : public RequestHandler{
private:
    TaxiSite * site;    
public:
    SignupHandler(TaxiSite * _site){ site = _site;}
    Response *callback(Request *);    
};

class TripRequestHandler : public RequestHandler{
private:
    TaxiSite * site;    
public:
    TripRequestHandler(TaxiSite * _site){ site = _site;}
    Response *callback(Request *); 
};


class CancleTripHandler : public RequestHandler{
private:
    TaxiSite * site;    
public:
    CancleTripHandler(TaxiSite * _site){ site = _site;}
    Response *callback(Request *); 
};


class ShowTripListHandler : public RequestHandler{
private:
    TaxiSite * site;    
public:
    ShowTripListHandler(TaxiSite * _site){ site = _site;}
    Response *callback(Request *); 
};

class FinishTripHandler : public RequestHandler{
private:
    TaxiSite * site;    
public:
    FinishTripHandler(TaxiSite * _site){ site = _site;}
    Response *callback(Request *); 
};

class AcceptTripHandler : public RequestHandler{
private:
    TaxiSite * site;    
public:
    AcceptTripHandler(TaxiSite * _site){ site = _site;}
    Response *callback(Request *); 
};



#endif