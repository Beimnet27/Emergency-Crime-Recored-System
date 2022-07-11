/*********************************************
**********************************************
**											**
**			Emergency						**
**		Crime Recording Program				**
**											**
**		https://github.com/Beimnet27		**
**											**
**********************************************
**********************************************/
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class Officer
{
	public:
		string officer_name;
		string password;
		Officer()
		{
			
			officer_name="Beimnet Genene";
			password="Cs123";
			cout<<"|| ---------------------------------------------------------------------||\n";
			cout<<"||			Emergency Crime Recorde			\t||\n";
			cout<<"||				Application 		\t\t||\n";
			cout<<"||----------------------------------------------------------------------||\n";
		}
		
};
class Criminal
{
	public:
		string cname;//criminal name
		int age;//
		string cplace;
		string checker;
		int ctime;
		string ctype;
		virtual void print()=0; // pure virtual function for overriding
};
class Thecase:public Officer,public Criminal
{
	public:
		void Login_Form()
		{
			
			cout<<"Enter Your Password Officer \n";
			cin>>checker;
			
			if(checker==password)
			{
				cout<<"Welcome  "<<officer_name<<endl;
				cout<<"Let's Register your Criminal\n";
				
			}
			else
			{
				cout<<"wrong Password you have one try left after that for the case of Security\n";
				cout<<"I will Complain to the Head Office\n";
				cout<<"Enter Your Password Officer this is the last time \n";
				
			cin>>checker;
			Login_Form(); // recuercive function
			
			}
		}
		void registeral()
		{
			cout<<"Criminal Name\n";
			cin>>cname;
			cout<<"Criminal Age\n";
			cin>>age;
			cout<<"Crime Type\n";
			cin>>ctype;
			cout<<"Crime Time\n";
			cin>>ctime;
			cout<<"crime Place\n";
			cin>>cplace;
			cout<<"You have sucessfully registerd the crime and the case transfered to Head office\n";
		}
		void crimedata()
		{
			fstream myfile;
			
			myfile.open("crimeData.txt",ios::out);
			
			if(myfile.is_open())
			{
				
				myfile<<"--------------------------------------------------------------------"<<endl;
				myfile<<" ---------- crime record ----------\n"<<endl;
				myfile<<"--------------------------------------------------------------------"<<endl;
				myfile<<"Officer Who control the case\n"<<endl;
				myfile<<"Officer's Name ->"<<setw(15)<<"|"<<officer_name<<endl;
				myfile<<"--------------------------------------------------------------------"<<endl;
				myfile<<"Crime Type ->"<<setw(15)<<"|"<<ctype<<endl;
				myfile<<"Criminal ->"<<setw(15)<<"|"<<cname<<endl;
				myfile<<"Criminal's Age ->"<<setw(15)<<"|"<<age<<endl;
				myfile<<"Crime Place ->"<<setw(15)<<"|"<<cplace<<endl;
				myfile<<"Crime Time ->"<<setw(15)<<"|"<<ctime<<endl;
				myfile.close();
			}
			
		}
	void print()
    {
	fstream myfile;
 myfile.open("crimeData.txt",ios::in);
 
if(myfile.is_open())
{  
	string line;
    while(getline(myfile,line))
     {
            cout<<line<<endl;


     }
     myfile.close();
}

   }
		
};
int main()
{
    Thecase tc;
    tc.Login_Form();
    tc.registeral();
    tc.crimedata();
    tc.print();

}
