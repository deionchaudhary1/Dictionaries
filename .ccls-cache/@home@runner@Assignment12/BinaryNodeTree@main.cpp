//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

  // ADT binary tree operations
#include <iostream>
#include <string>

class Person{
 private:
 string name;
 string birthday;

 public:
 string getName(){
   return name;
 }
 void setName(string n){
   name = n;
 }

 string getBirth(){
   return birthday;
 }
 string setBirth(string n){
   birthday = n;
 }
 };

 class Dictionary{
 //binary search tree implemenation because the search is log(n) or sorted list
 /*add an entry
 remove an entry
 search the dictionary for the birthday for a given name
 display the name and birthday of every entry in the dictionary
 display everyone in the dictionary who was born in a given month*/
 private:
 BinaryTreeInterface<Person>* tree1;


public:
Dictionary(){
  tree1 = new BinaryNodeTree<Person>();
}
void addEntry(Person p){
  tree1->add(p);
}

void removeEntry(Person p){
  tree1->remove(p);
}
void searchBirthday(Person p){
  if(tree1->getEntry(p) == p.getBirth())
    //Problem: need to sort by name - then i actually need to implement it


 };
  #include "BinaryNodeTree.h"


void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  // end check

int main()
{

   BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();
   
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");
   
   cout<<"Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80\n";
   tree1->preorderTraverse(display);
   
   cout<<"Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80\n";
   tree1->inorderTraverse(display);
   
   //cout<<"Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10\n";
   //tree1->postorderTraverse(display);
   
   cout << "Tree 1 height: " << tree1->getHeight() << endl;
   cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;
   
   cout << "Remove the leaf 80: ";
   bool success = tree1->remove("80");
   check(success);
   
   cout << "Try to remove the leaf 80 again: ";
   success = tree1->remove("80");
   check(success);
   
   cout << "Remove the leaf 50: ";
   success = tree1->remove("50");
   check(success);
   
   cout<<"Tree 1 Preorder: Should be 10 20 40 70 60 30\n";
   tree1->preorderTraverse(display);
   
   cout<<"Tree 1 Inorder: Should be 70 40 20 60 10 30\n";
   tree1->inorderTraverse(display);
   
   //cout<<"Tree 1 Postorder: Should be 70 40 60 20 30 10\n";
   //tree1->postorderTraverse(display);
   
   cout << "Tree 1 height: " << tree1->getHeight() << endl;
   cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;
   
   cout << "Remove the node 40 that has only a left child: ";
   success = tree1->remove("40");
   check(success);
   
   cout<<"Tree 1 Preorder: Should be 10 20 70 60 30\n";
   tree1->preorderTraverse(display);
   
   cout<<"Tree 1 Inorder: Should be 70 20 60 10 30\n";
   tree1->inorderTraverse(display);
   
   //cout<<"Tree 1 Postorder: Should be 70 60 20 30 10\n";
   //tree1->postorderTraverse(display);
   
   cout << "Tree 1 height: " << tree1->getHeight() << endl;
   cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;
   
   cout << "Remove the root 10 that has both left and right subtrees: ";
   success = tree1->remove("10");
   check(success);
   
   cout<<"Tree 1 Preorder: Should be 20 60 70 30\n";
   tree1->preorderTraverse(display);
   
   cout<<"Tree 1 Inorder: Should be 70 60 20 30\n";
   tree1->inorderTraverse(display);
   
   //cout<<"Tree 1 Postorder: Should be 70 60 30 20\n";
   //tree1->postorderTraverse(display);
   
   cout << "Tree 1 height: " << tree1->getHeight() << endl;
   cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << endl;
   
   return 0;
}  // end main

/* SAMPLE OUTPUT
 Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 40
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80
 Displaying item - 70
 Displaying item - 40
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 50
 Displaying item - 30
 Displaying item - 80
 Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10
 Displaying item - 70
 Displaying item - 40
 Displaying item - 60
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 4
 Tree 1 number of nodes: 8
 Remove the leaf 80: Done.
 Try to remove the leaf 80 again:  Entry not in tree.
 Remove the leaf 50: Done.
 Tree 1 Preorder: Should be 10 20 40 70 60 30
 Displaying item - 10
 Displaying item - 20
 Displaying item - 40
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Tree 1 Inorder: Should be 70 40 20 60 10 30
 Displaying item - 70
 Displaying item - 40
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Tree 1 Postorder: Should be 70 40 60 20 30 10
 Displaying item - 70
 Displaying item - 40
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 4
 Tree 1 number of nodes: 6
 Remove the node 40 that has only a left child: Done.
 Tree 1 Preorder: Should be 10 20 70 60 30
 Displaying item - 10
 Displaying item - 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Tree 1 Inorder: Should be 70 20 60 10 30
 Displaying item - 70
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Tree 1 Postorder: Should be 70 60 20 30 10
 Displaying item - 70
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 3
 Tree 1 number of nodes: 5
 Remove the root 10 that has both left and right subtrees: Done.
 Tree 1 Preorder: Should be 20 60 70 30
 Displaying item - 20
 Displaying item - 60
 Displaying item - 70
 Displaying item - 30
 Tree 1 Inorder: Should be 70 60 20 30
 Displaying item - 70
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Tree 1 Postorder: Should be 70 60 30 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Displaying item - 20
 Tree 1 height: 3
 Tree 1 number of nodes: 4


 #include <iostream>
 using namespace std;

 class Person{
 private:
 string name;
 string birthday;

 public:
 string getName(){
   return name;
 }
 void setName(string n){
   name = n;
 }

 string getBirth(){
   return birthday;
 }
 string setBirth(string n){
   birthday = n;
 }
 };

 class Dictionary{
 //binary search tree implemenation because the search is log(n) or sorted list
 add an entry
 remove an entry
 search the dictionary for the birthday for a given name
 display the name and birthday of every entry in the dictionary
 display everyone in the dictionary who was born in a given month
 private:
 string [] arr;
 };

 int main() {
   std::cout << "Hello World!\n";
 }
 */
