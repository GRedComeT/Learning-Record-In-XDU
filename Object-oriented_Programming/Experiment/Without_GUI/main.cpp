#include "Card.h"
#include "Car.h"
#include "main.h"
using namespace std;

extern const string GenderMap[] = { "", "男", "女" };
extern const string KindsMap[] = { "", "学生卡", "教师卡", "家属卡" };
extern const string NumberNameMap[] = { "", "学号", "工资卡号", "卡号" };
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
    cout << "        班车注册界面" << endl;
    cout << "请输入班车车牌: ";
    cin >> Car_Number;
    cout << "请选择班车核载人数('1'为30人, '2'为50人): ";
    L2:
    cin >> Kind;
    if (Kind != 1 && Kind != 2) {
        cout << "您的输入不正确, 请重新输入核载人数('1'为30人, '2'为50人): ";
        goto L2;
    }
    cout << "请输入班车的型号: ";
    cin >> carType;
    cout << "请输入驾驶员的姓名: ";
    cin >> driverName;
    system("cls");
    cout << "恭喜您, 班车注册成功" << endl;
    Cars.emplace_back(Car_Number, carType, Kind, driverName);
    Cars.back().showInfo();
    cout << "等待跳转至主界面";
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
        cout << "还未有班车注册, 请先注册班车, 即将跳转上一级" << endl;
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
            cout << "当前已上车人数: " << nowsum << endl;
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
            cout << "当前已上车人数: " << nowsum << endl;
        }
    }
    timeClock++;
    cout << "输入0结束模拟: ";
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
    cout << "        " << "校园一卡通乘车系统" << endl;
    cout << "请选择需要的功能(输入对应的编号):" << endl;
    cout << "1.注册卡号        2.查询信息" << endl;
    cout << "3.充值金额        4.注销卡号" << endl;
    cout << "5.模拟发车        6.保存并退出" << endl;
    int indication;
    cin >> indication;
    return indication;
}

int SimuWindows() {
    cout << "        " << "乘车模拟系统" << endl;
    cout << "请选择需要的功能(输入对应的编号):" << endl;
    cout << "1.注册班车        2.开始模拟" << endl;
    cout << "3.保存并退出" << endl;
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
    cout << "        一卡通注册界面" << endl;
    cout << "请输入您的姓名: ";
    cin >> Name; 
    cout << "请选择您的性别('1'为男性, '2'为女性): ";
    L2:
    cin >> Gender;
    if (Gender != 1 && Gender != 2) {
        cout << "您的输入不正确, 请重新输入性别('1'为男性, '2'为女性): ";
        goto L2;
    }
    cout << "请输入您要办理卡的种类('1'为学生卡, '2'为教师卡, '3'为家属卡): ";
    L1:
    cin >> Kind;
    switch (Kind) {
    case 1:
        cout << "请输入您的学号: ";
        cin >> ID_Number;
        if (store.count(ID_Number)) {
            cout << "该卡号已经注册, 无法重复注册, 即将跳转至主界面" << endl;
            WaitToJump(3);
            return;
        }
        cout << "请输入您的学院: ";
        cin >> Institution;
        store[ID_Number] = Card(Name, Gender, Kind, ID_Number, Institution);
        break;
    case 2:
        cout << "请输入您的工资号: ";
        cin >> ID_Number;
        cout << "请输入您的学院: ";
        cin >> Institution;
        store[ID_Number] = Card(Name, Gender, Kind, ID_Number, Institution);
        break;
    case 3:
        ID_Number = getCognateNumber();
        store[ID_Number] = Card(Name, Gender, Kind, ID_Number, Institution, takeTimes);
        break;
    default:
        cout << "您的输入不正确, 请重新输入卡的种类('1'为学生卡, '2'为教师卡, '3'为家属卡): ";
        goto L1;
    }
    system("cls");
    cout << "恭喜您, 乘车卡注册成功" << endl;
    store[ID_Number].showAllInfo();
    cout << "等待跳转至主界面";
    WaitToJump(5);
}

void SearchInfo() {
    string Key;
    cout << "请输入您需要查询的卡号(学号\\工资卡号): ";
    L3:
    cin >> Key;
    if (Key[0] == 'q') return;
    if (store.count(Key) == 0) {
        cout << "您输入的卡号不存在, 请重新输入, 或键入q返回主菜单: ";
        goto L3;
    }
    store[Key].showAllInfo();
    cout << "键入q返回主菜单: ";
    while (cin >> Key && Key[0] != 'q');
}

void TopUp() {
    string Key;
    int Money;
    cout << "        一卡通充值界面" << endl;
    cout << "请输入您要充值的卡号(学号\\工资卡号): ";
    L3:
    cin >> Key;
    if (Key[0] == 'q') return;
    if (store.count(Key) == 0) {
        cout << "您输入的卡号不存在, 请重新输入, 或键入q返回主菜单: ";
        goto L3;
    }
    cout << "请输入您要充值的金额: ";
    cin >> Money;
    store[Key].Topup(Money);
    cout << "恭喜您, 充值成功.";
    store[Key].showBalance();
    cout << "键入q返回主菜单: ";
    while (cin >> Key && Key[0] != 'q');
}

void DeleteCard() {
    string Key;
    cout << "请输入您需要注销的卡号(学号\\工资卡号): ";
    L3:
    cin >> Key;
    if (Key[0] == 'q') return;
    if (store.count(Key) == 0) {
        cout << "您输入的卡号不存在, 请重新输入, 或键入q返回主菜单: ";
        goto L3;
    }
    store.erase(Key);
    cout << "注销成功" << endl;
    cout << "等待跳转至主界面";
    WaitToJump(5);
}

void WindowsErrorTrap() {
    cout << "输入错误, 请重新输入, 等待跳转" << endl;
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
