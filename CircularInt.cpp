#include <iostream>
#include <string>
#include "CircularInt.hpp"
#define MAX 12
#define MIN 1

using namespace std;

//Constructors
    CircularInt::CircularInt(){
		max = MAX;
		min = MIN;
		cur = MIN;
	}

CircularInt::CircularInt(int min, int max){
	if(max < min){
		this->max = min;
		this->min = max;
		cur = 1;
	} else{
		this->max = max;
		this->min = min;
		cur = min;
	}
}

int normalization(int cur, int dif, int min, int max){
	cur += dif % (max - min + 1);
	if(cur > max)
		cur -= (max - min + 1);
	if(cur < min)
		cur += (max - min + 1);
	return cur;
}
//= = = = = = = = = = = = = = = = Assignment = = = = = = = = = = = = = = = = = //
CircularInt& CircularInt::operator = (CircularInt const & obj){
	this->max = obj.max;
	this->min = obj.min;
	this->cur = obj.cur;
	return *this;
}
CircularInt& CircularInt::operator = (int const num){
	this->cur = normalization(MIN - 1, num, min, max);
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

bool operator <= (CircularInt const & obj, int const num){
	return obj.cur <= num;
}

bool operator <= (int const num, CircularInt const & obj){
	return num <= obj.cur;

}

bool operator <= (CircularInt const & a, CircularInt const & b){
	return a.cur <= b.cur;
}

bool operator < (CircularInt const & obj, int const num){
	return obj.cur < num;
}

bool operator < (int const num, CircularInt const & obj){
	return num < obj.cur;

}

bool operator < (CircularInt const & a, CircularInt const & b){
	return a.cur < b.cur;
}

bool operator >= (CircularInt const & obj, int const num){
	return obj.cur >= num;
}

bool operator >= (int const num, CircularInt const & obj){
	return num >= obj.cur;

}

bool operator >= (CircularInt const & a, CircularInt const & b){
	return a.cur >= b.cur;
}

bool operator > (CircularInt const & obj, int const num){
	return obj.cur > num;
}

bool operator > (int const num, CircularInt const & obj){
	return num > obj.cur;

}

bool operator > (CircularInt const & a, CircularInt const & b){
	return a.cur > b.cur;
}
//+++++++++++++++++++++++++++++++++Addition++++++++++++++++++++++++++++++++++++//
CircularInt& CircularInt::operator += (CircularInt const & add){
	cur = normalization(cur, add.cur, min, max);
	return *this;
}

CircularInt& CircularInt::operator += (int const add){
	cur = normalization(cur, add, min, max);
	return *this;
}

CircularInt operator + (int add, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
    res.cur = normalization(obj.cur, add, obj.min, obj.max);
	return res;
}

CircularInt operator + (CircularInt const & obj, int add){
	return add + obj;
}

CircularInt operator + (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	res.cur = normalization(a.cur, b.cur, a.min, a.max);
	return res;
}

CircularInt& CircularInt::operator ++ (){
	*this += 1;
	return *this;
}

const CircularInt CircularInt::operator ++ (int){
	CircularInt res {min, max};
	res.cur = cur;
	cur = normalization(cur, 1, min, max);
	return res;
}

//---------------------------------Subtraction---------------------------------//
CircularInt& CircularInt::operator -= (CircularInt const & sub){
	cur = normalization(cur, -sub.cur, min, max);
	return *this;
}

CircularInt& CircularInt::operator -= (int const sub){
	cur = normalization(cur, -sub, min, max);
	return *this;
}

CircularInt operator - (int sub, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	res.cur = normalization(normalization(sub, 0, res.min, res.max), -obj.cur, res.min, res.max);
	return res;
}

CircularInt operator - (CircularInt const & obj, int sub){
	return ((-sub) + obj);
}

CircularInt operator - (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	res.cur = normalization(a.cur, -b.cur, a.min, a.max);
	return res;
}

CircularInt CircularInt::operator - (){
	CircularInt res {min, max};
	res.cur = normalization(max, -cur, min, max);
	return res;
}

CircularInt& CircularInt::operator -- (){
	cur -= 1;
	return *this;
}

const CircularInt CircularInt::operator -- (int){
	CircularInt res {min, max};
	res.cur = cur;
	cur = normalization(cur, -1, min, max);
	return res;
}
//*******************************Multiplication********************************//
CircularInt& CircularInt::operator *= (CircularInt const & mul){
	cout << "this *= CircularInt" << endl;
	cout << "mul " << mul.cur << endl;
	cout << "this.cur " << cur << endl;
	cout << "this.min " << min << endl;
	cout << "this.max " << max << endl;
	cur = normalization(0 , cur * mul.cur, min, max);
	cout << "new.cur " << cur << endl;
	return *this;
}

CircularInt& CircularInt::operator *= (int const mul){
	cout << "this *= int" << endl;
	cout << "mul " << mul << endl;
	cout << "this.cur " << cur << endl;
	cout << "this.min " << min << endl;
	cout << "this.max " << max << endl;
	cur = normalization(0, cur * mul, min, max);
	cout << "new.cur " << cur << endl;
	return *this;
}

CircularInt operator * (int mul, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	res.cur = normalization(obj.min - 1, obj.cur * mul, obj.min, obj.max);
	return res;
}

CircularInt operator * (CircularInt const & obj, int mul){
	return mul * obj ;
}

CircularInt operator * (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	res.cur = normalization(a.min - 1, a.cur * b.cur, a.min, a.max);
	return res;
}
//:::::::::::::::::::::::::::::::::Division:::::::::::::::::::::::::::::::::::://
CircularInt& CircularInt::operator /= (CircularInt const & div){
	if(max > div.cur && div.cur < min){
		for(int i = min; i <= max; i++)
			if(cur == div.cur * i){
				this->cur = i;
				return *this;
		}
	}
	throw "\"There is no number x in {"+to_string(min)+","+to_string(max)+"} such that x*"+to_string(div.cur)+"="+to_string(cur)+"\" ";
}

CircularInt& CircularInt::operator /= (int const div){
	if(max > div && div < min){
		for(int i = min; i <= max; i++)
			if(cur == div * i){
				this->cur = i;
				return *this;
		}
	}
	throw "\"There is no number x in {"+to_string(min)+","+to_string(max)+"} such that x*"+to_string(div)+"="+to_string(cur)+"\" ";
}

CircularInt& CircularInt::operator %= (const int div){
	cur = normalization(min - 1, cur % div, min, max);
	return *this;
}

CircularInt operator / ( CircularInt const & obj, int div){
	CircularInt res {obj.min, obj.max};
	if(obj.min <= div && div <= obj.cur){
		for(int i = obj.min; i <= obj.max; i++)
			if(obj.cur == div * i){
				res.cur = i;
				return res;
		}
	}
	throw "\"There is no number x in {"+to_string(obj.min)+","+to_string(obj.max)+"} such that x*"+to_string(div)+"="+to_string(obj.cur)+"\" ";
}

CircularInt operator / (int div, CircularInt const & obj){
	CircularInt res {obj.min, obj.max};
	if(obj.cur <= div && div <= obj.max){
		for(int i = obj.min; i <= obj.max; i++)
			if(div == obj.cur * i){
				res.cur = i;
				return res;
		}
	}
	throw "\"There is no number x in {"+to_string(obj.min)+","+to_string(obj.max)+"} such that x*"+to_string(div)+"="+to_string(obj.cur)+"\" ";
}

CircularInt operator / (CircularInt const & a, CircularInt const & b){
	CircularInt res {a.min, a.max};
	if(a.min <= b.cur && b.cur <= a.cur){
		for(int i = a.min; i <= a.max; i++)
			if(a.cur == b.cur * i){
				res.cur = i;
				return res;
			}
		}
    throw "\"There is no number x in {"+to_string(a.min)+","+to_string(a.max)+"} such that x*"+to_string(a.cur)+"="+to_string(b.cur)+"\" ";
}

const CircularInt operator % (const CircularInt& obj , const int num){
	CircularInt res {obj.min, obj.max};
	res.cur = normalization(0, obj.cur % num, obj.min, obj.max);
	return res;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
ostream& operator << (ostream& os, CircularInt const & circ){
	return os << circ.cur;
}

istream& operator >> (istream & is, CircularInt& circ){
	is >> circ.cur;
	circ.cur = normalization(circ.min - 1, circ.cur, circ.min, circ.max);
	return is;
}

	CircularInt::~CircularInt(){}
