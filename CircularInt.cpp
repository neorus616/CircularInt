#include <iostream>
#include <string>
#include "CircularInt.hpp"
using namespace std;


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


    CircularInt operator - (int x, CircularInt const & obj){
        CircularInt res {obj.min, obj.max};
        res.cur = x;
        res -= obj;
        return res;
    }
    
    CircularInt operator - (CircularInt const & obj,int x){
        CircularInt res {obj.min, obj.max};
        res.cur = obj.cur;
       // cout << res.cur;
        res -= x;
        return res;
    }
    
    CircularInt operator - (CircularInt const & a,CircularInt const & b){
        if(a.max != b.max || a.min != b.min){
            throw string("The objects have different cycles");
        } else {
            CircularInt res {a.min, a.max};
            res.cur = a.cur - b.cur;
            if(res.cur < 0){
                res.cur = res.cur % res.max;
                res.cur = res.cur*-1;
            }
            return res;
        }
    }
    
    CircularInt operator / ( CircularInt const & obj,int x){
        CircularInt res {obj.min, obj.max};
        res.cur = obj.cur;
        if(res.cur%x==0)
        res /= x;
        else
        throw string("There is no number x in {1,12} such that x*"+to_string(x)+"="+to_string(obj.cur)+" ");
        return res;
    }

    CircularInt operator + (CircularInt const & a, CircularInt const & b){
        CircularInt res {a.min, a.max};
        res.cur = (a.cur + b.cur) % a.max;
        return res;
    }

    CircularInt CircularInt::operator-(){
       // cur = (max - cur) % max;
       CircularInt res {min, max};
       res.cur = cur;
        res.cur -= max;
        res.cur *= -1;
        // if(cur<min)
        // cur*=(-1);
        return res;
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