#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct carData {
  string name;
  double mpg;
  int cylinders;
  double displacement;
  double hp;
  double weight;
  double accel;
  int year;
  string country;
};

double findAverageMPG(vector<carData> cars) {
  double total = 0;
  for (auto val : cars) total += val.mpg;
  return total / cars.size();
}

int numUSCars(vector<carData> cars) {
  int total = 0;
  string temp;
  for (auto val : cars) {
    temp = val.country;
    if(temp == "US")total++;
  }
  return total;
}

int main() {
  ifstream myFile;
  myFile.open("cars.txt");

  string line;
  vector<carData> cars;

  int lineNum = 0;

  while (getline(myFile, line, '\n')) {
    
    if (lineNum <= 1) {
      lineNum++;
      continue;
    }

    stringstream ss(line);
    string tname;
    string tmpg;
    string tcylinders;
    string tdisplacement;
    string thp;
    string tweight;
    string taccel;
    string tyear;
    string tcountry;
    getline(ss, tname, ',');
    getline(ss, tmpg, ',');
    getline(ss, tcylinders, ',');
    getline(ss, tdisplacement, ',');
    getline(ss, thp, ',');
    getline(ss, tweight, ',');
    getline(ss, taccel, ',');
    getline(ss, tyear, ',');
    getline(ss, tcountry, ',');

    cars.push_back({tname, stod(tmpg), stoi(tcylinders), stod(tdisplacement),stod(thp), stod(tweight), stod(taccel), stoi(tyear),tcountry});
  
  }

  for(auto val : cars) cout << val.name << endl;

  cout << "Average mpg of all the cars is " << findAverageMPG(cars) << endl;
  cout << "There are " << numUSCars(cars) << " of cars made in the US" << endl;

  return 0;

}