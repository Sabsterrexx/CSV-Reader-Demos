#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct World {
  std::string country;
  int area;
  double birthRate;
  double deathRate;
  long long debt;
  long long gdp;
  double infantMortality;
  int internetHosts;
  int internetUsers;
  int laborForce;
  double lifeExpectancy;
};

int numCountries(std::vector<World> world) { return world.size(); }

std::string largestCountry(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].area > world[0].area) world[0] = world[i];

  return world[0].country;
}

std::string smallestCountry(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].area < world[0].area) world[0] = world[i];

  return world[0].country;
}

int avgCountrySize(std::vector<World> world) {
  long sum;

  for (auto country : world) sum += country.area;

  return sum / world.size();
}

std::string mostInternetHosts(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].internetHosts > world[0].internetHosts) world[0] = world[i];

  return world[0].country;
}

std::string mostInternetUsers(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].internetUsers > world[0].internetUsers) world[0] = world[i];

  return world[0].country;
}

double highestBirthRate(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].birthRate > world[0].birthRate) world[0] = world[i];

  return world[0].birthRate;
}

long long avgGDP(std::vector<World> world) {
  long long num = 0;
  long long sum = 0;

  for (int i = 0; i < world.size(); i++) {
    if (world[i].gdp > 0) {
      sum += world[i].gdp;
      num++;
    }
  }

  return sum / num;
}

double avgLife(std::vector<World> world) {
  double num = 0;
  double sum = 0;

  for (int i = 0; i < world.size(); i++) {
    if (world[i].lifeExpectancy > 0) {
      num++;
      sum += world[i].lifeExpectancy;
    }
  }

  return sum / num;
}

std::string highestLife(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].lifeExpectancy > world[0].lifeExpectancy) world[0] = world[i];

  return world[0].country;
}

long long avgDebt(std::vector<World> world) {
  long long sum = 0;
  long long num = 0;

  for (int i = 0; i < world.size(); i++) {
    if (world[i].debt > 0) {
      num++;
      sum += world[i].debt;
    }
  }

  return sum / num;
}

std::string smallestLabor(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].laborForce < world[0].laborForce && world[i].laborForce > 0)
      world[0] = world[i];

  return world[0].country;
}

double avgMort(std::vector<World> world) {
  double sum = 0;
  int num = 0;

  for (int i = 0; i < world.size(); i++) {
    if (world[i].infantMortality > 0) {
      num++;
      sum += world[i].infantMortality;
    }
  }

  return sum / num;
}

std::string lowestDeath(std::vector<World> world) {
  for (int i = 0; i < world.size(); i++)
    if (world[i].deathRate < world[0].deathRate && world[i].deathRate > 0)
      world[0] = world[i];

  return world[0].country;
}

int main() {
  std::string line;
  std::vector<World> world;

  std::ifstream myFile("countryData.txt");

  while (std::getline(myFile, line)) {
    stringstream ss(line);

    std::string tcountry;
    std::string tarea;
    std::string tbirthRate;
    std::string tdeathRate;
    std::string tdebt;
    std::string tgdp;
    std::string tinfantMortality;
    std::string tinternetHosts;
    std::string tinternetUsers;
    std::string tlaborForce;
    std::string tlifeExpectancy;

    std::getline(ss, tcountry, ',');
    std::getline(ss, tarea, ',');
    std::getline(ss, tbirthRate, ',');
    std::getline(ss, tdeathRate, ',');
    std::getline(ss, tdebt, ',');
    std::getline(ss, tgdp, ',');
    std::getline(ss, tinfantMortality, ',');
    std::getline(ss, tinternetHosts, ',');
    std::getline(ss, tinternetUsers, ',');
    std::getline(ss, tlaborForce, ',');
    std::getline(ss, tlifeExpectancy, ',');

    world.push_back({

        tcountry, std::stoi(tarea), std::stod(tbirthRate),
        std::stod(tdeathRate), std::stoll(tdebt), std::stoll(tgdp),
        std::stod(tinfantMortality), std::stoi(tinternetHosts),
        std::stoi(tinternetUsers), std::stoi(tlaborForce),
        std::stod(tlifeExpectancy)

    });
  }

  std::cout << "Number of countries: " << world.size() << std::endl;
  std::cout << "Largest country by area: " << largestCountry(world) << std::endl;
  std::cout << "Smallest country by area: " << smallestCountry(world)<< std::endl;
  std::cout << "Average country size: " << avgCountrySize(world) << std::endl;
  std::cout << "Most internet hosts: " << mostInternetHosts(world) << std::endl;
  std::cout << "Most internet users: " << mostInternetUsers(world) << std::endl;
  std::cout << "Highest birth rate: " << highestBirthRate(world) << std::endl;
  std::cout << "Average GDP: " << avgGDP(world) << std::endl;
  std::cout << "Average life expectancy: " << avgLife(world) << std::endl;
  std::cout << "Highest life expectancy: " << highestLife(world) << std::endl;
  std::cout << "Average GDP: " << avgDebt(world) << std::endl;
  std::cout << "Smallest Labor Force: " << smallestLabor(world) << std::endl;
  std::cout << "Average Infant Mortality: " << avgMort(world) << std::endl;
  std::cout << "Lowest Death: " << lowestDeath(world) << std::endl;
}