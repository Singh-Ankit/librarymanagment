//FILE-HANDLING PROJECT
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<fstream>
#include <time.h>
#include <termios.h>
#include <unistd.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
 
#define NORMAL "\033[0m"								//Defination of colors
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"								//MACROS
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"

 
using namespace std;    
//boook
class book 										//creating BOOK class
{
		int bid,qty;                                                              
		char bname[50];                                                         //initialisation n declaration of varialbes
		char branch[5];
                public:
		void getData()
		     { 	                                      				//function created to display on input screen
			system("clear");
			cout<<"            "CYAN "Enter book_id no.  : " NORMAL "";
			cin >>                     bid;
			cin.ignore();
			cout<<"            "CYAN "Enter name of book : " NORMAL "";
			cin.getline(bname,50);
			cout<<"            "CYAN "Enter the branch   : " NORMAL "";
			cin.getline(branch,5);
			cout<<"            "CYAN "Enter quantity     : " NORMAL "";
			cin >>                     qty;

		}
		void displayData()
		{

			                                     			//function created to take input data
			cout<<"  "CYAN "\n\t\tBook ID.No . : " NORMAL ""<< bid;
			cout<<"  "CYAN "\n\t\tBook  Name   : " NORMAL ""<< bname;
		        cout<<"  "CYAN "\n\t\tBranch       : " NORMAL ""<< branch;
		   	cout<<"  "CYAN "\n\t\tQuantity     : " NORMAL ""<< qty<<endl;
				
			
		}
		 int retbid()
		 { return bid;							//function for admin_no
		 }
		};
		/* * function to write in a binary file. */
		void writerecord() 							//function created to perform write operation.
		{
			ofstream outFile;
			outFile.open("book.dat",ios::app | ios::binary);            
			book obj;
			obj.getData();
			outFile.write((char*)&obj, sizeof(obj));

			outFile.close();
		}

		/* * function to display records of file */				
		void show()
		{
			cout<<"\n\n\t\t"CYAN " System is fetching data.....wait a moment!" NORMAL "\n\n";
                        sleep(2);
                        system("clear");
			ifstream inFile;
			inFile.open("book.dat",ios::binary);					
			book obj;

				while(inFile.read((char*)&obj,sizeof(obj)))
				{
				 obj.displayData();
                                 sleep(1);
				}
			inFile.close();
		}
		void find(int n)
		 { 	
			 cout<<"           "CYAN "Search completed !" NORMAL "\n";			
			ifstream inFile;
			inFile.open("book.dat", ios::binary);
			book obj;
			while(inFile.read((char*)&obj, sizeof(obj)))
			{
				if(obj.retbid() == n)
				{
				  sleep(1);
				  cout<<"   \n        "CYAN " details of book id "<<n<<" is: " NORMAL "\n";
				  obj.displayData();
				}

			}
			inFile.close();
		 }
		 //modify_record
		 void change_record(int n)
		 {
			fstream file;
			file.open("book.dat",ios::in | ios::out);
			book obj;
			while(file.read((char*)&obj,sizeof(obj)))
			{
				if(obj.retbid()==n)
				{
						
				cout<<"            "CYAN "Enter the new details of book: " NORMAL "\n";				
						obj.getData();
						int pos = -1 * sizeof(obj);
						file.seekp(pos, ios::cur);
						file.write((char*)&obj, sizeof(obj));
						cout<<"       \n"CYAN "Record is Updated Successfully." NORMAL "\n";
						
				}
		
			}
					file.close();
				}

//student                                         

class Student 										//creating STUDENTS class
		     {
		int admno;                                                              
		char name[50];                                                         //initialisation n declaration of varialbes
		char branch[5];
		public:
		void setData()
		     { 	//cout << "\n\t\tEnter admission no. ";				//function created to display on input screen
			system("clear");
			cout<<"            "CYAN "Enter admission no. : " NORMAL "";
			cin >>                     admno;
			cin.ignore();
			cout<<"            "CYAN "Enter name of student : " NORMAL "";
			cin.getline(name,50);
			cout<<"            "CYAN "Enter branch of Student: " NORMAL "";
			cin.getline(branch,5);

		}
		void showData()
		{

			cout << "\n\t\tAdmission no.   :  " << admno;			//function created to take input data
			cout << "\n\t\tStudent Name    :  " << name;
			cout << "\n\t\tStudent Branch  : " << branch<<endl;
		}
		 int retAdmno()
		 { return admno;							//function for admin_no
		 }
		};
		/* * function to write in a binary file. */
		void write_record() 							//function created to perform write operation.
		{
			ofstream outFile;
			outFile.open("student.dat",ios::app | ios::binary);            
			Student obj;
			obj.setData();
			outFile.write((char*)&obj, sizeof(obj));

			outFile.close();
		}

		/* * function to display records of file */				
		void display()
		{       
                        cout<<"\n\n\t\t"CYAN " System is fetching data.....wait a moment!" NORMAL "\n\n";
                        sleep(2);
                        system("clear");
			ifstream inFile;
			inFile.open("student.dat",ios::binary);					
			Student obj;

				while(inFile.read((char*)&obj,sizeof(obj)))
				{
				 obj.showData();
				 
                                 sleep(1);
				}
			inFile.close();
		}
		void search(int n)
		 { 	ifstream inFile;
			inFile.open("student.dat", ios::binary);
			Student obj;
			while(inFile.read((char*)&obj, sizeof(obj)))
			{
				if(obj.retAdmno() == n)
				{
				   cout<<"           "CYAN "Search is completed Details of Admission Number "<<n<<" is: " NORMAL "\n";
				  obj.showData();
				}

			}
			inFile.close();
		 }
		 //modify_record
		 void modify_record(int n)
		 {
			fstream file;
			file.open("student.dat",ios::in | ios::out);
			Student obj;
			while(file.read((char*)&obj,sizeof(obj)))
			{
				if(obj.retAdmno()==n)
				{
						
				cout<<"            "CYAN "Enter the new details of student" NORMAL "\n";				
						obj.setData();
						int pos = -1 * sizeof(obj);
						file.seekp(pos, ios::cur);
						file.write((char*)&obj, sizeof(obj));
						cout<<"          \n"CYAN "Record is Updated Successfully." NORMAL "\n";
						
				}
		
			}
					file.close();
				}

			
main()									//MAIN FUNCTION ----> SWITCH CASE
{
system("clear"); //clears the screen
int ch;
time_t rawtime;
struct tm * timeinfo;
time ( &rawtime );
timeinfo = localtime ( &rawtime );
std::cout<<"\n\t\t\t\t\t\t";
std::cout<<asctime ((timeinfo) );
cout<<"         -----------------------------------------------------------\n";
cout<<"            "CYAN "LAKSHMI NARAIAN COLLEGE OF TECHNOLOGY EXELLENCE,BHOPAL" NORMAL "\n";
cout<<"         -----------------------------------------------------------\n";
cout<<"             "YELLOW "\t      WELCOME TO THE DIGITAL LIBRARY" NORMAL "\n";
cout<<"         ............................................................\n";
cout<<              "\n\n\t\t\t\t"GREEN "Login as:" NORMAL "\n\n"   ;       
cout<<"            \t1. Student \t\t         2.Adimn   \n\n\n";
cout<<"           \n\n\t............................................................\n";
cout<<"      \t............................................................\n";
cout<<"            "CYAN "                   choose to login:" NORMAL "";
cin>>ch;
switch(ch)								//INNER SWITCH
  {
    case 1:   
 	      system("clear");
	      cout<<"         \n\n\n\n\n\n\n\n\t\t"YELLOW"---------W * E * L * C * O * M * E------" NORMAL "\n\n\n\n\n";                
	      sleep(2);
		l5:
	      system("clear");
	      std::cout<<"\n\t\t\t\t\t\t";
	      std::cout<<asctime ((timeinfo) );
              cout<<"\n\t\t\t*********"YELLOW " STUDENT LOGIN " NORMAL "*********\n\n";
	      cout<<"         -----------------------------------------------------------\n\n";
			cout<<"           \t\t\t    MAIN MENU\n";
                        cout<<"\t\t\t"GREEN "       ===================" NORMAL "\n\n";
			cout<<"           \t\t\t"CYAN "1.SEARCH BOOK\n\n " NORMAL "";
			cout<<"           \t\t\t"CYAN "2.DISPLAY BOOKS\n\n " NORMAL "";
			cout<<"           \t\t\t"CYAN "3.REGISTERD STUDENTS\n\n " NORMAL "";
			cout<<"           \t\t\t"CYAN "4.EXIT\n\n " NORMAL "";
			 cout<<"         -----------------------------------------------------------\n\n";
			cout<<"           \n\t\t"GREEN "choose from menu to continue......." NORMAL "";
			cin>>ch;
			                       
			 switch(ch)
 			 {
 			   case 1:
					system("clear");
  					cout<<"\t\t\t\t"YELLOW "SEARCH BOOK" NORMAL "\n";
					cout<<"\t--------------------------------------------------------------\n";
					cout<<"\t"CYAN "Enter Book ID: " NORMAL "";
					int n;
					cin>>n;
					find(n);
					getch();
					
			break;

                              
                           case 2:
                                        system("clear");
					cout<<"\t\t\t\t"YELLOW "DISPLAY ALL BOOK" NORMAL "\n";
					cout<<" \n\t............................................................\n";
                                        show();
                                        getch();
					cout<<"  \n\t............................................................\n";
					sleep(2);
				        cout<<"\n\t\t\t"GREEN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n";
                                        sleep(2);
				
						cout<<"\n\t\t\t"YELLOW "choose to go....." NORMAL "\n";
						cout<<"\n\t\t\t"CYAN "1. Main Menu" NORMAL "\n";
						cout<<"\n\t\t\t"CYAN "2. Exit" NORMAL "\n";
						cin>>ch;
		  				switch(ch)
				  {
					case 1:
						goto l5;
					 break;
					case 2:
						system("clear");
		                                cout<<"\n\n\n\n\n\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
		                              	sleep(2);
		                                system("clear");
						cout<<"\n\n         -----------------------------------------------------------\n\n";
		                                cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	
		                                exit(0);
					 break;
  
			  }

                              break;
                           case 3:
                                        system("clear");
					cout<<"\t\t\t\t"YELLOW "STUDENTS LIST" NORMAL "\n";
					cout<<"  \n\t............................................................\n";
                                        display();
					getch();
					cout<<"  \n\t............................................................\n";
					cout<<"\n\n\t\t\t"GREEN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";
							sleep(2);
				        	cout<<"\n\t\t\t"YELLOW "choose to go....." NORMAL "\n";
						cout<<"\n\t\t\t"CYAN "1. Main Menu" NORMAL "\n";
						cout<<"\n\t\t\t"CYAN "2. Exit" NORMAL "\n";
						cin>>ch;
		  				switch(ch)
				  {
					case 1:
						goto l5;
					 break;
					case 2:
						system("clear");
		                                cout<<"\n\n\n\n\n\n\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
		                              	sleep(2);
		                                system("clear");
						cout<<"\n          -----------------------------------------------------------\n\n";
		                                cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                    			                                exit(0);
					 break;
				}
                              break;
			  case 4:      
					system("clear");
                                        cout<<"\n\n\n\n\n\n\n\t\t"CYAN "   Exiting in a moment...\n" NORMAL "\n\n";
                                      	sleep(2);
					system("clear");
					cout<<"\n\n\n\n\n\n         -----------------------------------------------------------\n\n";
                                        cout<<"\n\n\t\t\t"GREEN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	
                                     	exit(0);
                                        
                              break;	
                           default:
			               
					 cout<<"   \n\n         "YELLOW "WARNING: Invalid choice. check again...... " NORMAL "\n\n";
       			}
                         
	      
              
               
            
             
      break;
    case 2:
       {       
	       l1:
               system("clear");
	       cout<<"\t\t\t---------"YELLOW "ADMIN LOGIN" NORMAL "-----------\n";
	        l2:
                char pwd[5];
                cout<<"\t\t \n Enter the password: ";
                int i;
		__fpurge(stdin);
                for(i=0;i<5;i++)
		{
		pwd[i]=getch();
		cout<<"*";
		}
		pwd[i]='\0';
		system("clear");
		cout<<"\n\n\n\t \t         "CYAN "VERIFYING YOUR PASSWORD...... \n" NORMAL "\n\n";
		sleep(2);
		if (strcmp(pwd,"lncte")==0)
		{
		cout<<"\nPassword Matched\n";
		
                        system("clear");
	                cout<<" \n\n\n\n\n\n\n\n\n\t\t"YELLOW"---------W * E * L * C * O * M * E------" NORMAL "\n\n\n\n\n";                
	                sleep(2);
	                system("clear");                    
				
			{
	
			int record;
			system("clear");
			l3:
			std::cout<<"\n\t\t\t\t\t\t";
	      		std::cout<<asctime ((timeinfo) );
			cout<<"\t\t\t\t"YELLOW " ADMIN LOGIN" NORMAL "\n";
			cout<<"         -----------------------------------------------------------\n";
			cout<<" \t\t\t\t"CYAN "  MAIN MENU " NORMAL "\n";
			cout<<"\t\t\t"YELLOW "       ===================" NORMAL "\n";
			cout<<"           \t\t\t1. ADD BOOK\n\n";
			cout<<"           \t\t\t2. VIEW BOOK\n\n";
			cout<<"           \t\t\t3. SEARCH BOOK\n\n";
			cout<<"           \t\t\t4. UPDATE BOOK\n\n";
			cout<<"           \t\t\t5. CREATE STUDENT RECORD\n\n";
			cout<<"           \t\t\t6. DISPLAY STUDENT RECORD\n\n";
			cout<<"           \t\t\t7. SEARCH STUDENT RECORD\n\n";                                     
			cout<<"           \t\t\t8. UPDATE STUDENT RECORD\n\n";
			cout<<"           \t\t\t9. EXIT\n";
			cout<<"         -----------------------------------------------------------";
                        cout<<"           \n\t\t"GREEN "choose from menu to continue......." NORMAL "";
                        cin>>ch;
                        switch(ch)
 			 {
 			   case 1:
					system("clear");
  					cout<<"\t\t\t"YELLOW "ADD BOOK" NORMAL "\n";
					cout<<"         -----------------------------------------------------------\n";
					cout<<"\t\t"CYAN "Enter no. of record to input:" NORMAL "";
					cin>>record;
					for(int i = 1; i <=record; i++)
					writerecord();
					cout<<"           \n\t\t"YELLOW "*******Record Inserted Successfully********" NORMAL "";
					getch();
 					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
                              break;
                           case 2:
                                        system("clear");
					cout<<"\t\t\t\t"YELLOW "VIEW BOOK" NORMAL "\n";
					cout<<"\t--------------------------------------------------------------";
					show();
					getch();
					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
					
			
                              break;
                           case 3:
					system("clear");
					cout<<"\t\t\t\t"YELLOW "SEARCH BOOK" NORMAL "\n";
					cout<<"\t--------------------------------------------------------------\n";
					cout<<"\t"CYAN "Enter Book ID: " NORMAL "";
					int n;
					cin>>n;
					find(n);
					getch();
					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
			      break;
                           case 4:	
					system("clear");
					cout<<"\t\t\t\t"YELLOW "UPDATE BOOK" NORMAL "\n";
					cout<<"\t-------------------------------------------------------------\n";
                                        cout<<"\t"CYAN "Upadte Book ID:" NORMAL "";
					int change;
					cin>>change;
			 		change_record(change);
					getch();
					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
					
                              break;
                           case 5:      
					system("clear");
					cout<<"\t\t\t\t"CYAN "CREATE STUDENT RECORD" NORMAL "\n\n";
					cout<<"\t\t ----------------------------------------------------------------\n";
					cout<<"\t\t"CYAN "No Of Records To Enter:" NORMAL "\n\n";					
					cin>>record;
					for(int i = 1; i <=record; i++)
					write_record();
					cout<<"\n\t\t\t"CYAN "******Record Inserted Successfully*******" NORMAL "\n";
                                        getch();  
                                        cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }				
                              break;
                           case 6:      
					
					system("clear");
					cout<<"\t\t\t\t"CYAN "   STUDENTS RECORD" NORMAL "\n";
					cout<<"\t\t\t\t"YELLOW "============================" NORMAL "\n";
					display();
					getch();
					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
						
                              break;
                           case 7:
                                       	int ser;
					system("clear");
					cout<<"\t\t\t\t"CYAN "SEARCH STUDENT'S RECORD" NORMAL "\n\n";
					cout<<"----------------------------------------------------------------";
					cout<<"\n\tEnter Admission Number To Search: ";
					cin>>ser;
					cout<<"\n\n\t\t"CYAN " System is fetching data.....wait a moment!" NORMAL "\n\n";
					sleep(2);
					system("clear");
					cout<<"\t\t\t\t"CYAN "SEARCH STUDENT'S RECORD" NORMAL "\n\n";
					search(ser);
	                                getch();
					sleep(1);
					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
					

                              break;
					
                           case 8:     
					int update;
                                        system("clear");
					cout<<"\t\t\t\t"CYAN "MODIFY STUDENT RECORD" NORMAL "\n\n";
					cout<<"\t\t---------------------------------------------------------------";
			 		cout<<"\n\tEnter Addmission Number You Want To Update: ";
			 		cin>>update;
			 		modify_record(update);
					getch();
					cout<<"          \n\n \n\t\t"GREEN "choose to continue......." NORMAL "";
					cout<<"\n\t\t1. Back to main menu\n";
					cout<<"\t\t2. Exit \n";
   					cin>>ch;
          		                    switch(ch)
			  		       {
					          case 1:
							system("clear");
						  goto l3;
						  break;
						  case 2:
						  system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				                break;
  			                     }
					
			 break;
			

                              break;
			   case 9:
                                       system("clear");
                                        cout<<"\n\n\n\n\t\t\t"CYAN "   Exiting in a moment...\n" NORMAL "\n\n";
                                      	sleep(2);
					system("clear");
					cout<<"\n          -----------------------------------------------------------\n\n";
                                        cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	
                                     	//cout<<"  \n\n\t\tThank You\n";
                                    	exit(0);
                             break;
                            
                          } 
                            




			cout<<"         -----------------------------------------------------------\n";
               }
             }
                  else
  		{       
			system("clear");
			int ch;
			std::cout<<"\n\t\t\t\t\t\t";
	      		std::cout<<asctime ((timeinfo) );
			cout<<" \n\n\t  "YELLOW " Password incorrect ! " NORMAL "";
			getch();
                        system("clear");
			cout<<"\n\t\t\t "YELLOW " choose to go..... " NORMAL "\n";
			cout<<"\n\t\t "GREEN " 1. Re-Enter Password" NORMAL "";
               		cout<<"\n\t\t "GREEN " 2. EXIT " NORMAL "";
			cin>>ch;
          		switch(ch)
			  {
				case 1:
					system("clear");
					goto l2;
				 break;
				case 2:
					system("clear");
                                                  cout<<"\n\n\n\t\t\t\t"CYAN "Exiting in a moment...\n" NORMAL "\n\n";
                                      		  sleep(2);
                                        	  system("clear");
						  cout<<"\n          -----------------------------------------------------------\n\n";
                                       	   cout<<"\t\t\t"CYAN "THANKS FOR USING DIGITAL LIBRARY \n" NORMAL "\n\n";                        	                                        	  exit(0);
				 break;
  
			  }

                }
               break;
 
    default:
        cout<<"\n\n\t\t"BLUE "      INVALID: check your login....." NORMAL "\n\n";
   }
}
return 0;
}




