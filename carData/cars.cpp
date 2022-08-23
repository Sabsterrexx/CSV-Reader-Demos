#include <iostream>
#include<vector>

const int WIDTH = 20;
const int MONEY_WIDTH = 8;


struct Car{

  std::string carMake;
  std::string carModel;
  int yearModel;
  double cost;

};

std::vector<Car>cars;

void display(){

  for(auto car: cars){

    std::cout.width(WIDTH);
    std::cout.setf(std::ios::left); 
    std::cout << car.carMake; 

    std::cout.width(WIDTH);
    std::cout.setf(std::ios::left); 
    std::cout << car.carModel; 

    std::cout.width(WIDTH);
    std::cout.setf(std::ios::left); 
    std::cout << car.yearModel; 


    std::cout.width(1);
    std::cout.setf(std::ios::left); 
    std::cout << "$"; 

    std::cout.width(MONEY_WIDTH-1);
    std::cout.setf(std::ios::right); 
    std::cout << car.cost; 
    std::cout << std::endl;  

    std::cout.unsetf(std::ios::right);
  }



}


int main(){

  cars.push_back({"Ford","Taurus",1997,21000});
  
  cars.push_back({"Honda","Accord",1992,11000});

  cars.push_back({"Lamborghini","Countach",1997,200000});

  std::cout.width(WIDTH);
  std::cout.setf(std::ios::left); 
  std::cout << "Make";

  std::cout.width(WIDTH);
  std::cout.setf(std::ios::left); 
  std::cout << "Model";
  
  std::cout.width(WIDTH);
  std::cout.setf(std::ios::left); 
  std::cout << "Year";

  std::cout.width(MONEY_WIDTH);
  std::cout.setf(std::ios::left); 
  std::cout << "Cost" << std::endl;
  std::cout << std::endl;


  display();

  cars.push_back({});

  std::cout << "Input a new car model\n";

  std::cin >> cars[3].carModel;

  std::cout << "Input a new car make\n";

  std::cin >> cars[3].carMake;

  std::cout << "Input a new car year\n";

  std::cin >> cars[3].yearModel;

  std::cout << "Input a new car cost\n";

  std::cin >> cars[3].cost;

  display();

}