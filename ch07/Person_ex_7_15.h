#include<iostream>
#include<string>
using namespace std;

struct Person{
	   
		string name;
		string address;

		Person() = default;
		Person(const string n):name(n){}
		Person(const string n, const string a):name(n),address(a){}
		Person(istream&);
	    
	    string get_name() const
		{
			return name;
		}
		string get_address() const
		{
			return address;
		}
};

istream &read(istream &in, Person &person)
{
	in>>person.name>>person.address;
	return in;
}

ostream &print(ostream &out, const Person &person)
{
	out<<person.name<<" "<<person.address;
	return out;
}

Person::Person(istream &in)
{
	read(in, *this);
}