#include <iostream>
#include "CircularInt.hpp"
using namespace std;

    CircularInt::CircularInt(int a, int b){
        max = b;
        min = a;
        if(max<0 || max < min || min<0){
            cout << "Wrong values entered, defining default values 1-12";
            max=12;
            min=1;
            cur=1;
        } else cur = min;
    }
        
    CircularInt& CircularInt::operator =(CircularInt cp){
        this->max = cp.max;
        this->min = cp.min;
        this->cur = cp.cur;
    }
        
    CircularInt& CircularInt::operator =(int cp){
        this->cur = cp;
    }
        
    CircularInt& CircularInt::operator+=(CircularInt add){
        cur +=add.cur;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator+=(int add){
        cur +=add;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator-=(CircularInt sub){
        cur -=sub.cur;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator-=(int sub){
        cur -=sub;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator*=(CircularInt mul){
        cur *=mul.cur;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator*=(int mul){
        cur *=mul;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator/=(CircularInt div){
        cur /=div.cur;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator/=(int div){
        cur /=div;
        while(cur>max){
            cur-=max;
        }
        while(cur<min){
            cur+=max;
        }
        return *this;
    }
        
    std::ostream& operator<<(ostream& os, const CircularInt& circ){
        return os << circ.cur;
    }
    
    std::istream& operator>>(istream & is, CircularInt& frac){     
        }

        void CircularInt::operator+(CircularInt a){   
        }

        void CircularInt::operator+(int a){   
        }

        void CircularInt::operator-(CircularInt a){   
        }

        void CircularInt::operator-(int a){   
        }
        
        void CircularInt::operator*(int a){            
        }

        void CircularInt::operator/(int a){            
        }

        void CircularInt::operator++(int a){            
        }
        
        void CircularInt::operator--(int b){            
        }
        
        CircularInt::~CircularInt(){};
