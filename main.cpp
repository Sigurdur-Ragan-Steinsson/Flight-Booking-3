#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  FlightBooking();
  void printStatus();
  bool reserveSeats(int number_of_seats);
  bool cancelReservations(int number_of_seats);
  void updateFlight (int i, int c);
  int getId() { return id; };
private:
  int id;
  int capacity;
  int reserved;
  float percentOver;
  float maxCapacity;
};
FlightBooking::FlightBooking()
{
  id = 0; 
  capacity = 0; 
  reserved = 0;
}
FlightBooking::FlightBooking(int inputId, int inputCapacity, int inputReserved)
{
  id = inputId;
  capacity = inputCapacity;
  percentOver = 1.05;
  maxCapacity = percentOver * capacity;
  
  if((inputReserved < maxCapacity) && (inputReserved > 0))
    reserved = inputReserved;
  else if (inputReserved >= maxCapacity)
  {
    reserved = maxCapacity;
    reserved++;}
    
  else
    reserved = 0;
    
}

void FlightBooking::printStatus()
{
  //cout << "reserved = " << reserved << endl;
  cout << "Flight " << id << " : " << reserved <<  "/" <<  capacity << "(" << (reserved * 1.0) / capacity * 100 << "%)" << "seats taken";
}

bool FlightBooking::reserveSeats(int number_of_seats)
{
  if(reserved + number_of_seats <= maxCapacity){
    reserved += number_of_seats;
    return true;
  }
  else{
    cout << "Cannot perform this operation" << endl;
    return false;
    }
  // try to add reservations and return 'true' on success
  // keep the limits in mind
}
bool FlightBooking::cancelReservations(int number_of_seats)
{
  //max and min may be different, (ex. max reserve iirc is 110% of capacity) so go back, check and then fix
  if(reserved - number_of_seats >= 0){
    reserved -= number_of_seats;
    return true;
  }
  else{
    cout << "Cannot perform this operation" << endl;
    return false;
    }
  // try to canel reservations and return 'true' on success
  // keep the limits in mind
  }

void FlightBooking::updateFlight(int i, int c){
  id = i;
  capacity = c;
}

string findCommand(string command){
  string determiner;
  string stopword = "quit";
  if(command.find(' ') < command.length()){
    determiner = command.substr(0, command.find(' '));
    return determiner;
    }
  else
    return stopword;

  //print for x < flightNum, if x[id] != 0 print id
}
int findID(string command){
  int id;
  string segment;
  if(command.find(' ') < command.length()){
    segment = command.substr(command.find(' '));
    if(segment.find(' ') < segment.length()){
      id = stoi(segment.substr(0,segment.find(' ')));
    }
    else{
      id = stoi(segment);
    }
    return id;
  }
  else{
    return -1;
  }
}

int main() {
  FlightBooking booking[10];
  // Use this to have some starting value
  // booking[0] = FlightBooking(1, 400, 0);
  // booking[0].printStatus();
  string command = "";
  string det, segment;
  int ID;
  while (command != "quit")
  {
    cout << "What would you like to do?: ";
    getline(cin,command);
    // handle the command
    segment = command.substr(command.find(' '));
    det = findCommand(command);
    ID = findID(command);
    if(det == "add"){ 
      booking[ID].reserveSeats(stoi(segment.substr(segment.find(' '))));
    }
    else if(det == "cancel"){
      booking[ID].cancelReservations(stoi(segment.substr(segment.find(' '))));
    }
    else if(det == "delete"){
      
    }
  }
  return 0;
}