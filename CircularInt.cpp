#include <iostream>
#include "CircularInt.hpp"
using namespace std;

    CircularInt::CircularInt(int a, int b){

        if(max<0 || max < min || min<0){
            cout << "Wrong values entered, defining default values 1-12";
            max=12;
            min=1;
            cur=1;
        } 
        else {
            max = b;
            min = a;
            cur = min;
        }
    }
        
    CircularInt& CircularInt::operator=(const CircularInt cp){
        this->max = cp.max;
        this->min = cp.min;
        this->cur = cp.cur;
        return *this;
    }
        
    CircularInt& CircularInt::operator=(const int cp){
        this->cur = cp;
        return *this;
    }
        
    CircularInt& CircularInt::operator+=(const CircularInt add){
        cur += add.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator+=(const int add){
        cur += add;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator-=(const CircularInt sub){
        cur -= sub.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator-=(const int sub){
        cur -= sub;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator*=(const CircularInt mul){
        cur *= mul.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator*=(const int mul){
        cur *= mul;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator/=(const CircularInt div){
        cur /= div.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator/=(const int div){
        cur /= div;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    std::ostream& operator<<(ostream& os, const CircularInt& circ){
        return os << circ.cur;
    }
    
    std::istream& operator>>(istream & is, const CircularInt& circ){     
    }

    void CircularInt::operator+(CircularInt a){   
    }

    void CircularInt::operator+(int a){   
    }

    CircularInt& CircularInt::operator-(CircularInt a){
        return *this;
    }

    CircularInt& CircularInt::operator-(int a){
        return *this;
    }
        
    void CircularInt::operator*(int a){            
    }

    void CircularInt::operator/(int a){            
    }

    CircularInt& CircularInt::operator++(int){
        cur++;
        return *this;
    }
        
    CircularInt& CircularInt::operator--(int){    
        return *this;
    }
        
    CircularInt::~CircularInt(){};