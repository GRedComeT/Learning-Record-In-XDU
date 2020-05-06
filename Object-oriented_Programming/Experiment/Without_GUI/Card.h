#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Card {
    string Name;
    int Gender;
    int Kinds;
    string ID_Number;
    int Balance;
    string Institution;
    int takeTimes;
    friend void exitAndStoreCards();
public:
    Card();
    Card(string _Name, int _Gender, int _Kinds, string _ID_Number, string _Institution, int _takeTimes = 0, int _Balance = 0);
    void showBalance();
    void showAllInfo();
    void Topup(int Money);
    bool takeBus();
};
