#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#define N 100
int A_no=0;
using namespace std;
class Account 
{
private :
    string customerName;
    int accountNo;
    int dd, mm, yyyy;

public :
	Account(){}
	Account(string Cn, int An, int day, int month, int year){
		customerName = Cn;
        accountNo = An;
        dd = day;
        mm = month;
        yyyy = year;
		cout<<"\nConstructor is called of user with AccountNo "<<accountNo<<endl;
	}
    ~Account(){
		cout<<"\nDestructor is called of user with AccountNo "<<accountNo<<endl;
	}

    void showData(void)
    {
        cout<<"\n";
        cout << "Welcome  sir" << endl;
        cout<<"Your UserName is "<<customerName<<endl;
        cout << "Your Account Number is 0"<< accountNo << endl;
        cout << "Your birthDate is " << dd << "-" << mm << "-" << yyyy << endl;
    }

    void ageDisplay()
    {
        cout<<"\n";
        int p_dd, p_mm, p_yyyy;
        int day, month, year;   
        int md[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        cout<<"Present time is : ";
        auto timenow =  chrono::system_clock::to_time_t(chrono::system_clock::now()); 
        cout << ctime(&timenow) << endl; 
        cout << "Enter(one by one) the present date in (dd-mm-yyyy) formate (note dont no use zero at first eg 01) : \n";
        cin >> p_dd >> p_mm >> p_yyyy;
        year = p_yyyy - yyyy;
        if (p_mm < mm)
        {
            year--;
            month = 12 - (mm - p_mm);
        }
        else
        {
            month = p_mm - mm;
        }
        if (p_dd< dd)
        {
            month--;
            day = md[p_mm - 1] - (dd - p_dd);
        }
        else
        {
            day = p_dd - dd;
        }
        cout << "your age is : \n";
        cout <<year<< " years " <<month<<" months " <<day<< " days. ";
    }

    void nameLen()
    {
        cout<<"\n";
        int len = 0;
        for (int i = 0; customerName[i] != '\0'; i++)
        {
            len++;
        }
        cout <<"No of characters in your Name is " << len << endl;
        cout<<"\n";
    }

};

void createAc(Account Customer[]){
    string Uname;
    int day,month,year;
    cout<<"\n";
    cout<<"Enter your username for the account\n";
    cin>>Uname;
    cout<<"Enter(one by one) your date of birth in dd-mm-yyyy format\n";
    cin>>day>>month>>year;
    Customer[A_no]=Account(Uname,A_no,day,month,year);
    cout<<"\nAccount created successfully\n";
    cout<<"Your account number is 0"<<A_no<<" please note it down it will require for sign in process\n";
}
void accountInfo(Account Customer[]){
    int User_Acno;
    int ch;
    cout<<"\n";
    cout<<"Enter your Account Number(without 0)\n";
    cin>>User_Acno;
    cout<<"Welcome to your Account sir\n";
    cout<<"Here are some option that you can perform\n";
    while(1){
        cout<<"\n";
        cout<<"1 for Account details\n2 for your current age\n3 for length of your username\n4 for main menu\n";
        cin>>ch;
        if(ch==4){
            break;
        }
        switch(ch){
            case 1 :
                Customer[User_Acno].showData();
                break;
            case 2 :
                Customer[User_Acno].ageDisplay();
                break;
            case 3 :
                Customer[User_Acno].nameLen();
                break;
            default:
                cout<<"Enter a valid input\n";
        }
  
    }
  cout<<"\n";
}
int main()
{
    int choice;
    Account *Customer=new Account[N];
    do{
        cout<<"\n";
        cout<<"***** MAIN MENU *****";
        cout<<"\n";
        cout<<"1 for sign in\n2 for sign up\n3 for exit"<<endl;
        cin>>choice;
        if(choice==1){
            if(A_no==0){ 
                cout<<"please create a account first\n";
                continue;
            }
            else 
            accountInfo(Customer);
        }
        else if(choice==2){
            A_no+=1;
            createAc(Customer);
        }

        else{
            if(choice==3){
                cout<<"Thanku for using us visit again\n";
                exit(0);
            }
            cout<<"Enter a vaild input\n";
            continue;
        }
    }while(1);


    return 0;
}