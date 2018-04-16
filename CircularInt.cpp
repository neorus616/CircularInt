#include <iostream>
#include "CircularInt.hpp"
using namespace std;

//coding from universty pc check
    CircularInt::CircularInt(int min, int max){
        if(max<0 || max < min || min<0){
            cout << "Wrong values entered, defining default values 1-12";
            this->max=12;
            this->min=1;
            cur=1;
        } 
        else {
            this->max = max;
            this->min = min;
            cur = min;
        }
    }
        
    CircularInt& CircularInt::operator= (const CircularInt& cp){
        this->max = cp.max;
        this->min = cp.min;
        this->cur = cp.cur;
        return *this;
    }
        
    CircularInt& CircularInt::operator=(const int cp){
        this->cur = cp;
        return *this;
    }
        
    CircularInt& CircularInt::operator+=(const CircularInt& add){
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
        
    CircularInt& CircularInt::operator-=(const CircularInt& sub){
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
        
    CircularInt& CircularInt::operator*=(const CircularInt& mul){
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
        
    CircularInt& CircularInt::operator/=(const CircularInt& div){
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
        
    std::ostream& operator<<(ostream& os, CircularInt const & circ){
        return os << circ.cur;
    }
    
    //std::istream& operator>>(istream & is, const CircularInt& circ){     
    //}

    //void CircularInt::operator+(CircularInt a){   
    //}

    CircularInt operator - (int x, CircularInt const & obj){
        CircularInt res {obj.min, obj.max};
        res.cur = x;
        res -= obj;
        return res;
    }

    CircularInt operator + (CircularInt const & a, CircularInt const & b){
        CircularInt res {a.min, a.max};
        res.cur = (a.cur + b.cur) % a.max;
        return res;
    }

    CircularInt& CircularInt::operator-(){
        cur = (max - cur) % max;
        return *this;
    }
        
    //void CircularInt::operator*(int a){            
    //}

        CircularInt& CircularInt::operator++(int){
            cur++;
            return *this;
        }//
        
    // CircularInt& CircularInt::operator--(int){    
    //     return *this;
    // }
        
    CircularInt::~CircularInt(){};