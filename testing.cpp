#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iomanip>
#include<conio.h>
using namespace std;

class HOSTEL
{
	private:
	int room_no;
	  char name[30];
	  char address[50];
	  char phone[11];
	  long month;
	  long cost;
	  char floor[30];
	  long pay;


	public:
	  void main_menu();
	  void add();
	  void display();
	  void rooms();
	  void edit();
	  int check(int);
	  void modify();
	  void delete_rec();
	  void modify_name(int);
	  void modify_address(int);
	  void modify_phone(int);
	  void modify_days(int);
	  void hello();
	  void search();
	  bool  isPhoneNumberValid(char *);
	  
	 
}h;

void HOSTEL::main_menu()
{
	int choice;
	while(choice!=7)
	{

		cout<<"\n\t\t\t\t\t\t ********************";
		cout<<"\n\t\t\t\t\t\t * HOSTEL MAIN MENU *";
		cout<<"\n\t\t\t\t\t\t ********************";
		cout<<"\n\n\n\t\t\t\t\t\t1. Allot Room";
		cout<<"\n\t\t\t\t\t\t2. Student Information";
		cout<<"\n\t\t\t\t\t\t3. Rooms Allotted";
		cout<<"\n\t\t\t\t\t\t4. Edit Student Details";
		cout<<"\n\t\t\t\t\t\t5. Search";
		cout<<"\n\t\t\t\t\t\t6. Exit";
		cout<<"\n\n\t\t\t\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	add();
				break;
			case 2: display();
				break;
			case 3: rooms();
				break;
			case 4:	edit();
				break;
			case 5: search();
			    break;
			case 6: return;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.";
					cout<<"\n\t\t\tPress any key to continue.";
					getchar();
				}
		}
	}
}

void HOSTEL::add()
{

	int flag;
	int r;
	ofstream fout("Record.txt", ios::app);
	cout<<"\n\t\t\t +-----------------------+";
	cout<<"\n\t\t\t | Rooms  |   Floor no   |";
	cout<<"\n\t\t\t +-----------------------+";
	cout<<"\n\t\t\t |   1-50 |      1       |";
	cout<<"\n\t\t\t |  51-80 |      2       |";
	cout<<"\n\t\t\t | 81-100 |      3       |";
	cout<<"\n\t\t\t +-----------------------+";
	cout<<"\n\n ENTER STUDENT DETAILS";
	cout<<"\n ----------------------";
	cout<<"\n\n Room Number: ";
	cin>>r;
	flag=check(r);
	if(flag==1)
		cout<<"\n Sorry, Room is already booked.\n";
	else
	{
	   if(flag==2)
		   cout<<"\n Sorry, Room does not exist.\n";
	   else
	   {
		   room_no=r;
		   cout<<" Name: ";
		   cin>>name;
		   cout<<" Address: ";
		   cin>>address;
		cout << "Phone Number (exactly 10 digits): ";
    	cin.ignore(); 
    	cin.getline(phone, 11);

    	while (!isPhoneNumberValid(phone)) {
        cout << "Invalid phone number format! Please enter exactly 10 digits: ";
        cin.getline(phone, 11);
    }
		   cout<<" Number of Months: ";
		   cin>>month;
		   if(room_no>=1&&room_no<=50)
		   {
		      strcpy(floor,"1st-floor");
		      cost=month*10000;
		   }
		   else
		   {
		      if(room_no>=51&&room_no<=80)
		      {
			 strcpy(floor,"2nd-floor");
			 cost=month*10000;
		      }
		      else
		      {
			 if(room_no>=81&&room_no<=100)
			 {
			    strcpy(floor,"3rd-floor");
			    cost=month*10000;
			 }
		      }
		   }
		    fout  << room_no ;
            fout <<setw(20)<< name ;
            fout <<setw(20) << address;
            fout <<setw(20)<< phone ;
            fout  <<setw(20)<< month;
            fout << setw(20)<<cost;
			fout<<floor;
			fout<<endl;

		   cout<<"\n Room has been booked.";
	   }
	}
	cout<<"\n Press any key to continue.";
	getchar();
	fout.close();
}
bool HOSTEL ::isPhoneNumberValid(char *phone)
    {
        for (int i = 0; i < 10; i++)
        {
            if (!isdigit(phone[i]))
            {
                return false;
            }
        }
        return true;
    }


void HOSTEL::display()
{

	ifstream fin("Record.txt",ios::in);
	int flag;
	int r;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		if(room_no==r)
		{

			cout<<"\n Student Details";
			cout<<"\n ----------------";
			cout<<"\n\n Room Number: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone Number: "<<phone;
			cout<<"\n Staying for "<<month<<" month(s).";
			cout<<"\n Floor no: "<<floor;
			cout<<"\n Total cost of stay: "<<cost;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Room is Vacant.";
	cout<<"\n\n Press any key to continue.";
	getchar();
	getchar();
	fin.close();

}


void HOSTEL::rooms()
{

	const char separator=' ';
	const int NoWidth=8;
	const int GuestWidth=17;
	const int AddressWidth=16;
	const int RoomWidth=13;
	const int ContactNoWidth=13;
	ifstream fin("Record.txt",ios::in|ios::binary);
	cout<<"\n\t\t\t    LIST OF ROOMS ALLOTED";
	cout<<"\n\t\t\t   -----------------------";
	cout<<"\n\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n | Room No.|   Student Name   |      Address    |   Floor no   |  Contact No. |";
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		cout<<"\n |"<<setw(NoWidth)<<setfill(separator)<<room_no<<" |";
		cout<<setw(GuestWidth)<<setfill(separator)<<name<<" |";
		cout<<setw(AddressWidth)<<setfill(separator)<<address<<" |";
		cout<<setw(RoomWidth)<<setfill(separator)<<floor<<" |";
		cout<<setw(ContactNoWidth)<<setfill(separator)<<phone<<" |";
	}
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n\n\n\t\t\tPress any key to continue.";
	getchar();
	getchar();
	fin.close();
}

void HOSTEL::edit()
{

	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1. Modify Student Information.";
	cout<<"\n 2. Student Check Out.";
	cout<<"\n Enter your choice: ";
	cin>>choice;

	switch(choice)
	{
		case 1:	modify();
			break;
		case 2:	delete_rec();
			break;
		default: cout<<"\n Wrong Choice.";
			 break;
	}
	cout<<"\n Press any key to continue.";
	getchar();
}


int HOSTEL::check(int r)
{
	int flag=0;
	ifstream fin("Record.txt",ios::in|ios::binary);
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		if(room_no==r)
		{
			flag=1;
			break;
		}
		else
		{
		  if(r>100)
		  {
			flag=2;
			break;
		  }
		}
	}
	fin.close();
	return(flag);
}


void HOSTEL::modify()
{

	int ch,r;
	cout<<"\n MODIFY MENU";
	cout<<"\n -----------";
	cout<<"\n\n\n 1. Modify Name";
	cout<<"\n 2. Modify Address";
	cout<<"\n 3. Modify Phone Number";
	cout<<"\n 4. Modify Number of Months of Stay";
	cout<<"\n Enter Your Choice: ";
	cin>>ch;

	cout<<"\n Enter Room Number: ";
	cin>>r;
	switch(ch)
	{
		case 1: modify_name(r);
			break;
		case 2: modify_address(r);
			break;
		case 3: modify_phone(r);
			break;
		case 4: modify_days(r);
			break;
		default: cout<<"\n Wrong Choice";
				 getchar();
				 getchar();
			 break;
	}
}

void HOSTEL::modify_name(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Name: ";
			cin>>name;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Student name has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::modify_address(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Address: ";
			cin>>address;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n student Address has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::modify_phone(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Phone Number: ";
			cin>>phone;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Customer Phone Number has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::modify_days(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<" Enter New Number of month(s) of Stay: ";
			cin>>month;
			if(room_no>=1&&room_no<=50)
			{
				strcpy(floor,"1st-floor");
				cost=month*10000;
			}
			else
			{
				if(room_no>=51&&room_no<=80)
				{
				   strcpy(floor,"2nd-floor");
				   cost=month*10000;
				}
				else
				{
					if(room_no>=81&&room_no<=100)
					{
					   strcpy(floor,"3rd-floor");
					   cost=month*15000;
					}
				}
			}
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Student information is modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::delete_rec()
{
	int r,flag=0;
	char ch;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	ifstream fin("Record.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		if(room_no==r)
		{
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone Number: "<<phone;
			cout<<"\n Floor-No: "<<floor;
			cout<<"\n Your total bill is: Rs. "<<cost;
			cout<<"\n\n Do you want to check out this student(y/n): ";
			cin>>ch;
			if(ch=='n')
			   fout.write((char*)this,sizeof(HOSTEL));
			else
			   cout<<"\n Student Checked Out.";
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(HOSTEL));
	}
	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
		else
    {
        remove("Record.txt");
        rename("temp.txt", "Record.txt");
        cout << "\n Record deleted successfully.";
    }

	getchar();
	getchar();
}


void HOSTEL::hello()
{

	cout<<"\n\t\t\t\t\t\t ****************************";
	cout<<"\n\t\t\t\t\t\t * HOSTEL MANAGEMENT SYSTEM *";
	cout<<"\n\t\t\t\t\t\t ****************************";

	cout<<"\n\n\t\t\tPress enter to continue !!!";
	getchar();
}
void HOSTEL::search() {
    int r;
    cout << "\n Enter Room Number to search: ";
    cin >> r;
    int low = 1, high = 100;
    int mid, flag = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (check(mid) == 2) {
            high = mid - 1;
        } else if (check(mid) == 1) {
            low = mid + 1;
        } else {
            ifstream fin("Record.txt", ios::in);
            while (fin.read((char *) this, sizeof(HOSTEL))) {
                if (room_no == r) {
                    cout << "\n Student Details";
                    cout << "\n ----------------";
                    cout << "\n\n Room Number: " << room_no;
                    cout << "\n Name: " << name;
                    cout << "\n Address: "<<address;
                    cout<< "\n Phone: " << phone;
                    cout << "\n Floor: " << floor;
                    cout << "\n\n Press any key to continue.";
                    flag = 1;
                    getchar();
                }
            }
        fin.close();
        break;
    }
    }
    if (flag == 0) {
    cout << "\n\n Room number not found!";
}

}

int main()
{
	h.hello();

	h.main_menu();
	getch();
	return 0;
}





