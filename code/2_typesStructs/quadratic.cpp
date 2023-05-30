#include <string>
#include <iostream>
#include <cmath> //gives us pow and sqrt!

using std::string; using std::cout;
using std::cin; using std::pow;
using std::sqrt; using std::endl;

//want: a function named quadratic that will take in 3 doubles and return
//a combination of: does a solution exist, and if so, what is it?
struct result{
	bool real_root;
	std::pair<double,double>x1,x2;
};
result quadratic(double a,double b,double c){
	//get radical, test if negative, return indicating no roots
	double radical=pow(b,2)-4*a*c;
	result r;
	if(radical<0){
		r.real_root=0;
		r.x1=std::make_pair(-b/(2*a),-sqrt(-radical)/(2*a));
		r.x1=std::make_pair(-b/(2*a),+sqrt(-radical)/(2*a));
	}else{
		r.real_root=1;
		r.x1=std::make_pair((-b-sqrt(radical))/(2*a),0);
		r.x2=std::make_pair((-b+sqrt(radical))/(2*a),0);
	}
	return r;
	//otherwise get roots and return
}
int main(){
	//get 3 doubles (ax^2 + bx + c)
	double a, b, c;
	cout << "Give me 3 coefficients: " << endl;

	//This line gets 3 numbers from user input and stores them in a, b and c 
	//we will learn more about cin on Thursday
	cin >> a >> b >> c;
	//some call to quadratic function!
	result r=quadratic(a,b,c);
	//get roots if they exist
	if(r.real_root==1){
		cout<<"exsist real root:"<<r.x1.first<<" "<<r.x2.first<<endl;
	}else{
		cout<<"no real root:"<<r.x1.first<<"+"<<r.x1.second<<"i"<<" "<<r.x2.first<<"+"<<r.x2.second<<"i"<<endl;
	}
	//print accordingly

	return 0;
}