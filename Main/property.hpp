#pragma once 
#include<iostream>
#include "format.hpp"
using namespace std;

class Property
{ 
    int id;
    string name;
    double start;
    double price;
    int owner;

    public:
    Property()
    {
        price=-1;
        owner=-1;
    }
    void update_price(double z)
    {
        price=z;
    }
    void update_owner(int z)
    {
        owner=z;
    }
    double getStart()
    {
        return start;
    }
    
    friend ostream& operator<<(ostream& out, const Property& obj) {
        
        if (&out == &cout) 
        {   if(obj.price==-1)
            {   
                out << "ID: " << obj.id 
                << " | Name: " << left<<setw(10)<<obj.name 
                << " | Start: " << formatMoney(obj.start);

            }
            else
            {

                out << "ID: " << obj.id 
                << " | Name: " << setw(10)<<obj.name 
                << " | Start: " << left<<setw(15)<<formatMoney(obj.start)
                << " | Owner Id: "<<obj.owner
                << " | Final Price: " <<formatMoney(obj.price);
            }
                
        } else 
        
            out << obj.id << " " << obj.name << " " << obj.start<<" "<< obj.owner << " " << obj.price;
        
        return out;
    }
    friend istream& operator>>(istream& in, Property& obj) 
    {   
        if(&in==&cin)
        { 
           cout << "Enter id name price: "<<endl;
           in >> obj.id >> obj.name >> obj.start;
        }
        else
           in >> obj.id >> obj.name >> obj.start>>obj.owner>>obj.price;
        return in;
    }

};