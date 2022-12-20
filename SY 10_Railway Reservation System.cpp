/*
Object Oriented Programming Course Project

Title: Railway Reservation System

Group No: SY 10

Div: CS-A

Batch: B2

Group Members:

Name                      Roll No            GR No.

Spurthi Bhat                32              11910396

Rutuja Bhirud               33              11911053

Vaishnavi Bhokare           34              11910503

Ishaan Bhutada              37              11910147

Aditya Chavan               48              11910852


Description: Railway Reservation System is a project developed in C++ and has been implemented with the concepts of Encapsulation and
             Abstraction of Object Oriented programming. It has features such as booking tickets,canceling tickets,checking the information
             about availability of trains and number of seats. It has an administrator mode which is password protected and the administrator
             can add trains,delete trains and view passenger information.

Input: The user has to enter all the details required while booking the ticket and he/she has to enter the phone number entered during the booking
       of a ticket while canceling a particular ticket. To enter the admin mode the user has to enter the password (abcd). For adding the trains
       the admin has to enter all the details required regarding the train. For deleting a train admin has to add the train number of that train.
       After all the operation are completed the admin/user can choose to exit the program.

Output: According to the input given by the user appropriate functions will be carried out.Through view information and view passenger options the
        available trains and seats as well as passenger information will be displayed accordingly.


*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<iostream>
using namespace std;

//Function Declarations
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void add_train();
void delete_train();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();

int k=0,u=0;//global variables for maintaining the number of seats and trains in database

char trn_nmbr[100],name[100],phn[100];

//Class for adding the details regarding the train

class adddata
{
    public:
	char si[10]; //serial number
	char train_number[10];
	char train_name[100];
	char start[100];
	char bp1[100];//boarding point 1
	char bp2[100];//boarding point 2
	char destination[100];
	int price1;//price between start and boarding point1
	int price2;//price between boarding point1 and boarding point2
	int price3;//price between boarding point2 and destination
	int seat1;//seats available between start and boarding point1
	int seat2;//seats available between boarding point1 and boarding point2
	int seat3;//seats available between boarding point2 and destination
	char time[10];//duration of travel

} add[1000]; //an array of 1000 objects

//class for storing booked ticket information
class bookticket
{
    public:
	char train_number[20];
	char st[100]; //starting point
	char de[100]; //destination
	char name[100];
	char phone[20];
	char date[15];
	int seat1;//seat between start and boarding point1
	int seat2;//seat between start and boarding point1
	int seat3;//seat between start and boarding point1

}book_ticket[1000];//an array of 1000 objects

//Function for displaying the main menu to users

int main()
{
	aread();
	viewpassengers_read();
	int ch;
	time_t currentTime;
	time(&currentTime);
	cout<<"\n\t\t\t     "<<ctime(&currentTime)<<"\n";

	cout<<"\n\t\t\t*********************************\n";
	cout<<"\t\t\t---RAILWAY RESERVATION SYSTEM----\n";
	cout<<"\t\t\t*********************************\n";
	cout<<"\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n";
	cout<<"\n\n\t\t\t\t      MENU\n";
	cout<<"\t\t\t             ******";
	cout<<"\n\t\t\t[1] VIEW INFORMATION\n";
	cout<<"\n\t\t\t[2] BOOK TICKET\n";
	cout<<"\n\t\t\t[3] CANCEL TICKET\n";
	cout<<"\n\t\t\t[4] ADMIN";
	cout<<"\n\n\t\t\t[5] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";

	cin>>ch;
	switch(ch)
	{
		case 1:
			viewinfo();
			break;
        case 2:
            bookticket();
            break;
        case 3:
            cancelticket();
            break;

        case 4:
            password();
            break;
        case 5:
            cout<<"\n\t\t\t =========================================\n";
            cout<<"\t\t\t -------RAILWAY RESERVATION SYSTEM--------\n";
            cout<<"\t\t\t -----------------------------------------\n";
            cout<<"\t\t\t -----------THANKS FOR VISITING-----------\n";
            cout<<"\t\t\t =========================================\n";
            exit(0);
            break;
        default:

            cout<<"\n\t\t\t==============================================\n";
            cout<<"\t\t\t   ----------RAILWAY RESERVATION SYSTEM----------\n";
            cout<<"\t\t\t   ==============================================\n";
            cout<<"\n\n\t\t\t!!!!!!!!YOU ENTERED WRONG CHOICE!!!!!!!!\n";
            cout<<"\n\n\t\t\t===========START AGAIN PLEASE===========\n";
            exit(0);

	}//end of switch statement

	return 0;

}//end of main function

//Function for booking tickets

void bookticket()
{
	int c,j,n,i,found=-1;
	char v,train_number[10];
	aread();
	cout<<"\n\n\t\t\t==============================================";
	cout<<"\n\t\t\t----------RAILWAY RESERVATION SYSTEM----------\n";
	cout<<"\t\t\t==============================================";
	cout<<"\n\n\t\t\thow many ticket do you want to buy: ";
	cin>>n;
	for(j=u;j<u+n;j++)
	{
        cout<<"\n\n\t\t\tEnter train number: ";
        cin>>book_ticket[j].train_number;
        for(i=0;i<k;i++)
        {
            if(strcmp(book_ticket[j].train_number,add[i].train_number)==0)
            {
                if(add[i].seat1==0 && add[i].seat2==0 && add[i].seat3==0)
                {
                    cout<<"\n\n\t\t\tnot available seat";
                    main();
            }
            else
            {
                found=1;
                cout << "\n\t\t \tEnter Details\n";
                cout<<"\n\t\t\tenter date: ";
                cin>>book_ticket[j].date;
                book_ticket[j].date[10]='\n';
                cout<<"\n\t\t\tenter your name: ";
                cin.ignore();
                cin.getline(book_ticket[j].name,100);
                cout<<"\n\t\t\tenter your boarding point: ";
                cin>>book_ticket[j].st;
                cout<<"\n\t\t\tenter your destination: ";
                cin>>book_ticket[j].de;
                cout<<"\n\t\t\tenter your phone number: ";
                cin>>book_ticket[j].phone;


                if(strcmp(book_ticket[j].st,add[i].start)==0 && strcmp(book_ticket[j].de,add[i].bp1)==0){

                    cout<<"\n\t\t\t seat number : "<<add[i].seat1;
                    cout << "\n\t\t\t Price: " << add[i].price1;
                    add[i].seat1--;

                }//end of if condition

                else if(strcmp(book_ticket[j].st,add[i].start)==0 && strcmp(book_ticket[j].de,add[i].bp2)==0){

                    if(add[i].seat1<add[i].seat2){

                        cout<<"\n\t\t\t seat number : "<<add[i].seat1;
                        int p;
                        p= add[i].price1+ add[i].price2;
                        cout << "\n\t\t\t Price: " << p;

                    }//end of if condition

                    else{
                        cout<<"\n\t\t\t seat number : "<<add[i].seat2;
                        int p;
                        p= add[i].price1+ add[i].price2;
                        cout << "\n\t\t\t Price: " << p;

                    }//end of else condition

                add[i].seat1--;
                add[i].seat2--;

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].start)==0 && strcmp(book_ticket[j].de,add[i].destination)==0){
                    if(add[i].seat1<add[i].seat2 && add[i].seat1<add[i].seat3){

                            cout<<"\n\t\t\t seat number : "<<add[i].seat1;
                            int p;
                            p= add[i].price1+ add[i].price2+ add[i].price3;
                            cout << "\n\t\t\t Price: " << p;

                    }//end of if condition

                    else if(add[i].seat2<add[i].seat1 && add[i].seat2<add[i].seat3){

                            cout<<"\n\t\t\t seat number : "<<add[i].seat2;
                            int p;
                            p= add[i].price1+ add[i].price2+ add[i].price3;
                            cout << "\n\t\t\t Price: " << p;

                    }//end of else if condition

                    else{


                            cout<<"\n\t\t\t seat number : "<<add[i].seat3;
                            int p;
                            p= add[i].price1+ add[i].price2+ add[i].price3;
                            cout << "\n\t\t\t Price: " << p;

                    }//end of else condition

                    add[i].seat1--;
                    add[i].seat2--;
                    add[i].seat3--;

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].bp1)==0 && strcmp(book_ticket[j].de,add[i].bp2)==0){

                        cout<<"\n\t\t\t seat number : "<<add[i].seat2;
                        add[i].seat2--;
                        cout << "\n\t\t\t Price: " <<  add[i].price2;


            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].bp1)==0 && strcmp(book_ticket[j].de,add[i].destination)==0){

                    if(add[i].seat2<add[i].seat3){

                            cout<<"\n\t\t\t seat number : "<<add[i].seat2;
                            int p;
                            p= add[i].price2+ add[i].price3;
                            cout << "\n\t\t\t Price: " << p;

                    }//end of if condition

                    else{

                            cout<<"\n\t\t\t seat number : "<<add[i].seat3;
                            int p;
                            p= add[i].price2+ add[i].price3;
                            cout << "\n\t\t\t Price: " << p;

                    }//end of else condition

                    add[i].seat2--;
                    add[i].seat3--;

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].bp2)==0 && strcmp(book_ticket[j].de,add[i].destination)==0){

                        cout<<"\n\t\t\t seat number : "<<add[i].seat3;
                        cout << "\n\t\t\t Price: " <<  add[i].price3;
                        add[i].seat3--;

            }//end of else if condition


            cout<<"\n\n\t\t\t==============================================";
            cout<<"\n\t\t\t----------RAILWAY RESERVATION SYSTEM----------\n";
            cout<<"\t\t\t==============================================";
            cout<<"\t\t\t --------------TICKET BOOKED--------------\n";
            cout<<"\t\t\t -----------------------------------------\n";
            cout<<"\t\t\t --------------Happy Journey--------------\n";
            book_ticket[j].seat1=add[i].seat1;
            book_ticket[j].seat2=add[i].seat2;
            book_ticket[j].seat3=add[i].seat3;
            bookticket_write();
            awrite();

         }//end of else condition

        }//end of if condition

      }//end of inner for  loop
        if(found==-1)
        {
            cout<<"\n\n\t\t\t Train not found!!!";
            main();

        }//end of if condition

    }//end of outer for loop
            u=j;
            bookticket_write();
            cout<<"\n\n\t\t\tenter '1' for main menu & press any key to exit: ";
            cin>>c;

                if(c==1)
                {
                    main();

                }//end of if statement

                if(c!=1)
                {
                    exit;

                }//end of if condition

}//end of book ticket function definition

//Function for canceling ticket

void cancelticket()
{
	viewpassengers_read();
    char pnnmbr[100];
    int location = -1,e,i;
    cout<<"\n\n\t\t\tenter phone number: ";
    cin>>pnnmbr;
    for (e=0;e<u;e++)
    {
        if (strcmp(pnnmbr,book_ticket[e].phone)==0)
        {

            for(i=0;i<k;i++)
            {
                if(strcmp(book_ticket[e].train_number,add[i].train_number)==0)
                {

                     if(strcmp(book_ticket[e].st,add[i].start)==0 && strcmp(book_ticket[e].de,add[i].bp1)==0){

                             add[i].seat1++;


                     }//end of if condition

                    else if(strcmp(book_ticket[e].st,add[i].start)==0 && strcmp(book_ticket[e].de,add[i].bp2)==0){

                          add[i].seat1++;
                          add[i].seat2++;

                    }//end of else if condition

                    else if(strcmp(book_ticket[e].st,add[i].start)==0 && strcmp(book_ticket[e].de,add[i].destination)==0){


                            add[i].seat1++;
                            add[i].seat2++;
                            add[i].seat3++;

                    }//end of else if condition

                    else if(strcmp(book_ticket[e].st,add[i].bp1)==0 && strcmp(book_ticket[e].de,add[i].bp2)==0){

                            add[i].seat2++;

                    }//end of else if condition

                    else if(strcmp(book_ticket[e].st,add[i].bp1)==0 && strcmp(book_ticket[e].de,add[i].destination)==0){

                            add[i].seat2++;
                            add[i].seat3++;

                    }//end of else if condition

                    else if(strcmp(book_ticket[e].st,add[i].bp2)==0 && strcmp(book_ticket[e].de,add[i].destination)==0){

                            add[i].seat3++;

                    }//end of else if condition

            }//end of if condition

        }//end of inner for loop


        awrite();
        location=e;
        break;

    }//end of if condition

  }//end of for loop

    if (location==-1)
    {
        cout<< ("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        main();

    }//end of if condition

    else
    {
        for (e=location;e<u;e++)
        {
            strcpy(book_ticket[e].date,book_ticket[e+1].date);
            strcpy(book_ticket[e].train_number,book_ticket[e+1].train_number);
            strcpy(book_ticket[e].name,book_ticket[e+1].name);
            strcpy(book_ticket[e].phone,book_ticket[e+1].phone);
            strcpy(book_ticket[e].st,book_ticket[e+1].st);
            strcpy(book_ticket[e].de,book_ticket[e+1].de);
            book_ticket[e+1].seat1=book_ticket[e].seat1;
            book_ticket[e+1].seat2=book_ticket[e].seat2;
            book_ticket[e+1].seat3=book_ticket[e].seat3;

            bookticket_write();

        }//end of for loop

        u--;
        bookticket_write();
        cout<<"\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>";
        main();

    }//end of else condition

}//end of cancel ticket function definition

//Function for accessing the facilities in administrator mode

void admin()
{
	int choice;
	cout<<"\n     =================================================================";
    cout<<"\n     ********************RAILWAY RESERVATION SYSTEM*******************";
    cout<<"\n     =================================================================";
    cout<<"\n\n";
	cout<<"               <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n";
	cout<<"\n\n";
	cout<<"                 ************************************\n";
	cout<<"                 ||      CHOOSE YOUR OPERATION     ||\n";
	cout<<"                 ||--------------------------------||\n";
	cout<<"                 ||      [1] VIEW PASSENGERS       ||\n";
	cout<<"                 ||      [2] ADD TRAIN             ||\n";
	cout<<"                 ||      [3] DELETE TRAIN          ||\n";
	cout<<"                 ||      [4] VIEW INFORMATION      ||\n";
	cout<<"                 ||      [5] BACK                  ||\n";
	cout<<"                 ************************************\n\n";
	cout<<"       **********************************************************\n";
	cout<<"\n\t\tENTER YOUR CHOICE: ";
	cin>>choice;

	switch(choice)
	{
		case 1:
                viewpassenger();
                break;
        case 2:
                add_train();
                break;
        case 3:
                delete_train();
                break;
        case 4:
                viewinfo();
                break;
        case 5:
                main();
                break;
        default:

                cout<<"\n\t\t\tyou entered wrong KEY!!!!";
                main();

	}//end of switch statement

}//end of admin function definition

//Function for taking Password and hide it's visibility from screen

string takePassword(){
    string ipt = "";
    char ipt_ch;
    while (true) {

        ipt_ch=_getch();

        // Check whether user enters a special non-printable character
        if (ipt_ch < 32) {

            return ipt;

        }//end of if condition

        ipt.push_back(ipt_ch);

    }//end of while loop

}//end of takePassword function definition

void password()
{

	string number="abcd";
	string pass;

	cout<<"\n\t\t\tenter password: ";

	pass=takePassword();


	if(pass==number)
	{
		cout<<"\n\n\t\t\t<<<<<login successfully>>>>>";
		admin();

	}//end of if condition

	else
	{
		cout<<"\n\n\t\t\t\t   ERROR!!!!!";
		cout<<"\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>";
		main();

	}//end of else condition

}//end of password function definition

//Function for deleting train from the database

void delete_train()
{
	aread();
    char train[100];
    int location = -1,f;
    cout<<"\n\n\tenter train number: ";
    cin>>train;
    for (f=0;f<k;f++)
    {
        if (strcmp(train,add[f].train_number)==0)
        {
            location=f;
            break;

        }//end of if condition

    }//end of for loop

    if (location==-1)
    {
        cout<<"\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n";
        admin();

    }//end of if condition

    else
    {
        for (f=location;f<k;f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].train_number,add[f+1].train_number);
            strcpy(add[f].train_name,add[f+1].train_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].bp1,add[f+1].bp1);
            strcpy(add[f].bp2,add[f+1].bp2);
            strcpy(add[f].destination,add[f+1].destination);
            add[f+1].price1=add[f].price1;
            add[f+1].price2=add[f].price2;
            add[f+1].price3=add[f].price3;
            add[f+1].seat1=add[f].seat1;
            add[f+1].seat2=add[f].seat2;
            add[f+1].seat3=add[f].seat3;
            strcpy(add[f].time,add[f+1].time);
            awrite();

        }//end of for loop

        k--;
        awrite();
		cout<<"\n\n\t<<<<<<<<<<<<<train deleted successfully>>>>>>>>>>>>>";
		admin();

    }//end of else condition

}//end of delete_train function definition

//Function for viewing passengers details and their booking details

void viewpassenger()
{
	int a,j,i;
	viewpassengers_read();
	cout<<"\n\t\t\t       **********************************************************";
	cout<<"\n\t\t\t       ****************RAILWAY RESERVATION SYSTEM****************";
	cout<<"\n\t\t\t       **********************************************************";
	cout<<"\n\n\t\t\tTrain number\t\tName\t\tPhone Number\t\t\tDate\t\tBoarding Station\t\tDestination\t\tSeat Number\n";
	cout<<"\n\t\t\t**********************************************************************************************************************************************************\n";
	for(j=0;j<u;j++)
	{

	    for(i=0;i<k;i++)
        {

            if(strcmp(book_ticket[j].st,add[i].start)==0 && strcmp(book_ticket[j].de,add[i].bp1)==0){

                cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat1+1;

            }//end of if condition

            else if(strcmp(book_ticket[j].st,add[i].start)==0 && strcmp(book_ticket[j].de,add[i].bp2)==0){

                if(add[i].seat1<add[i].seat2){

                    cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat1+1;

                }//end of if condition
                else{

                     cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat2+1;

                }//end of else condition

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].start)==0 && strcmp(book_ticket[j].de,add[i].destination)==0){
                    if(add[i].seat1<add[i].seat2 && add[i].seat1<add[i].seat3){

                        cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<<book_ticket[j].seat1+1;

                    }//end of if condition

                    else if(add[i].seat2<add[i].seat1 && add[i].seat2<add[i].seat3){

                        cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat2+1;

                    }//end of else if condition

                    else{

                        cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat3+1;

                    }//end of else condition

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].bp1)==0 && strcmp(book_ticket[j].de,add[i].bp2)==0){

                cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat2+1;

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].bp1)==0 && strcmp(book_ticket[j].de,add[i].destination)==0){
                    if(add[i].seat2<add[i].seat3){

                        cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat2+1;

                    }//end of if condition

                    else{

                        cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t"<< book_ticket[j].seat3+1;

                    }//end of else condition

            }//end of else if condition

            else if(strcmp(book_ticket[j].st,add[i].bp2)==0 && strcmp(book_ticket[j].de,add[i].destination)==0){

                   cout<<"\n\t\t\t"<< book_ticket[j].train_number<<"\t\t\t"<< book_ticket[j].name <<"\t\t"<< book_ticket[j].phone<<"\t\t"<< book_ticket[j].date<<"\t\t"<<book_ticket[j].st<<"\t\t\t"<< book_ticket[j].de<<"\t\t\t" <<book_ticket[j].seat3+1;

            }//end of else if condition


        }//end of inner for loop


	}//end of outer for loop

	cout<<"\n\t\t\t*********************************************************************************************************************************************************\n";
	cout<<"\n\n\t\t\tenter '1' for main menu & enter '0' for back: ";
	cin>>a;
	if(a==1)
	{
		main();

	}//end of if condition

	if(a==0)
	{
		admin();

	}//end of if condition

}//end of viewpassenger function definition

//Function for adding a train in the database

void add_train()
{

	int ch;
	aread();
	int i,a;
    cout<<"\n\t\t     **********************************************************";
    cout<<"\n\t\t     ****************RAILWAY RESERVATION SYSTEM****************";
	cout<<"\n\t\t     **********************************************************";
	cout<<"\n\n\t\t\thow many trains do you want to add: ";
	cin>>a;
	for(i=k;i<k+a;i++)
	{
		cout<<"\n\t\t\tenter "<<i+1<<" train details: ";
		cout<<"\n\n\t\t\tenter serial number: ";
		cin>>add[i].si;
		cout<<"\n\t\t\tenter train number: ";
		cin>>add[i].train_number;
		cout<<"\n\t\t\tenter train name: ";
		cin>>add[i].train_name;
		cout<<"\n\t\t\tenter start place: ";
		cin>>add[i].start;
		cout<<"\n\t\t\tenter Boarding Point 1: ";
		cin>>add[i].bp1;
		cout<<"\n\t\t\tenter Boarding Point 2: ";
		cin>>add[i].bp2;
		cout<<"\n\t\t\tenter destination place: ";
		cin>>add[i].destination;
		cout<<"\n\t\t\t enter price for travel between " << add[i].start << " and " << add[i].bp1 << ":";
		cin>>add[i].price1;
		cout<<"\n\t\t\t enter price for travel between " << add[i].bp1 << " and " << add[i].bp2 << ":";
		cin>>add[i].price2;
		cout<<"\n\t\t\t enter price for travel between " << add[i].bp2 << " and " << add[i].destination << ":";
		cin>>add[i].price3;
		cout<<"\n\t\t\t enter seat: ";
		cin>>add[i].seat1;
		add[i].seat2=add[i].seat1;
		add[i].seat3=add[i].seat2;
		cout<<"\n\t\t\t enter time: ";
		cin>>add[i].time;

	}//end of for loop

		cout<<"\n\n\t\t\tConfirm train: (y=1/n=0):- ";
		cin>>ch;
		if(ch==1)
		{
			awrite();
			k=i;
			awrite();
			cout<<"\n\n\t\t\t**********************************************************";
            cout<<"\n\t\t\t****************RAILWAY RESERVATION SYSTEM****************";
            cout<<"\n\t\t\t**********************************************************";
			cout<<"\n\n";
			cout<<"\n\t\t\t\t   **********************************";
			cout<<"\n\t\t\t\t   *<<<<<train add successfully>>>>>*";
			cout<<"\n\t\t\t\t   **********************************";
			main();

		}//end of if condition

			if(ch==0)
			{
				admin();
			}//end of if condition

			if((ch!=1)&&(ch!=0))
			{
				main();

			}//end of if condition

}//end of add_train function definition

//Function for viewing Information about the trains

void viewinfo()
{
    int ch,i;
    aread();
    cout<<"\n\t\t     **********************************************************";
    cout<<"\n\t\t     ****************RAILWAY RESERVATION SYSTEM****************";
    cout<<"\n\t\t     **********************************************************";
    cout<<"\n\n\n    SI\t\tTrain number\t\tTrain name\t\tStart place\t\tDestination place\t\t Price\t\tAvailable Seats\t\tTotal Duration\n\n";
    cout<<"     ***************************************************************************************************************************************************************************\n";
	for(i=0;i<k;i++)
	{
	    if(add[i].seat1<=add[i].seat2 && add[i].seat1<=add[i].seat3){

                cout<<"    "<<add[i].si<<"\t\t"<<add[i].train_number <<"\t\t\t"<< add[i].train_name<<"\t\t\t"<<add[i].start <<"\t\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price1+add[i].price2+add[i].price3<< "\t\t\t"<<add[i].seat1 <<"\t\t\t"<<add[i].time <<"\n";

	    }//end of if condition

	    else if(add[i].seat2<=add[i].seat1 && add[i].seat2<=add[i].seat3){

                cout<<"    "<<add[i].si<<"\t\t"<<add[i].train_number <<"\t\t\t"<< add[i].train_name<<"\t\t\t"<<add[i].start <<"\t\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price1+add[i].price2+add[i].price3<< "\t\t\t"<<add[i].seat2 <<"\t\t\t"<<add[i].time <<"\n";

	    }//end of else if condition

	    else {

                cout<<"    "<<add[i].si<<"\t\t"<<add[i].train_number <<"\t\t"<< add[i].train_name<<"\t\t\t"<<add[i].start <<"\t\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price1+add[i].price2+add[i].price3<< "\t\t\t"<<add[i].seat3 <<"\t\t\t"<<add[i].time <<"\n";

	    }//end of else condition


        cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].start <<"\t\t\t"<< add[i].bp1<<"\t\t\t"<<add[i].price1 << "\t\t\t" <<add[i].seat1  <<"\n";
        cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].bp1<<"\t\t\t"<< add[i].bp2<<"\t\t\t"<<add[i].price2 << "\t\t\t" <<add[i].seat2  <<"\n";
        cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].bp2 <<"\t\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price3 << "\t\t\t" <<add[i].seat3 <<"\n";

	    if(add[i].seat2<add[i].seat3){

	   	       cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].bp1 <<"\t\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price2+add[i].price3 << "\t\t\t" <<add[i].seat2  <<"\n";

	    }//end of if condition

	    else {

          cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].bp1 <<"\t\t\t"<< add[i].destination<<"\t\t\t"<<add[i].price2+add[i].price3<< "\t\t\t" <<add[i].seat3  <<"\n";

	    }//end of else condition

	    if(add[i].seat1<add[i].seat2){

	   	       cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].start <<"\t\t\t"<< add[i].bp2<<"\t\t\t"<<add[i].price1+add[i].price2 << "\t\t\t" <<add[i].seat1  <<"\n";

	    }//end of if condition

	    else {

          cout<<"    "<<"\t\t\t"<<"\t\t\t" <<"\t\t\t"<<add[i].start <<"\t\t\t"<< add[i].bp2<<"\t\t\t"<<add[i].price1+add[i].price2<< "\t\t\t" <<add[i].seat2 <<"\n";

	    }//end of else condition

        printf("\n");

	}//end of for loop

	cout<<"    *********************************************************************************************************************************************************************************\n";
	cout<<"\n\t\t\tpress '1' for main menu & press any key for exit:  ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			main();
			break;
        default:
            exit(0);

	}//end of switch statement

}//end of viewinfo function definition

//-----------------------------------------book ticket file start----------------------------------

//File Handling

//function for saving the booked tickets in database

void bookticket_write()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
    fwrite(&book_ticket,sizeof(book_ticket),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);

}//end of bookticket_write function definition


//function for reading saved passenger's information

void viewpassengers_read()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book_ticket,sizeof(book_ticket),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);

}//end of viewpassengers_read function definition

//---------------------------------------add train file start-----------------------------------------

//function for saving train details in the database

void awrite()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","w");
	fwrite(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","w");
	fwrite(&k,sizeof(k),1,train_report);
	fclose(train_report);

}//end of awrite function definition


//function for reading train details for reading the details of train from database

void aread()
{
	FILE *train_details;
	train_details = fopen("train_details.txt","r");
	fread(&add,sizeof(add),1,train_details);
	fclose(train_details);

	FILE *train_report;
	train_report = fopen("train_report.txt","r");
	fread(&k,sizeof(k),1,train_report);
	fclose(train_report);

}//end of  aread function definition

