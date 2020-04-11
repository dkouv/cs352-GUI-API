#include "LOGO.h"

variable ss;	//Temporary variable for lists/sentences/arrays.
vector<int> glob_list;


bool variable::operator==(variable v) {

	if ((*this).getType() == v.getType() && v.getType() == N)
		return  (*this).getNumber() == v.getNumber();
	else if ((*this).getType() == v.getType() && v.getType() == W)
		return  (*this).getWord() == v.getWord();
	else if ((*this).getType() == v.getType() &&  v.getType() == B)
		return  (*this).getBoolean() == v.getBoolean();
	else
		return false;
}

bool variable::operator!=(variable v) {

	if ((*this).getType() == v.getType() && v.getType() == N)
		return  (*this).getNumber() != v.getNumber();
	else if ((*this).getType() == v.getType() && v.getType() == W)
		return  (*this).getWord() != v.getWord();
	else if ((*this).getType() == v.getType() && v.getType() == B)
		return  (*this).getBoolean() != v.getBoolean();
	else
		return false;
}

bool variable::operator>=(variable v) {

	if ((*this).getType() == v.getType() && v.getType() == N)
		return  (*this).getNumber() >= v.getNumber();
	else if ((*this).getType() == v.getType() && v.getType() == W)
		return  (*this).getWord() >= v.getWord();
	else if ((*this).getType() == v.getType() && v.getType() == B)
		return  (*this).getBoolean() >= v.getBoolean();
	else
		return false;
}

bool variable::operator<=(variable v) {

	if ((*this).getType() == v.getType() && v.getType() == N)
		return  (*this).getNumber() <= v.getNumber();
	else if ((*this).getType() == v.getType() && v.getType() == W)
		return  (*this).getWord() <= v.getWord();
	else if ((*this).getType() == v.getType() && v.getType() == B)
		return  (*this).getBoolean() <= v.getBoolean();
	else
		return false;
}

bool variable::operator<(variable v) {

	if ((*this).getType() == v.getType() && v.getType() == N)
		return  (*this).getNumber() < v.getNumber();
	else if ((*this).getType() == v.getType() && v.getType() == W)
		return  (*this).getWord() < v.getWord();
	else if ((*this).getType() == v.getType() && v.getType() == B)
		return  (*this).getBoolean() < v.getBoolean();
	else
		return false;
}

bool variable::operator>(variable v) {

	if ((*this).getType() == v.getType() && v.getType() == N)
		return  (*this).getNumber() > v.getNumber();
	else if ((*this).getType() == v.getType() && v.getType() == W)
		return  (*this).getWord() > v.getWord();
	else if ((*this).getType() == v.getType() && v.getType() == B)
		return  (*this).getBoolean() > v.getBoolean();
	else
		return false;
}



variable variable::operator,(variable v)
{
	ss.setType(S);
	if (ss.bucket.size() == 0)
	{
		ss.bucket.push_back(*this);
		ss.bucket.push_back(v);
	}
	else
	{
		ss.bucket.push_back(v);
	}

	return ss;
}

variable variable::operator=(variable v)
{
	if(ss.getType() == L)
	{
		ss.bucket.clear();
	}
	else if(ss.getType() == S)
	{

		for(auto i : ss.bucket)
		{
			if(i.getType() != W)
			{
				cout << "Error: Sentence must have only words."<<endl;
				v.bucket.clear();
			}
		}
		ss.bucket.clear();
	}

	if(v.getType() == N && (*this).getType() == N)
	{
		(*this).setNumber(v.getNumber());
		return (*this);
	}
	if(v.getType() == W && (*this).getType() == W)
	{
		(*this).setWord(v.getWord());
		return (*this);
	}
	if(v.getType() == B && (*this).getType() == B)
	{
		(*this).setBoolean(v.getBoolean());
		return (*this);
	}
	if(v.getType() == L && (*this).getType() == L)
	{
		(*this).bucket.clear();
		for(auto i : v.bucket)
		(*this).bucket.push_back(i);
		return (*this);
	}
	//ADD FOR ARRAY AND SENTENCE
	return v;
}

variable variable::operator[](variable v) {
	(*this).setType(L);
	return *this;

}

bool not_func(bool x)
{
	if(x == TRUE){return FALSE;}
	else{return TRUE;}
}
//AND + OR implemented in LOGO.h

//Helper function for print. Isos ginei allagi sto PRINT 'h SHOW
void output(variable v)
{
	if( v.getType() == L)
	{
		for(auto i : v.bucket)
		{
			if(i.getType() == W)
			{
				cout << "-->List item: "<< i.getWord() << endl;
			}
			else if(i.getType() == N)
			{
					cout << "-->List item: "<< i.getNumber() << endl;
			}
			else if(i.getType() == B)
			{
				cout << "-->List item: "<< i.getBoolean() << endl;
			}
			else if(i.getType() == L || i.getType() == A || i.getType() == S)
			{
				output(i);
			}
		}
	}
	else if(v.getType() == S )
	{
		for(auto i : v.bucket)
		{
			if(i.getType() == W)
			{
				cout << "-->Sentence item: "<< i.getWord() << endl;
			}
			else if(i.getType() == N)
			{
					cout << "-->Sentence item: "<< i.getNumber() << endl;
			}
			else if(i.getType() == B)
			{
				cout << "-->Sentence item: "<< i.getBoolean() << endl;
			}
			else if(i.getType() == L || i.getType() == A || i.getType() == S)
			{
				output(i);
			}
		}
	}
	else if(v.getType() == A )
	{
		for(auto i : v.bucket)
		{
			if(i.getType() == W)
			{
				cout << "-->Array item: "<< i.getWord() << endl;
			}
			else if(i.getType() == N)
			{
					cout << "-->Array item: "<< i.getNumber() << endl;
			}
			else if(i.getType() == B)
			{
				cout << "-->Array item: "<< i.getBoolean() << endl;
			}
			else if(i.getType() == L || i.getType() == A || i.getType() == S)
			{
				output(i);
			}
		}
	}
	else if(v.getType() == W)
	{
		cout << "-->Variable: "<< v.getWord() << endl;
	}
	else if(v.getType() == N)
	{
		cout << "-->Variable: "<< v.getNumber() << endl;
	}
	else if(v.getType() == B)
	{
		cout << "-->Variable: "<< v.getBoolean() << endl;
	}
	else
	{
			cout << "Error printing variable" <<endl;
	}
}

//Set and get
type variable::getType() const {
	return t;
}

void variable::setType(type t) {
	variable::t = t;
}

int variable::getNumber() const {
	return number;
}

void variable::setNumber(int n) {
	variable::number = n;
}

string variable::getWord() const {
	return word;
}
void variable::setWord(string s) {
	variable::word = s;
}

bool variable::getBoolean() const {
	return boolean;
}

void variable::setBoolean(bool b) {
	variable::t = t;
}


variable get_item(initializer_list<int> list, variable v)
{
	variable tmp;
	int tmp_count=0;

	if(v.getType() == S || v.getType() == L || v.getType() == A)
	{
		for(auto i : list)
		{
			tmp_count++;
			if(v.bucket.size() > i-1)
			{
				std::list<variable>::iterator it = v.bucket.begin();
				std::advance(it, i-1);
				tmp.bucket.push_back(*it);
			}
		}
		if(tmp_count > 1)
		{
			tmp.setType(L);
		}
		return tmp;
	}
	else
	{
			cout << "Error: cannot get index from regular variables."<<endl;
			return v;
	}
}

void set_func(std::vector<int>::iterator& glob, variable& set, variable value)
{
		cout <<"INSIDE\n";
		if(glob != glob_list.end())
		{
			std::list<variable>::iterator it = set.bucket.begin();
			std::advance(it, (*glob)-1);
			if(set.getType() == L || set.getType() == A || set.getType() == S)
			advance(glob, 1);
			set_func(glob, (*it), value);
		}
		else
		{
			switch (value.getType())
			{
				case 0:
				set.setWord(value.getWord());
				set.setType(W);
				cout << "case0\n";
				break;
				case 1:
				set.setNumber(value.getNumber());
				set.setType(N);
				cout << "case1\n";
				break;
				case 2:
				set.setBoolean(value.getBoolean());
				set.setType(B);
				cout << "case2\n";
				break;
				case 3:
				for(auto i : value.bucket)
				{
					set.bucket.push_back(i);
					set.setType(L);
				}
				cout << "case3\n";
				break;
				case 4:
				for(auto i : value.bucket)
				{
					set.bucket.push_back(i);
					set.setType(A);
				}
				//cout << "case4\n";
				break;
				case 5:
				for(auto i : value.bucket)
				{
					set.bucket.push_back(i);
					set.setType(S);
				}
				//cout << "case5\n";
				break;
				default:
				cout << "Error: Wrong type"<<endl;
			}
		}


		/*switch (value.getType())
		{
			case 0:
			if(glob != glob_list.end())
			{
				advance(glob, 1);
				set_func(glob, (*it), value);
			}

				(*it).setWord(value.getWord());
				(*it).setType(W);



			cout << "case0\n";
			break;
			case 1:
			//(*it) = value;
			if(glob != glob_list.end())
			{
				advance(glob, 1);
				set_func(glob, (*it), value);
			}

			(*it).setNumber(value.getNumber());
			(*it).setType(N);
			cout << "case1\n";
			break;
			case 2:
			//(*it) = value;
			if(glob != glob_list.end())
			{
				advance(glob, 1);
				set_func(glob, (*it), value);
			}
			(*it).setBoolean(value.getBoolean());
			(*it).setType(B);
			cout << "case2\n";
			break;
			case 3:
			if(glob != glob_list.end())
			{
				advance(glob, 1);
				set_func(glob, (*it), value);
			}
			//flag++;
			//(*it) = value;

			cout << "case3\n";
			break;
			case 4:
			if(glob != glob_list.end())
			{
				advance(glob, 1);
				set_func(glob, (*it), value);
			}

			(*it) = value;

			//cout << "case4\n";
			break;
			case 5:
			if(glob != glob_list.end())
			{
				advance(glob, 1);
				set_func(glob, (*it), value);
			}

			(*it) = value;

			//cout << "case5\n";
			break;
			default:
			cout << "Error: Wrong type"<<endl;
		}*/
		//if(flag == 1)
		//(*it) = value;
	//}
}

void set_item(initializer_list<int> list, variable& set, variable value)
{
	if(set.getType() == S || set.getType() == L || set.getType() == A)
	{
		for(auto i : list)
		{
			glob_list.push_back(i);
		}
		std::vector<int>::iterator glob = glob_list.begin();
		set_func(glob, set, value);
		glob_list.clear();
	}
}
