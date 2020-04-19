#ifndef ANY_NUM_PLUS_CPP
#define ANY_NUM_PLUS_CPP

#include <iostream>
#include <string>

//#define MAX_NUM_SIZE 1000

using namespace std;

class AnyPlus
{
    public:
        AnyPlus(string str); //构造函数
        AnyPlus(const AnyPlus &obj);
        ~AnyPlus(); //析构函数
        virtual AnyPlus operator+(const AnyPlus &obj); //重载、虚函数

        void setNum(string str)
        {
            strNum = str;
        }

        string getNum(void)
        {
            return strNum;
        }

        friend void print(AnyPlus &obj); //友元函数

    private:
        string strNum; //不要初始化
};

AnyPlus::AnyPlus(string str)//: strNum(str) //列表初始化
{
    cout << "调用构造函数..." << endl;
    strNum = str;
}

AnyPlus::AnyPlus(const AnyPlus &obj)
{
    cout << "调用拷贝构造函数..." << endl;
    strNum = obj.strNum; //这里拷贝构造对象的strNum与obj.strNum指向相同的数据地址
}

AnyPlus::~AnyPlus()
{
    cout << "调用析构函数..." << strNum << endl;
}

AnyPlus AnyPlus::operator+(const AnyPlus &obj) //虚函数只能出现在class内
{
    cout << "调用加法重载函数..." << strNum << endl;
    string sum;
    int strSize1(0), strSize2(0);
    int overFlow(0), i(0);
    strSize1 = this->strNum.size();
    strSize2 = obj.strNum.length(); //size或者length函数功能相同
    
    for(i=(strSize1<strSize2?strSize1:strSize2)-1; i>=0; i--)
    {
        int n1(0), n2(0);
        string s;
        n1 = int(this->strNum[i] - '0');
        n2 = int(obj.strNum[i]- '0');
        s = (n1 + n2 + overFlow) % 10 + '0';
        sum.insert(0, s);
        overFlow = (n1 + n2 + overFlow) / 10;
    }
    AnyPlus newObj(sum);
    
    return newObj;
}

void print(AnyPlus &obj)
{
    cout << "友元函数..." << obj.strNum << endl;
}

int main(int argc, char *argv[])
{
    AnyPlus num1("1234"), num2("5678"), numSum("0");
    numSum = num1 + num2;
    //cout << numSum.getNum() << endl;
    print(numSum);
    return 0;
}

#endif
