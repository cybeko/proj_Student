#include<iostream>
using namespace std;

class Student
{
	char* name;
	char* email;
	int age;

public:
	Student()
	{
		cout << "[Constructor by def.]\n";
		name = nullptr;
		email = nullptr;
		age = 0;
	}
	Student(const char* n, int a, const char* e)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		email = new char[strlen(n) + 1];
		strcpy_s(email, strlen(n) + 1, n);
		age = a;
		cout << "[Constructor 2 params]\n";
	}
	void Input()
	{
		char buff[20];

		cout << "\nEnter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			//cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cout << "Enter email: ";
		cin >> buff;
		if (email != nullptr)
		{
			//cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);

		cout << "Enter age: ";
		cin >> age;
		cout << endl;
	}
	void Print()
	{
		cout << "Name: " << name << "\nAge: " << age << "\nEmail: " << email << endl;
	}
	~Student()
	{
		delete[] name;
		delete[] email;
		cout << "[Destructor]\n";
	}
	void setEmail(const char* var)
	{
		if (email != nullptr)
		{
			delete[] email;
		}
		email = new char[strlen(var) + 1];
		strcpy_s(email, strlen(var) + 1, var);
	}
	void setName(const char* var)
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		name = new char[strlen(var) + 1];
		strcpy_s(name, strlen(var) + 1, var);
	}
	void setName(int var)
	{
		age = var;
	}
	int getAge()
	{
		return age;
	}
	char* getName()
	{
		return name;
	}
	char* getEmail()
	{
		return email;
	}

	/* добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * удаление выделенной динамической памяти в деструкторе.
	*/
};

int main()
{
	Student obj1("Oleg", 20, "oleg21@gmail.com");
	obj1.Print();

	obj1.Input();
	obj1.Print();

}