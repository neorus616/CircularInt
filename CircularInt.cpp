#include <iostream>
using namespace std;

#include "CircularInt.hpp"



        CircularInt::CircularInt(int a, int b){
            max = a;
            min = b;
            if(max<0 || max < min || min<0){
                cout << "Wrong values entered, defining default values 1-12 and assigning min value";
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
        void CircularInt::operator-=(int sub){
            cur -=sub;
            while(cur>max){
                cur-=max;
            }
            while(cur<min){
                cur+=max;
            }
        }
        void CircularInt::operator*=(int mul){
            cur *=mul;
            while(cur>max){
                cur-=max;
            }
            while(cur<min){
                cur+=max;
            }
        }
        void CircularInt::operator/=(int div){
            cur /=div;
            while(cur>max){
                cur-=max;
            }
            while(cur<min){
                cur+=max;
            }
        }
        ostream& CircularInt::operator<<(ostream& os, const CircularInt& circ){
            return os << circ.cur;
        }
        istream& CircularInt::operator>>(istream & is, CircularInt& frac){
            
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