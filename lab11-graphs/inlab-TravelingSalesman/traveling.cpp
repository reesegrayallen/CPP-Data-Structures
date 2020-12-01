// REESE ALLEN | rga2uz | 11-17-20 | traveling.cpp

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

// Implementation of brute-force traveling salesperson, building on traveling-skeleton.cpp

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    string start = dests[0];
    dests.erase(dests.begin()); // starting city is not to be permuted (always start and end at this city)

    float shortest_distance = computeDistance(me, start, dests);

    // // program should print out the shortest path as the last thing printed
    // // can print out multiple paths as shortest is found, but NOT every path 

    vector<string> shortest_path; // to be printed

    for(int i = 0; i < dests.size(); i++){
      shortest_path.push_back(dests[i]);
    }

    sort(dests.begin(), dests.end()); // must start out with a sorted vector (and then moves through each possible list ordering)

    while(next_permutation(dests.begin(), dests.end())){ // modifies the vector passed in (does not return a new permutation)

      float perm_distance = computeDistance(me, start, dests);

      if(perm_distance < shortest_distance){
        shortest_distance = perm_distance;
        shortest_path.clear();
        for(int i = 0; i < dests.size(); i++){shortest_path.push_back(dests[i]);}
      }
    }


    cout << "Minimum path has distance " << shortest_distance << ": ";      // opting to just print out the shortest
    printRoute(start, shortest_path);

    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**
 * @brief Computes the full distance of the cycle
 *
 * @details This function computes the total distance of the cycle, repeatedly calling getDistance on two adjacent 
 * cities in the vector, beginning with the start, to each of the cities in dests, and ending back at start.
 *
 * @return The total distance traveled
 * @param me MiddleEarth world
 * @param start The starting city 
 * @param dests A vector of cities to visit 
*/
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {

    float full_distance = me.getDistance(start, dests[0]);
    full_distance += me.getDistance(dests[dests.size() - 1], start);

    for(int i = 0; i < dests.size()-1; i++){
      full_distance += me.getDistance(dests[i], dests[i+1]);
    }

    return full_distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor

/**
 * @brief Prints the entire route 
 * This function prints the route traveled, starting and ending at the start
 *
 * @return void 
 * @param start The starting city
 * @param dests A vector of cities  
*/
void printRoute(const string& start, const vector<string>& dests) {
    cout << start;
    for(int i = 0; i < dests.size(); i++){
      cout << " -> " << dests[i];
    }
    cout << " -> " << start << endl;
}