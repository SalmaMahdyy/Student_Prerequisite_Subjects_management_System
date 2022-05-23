#pragma once
#include <string>
#include "Course.h"
#include <vector>
#include<iostream>
#include<queue>
#include "Student.h"
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include "Admin.h"
using namespace std;
int main() {
	int inp , t=1,check = 0;
	int choose1, choose2, choose3;
	Admin a;
	Student b;
	do
	{
		cout << "Enter 1 if you are an Admin\n" << "Enter 2 if you are a student\n" << "Enter 3 if you want to register \n";
		cin >> inp;
		switch (inp) {

		case 1:
			a.login_admin();
			while (t == 1) {
				cout << "For adding course press 1 \n";
				cout << "For adding new student press 2 \n";
				cout << "For editing course data press 3 \n";
				cout << "For viewing courses of a specific student press 4 \n";
				cout << "For viewing students in specific course press 5 \n";
				cin >> choose3;
				if (choose3 == 1) {
					a.add_cource();
				}
				else if (choose3 == 2) {
					a.add_new_student();
				}
				else if (choose3 == 3) {
					a.edit_course_data();
				}
				else if (choose3 == 4) {
					a.ViewCoursesOfStudent();
				}
				else if (choose3 == 5) {
					a.view_students_in_a_specific_course();
				}
				else {
					cout << "You entered a wrong number\n";
				}
				cout << "To return back to admin finctionalities press 1\n";
				cin >> t;
			}
			break;

		case 2:
			b.login();
			while (t == 1) {
				cout << " If you want to view available courses press 1\n";
				cout << " If you want to register to a course press 2 \n";
				cout << " If you want to view your courses press 3 \n";
				cout << " If you want to details of a specific course press 4 \n";
				cin >> choose1;
				if (choose1 == 1) {
					b.available_courses(2);
				}
				else if (choose1 == 2) {
					b.registercourse(555, "archi");
				}
				else if (choose1 == 3) {
					b.view_all_courses(2);
				}
				else if (choose1 == 4) {
					b.view_details_of_specific_course();
				}
				else if (choose1 == 5) {
					b.edit_student_data();
				}
				else {
					cout << " You entered wrong number\n";
				}
				cout << " To return back press to student functionalities 1\n";
				cin >> t;
			}
			break;
		case 3:
			b.registr();
			break;

		}
		cout << " If you want to exit press 6 the program , If you want to continue press 0 " << endl;
		cin >> check;
		if(check==6)
			return 0;


	} while (check != 6);


	return 0;
}