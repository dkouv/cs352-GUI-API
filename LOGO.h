#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include "./hy352_gui.h"

using namespace std;

#define START_PROGRAM int main(){extern vector<int> glob_list;extern variable ss; variable v;turtle_mv_f turtle_f;turtle_mv_b turtle_b;turtle_left turtle_l;turtle_right turtle_r;set_pen_c pen_color;set_screen_c screen_color;turtle_draw_cir draw_circle; set_pen_thic thic;draw_label d_label;int a; string s;  bool b;
#define END_PROGRAM ;return 0;}

#define PROGRAM_BEGIN_PRINT cout << "********START*********" << endl;
#define PROGRAM_END_PRINT cout   << "*********END**********" << endl; cin.get();

#define SETSCREENCOLOR 	;screen_color=
#define SETPENCOLOR 		;pen_color=
#define FORWARD 				;turtle_f=
#define BACK 						;turtle_b=
#define LEFT						;turtle_l=
#define RIGHT						;turtle_r=
#define CENTER 					;turtle_go_to_center();
#define PENUP 					;pen_up();
#define PENDOWN					;pen_down();
#define CIRCLE					;draw_circle=
#define SETPENSIZE			;thic=
#define PRINT						;d_label=

#define MAKE 	;auto
#define TRUE 	true
#define FALSE false

#define IF 		;if(
#define DO 		){
#define ELIF	;}else if(
#define ELSE 	;}else{
#define END 	;};

#define NUMBER 		v = a = false ? 1
#define WORD  		v = s = false ? "lol "
#define BOOLEAN 	v = b = false ? false
#define LIST 			ss
#define SENTENCE 	ss=
#define ARRAY 		variable

#define SUM 				sum_func
#define DIFFERENCE 	diff_func
#define MINUS				minus_func
#define PRODUCT			product_func
#define QUOTIENT 		quot_func
#define MODULO 			mod_func

#define NOT not_func
#define AND and_func
#define OR 	or_func

#define ASSIGN ;

#define REPEAT		;for(int i=0; i <
#define TIMES			; i++
#define REPCOUNT	v = NUMBER: i+1
//#define WHILE

#define ITEM		get_item
#define SETITEM	;set_item

enum type { W, N, B, L, A, S, D, LOL = -1 };


class variable
{
private:
	type t;
	int number;
	double d_number;
	string word;
	bool boolean;

public:
	list <variable> bucket;
	variable() {}

	variable(int i) : number(i), t(N) {}

	variable(string s) : word(s), t(W) {}

	variable(bool b) : boolean(b), t(B) {}

	variable(double d) : d_number(d), t(D) {}

	variable(string s, type t) : word(s), t(S) {}

	variable(initializer_list<variable> list)
	{
		setType(A);
		for(auto i : list)
		{
			bucket.push_back(i);
		}
	}

	variable operator[](variable v);

	variable operator,(variable v);

	variable operator=(variable v);

	bool operator==(variable v);
	bool operator!=(variable v);
	bool operator>=(variable v);
	bool operator<=(variable v);
	bool operator<(variable v);
	bool operator>(variable v);

	/***************setters and getters****************/
	type getType() const;

	void setType(type t);

	int getNumber() const;

	void setNumber(int y);

	string getWord() const;

	void setWord(string s);

	bool getBoolean() const;

	void setBoolean(bool b);

};

class turtle_mv_f
{
public:
	turtle_mv_f() {}
	turtle_mv_f(variable v)
	{
		turtle_mv_forward(v.getNumber());
	}
};

class turtle_mv_b
{
public:
	turtle_mv_b() {}
	turtle_mv_b(variable v)
	{
		turtle_mv_backward(v.getNumber());
	}
};

class turtle_right
{
public:
	turtle_right() {}
	turtle_right(variable v)
	{
		turtle_rotate(v.getNumber());
	}
};

class turtle_left
{
public:
	turtle_left() {}
	turtle_left(variable v)
	{
		int tmp = (-1) * v.getNumber();
		turtle_rotate(tmp);
	}
};

class set_pen_thic
{
public:
	set_pen_thic() {}
	set_pen_thic(variable v)
	{
		set_pen_thickness(v.getNumber());
	}
};

class turtle_draw_cir
{
public:
	turtle_draw_cir() {}
	turtle_draw_cir(variable v)
	{
		turtle_draw_circle(v.getNumber());
	}
};

class set_pen_c
{
public:
	set_pen_c() {}
	set_pen_c(variable v)
	{
		unsigned i1, i2, i3;
		std::list<variable>::iterator it = v.bucket.begin();
		i1 = (unsigned) (*it).getNumber();
		it++;
		i2 = (unsigned) (*it).getNumber();
		it++;
		i3 = (unsigned) (*it).getNumber();
		set_pen_color(i1, i2, i3);
	}
};

class set_screen_c
{
public:
	set_screen_c() {}
	set_screen_c(variable v)
	{
		unsigned i1, i2, i3;
		std::list<variable>::iterator it = v.bucket.begin();
		i1 = (unsigned) (*it).getNumber();
		it++;
		i2 = (unsigned) (*it).getNumber();
		it++;
		i3 = (unsigned) (*it).getNumber();
		set_screen_color(i1, i2, i3);
	}
};

class draw_label
{
public:
	draw_label() {}
	draw_label(variable v)
	{
		turtle_draw_label(v.getWord().c_str());
	}
};


void foreach_func(variable v);

void output(variable v);

variable get_item(initializer_list<int> list, variable v);

void set_item(initializer_list<int> list, variable& set, variable value);

void set_func(int list, variable& set, variable value);

bool not_func(bool x);


template<typename T>
T sum_func(T v) {
	return v;
}

template<typename T, typename... Args>
T sum_func(T first, Args... args) {
	return first.getNumber() + sum_func(args...).getNumber();
}

template<typename T, typename Ts>
T diff_func(T first, Ts second) {
	return first.getNumber() - second.getNumber();
}

template<typename T>
T minus_func(T v) {
	variable temp;
	temp.setNumber(-v.getNumber());
	return temp;
}

template<typename T>
T product_func(T v) {
	return v;
}

template<typename T, typename... Args>
T product_func(T first, Args... args) {
	return first.getNumber() * product_func(args...).getNumber();
}


template<typename T, typename Ts>
T quot_func(T first, Ts second) {
	variable temp;


	if (second.getNumber() == 0) {
		cout << "Error: You tried to divide by zero";
		return -1;
	}
	else {
		temp.setNumber(first.getNumber() / second.getNumber());
		return temp;
	}

}

template<typename T, typename Ts>
T mod_func(T first, Ts second) {
	return  first.getNumber() % second.getNumber();
}

template<typename T>
T and_func(T v) {
	return v;
}

template<typename T>
T or_func(T v) {
	return v;
}

template<typename T, typename... Args>
T and_func(T first, Args... args) {

	return first && and_func(args...);
}

template<typename T, typename... Args>
T or_func(T first, Args... args) {
	return first || or_func(args...);
}
