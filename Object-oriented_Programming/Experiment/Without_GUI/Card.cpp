#include "Card.h"

extern const string GenderMap[];
extern const string KindsMap[];
extern const string NumberNameMap[];


Card::Card() {
    Name = "", ID_Number = "", Institution = "", Gender = Kinds = Balance = takeTimes = 0;
}
Card::Card(string _Name, int _Gender, int _Kinds, string _ID_Number, string _Institution, int _takeTimes, int _Balance) :
    Name(_Name), Gender(_Gender), Kinds(_Kinds), ID_Number(_ID_Number), Institution(_Institution), takeTimes(_takeTimes),
    Balance(_Balance) {}
void Card::showBalance() {
    cout << "您当前的余额为: " << Balance << endl;
}
void Card::showAllInfo() {
    cout << "您的一卡通信息如下: " << endl;
    cout << "姓名: " << Name << "        ";
    cout << "性别: " << GenderMap[Gender] << endl;
    cout << "所属卡类别为: " << KindsMap[Kinds] << endl;
    cout << "您的" << NumberNameMap[Kinds] << "为: " << ID_Number << endl;
    if (Kinds != 3) cout << "您所属的学院为: " << Institution << endl;
    else cout << "您当前剩余的免费次数为: " << (takeTimes > 20 ? 0 : 20 - takeTimes) << endl;
    cout << "本月您已乘车" << takeTimes << "次" << endl;
    showBalance();
}
void Card::Topup(int Money) {
    Balance += Money;
}
bool Card::takeBus() {   // "true" can take bus.
    if (Kinds == 2) {
        takeTimes++;
        cout << "刷卡成功      " << "一卡通类别: 教师卡" << "        姓名: " << Name << "        本次乘车免费" << endl;
    }
    else if (Kinds == 1) {
        if (Balance < 2) {
            cout << "一卡通类别: 学生卡" << "        姓名: " << Name << " 您的余额不足, 无法上车, 请充值" << endl;
            return false;
        }
        Balance -= 2, takeTimes++;
        cout << "刷卡成功      " << "一卡通类别: 学生卡" << "        姓名: " << Name << "        余额: " << Balance << endl;
        if (Balance <= 5) {
            cout << "您的余额过低, 请注意及时充值" << endl;
        }
    }
    else {
        if (takeTimes < 20) {
            cout << "刷卡成功      " << "一卡通类别: 家属卡" << "        姓名: " << Name << "       本次免费, 本月已乘坐次数: " << takeTimes++;
            if (takeTimes == 20) cout << "  此次乘车为本月最后一次免费乘车";
            cout << endl;
        }
        else {
            if (Balance < 2) {
                cout << "一卡通类别: 家属卡" << "        姓名: " << Name << " 您的余额不足, 无法上车, 请充值" << endl;
                return false;
            }
            cout << "刷卡成功      " << "一卡通类别: 家属卡" << "        姓名: " << Name << "       免费额度已尽，开始收费, 余额: " << Balance << endl;
            if (Balance <= 5) {
                cout << "您的余额过低, 请注意及时充值" << endl;
            }
        }
    }
    return true;
}