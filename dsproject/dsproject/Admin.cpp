#include "Admin.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;


void Admin::add_new_student()
{

	int n = -1;
	do {
		cout << "enter 1 to student data" << endl;
		cout << "enter 2 to exit" << endl;

		cin >> n;
		Student student;
		fstream file;

		if (n == 1)
		{
			cout << "student name" << endl;
			cin >> student.name;
			cout << "password" << endl;
			cin >> student.password;
			cout << "student id" << endl;
			cin >> student.id;
			cout << "academic year" << endl;
			cin >> student.academic_year;
			student.s.push_back(student);
			file.open("addStudent.txt", ios::app | ios::out);
			file << student.name << endl << student.id << endl<<student.password << student.academic_year << endl;
			file.close();

		}

	} while (n != 2);

}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Admin::add_cource()
{
	int input;

	fstream file;

	cout << "press 1 to add new cource" << endl;
	cout << "press 0 to exit" << endl;
	cin >> input;
	string add;
	int i = 0;


	while (input != 0) {

		cout << "Enter Name Of Course : " << endl;
		cin >> c.name;
		cout << "Enter Code Of Course : " << endl;
		cin >> c.code;
		cout << "Enter Muximum Number Of Student : " << endl;
		cin >> c.max_num_students;
		addPreOfEachCourse();
		cout << "Enter Hourse Of Course : " << endl;
		cin >> c.hours;
		courses.push_back(c);

		cout << "press 1 to add new cource" << endl;
		cout << "press 0 to exit" << endl;
		cin >> input;
		i++;
		file.open("AddCourse.txt", ios::app | ios::out);
		file << " name " << " : " << c.name << endl << " code " << " : " << c.code << endl << " Muximum Number Of Student " << " : " << c.max_num_students << endl << " Hours Of Course " << " : " << c.hours << endl << "pre_name"<< " : " << c.list_of_prerequired << " " << endl;
		file.close();
	}
}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Admin::edit_course_data()
{
	fstream file, file1;
	int isFound = 0;
	cout << "enter course code " << endl;
	string courseCode;
	file.open("AddCourse.txt", ios::in);

	if (!file) {
		cout << "no courses to edit" << endl;
	}
	else {
		cin >> courseCode;
		file1.open("AddCourseEdit.txt", ios::app | ios::out);
		file << " name " << " : " << c.name << endl << " code " << " : " << c.code << endl << " Muximum Number Of Student " << " : " << c.max_num_students << endl << " Hours Of Course " << " : " << c.hours << endl << "pre_name" << " : " << c.list_of_prerequired << " " << endl;
		while (!file.eof()) {
			if (courseCode != c.code) {
				file1 << " name " << " : " << c.name << endl << " code " << " : " << c.code << endl << " Muximum Number Of Student " << " : " << c.max_num_students << endl << " Hours Of Course " << " : " << c.hours << endl << "pre_name" << " : " << c.list_of_prerequired << " " << endl;
			}
			else {
				cout << "Enter Name Of Course : " << endl;
				cin >> c.name;
				cout << "Enter Code Of Course : " << endl;
				cin >> c.code;
				cout << "Enter Muximum Number Of Student : " << endl;
				cin >> c.max_num_students;
				cout << "Enter Pre_required Course : " << endl;
				addPreOfEachCourse();
				cout << "Enter Hours Of Course : " << endl;
				cin >> c.hours;
				file1 << " name " << " : " << c.name << endl << " code " << " : " << c.code << endl << " Muximum Number Of Student " << " : " << c.max_num_students << endl << " Hours Of Course " << " : " << c.hours << endl << "pre_name" << " : " << c.list_of_prerequired << " " << endl;
				isFound++;
				file1.close();
				file.close();
				remove("AddCourse.txt");
				rename("AddCourseEdit.txt", "AddCourse.txt");

				break;
			}
			file << " name " << " : " << c.name << endl << " code " << " : " << c.code << endl << " Muximum Number Of Student " << " : " << c.max_num_students << endl << " Hours Of Course " << " : " << c.hours << endl << "pre_name" << " : " << c.list_of_prerequired << " " << endl;
			if (isFound == 0) {
				cout << "course's not found" << endl;
				break;
			}

		}
	}





	/*string course_code;
	cout << "enter the course code" << endl;
	cin >> course_code;
	if (courses.size() == 0) {
		cout << "no courses to edit" << endl;
	}
	bool isNotFound = true;
	while (isNotFound && courses.size() > 0) {

		if (c.code == course_code) {
			int maxStudentNum, courseHours;
			string coursePrerequired;
			fstream file;
			for (int i = 0; i < courses.size(); i++) {
				cout << "Enter Muximum Number Of Student : " << endl;
				cin >> maxStudentNum;
				courses[i].max_num_students = maxStudentNum;
				cout << "Enter Pre_required Course : " << endl;
				cin >> coursePrerequired;
				courses[i].list_of_prerequired = coursePrerequired;
				cout << "Enter Hours Of Course : " << endl;
				cin >> courseHours;
				courses[i].hours = courseHours;

				isNotFound = false;

				file.open("AddCourse.txt", ios::app | ios::trunc );
				file << " Muximum Number Of Student " << maxStudentNum << endl << " Hours Of Course " << courseHours << endl << "prerequired courses" << " " << coursePrerequired << endl;
				file.close();
			}
		}
		if (c.code != course_code) {
			cout << "course is not found" << endl;

		}
	}*/
}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Admin::login_admin()
{
	Admin a;
	int coun = 0;
	string a_name;
	int a_pass;
	int t = 1;
	do {
		cout << "please enter the following details" << endl;
		cout << "USERNAME :";
		cin >> a.name;
		cout << "PASSWORD :";
		cin >> a.password;

		ifstream input("admin.txt");
		while (input >> a_name >> a_pass)
		{
			if (a_name == a.name && a_pass == a.password)

			{
				coun = 1;

			}
		}
		input.close();
		if (coun == 1)
		{
			cout << "\nHello LOGIN SUCESS\n";
			cin.get();
			cin.get();

		}
		else
		{
			cout << "\nLOGIN ERROR\n";
		}
	} while (coun == 0);
}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Admin::addPreOfEachCourse()
{
	fstream file;
	string Name;
	int check = -1;
	do
	{
		cout << " If you want add prerequisite press 1 " << endl;
		cout << " If you want to exit press 0" << endl;
		cin >> check;

		if (check == 1)
		{
			cout << "please enter the name and the code of this course " << endl;
			cout << "course name is : ";
			cin >> Name;

			c.pre.push_back(Name);
			c.list_of_prerequired = Name;
		}

	} while (check != 0);

}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Admin::ViewCoursesOfStudent()
{
	vector <Student> s;
	int searching;
	bool exist = false;
	cout << "Enter id of the student" << endl;
	cin >> searching;
	//fstream file;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].getid() == searching) {
			exist = true;
			int count1 = s[i].FinishedCourses.size();
			for (int j = 0; j < count1; j++) {

				cout << " student's finished courses are :" << endl;
				//file.open("addStudent.txt", ios::app | ios::in);
				cout << " " << s[i].FinishedCourses[j] << endl;
				//file.close();
			}
			int count2 = s[i].CourseInProgress.size();
			for (int n = 0; n < count1; n++) {
				cout << " student's finished courses are :" << endl;
				//file.open("addStudent.txt", ios::app | ios::in);
				cout << " " << s[i].CourseInProgress[n] << endl;
			//	file.close();
			}
		}
	} 
	if (!exist) {
		cout << "Student is not found \n";
	}
}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Admin::view_students_in_a_specific_course()
{
	Student s;
	cout << " VIEW LIST OF ALL STUDENTS IN A SPECIFIC COURSE. \n";
	string search;
	cout << " Enter the course name : ";
	cin >> search;
	cout << " students : \n";
	for (int i = 0; i < s.s.size(); i++)
	{
		int count_progress = s.s[i].CourseInProgress.size();
		for (int j = 0; j < count_progress; j++)
		{
			if (s.s[i].CourseInProgress[j] == search)
			{
				cout << s.s[i].name << "\n";
			}
		}
	}
}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
Admin::Admin()
{

}
Admin::Admin(string n)
{
	name = n;
}
Admin::~Admin()
{

}