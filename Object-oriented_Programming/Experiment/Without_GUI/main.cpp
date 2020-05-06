#include<iostream>
#include<fstream>
#include<json/json.h>
#include<time.h>
#include<cstdlib>
#include<algorithm>
#include<unordered_set>
#include "Card.h"
#include "Car.h"
#include "main.h"
using namespace std;

extern const string GenderMap[] = { "", "��", "Ů" };
extern const string KindsMap[] = { "", "ѧ����", "��ʦ��", "������" };
extern const string NumberNameMap[] = { "", "ѧ��", "���ʿ���", "����" };
extern const int carKindsMap[] = { 0, 30, 50 };
extern const int Clocks[] = { 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };

map<string, Card> store;
vector<string> memberStore;
vector<Car> Cars;

// Work for simulate
void preworkForCard() {
    memberStore.clear();
    for (auto i : store)
        memberStore.push_back(i.first);
}

void InitializeCars() {
    ifstream in;
    JSONCPP_STRING errs;
    in.open("Cars.json", ios::in);
    if (!in) return;
    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::parseFromStream(builder, in, &root, &errs);
    in.close();
    for (int i = 0; i < root["cars"].size(); ++i) {
        auto now = root["cars"][i];
        Cars.emplace_back(now["Car_Number"].asString(), now["carType"].asString(), now["Kinds"].asInt(),
            now["driverName"].asString());
    }
}

void exitAndStoreCars() {
    ofstream out;
    out.open("Cars.json", ios::out);
    Json::Value root;
    Json::Value car;
    Json::Value cars;
    Json::StreamWriterBuilder builder;
    for (auto i : Cars) {
        car["Car_Number"] = i.Car_Number;
        car["carType"] = i.carType;
        car["Kinds"] = i.Kinds;
        car["driverName"] = i.driverName;
        root.append(car);
    }
    cars["cars"] = Json::Value(root);
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(cars, &out);
}

void createCar() {
    string Car_Number;
    int Kind;
    string carType;
    string driverName;
    cout << "        �೵ע�����" << endl;
    cout << "������೵����: ";
    cin >> Car_Number;
    cout << "��ѡ��೵��������('1'Ϊ30��, '2'Ϊ50��): ";
    L2:
    cin >> Kind;
    if (Kind != 1 && Kind != 2) {
        cout << "�������벻��ȷ, �����������������('1'Ϊ30��, '2'Ϊ50��): ";
        goto L2;
    }
    cout << "������೵���ͺ�: ";
    cin >> carType;
    cout << "�������ʻԱ������: ";
    cin >> driverName;
    system("cls");
    cout << "��ϲ��, �೵ע��ɹ�" << endl;
    Cars.emplace_back(Car_Number, carType, Kind, driverName);
    Cars.back().showInfo();
    cout << "�ȴ���ת��������";
    WaitToJump(5);
}

void simulateMain() {
    srand((unsigned int)time(NULL));
    static int timeClock = 0;
    int car1 = 0, car2 = 0;
    if (Cars.size() > 1) {
        car1 = rand() % Cars.size();
        do {
            car2 = rand() % Cars.size();
        } while (car1 == car2);
    }
    if (Cars.size() == 0) {
        cout << "��δ�а೵ע��, ����ע��೵, ������ת��һ��" << endl;
        WaitToJump(2);
        return;
    }
    int car1Num = min(rand() % Cars[car1].getMemberNumber() + 1, (int)memberStore.size());
    int car2Num = car1 == car2 ? 0 : (rand() % Cars[car2].getMemberNumber() + 1);
    if (car1Num == (int)memberStore.size()) car2Num = 0;
    int Num = car1Num + car2Num;
    unordered_set<int> Members;
    while (Members.size() != Num) {
        Members.insert(rand() % (int)memberStore.size());
    }
    auto i = Members.begin();
    if (car1Num) {
        Cars[car1].showInfo(timeClock % 9);
        int nowsum = 0;
        for (int j = 0; j < car1Num; ++j, ++i) {
            if (store[memberStore[*i]].takeBus()) {
                nowsum++;
            }
            cout << "��ǰ���ϳ�����: " << nowsum << endl;
        }
    }
    cout << "\n\n" << endl;
    if (car2Num) {
        Cars[car2].showInfo(timeClock % 9);
        int nowsum = 0;
        for (int j = 0; j < car2Num; ++j, ++i) {
            
            if (store[memberStore[*i]].takeBus()) {
                nowsum++;
            }
            cout << "��ǰ���ϳ�����: " << nowsum << endl;
        }
    }
    timeClock++;
    cout << "����0����ģ��: ";
    cin >> car1;
    if (!car1) return;
}

void simulateCar() {
    InitializeCars();
    while (true) {
        system("cls");
        switch (SimuWindows()) {
        case 1:
            system("cls");
            createCar();
            break;

        case 2:
            system("cls");
            preworkForCard();
            simulateMain();
            break;
        case 3:
            system("cls");
            exitAndStoreCars();
            return;
        default:
            system("cls");
            WindowsErrorTrap();
            break;
        }

    }
}

// Work for store Cards 
void InitializeCards() {
    ifstream in;
    JSONCPP_STRING errs;
    in.open("Cards.json", ios::in);
    if (!in) return;
    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::parseFromStream(builder, in, &root, &errs);
    in.close();
    for (int i = 0; i < root["cards"].size(); ++i) {
        auto now = root["cards"][i];
        store[now["ID_Number"].asString()] = Card(now["Name"].asString(), now["Gender"].asInt(), now["Kinds"].asInt(),
            now["ID_Number"].asString(), now["Institution"].asString(), now["takeTimes"].asInt(), now["Balance"].asInt());
    }
}

void exitAndStoreCards() {
    ofstream out;
    out.open("Cards.json", ios::out);
    Json::Value root;
    Json::Value card;
    Json::Value cards;
    Json::StreamWriterBuilder builder;
    for (auto i : store) {
        auto j = i.second;
        card["Name"] = j.Name;
        card["Gender"] = j.Gender;
        card["Kinds"] = j.Kinds;
        card["ID_Number"] = j.ID_Number;
        card["Institution"] = j.Institution;
        card["Balance"] = j.Balance;
        card["takeTimes"] = j.takeTimes;
        root.append(card);
    }
    cards["cards"] = Json::Value(root);
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(cards, &out);
}

void WaitToJump(int interval) {
    time_t time1, time2;
    time(&time1);
    do {
        time(&time2);
    } while (time2 - time1 < interval);
}

string getCognateNumber() {
    ifstream in;
    ofstream out;
    in.open("CognateNumber.dat", ios::in);
    long long Number;
    in >> Number;
    in.close();
    string returnNumber = to_string(Number++);
    out.open("CognateNumber.dat", ios::out);
    out << Number << endl;
    out.close();
    return returnNumber;
}

int MainWindows() {
    cout << "        " << "У԰һ��ͨ�˳�ϵͳ" << endl;
    cout << "��ѡ����Ҫ�Ĺ���(�����Ӧ�ı��):" << endl;
    cout << "1.ע�Ῠ��        2.��ѯ��Ϣ" << endl;
    cout << "3.��ֵ���        4.ע������" << endl;
    cout << "5.ģ�ⷢ��        6.���沢�˳�" << endl;
    int indication;
    cin >> indication;
    return indication;
}

int SimuWindows() {
    cout << "        " << "�˳�ģ��ϵͳ" << endl;
    cout << "��ѡ����Ҫ�Ĺ���(�����Ӧ�ı��):" << endl;
    cout << "1.ע��೵        2.��ʼģ��" << endl;
    cout << "3.���沢�˳�" << endl;
    int indication;
    cin >> indication;
    return indication;
}

void RegisterCard() {
    string Name;
    int Kind;
    int Gender;
    int takeTimes = 0;
    
    string ID_Number;
    string Institution = "";
    cout << "        һ��ͨע�����" << endl;
    cout << "��������������: ";
    cin >> Name; 
    cout << "��ѡ�������Ա�('1'Ϊ����, '2'ΪŮ��): ";
    L2:
    cin >> Gender;
    if (Gender != 1 && Gender != 2) {
        cout << "�������벻��ȷ, �����������Ա�('1'Ϊ����, '2'ΪŮ��): ";
        goto L2;
    }
    cout << "��������Ҫ����������('1'Ϊѧ����, '2'Ϊ��ʦ��, '3'Ϊ������): ";
    L1:
    cin >> Kind;
    switch (Kind) {
    case 1:
        cout << "����������ѧ��: ";
        cin >> ID_Number;
        if (store.count(ID_Number)) {
            cout << "�ÿ����Ѿ�ע��, �޷��ظ�ע��, ������ת��������" << endl;
            WaitToJump(3);
            return;
        }
        cout << "����������ѧԺ: ";
        cin >> Institution;
        store[ID_Number] = Card(Name, Gender, Kind, ID_Number, Institution);
        break;
    case 2:
        cout << "���������Ĺ��ʺ�: ";
        cin >> ID_Number;
        cout << "����������ѧԺ: ";
        cin >> Institution;
        store[ID_Number] = Card(Name, Gender, Kind, ID_Number, Institution);
        break;
    case 3:
        ID_Number = getCognateNumber();
        store[ID_Number] = Card(Name, Gender, Kind, ID_Number, Institution, takeTimes);
        break;
    default:
        cout << "�������벻��ȷ, ���������뿨������('1'Ϊѧ����, '2'Ϊ��ʦ��, '3'Ϊ������): ";
        goto L1;
    }
    system("cls");
    cout << "��ϲ��, �˳���ע��ɹ�" << endl;
    store[ID_Number].showAllInfo();
    cout << "�ȴ���ת��������";
    WaitToJump(5);
}

void SearchInfo() {
    string Key;
    cout << "����������Ҫ��ѯ�Ŀ���(ѧ��\\���ʿ���): ";
    L3:
    cin >> Key;
    if (Key[0] == 'q') return;
    if (store.count(Key) == 0) {
        cout << "������Ŀ��Ų�����, ����������, �����q�������˵�: ";
        goto L3;
    }
    store[Key].showAllInfo();
    cout << "����q�������˵�: ";
    while (cin >> Key && Key[0] != 'q');
}

void TopUp() {
    string Key;
    int Money;
    cout << "        һ��ͨ��ֵ����" << endl;
    cout << "��������Ҫ��ֵ�Ŀ���(ѧ��\\���ʿ���): ";
    L3:
    cin >> Key;
    if (Key[0] == 'q') return;
    if (store.count(Key) == 0) {
        cout << "������Ŀ��Ų�����, ����������, �����q�������˵�: ";
        goto L3;
    }
    cout << "��������Ҫ��ֵ�Ľ��: ";
    cin >> Money;
    store[Key].Topup(Money);
    cout << "��ϲ��, ��ֵ�ɹ�.";
    store[Key].showBalance();
    cout << "����q�������˵�: ";
    while (cin >> Key && Key[0] != 'q');
}

void DeleteCard() {
    string Key;
    cout << "����������Ҫע���Ŀ���(ѧ��\\���ʿ���): ";
    L3:
    cin >> Key;
    if (Key[0] == 'q') return;
    if (store.count(Key) == 0) {
        cout << "������Ŀ��Ų�����, ����������, �����q�������˵�: ";
        goto L3;
    }
    store.erase(Key);
    cout << "ע���ɹ�" << endl;
    cout << "�ȴ���ת��������";
    WaitToJump(5);
}

void WindowsErrorTrap() {
    cout << "�������, ����������, �ȴ���ת" << endl;
    WaitToJump(3);
}

int main() {
    InitializeCards();
    while (true) {
        system("cls");
        switch (MainWindows()) {
        case 1:
            system("cls");
            RegisterCard();
            break;
        case 2:
            system("cls");
            SearchInfo();
            break;
        case 3:
            system("cls");
            TopUp();
            break;
        case 4:
            system("cls");
            DeleteCard();
            break;
        case 5:
            system("cls");
            simulateCar();
            break;
        case 6:
            system("cls");
            exitAndStoreCards();
            exitAndStoreCars();
            return 0;
        default:
            system("cls");
            WindowsErrorTrap();
            break;
        }
    }
    return 0;
}