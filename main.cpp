#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include<cstdlib.>
using namespace std;
int dayy(){
int d=0;
cout<<"Enter day :";
cin>>d;
if(d<1||d>31){
    cout<<"Invalid day"<<endl;
    cout<<"Enter day again"<<endl;
    d=dayy();
}

return d;
}
int monthh(){
int m=0;
cout<<"Enter Month :";
cin>>m;
if(m<1||m>12){
    cout<<"Invalid month"<<endl;
    cout<<"Enter Month again "<<endl;
    m=monthh();
}
return m;
}
int yearr(){

int y=0;
cout<<"Enter year :";
cin>>y;
if(y<1970||y>2099){
    cout<<"Year out of range"<<endl;
    cout<<"Enter year again"<<endl;
    y=yearr();
}
return y;
}
class date{
private:
    int day;
    int month;
    int year;
public:
void getdate(){

day=dayy();
month=monthh();
year=yearr();
}
bool checkdate(int d,int m,int y){
    d=day;
    m=month;
    y=year;

if(d==31&&(m==4||m==6||m==9||m==11)){
  return 0;
}
else if((d==30||d==31)&&m==2){
        return 0;
}
else if(d==29&&m==2&&y%4!=0){
       return 0;
}
else
    return 1;
}
string returndate(){
    stringstream s;
while (checkdate(day,month,year)==0){
   cout<<"Invalid date, Enter date again"<<endl;
   getdate();
}
s<<day<<"/"<<month<<"/"<<year<<"";
return s.str();
}
};
class record{
private:
    int id;
    string description;
    double quantity;
    double wholesalecost;
    double retailcost;
    string datee;
    date idate;
public:
    void writedata(){
    ofstream out("e:\\abc.txt");
    if(!out){
        cout<<"File opening error";
        exit(1);
          }
    out<<id<<endl;
    out<<description<<endl;
    out<<wholesalecost<<endl;
    out<<retailcost<<endl;
    out<<datee<<endl;
    out.close();
          }
    void savedata(){
    ofstream write;
    write.open("e:\\abc.txt",ios::app);
    write<< id<<endl;
    write<< description<<endl;
    write<< quantity<<endl;
    write<< wholesalecost<<endl;
    write<< retailcost<<endl;
    write<< datee<<endl;
    write.close();
    }
    void readdata(int i){

        ifstream in("e:\\abc.txt");
        if(!in){
            cout<<"File opening error";
            exit(1);
        }
for(int j=0;j<i;j++){
        in>>id;
        in>>description;
        in>>quantity;
        in>>wholesalecost;
        in>>retailcost;
        in>>datee;
}

in.close();


        }
    void getrecord(int recordeditems){


        id=recordeditems;
        cout<<"Enter Description of Item :";
        getline(cin,description);
        cout<<"Enter quantity :";
        cin>>quantity;
        cout<<"Enter Wholesale cost :";
        cin>>wholesalecost;
        cout<<"Enter Retail Cost :";
        cin>>retailcost;
        cout<<"Enter added date of inventory :";
        idate.getdate();
        datee=idate.returndate();

}
  void showrecord(){
  cout<<"*******************************************************************************"<<endl;
  cout<<"* Item ID Number :"<<id<<endl;
  cout<<"* Description of Item :"<<description<<endl;
  cout<<"* Quantity of Item :"<<quantity<<endl;
  cout<<"* Wholesale cost of Item :"<<wholesalecost<<endl;
  cout<<"* Retail Cost of Item :"<<retailcost<<endl;
  cout<<"* Added date of Inventory :"<<datee<<cout<<endl;
  cout<<"*******************************************************************************"<<endl;

  }
  void cleardata(){
  ofstream ofs;
  ofs.open("e://abc.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  }
};
int main()
{
    record records[50];
    int recordeditems; //number of records which have been entered.
    ifstream in("e:\\index.txt");
    in>> recordeditems;
    if(!in){
        ofstream out("e:\\index.txt");
        recordeditems=0;
        out<<recordeditems;
    }
    char ch;
   do{
        char choice;
        cout<<"Press 'A' to Add  New Records to File"<<endl;
        cout<<"Press 'D' to Display Any Record to File"<<endl;
        cout<<"Press 'M' to Modify any existed Record to File"<<endl;
        cout<<"Enter Choice :";
        cin>>choice;
        cin.ignore();
     switch(choice){
         case 'A':{
             recordeditems++;
            ofstream out("e:\\index.txt");
            out<< recordeditems;
             if(recordeditems==1){
                records[recordeditems-1].getrecord(recordeditems);
                records[recordeditems-1].writedata();
             }
             else{
             records[recordeditems-1].getrecord(recordeditems);
             records[recordeditems-1].savedata();

              }




            }break;


         case 'D':{
             record call;
             a:
             system("cls");
             int i;
             cout<<"Which Recorded Item, Would you like to display :";
             cin>>i;
             if(i>recordeditems){
                cout<<"Record item is not stored yet"<<endl;
                system("pause");
                goto a;
             }
             call.readdata(i);
             call.showrecord();

         }break;
         case 'M':{
             int mod;
             int n;
            for(int i=0;i<recordeditems;i++){
                records[i].readdata(i+1);
            }
             cout<<"Enter which record number you want to modify :";
              cin>>mod;
              cin.ignore();
              records[mod-1].getrecord(mod);
              records[mod-1].cleardata();


            for(int j=0;j<recordeditems;j++){
                  if(j==0){
                    records[j].writedata();
                  }
                  else{
                    records[j].savedata();
                  }
                 }

                  }break;



            default:{

            cout<<"Invalid Option";
            }continue;

     }
     cout<<endl<<"Enter 'y' to go back to menu ";
     cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}
