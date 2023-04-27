#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

using namespace std;

class customer
{
	public:
		char name[40],address[40],email[40],types[30],brandName[40];
		long long int price , phone;
		int pieces,billnum;
	
		void getdata()
		{
			cout<<"----------------------------------------------------\n";
			fflush(stdin);
			cout<<"  Name: ";
			cin.getline(name,40);
			fflush(stdin);
			cout<<"  Address:";
			cin.getline(address,40);
			fflush(stdin);
			cout<<"  Brand Name:";
			cin.getline(brandName,40);
			fflush(stdin);
			cout<<"  Types:";
			cin.getline(types,30);
			cout<<"  Pieces:";
			cin>>pieces;
			cout<<"  Price per Unit:";
			cin>>price;
			cout<<"  Phone number:";
			cin>>phone;
			fflush(stdin);
			cout<<"  Email:";
			cin.getline(email,40);
			cout<<"----------------------------------------------------\n";
		}
		void display()
		{ 
			cout<<"\n----------------------------------------------------\n";
			cout<<"  Bill No.:"<<billnum<<endl;
			cout<<"  Name: "<<name<<endl;
			cout<<"  Address:"<<address<<endl;
			cout<<"  Brand Name:"<<brandName<<endl;
			cout<<"  Types:"<<types<<endl;
			cout<<"  Pieces:"<<pieces<<endl;
			cout<<"  Price per unit:"<<price<<endl;
			cout<<"  Total Cost:"<<price*pieces<<endl;
			cout<<"  Phone number:"<<phone<<endl;
			cout<<"  Email:"<<email<<endl;
			cout<<"----------------------------------------------------\n";
			cout<<endl;
		}
		void addRecord();
		void viewRecord();
		void modifyRecord();
		void searchRecord();
		void deleteRecord();
		void developers();
		void programExit();
}ss;
class userAuthentication
{
	private:
		char storeCh,username[40],password[40];
	public:
	void getid()
	{
    system("cls");
    int i = 0;
	cout<<"\n\n\t\t**************************";
	cout<<"\n\t\t**************************\n\n";
	cout<<"\t\t********LOGIN PANEL*******";
	cout<<"\n\n\t\t**************************";
	cout<<"\n\t\t**************************\n\n";
    cout<<"\n\n\t\tUSERNAME: ";
    cin>>username;
    cout<<"\n\t\tPASSWORD: ";

    while (1)
    {
        storeCh = getch();
        if (storeCh == ENTER)
        {
            password[i] = '\0';
            break;
        }
        else if (storeCh == TAB || storeCh == SPACE)
        {
            continue;
        }
        else if (storeCh == BKSP)
        {
            if (i > 0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else
        {
            password[i] = storeCh;
            i++;
            cout<<"*";
        }
    }

	}
		bool compare()
		{
			if(strcmp(username,"admin")==0 && strcmp(password,"password")==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
class menu
{
	public:
		int selectNumber()
		{
	    system("cls");
		cout<<"\t\t>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<\n";
		cout<<"\t\t\t\tMAIN MENU\n";
		cout<<"\t\t>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<\n";
		cout<<"\n\t\t\t 1.CREATE RECORDS\t<ENTER 1>";
		cout<<"\n\t\t\t 2.READ RECORDS\t\t<ENTER 2>";
		cout<<"\n\t\t\t 3.SEARCH RECORDS\t<ENTER 3>";
		cout<<"\n\t\t\t 4.DELETE RECORDS\t<ENTER 4>";
		cout<<"\n\t\t\t 5.MODIFY RECORDS\t<ENTER 5>";
		cout<<"\n\t\t\t 6.DEVELOPERS\t\t<ENTER 6>";
		cout<<"\n\t\t\t 7.EXIT\t\t\t<ENTER 7>";

        int ch;
        cout<<"\n\t\t\tENTER YOUR CHOICE: ";
        cin>>ch;

		return ch;
		}
}m;
int main()
{
	int login_attempt=0;
	top:
	userAuthentication user;
	user.getid();
	bool result=user.compare();
	if(result==true)
	{
		system("cls");
		cout<<"Logged in successfully!!!"<<endl;
		cout<<"press any key"<<endl;
		system("cls");
		cout<<"\n\n\t\t========================================================\n\n";
		cout<<"\t\t\t\tWELCOME TO OUR PROJECT";
		cout<<"\n\n\t\t========================================================\n";
		cout<<"\n\t\tPress any key to.....................";
		getch();
		system("cls");
	
	while(1)
	{
	int choice;
	choice=m.selectNumber();
	switch(choice)
	{
		case 1:
			ss.addRecord();
			break;
		
		case 2:
			ss.viewRecord();	
			break;
			
		case 3:
			ss.searchRecord();
			break;
			
		case 4:
			ss.deleteRecord();
			break;
			
		case 5:
			ss.modifyRecord();
			break;
			
		case 6:
			ss.developers();
			break;
		
		case 7:
			ss.programExit();
			break;
			
	default:
		cout<<"\t\t\tInvalid number.....Enter again";
		getch();
		system("cls");
	}
	}
	}
	
	else if(result==false)
	{
		cout<<"\nInvalid password!!!"<<endl;
		login_attempt++;
		
		if(login_attempt>=3)
		{
		cout<<"\n You have already attempt 3 times. Please contact Administrator!!!";
		exit(1);
		}
		goto top;
		
	}
	
	return 0;
}

//----------------------------addRecord---------------------------
void customer:: addRecord()
{
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
	system("cls");
	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    cout<<"\t\t\tCREATING RECORDS\n";
   	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    int checkID, found = 0;
    cout<<"Bill No.: ";
    cin>>checkID;
	fstream file;
	fstream file1;
	file.open("record.txt", ios::in | ios::binary);
	file1.open("Temp.txt", ios::app | ios::out |  ios::binary);

    while(file.read((char *)&ss,sizeof (ss)).eof()==0)
    {
        if (checkID != ss.billnum)
        {
        	file1.write((char *)&ss,sizeof (ss));
        }
        else
        {
        	found = 1;
        	file1.write((char *)&ss,sizeof (ss));
		}
    }
        if (found == 1)
        {
        	cout<<"\nRecord Already Exist!!\n";

        }
        else
        {
        	ss.billnum=checkID;
        	ss.getdata();
        	file1.write((char *)&ss,sizeof (ss));
		}

        file.close();
        file1.close();
        
        remove("record.txt");
        rename("Temp.txt","record.txt");
        
        cout<<"\nDo you want to add more record? (Y/N) ";
        ch = getch();
    }
    printf("\nPress any key to go to main menu!!");
    getch();
}

//-------------------------viewRecord-------------------------------
void customer:: viewRecord()
{
	system("cls");
	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    cout<<"\t\t\tVIEWING RECORDS\n";
   	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
	fstream file;
	file.open("record.txt", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char *)&ss,sizeof (ss)).eof()==0)
	{
		ss.display();
		cout<<endl;
	}
	file.close();
	cout<<"Enter any key....."<<endl;
	getch();
}


//-----------------------search record-------------------------------------

void customer::searchRecord()
{
	char another = 'y';
	while(another == 'y' || another == 'Y')
	{
		system("cls");
		int found = 0;
		cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    	cout<<"\t\t\tSEARCHING RECORDS\n";
   		cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    	int checkID;
		cout<<"Bill No.: ";
    	cin>>checkID;
    	fstream file;
		file.open("record.txt", ios::in | ios::binary);
    	
    	while(file.read((char *)&ss,sizeof (ss)).eof()==0)
		{
    		if(checkID == ss.billnum)
			{
				cout<<"\n-----------";
                cout<<"\n Record:";
                cout<<"\n-----------\n\n";
    			found = 1;
    			ss.display();
			}
		}
		if(found == 0)
		{
			printf("\nNo record found!!");
		}
		file.close();
		
		cout<<"\nDo you want to search more records?(Y/N)";
		another=getch();
	}
	cout<<"\nPress any key to go to main menu";
}

//--------------------DELETE RECORD-----------------------
void customer:: deleteRecord()
{
    int checkID;
    char another = 'y';
    while (another == 'y' || another == 'Y')
    {
        int count = 0;
        system("cls");
		cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    	cout<<"\t\t\tDELETING RECORDS\n";
    	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
        cout<<"\nBill No.: ";
        cin>>checkID;
        fstream file;
		fstream file1;
		file.open("record.txt", ios::in | ios::binary);
		file1.open("temp.txt", ios::app| ios::out | ios::binary);
		file.seekg(0,ios::beg);

        while(file.read((char *)&ss,sizeof (ss)).eof()==0)
        {
            if (checkID != ss.billnum)
            {
                file1.write((char *)&ss,sizeof (ss));
            }
            else
            {
                count = 1;
                cout<<"\n-----------";
                cout<<"\n Record:";
                cout<<"\n-----------\n\n";
                ss.display();
            }
        }
        file.close();
        file1.close();
        remove("record.txt");
        rename("temp.txt","record.txt");

        if (count == 0)
        {
            cout<<"\n\nNo record found";
            cout<<"\n\nDo you want to delete more records? (Y/N) ";
            another = getch();
        }
        else
        {
            cout<<"\n\nThis record is deleted Successfully!!";
            cout<<"\n\nDo you want to delete more records? (Y/N) ";
            another = getch();
        }
    }
    cout<<"\n\nPress any key to go to Main Menu!!";
    getch();
}


//-----------------MODIFY RECORDS--------------------

void customer:: modifyRecord()
{
    int checkId;
    char another = 'y';
    while (another == 'y' || another == 'Y')
    {
        system("cls");
		cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
	    cout<<"\t\t\tUPDATING RECORDS\n";
	    cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
        cout<<"\nBill No.: ";
        cin>>checkId;
        int count = 0;
        fstream file;
        fstream file1;
        file.open("record.txt", ios::in | ios::binary);
        file1.open("Temp.txt", ios::app | ios::binary);
        file.seekg(0,ios::beg);
        while(file.read((char *)&ss,sizeof (ss)).eof()==0)
        {
            if (checkId == ss.billnum)
            {
                count = 1;
                cout<<"\n-----------";
                cout<<"\nOld Record:";
                cout<<"\n-----------\n";
                ss.display();
                
                count++;
				
				printf("\n-----------");
                printf("\nNew Record:");
                printf("\n-----------\n");
                ss.getdata();

                file1.write((char *)&ss,sizeof (ss));
            }
            else
            {
            	file1.write((char *)&ss,sizeof (ss));
			}
        }
        
        if (count == 0)
        {
            cout<<"\n\nNo record found";
            cout<<"\nDo you want to modify another records? (Y/N): ";
            another = getch();
        }
        else
        {
            cout<<"\n\nRecord modified!!";
            cout<<"\n\nDo you want to modify more records? (Y/N) ";
            another = getch();
        }
        file.close();
        file1.close();
        remove("record.txt");
        rename("Temp.txt","record.txt");
        
    }
    cout<<"\n\nPress any key to go to Main Menu!!";
    getch();
}


//-------------------Developers--------------------

void customer:: developers()
{
    system("cls");
	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    cout<<"\t\t\tDEVELOPERS\n";
    cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";

    cout<<"\t\t|| SANDESH LIMBU ||\n\n";
    cout<<"\t\t|| TANUZA AGRAWAL ||\n\n";
    cout<<"\t\t|| SANDIP BARAL  ||\n\n";
    cout<<"\n\nPress any key to go back to Main Menu!! ";
    getch();
}

//-------------------Exit-----------------
void customer:: programExit()
{
    system("cls");
	cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
    cout<<"\t\t\tEXITING\n";
    cout<<"\t\t>>>>>>>>>>>>>><<<<<<<<<<<<<<<\n";
	
	cout<<"\n\n\t||>>>>>>Thank for using our system.......<<<<<<<||";
	getch();
	exit(1);
}


