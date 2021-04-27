#include <iostream>
using namespace std;
class A
{
    public:
    int a1=1;
    void display()
    {
        cout<<"Variables declared in Class A are "<<a1<<" "<<a2<<" "<<a3<<endl;
        cout<<"All accessible variables by Class A are "<<a1<<" "<<a2<<" "<<a3<<endl; 
    }
    private:
    int a2=2;
    protected:
    int a3=3;
};
class B:virtual public A
{
    public:
    int b1=4;
    void addAll()
    {
        int sum;
        cout<<"Variables declared in Class B are "<<b1<<" "<<b2<<" "<<b3<<endl;
        cout<<"All accessible variable by Class B are "<<a1<<" "<<a3<<" "<<b1<<" "<<b2<<" "<<b3<<endl;
        sum=a1+a3+b1+b2+b3;
        cout<<"The sum of all accessible variable by Class B is "<<sum<<endl; 
    }
    private:
    int b2=5;
    protected:
    int b3=6;
};
class C:virtual private A
{
    public:
    int c1=7;
    void addAll()
   {
        int sum;
        cout<<"Variables declared in Class C are "<<c1<<" "<<c2<<" "<<c3<<endl;
        cout<<"All accessible variables by Class C are "<<a1<<" "<<a3<<" "
        <<c1<<" "<<c2<<" "<<c3<<endl;
        sum=a1+a3+c1+c2+c3;
        cout<<"The sum of all accessible variables by Class C is "<<sum<<endl; 
    }
    private:
    int c2=8;
    protected:
    int c3=9;
};
class D:protected B,public C
{
    public:
    int d1=10;
    void addAll()
    {
        int sum;
        cout<<"Variables declared in Class D are "<<d1<<" "<<d2<<" "<<d3<<endl;
        cout<<"All accessible variables by Class D are "<<a1<<" "<<a3<<" "<<b1<<" "<<b3<<" "<<c1<<" "<<c3<<" "<<d1<<" "<<d2<<" "<<d3<<endl;
        sum=a1+a3+b1+b3+c1+c3+d1+d2+d3;
        cout<<"The sum of all accessible variables by class D is "<<sum<<endl;
    }
    private:
    int d2=11;
    protected:
    int d3=12;
};
int main()
{
    A a1;
    a1.display();
    B b1;
    b1.addAll();
    C c1;
    c1.addAll();
    D d1;
    d1.addAll();
    return 0;
}
