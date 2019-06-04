//
//  basics.hpp
//  OOP assigments
//
//  Created by Brian Kango on 5/31/19.
//  Copyright © 2019 Brian Kang. All rights reserved.
//

#ifndef basics_hpp
#define basics_hpp

#include <string>
#include <vector>

struct coord {
    int x = 0;
    int y = 0;
};

void inc_pass_copy(int n);
void inc_pass_ref(int& n);
void fill_vector(std::vector<int>& v, int n);
void print_vector(const std::vector<int>& v);
void print_coords(coord pos);
int square(int n);
double square(double n);
int my_abs(int n);
int sum(int n);
int sum2(int n);
void pull_apart_string(std::string s);
void say(std::string s);


#endif /* basics_hpp */
