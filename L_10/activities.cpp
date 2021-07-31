#include "activities.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compr(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

vector<Activity> get_max_activities(const vector<Activity>& activities) {

    if (activities.size() == 0 || activities.size() == 1) {
        return activities;
    }
    vector<Activity> result;

    vector<Activity> data = activities;

    sort(data.begin(), data.end(), compr);
    result.push_back(data[0]);
    
    int counter = 0;

    for (int i = 1; i < data.size(); i++) {
        if (result[counter].finish <= data[i].start) {
            result.push_back(data[i]);
            counter++;
        }
    }

    return result;
}

