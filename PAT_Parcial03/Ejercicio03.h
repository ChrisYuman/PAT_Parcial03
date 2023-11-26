#ifndef TIMEMAP_H
#define TIMEMAP_H

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class TimeMap
{
private:
    struct Pair {
        int timestamp;
        string value;
    };

    unordered_map<string, vector<Pair>> map;

public:
    TimeMap();

    void set(string key, string value, int timestamp);

    string get(string key, int timestamp);

    ~TimeMap();
};

#endif // TIMEMAP_H