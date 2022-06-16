/*
Griffin Morgan
CSC 112L Spring 2022
Final
*/

#include<iostream>
#include<vector>

using namespace std;

class ClubMember  //Adding the club member class
{              
        string name,phone;      //Creating variables to store info later
        int points;            //Same as before
        public:

            ClubMember() {}   //Allocate setters and getters to the data 
                void setName(string name)
                {
                        this->name = name;
                }
                void setPhone(string phone)
                {
                        this->phone = phone;
                }
                void setPoints(int points)
                {
                        this->points = points;
                }
                
          
                string getName()
                {
                        return this->name;
                }
                string getPhone()
                {
                        return this->phone;
                }
                int getPoints()
                {
                        return this->points;
                }
};
class ClubManager             //Creating club manager class
{              
    vector<ClubMember>members;        //A vector is used for the ClubMember objects
      public:
          ClubManager() {}
                void addMember(string name,string phone,int points) //Add temporary variables for the new members
                {
                        ClubMember temp;
                        temp.setName(name);
                        temp.setPhone(phone);
                        temp.setPoints(points);
                        members.push_back(temp); 
                }
                ClubMember search(string name)         //Find the members by the first iteration of their names
                {
                        vector<ClubMember>::iterator findname;
                        ClubMember temp;

                        for(findname=members.begin();findname!=members.end();findname++)
                        {
                                temp = *findname;
                                if(temp.getName()==name)
                                {
                                        return temp;
                                }
                        }
                        ClubMember emp;     //Return nothing if no member found
                        return emp;
                }
                void display()
                {   
                        vector<ClubMember>::iterator findname;
                        for(findname=members.begin();findname!=members.end();findname++){
                                string name = findname->getName();
                                int points = findname->getPoints();
                                cout<<"Name:"<<name<<" \tPoints:"<<points<<"\n";
                        }
                }
};
int main()
{
        //Setting club managers to objects
        ClubManager obj;
        obj.addMember("JK Rowling","(123) 420-6969",55);
        obj.addMember("Stephen King","(916) 917-2032",345);
        obj.addMember("John Grisham","(228) 007-8008",90);
        obj.addMember("George R.R. Martin","(098) 890-6543",200);
        obj.addMember("Lily King","(911) 243-5651",150);
        
       
        string str = "JK Rowling";   //CLub member to be displayed
        ClubMember obj2 = obj.search(str); //Code to search for the club member entered
        if(obj2.getName()!="")
        {
                cout<<"Member found: "<<str<<endl;
                cout<<"Name:"<<obj2.getName()<<" \tPhone:"<<obj2.getPhone()<<" \tPoints:"<<obj2.getPoints()<<endl<<endl;
        }

        //And to display all the members
        obj.display();
        return 0;
}