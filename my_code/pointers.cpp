//
//  pointers.cpp
//  OOP assigments
//
//  Created by Brian Kango on 6/4/19.
//  Copyright © 2019 Brian Kang. All rights reserved.
//

#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
    n++;
}


void inc_with_pointer(int* iptr) {
//    (*iptr)+1;
    *iptr +=1;
}


void inc_with_reference(int& n) {
    n++;
}


Thing** create_array_of_things(int n) {
    Thing** array = new Thing*[n];
    for (int i = 0; i < n; i++){
        array[i] = new Thing(i);
    }
    return array;
}

void print_all_things(Thing** things, int n){
    for (int i = 0; i < n; i++){
        cout << things[i] -> val << " ";
    }
    cout <<endl;
}

void double_all_things(Thing** things, int n){
    for (int i = 0; i < n; i++){
        things[i]->val*=2;
    }
}

void delete_all_things(Thing** things, int n) {
    for (int i = 0; i < n; i++){
        delete things[i];
        things[i] = nullptr;
    }
    delete[] things;
    things = nullptr;
}


//void assignTA(Student& s, Student& ta) {
//}
//
//void printTAs(vector<Student> students) {
//}
