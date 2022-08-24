#include<iostream>
#include<fstream>

using namespace std;

void mainMenu();

class management{

public :

    management(){
    mainMenu();
    }


};

class details{

public:

static string name;
int age;
int phoneNo;
static string gender;
static int cId;
char arr[100];

void information(){
cout << "enter the customer ID" << endl;
cin>>cId;

cout << "enter the name " << endl;
cin >> name;

cout << "enter the gender" << endl;
cin>>gender;

cout << "enter the age " << endl;
cin >> age;

cout << "your details are saved with us" << endl;

}

};

int details::cId;
string details::name;
string details::gender;

class registration{
public :

static int choice;
int choice1;
int back;
static float charges;

void flights(){

string flightsN[]={"Goa","Mumbai","Delhi"};

for(int i=0;i<3;i++){
    cout <<(i+1)<<".Flight to  " << flightsN[i]<< endl;
}

cout << "welcome to the airlines"<< endl;
cout << "press the number of the country of which you want to fly " << endl;
cin>>choice;

switch(choice){
case 1:
    cout << "welcome to Goa airways" << endl;
    cout << "your comfort is our priority" << endl;
    cout << "following are the flights" << endl;

    cout << "1.Goa-123"<< endl;
    cout <<"1-08-2022 12:00 Am 1 hr Rs.3000/-" << endl;

    cout << "2.Goa-321"<< endl;
    cout << "2-08-2022 1:00 Am 1 hr Rs.3300/-" << endl;

    cout << "select the Flight " << endl;
    cin>>choice1;

    if(choice1==1){
            charges=3000;
        cout << "you have booked the Flight Goa-123"<< endl;
    cout << "you can go back to the mainmenu and get your ticket" << endl;
    }else if(choice1==2){
    charges=3300;
    cout << "you have booked the flight Goa-321"<< endl;
    cout << "you can go back to the mainmenu and get your ticket" << endl;
    }else{
    cout << "invalid input,shifting to mainmenu" << endl;
    flights();
    }

    cout << "press any key to go back to mainmenu" << endl;
    cin>>back;

    if(back==1){
        mainMenu();
    }else{
    mainMenu();
    }
    break;
case 2:
    cout << "welcome to Mumbai Airways" << endl;
    cout << "your comfort is our priority " << endl;
    cout << "following are the flights" << endl;

    cout << "1.Mum-123"<< endl;
    cout << "3-08-2022 2:00 Am 1 1/2 hr Rs.4000/-"<< endl;

    cout << "2.Mum-321"<< endl;
    cout << "4-08-2022 3:00 Am 1 1/2 hr Rs.4500/-" << endl;

    cout << "select the flight " << endl;
    cin>>choice1;

    if(choice1==1){
        charges=4000;
        cout << "you have booked the flight Mum-123"<< endl;
        cout << "you can go back to the mainmenu" << endl;
    }else if(choice1==2){
    charges=4500;
    cout << "you have booked the flight Mum-321" << endl;
    cout << "you can go back to the mainmenu" << endl;
    }else{
    cout << "invalid input,shifting to the mainmenu"<< endl;
    flights();
    }

    cout << "press any key to go back to the mainmenu"<< endl;
    cin>>back;

    if(back==1){
        mainMenu();
    }else{
    mainMenu();
    }
    break;
case 3:
    cout << "welcome to delhi airways" << endl;
    cout << "your comfort is our priority " <<endl;
    cout << "following are the flights" << endl;

    cout <<"1.Del-123"<< endl;
    cout << "5-08-2022 5:00 Am 2 hr Rs.5000/-";

    cout <<"2.Del-321"<< endl;
    cout << "6-08-2022 6:00 Am 2 hr Rs.6000/-";

    cout << "select the flight "<< endl;
    cin>>choice1;

    if(choice1==1){
        charges=5000;
        cout << "you have booked the flight Del-123"<< endl;
        cout << "you can go back to the mainmenu" << endl;
    }else if(choice1==2){
    cout << "you have booked the flight Del-321"<< endl;
        cout << "you can go back to the mainmenu" << endl;
    }else{
    cout << "invalid input,shifting to the mainmenu"<< endl;
    flights();
    }
    cout << "press any key to go back to mainmenu" << endl;
    cin>>back;

    if(back==1){
        mainMenu();
    }else{
    mainMenu();
    }
    break;

default :
    cout << "invalid input, shifting to the mainmenu" << endl;
    mainMenu();
    break;



}

}



};

float registration::charges;
int registration::choice;

class ticket: public registration,details{

public :

    void bill(){

        string destination = "" ;
    ofstream outf("flight.txt");
    {
        outf<<"_______Aadhya Airlines______" << endl;
        outf<<"___________Ticket___________" << endl;
        outf<<"____________________________" << endl;

        outf<<"customer Id: " <<details::cId<< endl;
        outf<<"Name: " <<details::name<< endl;
        outf<<"Gender: "<<details::gender<<endl;
        outf<<"Description: "<<endl<<endl;

        if(registration::choice==1){
            destination="Goa";
        }else if(registration::choice==2){
        destination = "Mumbai";
        }else if(registration::choice==3){
        destination = "Delhi";
        }
        outf<<"Destination: " <<destination << endl;
        outf<<"Flight cost: " <<registration::charges<< endl;
    }
    outf.close();



    }
    void display(){
    ifstream ifs("flight.txt");
    {
        if(!ifs){
            cout << "file error" << endl;
        }
        while(!ifs.eof()){
            ifs.getline(arr,100);
            cout << arr << endl;
        }
    }
    ifs.close();

    }


};

void mainMenu(){

int lchoice;
int schoice;
int back;

cout << "__________Aadhya Airlines_________"<< endl;
cout << "Main Menu" << endl;

cout << "press-1 to add customer details" << endl;
cout << "press-2 to register a flight" << endl;
cout << "press-3 to get flight and charges" << endl;
cout << "press-4 to exit" << endl;
cout << "enter the choice" << endl;
cin>>lchoice;

details d;
registration r;
ticket t;

switch(lchoice){

case 1:

    cout << "________customers________"<< endl;
    d.information();

    cout << "press any key to go to main menu" << endl;
    cin >> back;

    if(back==1){
        mainMenu();
    }else{
    mainMenu();
    }
    break;
case 2:
    cout << "book a flight using this system " << endl;
    r.flights();
    break;
case 3:
    cout << "get your ticket " << endl;
    t.bill();

    cout << "your ticket is printed , you can get your ticket " << endl;
    cout << "press-1 to display your ticket " << endl;
    cin>>back;

    if(back==1){
        t.display();
        cout << "press-1 to go back to main menu" << endl;
        cin>>back;
        if(back==1){
            mainMenu();
        }else{
        mainMenu();
        }
        }else{
        mainMenu();
        }

    break;
case 4:
    cout << "_______Thank you________" << endl;
    break;
default :
    cout << "invalid input" << endl;
    mainMenu();
    break;

}

    
    


}


int main(){

management mobj;
return 0;
}
