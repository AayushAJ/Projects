//EMPLOYEE MANAGEMENT SYSTEM

#include <bits/stdc++.h>
using namespace std;
int size = 10; //Maximum storage capacity

//Creating structure named employee
struct employee{

	string name;
	int age;
	string designation;
	int experience;
	long int code;
};
int num;
void showMenu();
vector<employee> emp(size); //To store info of employees
void insertRecord()
{
	if(num<size)
	{
		int i=num;
		num++;

        cout << "Name "; 
        cin >> emp[i].name; 
  
        cout << "Employee ID "; 
        cin >> emp[i].code;
  
        cout << "Designation "; 
        cin >> emp[i].designation;
  
        cout << "Experience "; 
        cin >> emp[i].experience ; 

        cout << "Age "; 
        cin >> emp[i].age; 

	}
	else //No more empty space left
		cout<<"Employee table full ."<<endl;
	showMenu();
}
void deleteRecord()
{
	cout<<"Enter ID Code to be deleted :: ";
	int id,i;
	cin>>id;
	//To find index of employee with this ID Code
	for(i=0;i<num;i++)
	{
		if(emp[i].code==id)
		{
			num--;
			break;
		}
	}
	//Deleting info of that employee and shifting left over employee data
	for (int j = i; j < num ; j++)
	{ 
        emp[j].name = emp[j + 1].name; 
	    emp[j].code = emp[j + 1].code; 
        emp[j].designation = emp[j + 1].designation; 
        emp[j].experience = emp[j + 1].experience; 
        emp[j].age = emp[j + 1].age; 
    }

    showMenu(); 

}
void showRecords()
{
	int k=0;
	int colWidth = 20;
	//Setting header of table to be displayed
	cout << setfill('*') << setw(5*colWidth) << "*" << endl;
	cout << setfill(' ') << fixed;
	cout << setw(colWidth)<<"NAME" << setw(colWidth) << "ID" << setw(colWidth) <<
	"Designation" <<setw(colWidth) << "Experience" <<setw(colWidth) << "Age" << endl; 
	cout << setfill('*') << setw(5*colWidth) << "*" << endl; 
	cout << setfill(' ') << fixed; 

	//Displaying data of employees
	while (k < num) { 
    cout << setw(colWidth) << emp[k].name << setw(colWidth) << emp[k].code << 
	setw(colWidth)<< emp[k].designation << setw(colWidth) << 
	emp[k].experience << setw(colWidth) << emp[k].age <<endl;
	k++;
	
	}
	cout << setfill('*') << setw(5*colWidth) << "*" << endl;
	showMenu(); 
}
void searchRecord()
{
	cout<<"Enter ID Code to be searched for :: ";
	int id;
	cin>>id;
	for(int i=0;i<num;i++)  //Searching for the employee
	{
		if(emp[i].code==id)
		{
			//Displaying information of that employee
			cout<<"Name ---> "<<emp[i].name<<endl;
			cout<<"ID Code ---> "<<emp[i].code<<endl;
			cout<<"Age ---> "<<emp[i].age<<endl;
			cout<<"Designation ---> "<<emp[i].designation<<endl;
			cout<<"Experience ---> "<<emp[i].experience<<endl;
			break;

		}
	}
	showMenu();
}
void showMenu()
{
	//General Display Menu
	cout<<"Insert a record ---> PRESS 1\n";
	cout<<"Delete an existing record ---> PRESS 2\n";
	cout<<"Search a Record ---> PRESS 3\n";
	cout<<"Show all records ---> PRESS 4\n";
	cout<<"To exit ---> PRESS 0\n";

	//Taking input from user
	int opt;
	cin>>opt;
	if(opt==1)
		insertRecord();
	else if(opt==2)
		deleteRecord();
	else if(opt==3)
		searchRecord();
	else if(opt==4)
		showRecords();
	else if(opt==0)
		return ;
	else
	{
		cout<<"Invalid Input\n";
		showMenu();
	}
}
int main()
{
	cout<<setfill(' ')<<setw(65)<<"EMPLOYEE MANAGEMENT SYSTEM"<<endl<<endl;
	showMenu();
	return 0;
}
