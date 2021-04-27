#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std; 
class incomeTax;
class Account{
    public:
    float balance;
    void displayBalance(){
        system("cls");
        cout<<"Your current balance is "<<balance<<endl;
        cout<<"\n";
    }
    friend void Bonus(Account &);
    friend incomeTax;
};
void Bonus(Account &a1){
    system("cls");
    a1.balance+=5000.0;
    cout<<"Bonus added successfully\n";
    cout<<"\n";
}
class incomeTax{
    public:
    float calculated_tax;
        void calculateTax(Account &a1){
            calculated_tax=a1.balance/10.0;
        }
        void displayTax(void){
            system("cls");
            cout<<"Tax on your current balance is "<<calculated_tax<<endl;
            cout<<"\n";
        }
};
int main(){
    Account A1;
    incomeTax taxOfA1;
    int ch;
    system("cls");
    while(1){
        cout<<"\n";
        cout<<"1 to set Balance \n"
            <<"2 to add Bonus \n"
            <<"3 to display current Balance\n4 to display tax on your Balance\n"
            <<"5 to quit \n";
        cout<<"\n";
        cin>>ch;
        switch(ch){
            case 1 :
                cout<<"Enter the amt to set the balance\n";
                cin>>A1.balance;
                break;
            case 2 :
                Bonus(A1);
                break;
            case 3 :
                A1.displayBalance();
                break;
                taxOfA1.calculateTax(A1);
                taxOfA1.displayTax();
                break;
            case 4:
                taxOfA1.calculateTax(A1);
                taxOfA1.displayTax();
                break;
            case 5 :
                exit(0);
            default :
                cout<<"Enter a valid input\n";
                continue;
        }
    }

return 0;
}
