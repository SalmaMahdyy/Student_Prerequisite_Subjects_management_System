#pragma once
#include "Student.h"
#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include<queue>
#include <vector>

using namespace std;
class Admin
{


public:
	string name;
	int password;
    vector <course> courses;
	course c;
	void ViewCoursesOfStudent();
	void add_new_student();
	void add_cource();
	void edit_course_data();
	void login_admin();
	void view_students_in_a_specific_course();
	void addPreOfEachCourse();
	Admin();
	Admin(string n);
	~Admin();
};