#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

class Bank_Account
{
	private:
		char username[100],email[50],phone[20],password[100],accountType[50],re_pass[100],pin[10],re_pin[10],tran[100];
		int age,acc_no,damt=0,wamt=0;
		double balance;
		double min;
		
	public:
		char* getuser()
		{
			return username;
		}
		char* getpass()
		{
			return password;
		}
		void setDetails();
		void lbal();
		void viewAccountDetails();
		void viewTransactionDetails();
		void withdraw(char x[100], char y[100]);
		void deposit(char u[100], char p[100]);
		bool authenticate(char user_check[100], char pass_check[100]);
		bool authenticate_p(char user_check[100], char phone_check[20]);
		bool authenticate_a(char user_check[100], int acc_check);
};

void Bank_Account::setDetails()
{
	cout<<"Namaste! Welcome to National Bank!\nWe Hope that you are having a great day.\n\nPlease Register to continue : ";
	a1:
	int a=0;
	fflush(stdin);
	cout<<endl<<"Enter username: ";
	cin.getline(username,100);
	for(int i=0;i<100;i++)
	{
		if(username[i]==' ')
		{
			a=1;
			break;
		}
	}
	if(a==1)
	{
		cout<<"\n\n***User Name Shouldn't Contain Any Space***\n***Please Try Again***\n\n";
		goto a1;
	}
	else
	{
		fflush(stdin);
		cout<<"\nEnter Email: ";
		cin.getline(email,50);
		a2:
		int b=1;
		fflush(stdin);
		cout<<"\nEnter Phone: ";
		cin.getline(phone,20);
		int count;
		count=strlen(phone);
		for(int i=0;i<=10;i++)
		{
			if(phone[i]>='0' && phone[i]<='9')
			{
				b=0;
			}
		}
		if(b==1 || count<10)
		{
			cout<<"\n\n***Incorrect Phone Number***\n***Please Try Again***\n\n";
			goto a2;
		}
		else
		{
			a3:
			cout<<"\nEnter Age: ";
			cin>>age;
			if(age>150)
			{
				cout<<"\n\n***Error***\n***Please Try Again***\n\n";
				goto a3;
			}
			else
			{
				a4:
				int q=0,r=0;
				cout<<"\nEnter password: ";
				fflush(stdin);
				while(1)
				{
					char c=getch();
					if(c=='\r')
					{
						password[q]='\0';
						break;
					}
					if(c=='\b')
					{
						cout<<"\b \b";
						q--;
					}
					else
					{
						password[q]=c;
						cout<<"*";
						q++;
					}
				}
				cout<<"\nRe-Enter password: ";
				fflush(stdin);
				while(1)
				{
					char c=getch();
					if(c=='\r')
					{
						re_pass[r]='\0';
						break;
					}
					if(c=='\b')
					{
						cout<<"\b \b";
						r--;
					}
					else
					{
						re_pass[r]=c;
						cout<<"*";
						r++;
					}
				}
				if(strcmp(password,re_pass)==0)
				{
					int type;
					cout<<"\n\nType of account: \n\nPress 1 --> Savings Account \nPress 2 --> Current Account \n\nEnter Your Choice : ";
					cin>>type;
					if(type==1)
					{
						a5:
						min=2000;
						cout<<"\n\nFor Opeining Savings Account The Minimum Balance Is 2000 Rs \nPlease Enter Your Opening Balance : ";
						cin>>balance;
						if(min>balance)
						{
							cout<<"\n\n***Opening Balance Is Less Than The Minimum Required Balance***\n***Please Try Again***\n\n";
							goto a5;
						}
						else
						{
							strcpy(accountType,"Savings");
							a7:
							cout<<"\nEnter Your 4 Digit Transaction Pin : ";
							int q=0;
							fflush(stdin);
							while(1)
							{
								char c=getch();
								if(c=='\r')
								{
									pin[q]='\0';
									break;
								}
								if(c=='\b')
								{
									cout<<"\b \b";
									q--;
								}
								else if(c>='0' && c<='9')
								{
									pin[q]=c;
									cout<<"*";
									q++;
								}
							}
							int len=strlen(pin);
							if(len<4 || len>4)
							{
								cout<<"\n\n***Transaction Pin Shouldn't Be More Than 4 Numbers***\n***Please Try Again***\n\n";
								pin[0] = '\0';
								q=0;
								goto a7;
							}
							cout<<"\nRe-Enter Your 4 Digit Transaction Pin : ";
							int r=0;
							fflush(stdin);
							while(1)
							{
								char c=getch();
								if(c=='\r')
								{
									re_pin[r]='\0';
									break;
								}
								if(c=='\b')
								{
									cout<<"\b \b";
									r--;
								}
								else if(c>='0' && c<='9')
								{
									re_pin[r]=c;
									cout<<"*";
									r++;
								}
							}
							int len1=strlen(re_pin);
							if(len<4 || len>4)
							{
								cout<<"\n\n***Transaction Pin Shouldn't Be More Than 4 Numbers***\n***Please Try Again***\n\n";
								re_pin[0] = '\0';
								r=0;
								goto a7;
							}
							
							if(strcmp(pin,re_pin)==0)
							{							
								cout<<"\n\n*****You Have Registered Successfully*****";
								time_t t1;
								srand(time(0));
								acc_no=rand()%1000000;
								cout<<endl<<endl<<"*****New Unique Account Number Generated Successfully*****";
								cout<<endl<<endl<<"\nYour New Account Number Is "<<acc_no;
							}
							else
							{
								cout<<"\n\n***Both The Pin Doesn't Match***\n***Please Try Again***\n\n";
								pin[0] = '\0';
								q=0;
								re_pin[0] = '\0';
								r=0;
								goto a7;
							}
						}
					}
					else if(type==2)
					{
						a6:
						min=10000;
						cout<<"\n\nFor Opeining Current Account The Minimum Balance Is 10000 Rs \nPlease Enter Your Opening Balance : ";
						cin>>balance;
						if(min>balance)
						{
							cout<<"\n\n***Opening Balance Is Less Than The Minimum Required Balance***\n***Please Try Again***\n\n";
							goto a6;
						}
						else
						{
							strcpy(accountType,"Current");
							cout<<"\nEnter Your 4 Digit Transaction Pin : ";
							int w=0;
							fflush(stdin);
							while(1)
							{
								char c=getch();
								if(c=='\r')
								{
									pin[w]='\0';
									break;
								}
								if(c=='\b')
								{
									cout<<"\b \b";
									w--;
								}
								else if(c>='0' && c<='9')
								{
									pin[w]=c;
									cout<<"*";
									w++;
								}
							}
							int len=strlen(pin);
							if(len<4 || len>4)
							{
								cout<<"\n\n***Transaction Pin Should Be Of 4 Digits***\n***Please Try Again***\n\n";
								pin[0] = '\0';
								w=0;
								goto a7;
							}
							cout<<"\nRe-Enter Your 4 Digit Transaction Pin : ";
							int u=0;
							fflush(stdin);
							while(1)
							{
								char c=getch();
								if(c=='\r')
								{
									re_pin[u]='\0';
									break;
								}
								if(c=='\b')
								{
									cout<<"\b \b";
									u--;
								}
								else if(c>='0' && c<='9')
								{
									re_pin[u]=c;
									cout<<"*";
									u++;
								}
							}
							int len2=strlen(re_pin);
							if(len<4 || len>4)
							{
								cout<<"\n\n***Transaction Pin Should Be Of 4 Digits***\n***Please Try Again***\n\n";
								re_pin[0] = '\0';
								u=0;
								goto a7;
							}
							
							if(strcmp(pin,re_pin)==0)
							{							
								cout<<"\n\n*****You Have Registered Successfully*****";
								time_t t1;
								srand(time(0));
								acc_no=rand()%1000000;
								cout<<endl<<endl<<"*****New Unique Account Number Generated Successfully*****";
								cout<<endl<<endl<<"\nYour New Account Number Is "<<acc_no;
							}
							else
							{
								cout<<"\n\n***Both The Pin Doesn't Match***\n***Please Try Again***\n\n";
								pin[0] = '\0';
								w=0;
								re_pin[0] = '\0';
								u=0;
								goto a7;
							}
						}
					}
					else
					{
						cout<<"\n\n***Invalid Choice***\n***Please Try Again Later***\n\n";
					}
				}
				else
				{
					cout<<"\n\n***Both The Password Doesn't Match***\n***Please Try Again***\n\n";
					password[0] = '\0';
					q=0;
					re_pass[0] = '\0';
					r=0;
					goto a4;
				}
			}
		}
	}
}

void Bank_Account::viewAccountDetails()
{
	cout<<acc_no<<setw(20)<<username<<setw(30)<<email<<setw(25)<<phone<<setw(25)<<accountType<<setw(28)<<balance<<endl;
}

void Bank_Account::viewTransactionDetails()
{
	float tamt=damt==0?wamt:damt;
	cout<<acc_no<<setw(20)<<tran<<setw(23)<<tamt<<setw(28)<<balance<<endl;
}

void Bank_Account::lbal()
{
	if(balance<=2000)
	{
		cout<<acc_no<<setw(20)<<username<<setw(30)<<email<<setw(25)<<phone<<setw(25)<<accountType<<setw(28)<<balance<<endl;
	}
}

Bank_Account b;
fstream f;
fstream fout;

void write()
{
	f.open("login.dat",ios::binary|ios::app);
	b.setDetails();
	f.write((const char*)&b,sizeof(b));
	f.close();
}

void read()
{
	f.open("login.dat",ios::binary|ios::in);
	while(f.read((char*)&b,sizeof(Bank_Account)))
	{
		b.viewAccountDetails();
	}
	f.close();
}

void read_tran_a()
{
	f.open("logs.dat",ios::binary|ios::in);
	while(f.read((char*)&b,sizeof(Bank_Account)))
	{
		b.viewTransactionDetails();
	}
	f.close();
}

void read_tran(char x[100], char y[100])
{
	f.open("logs.dat",ios::binary|ios::in);
	while(f.read((char*)&b,sizeof(Bank_Account)))
	{
		if(strcmp(x,b.getuser())==0 && strcmp(y,b.getpass())==0)
		{
			b.viewTransactionDetails();
		}
	}
	f.close();
}

bool Bank_Account::authenticate(char user_check[100], char pass_check[100])
{
	f.open("login.dat",ios::binary|ios::in);
	while(f.read((char*)&b,sizeof(b)))
	{
		if(strcmp(user_check,b.username)==0 && strcmp(pass_check,b.password)==0)
		{
			return true;
		}
	}
	f.close();
	return false;
}

bool Bank_Account::authenticate_p(char user_check[100], char phone_check[10])
{
	f.open("login.dat",ios::binary|ios::in);
	while(f.read((char*)&b,sizeof(b)))
	{
		if(strcmp(user_check,b.username)==0 && strcmp(phone_check,b.phone)==0)
		{
			return true;
		}
	}
	f.close();
	return false;
}

bool Bank_Account::authenticate_a(char user_check[100], int acc_check)
{
	f.open("login.dat",ios::binary|ios::in);
	while(f.read((char*)&b,sizeof(b)))
	{
		if(strcmp(user_check,b.username)==0 && acc_check==b.acc_no)
		{
			return true;
		}
	}
	f.close();
	return false;
}

void Bank_Account::deposit(char u[100],char p[100])
{
	int n1=0,n2=0,n5=0,n20=0;
	double amt;
	bool found=false;
	
	if(b.authenticate(u,p))
	{
		cout<<"\n\n***Error In Opening The Account***\n\n";
		return;
	}
	
	f.open("login.dat",ios::binary|ios::in|ios::out);
	while(f.read((char*)&b,sizeof(Bank_Account)))
	{
		if(strcmp(u,username)==0 && strcmp(p,password)==0)
		{
			int t=f.tellp();
			found=true;
			cout<<"\nCurrent Balance: "<<balance;
			cout<<"\nEnter the amount to be deposited: ";
			cin>>amt;
			cout<<"\nEnter the number of notes of the following: \n100:";
			cin>>n1;
			cout<<"\n200: ";
			cin>>n2;
			cout<<"\n500: ";
			cin>>n5;
			cout<<"\n2000: ";
			cin>>n20;
			if(n1*100+n2*200+n5*500+n20*2000>amt)
			{
				cout<<"\n\n***Please Enter The Number Of Notes Correctly***\n\n";
				break;
			}
			b.balance+=amt;
			wamt=0;
			damt=amt;
			strcpy(tran,"Deposite");
			f.seekp(t-sizeof(Bank_Account));
			f.write((const char*)&b,sizeof(Bank_Account));
			fout.open("logs.dat",ios::binary|ios::app);
			fout.write((const char*)&b,sizeof(Bank_Account));
			fout.close();
			cout<<"\n\nSuccess! The amount is deposited to your account \nRemaining Balance: "<<balance<<endl<<endl;
			break;
		}
	}
	if(found!=1)
	{
		cout<<"\n\n***1Error In Opening The Account***\n\n";
	}
	f.close();
}

void Bank_Account::withdraw(char x[100],char y[100])
{
	char temp[10]={};
	double amt;
	bool found=false;
	
	if(b.authenticate(x,y))
	{
		cout<<"\n\n***Error In Opening The Account***\n\n";
		return;
	}
	
	f.open("login.dat",ios::binary|ios::in|ios::out);
	while(f.read((char*)&b,sizeof(Bank_Account)))
	{
		if(strcmp(x,username)==0 && strcmp(y,password)==0)
		{
			int t=f.tellp();
			found=true;
			cout<<"\nEnter the amount to be withdrawn: ";
			cin>>amt;
			cout<<"\nEnter Your Transaction Pin: ";
			fflush(stdin);
			int z=0;
			while(1)
			{
				char c=getch();
				if(c=='\r')
				{
					temp[z]='\0';
					break;
				}
				if(c=='\b')
				{
					cout<<"\b \b";
					z--;
				}
				else if(c>='0' && c<='9')
				{
					temp[z]=c;
					cout<<"*";
					z++;
				}
			}
			cout<<"\n...Processing";
			sleep(3);
			if(strcmp(temp,pin)==0)
			{
				int temp1;
				temp1=balance-amt;
				if(temp1<min)
				{
					cout<<"\n\n***Your Account Doesn't Have Required Funds***\n\n***Please Try Again Later***\n\n";
					break;
				}
				else
				{
					balance-=amt;
					damt=0;
					wamt=amt;
					strcpy(tran,"Withraw");
					f.seekp(t-sizeof(Bank_Account));
					f.write((const char*)&b,sizeof(Bank_Account));
					fout.open("logs.dat",ios::binary|ios::app);
					fout.write((const char*)&b,sizeof(Bank_Account));
					fout.close();
					cout<<"\n\nSuccess! "<<amt<<" withdrawn from your account \nRemaining amount: "<<balance<<endl<<endl;
				}
			}
			else
			{
				cout<<"\n\n***Your Transaction Pin Is Incorrect***\n\n***Please Try Again Later***\n\n";
				temp[0] = '\0';
				z=0;
				break;
			}
			break;
		}
	}
	if(found!=1)
	{
		cout<<"\n\n***1Error In Opening The Account***\n\n";
	}
	f.close();
}

void low_bal()
{
	f.open("login.dat",ios::binary|ios::in|ios::out);
	f.read((char*)&b,sizeof (b));
	while(!f.eof())
	{
		int tell=f.tellp();
		b.lbal();
		f.seekp(tell-sizeof(b));
		f.write((char*)&b,sizeof(b));
		f.read((char*)&b,sizeof (b));
	}
	f.close();
}

void already_user(char x[100],char y[100],char u[100],char p[100])
{
	int ch2;
	while(1)
	{
		cout<<"\n\nMenu : \nPress 1 --> To View Account Details \nPress 2 --> To View Transaction Details \nPress 3 --> To Withdraw Money \nPress 4 --> To Deposit Money \nPress 5 --> To Go Back To Main Menu \n\nEnter Your Choice : ";
		cin>>ch2;
		if(ch2==1)
		{
			system("cls");
			cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"AccNo"<<setw(20)<<"Username"<<setw(22)<<"E-mail"<<setw(30)<<"PhoneNo"<<setw(28)<<"AccType"<<setw(30)<<"Balance"<<endl;
			cout<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			b.viewAccountDetails();
			cout<<endl<<endl;
		}
		else if(ch2==2)
		{
			system("cls");
			cout<<endl<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"AccNo"<<setw(20)<<"Transaction"<<setw(30)<<"Trans_Amount"<<setw(20)<<"Balance"<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;
			read_tran(x,y);
			cout<<endl<<endl;
		}
		else if(ch2==3)
		{
			system("cls");
			cout<<"\n\n--------------------Withdraw Amount--------------------\n";
			b.withdraw(x,y);
		}
		else if(ch2==4)
		{
			system("cls");
			cout<<"\n\n--------------------Deposit Amount--------------------\n";
			b.deposit(u,p);
		}
		else if(ch2==5)
		{
			break;
		}
		else
		{
			cout<<"\n\nInvalid Input***\n\n***Please Try Again***\n\n";
		}
	}
}

void forgot_pass()
{
	char user_check[100]={},u[100]={},p[100]={},x[100]={},y[100]={},phone_check[20]={};
	int f_ch,acc_check;
	
	cout<<"\n\nPress 1 --> To Login Via Username And Account Number \nPress 2 --> To Login Via Username And Phone Number \nPress 3 --> To Go Back To Main Menu \n\nEnter Your Choice : ";
	cin>>f_ch;
	if(f_ch==1)
	{
		cout<<endl<<endl<<"Please Enter Your Username: ";
		fflush(stdin);
		cin.getline(user_check,100);
		strcpy(u,user_check);
		strcpy(x,user_check);
		cout<<"Please Enter Your Account Number: ";
		cin>>acc_check;
		
		if(b.authenticate_a(user_check,acc_check)!=1)
		{
			cout<<"\n\n***No Account Found***\n***Please Register Your Account First***\n\n";
			return;
		}
		else
		{
			strcpy(p,b.getpass());
			strcpy(y,b.getpass());
			cout<<"\n\n*****WELCOME USER*****\n\n";
			already_user(x,y,u,p);
		}
	}
	else if(f_ch==2)
	{
		cout<<endl<<endl<<"Please Enter Your Username: ";
		fflush(stdin);
		cin.getline(user_check,100);
		strcpy(u,user_check);
		strcpy(x,user_check);
		cout<<"Please Enter Your Phone Number: ";
		fflush(stdin);
		cin.getline(phone_check,20);
		
		if(b.authenticate_p(user_check,phone_check)!=1)
		{
			cout<<"\n\n***No Account Found***\n***Please Register Your Account First***\n\n";
			return;
		}
		else
		{
			strcpy(p,b.getpass());
			strcpy(y,b.getpass());
			cout<<"\n\n*****WELCOME USER*****\n\n";
			already_user(x,y,u,p);
		}
	}
	else if(f_ch==3)
	{
		return;
	}
	else
	{
		cout<<"\n\n***Invalid Choice***\n***Please Try Again Later***\n\n";
		return;
	}
}

int main()
{
	//remove("login.dat");
	//remove("logs.dat");
	int ch,recheck,k=0,a_ch,l=0;
	char user_check[100]={},pass_check[100]="",u[100]={},p[100]={},x[100]={},y[100]={},admin_name[100]={},admin_password[100]={};
	cout<<"\n*****WELCOME TO NATIONAL BANK*****";
	fflush(stdin);
	while(1)
	{
		cout<<"\n\nMain Menu : \nPress 1 --> To Register New Account \nPress 2 --> If You Are Already A User \nPress 3 --> To Exit \n\nEnter Your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				system("cls");
				write();
				break;
			case 2:
				system("cls");
				b1:
				cout<<endl<<endl<<"Please Enter Your Username: ";
				fflush(stdin);
				cin.getline(user_check,100);
				strcpy(u,user_check);
				strcpy(x,user_check);
				cout<<"Please Enter Your Password: ";
				fflush(stdin);
				while(1)
				{
					char c=getch();
					if(c=='\r')
					{
						pass_check[k]='\0';
						break;
					}
					if(c=='\b')
					{
						cout<<"\b \b";
						k--;
					}
					else
					{
						pass_check[k]=c;
						cout<<"*";
						k++;
					}
				}
				strcpy(p,pass_check);
				strcpy(y,pass_check);
				
				if(b.authenticate(user_check,pass_check)!=1)
				{
					cout<<"\n\n***No Account Found***\n\n";
					cout<<"Press 1 --> Try Again \nPress 2 --> Forgot Password \nPress 3 --> Back To Main Menu \n\nEnter Your Choice : ";
					cin>>recheck;
					if(recheck==1)
					{
						pass_check[0] = '\0';
						k=0;
						goto b1;
					}
					else if(recheck==2)
					{
						system("cls");
						forgot_pass();
					}
					else if(recheck==3)
					{
						break;
					}
					else
					{
						cout<<"\n\n***Invalid Choice***\n***Please Try Again Later***\n\n";
						break;
					}
				}
				else
				{
					cout<<"\n\n*****WELCOME USER*****\n\n";
					already_user(x,y,u,p);
				}
				break;
				
			case 3:exit(1);
			
			case 101:
				system("cls");
				cout<<"\n\n*****Admin Login*****\n\n";
				fflush(stdin);
				cout<<"Enter Admin Name : ";
				cin.getline(admin_name,100);
				cout<<"Enter Password : ";
				fflush(stdin);
				while(1)
				{
					char c=getch();
					if(c=='\r')
					{
						admin_password[l]='\0';
						break;
					}
					if(c=='\b')
					{
						cout<<"\b \b";
						l--;
					}
					else
					{
						admin_password[l]=c;
						cout<<"*";
						l++;
					}
				}
				
				if(strcmp(admin_name,"Manav")==0 && strcmp(admin_password,"admin@123")==0)
				{
					while(1)
					{
						cout<<"\n\n*****Admin Login Successfull*****";
						cout<<"\n\nMenu : \nPress 1 --> To View All Accounts With Average Monthly Low Balance \nPress 2 --> To View All Accounts \nPress 3 --> To View All Transactions \nPress 4 --> To Go Back To Main Menu \n\nEnter Your Choice : ";
						cin>>a_ch;
						if(a_ch==1)
						{
							cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
							cout<<"AccNo"<<setw(20)<<"Username"<<setw(22)<<"E-mail"<<setw(30)<<"PhoneNo"<<setw(28)<<"AccType"<<setw(30)<<"Balance"<<endl;
							cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
							low_bal();
						}
						else if(a_ch==2)
						{
							cout<<endl<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
							cout<<"AccNo"<<setw(20)<<"Username"<<setw(22)<<"E-mail"<<setw(30)<<"PhoneNo"<<setw(28)<<"AccType"<<setw(30)<<"Balance"<<endl;
							cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
							read();
						}
						else if(a_ch==3)
						{
							cout<<endl<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
							cout<<"AccNo"<<setw(20)<<"Transaction"<<setw(30)<<"Trans_Amount"<<setw(20)<<"Balance"<<endl;
							cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
							read_tran_a();
						}
						else if(a_ch==4)
						{
							break;
						}
					}
					break;
				}
				else
				{
					cout<<"\n\n***Error***\n***Please Try Again Later***\n\n";
					admin_password[0] = '\0';
					l=0;
					break;
				}
				break;
				
			default:cout<<"\n\n***Invalid Choice***\n***Please Try Again Later***\n\n";break;
		}
	}
}
