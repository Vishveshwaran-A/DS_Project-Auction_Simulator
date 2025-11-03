#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;

string formatMoney(double x) 
{
    stringstream ss;
    ss << fixed << setprecision(2) << x;
    string s = ss.str();

    int pos = s.find('.');
    for (int i = pos - 3; i > 0; i -= 3) 
        s.insert(i, ",");
    
    return "$" + s;
}

void line_printer()
{
    cout<<"\n=====================================================\n";
}