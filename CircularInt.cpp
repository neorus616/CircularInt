#include <iostream>
#include <string>
#include "CircularInt.hpp"
using namespace std;


    CircularInt::CircularInt(int min, int max){
        if(max < 0 || min < 0 || max < min){
            cout << "Wrong values entered, defining default values 1-12" << endl;
            this->max = 12;
            this->min = 1;
            cur = 1;
        } 
        else {
            this->max = max;
            this->min = min;
            cur = min;
        }
    }
        
    CircularInt& CircularInt::operator = (CircularInt const & cp){
        this->max = cp.max;
        this->min = cp.min;
        this->cur = cp.cur;
        return *this;
    }

    CircularInt& CircularInt::operator += (CircularInt const & add){
        cur += add.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator += (int const add){
        cur += add;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator -= (CircularInt const & sub){
        cur -= sub.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator -= (int const sub){
        cur -= sub;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator *= (CircularInt const & mul){
        cur *= mul.cur;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator *= (int const mul){
        cur *= mul;
        cur = cur % max;
        if(cur < min)
            cur += max;
        return *this;
    }
        
    CircularInt& CircularInt::operator /= (CircularInt const & div){
        if(cur % div.cur != 0)
            throw "There is no number x in {"+to_string(min)+","+to_string(max)+"} such that x * "+to_string(div.cur)+" = "+to_string(cur)+" ";
        else{
            cur /= div.cur;
            cur = cur % max;
            if(cur < min)
                cur += max;
        }
        return *this;
    }
        
    CircularInt& CircularInt::operator /= (int const div){
         if(cur % div != 0)
            throw "There is no number x in {"+to_string(min)+","+to_string(max)+"} such that x * "+to_string(div)+" = "+to_string(cur)+" ";
        else{
        cur /= div;
        cur = cur % max;
        if(cur < min)
            cur += max;
        }
        return *this;
    }
        
    ostream& operator << (ostream& os, CircularInt const & circ){
        return os << circ.cur;
    }
    
    istream& operator >> (istream & is, CircularInt& circ){
        is >> circ.min >> circ.max;
        circ.cur = circ.min;
    }

    CircularInt operator - (int x, CircularInt const & obj){
        CircularInt res {obj.min, obj.max};
        x = x % obj.max;
        res.cur = x;
        res -= obj;
        return res;
    }
    
    CircularInt operator - (CircularInt const & obj,int x){
        CircularInt res {obj.min, obj.max};
        res.cur = obj.cur;
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
                res.cur = res.cur+res.max;
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
    
    CircularInt operator / (int x, CircularInt const & obj){
        CircularInt res {obj.min, obj.max};
        x = x % obj.max;
        res.cur = x;
        res /= obj;
        return res;
    }
    
    CircularInt operator / (CircularInt const & a, CircularInt const & b){
        if(a.max != b.max || a.min != b.min){
            throw string("The objects have different cycles");
        } else {
            CircularInt res {a.min, a.max};
            res.cur = a.cur / b.cur;
            if(res.cur < 0){
                res.cur = res.cur % res.max;
                res.cur = res.cur+res.max;
            }
            return res;
        }
    }

    CircularInt operator + (int x, CircularInt const & obj){
        CircularInt res {obj.min, obj.max};
        x = x % obj.max;
        res.cur = x;
        res += obj;
        return res;
    }
    
    CircularInt operator + (CircularInt const & obj,int x){
        CircularInt res {obj.min, obj.max};
        res.cur = obj.cur;
        res += x;
        return res;
    }
    
    CircularInt operator + (CircularInt const & a, CircularInt const & b){
        if(a.max != b.max || a.min != b.min){
            throw string("The objects have different cycles");
        } else {
        CircularInt res {a.min, a.max};
        res.cur = (a.cur + b.cur) % a.max;
        return res;
        }
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
        

    CircularInt& CircularInt::operator++(int){
        cur++;
        return *this;
    }
        
      
    CircularInt::~CircularInt(){};