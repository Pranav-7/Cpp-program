#include<iostream>
#include<stdlib.h>
#include <unistd.h>
using namespace std; 
class Distance{
    public:
    int km,m,cm;
    Distance(){
        km =0;
        m=0;
        cm=0;
    }
    ~Distance(){}
    void displayDistance(){
        while(1){
        if(cm>=100)
        {
            cm=cm-100;
        }else if(m>=1000){
            m=m-1000;
            km++;
        }else if(cm<100&&m<1000){
            break;
        }
        }
        cout<<"The Distance is "<<km<<"km "<<m<<"m "<<cm<<"cm "<<endl;
    }
    friend Distance operator +(Distance const &,Distance const &);
    friend Distance operator ++(Distance);
    friend int operator < (Distance,Distance);

};
Distance operator+(Distance const &d1,Distance const &d2){
    Distance temp;
    temp.km=d1.km+d2.km;
    temp.m=d1.m+d2.m;
    temp.cm=d1.cm+d2.cm;
    cout<<"Distances added successfully\n";
    return temp;
}

Distance operator++(Distance d){
    d.km++;
    d.m++;
    d.cm++;
    return d;
}
int operator < (Distance d1,Distance d2){
    if(d1.km==d2.km && d1.m==d2.m && d1.cm==d2.cm) return 0;
    else if(d1.km < d2.km ) return 1;
    else if(d1.km > d2.km ) return -1;
    return 2;
}
int main() {
    system("cls");
    Distance d1,d2,d3;
    int choice;
    int ch;
    int c;
    int x;
    while(1){
    cout<<"1 to set Distance of d1 and d2\n"
        <<"2 to add Distance of d1 and d2 \n"
        <<"3 to increment the Distace of given obj by 1\n"
        <<"4 to compare the Distance of d1 and d2\n"
        <<"5 to Display the Distance Given obj\n"
        <<"6 to exit "<<endl;
        cin>>choice;
    switch(choice){
        case 1 :
            cout<<"Enter the Distance of d1 in  km,m,cm respectively\n";
            cin>>d1.km>>d1.m>>d1.cm;
            cout<<"Enter the Distace of d2 in km,m,cm respectively\n";
            cin>>d2.km>>d2.m>>d2.cm;
            cout<<"Distances set \n";
            break;
        case 2 :
            d3=d1+d2;
            break;
        case 3 : 
            while(1){
            cout<<"1 to increment the distance of d1 \n"
            <<"2 to increment the distance of d2 \n"
            <<"3 to increment the distance of d3 \n4 to main menu \n";
            cin>>c;
            if(c==1) 
            d1=++d1;
            else if(c==2) 
            d2=++d2;
            else if(c==3) 
            d3=++d3;
            else break;
            }
            break;
        case 4 :
            x = d1<d2;
            if(x==-1) cout<<"Distance of d1 is greater than distance of d2 \n";
            else if(x==1) cout<<"Distance of d2 is greater than distance of d1\n";
            else if(x==0) cout<<"Distance of d1 and d2 is same\n";
            break;
        case 5 :
            while(1){
            cout<<"1 to see d1's distance  \n"
                <<"2 to see d2's distace  \n"
                <<"3 to see d3's distance \n4 to Main Menu \n";
            cin>>ch;
            if(ch==1)
            d1.displayDistance();
            else if(ch==2)
            d2.displayDistance();
            else if(ch==3)
            d3.displayDistance();
            else if(ch==4) break;
            }
            break;
        case 6 :
            exit(0);
        default:
            cout<<"Enter a valid Input\n";
            break;
            system("cls");
    }
    }
return 0;
}
