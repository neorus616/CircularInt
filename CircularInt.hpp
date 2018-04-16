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
        CircularInt& operator = (CircularInt const &);
        CircularInt& operator = (int);
        
        CircularInt& operator += (CircularInt const &);
        CircularInt& operator += (int);
        friend CircularInt operator + (int, CircularInt const &);
        friend CircularInt operator + (CircularInt const &,int);
        friend CircularInt operator + (CircularInt const &, CircularInt const &);
        CircularInt& operator ++ (int);
        
        CircularInt& operator -= (CircularInt const &);
        CircularInt& operator -= (int);
        friend CircularInt operator - (int, CircularInt const &);
        friend CircularInt operator - (CircularInt const &,int);
        friend CircularInt operator - (CircularInt const &,CircularInt const &);
        CircularInt operator - ();
        
        CircularInt& operator *= (CircularInt const &);
        CircularInt& operator *= (int);
        friend CircularInt operator * (int, CircularInt const &);
        friend CircularInt operator * (CircularInt const &,int);
        friend CircularInt operator * (CircularInt const &, CircularInt const &);
        
        CircularInt& operator /= (CircularInt const &);
        CircularInt& operator /= (int);
        friend CircularInt operator / (int, CircularInt const &);
        friend CircularInt operator / (CircularInt const &,int);
        friend CircularInt operator / (CircularInt const &, CircularInt const &);

        friend ostream& operator << (ostream &, CircularInt const &);
        friend istream& operator >> (istream & ,CircularInt const &);
        
        

        ~CircularInt();
};
