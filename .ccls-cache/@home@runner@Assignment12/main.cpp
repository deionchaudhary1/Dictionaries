#include <iostream>
 using namespace std;

 class Person{
 private:
 string name;
 string birthday;

 public:
Person(){
  name = " ";
  birthday = " ";
}
~Person(){
  name = " ";
  birthday = " ";
}
 string getName(){
   return name;
 }
 void setName(string n){
   name = n;
 }

 string getBirth(){
   return birthday;
 }
 void setBirth(string n){
   birthday = n;
 }

 };

 class Dictionary{

/*
 add an entry
 remove an entry
 search the dictionary for the birthday for a given name
 display the name and birthday of every entry in the dictionary
 display everyone in the dictionary who was born in a given month*/
 private:
Person items[20];
int count;
int max;

public:
Dictionary(){
  count = 0;
  max = 20;
}

~Dictionary(){
  count=0;
  max=0;
}

bool add(Person p){
  if (count >= max){
    return false;
  } 
  int i; 
  for (i = count; (i >= 0 && items[i].getName() > p.getName()); i--) {
    items[i + 1] = items[i]; 
  }
  items[i + 1] = p; 
  count++;
  return true;
}

bool remove(Person p){
  int index = binarySearch(0, count, p.getName()); 
  if (index == -1) {  
      return false; 
  } 
 
  int i; 
  for (i = index; i <= count; i++) {
    items[i] = items[i + 1]; 
  }
  count--;
  return true;
}

void display(){
  for(int i = 0; i<=count; i++){
    cout<<((items[i]).getName())<<" "<<(items[i].getBirth())<<endl;
  }
}

int binarySearch(int low, int high, string n)
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2; 
    if (n == items[mid].getName()) 
        return mid; 
    if (n > items[mid].getName()) 
        return binarySearch((mid + 1), high, n); 
    return binarySearch(low, (mid - 1), n); 
}

string getBirth(string name){
  int index = binarySearch(0, count, name);
  return items[index].getBirth();
}

void displayBirthM(string month){ 
  for(int i = 0; i<=count; i++){
      if(items[i].getBirth().substr(0,2) == month.substr(0,2)){
      cout<<(items[i]).getName()<<endl;
    }
  }
}


 };

 int main() {
   Person p;
   p.setName("John");
   p.setBirth("11/12/98");
   Person b;
    b.setName("Josh");
    b.setBirth("12/25/98");
   Person g;
   g.setName("Natalie");
   g.setBirth("11/26/00");
   Dictionary d;
   d.add(p);
   d.add(b);
   cout<<"Displaying Dictionary: ";
   d.display();
   cout<<endl;
   d.remove(b);
   cout<<"Displaying Dictionary after removing Josh: ";
   d.display();
   cout<<endl;
   d.add(g);
   cout<<"Displaying Dictionary after adding Natailie: ";
   d.display();
   cout<<endl;
   cout<<"Displaying the Birthday of John:"<<endl;
   cout<<d.getBirth("John")<<endl;
   cout<<endl;
   cout<<"Displaying names of those born in November:"<<endl;
   d.displayBirthM("11/26/00"); 
 }
 
