#pragma once 
#include<iostream>
#include<iomanip>
#include "format.hpp"
using namespace std;

class Member
{   
    int id;
    string name;
    double donation;
    
    

    public:
    
    Member()
    {
        donation=0;
        id=-999;
        name="!!!!!";
    }

    int getID(){
        return id;
    }

    bool operator==(int x)
    {
        return id == x;
    }

    bool operator>(Member& other)
    {
        return donation > other.donation;
    }
    
    void update_donation(double x)
    {
        donation+=x;
    }
    friend ostream& operator<<(ostream& out, const Member& obj) {
        
        if (&out == &cout) 
        {   
            
            out << "ID: " << obj.id 
                << " | Name: " << left<<setw(10)<<obj.name 
                << " | Total Donation: " << formatMoney(obj.donation);

           
                
        } else 
        
            out << obj.id << " " << obj.name << " " << obj.donation<<" ";

        
        return out;
    }
    friend istream& operator>>(istream& in, Member& obj) 
    {   
        if(&in==&cin)
        { 
           cout << "Enter ID and Name: "<<endl;
           in >> obj.id >> obj.name;
        }
        else
           in >> obj.id >> obj.name >> obj.donation;
        return in;
    }

};
    

