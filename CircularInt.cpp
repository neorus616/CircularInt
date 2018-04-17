#include <iostream>
#include <string>
#include "CircularInt.hpp"
using namespace std;

    //change for commit


int normalization(int norm, int min, int max){
	norm = norm % (max-min+1);
	if(norm>max)
		norm -= (max-min+1);
	if(norm < min)
		norm += (max-min+1);
	return norm;
}

//Constructor
CircularInt::CircularInt(int min, int max){
	if(max < 0 || min < 0 || max < min){
		cout << "Wrong values entered, defining default values 1-12" << endl;
		this->max = 12;
		this->min = 1;
		cur = 1;
	} else{
		this->max = max;
		this->min = min;
		cur = min;
	}
}
//= = = = = = = = = = = = = = = = Assignment = = = = = = = = = = = = = = = = = //
CircularInt& CircularInt::operator = (CircularInt const & cp){
	this->max = cp.max;
	this->min = cp.min;
	this->cur = cp.cur;
	return *this;
}
//================================Comparison===================================//
bool operator == (CircularInt const & obj, int const num){
    return obj.cur == num;
}

bool operator == (int const num, CircularInt const & obj){
    return num == obj.cur;
}

bool operator == (CircularInt const & a, CircularInt const & b){
    return a.cur == b.cur;
}

bool operator != (CircularInt const & obj, int num){
    return !(obj.cur == num);
}

bool operator != (int num, CircularInt const & obj){
    return !(num == obj.cur);
}

bool operator != (CircularInt const & a, CircularInt const & b){
    return !(a.cur == b.cur);
}
//+++++++++++++++++++++++++++++++++Addition++++++++++++++++++++++++++++++++++++//
CircularInt& CircularInt::operator += (CircularInt const & add){
	cur = normalization(cur+add.cur, min, max);
	return *this;
}

CircularInt& CircularInt::operator += (int const add){
	cur = normalization(cur+add, min, max);
	return *this;
}

CircularInt operator + (int add, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
    res.cur = normalization(add+obj.cur, obj.min, obj.max);
	return res;
}

CircularInt operator + (CircularInt const & obj, int add){
	return add + obj;
}

CircularInt operator + (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	res.cur = normalization(a.cur+b.cur, a.min, a.max);
	return res;
}

CircularInt& CircularInt::operator ++ (){
	*this += 1;
	return *this;
}

const CircularInt CircularInt::operator ++ (int){
	CircularInt res {min, max};
	res.cur = cur;
	cur = normalization(cur + 1, min, max);
	return res;
}

//---------------------------------Subtraction---------------------------------//
CircularInt& CircularInt::operator -= (CircularInt const & sub){
	cur = normalization(cur-sub.cur, min, max);
	return *this;
}

CircularInt& CircularInt::operator -= (int const sub){
	cur = normalization(cur-sub, min, max);
	return *this;
}

CircularInt operator - (int sub, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	res.cur = normalization(res.cur-sub, res.min, res.max);
	return res;
}

CircularInt operator - (CircularInt const & obj, int sub){
	return sub - obj;
}

CircularInt operator - (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	res.cur = normalization(a.cur-b.cur, a.min, a.max);
	return res;
}

CircularInt CircularInt::operator - (){
	CircularInt res {min, max};
	res.cur = cur;
	res.cur -= max;
	res.cur *= -1;
	return res;
}

CircularInt& CircularInt::operator -- (){
	cur -= 1;
	return *this;
}

const CircularInt CircularInt::operator -- (int){
	CircularInt res {min, max};
	res.cur = cur;
	cur = normalization(cur - 1, min, max);
	return res;
}
//*******************************Multiplication********************************//
CircularInt& CircularInt::operator *= (CircularInt const & mul){
	cur = normalization(cur*mul.cur, min, max);
	return *this;
}

CircularInt& CircularInt::operator *= (int const mul){
	cur = normalization(cur*mul, min, max);
	return *this;
}

CircularInt operator * (int mul, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	res.cur = normalization(obj.cur*mul, obj.min, obj.max);
	return res;
}

CircularInt operator * (CircularInt const & obj, int mul){
	return mul * obj ;
}

CircularInt operator * (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	res.cur = normalization(a.cur*b.cur, a.min, a.max);
}
//:::::::::::::::::::::::::::::::::Division:::::::::::::::::::::::::::::::::::://
CircularInt& CircularInt::operator /= (CircularInt const & div){
	cur /= div.cur;
	cur = cur % max;
	if(cur < min)
		cur += max;
	return *this;
}

CircularInt& CircularInt::operator /= (int const div){
	cur /= div;
	cur = cur % max;
	if(cur < min)
		cur += max;
	return *this;
}

CircularInt operator / ( CircularInt const & obj, int div){
	CircularInt res {obj.min, obj.max};
	res.cur = obj.cur;
	if(res.cur % div == 0)
		res /= div;
	else
		throw "\"There is no number x in {"+to_string(obj.min)+","+to_string(obj.max)+"} such that x*"+to_string(div)+"="+to_string(obj.cur)+"\" ";
	return res;
}

CircularInt operator / (int x, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	x = x % obj.max;
	res.cur = x;
	if(res.cur % obj.cur == 0)
		res /= obj;
	else
		throw "\"There is no number x in {"+to_string(obj.min)+","+to_string(obj.max)+"} such that x*"+to_string(x)+"="+to_string(obj.cur)+"\" ";
	return res;
}

CircularInt operator / (CircularInt const & a, CircularInt const & b){
	if(a.max != b.max || a.min != b.min)
		throw "The objects have different cycles";
	else {
		CircularInt res {a.min, a.max};
        if(a.cur % b.cur == 0)
            res.cur = a.cur / b.cur;
        else
            throw "\"There is no number x in {"+to_string(a.min)+","+to_string(a.max)+"} such that x*"+to_string(a.cur)+"="+to_string(b.cur)+"\" ";
		return res;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
ostream& operator << (ostream& os, CircularInt const & circ){
	return os << circ.cur;
}

istream& operator >> (istream & is, CircularInt& circ){
		cin >> circ.min >> circ.max;
		circ.cur = circ.min;
	}

	CircularInt::~CircularInt(){}