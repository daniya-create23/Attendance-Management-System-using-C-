#define _CRT_SECURE_NO_WARNINGS /*definition of all the colour ranges added in the program*/
#define RED     "\033[31m"      /* Red */ 
#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define MAGENTA "\033[35m"      /* Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define CYAN    "\033[36m" 
#include <iostream>
using namespace std;
#include <string>
#include <windows.h> // header file for declarations for all of the functions in the Windows API
#include <ctime> //library for inclusive live time 
class attendance //oop class
{
private: //access modifier

		 /*declaration of all the possible class members*/
	string name[100];
	string username[100];
	string password1[100];
	string password2[100];
	string rollno[100];
public:
	char attend[100][100][100];

	int m[100], l[100], u[100], m1[100], l1[100], u1[100], q[100];

	friend class attendance_management; //friend class to access private and protected members

};

class attendance_management
{
	attendance p; //constructor
public: //access modifier
	int o = 0; //initialization
	void virtual start() = 0;//virtual void function for dynamic linking

							 /*FUNCTION DECLARATION WITH DIFFERENT PARAMETERS*/
	void student_present(int k);
	void display();
	void login();
	void adminview();
	void present();
	void upgrade_attendance(int s);
	int i[100];
	double q;
	void studentview(int z);

};
class system_managemnt : public attendance_management //derived class from the base class system management
{
public:
	char a;
	void start()
	{

		/* USE OF ASTERISK FOR PROPER DISPLAY*/

		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
		cout << "************************************\n";
		cout << "\t\t\t\t\t";
		cout << "* Welcome to Attendance Management *\n";
		cout << "\t\t\t\t\t";
		cout << "* Choose the folowing:             *" << endl;
		cout << "\t\t\t\t\t";
		cout << "* 1.Register an account            *" << endl;
		cout << "\t\t\t\t\t";
		cout << "* 2.Sign in                        *" << endl;
		cout << "\t\t\t\t\t";
		cout << "************************************\n";

	}
};

void attendance_management::display() //function definition using scope resolution
{

	system("CLS"); //clears the previous outputs on the screen
	cin.ignore();


	cout << "***********************\n";
	cout << "*Full Name*\n";
	while (true) //loop for continues working
	{
		string* ptr = &p.name[o]; //use of string as pointer 
		getline(cin, *ptr);
		if (p.name[o] == "") //decision statement
		{

			cout << RED << "Please enter a Valid Name" << RESET << endl; // output is in red colour

		}
		else
		{
			break;
		}
	}
	cout << "***********************\n";
	Sleep(1300); // delays the output/ suspends execution 
	system("CLS");
	cout << "***********************\n";
	cout << "*Roll number*\n";
	string* ptr1 = &p.rollno[o]; //string pointer
	while (true) // loop for continous running 
	{

		getline(cin, *ptr1); //takes input from the user
		if (*ptr1 == "") //condition statement
		{
			cout << RED << "Please enter a valid rollnumber" << RESET << endl; //prints the output in red
		}
		else
		{
			break;
		}

	}

	for (int v = 1; v <= o; v++)
	{
		if ((*ptr1) == p.rollno[v - 1] && v > 0)
		{
			cout << RED << "THE ENTERED ROLLNUMBER ALREADY EXISTS, PLEASE TRY AGAIN.\n" << RESET;
			getline(cin, *ptr1);
			v--;
		}

	}


	cout << "***********************\n";
	Sleep(1300); //delays the execution of the program
	system("CLS");
	cout << "***********************\n";
	cout << "*Username" << RED << "(without space and should be of atleast 8 characters)" << RESET << "*\n"; //prints the output in red
	string* ptr2 = &p.username[o]; //string pointer
	while (true) //loop for continuous running
	{
		string* ptr2 = &p.username[o]; //string pointer
		getline(cin, *ptr2); //takes input
		if (*ptr2 == "" || (*ptr2).length() < 8 || (*ptr2).find(" ") != string::npos) //condition statement that runs if it is true
		{
			cout << RED << "Please enter a valid username, should be of atleast 8 characters and should not contain spaces !" << RESET << endl;
		}
		else
		{
			break;
		}
	}

	for (int k = 1; k <= o; k++)
	{

		if ((*ptr2) == p.username[k - 1] && k > 0) // condition statement if this is true it executes
		{

			cout << RED << "THIS USERNAME ALREADY EXISTS " << RESET << endl; //output is in red
			getline(cin, *ptr2); //takes input
			k--;
			if (*ptr2 == "" || (*ptr2).length() < 8 || (*ptr2).find(" ") != string::npos) //condition statement that runs if it is true
			{
				cout << RED << "Please enter a valid username, should be of atleast 8 characters and should not contain spaces !" << RESET << endl;
				getline(cin, *ptr2); //takes input
			}
		}

	}

	cout << "***********************\n";
	Sleep(1300); //delayes execution when the program runs
	system("CLS");

	cout << "***********************\n";
	cout << "*Password " << RED << "(should be of atleast 8 characters)" << RESET << "*\n"; //output is in red
	while (true)
	{
		string* ptr3 = &p.password1[o]; //string pointer
		getline(cin, *ptr3);
		if (*ptr3 == "" || (*ptr3).length() < 8) // this block of code executes if this true
		{

			cout << RED << "Please enter a strong password , should be of atleast 8 characters!" << RESET << endl; // prints in red

		}
		else
		{
			break;
		}
	}

	cout << "*Please re-enter your password*\n";
	while (true) //runs if condition is true
	{
		string* ptr4 = &p.password2[o]; //string pointer
		getline(cin, *ptr4); //takes input from the user

		if (p.password1[o] == *ptr4) // decision statement runs if it is true
		{
			/* displays on the console if this is true*/

			cout << "***********************\n";
			Sleep(1300);
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
			cout << "*****************************************************\n";
			cout << "\n\t\t\t\t\t";
			cout << "      ACCOUNT HAS BEEN SUCCESSFULLY RESGISTERED!    " << endl;
			cout << "\t\t\t\t\t";
			cout << "      FULLNAME: " << p.name[o] << endl;
			cout << "\t\t\t\t\t";
			cout << "      ROLL NUMBER: " << p.rollno[o] << endl;
			cout << "\t\t\t\t\t";
			cout << "      USERNAME:" << p.username[o] << endl;
			cout << "\t\t\t\t\t";
			cout << "      PASSWORD:" << p.password1[o] << endl;
			o++;
			cout << "\n\t\t\t\t\t";
			cout << "*****************************************************\n";

			break; // exits block of code after successful execution

		}
		else
		{

			cout << RED << "Passwords doesn't match. Please try again!" << RESET << "\n ";
		}
	}

	getchar();
	system("cls");
}
void attendance_management::login() //definition of function using scope resolution operator
{

	int h = o;
	while (true) //if this condition is true following block of code executes
	{
		system("CLS");

		/* displays the log in option on the console*/

		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
		cout << "****************\n";
		cout << "\t\t\t\t\t* LOG IN AS    *\n";
		cout << "\t\t\t\t\t* 1-STUDENT    *\n";
		cout << "\t\t\t\t\t* 2-ADMIN      *\n";
		cout << "\t\t\t\t\t* 3-REGISTER   *\n";
		cout << "\t\t\t\t\t****************\n";
		char b;
		cin >> b;
		string searchname, searchpassword; //string type declation
		system("CLS");
		int r = 0;
		if (b == '1') //condition statement
		{
			if (h > 0)
			{
				int attempts = 0;
				cin.ignore();
				while (true) //following code executes if this condition is true
				{
					cout << "Username: ";
					getline(cin, searchname); //takes input of string
					cout << "Password: ";
					getline(cin, searchpassword);
					int j = h;
					int l;
					while (j > 0)
					{

						if (searchname == p.username[j - 1] && searchpassword == p.password1[j - 1]) //condition statement that matches username statement

						{

							l = j - 1;
							r++;
						}
						j--;
					}
					if (r == 1) //decision statement
					{
						cout << GREEN << "YOU HAVE BEEN SUCCESSFULLY LOGGED IN " << RESET << endl; //output is printed in green
						Sleep(800); //delays execution on debugging
						studentview(l); //calling of function student view
						break;
						system("cls");
					}
					else if (r == 0)
					{
						cout << RED << "WRONG PASSWORD OR USERNAME." << RESET << endl; //output is in red
						attempts++;
						if (attempts == 4) //condition statement that doesn't allow more attempts
						{
							cout << RED << "You have exceeded the attempt limit. Sorry, your account has been blocked!" << RESET << endl;
							getchar();
							break;
						}
					}
				}
			}
			else if (h == 0) //decision for unregistered account
			{
				cout << RED << "KINDLY REGISTER YOURSELF IN FIRST " << RESET << endl;
				cout << "Do you want to " << RED << "exit" << RESET << " and " << GREEN << "register?" << RESET << endl;
				cout << "Press 'E' to " << RED << "exit " << RESET << "or any key to " << GREEN << "try again" << RESET << endl;
				char r;
				cin >> r;
				if (r == 'e' || r == 'E') //decision statement to exit the code
				{
					system("CLS");
					break;

				}

			}
		}
		else if (b == '2') //decision statement
		{
			int n = 0;
			cin.ignore();
			while (true)
			{
				/* dsiplays the authorities of admin*/

				cout << BOLDMAGENTA << "\n \t\t -------- ADMIN VIEW ---------\t\t\n" << RESET;

				/*inputs username and password for admin account*/

				cout << "\n\t\tUsername: ";
				getline(cin, searchname);
				cout << "\t\tPassword: ";
				getline(cin, searchpassword);

				/* ADMIN USERNAME IS "admin" AND PASSWORD IS "admin@1"*/

				if (searchname == "admin" && searchpassword == "admin@1") //matches input with assigned username and password
				{
					cout << GREEN << "\nYOU ARE LOGGED IN AS AN ADMIN " << RESET << endl; //output is printed in green
					Sleep(800); //sleep function to delay the execution
					adminview(); //function is called

					break;
				}
				else
				{
					cout << RED << "\nWRONG PASSWORD" << RESET << endl;
					n++;
					if (n == 4) //attempt check
					{
						cout << RED << "You have exceeded the attempt limit. Sorry, your account has been blocked!" << RESET << endl;
						Sleep(1500);
						break;
					}
				}
			}
		}
		else if (b == '3')
		{
			break;

		}
		else //decision statement executed if previous statements are false
		{
			cout << RED << "Invalid Input.." << RESET << endl;
			cout << "Press 'E' to " << RED << "exit " << RESET << "or any key to " << GREEN << "try again" << RESET << endl;
			char r;
			cin >> r;
			if (r == 'e' || r == 'E') //exits the block of code
			{
				system("CLS");
				break;

			}

		}
	}

}

void attendance_management::studentview(int z) //student view function is defined using scope resolution operator
{
	while (true) // following code executes if this is true
	{
		system("cls");

		/* STUDENT VIEW IS DISPLAYED ON THE CONSOLE*/

		cout << MAGENTA << "\n \t\t -------- STUDENT VIEW ---------\t\t\n" << RESET;

		cout << "\n\t\tNAME : " << p.name[z] << endl;
		cout << "\t\tROLL NO : " << p.rollno[z] << endl;
		cout << " \n 1-Check your attendance  \n";
		cout << RED << " \n 2-LOG OUT " << RESET;
		char e;
		cin >> e;
		if (e == '1') //decision statement
		{
			student_present(z); // if this block of code executes student present is called with 2 parameters 

			system("CLS");
		}
		else if (e == '2')
		{
			cout << RED << "\n\n\n\n\nLOGGING OUT!!" << RESET;  //printed in red colour 
			Sleep(1300); //delayes execution 
			system("CLS"); //clears the output screen
			break;

		}
		else //this code executes if others are falsified
		{
			cout << RED << "Invalid Input! Please try again.." << RESET << endl;
			Sleep(800); //delays execution
		}


	}
}
void attendance_management::adminview() //admin view function is defined usin
{
	while (true) //this line executes if this is true
	{
		/* ADMIN VIEW IS PRINTED ON THE CONSOLE SCREEN*/
		//colour of the display is magenta
		system("CLS");
		cout << BOLDMAGENTA << "\n \t\t -------- ADMIN VIEW ---------\t\t\n" << RESET;
		cout << "\n 1 List of Students registered ";
		cout << "\n 2 Check presense count of any student by Roll No";
		cout << "\n 3 Get List of student with their attendance count";
		cout << "\n 4 Check complete attendance of student with username ";
		cout << "\n 5 Mark Attendence of any student";
		cout << "\n 6 Upgrade attendance";
		cout << "\n 7 Delete student by rollno";
		cout << "\n 8 Delete All students name registered";
		cout << "\n 9 Log out " << endl;

		cout << "\nPlease select the desired option you want to opt: " << RESET;
		int y;
		cin >> y;
		system("cls");

		if (y == 1) //if user enters 4th option
		{
			int h = o;
			if (h == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
			}
			if (h > 0)
			{
				for (int i = 0; i < o; i++)
				{
					cout << i + 1 << ". NAME :" << p.name[i] << "\t" << "ROLL NO :" << p.rollno[i] << endl; //diplays the name of all the registered users
					Sleep(1500); //delays execution

				}
			}
			Sleep(1800);
			getchar();
			system("cls");
		}
		if (y == 2) //if user chooses 5th option
		{
			int r = o;
			if (r == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
				Sleep(1500);
			}
			if (r > 0)
			{
				int b = o;
				string rollnum2; //string of roll number
				cout << "Enter the roll number of the student: ";
				cin.ignore();
				getline(cin, rollnum2);
				int y = 0;
				int j;
				while (b >= 0)
				{
					if (rollnum2 == p.rollno[b - 1]) //checks entered roll number by already registered roll numbers
					{
						y++;
						j = b - 1;
					}
					b--;
				}
				if (y == 1) //checks entered roll number by already registered roll numbers
				{

					if (i[j] == 1)
					{
						cout << "\n\n\nThe Percentage Attendance of " << p.username[j] << " is: " << GREEN << p.q[j] << RESET << endl; //prints attendence percentageof user
						Sleep(1500);
					}
					else
					{
						cout << RED << "ATENDANCE NOT UPDATED YET " << RESET << endl;
						Sleep(1500);

					}
				}
				else if (y == 0)
				{
					cout << RED << "The entered roll number doesn't match with recored!" << RESET; //if wrong data is entered
					Sleep(1500);
				}
			}
		}
		if (y == 3) //if user chooses 6th option

		{
			int h = o;
			if (h == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
				Sleep(1500);
			}
			if (h > 0)
			{
				for (int d = 0; d < o; d++) //for loop runs as long as it is true
				{
					cout << d + 1 << "- Username: " << p.username[d] << "\t";
					if (i[d] == 1)
					{
						cout << "Percentage attendance: " << GREEN << p.q[d] << RESET << endl; // prints the attendence of students in green colour
					}
					else
					{
						cout << RED << "ATENDANCE NOT UPDATED YET " << RESET << endl;

					}

					Sleep(1500);
				}
			}
			system("CLS");
		}

		if (y == 4)
		{
			int h = o;
			if (h == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
				Sleep(1500);
			}
			if (h > 0)
			{
				cout << "Enter the username of student you want to check the attendence of: ";
				string username2;

				cin.ignore();
				getline(cin, username2);
				int g = o;
				int k = 0;
				int s;

				while (g > 0)
				{
					if (username2 == p.username[g - 1])
					{
						k++;
						s = g - 1;

					}
					g--;
				}

				if (k == 1)
				{
					cout << GREEN << "\n\n\t\t********User Found********" << RESET << endl;
					cout << "\n\t\tName: " << p.name[s] << endl;
					cout << "\t\tRoll no: " << p.rollno[s] << endl;
					cout << MAGENTA << "\n\t\t*******************************************************\n\n" << RESET;
					int a = p.l1[s] - p.l[s];
					int c = p.u[s];
					if (i[s] == 1)
					{

						for (; p.l[s] <= p.l1[s]; p.l[s]++)
						{
							int n = p.l[s];
							if (p.l[s] < p.l1[s])
							{

								int t = 31;
								for (int y = p.u[s]; y <= t; y++)
								{

									cout << " \t\t\tAttendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << "       ";
									cout << p.attend[s][y][n] << endl;
									Sleep(1000);
									y++;
								}
								p.u[s] = 1;
							}
							if (p.l[s] == p.l1[s])
							{

								for (int y = p.u[s]; y <= p.u1[s]; y++)
								{
									cout << "\t\t\tAttendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << "       ";
									cout << p.attend[s][y][n] << endl;
									Sleep(1500);
									y++;
								}
							}
						}
						cout << MAGENTA << "\n\n\t\t*******************************************************\n\n" << RESET;
						p.u[s] = c;
						p.l[s] = p.l[s] - (a + 1);
						if (p.q[s] <= 75) //if attendence percentage is below 
						{
							cout << "\n\nPercentage of Student is: " << RED << p.q[s] << "%" << RESET << endl;

						}
						else
						{
							cout << "Percentage of Student is: " << GREEN << p.q[s] << "%" << RESET << endl; //normal attendence printed in green

						}
						Sleep(1500);

					}
					else if (i[s] != 1)
					{
						cout << RED << "No attendance has been marked for this user yet" << RESET;
						getchar();

					}
				}
				if (k == 0)
				{
					cout << RED << "USERNAME DIDNT MATCH WITH OUR EXISTING ACCOUNTS " << RESET << endl;
					getchar();
				}

			}
		}


		if (y == 5) //if user chooses 7th option
		{
			int t = o;

			if (t == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
				Sleep(1500);
			}
			if (t > 0)
			{
				/* DISPLAYS CALENDER ,TIME TABLE AND MARKS PRESENCE */
				cout << "The Class schedule is as follows\n" << endl;
				cout << " The classes are held on Monday Wednesday and Friday\n" << endl;
				cout << "\n\t\t-------- CALENDAR ---------\t\t\n";
				cout << CYAN << "\t\tMonday : Wednesday : Friday" << endl;
				cout << "\t\t13     : 15        : 17 \n\t\t20     : 22        : 24 \n\t\t27     : 29        : 31 \n\t\t3      : 5         : 7 \n\t\t10     : 12        : 13" << RESET << endl;
				time_t l;
				time(&l);
				cout << "\n\n\nCalendar date and time as per todays is : " << CYAN << asctime(localtime(&l)) << RESET;
				present(); //function present is declared
			}
		}
		if (y == 6)
		{
			int h = o;
			if (h == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
				Sleep(1500);
			}
			if (h > 0)
			{
				cout << "Enter the username of student you want to upgrade the attendence of: ";
				string username2;

				cin.ignore();
				getline(cin, username2);

				int g = o;
				int k = 0;
				int s;

				while (g > 0)
				{
					if (username2 == p.username[g - 1])
					{
						k++;
						s = g - 1;

					}
					g--;
				}

				if (k == 1)
				{
					cout << GREEN << "\n\n\t\t********User Found********" << RESET << endl;
					cout << "\n\t\tName: " << p.name[s] << endl;
					cout << "\t\tRoll no: " << p.rollno[s] << endl;

					if (i[s] == 1)
					{
						getchar();
						system("CLS");
						upgrade_attendance(s);

					}
					else if (i[s] != 1)
					{
						cout << RED << "No attendance has been marked for this user yet" << RESET;
						getchar();

					}

				}

				else
				{
					cout << RED << "Wrong USERNAME..\n " << RESET << endl;
					getchar();

				}

			}
		}
		if (y == 7) //if user chooses 3rd option 
		{
			int h = o;
			if (h == 0)
			{
				cout << RED << "There are no records registered yet!" << RESET;
				Sleep(1500);
			}
			if (h > 0)
			{
				int l = o;
				string rollnum; // string type roll number
				cout << "Enter the rollnumber of the student: ";
				cin.ignore();
				getline(cin, rollnum); //user takes input
				int n = 0;
				int q = 0;
				while (l > 0)
				{

					if (rollnum == p.rollno[l]) //if roll number matches the already registeres roll number
					{
						n++;
						q = l;
					}
					l--;
				}
				if (n == 1)
				{
					cout << GREEN << "The entered roll number has been match with another roll nmber from our records!" << RESET << endl; //prints in green colour
					cout << "\nWait till the records has been clearded.." << endl;
					Sleep(1500);//delays execution of the program
								//clears all the users entered by roll number
					(p.name[q]).clear();
					(p.username[q]).clear();
					(p.password1[q]).clear();
					(p.password2[q]).clear();
					(p.rollno[q]).clear();
					o--;
					int i = q;
					while (i <= o)
					{
						p.username[i] = p.username[i + 1];
						p.name[i] = p.name[i + 1];
						p.password1[i] = p.password1[i + 1];
						p.password2[i] = p.password2[i + 1];
						p.rollno[i] = p.rollno[i + 1];
						i++;
					}
					cout << GREEN << "\nRecord for the specific roll number has been cleared." << RESET << endl; //displayed in green
				}

				else
				{
					cout << RED << "The entered roll number doesn't match with our record." << RESET << endl; //if wrong roll number is entered
					Sleep(1500);
				}
				getchar();
				system("CLS");
			}

		}
		if (y == 8) //if the user chooses two
		{
			int x;

			for (x = 1; x <= o; x++) //for loop runs until the condition is true
			{
				//deletes all the entered student playing their number -1
				(p.name[x - 1]).clear();
				(p.username[x - 1]).clear();
				(p.password1[x - 1]).clear();
				(p.password2[x - 1]).clear();
				(p.rollno[x - 1]).clear();

			}
			cout << RED << "Please wait for a few seconds for this course of action to take place..." << RESET << endl;
			o = 0;
			Sleep(1500); //sleep funtion to delay execution
			getchar();
			system("CLS");

		}

		if (y == 9) //if user chooses 8th option
		{
			cout << RED << "\n Logging out..." << RESET << endl;
			Sleep(1800); //delays execution of program
			break;
		}
	}
}

void attendance_management::present() //function present is defined using scope resolution operator

{
	cout << "\n\nEnter the username you want to mark the attendance of: ";
	string username2; //string type uderna,e
	cin.ignore();
	getline(cin, username2); //inputs username 
	int g = o;
	int k = 0;
	int s;
	while (g > 0)
	{
		if (username2 == p.username[g - 1]) //checks the condition of username if this is true it executes
		{
			k++;
			s = g - 1;
		}
		g--;
	}
	if (k == 1) //if this is true following block of code executes
	{
		cout << GREEN << "\n\n\t\t*********User Found*********" << RESET << endl;
		cout << "\nName: " << p.name[s] << endl;
		cout << "Roll no: " << p.rollno[s] << endl;
		Sleep(1500);
		system("CLS");

		/* TAKES INPUT FOR MARKING ATTENDENCE*/

		cout << BOLDMAGENTA << "\n \t ****** ENTER THE START DATE OF THE SEMESTER ******" << RESET;


		while (true)
		{
			cout << "\n\n\t\tENTER THE START DAY [1-31]: ";

			cin >> p.u[s];
			while (p.u[s] < 0 || p.u[s] > 31) //if wrong day is entered
			{
				cout << RED << "INVALID INPUT PLEASE ENTER AGAIN \n" << RESET;
				cin >> p.u[s];
			}
			cout << "\n\n\t\tENTER THE NUMBER OF THE MONTH[1-12]: ";

			cin >> p.l[s];
			while (p.l[s] < 0 || p.l[s] > 12) //if wrong month is enetered
			{
				cout << RED << "INVALID INPUT PLEASE ENTER AGAIN \n" << RESET;
				cin >> p.l[s];
			}
			if ((p.u[s] == 31 && (p.l[s] == 2 || p.l[s] == 4 || p.l[s] == 6 || p.l[s] == 9 || p.l[s] == 11)) || (p.u[s] > 29 && p.l[s] == 2)) //condition for invalid input
			{
				cout << RED << "INVALID INPUT PLEASE ENTER AGAIN \n" << RESET;
			}
			else
			{
				break; //breaks the block of code
			}
		}
		cout << "\n\n\t\tENTER THE YEAR[2020]: ";
		int c = p.u[s];
		cin >> p.m[s]; //takes inout of year from the user

		while (p.m[s] != 2020) //if any year other than 2020 is entered
		{
			cout << RED << "INVALID INPUT PLEASE ENTER AGAIN \n" << RESET;
			cin >> p.m[s];
		}
		//takes input of end of lecture dates
		cout << BOLDMAGENTA << "\n \t ****** ENTER THE DATE OF THE LAST LECTURE ******" << RESET;

		while (true)
		{
			cout << "\n\n\t\tENTER THE LAST DAY[1-31]: ";
			cin >> p.u1[s]; //takes input from user
			while (p.u1[s] < 0 || p.u1[s] > 31) //if input is wrong
			{
				cout << RED << "INVALID INPUT PLEASE TRY AGAIN " << RESET;
				cin >> p.u1[s];
			}
			cout << "\n\n\t\tENTER THE NUMBER OF THE MONTH[1-12]: ";

			cin >> p.l1[s]; //takes input for end month of lecture
			while (p.l1[s] < 0 || p.l1[s] > 12)
			{
				cout << RED << "INVALID INPUT PLEASE TRY AGAIN " << RESET;
				cin >> p.l1[s];
			}
			if ((p.u[s] == 31 && (p.l1[s] == 2 || p.l1[s] == 4 || p.l1[s] == 6 || p.l1[s] == 9 || p.l1[s] == 11)) || (p.u[s] > 29 && p.l1[s] == 2)) //if any date other than lecture dates is entered
			{
				cout << RED << "INVALID DATE " << RESET;
			}
			else
			{
				break;
			}
		}
		cout << "\n\n\t\tENTER THE YEAR[2020]: ";

		cin >> p.m1[s]; //takes input of the year 2020

		while (p.m1[s] != 2020) //if end of lecture year is not 2020
		{
			cout << RED << "INVALID INPUT" << RESET;
			cin >> p.m1[s];
		}


		Sleep(1500);
		system("CLS");
		/*PRINTS START DATE OF ATTENDENCE AND MARKING ATTENDENCE STARTER AND END */
		cout << "****************************" << endl;;
		cout << CYAN << "\nSTART DAY OF SEMESTER IS " << p.u[s] << "-" << p.l[s] << "-" << p.m[s] << endl;
		cout << "LAST DAY OF SEMESTER IS " << p.u1[s] << "-" << p.l1[s] << "-" << p.m1[s] << RESET << endl;
		cout << "\n****************************\n\n";
		float counter = 0;

		cout << "Mark Attendence from " << p.u[s] << "-" << p.l[s] << "-" << p.m[s] << endl;
		cout << "Enter 'P' for" << GREEN << " Present" << RESET << " and 'A' for " << RED << "Absent" << RESET << endl;
		int y = 0;
		float total = 0;
		int a; //declartion of a to int
		a = p.l1[s] - p.l[s];

		for (; p.l[s] <= p.l1[s]; p.l[s]++) //for statement that runs if the condition is true
		{
			int n = p.l[s];
			if (p.l[s] < p.l1[s]) // multiple if statement
			{
				int t = 31;
				for (int y = p.u[s]; y <= t; y++) //runs until condition is true
				{
					cout << "Attendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << endl;
					cin >> p.attend[s][y][n]; //takes input for attendence
					total++;
					while (true)
					{
						if (p.attend[s][y][n] == 'P' || p.attend[s][y][n] == 'p') //counts number of P for present
						{
							counter++; //number increases by 1
							break;
						}
						else if (p.attend[s][y][n] == 'A' || p.attend[s][y][n] == 'a')
						{

							break;
						}
						else
						{
							cout << "INVALID INPUT PLEASE ENTER AGAIN \n";
						}
						cin >> p.attend[s][y][n];
					}
					y++;
				}
				p.u[s] = 1;
			}

			else if (p.l[s] == p.l1[s])  //if statement is wrong then this executes
			{
				for (int y = p.u[s]; y <= p.u1[s]; y++) //this executes as long as it is true
				{
					total++;
					cout << "Attendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << endl;
					cin >> p.attend[s][y][n]; //takes input for the attendence
					while (true)
					{
						if (p.attend[s][y][n] == 'P' || p.attend[s][y][n] == 'p') //checks if input is equal to P
						{
							counter++; //increases the counter by 1
							break;
						}
						else if (p.attend[s][y][n] == 'A' || p.attend[s][y][n] == 'a')
						{
							break;
						}
						else
						{
							cout << "INVALID INPUT PLEASE ENTER AGAIN \n";
						}
						cin >> p.attend[s][y][n];
					}
					y++;
				}
			}
			if (p.l[s] > p.l1[s]) //if wrong input is entered
			{
				cout << RED << "INVALID INPUT " << RESET;

			}
		}
		p.l[s] = p.l[s] - (a + 1);

		p.q[s] = ((counter) / total) * 100; //formulai for percentage calculater
		if (p.q[s] <= 75) //attendence marker
		{
			cout << "Percentage of Student is: " << RED << p.q[s] << "%" << endl; //lower attendence is marked in RED
			cout << "\n\nPLEASE MANAGE YOUR PERCENTAGE AS IT IS LOWER THAN 75%;" << RESET;
			Sleep(1500);
			getchar();
		}
		else
		{
			cout << "Percentage of Student is: " << GREEN << p.q[s] << "%" << RESET << endl; //Sustainable attendence is printed in green
			Sleep(1500);
			getchar();
		}
		i[s] = 1;
		p.u[s] = c;
	}
	else if (k == 0)
	{
		cout << RED << "The entered name doesn't match our record." << RESET << endl; //if wrong name is entered
		Sleep(1300); //delays execution 
	}
}

void attendance_management::student_present(int s) //student present function is defined having 2 parameters

{
	cout << BOLDMAGENTA << "\n\t\t******** YOUR ATTENDANCE IS MARKED AS SHOWN BELOW FOR SPECIFIC DATES ONLY ********\n\n" << RESET;
	int a = p.l1[s] - p.l[s];
	if (i[s] == 1)
	{
		for (; p.l[s] <= p.l1[s]; p.l[s]++) //executes as long as condition satisfies
		{
			int n = p.l[s];
			if (p.l[s] < p.l1[s]) //if this is true following block of code executes
			{
				int t = 31;
				for (int y = p.u[s]; y <= t; y++) //for loop for printing attendence
				{
					cout << "\t\t\tAttendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << "       ";
					cout << p.attend[s][y][n] << endl;
					Sleep(1000); //delays execution of program
					y++;
				}
				p.u[s] = 1;
			}

			if (p.l[s] == p.l1[s]) //if this true following code executes
			{
				for (int y = p.u[s]; y <= p.u1[s]; y++) //for loop running as long as it is true
				{
					cout << "\t\t\tAttendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << "       ";
					cout << p.attend[s][y][n] << endl; //attendence is printed
					Sleep(1500); //delayes execution of the program
					y++;

				}

			}
		}
		p.l[s] = p.l[s] - (a + 1);
		if (p.q[s] <= 75) //if attendence percentage is below 
		{
			cout << "Percentage of Student is: " << RED << p.q[s] << "%" << endl;
			cout << "\n\nPLEASE MANAGE YOUR PERCENTAGE AS IT IS LOWER THAN 75%;" << RESET; //warning for lower attendence percentage
			getchar();
		}
		else
		{
			cout << "Percentage of Student is: " << GREEN << p.q[s] << "%" << RESET << endl; //normal attendence printed in green
			getchar();
		}
		Sleep(1500); //delays execution of the program

	}
	else
	{
		cout << RED << "\n\nYOUR ATTENDANCE HAS NOT BEEN UPDATED YET " << RESET; //if attendence is not updated
		Sleep(1500);
		getchar();
	}
}
void attendance_management::upgrade_attendance(int s)
{
	cout << MAGENTA << "\n\t\t*******************************************************\n\n" << RESET;
	int a = p.l1[s] - p.l[s];
	int c = p.u[s];
	if (i[s] == 1)
	{

		for (; p.l[s] <= p.l1[s]; p.l[s]++)
		{
			int n = p.l[s];
			if (p.l[s] < p.l1[s])
			{

				int t = 31;
				for (int y = p.u[s]; y <= t; y++)
				{

					cout << " \t\t\tAttendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << "       ";
					cout << p.attend[s][y][n] << endl;
					Sleep(1000);
					y++;
				}
				p.u[s] = 1;
			}
			if (p.l[s] == p.l1[s])
			{

				for (int y = p.u[s]; y <= p.u1[s]; y++)
				{
					cout << "\t\t\tAttendence for Day: " << y << "-" << p.l[s] << "-" << p.m[s] << "       ";
					cout << p.attend[s][y][n] << endl;
					Sleep(1500);
					y++;
				}
			}
		}
		cout << MAGENTA << "\n\n\t\t*******************************************************\n\n" << RESET;
		p.u[s] = c;
		p.l[s] = p.l[s] - (a + 1);
		if (p.q[s] <= 75) //if attendence percentage is below 
		{
			cout << "\n\nPercentage of Student is: " << RED << p.q[s] << "%" << RESET << endl;

		}
		else
		{
			cout << "Percentage of Student is: " << GREEN << p.q[s] << "%" << RESET << endl; //normal attendence printed in green

		}
		Sleep(1500);
		while (true)
		{
			cout << "\nENTER THE DAY AT WHICH YOU WANT TO CHANGE THE ATTENDANCE[1-31]: ";
			int k;
			cin >> k;
			cout << "ENTER THE MONTH AT WHICH YOU WANT TO CHANGE THE ATTENDANCE[1-12]: ";
			int j;
			cin >> j;

			if (p.attend[s][k][j] == 'p' || p.attend[s][k][j] == 'P' || p.attend[s][k][j] == 'a' || p.attend[s][k][j] == 'A')
			{
				cout << "\nEnter 'A' for " << RED << "ABSENT" << RESET << " and 'P' for " << GREEN << "PRESENT: " << RESET;
				cin >> p.attend[s][k][j];
				while (true)
				{
					if (p.attend[s][k][j] == 'p' || p.attend[s][k][j] == 'P' || p.attend[s][k][j] == 'a' || p.attend[s][k][j] == 'A')
					{
						break;
					}
					else
					{
						cout << RED << "INVALID INPUT PLEASE ENTER AGAIN \n" << RESET;
						cin >> p.attend[s][k][j];
					}
				}
				cout << GREEN << "\n\nATTENDANCE HAS BEEN UPGRADED\n" << RESET;
				Sleep(1500);

				break;
			}
			else
			{
				cout << RED << "INVALID INPUT PLEASE ENTER AGAIN \n" << RESET;

			}
		}
		p.u[s] = c;
		int e = p.l1[s] - p.l[s];
		int l = p.u[s];

		float total = 0;
		float count = 0;

		for (; p.l[s] <= p.l1[s]; p.l[s]++)
		{
			int i = p.l[s];
			if (p.l[s] < p.l1[s])
			{

				int t = 31;
				for (int y = p.u[s]; y <= t; y++)
				{
					count++;
					if (p.attend[s][y][i] == 'p' || p.attend[s][y][i] == 'P')
					{
						total++;

					}
					y++;


				}
				p.u[s] = 1;
			}
			if (p.l[s] == p.l1[s])
			{
				for (int y = p.u[s]; y <= p.u1[s]; y++)
				{
					count++;
					if (p.attend[s][y][i] == 'p' || p.attend[s][y][i] == 'P')
					{
						total++;

					}
					y++;
				}
			}


		}
		p.q[s] = (total / count) * 100;
		p.l[s] = p.l[s] - (e + 1);
		if (p.q[s] <= 75) //if attendence percentage is below 
		{
			cout << "\n\n\nPercentage of Student after the UPDATE is: " << RED << p.q[s] << "%" << endl;
			cout << "\n\nPLEASE MANAGE YOUR PERCENTAGE AS IT IS LOWER THAN 75%;" << RESET; //warning for lower attendence percentage
			getchar();
		}
		else
		{
			cout << "Percentage of Student is: " << GREEN << p.q[s] << "%" << RESET << endl; //normal attendence printed in green
			getchar();
		}

		p.u[s] = l;
		Sleep(5000);
	}

	else
	{
		cout << RED << " \n\n\nATTENDANCE HAS NOT BEEN UPDATED YET " << RESET;
		Sleep(1500);
		getchar();
	}
}



int main() //main function that execution starts from here
{

	int o;
	int t = 0;
	system_managemnt b; //object is decalred
	attendance_management* a; //object pointer
	a = &b;
	for (o = 0; o <= 100; o++) //for loop that makes the program run upto a 100 times
	{
		a->start(); //arrow head to call start sunction

		cin >> b.a; //takes input 
		system("CLS");
		if (b.a == '1') //is user chooses one
		{
			a->display(); //arrow operater calls the display function
			t++;

		}
		else if (b.a == '2') //if user enteres two
		{
			a->login(); //arrow operater calls login fucntion
		}
		else
		{
			cout << RED << "Invalid Input!" << RESET << endl;

			cout << "Press '1' for " << GREEN << "TRYING AGAIN " << RESET << "or any other key to" << RED << " EXIT." << RESET << endl; //if user wants to try again 

			char g;
			cin >> g;
			if (g == '1') //if user entered one
			{

				system("CLS");
				cout << RED << "Please enter a valid option now." << RESET << endl;
				Sleep(1300);
				system("CLS");
			}
			else { break; } //breaks the block of code
		}
	}
	system("CLS");
	/* ENDING STATEMENTS ARE PRINTED*/

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	cout << "******************************************************\n";
	cout << "\t\t\t\t";
	cout << "* " << MAGENTA << "Thanks for using our service, have an amazing day!" << RESET << " * " << endl;
	cout << "\t\t\t\t";
	cout << "******************************************************\n\n\n\n\n\n\n\n";
	return 0;
}