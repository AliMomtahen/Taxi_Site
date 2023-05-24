FLAGE = g++ -std=c++11
CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template


all: $(BUILD_DIR) utaxi.out


utaxi.out: main.o TaxiSite.o Location.o Trip.o Person.o Exception.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o handler.o
	$(FLAGE) main.o TaxiSite.o Location.o Trip.o Person.o Exception.o func.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o handler.o  -o utaxi.out 
	rm *.o

main.o: main.cpp TaxiSite.o
	$(FLAGE) -c main.cpp

TaxiSite.o: TaxiSite.cpp TaxiSite.hpp Trip.o Person.o func.o $(BUILD_DIR)/server.o
	$(FLAGE) -c TaxiSite.cpp 


Location.o: Location.cpp Location.hpp Exception.o
	$(FLAGE)  -c Location.cpp

Trip.o: Trip.cpp Trip.hpp Location.o
	$(FLAGE) -c Trip.cpp 

Person.o: Person.cpp Person.hpp Trip.o Location.o
	$(FLAGE) -c Person.cpp

Exception.o: Exception.cpp Exception.hpp 
	$(FLAGE) -c Exception.cpp

func.o: func.cpp func.hpp Person.o Trip.o
	$(FLAGE) -c func.cpp

handler.o: ./handler/handler.hpp  ./handler/handler.cpp TaxiSite.o $(BUILD_DIR)/server.o
	$(FLAGE) -c ./handler/handler.cpp


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o
	
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null

