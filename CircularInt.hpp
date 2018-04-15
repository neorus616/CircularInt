#pragma once
#include <iostream>
using namespace std;


class CircularInt{
    private:
       
    public:
     int max;
        int min;
        int cur;
        CircularInt(int, int);
        CircularInt& operator =(CircularInt);
        CircularInt& operator =(int);
        CircularInt& operator+=(CircularInt);
        CircularInt& operator+=(int);
        CircularInt& operator-=(CircularInt);
        CircularInt& operator-=(int);
        CircularInt& operator*=(CircularInt);
        CircularInt& operator*=(int);
        CircularInt& operator/=(CircularInt);
        CircularInt& operator/=(int);
        
        void operator+(CircularInt);
        void operator+(int);
        void operator-(CircularInt);
        void operator-(int);
        void operator*(int);
        void operator/(int);
        void operator++(int);
        void operator--(int);
        ~CircularInt();
};
std::ostream& operator<<(ostream& , const CircularInt&);
        std::istream& operator>>(istream & , CircularInt&);