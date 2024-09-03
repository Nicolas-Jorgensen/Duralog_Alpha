// Include necessary headers for file handling, data structures, etc.
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <array>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iterator>
using namespace std;
using namespace chrono;

const int THIRDSOFMIN = 50, LAYERS = 5; 
 
void printFire(const map<pair<int,int>, array<list<int>, 3>> &fireGrid, int timeAt) {
    string flame;
    int fireNum = 0, spaces = 7;
    int clear = system("clear");
    for(auto tile : fireGrid) {
    
        auto it = tile.second[0].begin();
        
        advance(it,timeAt);
            if(fireNum == 0 || fireNum == 1 || fireNum == 3 || fireNum == 6
            || fireNum == 10) {
                 if(fireNum != 0)
                    cout << endl;
                cout << setw(spaces-- + rand() % 2) << "";
            }
            //fire will print differnt chars depending on int
            if(*it > 90)
                flame = "( ";
            else if(*it >60)
                flame = ") ";
            else if(*it > 30)
                flame = "* ";
            else
                flame = "[]";
            cout << flame;
            fireNum++;
    }
    clear++; //use 
    cout << endl;
   cout << " _ -./_/ \\\\--._ " << endl;
    cout << "(_;-/ | \\ \\-'.\\" << endl;
    cout << "( `.__ _  ___,')" << endl;
    cout << " `'(_ )_)(_)_)'" << endl;
}
void calcTemp(map<pair<int,int>, array<list<int>, 3>> &fireGrid, int totalTime) {
    int currentTime = totalTime;
    while(currentTime > 0) {
        for(auto &tile : fireGrid) {
            auto temp = tile.second[0].begin();
            auto o2 = tile.second[1].begin();
            auto carb = tile.second[2].begin();
            advance(temp,(totalTime - currentTime));
            advance(o2, (totalTime - currentTime));
            advance(carb, (totalTime - currentTime));
            *temp = *o2 + *carb;  
        }
        currentTime--;
    }
}
// Define a function to avg O2 levels across the fire
    // Parameters: map of fire tiles, current timestep

// Define a function to calculate higher tile's C levels based on
//  unfired C from lower tiles
    // Parameters: map of fire tiles, current timestep

/*void unburntCarb(map<pair<int,int>, array<list<int>, 3>> &fireGrid, int maxLayers,
                    int totalTime) {
    int leftoverLow = 0, leftoverHigh = 0, currentTime = totalTime;
    while(currentTime > 0) {
        for (int height = 0; height < maxLayers; height++) { 
            for(int row = 0; row <= height; row++) {
                auto it = fireGrid[{height,row}][2].begin();
                advance(it, (totalTime - currentTime));
                leftoverLow += *it;
            }
            if(height != maxLayers - 1) {
                for(int row = 0; row <= height; row++) {
                    auto it = fireGrid[{height + 1,row}][2].begin();
                    advance(it, (totalTime - currentTime));
                    leftoverHigh += *it;
                }
            }
            for(int row = 0; row <= height; row++) {
                auto it = fireGrid[{height+1,row}][2].begin();
                advance(it, (totalTime - currentTime));
                *it += leftoverLow;
            }
            
        }
        currentTime--;
    }
} */
int main() {
    map<pair<int,int>, array<list<int>, 3>> fire;
    int num; //t = 0; //time
 
    for (int height = 0; height < LAYERS; height++) { //filling temperature of map with 0
        for(int row = 0; row <= height; row++) {
            array<list<int>, 3> empties = {
                list<int>(THIRDSOFMIN, 0) //filling list with 0
            };
            fire[{height,row}] = empties;
        }
    }
    
    //fstream fin("O2 and C.txt");
    fstream fin("O2 and C.txt");
    if(!fin.good()) {
        cerr << "Could not open oxy and carbon level file.";
        fin.close();
        return 1;
    }
    for(int i = 0; i < THIRDSOFMIN; i++) {
        for(auto &tile : fire) {
            auto &levels = tile.second;
            fin >> num;
            levels[1].push_back(num);
            fin >> num;
            levels[2].push_back(num);
        }
    }
    fin.close();
    calcTemp(fire,THIRDSOFMIN);
    for(int i = 0; i < THIRDSOFMIN; i++) {
        printFire(fire, i);
        this_thread::sleep_for(milliseconds(100));
    } 
    // Open an external file to read data for O2 and CO2 levels
        // If file does not open, print an error and exit

    // Read data from file and populate map
        // First extract O2 data
        // then extract CO2 data
        // Insert O2 and CO2 levels into appropriate lists in the map's value array
    // Close the file

    //Print fancy Header

    // Begin a time-based simulation for DuraLog Fire
        // For 100 time intervals
            // Call function to avg O2 across fire
            // Call function to calc each tile's CO2
            // Call function to calculate temp
            //call function to print all fire tiles
            // advance Timestep
    //Continue loop              
    return 0;
}
