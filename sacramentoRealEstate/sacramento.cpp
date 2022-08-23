#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct houseData {
  std::string address;
  std::string city;
  int zip;
  int bed;
  int bathRooms;
  int sqrft;
  int price;

};

int avgSacPrice(vector<houseData>caData){

    int total = 0;
    int numHouses = 0;

    for(auto house: caData){
        if(house.city == "SACRAMENTO"){
            numHouses++;
            total += house.price;
        }
    }

    return total/numHouses;

}

int numOfRanchoHouses(vector<houseData> caData){
    int total = 0;
    for(auto val:caData){
        if(val.city == "RANCHO CORDOVA"){
            total++;
        }
    }

    return total;
}

int numOfRosevilleHouses(vector<houseData> caData){
    int total = 0;
    for(auto val:caData){
        if(val.city == "ROSEVILLE"){
            total++;
        }
    }

    return total;
}

int highestPrice(std::vector<houseData> caData){

    for (int i = 0; i < caData.size(); i++){

        if(caData[i].price > caData[0].price){

            caData[0].price = caData[i].price;

        }
    }

    return caData[0].price;
}

int numOfCrystalwoodHousesSold(vector<houseData> caData){
    int total = 0;
    string cwSize = "CRYSTALWOOD CIR";
    for(auto val:caData){
        if(val.address.size() >= cwSize.size()){
            string temp = val.address.substr(val.address.size()-cwSize.size());
            if(temp == cwSize){
                total++;
            }
        }
    }

    return total;
}

int lowestPriceSac(std::vector<houseData>caData){

    std::vector<houseData>sacData;

    for(auto house: caData){

        if(house.city == "SACRAMENTO"){
            sacData.push_back(house);
        }

    }


    for (int i = 0; i < sacData.size(); i++){

        if(sacData[i].price < sacData[0].price){

            sacData[0].price = sacData[i].price;

        }

    }

    return sacData[0].price;
}

int highestPriceSac(std::vector<houseData>caData){

    std::vector<houseData>sacData;

    for(auto house: caData){

        if(house.city == "SACRAMENTO"){
            sacData.push_back(house);
        }

    }


    for (int i = 0; i < sacData.size(); i++){

        if(sacData[i].price > sacData[0].price){

            sacData[0].price = sacData[i].price;

        }

    }

    return sacData[0].price;
}

int lowestPrice(std::vector<houseData>caData){


    for (int i = 0; i < caData.size(); i++){

        if(caData[i].price < caData[0].price){

            caData[0].price = caData[i].price;

        }
    }

    return caData[0].price;

}

int avgSize(std::vector<houseData>caData){

    int total = 0;

    for(auto house: caData){

        total += house.sqrft;


    }

    return total/caData.size();

}

int avgSacBed(std::vector<houseData>caData){


    int total = 0;
    int numBeds = 0;

    for(auto house: caData){

        if(house.city == "SACRAMENTO"){
            numBeds++;
            total += house.bed;
        }

    }

    
    return total/numBeds;

}


int avgBaths(std::vector<houseData>caData){

    int total = 0;
    int baths = 0;

    for(auto house: caData){

        baths++;
        total += house.bathRooms;
        
    }

    
    return total/baths;

}

int main(){
  
  std::string line;
  std::vector<houseData> caData;

  std::ifstream myFile("sacramento.txt");

    while (std::getline(myFile, line)) {
        stringstream ss(line);

        std::string taddress;
        std::string tcity;
        std::string tzip;
        std::string tbed;
        std::string tbathRooms;
        std::string tsqrft;
        std::string tprice;

        std::getline(ss, taddress, ',');
        std::getline(ss, tcity, ',');
        std::getline(ss, tzip, ',');
        std::getline(ss, tbed, ',');
        std::getline(ss, tbathRooms, ',');
        std::getline(ss, tsqrft, ',');
        std::getline(ss, tprice, ',');

        caData.push_back({taddress, tcity, std::stoi(tzip), std::stoi(tbed), std::stoi(tbathRooms), std::stoi(tsqrft), std::stoi(tprice)});
    }

    std::cout << "Number of houses in total: " << caData.size() << std::endl;
    std::cout << "Highest overall price: " << highestPrice(caData) << std::endl;
    std::cout << "Average Sacramento price: " << avgSacPrice(caData) << std::endl;
    std::cout << "Lowest price: " << lowestPrice(caData) << std::endl;
    std::cout << "Avg size: " << avgSize(caData) << std::endl;
    std::cout << "Avg beds: " << avgSacBed(caData) << std::endl;
    std::cout << "Avg baths: " << avgBaths(caData) << std::endl;
}