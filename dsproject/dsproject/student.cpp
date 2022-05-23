#include "Student.h"
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include "Admin.h"

void Student::login()
{
	Student s;
	int count = 0;
	string s_name;
	int s_pass;
	do {
		cout << "please enter the following details" << endl;
		cout << "USERNAME :";
		cin >> s.name;
		cout << "PASSWORD :";
		cin >> s.password;
		ifstream input("addStudent.txt");
		while (input >> s_name >> s_pass)
		{
			if (s_name == s.name && s_pass == s.password)

			{
				count = 1;

			}
		}
		input.close();
		if (count == 1)
		{
			cout << "\nHello LOGIN SUCESS \n";
			cin.get();
			cin.get();

		}
		else
		{
			cout << "\nLOGIN ERROR \n";
		}
	} while (count == 0);

}

/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/

void Student::registr()
{
	Student s;
	cout << "Enter the username :";
	cin >> s.name;
	cout << "\nEnter the password :";
	cin >> s.password;
	cout << "\n Enter ID :";
	cin >> s.id;
	ofstream reg("addStudent.txt", ios::app);
	reg << s.name << endl << s.password << endl<<s.id << endl;

	cout << "\nRegistration Sucessful\n";

}

/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
vector<string>Student::available_courses(int Id)
{
	Admin a;
	vector<string>availablecourses;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].id == Id)
		{



			for (int k = 0; k < a.courses.size(); k++)
			{
				bool flag2 = true;
				bool flag1 = false;
				for (int q = 0; q < s[i].FinishedCourses.size(); q++)
				{
					if (s[i].FinishedCourses[q] == a.courses[k].getname())
					{
						flag2 = false;
						break;
					}
				}

				for (int q = 0; q < s[i].CourseInProgress.size(); q++)
				{
					if (s[i].CourseInProgress[q] == a.courses[k].getname())
					{
						flag2 = false;
						break;
					}

				}


				int t = 0;
				for (int z = 0; z < s.size(); z++)
				{
					for (int y = 0; y < s[z].CourseInProgress.size(); y++)
					{
						if (s[z].CourseInProgress[y] == a.courses[k].getname())
							t++;
					}

				}
				if (a.courses[k].max_num_students <= t)
					flag2 = false;
				if (flag2 == false)
					continue;
				int l = a.courses[k].pre.size();
				int o = s[i].FinishedCourses.size();
				for (int p = 0; p < l; p++)
				{
					flag1 = false;

					for (int e = 0; e < o; e++)
					{
						if (a.courses[k].pre[p] == s[i].FinishedCourses[e])
						{
							flag1 = true;
							break;
						}

					}
					if (flag1 == false)
						break;
				}
				if (flag1 == true)
				{
					cout << a.courses[k].getname();
					availablecourses.push_back(a.courses[k].name);
				}
			}

			break;
		}

	}
	return availablecourses;
}

/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/

void Student::edit_student_data()
{
	fstream file, file1;
	int isFound = 0;
	Student student;
	cout << "enter your id " << endl;
	int studId;
	file.open("addstudent.txt", ios::in);

	if (!file) {
		cout << "no student to edit" << endl;
	}
	else {
		cin >> studId;
		file1.open("addStudentEdit.txt", ios::app | ios::out);
		file << student.name << endl << student.id << endl << student.password << endl << student.academic_year << endl;
		while (!file.eof()) {
			if (studId != student.id) {
				file1 << student.name << endl << student.id << endl << student.password << endl << student.academic_year << endl;
			}
			else {
				cout << "student name" << endl;
				cin >> student.name;
				cout << "password" << endl;
				cin >> student.password;
				cout << "student id" << endl;
				cin >> student.id;
				cout << "academic year" << endl;
				cin >> student.academic_year;
				file1 << student.name << endl << student.id << endl << student.password << endl << student.academic_year << endl;
				isFound++;
				file1.close();
				file.close();
				remove("addStudent.txt");
				rename("addStudentEdit.txt", "addStudent.txt");

				break;
			}
			file << student.name << endl << student.id << endl << student.password << endl << student.academic_year << endl;
			if (isFound == 0) {
				cout << "student's not found" << endl;
				break;
			}

		}
	}

}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/

void Student::registercourse(int studid, string cname)
{
	vector<string>r = available_courses(studid);
	for (int i = 0; i < s.size(); i++)
	{
		if (r[i] == cname)
		{
			for (int j = 0; j < s.size(); j++) {
				if (s[j].id == studid) {
					s[j].CourseInProgress.push_back(cname);
					fstream myfile;
					myfile.open("addStudent.txt", ios::out);
					myfile.close();
					myfile.open("addStudent.txt", ios::app | ios::out);
					if (myfile.is_open()) {
						for (int n = 0; n < s.size(); n++) {
							myfile << s[n].name << ",";
							myfile << s[n].id << ",";
							myfile << s[n].password << ",";
							myfile << s[n].academic_year << ",";
							for (int k = 0; k < s[n].FinishedCourses.size(); k++) {
								myfile << s[n].FinishedCourses[k] << ":";
							}
							myfile << ",";
							for (int k = 0; k <s[n].CourseInProgress.size(); k++) {
								myfile << s[n].CourseInProgress[k] << "/";
							}
							myfile << endl;
						}

						myfile.close();
					}

					break;
				}
			}
			break;
		}
	}
	cout << "DONE" << endl;
}

/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/

void Student::view_all_courses(int id)
{
	int view;
	cout << "Enter your id" << endl;
	cin >> view;
	for (int i = 0; i < Student::s.size(); i++)
	{
		for (int j = 0; j < Student::s[i].FinishedCourses.size(); j++)
		{
			if (Student::s[i].id == view)
			{
				cout << "Your finished courses are :" << endl;
				cout << Student::s[i].FinishedCourses[j] << endl;
			}
			else
			{
				cout << "error";
			} //showed finished courses llstudent
		}

	}
	for (int a = 0; a > Student::s.size(); a++)
	{
		for (int b = 0; b < Student::s[a].CourseInProgress.size(); b++)
		{
			if (Student::s[a].id == view)
			{
				cout << "Your courses in progress are :" << endl;
				cout << Student::s[a].CourseInProgress[b];
			}
			else
			{
				cout << "error";
			}
			break;
		} //showed courses in progress
	}
}
/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
void Student::view_details_of_specific_course()
{
	string n;
	cout << "Enter name of course:" << endl;
	cin >> n;
	Admin a;
	for (int i = 0; i < a.courses.size(); i++)
	{
		if (a.courses[i].name == n)
		{
			cout << "\n the name is:";
			cout << a.courses[i].getname();

			cout << "\n the code is:";
			cout << a.courses[i].getcode();

			cout << "\n the number of student";
			cout << a.courses[i].max_num_students;

			cout << "\n the hours are:";
			cout << a.courses[i].hours;

			for (int j = 0; j < a.courses[i].list_of_prerequired.size(); j++)
			{
				cout << "\n the prerequired list is";
				cout << a.courses[i].get_prerequiredcourse(j) << endl;
			}
		}
	}
}

/***********************************************************************************************************************
***********************************************************************************************************************
***********************************************************************************************************************/
Student::~Student(void)
{

}
int Student::getid()
{
	return id;
}
void Student::setid(int id)
{
	this->id = id;
}
Student::Student()
{

}