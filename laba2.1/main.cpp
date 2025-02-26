#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <map>
#include <ctime>
#include <algorithm>

using namespace std;

int zapolnenie(int s)
{
    ofstream file("основное.txt");
    int i=0;
    s=0;
    string str;
    cout<<"введите текст оканчивающийся точкой"<<endl;
    while(i==0)
    {
        getline(cin,str);
        if (str.find('.') != str.npos)
        {
            str.erase(str.find_first_of('.'));
            i++;
        }
        if((i!=1)&&(str!=""))
            file<<str<<endl;
        s++;
    }
    return s;
    file.close();
}

void dopolnenie(int obrez)
{
    ifstream file("основное.txt");
    ofstream fil("1 доп задание.txt");
    string line;
    int n;
    char ch='*';
    while(getline(file,line))
    {
        if(line.length()>obrez)
        {
            line.erase(obrez);
        }
        else
        {
            line.push_back(ch);
        }
        fil<<line<<endl;
    }
    file.close();
    fil.close();
}

void perestanovka()
{
    ifstream file("1 доп задание.txt");
    ofstream fil("основное.txt");
    string line;
    while(getline(file,line))
    {
        fil<<line<<endl;
    }
    file.close();
    fil.close();
}

void chisla()
{
    ofstream file("1 доп задание.txt");
    ifstream fil("основное.txt");
    string line;
    int n;
    while(getline(fil,line))
    {
        n=rand()%200-100;
        file<<line<<n<<endl;
    }
    file.close();
    fil.close();
}

void podschet(int obrez)
{
    ifstream fil("1 доп задание.txt");
    string line,str;
    int n,k;
    k=0;
    while(getline(fil,line))
    {
        str="";
        for(int j=0; j<line.length(); j++)
        {
            if(j>=obrez)
            {

                if((line[j]>='0')&&(line[j]<='9')||(line[j]=='-'))
                {
                    str=str+line[j];
                }
            }
        }
        n=stoi(str);
        if(n<0)
            k++;
    }
    cout<<"Количество отрицательных чисел : "<<k<<endl;
    fil.close();
}

void bukva(int z)
{
    ifstream fil("основное.txt");
    ofstream file("2 доп задание.txt");
    string line,str,s;
    int i,t,n;
    cout<<"Введите символ который нужно вставить"<<endl;
    cin>>str;
    i=0;
    while(i==0)
    {
        if((((str>="a")&&(str<="z"))||((str>="а")&&(str<="я"))||((str>="А")&&(str<="Я"))||((str>="A")&&(str<="Z")))&&(str.length()==1))
        {
            break;
        }
        cout<<"неверный ввод!"<<endl;
        cout<<"Введите символ который нужно вставить"<<endl;
        getline(cin,str);
    }
    t=0;
    n=rand()%(z-1)+1;
    z=0;
    while(getline(fil,line))
    {
        i++;
        if(i==n)
        {
            z=line.length();
            t=rand()%z+0;
            line.insert(t-1,str);
        }
        file<<line<<endl;
    }
    cout<<"строка "<<n<<endl;
    cout<<"место "<<t<<endl;
    if(t==0)
        cout<<"таких символов нет."<<endl;
    file.close();
    fil.close();
}

int main()
{
    setlocale(0,"");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int k=0,a=0,dlin;
    a=zapolnenie(k);
    cout<<"Введите максимальную длину строки:";
    cin>>dlin;
    dopolnenie(dlin);
    perestanovka();
    chisla();
    podschet(dlin);
    bukva(a);
    return 0;
}
