#include"handler.hpp"


Response * SignupHandler::callback(Request *req){
    Response *respons = new Response;
    std::string name = req->getBodyParam(USERNAME);
    std::string role = req->getBodyParam(ROLE);
    if(role != PASSENGER)
        role = DRIVER;
    try{

        site->signup(name , role);
        
        respons = Response::redirect(SIGNUP_PAGE_SUCCSFULL);
        
        
        return respons;
    }
    catch(My_Exception& error){
        std::string path = error.show_message();

        respons = Response::redirect(path);
        return respons;
    }

    

}




Response * TripRequestHandler::callback(Request *req){
    std::string username = req->getBodyParam(USERNAME);
    std::string origin = req->getBodyParam(ORIGIN);
    std::string destination = req->getBodyParam(DESTINATION);
    std::string in_hurry_mode = req->getBodyParam(IN_HURRY);
    std::string request_trip = req->getBodyParam("request");
    
    bool in_hurry = false;
    if(in_hurry_mode == YES)
        in_hurry = true;
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");

    std::string body;    
    
    try{    
        if(request_trip == YES){
            int id = site->request_trip(username , origin , destination , in_hurry);
            
            body += "<!DOCTYPE html><html>";
            body += "\n<head>";
            body += "\n<link rel='stylesheet' href='/classes.css'>";
            body += "\n</head>"; 
            body += "<body>"; 
            body += "\n    <h1 style='color: rgb(61, 61, 236);font-size: 60px; margin: 4px;' >UTAXI!</h1>";
            body += "\n    <div style='width: 100%; border-radius: 7px;'>";
            body += "\n        <div class='menu_div'  ><a class='menu' href='/'>HOME</a></div";
            body += "\n        ><div  class='menu_div'><a class='menu' href='/signuppage'>Signup</a></div";
            body += "\n        ><div  class='menu_div'><a class='menu' href='/request'>Request Trip</a></div";
            body += "\n        ><div          class='menu_div'><a class='menu' href='/login'>Trip List</a></div>";
            body += "\n    </div>";

            body += "  <p style='text-align: center; font-size: larger' >Your trip id is: ";
            body +=  std::to_string(id); 
            body +=  "</p>  </body></html>";
            
            res->setBody(body);
            return res;
        }
        else{
            body += "<!DOCTYPE html><html>";

            body += "\n<head>";
            body += "\n<link rel='stylesheet' href='/classes.css'>";
            body += "\n</head>";
            body += "<body>  ";
            
            body += "\n    <h1 style='color: rgb(61, 61, 236);font-size: 60px; margin: 4px;' >UTAXI!</h1>";
            body += "\n    <div style='width: 100%; border-radius: 7px;'>";
            body += "\n        <div class='menu_div'  ><a class='menu' href='/'>HOME</a></div";
            body += "\n        ><div  class='menu_div'><a class='menu' href='/signuppage'>Signup</a></div";
            body += "\n        ><div  class='menu_div'><a class='menu' href='/request'>Request Trip</a></div";
            body += "\n        ><div          class='menu_div'><a class='menu' href='/login'>Trip List</a></div>";
            body += "\n    </div>"; 
            body += " <p style='text-align: center; font-size: larger'>Your trip cost is: ";
            double exact_cost = site->get_cost_trip(username , origin, destination, in_hurry);
            body += flout_chang_to_string(exact_cost);
            body +=  "</p>  </body></html>";
            res->setBody(body);
            return res;
        }
    }
    catch(My_Exception &error){
        std::string path = error.show_message();
        res = Response::redirect(path);
        return res;
    }    


        
}

Response * CancleTripHandler::callback(Request *req){
    std::string username = req->getBodyParam(USERNAME);
    std::string id_str = req->getBodyParam(ID);
    int id = std::stoi(id_str);
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    std::string body;    

    try{
        body += "\n<link rel='stylesheet' href='/classes.css'>";
        body += "<!DOCTYPE html><html>";
        body += "\n<head>";
        body += "\n<link rel='stylesheet' href='/classes.css'>";
        body += "\n</head>"; 
        body += "<body>"; 
        body += "\n    <h1 style='color: rgb(61, 61, 236);font-size: 60px; margin: 4px;' >UTAXI!</h1>";
        body += "\n    <div style='width: 100%; border-radius: 7px;'>";
        body += "\n        <div class='menu_div'  ><a class='menu' href='/'>HOME</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/signuppage'>Signup</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/request'>Request Trip</a></div";
        body += "\n        ><div          class='menu_div'><a class='menu' href='/login'>Trip List</a></div>";
        body += "\n    </div>";  
        body += "   <p>Your trip was cancled</p>";
        site->delete_trip(username , id);
        body +=  "</body></html>";
        res->setBody(body);
        return res;
    }catch(My_Exception & error){
        std::string path = error.show_message();
        res = Response::redirect(path);
        return res;
    }
}



Response * FinishTripHandler::callback(Request *req){
    std::string username = req->getSessionId();
    std::string id_str = req->getQueryParam(ID);
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    res->setSessionId(username);
    std::string body;
    try{
        body += "<!DOCTYPE html>";
        body += "\n<html>";
        body += "\n<head>";
        body += "\n<link rel='stylesheet' href='/classes.css'>";
        body += "\n</head>";
        body += "\n<body>";
        body += "\n    <h1 style='color: rgb(61, 61, 236);font-size: 60px; margin: 4px;' >UTAXI!</h1>";
        body += "\n    <div style='width: 100%; border-radius: 7px;'>";
        body += "\n        <div class='menu_div'  ><a class='menu' href='/'>HOME</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/signuppage'>Signup</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/request'>Request Trip</a></div";
        body += "\n        ><div          class='menu_div'><a class='menu' href='/login'>Trip List</a></div>";
        body += "\n    </div>";
        site->finish_trip(username , std::stoi(id_str));

        body += "\n <h2 style='text-align: center; margin-top:30px'>You Finish the trip successfully</h2>";
        
        body += "<img src='/taxi2.png' style='animation-delay: 1s;' class='animation_mode' >";
        
        body += "</body>";
        body += "</html>";

        res->setBody(body);
        return res;

    }catch(My_Exception &error){
        std::string path = error.show_message();
        res = Response::redirect(path);
        return res;
    }
    
}

Response * AcceptTripHandler::callback(Request *req){
    std::string username = req->getSessionId();
    std::string id_str = req->getQueryParam(ID);
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    res->setSessionId(username);
    std::string body;
    try{
        body += "<!DOCTYPE html>";
        body += "\n<html>";
        body += "\n<head>";
        body += "\n<link rel='stylesheet' href='/classes.css'>";
        body += "\n</head>";
        body += "\n<body>";
        body += "\n    <h1 style='color: rgb(61, 61, 236);font-size: 60px; margin: 4px;' >UTAXI!</h1>";
        body += "\n    <div style='width: 100%; border-radius: 7px;'>";
        body += "\n        <div class='menu_div'  ><a class='menu' href='/'>HOME</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/signuppage'>Signup</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/request'>Request Trip</a></div";
        body += "\n        ><div          class='menu_div'><a class='menu' href='/login'>Trip List</a></div>";
        body += "\n    </div>";
        site->accept_trip(username , std::stoi(id_str));

        body += "\n <h2 style='text-align: center; margin-top:30px'>You Accept the trip successfully</h2>";
        body += "<img src='/taxi2.png' style='animation-delay: 1s;' class='animation_mode' >";
        
        body += "</body>";
        body += "</html>";
        
        res->setBody(body);
        return res;

    }catch(My_Exception &error){
        std::string path = error.show_message();
        res = Response::redirect(path);
        return res;
    }

}







Response * ShowTripListHandler::callback(Request *req){
    std::string username = req->getQueryParam(USERNAME);
    std::string is_sort_cost = req->getQueryParam(SORT_BY_COST);
    std::string username2 = req->getSessionId();
    Response *res = new Response;

    if(username.size() != 0 ){
        username2 = username;
    }
    else
        username = username2;

    res->setHeader("Content-Type", "text/html");
    res->setSessionId(username2);

    std::string body;
    try{

        body += "<!DOCTYPE html>";
        body += "\n<html>";
        body += "\n<head>";
        body += "\n<link rel='stylesheet' href='/classes.css'>";
        body += "\n</head>";
        body += "\n<body>";
        body += "\n    <h1 style='color: rgb(61, 61, 236);font-size: 60px; margin: 4px;' >UTAXI!</h1>";
        body += "\n    <div style='width: 100%; border-radius: 7px;'>";
        body += "\n        <div class='menu_div'  ><a class='menu' href='/'>HOME</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/signuppage'>Signup</a></div";
        body += "\n        ><div  class='menu_div'><a class='menu' href='/request'>Request Trip</a></div";
        body += "\n        ><div          class='menu_div'><a class='menu' href='/login'>Trip List</a></div>";
        body += "\n    </div>";
        body += "\n <h2 style='text-align: center;'>Trip list</h2>";
        body += "<table >";
        body += "\n <tr>";
        body += "\n     <th><a href='/list?sort_by_cost=no'>Trip id</a></th>";
        body += "\n     <th>Name</th>";
        body += "\n     <th>Origin</th>";
        body += "\n     <th>Destination</th>";
        body += "\n     <th>State</th>";
        body += "\n     <th><a href='/list?sort_by_cost=yes'>Trip cost</a></th>";
        body += "\n     <th>  </th>";
        body += "\n </tr>";

        if(is_sort_cost == NO){
            site->get_trip_list(username , body);
        }
        else{
            site->get_trip_list_sorted_by_cost(username , body);

        }
        

        body += "\n </table>";
        body += "<img src='/taxi2.png' style='animation-delay: 1s;' class='animation_mode' >";
        
        body += "</body>";
        body += "</html>";
        res->setBody(body);
        return res;
    }catch(My_Exception & error){
        std::string path = error.show_message();
        res = Response::redirect(path);
        return res;
    }
}




