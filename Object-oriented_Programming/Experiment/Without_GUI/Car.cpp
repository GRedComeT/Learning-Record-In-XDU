#include "Car.h"

extern const int carKindsMap[];
extern const int Clocks[];

Car::Car() {
    Car_Number = "", carType = "", driverName = "", Kinds = 0;
}
Car::Car(string _Car_Number, string _carType, int _Kinds, string _driverName) :Car_Number(_Car_Number), carType(_carType),
    Kinds(_Kinds), driverName(_driverName) {}
void Car::showInfo(int StartTime) {
    cout << "�೵��Ϣ: " << endl;
    cout << "���ƺ�: " << Car_Number << "        �ͺ�: " << carType << endl;
    cout << "��������: " << carKindsMap[Kinds] << "        ˾������: " << driverName << endl;
    if (StartTime != -1) cout << "����ʱ��: " << Clocks[StartTime] << ":00" << endl;
}
int Car::getMemberNumber() {
    return carKindsMap[Kinds];
}