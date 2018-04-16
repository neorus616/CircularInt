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
        CircularInt& operator =(CircularInt const &);
        CircularInt& operator =(int);
        CircularInt& operator+=(CircularInt const &);
        CircularInt& operator+=(int);
        CircularInt& operator-=(CircularInt const &);
        CircularInt& operator-=(int);
        CircularInt& operator*=(CircularInt const &);
        CircularInt& operator*=(int);
        CircularInt& operator/=(CircularInt const &);
        CircularInt& operator/=(int);
        friend CircularInt operator - (int, CircularInt const &);
        friend CircularInt operator + (CircularInt const &, CircularInt const &);
        friend CircularInt operator / ( CircularInt const &,int);
        friend ostream& operator<<(ostream &, CircularInt const &);
        friend istream& operator>>(istream & ,CircularInt const &);
        
        //void operator+(CircularInt);
        //void operator+(int);
        //int operator- (int);
        CircularInt operator- ();
        //void operator*(int);
        //void operator/(int);
        CircularInt& operator++(int);
        //void operator--(int);
        ~CircularInt();
};