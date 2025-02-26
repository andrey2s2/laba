#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <map>
#include <algorithm>
#include <conio.h>

using namespace std;


int Na()
{
    float K;
    cout<<"Введите значение N"<<endl;
    cin>>K;
    cout<<endl;
    while((K<1)||(K>26)||(K!=(int)K))
    {
        cout<<"НЕВЕРНЫЙ ВВОД!"<<endl<<"Введите снова"<<endl;
        cin>>K;
    }
    return K;
}

 void zapolnenie(float k)
 {
     string str="a",str1="a";
    ofstream file("основной.txt");
    for(int i=0;i<k;i++)
    {
        file<<str1<<endl;
        str[0]++;
        str1=str1+str;
    }
    file.close();
 }
 void vivod(int n)
 {
     ifstream file("основной.txt");
     int i=1;
     string line;
     while(getline(file,line))
     {
         if(i==n)
         {
             cout<<line<<endl;
         }
         i++;
     }
     file.close();
 }

string simvol()
{
    string str;
    cout<<"введите букву для поиска"<<endl;

    getline(cin,str);

    while((str=="")||(str.length()>1))
    {
        cout<<"Введено неверно.Введите заново"<<endl;
        getline(cin,str);
    }
    return str;
}

int m1()
{
    int m;
    ifstream file("осн.txt");
    string line;
    while(getline(file,line))
    {
        m=m+line.length();
    }
    return m;
    file.close();
}

void poisksim(int s,string str11)
{
    ifstream file("основной.txt");
    int *str=new int [s];
    int *stl=new int [s];
    int x=0,z=0,t=0;
    string line;
    while(getline(file,line))
    {
        x++;
        z=1;
        for(int j=0; j<line.length(); j++)
        {
            if(line[j]==str11[0])
            {
                stl[t]=x;
                str[t]=z;
                t++;
            }
            z++;
        }
    }
    for(int j=0; j<t; j++)
    {
        cout<<"строка : "<<stl[j]<<endl;
        cout<<"номер позиции : "<<str[j]<<endl;
    }
    delete str;
    delete stl;
    file.close();
}

void kolslov()
{
    ifstream file("основной.txt");
    string unic[100];
    string line;
    int n=0;
    while(getline(file,line))
    {
        for(int i=0;i<line.length();i++)
        {
            string str;
            if((line[i]==' ')||(line[i]=='!')||(line[i]=='.')||(line[i]==',')||(i==(line.length()-1)))
            {
                int k=0;
                for(int j=0;j<=n;j++)
                {
                    if(str!=unic[j])
                    {
                        k++;
                    }
                }
                if(k==n)
                {
                    unic[n]=str;
                    n++;
                }
            }
            else
            {
                str=str+line[i];
            }
        }
    }
    cout<<"кол-во уникальных слов: "<<n<<endl;
    file.close();
}

int main()
{
    setlocale(0,"");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int x=0,k=0;
    float N;
    string str,s;
    N=Na();
    zapolnenie(N);
    cout<<"Введите номер строки которую надо вывести:"<<endl;
    cin>>k;
    while((k<1)&(k>N))
    {
        cout<<"НЕВЕРНЫЙ ВВОД!"<<endl<<"Введите снова"<<endl;
        cin>>k;
    }
    vivod(k);
    s=simvol();
    x=m1();
    poisksim(x,s);
    kolslov();
    return 0;
}
