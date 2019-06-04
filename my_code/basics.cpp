//
//  basics.cpp
//  OOP assigments
//
//  Created by Brian Kango on 5/31/19.
//  Copyright © 2019 Brian Kang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;

/*
 * increment arg passed by copy
 * */
void inc_pass_copy(int j) {
    j++;
}

/*
 * increment arg passed by reference
 * */
void inc_pass_ref(int& j) {
    j++;
}

/*
 * Fill a vector with n elements from 1 to n.
 * 1st item == 1, 2nd item == 2, etc.
 * 0 filled for you.
 * Use `push_back()` to fill the vector.
 * */
void fill_vector(vector<int>& v, int n) {
    for (int i = 1; i <=n; i++){
        v.push_back(i);
    }
}

/*
 * Print all elements in a vector. Use a ranged for!
 * */
void print_vector(const vector<int>& v) {
    for (int i = 0; i <= v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

/*
 * Print a pair of coordinates.
 * */
void print_coords(coord pos) {
    cout << "x: " << pos.x << " y: " << pos.y << endl;
}

/*
 * Square an integer.
 * */
int square(int n) {
    return n*n;
}

/*
 * Square a double.
 * */
double square(double d) {
    return d * d;
}

/*
 * Get the absolute value of a number.
 * */
int my_abs(int n) {
    if (n < 0){
        return -n;
    }
    else{
        return n;
    }
}

/*
 * Sum from 0 to n using a `while` loop.
 * */
int sum(int n) {
    int result = 0;
    int i = 0;
    while (i <n){
        result += i;
        //cout << i << " ";
        i++;
    }
  //  cout << result << endl;
    return result;
}

/*
 * Sum from 0 to n using a `for` loop.
 * */
int sum2(int n) {
    int result = 0;
    for (int i = 1; i < n; i++){
        result += i;
    }
    return result;
}

/*
 * say() is built for you!
 * */
void say(std::string s) {
    cout << s << endl;
}


/*
 * Use a ranged for to pull a string apart into its bits.
 * */
void pull_apart_string(std::string s) {
    //cout << "got here ";
    for (char c : s){
        //cout << "got here ";
        cout << c << " ";
    }
    cout << endl;
}

