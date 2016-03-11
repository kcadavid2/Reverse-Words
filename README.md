# Reverse-Words
OOP Project Question#1

#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<string> myStack;
    char arr[] = "This sentence will be reversed by pushing the words onto the stack and popping them out";
    char * pch;
    pch = strtok (arr," ");
    
    while (pch != NULL)
    {
        myStack.push(pch);
        pch = strtok (NULL, " ");
    }
    
    while (!myStack.empty())
    {
        cout << ' ' << myStack.top();
        myStack.pop();
    }

    return 0;
}
