#ifndef _GENERATE_RANDOM_ARRAY_HPP_
#define _GENERATE_RANDOM_ARRAY_HPP_

#include <ros/ros.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define MAX_N 10000
#define MIN_N 10
/**
 * @param arr array to be filled randomly
 * @returns {void}
 * */
void generate_random_array(std::vector<int> &arr){
    static bool isSeeded = false;
    if(!isSeeded){
        isSeeded = true;
        srand(time(NULL));
    }
    int n = std::max(MIN_N, rand()%MAX_N);
    for(int i = 0; i<n; i++){
        arr.push_back(i);
    }
    for(int i = 0; i<n; i++){
        int j = rand() % n;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

#endif