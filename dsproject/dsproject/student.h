#pragma once
#include <string>
#include "Course.h"
#include <vector>
#include<iostream>

using namespace std;

class Student
{


public:
	int password;
	int id;
	vector<Student>s;  //for add//
	string name;
	//vector<Student> student;
	vector <string> FinishedCourses;
	vector <string> CourseInProgress;
	int academic_year;
	int getid();
	void setid(int id);
	void login();
	void registr();
	vector<string>available_courses(int);
	void edit_student_data();
	Student();
	~Student();
	void registercourse(int , string );
	void view_all_courses(int);
	void view_details_of_specific_course();
};