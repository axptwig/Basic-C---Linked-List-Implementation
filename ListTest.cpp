#include <iostream>
#include <cassert>
#include "linkedList.cpp"
using namespace std;

//fixtures
LinkedList list;

void TestAddValue(){
  list.addValue(5);
  assert(list.head->data == 5);
  cout << "First Assert Passed!" << endl;
}
void TestMiddleElement(){
  list.addValue(5);
  list.addValue(10);
  list.addValue(15);
  Node* n = list.middleElement();
  assert(n->data == 10);
  cout << "Second Assert Passed!" << endl;
}
void TestFindLoop(){
  list.addValue(5);
  list.addValue(10);
  list.addValue(15);
  list.addValue(20);
  list.addValue(25);
  list.addValue(30);
  list.addValue(35);
  list.createLoop();
  Node* n = list.hasLoop();
  assert(n->data == 5);
  cout << "Third Assert Passed!" << endl;
}

int main(){
  LinkedList list;
  TestAddValue();
  TestMiddleElement();
  TestFindLoop();

}
