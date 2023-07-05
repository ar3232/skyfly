//Team membrs: Amjad Al-joufi | Atheer Al-joufi | Amal Alqahtani | Yaqeen Ahmed 

#include <iostream>
#include "sky.h"   //Header files
#include"sky.cpp"
#include <string>
#include<fstream>

using namespace std;
//Here we used namespace
namespace seat{
	void seatt(){
	cout<<"What would you like to choose a seat for the trip? (1 or 2) \n"<<"\t"<<endl<<"1- Economy sea "<<endl<<"2- Business seat"<<endl;}
}
int index =-1;   //global variable
bool found;
// Here we used struct
struct Date
{
int day, month, year;
};
struct passenger
{
string panumber;
char  gender,paname[100];
Date dob;
string nationality;
};

//Here we used void function
void view(){
	
	system("color f9");
	cout<<"\t\t\t\t      |======================== ***SkyFly*** =======================|"<<endl;
	cout<<"\t\t\t\t      |======We're glad you're here and wish you a safe voyage======|"<<endl;
	cout<<"\t\t\t\t      |=============================================================|"<<endl<<endl;
	
	
}

void add(passenger pa[])   //to include the person's information and the destination
{
	system("cls");
 	view();
index++;
 cout<<endl<<"**Note**"<<endl<<"ahmed  | ibrahiem   ** wanted**"<<endl<<endl;
cout << "Enter passenger name: ";
cin >>pa[index].paname;
cout << "Enter passenger ID: ";
cin >> pa[index].panumber;
cout << "Enter passenger gender (f or m): ";
cin >> pa[index].gender;
cout << "Enter the date of birth (d/m/y): ";
cin >> pa[index].dob.day
>> pa[index].dob.month
>> pa[index].dob.year;
cout<<"Enter nationality:"<<endl;

cin>>pa[index].nationality;

cout << "**passenger added**\n";
}


void delet(passenger pa[],string id)   //to remove a person's data
{
	system("cls");
	view();
found = false;

for (int i= 0;i<=index;i++)
{
	if(id==pa[i].panumber)
	{
		for (int j=i;j<index;j++)
			pa[j]=pa[j+1];
			index--;
			cout<< "**passenger deleted**\n";
			found=true;
			break;
	}
}
if (!found)
cout << "passenger not found\n";

}

void update(passenger pa[], string id)   //In order to change the person's name
{
	system("cls");
	view();
found = false;
for (int i = 0 ; i <= index ; i++)
{
if(id == pa[i].panumber)
{
cout << "Enter new passenger name: ";
cin >> pa[i].paname;
cout << "**passenger name updated**\n";
found = true;
break;
}
}
if (!found)
cout << "passenger not found\n";

}

void view(passenger pa[])   //Here we used overloading  (view)
{
	system("cls");
	view();
for (int i = 0 ; i <=index; i++)
cout<< "passenger [" << i+1 << "]: name: " << pa[i].paname<<"\t";

}

void search(passenger pa[], string id)   //To perform a search for a person and view his details by ID number
{
	system("cls");
	view();
found = false;
for (int i = 0 ; i <= index ; i++)
{
	if(id == pa[i].panumber)
{
cout<< "passenger Name: " << pa[i].paname << endl
<< "passenger Gender: " << pa[i].gender << endl
<< "passenger Date of Birth: "<< pa[i].dob.day << "/"<<pa[i].dob.month << "/"<<pa[i].dob.year << endl;
cout<<"nationality: "<<pa[i].nationality<<endl;
found = true;
break;
}
}
if (!found)
cout << "passenger not found\n";

}



void sort(passenger pa[]) //To view names in alphabetical order
{      
	system("cls");
 	view();
	bool ordered = false;
	for(int i = 0 ; i < index && ordered == false ; ++i) //instead for
	{      
		ordered = true;
		passenger temp;
		for(int j=0;j<index;++j){
			if(pa[j].panumber>pa[j+1].panumber)
				{
					ordered=false;
					temp=pa[j];
					pa[j]=pa[j+1];
					pa[j+1]=temp;
			}}
	}
cout<<"\n Passengers after sorting by identification number:\n";
view(pa);
}

bool searchName(string name, string wanted[],int size) {
    for (int i = 0; i <size; i++) {
        if (name == wanted[i]) {
            return true;
        }
    }

    return false;
}

string wanted(passenger pa[],int size){     //to stop those whose names are mentioned from finishing the steps
	string wanted[] = {"ahmed", "ibrahiem"},tempname;
	cout<<"**To confirm if you are wanted or not, type the names into the security system once**";
	cout<<endl;
	 	for(int i=0;i<size;i++){
 		    cin >> tempname;
       		if (searchName(tempname, wanted,size)) {
       	       	cout << tempname << " is Wanted!" << endl<< "sorry we cannot complate your reservation !  ";
				exit(0);}
       	    else
       	    cout<<"You may finish making the reservation. we apologize for the inconvenience :)"<<endl;
			return tempname;
}}

void add(int numpserv,string serv[]){//This function is to add additional services for people with a business seat
		system("cls");
 		view();
 		
	index++;

	if(numpserv>0){
		cout << "Select the services you require: "<<endl;
		cout<<"|Entertainment screen - services for private suites to sleep - Wi-Fi - privacy and storage of personal items - hospitality services|"<<endl;
		for(int i=0;i<numpserv;i++){
		cin >>serv[i];
		}
		cout << "**service added**\n";
	}
	}
	
	
	
void pet(int &price){      //we used Pass by reference /(People who want to bring their animals with them can use this function )
	system("cls");
 	view();
	string pet;
	cout<<"If you want to take your pet with you, choose the pet : "<<endl;
	cout<<" | "<<" cat"<<" | "<<" dog"<<" | "<<" bird"<<" | "<<endl;
	cout<<"*Note :only these breeds of animals are allowed on airplanes. If you don't want any of them, type no.*";
	cin>>pet;
	cout<<endl;
	if(pet=="cat"){
		cout<<"ticket cost: ";
		cout<<price+400<<"SR"<<endl;
		}
	else if(pet=="dog"){
		cout<<"ticket cost: ";
		cout<<price+500<<"SR"<<endl;
		
	}
	else if(pet=="bird"){
		cout<<"ticket cost: ";
		cout<<price+300<<"SR"<<endl;

	}
	else {
	 cout<<"ticket cost: "<<price<<"SR"<<endl;
	
	}
}

	


int main(){


	view();
	cout<<"Observe these steps to reserve your seat:"<<endl<<endl;
	string pass_id;
	int age;
	
	do{
		cout<<" What age are you?"<<endl<<endl;
		cout<<"**Note: If you are under the age of 18, you cannot finish the procedure!!**"<<endl;
  	 		cin>>age;
  	 	if (age<18){
   			break;
	   }
	int size,numberOfItems=0,choice;
   	cout<<"enter  the number of passengers:"<<endl;
    cin >> size;
   	passenger pass[size];
   
   	do
	{
		cout<<"\nChoose the operation: \n";
		cout<<"\t1.Add passenger records \n";
		cout<<"\t2.Delete passenger records \n";
		cout<<"\t3.Update passenger records \n";
		cout<<"\t4.View all passenger records \n";
		cout<< "\t5.Find passenger by ID\n";
		cout<< "\t6.Sort records by alphabetical \n";	
		cout<<"\t7.technical support\n";   //to receive suggestions and problems with the user
		cout<< "\t0.Exit \n";
		cout<< "\tEnter your choice: ";

		cin >> choice;
		cout << endl;
		int price;
	switch (choice)
	{
		case 1:{
			
			if (index < size -1){  //index=-1 in global variable
			
			add(pass);   
			wanted(pass,size);
			cout<<endl;
			cout<<"Enter your travel destination:"<<endl;
			cout<<"*Note(Please provide the country's abbreviation if its name consists of more than one word) "<<"  "<<endl;
			string country;
			cin>>country;
			int seat;
			seat::seatt();//here we  used namespace
			cin>>seat;
			
			int seatt;
			int *p=&seatt;
			if(seat==2){
			 *p=400;
			int numpserv;
			string serv[5];
			cout<<endl;
			cout<<"How many services do you need for journey?(maximum of 5 services)"<<endl;
			cin>>numpserv;
			add(numpserv,serv);
			price=sum(seatt);//the function in header files
			cout<<"The seat is included in the ticket price: "<<price<<" SR"<<endl;//we use  Header file and pointer and Function Recursion 
			
			pet(price);
			
			}
			else
			{
			*p=0;
			price=sum(seatt);
			cout<<"The seat is included in the ticket price: "<<price<<" SR"<<endl;//we use Header file and pointer and Function Recursion
			pet(price);
			}
			
			
			}
			else 
			cout<<"The plane is full, You can't add new passenger\n";
			
			
			break;}
		
		
		
		case 2:{
		
		
			if (index >= 0)
			{
			cout << "Enter passenger ID to delete: ";
			cin >> pass_id;
			delet(pass, pass_id);
			}
			else
			cout<< "There are no passengers in this plane. "<< "You can't delete\n";
			
			break;}
			
		case 3:{
		
			
			if (index >= 0)
			{
			cout << "Enter passenger ID to update: ";
			cin >> pass_id;
			update(pass, pass_id);
			}
			else
			cout<< "There are no passengers in this plana. "<< "You can't update\n";
			break;}
			
		case 4:{
		
			if (index >= 0)
			view(pass);
			else
			cout<<"There are no passengers in this plana.\n";
			break;}
		case 5:{
			if (index >= 0)
			{
			cout << "Enter passenger ID to search: ";
			cin >> pass_id;
			search(pass, pass_id);
			}
			else
			cout<<"There are no passengers in this plana.\n";
			break;}
		case 6:{
		
			if (index+1 >= 2)
			{
				sort(pass);
			}
			else if (index+1 == 1)
				{
				cout << "There is only one passenger in the plana. "<< "Nothing to sort!\n";

				}
			else
			cout<< "There are no passengers in this plana. "<< "Nothing to sort !!\n";

			break;}
			
		case 7:{     //reading from Writing in a file , For evaluation and receiving suggestions and inquiries
		system("cls");
 		view();
 		int user;
		int *m=&user;
 		 cout<<"Enter 1 if you satisfied with your experince with us and 2 if you are not: "; 
 		 cin>>user;
 		 cout<<"Your choice is: "<<*m<<endl;
  
  		if(user==1){
  	  cout<<"Thank you for choosing us and have a nice trip\n"<<endl;
		}
		  else 
 		 cout<<"We apologize and would like you to let us know about the issue you are having:\nSupport: 991119 \n "<<endl;
  		
			
			
			string problem[10];
			ofstream outfile;//writing
			ifstream infile;//reading
			string x;
			infile.open("sky.txt",ios::in);
			if(infile.is_open()){
				for(int i=0;i<4;i++){
					getline(infile,x);
					cout<<x<<endl;
				}
			//	cout<<"We welcome all suggestions and problems:  ";
			//	cout<<"(Write your query or suggestion in no more than 10 words)\n"<<endl;
			cout<<"If your query or suggestion is more than 10 words, kindly contact us: \nSupport:991119 \n"<<endl;
		//	cout<<"(Between each word please click on *|Enter|)*";
			
			}
			
			outfile.open("Skyfly.txt",ios::out);
			if(outfile.is_open()){
			outfile<<"\t\t\t\t      |======================== ***SkyFly** ========================|"<<endl;
			outfile<<"\t\t\t\t      |========We welcome all your inquiries and suggestions========|"<<endl;
			outfile<<"\t\t\t\t      |=============================================================|"<<endl<<endl;
			outfile<<"suggestions and inquiries:"<<endl<<endl;
			for(int i=0;i<10;i++){
			cin>>problem[i];}
			for(int j=0;j<10;j++){
			outfile<<problem[j]<<" ";}}
			
			
			
		}
		
		break;}
		

	}
	
	 while (choice != 0);
	cout<<"We appreciate you choosing our service. Having a good trip :)";
	exit(0);
	
	}
	while (age <=18);
	cout<<"You're not qualified to receive the service!"<<endl;
	system("pause");
	system("cls");
	
		
	return 0;
}