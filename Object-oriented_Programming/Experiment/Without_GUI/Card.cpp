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
    cout << "����ǰ�����Ϊ: " << Balance << endl;
}
void Card::showAllInfo() {
    cout << "����һ��ͨ��Ϣ����: " << endl;
    cout << "����: " << Name << "        ";
    cout << "�Ա�: " << GenderMap[Gender] << endl;
    cout << "���������Ϊ: " << KindsMap[Kinds] << endl;
    cout << "����" << NumberNameMap[Kinds] << "Ϊ: " << ID_Number << endl;
    if (Kinds != 3) cout << "��������ѧԺΪ: " << Institution << endl;
    else cout << "����ǰʣ�����Ѵ���Ϊ: " << (takeTimes > 20 ? 0 : 20 - takeTimes) << endl;
    cout << "�������ѳ˳�" << takeTimes << "��" << endl;
    showBalance();
}
void Card::Topup(int Money) {
    Balance += Money;
}
bool Card::takeBus() {   // "true" can take bus.
    if (Kinds == 2) {
        takeTimes++;
        cout << "ˢ���ɹ�      " << "һ��ͨ���: ��ʦ��" << "        ����: " << Name << "        ���γ˳����" << endl;
    }
    else if (Kinds == 1) {
        if (Balance < 2) {
            cout << "һ��ͨ���: ѧ����" << "        ����: " << Name << " ��������, �޷��ϳ�, ���ֵ" << endl;
            return false;
        }
        Balance -= 2, takeTimes++;
        cout << "ˢ���ɹ�      " << "һ��ͨ���: ѧ����" << "        ����: " << Name << "        ���: " << Balance << endl;
        if (Balance <= 5) {
            cout << "����������, ��ע�⼰ʱ��ֵ" << endl;
        }
    }
    else {
        if (takeTimes < 20) {
            cout << "ˢ���ɹ�      " << "һ��ͨ���: ������" << "        ����: " << Name << "       �������, �����ѳ�������: " << takeTimes++;
            if (takeTimes == 20) cout << "  �˴γ˳�Ϊ�������һ����ѳ˳�";
            cout << endl;
        }
        else {
            if (Balance < 2) {
                cout << "һ��ͨ���: ������" << "        ����: " << Name << " ��������, �޷��ϳ�, ���ֵ" << endl;
                return false;
            }
            cout << "ˢ���ɹ�      " << "һ��ͨ���: ������" << "        ����: " << Name << "       ��Ѷ���Ѿ�����ʼ�շ�, ���: " << Balance << endl;
            if (Balance <= 5) {
                cout << "����������, ��ע�⼰ʱ��ֵ" << endl;
            }
        }
    }
    return true;
}