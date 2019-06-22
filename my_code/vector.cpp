#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    cout << endl;
}


MyVec::MyVec() : sz(0), capacity(DEF_CAPACITY), data(new int[DEF_CAPACITY]){}

MyVec::MyVec(const MyVec& v2) {
    sz = v2.sz;
    capacity = v2.capacity;
    data = new int[capacity];
    for (int i = 0; i < sz; i++){
        data[i] = v2[i];
    }
}

MyVec::~MyVec() {
    //delete array
    //delete all elements from array
    //delete actual array
    delete[] data;
    data = nullptr;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    //assignment operator
    //delete my own data, replace with new data
    if (&v2 != this){
        delete []data;
        data = new int[v2.capacity];
        for (int i = 0; i < v2.sz; i++){
            data[i] = v2[i];
        }
    }
    return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
    //if data are the same?
    if (v1.size() == v2.size()){
        for (int i = 0; i < v1.size(); i++){
            if (v1[i] != v2[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
    //if new size exceeds capacity, make new array with double capacity
    if (sz == capacity){
        int* old = new int[capacity];// create a new vector to store previous array
        for (int i = 0; i < capacity; i++){
            old[i] = data[i];
        }
        for (int i = 0; i < capacity; i++){
            if (old[i] != data[i]){
                cout << "uh oh..." << endl;
            }
        }
        capacity*=2;
        //delete [] data;
        data = new int[capacity];
        for (int i = 0; i < sz; i++){//copy over everything from old to current array
            data[i] = old[i];
        }
        data[sz] = val;
        sz++;
    }
    else{
        data[sz] = val;
        sz++;
    }
    cout << "Val to push: " << val << " Added val: " << data[sz] << " sz: " << sz << endl;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
    return data[i];
}
