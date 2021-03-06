#pragma once
#include <iostream>
using namespace std;

class CircularInt{
    private:
        int max;
        int min;
        int cur;
        //int normalization(int, int, int, int);
       
    public:
        CircularInt();
        CircularInt(int, int);
        //= = = = = = = = = = = = = = = =Assignment = = = = = = = = = = = = = = = = = =//
        CircularInt& operator = (CircularInt const &);
        CircularInt& operator = (int const);
        //===============================Comparison====================================//
        friend bool operator == (CircularInt const &, int const);
        friend bool operator == (int const, CircularInt const &);
        friend bool operator == (CircularInt const &, CircularInt const &);
        friend bool operator != (CircularInt const &, int const);
        friend bool operator != (int const, CircularInt const &);
        friend bool operator != (CircularInt const &, CircularInt const &);
        friend bool operator <= (CircularInt const &, int const);
        friend bool operator <= (int const, CircularInt const &);
        friend bool operator <= (CircularInt const &, CircularInt const &);
        friend bool operator < (CircularInt const &, int const);
        friend bool operator < (int const, CircularInt const &);
        friend bool operator < (CircularInt const &, CircularInt const &);
        friend bool operator >= (CircularInt const &, int const);
        friend bool operator >= (int const, CircularInt const &);
        friend bool operator >= (CircularInt const &, CircularInt const &);
        friend bool operator > (CircularInt const &, int const);
        friend bool operator > (int const, CircularInt const &);
        friend bool operator > (CircularInt const &, CircularInt const &);
        //++++++++++++++++++++++++++++++++Addition+++++++++++++++++++++++++++++++++++++//
        CircularInt& operator += (int);
        CircularInt& operator += (CircularInt const &);
        friend CircularInt operator + (int, CircularInt const &);
        friend CircularInt operator + (CircularInt const &, int);
        friend CircularInt operator + (CircularInt const &, CircularInt const &);
        CircularInt& operator ++ ();
        const CircularInt operator ++ (int);
        //--------------------------------Subtraction----------------------------------//
        CircularInt operator - ();
        CircularInt& operator -= (CircularInt const &);
        CircularInt& operator -= (int);
        friend CircularInt operator - (int, CircularInt const &);
        friend CircularInt operator - (CircularInt const &,int);
        friend CircularInt operator - (CircularInt const &,CircularInt const &);
        CircularInt& operator -- ();
        const CircularInt operator -- (int);
        //********************************Multiplication*******************************//
        CircularInt& operator *= (CircularInt const &);
        CircularInt& operator *= (int);
        friend CircularInt operator * (int, CircularInt const &);
        friend CircularInt operator * (CircularInt const &,int);
        friend CircularInt operator * (CircularInt const &, CircularInt const &);
        //:::::::::::::::::::::::::::::::::Division:::::::::::::::::::::::::::::::::::://
        CircularInt& operator /= (int);
        CircularInt& operator /= (CircularInt const &);
        CircularInt& operator %= (const int other);
        friend CircularInt operator / (int, CircularInt const &);
        friend CircularInt operator / (CircularInt const &, int);
        friend CircularInt operator / (CircularInt const &, CircularInt const &);
        friend const CircularInt operator % (const CircularInt& c , const int num);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, CircularInt const &);
        friend istream& operator >> (istream & ,CircularInt &);

        ~CircularInt();
};