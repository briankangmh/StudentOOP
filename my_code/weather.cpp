//
//  weather.cpp
//  lecture3
//
//  Created by Brian Kango on 6/6/19.
//  Copyright © 2019 Brian Kang. All rights reserved.
//

#include <string>
#include <iostream>
#include "weather.h"

using namespace std;

Weather::Weather(string name, GPS loc) : name (name), location(loc){
}

ostream& operator << (ostream& os, const Weather& w){
    int r = w.get_rating();
    os << w.name << " : rating " << r <<
    " longitude: " << w.location.longitude <<
    " latitude: " << w.location.latitude << endl;
    os << "Weather rEadInGS:" << endl;
    for (WReading i : w.wreadings){
        os << i;
    }
    return os;
}

//ostream& operator << (ostream& os, const GPS& gps){
//    os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude << endl;
//    return os;
//}
int Weather::get_rating() const{
    return rating;
}
void Weather::set_rating(int new_rating){
    rating = new_rating;
}

string Weather::get_name() const{
    return name;
}

void Weather::add_reading(WReading wr){
    wreadings.push_back(wr);
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y){};

ostream& operator << (ostream& os, const Date& date){
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}

//WReading::WReading(date d, double t, double h, double ws) : day(d), month(m), year(y){};

ostream& operator << (ostream& os, const WReading& r){
    os << "Date: " << r.date << " Temperature: " << r.temperature << " Humidity: " << r.humidity << " Windspeed: " << r.windspeed << endl;
    return os;
}

Image:: Image(int w, int h, string flnm) : width(w), height(h), filename(flnm){}

int Image::image_sz(){
    return width*height;
}

Image:: Image(const Image& rhs){
    width = rhs.width;
    height = rhs.height;
    filename = rhs.filename;
    image_buf = new char[image_sz()];
    for (int i = 0; i < image_sz(); i++){
        image_buf[i] = rhs.image_buf[i];
    }
}

Image::~Image(){
    delete image_buf;
    image_buf = nullptr;
}

Image& Image ::operator=(const Image& rhs){
    if (this != &rhs)
        if (image_buf != nullptr){
            delete image_buf;
        }
        image_buf = nullptr;
        width = rhs.width;
        height = rhs.height;
        filename = rhs.filename;
        image_buf = new char[image_sz()];
        for (int i = 0; i < image_sz(); i++){
            image_buf[i] = rhs.image_buf[i];
        }
    return *this;
}

double WReading::get_tempF(){
    return ((temperature*9)/5) + 32;
}
