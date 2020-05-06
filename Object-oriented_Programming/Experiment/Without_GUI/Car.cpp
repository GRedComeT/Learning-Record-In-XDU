#include "Car.h"

extern const int carKindsMap[];
extern const int Clocks[];

Car::Car() {
    Car_Number = "", carType = "", driverName = "", Kinds = 0;
}
Car::Car(string _Car_Number, string _carType, int _Kinds, string _driverName) :Car_Number(_Car_Number), carType(_carType),
    Kinds(_Kinds), driverName(_driverName) {}
void Car::showInfo(int StartTime) {
    cout << "班车信息: " << endl;
    cout << "车牌号: " << Car_Number << "        型号: " << carType << endl;
    cout << "核载人数: " << carKindsMap[Kinds] << "        司机姓名: " << driverName << endl;
    if (StartTime != -1) cout << "发车时间: " << Clocks[StartTime] << ":00" << endl;
}
int Car::getMemberNumber() {
    return carKindsMap[Kinds];
}