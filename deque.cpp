#include <iostream>

using namespace std;

struct Cvector
{	
	int* ini_vector;
	int* vector;
	int* fin_vector;
	Cvector() {
		vector = new int[5];		
		fin_vector = vector;
		ini_vector = fin_vector;
	};

	bool push_back(int);
	bool push_front(int);
	bool pop_back();
	bool pop_front();
	void print();

};



bool Cvector::push_back(int data) {
	if (fin_vector - vector > 4)
	{
		return true;         // lleno, crea vector
	}
	*fin_vector = data;
	fin_vector++;
	return false;
}

bool Cvector::pop_back() {
	fin_vector--;
	*fin_vector = -87845612;
	if (fin_vector == vector)
	{
		return true;
	}	
	return false;
}

bool Cvector::push_front(int data) {
	if (ini_vector == vector)
	{
		return true;         // lleno, crea vector
	}
	*(ini_vector-1) = data;
	ini_vector--;
	return false;
}

bool Cvector::pop_front() {
	*ini_vector = -87845612;
	ini_vector++;
	if (ini_vector == fin_vector)
	{
		return true;
	}
	return false;
}

class Cdeque
{
public:

	Cvector** ini_deque;
	Cvector** fin_deque;
	Cvector** deque;


	Cdeque() {
		deque = new Cvector * [5];
		fin_deque = deque+2;
		ini_deque = fin_deque;
		*fin_deque = new Cvector();
		(*fin_deque)->fin_vector = (*fin_deque)->fin_vector+2;
		(*fin_deque)->ini_vector = (*fin_deque)->fin_vector;
	};

	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void print();
	int& operator[](int);
};

int& Cdeque::operator[](int id) {
    int dif = (*ini_deque)->ini_vector - (*ini_deque)->vector;
	id = id + dif;
	return (*(ini_deque + (id / 5)))->vector[id % 5];
}



void Cdeque::push_back(int data) {
	if ((*fin_deque)->push_back(data))    //lleno, crea vector
	{
		fin_deque++;
		*fin_deque = new Cvector();
		(*fin_deque)->push_back(data);
	}
	
}

void Cdeque::pop_back() {
	if ((*fin_deque)->pop_back())    //lleno, crea vector
	{
		fin_deque--;
	}
}

void Cdeque::push_front(int data) {
	if ((*ini_deque)->push_front(data))    //lleno, crea vector
	{
		ini_deque--;
		*ini_deque = new Cvector();
		(*ini_deque)->fin_vector = (*ini_deque)->vector+5;
		(*ini_deque)->ini_vector = (*ini_deque)->fin_vector;
		(*ini_deque)->push_front(data);
	}
	
}

void Cdeque::pop_front() {
	if ((*ini_deque)->pop_front())    //lleno, crea vector
	{
		ini_deque++;
	}
}




int main() {
	Cdeque deque;

	for (int i = 1; i < 10; i++)
	{
		deque.push_back(i);
	}
	for (int i = -1; i > -10; i--)
	{
		deque.push_front(i);
	}
	for (int i = 0; i < 3; i++)
	{
		deque.pop_back();
		deque.pop_front();
	}

	deque.print();
	int id = 4;
	cout << endl<<"deque[" << id << "] = " << deque[id] << endl;

	return 0;
}


void Cvector::print() {
	cout << "[";
	for (int i = 0; i < 5; i++)
	{
		cout << vector[i] << ", ";
	}
	cout << "] - ";
}

void Cdeque::print() {
	for (Cvector** ptr = ini_deque; ptr <= fin_deque; ++ptr) {
		(*ptr)->print();
	}
}