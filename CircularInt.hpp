#pragma once
#include <iostream>
using namespace std;


class CircularInt{
    private:
        int max;
        int min;
        int cur;
        
    public:
        CircularInt(int, int);
        CircularInt& operator =(CircularInt);
        CircularInt& operator =(int);
        CircularInt& operator+=(CircularInt);
        void operator-=(int);
        void operator*=(int);
        void operator/=(int);
        ostream& operator<<(ostream& , const CircularInt&);
        istream& operator>>(istream & , CircularInt&);
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