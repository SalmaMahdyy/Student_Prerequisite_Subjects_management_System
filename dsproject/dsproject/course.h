#pragma once
#include <string>
#include <vector>
#include<iostream>

using namespace std;

class course
{
public:
	string name, code;
	int hours, max_num_students;
	string list_of_prerequired;
	vector<string> pre;

	string getname();
	string getcode();
	string get_prerequiredcourse(int);
	course();
	~course();



};