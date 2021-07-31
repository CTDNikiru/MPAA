#define CATCH_CONFIG_RUNNER

#include "../catch.hpp"

#include "activities.h"
#include <iostream>
#include<math.h>
#include <cstdlib>
#include <ctime> 
using namespace std;



vector<Activity> get_max_activities_bruteforce(const std::vector<Activity>& activities) {

    

    if (activities.size() == 0 || activities.size() == 1) return activities; // если ничего нет - вернуть пустое множетсво или просто один процесс
    vector<vector<Activity>> result;
    vector<Activity> temp = activities;
    Activity k;
   

    bool find = false;
    for (int i = 0; i < temp.size() && !find; i++) {
        for (int j = i + 1; j < temp.size() && !find; j++) {
            if (temp[i].finish > temp[j].start || temp[j].finish > temp[i].start) {
                find = true;
            }
        }
    }

    if (find) {
        for (int i = 0; i < temp.size(); i++) {
            k = temp[i];
            temp.erase(temp.begin()+i);
            result.push_back(get_max_activities_bruteforce(temp));
            temp.insert(temp.begin() + i, k);
        }
    }
    else {
        return temp;
    }



    int index = 0;
    for (int i = 1; i < result.size(); i++) {
        if (result[index].size() < result[i].size())
            index = i;
    }



    return result[index];
}

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);

    Activity a;
    srand(time(NULL));
    int theFirst;
    int theSecond;
    vector <Activity> b;
    

    for (int n = 0; n < 7; n++) {
        int count = pow(10, n);
        b.clear();
        for (int i = 0; i < count; i++) {
            theFirst = rand();
            theSecond = rand();
            if (theFirst > theSecond) {
                a.finish = theFirst;
                a.start = theSecond;
            }
            else {
                a.start = theFirst;
                a.finish = theSecond;
            }
            b.push_back(a);
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        get_max_activities(b);
        auto t2 = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double>(t2 - t1).count();
        std::cout << "N: " << count << ", time: " << time << std::endl;
    }

    cout << "\nINEFFECTIVE ALGORITM\n";

    for (int n = 0; n < 2; n++) {
        int count = pow(10, n);
        b.clear();
        for (int i = 0; i < count; i++) {
            theFirst = rand();
            theSecond = rand();
            if (theFirst > theSecond) {
                a.finish = theFirst;
                a.start = theSecond;
            }
            else {
                a.start = theFirst;
                a.finish = theSecond;
            }
            b.push_back(a);
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        get_max_activities_bruteforce(b);
        auto t2 = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double>(t2 - t1).count();
        std::cout << "N: " << count << ", time: " << time << std::endl;
    }
}