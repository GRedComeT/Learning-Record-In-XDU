#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Car {
    string Car_Number;
    string carType;
    int Kinds;
    string driverName;
    friend void exitAndStoreCars();
public:
    Car();
    Car(string _Car_Number, string _carType, int _Kinds, string _driverName);
    void showInfo(int StartTime = -1);
    int getMemberNumber();
};