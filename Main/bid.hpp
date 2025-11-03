#pragma once 
#include<iostream>
#include "format.hpp"
using namespace std;

class Bid
{
    double amount;
    int id;
    
    public:
    Bid()
    {
        amount=-1;
        id=-1;
    }
    Bid(int x,double y)
    {
        id=x;
        amount=y;
    }
    int getId()
    {
        return id;
    }
    double getAmount()
    {
        return amount;
    }
    
    friend ostream& operator<<(ostream& out, const Bid& obj) {
        
        if (&out == &cout) 
        {
            out << "ID: " << obj.id 
                << " | Amount: " << formatMoney(obj.amount);
                
        } else 
        
            out << obj.id << " " << obj.amount; 
        return out;
    }
    friend istream& operator>>(istream& in, Bid& obj) 
    {   
        if(&in==&cin)
        { 
           cout << "Enter ID Amount: "<<endl;
           in >> obj.id >> obj.amount;
        }
        else
           in >> obj.id >> obj.amount;
        return in;
    }  

};