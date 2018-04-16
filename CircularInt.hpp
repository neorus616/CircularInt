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
        CircularInt& operator = (int);
        CircularInt& operator = (CircularInt const &);
        
        CircularInt& operator += (int);
        CircularInt& operator += (CircularInt const &);
        friend CircularInt operator + (int, CircularInt const &);
        friend CircularInt operator + (CircularInt const &, int);
        friend CircularInt operator + (CircularInt const &, CircularInt const &);
        CircularInt& operator ++ (int);
        //---------------------------------Subtraction---------------------------------//
        CircularInt operator - ();
        CircularInt& operator -= (CircularInt const &);
        CircularInt& operator -= (int);
        friend CircularInt operator - (int, CircularInt const &);
        friend CircularInt operator - (CircularInt const &,int);
        friend CircularInt operator - (CircularInt const &,CircularInt const &);
        //*******************************Multiplication********************************//
        CircularInt& operator *= (CircularInt const &);
        CircularInt& operator *= (int);
        friend CircularInt operator * (int, CircularInt const &);
        friend CircularInt operator * (CircularInt const &,int);
        friend CircularInt operator * (CircularInt const &, CircularInt const &);
        //:::::::::::::::::::::::::::::::::Division:::::::::::::::::::::::::::::::::::://
        CircularInt& operator /= (int);
        CircularInt& operator /= (CircularInt const &);
        friend CircularInt operator / (int, CircularInt const &);
        friend CircularInt operator / (CircularInt const &, int);
        friend CircularInt operator / (CircularInt const &, CircularInt const &);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, CircularInt const &);
        friend istream& operator >> (istream & ,CircularInt &);

        ~CircularInt();
};
