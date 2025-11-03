#pragma once 
#include <iostream>
#include <string>
#include<iomanip>
#include "format.hpp"
using namespace std;

class Institute {
    string name;
    double aid;

public:
   
    Institute(string n="", int a=0)
    {
        name=n;
        aid=a;
    }

    double getAid()
    {
        return aid;
    }

    string getName()
    {
        return name;
    }

    bool operator<(const Institute& other) const   
    {
        return aid < other.aid;
    }

    
    bool operator>(const Institute& other) const  
    {
        return aid > other.aid;
    }

    
    Institute& operator+=(const Institute& other) 
    {
        aid += other.aid;
        return *this;
    }

    
    Institute& operator-=(const Institute& other) 
    {
        aid -= other.aid;
        return *this;
    }

    Institute& operator+=(double x) 
    {
        aid += x;
        return *this;
    }
    Institute& operator-=(double x) 
    {
        aid -= x;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Institute& obj)   
    {
        if (&out == &cout) 
        {  
            out << left<<setw(20)<<obj.name
                << "| Aid Required: " << formatMoney(obj.aid);
        } else { 
            out << obj.name << " " << obj.aid;
        }
        return out;
    }


    friend istream& operator>>(istream& in, Institute& obj) 
    {
        if (&in == &cin) { 
            cout << "Enter Institute Name and Aid Required: ";
            in >> obj.name >> obj.aid;
        } else {  
            in >> obj.name >> obj.aid;
        }
        return in;
    }
};
