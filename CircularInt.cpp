#include <iostream>
#include <string>
#include "CircularInt.hpp"
using namespace std;

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

CircularInt operator + (int x, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
    res.cur = (x + obj.cur) % obj.max;
	return res;
}

CircularInt operator + (CircularInt const & obj, int add){
	CircularInt res {obj.min, obj.max};
	res.cur = (add + obj.cur) % obj.max;
	return res;
}

CircularInt operator + (CircularInt const & a, CircularInt const & b){
	if(a.max != b.max || a.min != b.min){
		throw "The objects have different cycles";
	} else{
		CircularInt res {a.min, a.max};
		res.cur = (a.cur + b.cur) % a.max;
		return res;
	}
}

CircularInt& CircularInt::operator ++ (){
	*this += 1;
	return *this;
}

const CircularInt CircularInt::operator ++ (int){
	CircularInt res {min, max};
	if(cur==max){
	    res.cur = min;
	    cur = min;
	}
	else 
	    res.cur = cur++;
	return res;
}

//---------------------------------Subtraction---------------------------------//
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

CircularInt operator - (int x, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	x = x % obj.max;
	res.cur = x;
	res -= obj;
	return res;
}

CircularInt operator - (CircularInt const & obj, int sub){
	CircularInt res {obj.min, obj.max};
	res.cur = obj.cur;
	res -= sub;
	return res;
}

CircularInt operator - (CircularInt const & a, CircularInt const & b){
	if(a.max != b.max || a.min != b.min){
		throw string("The objects have different cycles");
	} else {
		CircularInt res {a.min, a.max};
		res.cur = (a.cur - b.cur) % res.max;
		if(res.cur < res.min)
			res.cur += res.max;
		return res;
	}
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
    res.cur = this->cur-- % this->max;
	if(res.cur < res.min)
		res.cur += res.max;
	return res;
}
//*******************************Multiplication********************************//
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

CircularInt operator * (int x, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	x = x % obj.max;
	res.cur = x;
	res *= obj;
	return res;
}

CircularInt operator * (CircularInt const & obj, int mul){
	CircularInt res {obj.min, obj.max};
	res.cur = obj.cur;
	res *= mul;
	return res;
}

CircularInt operator * (CircularInt const & a, CircularInt const & b){
	if(a.max != b.max || a.min != b.min){
		throw "The objects have different cycles";
	} else {
		CircularInt res {a.min, a.max};
		res.cur = a.cur * b.cur % res.max;
		if(res.cur < res.min)
			res.cur += res.max;
		return res;
	}
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