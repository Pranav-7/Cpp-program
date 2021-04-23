#include<iostream>
using namespace std;
class Department 
{
	private:
    string name;
    int num_students;
    static int total_departments;
    public:
  // Constructor definition
  Department(string i_name, int i_num_students)
  {
    cout << "Constructor called for: " << i_name << endl;
    get_name(i_name); // Assign name and number of students
	get_students(i_num_students);
    total_departments++; 
  }
  
// Destructor definition
   ~Department()
  {
   cout << "Destructor called for: " << name << endl;
   total_departments--; 
  }


  inline int get_name(string i_name)
  {
  	name=i_name;
  } 
  
   inline int get_students(int  i_num_students ) 
  {
  	num_students=i_num_students; 
  }

// Static function to return departments count
static int get_total() 
{
 return total_departments;
}
};
int Department::total_departments = 0;
int main() {

Department dep1("CS", 2000);
Department dep2("BIO", 3000);
dep1.~Department(); 
cout << "Total departments: " << Department::get_total() << endl;
cout << "Here is the end of the main." << endl;
exit(0);
return 0;
}


