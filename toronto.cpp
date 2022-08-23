#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct City {
  long long finalPrice;

  long long listPrice;

  int bedrooms;

  int bathRooms;

  int sqft;

  int parking;

  std::string type;

  std::string fullAddress;
};

int numSemi(std::vector<City>toronto){

    int n = 0;

    for(auto unit: toronto) if(unit.type == "Semi-Detached") n++;

    return n;

}

long long avgFinalPriceDetach(std::vector<City>toronto){

    long long sum = 0;
    long long n = 0;

    for(auto unit: toronto){
        if(unit.type == "Detached"){
            n++;
            sum += unit.finalPrice;
        }
    }

    return sum/n;

}

int profitable(std::vector<City>toronto){

    int n = 0;

    for(auto unit: toronto) if(unit.finalPrice > unit.listPrice) n++;
    
    return n;

}

void whichSoldMore(std::vector<City>toronto){

    int numHouse = 0;
    int numCondo = 0;

    for(auto unit: toronto){

        if(unit.type == "Semi-Detached" || unit.type == "Detached") numHouse++;

        else if(unit.type == "Condo Apt" || unit.type == "Condo Townhouse" || unit.type == "Condo Element") numCondo++;

    }

    if(numCondo > numHouse) std::cout << "Condos sold more by: " << numCondo - numHouse << " units" << std::endl;

    else if(numCondo < numHouse) std::cout << "Houses sold more by: " <<  numHouse - numCondo<< " units" << std::endl;

}


long long avgPriceQueens(std::vector<City>toronto){

    long long sum = 0;
    long long n = 0;

    for(auto unit: toronto){
        if(unit.fullAddress.find("The Queensway Ave") != std::string::npos){
            sum+= unit.finalPrice;
            n++;
        }
    }

    return sum/n;

}


long long avgCondoSize(std::vector<City>toronto){

    long long sum = 0;
    long long n = 0;

    for(auto unit: toronto){
        if(unit.type == "Condo Apt"){
            sum+= unit.sqft;
            n++;
        }
    }

    return sum/n;

}


std::string highestPrice(std::vector<City>toronto){

   for (int i = 0; i < toronto.size(); i++)
    if (toronto[i].finalPrice > toronto[0].finalPrice) toronto[0] = toronto[i];

  return toronto[0].fullAddress;

}


int moreThanMil(std::vector<City>toronto){

    int n = 0;

    for(auto unit: toronto) if(unit.finalPrice > 1000000) n++;

    return n;
    
}


int main() {
  std::string line;
  std::vector<City> toronto;

  std::ifstream myFile("torontoData.txt");

  while (std::getline(myFile, line)) {
    stringstream ss(line);

    std::string tfinalPrice;

    std::string tlistPrice;

    std::string tbedrooms;

    std::string tbathRooms;

    std::string tsqft;

    std::string tparking;

    std::string ttype;

    std::string tfullAddress;

    std::getline(ss, tfinalPrice, ',');
    std::getline(ss, tlistPrice, ',');
    std::getline(ss, tbedrooms, ',');

    std::getline(ss, tbathRooms, ',');

    std::getline(ss, tsqft, ',');
    std::getline(ss, tparking, ',');
    std::getline(ss, ttype, ',');
    std::getline(ss, tfullAddress, ',');

    toronto.push_back({std::stoll(tfinalPrice), std::stoll(tlistPrice),
                       std::stoi(tbedrooms), std::stoi(tbathRooms),
                       std::stoi(tsqft), std::stoi(tparking), ttype,
                       tfullAddress});
  }

    std::cout << "Number of units: " << toronto.size() << std::endl;

    std::cout << "Number of Semi Detatched Homes: " << numSemi(toronto) << std::endl;

    std::cout << "Average final price of Detatched Homes: " << avgFinalPriceDetach(toronto) << std::endl;

    std::cout << "Units where final price > listing price: " << profitable(toronto) << std::endl;

    whichSoldMore(toronto);

    std::cout << "Average price on Queens: "  << avgPriceQueens(toronto)<< std::endl;


    std::cout << "Average Condo Size: "  << avgCondoSize(toronto)<< std::endl;

    std::cout << "Highest Sold House: "  << highestPrice(toronto)<< std::endl;

    std::cout << "Units more than a million: "  << moreThanMil(toronto)<< std::endl;



}