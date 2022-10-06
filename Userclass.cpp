#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class UserClass
{
	private:
        int id;
		string name,email,dob, address, mobileno;
	public:
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void deleteUser();
};
void UserClass::menu()
{
	menustart:
	int choice;
	char x;
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   User Management System |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Insert User"<<endl;
	cout<<"\t\t\t 2. Display User"<<endl;
	cout<<"\t\t\t 3. Modify User"<<endl;
	cout<<"\t\t\t 4. Search User"<<endl;
	cout<<"\t\t\t 5. Delete User"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tChoose Option:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Enter Your Choose: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    	    this->insert();
    		cout<<"\n\t\t\t Add another participant(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		this -> display();
		break;
	case 3:
		this -> modify();
		break;
	case 4:
		this -> search();
		break;
	case 5:
		this -> deleteUser();
		break;
	case 6:
		exit(0);

	default:
		cout<<"\n\t\t\t Invalid choice...Please Try Again..";
	}
	goto menustart;
}
void UserClass::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Add User Details------------------------------------------------"<<endl;
	cout<<"\t\t\tEnter User id: ";
	cin>>id;
	cout<<"\t\t\tEnter User name: ";
	cin>>name;
	cout<<"\t\t\tEnter User email: ";
	cin>>email;
	cout<<"\t\t\tEnter User DOB: ";
	cin>>dob;
	cout<<"\t\t\tEnter User Address: ";
	cin>>address;
	cout<<"\t\t\tEnter user mobileno: ";
	cin>>mobileno;
	file.open("userRecord.txt", ios::app | ios::out);
	file<< std::left << std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< email <<std::left<<std::setw(15)<< dob <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< mobileno << "\n";
	//file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< event <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	file.close();
}
void UserClass::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------User Table-------------------------"<<endl;
	file.open("userRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo Data is Present";
		file.close();
	}
	else
	{
		file >> id >> name >> email >> dob >> address >> mobileno;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t User id: "<<id<<endl;
			cout<<"\t\t\t User name: "<<name<<endl;
			cout<<"\t\t\t User Email: "<<email<<endl;
			cout<<"\t\t\t User DOB: "<<dob<<endl;
			cout<<"\t\t\t User address: "<<address<<endl;
			cout<<"\t\t\t User Mobilno: "<< mobileno<<endl;

            file >> id >> name >> email >> dob >> address >> mobileno;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo Data Is Present...";
		}
	}
	file.close();
}
void UserClass::modify()
{
	system("cls");
	fstream file,file1;
	int  userId;
	int found=0;
	cout<<"\n-------------------------User Modified Details-------------------------"<<endl;
	file.open("userRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No Data is present..,";
		file.close();
	}
	else
	{
		cout << "\n Enter the User id to be Modified: ";
		cin >> userId;

		file1.open("userRecord.txt",ios::app | ios::out);

        // read the data from the file 
		file >> id >> name >> email >> dob >> address >> mobileno;
		while(!file.eof())
		{
			if(userId!=id)
			{
			 file1<< std::left << std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< email <<std::left<<std::setw(15)<< dob <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< mobileno << "\n";
			}
			else
			{
				cout<<"\t\t\tEnter User id: ";
                cin>>id;
                cout<<"\t\t\tEnter User name: ";
                cin>>name;
                cout<<"\t\t\tEnter User email: ";
                cin>>email;
                cout<<"\t\t\tEnter User DOB: ";
                cin>>dob;
                cout<<"\t\t\tEnter User Address: ";
                cin>>address;
                cout<<"\t\t\tEnter user mobileno: ";
                cin>>mobileno;

				file1 <<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< email <<std::left<<std::setw(15)<< dob <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< mobileno << "\n";
				found++;
			}

			file >> id >> name >> email >> dob >> address >> mobileno;
		}
		file1.close();
		file.close();
		remove("userRecord.txt");
		rename("Record.txt","userRecord.txt");
	}
}
void UserClass::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("userRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------User Search Data ------------------------"<<endl;
		cout<<"\n\t\t\t  No Data is Preasent...";
	}
	else
	{
		int userId ;
		cout<<"\n-------------------------User Search data------------------------"<<endl;
		cout<<"\nEnter User id you want to search : ";
		cin>>userId;
        file >> id >> name >> email >> dob >> address >> mobileno;
		while(!file.eof())
		{
			if(userId == id)
			{
				cout<<"\n\n\t\t\t User id: "<<id<<endl;
                cout << "\n\n \t\t\t User Name : "<<name<<endl;
                cout << "\n\n\t\t\t User Email : "<<email<<endl;
                cout << "\n\n\t\t\t User Dob : "<< dob << endl;
                cout << "\n\n\t\t\t User Address : "<< address  << endl;
                cout << "\n\n\t\t\t User Mobileno : "<< mobileno << endl;
				found++;
			}
			file >> id >> name >> email >> dob >> address >> mobileno;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t User Id not found...";
		}
		file.close();
	}
}
void UserClass::deleteUser()
{
	system("cls");
	fstream file,file1;
	int  userId;
	int found=0;
	cout<<"\n-------------------------Delete User Details -------------------------"<<endl;
	file.open("UserRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo Data is present...";
		file.close();
	}
	else
	{
		cout<<"\n Enter the User id you want to delete ..\n: " << endl;
		cin>>userId;
		file1.open("Record.txt",ios::app | ios::out);

        file >> id >> name >> email >> dob >> address >> mobileno;
		
		while(!file.eof())
		{
			if(userId!= id)
			{
				file1<< std::left << std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< email <<std::left<<std::setw(15)<< dob <<std::left<<std::setw(15)<< address <<std::left<<std::setw(15)<< mobileno << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tSuccessfully Delete Data";
			}
			file >> id >> name >> email >> dob >> address >> mobileno;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t User Id not found...";
		}
		file1.close();
		file.close();
		remove("UserRecord.txt");
		rename("Record.txt","UserRecord.txt");
	}
}

//

int main(){

    UserClass user;
    std::cout << "Application Started" << endl;
    user.menu();
    return 0;
    
}
