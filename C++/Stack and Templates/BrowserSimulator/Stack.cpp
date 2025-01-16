/*****************************************
** File: Stack.cpp
** Project: CMSC 202 Project 5, Fall 2024
** Author: Saim Siddique
** Date: 12/1/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program defines the stack class
** 
***********************************************/

#include <iostream>
#include <stdexcept>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
  m_data = data;
  m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
  return m_data;
}


//Sets the data in a Node
template <class T>
void Node<T>::SetData(const T& data ) {
  m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
  return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
  m_next = next;
}

//**********Stack Class Declaration***********
template <typename T> //Indicates linked list is templated
class Stack {
public:
  // Name: Stack (Default constructor)
  // Description: Creates a new Stack object
  // Preconditions: None
  // Postconditions: Creates a new Stack object
  Stack();
  // Name: ~Stack
  // Description: Stack destructor - deallocates all nodes in linked list
  // Preconditions: None
  // Postconditions: All nodes are deleted. Size is 0. No memory leaks.
  ~Stack();
  // Name: Stack (Copy constructor)
  // Description: Creates a new Stack object based on existing stack
  // Preconditions: None
  // Postconditions: Creates a new Stack object from existing stack
  //                 in separate memory space
  Stack(const Stack& source);
  // Name: Stack<T>& operator= (Assignment operator)
  // Description: Makes two stacks identical based on source.
  // Preconditions: None
  // Postconditions: Two stacks with same number of nodes and same values
  //                 in each node in a separate memory space
  Stack<T>& operator=(const Stack& other);
  // Name: Push
  // Description: Adds a new node to the top of the stack
  // Preconditions: None
  // Postconditions: Adds a new node to the top of the stack
  void Push(const T& value);
  // Name: Pop
  // Description: If stack is empty, throw runtime_error("Stack is empty");
  //              Temporarily stores data from node at the top of the stack.
  //              Removes the node from the top of the stack. Returns the stored data.
  // Preconditions: Stack has at least one node
  // Postconditions: See description 
  T Pop();
  // Name: Peek
  // Description: If stack is empty, throw runtime_error("Stack is empty");
  //              Returns the stored data from top node.
  // Preconditions: Stack has at least one node
  // Postconditions: See description
  T Peek() const;
  // Name: At
  // Description: If stack is empty, throw runtime_error("Stack is empty")
  //              Returns stored data from number of the node passed to function.
  //              At(3) would return the data from the fourth node.
  // Preconditions: Stack has at least one node
  // Postconditions: Returns data from number of node starting at m_top
  T At(int num);
  // Name: IsEmpty
  // Description: Returns if the stack has any nodes.
  // Preconditions: Stack has at least one node
  // Postconditions: If stack has no nodes, returns true. Else false.
  bool IsEmpty() const;
  // Name: RemoveBottom
  // Description: If stack is empty, throw runtime_error("Stack is empty")
  //              Temporarily stores data from node at the bottom of the stack.
  //              Removes node from bottom of the stack. Returns the stored data.
  //              Similar to Pop but opposite end of stack
  // Preconditions: Stack has at least one node
  // Postconditions: Removes node from bottom of stack and returns data
  T RemoveBottom();
  // Name: Display
  // Description: If stack is empty, outputs that the stack is empty
  //              Otherwise, iterates through stack and displays data in each node
  // Preconditions: Stack has at least one node
  // Postconditions: Displays data from each node in stack
  void Display();
  // Name: GetSize
  // Description: Returns the number of nodes in the stack
  // Preconditions: None
  // Postconditions: Returns the number of nodes in the stack.
  size_t GetSize() const;  
private:
  Node<T>* m_top; //Top node in stack
  size_t m_size; //Number of nodes in stack
};

//*********************STACK FUNCTIONS IMPLEMENTED HERE******************
  
// Name: Stack (Default constructor)
// Preconditions: None
// Postconditions: Creates a new Stack object
template <class T>
Stack<T>::Stack(){
  // sets m_top to nullptr
  m_top = nullptr;
  // m_size to 0
  m_size = 0;
}


// Name: ~Stack
// Preconditions: None
// Postconditions: All nodes are deleted. Size is 0. No memory leaks.
template <class T>
Stack<T>::~Stack(){
  // loops through until m_top is empty
  while (m_top) {
    // sets a temporary node = to m_top
    Node<T>* temp = m_top;
    // iterates to the next thing in m_top
    m_top = m_top->GetNext();
    // deletes said node
    delete temp;
  }
  m_size = 0;
}


// Name: Stack (Copy constructor)
// Preconditions: None
// Postconditions: Creates a new Stack object from existing stack in separate memory space
template <class T>
Stack<T>::Stack(const Stack& source){
  m_top = nullptr;
  m_size = 0;
  // sets a node pointer equal to source
  Node<T>* current = source.m_top;
  // sets a node pointer prev to nullptr
  Node<T>* prev = nullptr;
  
  // loops through the current node pointer until we reach the end
  while (current){
    // dynamically allocates a new node
    Node<T>* newNode = new Node<T>(current->GetData());
    // if m_top is not empty, meaning equal to 0
    if (!m_top){
      m_top = newNode; 
    }
    // iterates simular to the method of m_top
    if (prev){
      prev->SetNext(newNode);
    }

    prev = newNode;
    // iterates through current
    current = current->GetNext();
  }
  // resets the size
  m_size = source.m_size;
}


// Name: Stack<T>& operator= (Assignment operator)
// Preconditions: None
// Postconditions: Two stacks with same number of nodes and same values
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& other){
  if (this != &other) {
    // loops through m_top until its empty
    while (m_top) {
      Node<T>* temp = m_top;
      m_top = m_top->GetNext();
      // deletes the created temp pointer
      delete temp;
    }
    m_size = 0;

    // sets a current node pointer
    Node<T>* current = other.m_top;
    // sets a prev node pointer
    Node<T>* prev = nullptr;
    
    while (current){
    // dynamically allocates a new node of the same node
      Node<T>* newNode = new Node<T>(current->GetData());
      if (!m_top){
        m_top = newNode;
      }
      if (prev){
        // sets our prev to the next node
        prev->SetNext(newNode);
      }
      prev = newNode;
      // iterates current to whats next
      current = current->GetNext();
    }
    m_size = other.m_size;
  }
  // returns this
  return *this;
}


// Name: Push
// Preconditions: None
// Postconditions: Adds a new node to the top of the stack
template <class T>
void Stack<T>::Push(const T& value){
  // dynmically allocates a new node
  Node<T>* newNode = new Node<T>(value);
  // dereferencing node to use the setnext function
  newNode->SetNext(m_top);
  m_top = newNode;
  // increments the size
  ++m_size;
}


// Name: Pop
// Preconditions: Stack has at least one node
// Postconditions: See description 
template <class T>
T Stack<T>::Pop(){
  // checks to see if the stack is empty
  if (IsEmpty()){
    cout << "Stack is empty" << endl;
  }
  
  // creates a temporary node pointer and sets it equal to m_top
  Node<T>* temp = m_top;
  
  T data = temp->GetData();
  m_top = m_top->GetNext();
  // deletes the temporary pointer
  delete temp;
  // decrements size
  --m_size;
  return data;
}


// Name: Peek
// Preconditions: Stack has at least one node
// Postconditions: See description
template <class T>
T Stack<T>::Peek() const{
  // checks to see if stack is empty
  if (IsEmpty()){
    cout << "Stack is empty" << endl;
  }
  // returns the data of the element at the top
  return m_top->GetData();
}

  
// Name: At
// Preconditions: Stack has at least one node
// Postconditions: Returns data from number of node starting at m_top
template <class T>
T Stack<T>::At(int num){
  // checks to see if stack is empty
  if (IsEmpty()){
    cout << "Stack is empty" << endl;
  }
  // checks to see if num is out of range
  if (num < 0 || num >= static_cast<int>(m_size)){
    cout << "Invalid position" << endl;
  }
  // sets a current pointer to m_top
  Node<T>* current = m_top;
  // loops through num
  for (int i = 0; i < num; ++i){
    // gets current up the the proper number
    current = current->GetNext();
  }
  // returns current
  return current->GetData();
}

// Name: IsEmpty
// Preconditions: Stack has at least one node
// Postconditions: If stack has no nodes, returns true. Else false.
template <class T>
bool Stack<T>::IsEmpty() const{
  return m_top == nullptr;
}


// Name: RemoveBottom
// Preconditions: Stack has at least one node
// Postconditions: Removes node from bottom of stack and returns data
template <class T>
T Stack<T>::RemoveBottom(){
    if (IsEmpty()){
      // returns a default value
      return T();
    }

    if (m_size == 1){
      // pops if theres only one element
      return Pop(); 
    }

    // iterates to the second to last node
    Node<T>* current = m_top;
    while (current->GetNext()->GetNext()){
      current = current->GetNext();
    }

    // Gets the bottom node and its data
    Node<T>* bottomNode = current->GetNext();
    T data = bottomNode->GetData();

    // Deletes the bottom node and updates the second-last node
    delete bottomNode;
    current->SetNext(nullptr);

    // Decrements the size
    --m_size;

    return data;
}


// Name: Display
// Preconditions: Stack has at least one node
// Postconditions: Displays data from each node in stack
template <class T>
void Stack<T>::Display(){
  // checks to see if the stack is empty
  if (IsEmpty()) {
    cout << "Stack is empty" << endl;
    return;
  }
  // sets current to m_top
  Node<T>* current = m_top;
  // loops through the stack
  while (current) {
    // couts the data for the stack
    cout << current->GetData() << endl;
    // sets current to next
    current = current->GetNext();
  }
}


// Name: GetSize
// Preconditions: None
// Postconditions: Returns the number of nodes in the stack.
template <class T>
size_t Stack<T>::GetSize() const{
  // returns the size
  return m_size;
}