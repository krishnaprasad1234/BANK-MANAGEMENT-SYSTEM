#include <iostream>
#include<conio.h>

#include<bits/stdc++.h>

using namespace std;
class Bank{
    private:
        int total;
        string id;
       
        struct person{
            string name,ID,address;
            int cash;
            long contact;
        }person[100];
    
    public:
         Bank(){
             total=0;
         }
         void choice();
         void perdata();
         void show();
         void update();
         void search();
         void transactions();
         void remove_account();
};
int main()
{
    Bank b;
    b.choice();
    
    return 0;
}
void Bank::choice(){
    char ch;
    while(1){
        cout<<"\n\nPRESS  "<<endl;
        cout<<"1.Create new account"<<endl;
        cout<<"2.View Customers list"<<endl;
        cout<<"3.Update information of existing account"<<endl;
        cout<<"4.check the details of existing account"<<endl;
        cout<<"5.For transactions"<<endl;
        cout<<"6.Remove existing account"<<endl;
        cout<<"7.Exit account"<<endl;
        cin>>ch;
        switch(ch){
            case '1':  Bank::perdata();
                        break;
            case '2':   if(total==0){
                         cout<<"No data is entered"<<endl;
                        }
                        else{
                             Bank::show();
                        }
                        
                        break;
            case '3':   if(total==0){
                         cout<<"No data is entered"<<endl;
                        }
                        else{
                             Bank::update();
                        }
                        
                        break;
            case '4':   if(total==0){
                         cout<<"No data is entered"<<endl;
                        }
                        else{
                             Bank::search();
                        }
                        
                        break;
            case '5':   if(total==0){
                         cout<<"No data is entered"<<endl;
                        }
                        else{
                             Bank::transactions();
                        }
                        
                        break;
            case '6':   if(total==0){
                         cout<<"No data is entered"<<endl;
                        }
                        else{
                             Bank::remove_account();
                        }
                        
                        break;
            case '7':   exit(0);
                        break;
            default:    cout<<"Invaid Input"<<endl;
                        break;
           
        }
    }
}
void Bank::perdata(){
    cout<<"Enter data of person"<<total+1 << endl;
    cout<<"Enter name: ";
    cin>>person[total].name;
    cout<<"ID: ";
    cin>>person[total].ID;
    cout<<"Address: ";
    cin>>person[total].address;
    cout<<"Contact: ";
    cin>>person[total].contact;
    cout<<"Total cash: ";
    cin>>person[total].cash;
    
    total++;
}
void Bank::show(){
    for(int i=0;i<total;i++){
        cout<<"Data of person "<<i+1<<endl;
        cout<<"Name: "<<person[i].name<<endl;
        cout<<"ID: "<<person[i].ID<<endl;
        cout<<"Address: "<<person[i].address<<endl;
        cout<<"Contact: "<<person[i].contact<<endl;
        cout<<"Cash: "<<person[i].cash<<endl;
    }
}
void Bank::update(){
    cout<<"Enter ID of student whose data you want to update";
    
    cin>>id;
    for(int i=0;i<total;i++){
        if(person[i].ID==id){
            cout<<"Previous data"<<endl;
            cout<<"Data of person "<<i+1<<endl;
            cout<<"Name: "<<person[i].name<<endl;
            cout<<"ID: "<<person[i].ID<<endl;
            cout<<"Address: "<<person[i].address<<endl;
            cout<<"Cash: "<<person[i].cash<<endl;
            
            cout<<"Enter new data"<<endl;
            
            cout<<"Enter name: ";
            cin>>person[i].name;
            cout<<"ID: ";
            cin>>person[i].ID;
            cout<<"Address: ";
            cin>>person[i].address;
            cout<<"Contact: ";
            cin>>person[i].contact;
            cout<<"Total cash: ";
            cin>>person[i].cash;
            break;
        }
         if(i==total-1){
            cout<<"No such record found"<<endl;
        }
    }
}
void Bank::search(){
    cout<<"Enter id of student"<<endl;
    cin>>id;
    for(int i=0;i<total;i++){
        if(id==person[i].ID){
            cout<<"Data of person "<<i+1<<endl;
            cout<<"Name: "<<person[i].name<<endl;
            cout<<"ID: "<<person[i].ID<<endl;
            cout<<"Address: "<<person[i].address<<endl;
            cout<<"Contact: "<<person[i].contact<<endl;
            cout<<"Cash: "<<person[i].cash<<endl;
            break;
        }
        if(i==total-1){
            cout<<"No such record found"<<endl;
        }
    }
}
void Bank::transactions(){
    cout<<"Enter id of student"<<endl;
    cin>>id;
    for(int i=0;i<total;i++){
        if(id==person[i].ID){
            cout<<"Name: "<<person[i].name<<endl;
            cout<<"Address: "<<person[i].address<<endl;
            cout<<"Contact: "<<person[i].contact<<endl;
            cout<<"\nExisting cash "<<person[i].cash<<endl;
            cout<<"Press 1 to deposit"<<endl;
            cout<<"Press 2 to withdraw"<<endl;
            char ch;
            cin>>ch;
            int cash;
            switch(ch){
                case '1': cout<<"How much cash you want to deposit?";
                            cin>>cash;
                            person[i].cash+=cash;
                            cout<<"Your new cash: "<<person[i].cash<<endl;
                            break;
                case '2': back:
                          cout<<"How much cash you want to withdraw?"<<endl;
                          cin>>cash;
                          if(cash > person[i].cash){
                               cout<<"Your existing cash is just"<<person[i].cash<<endl;
                               goto back;
                           }
                           person[i].cash-=cash;
                            cout<<"Your new cash: "<<person[i].cash<<endl;
                            break;
                default:  cout<<"Invalid input"<<endl;
                            break;
            }
            break;
        }
        if(i==total-1){
            cout<<"No such record found"<<endl;
        }
    }
}
void Bank::remove_account(){
    
       cout<<"Enter id of student whose data you want to remove"<<endl;
                  cin>>id;
                  for(int i=0;i<total;i++){
                      if(id==person[i].ID){
                          for(int j=i;j<total;j++){
                               person[j].name=person[j+1].name;
                                person[j].ID=person[j+1].ID;
                                 person[j].address=person[j+1].address;
                                  person[j].contact=person[j+1].contact;
                                   person[j].cash=person[j+1].cash;
                          cout<<"requested record is removed"<<endl;
                          total--;
                          break;
                           }
                       }
                       if(i==total-1){
                           cout<<"No such record found"<<endl;
                       }
    }
}