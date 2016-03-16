
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <stack>
using namespace std;

int main () {
    string firstLine;
    string line;
    ifstream myfile ("B-large-practice.in.txt");
    ofstream myfile2 ("largeOutputFile.txt");
    string totalCredit;
    string spacedStrings;
    stack<string> myStack;
    int caseNum = 1;
    
    //while both files are open
    if (myfile.is_open() )//&& myfile2.is_open())
    {
        while ( getline (myfile,line) )
        {
            //get the first line, which will state the number of cases
            getline(myfile, firstLine);
            int convertedFirstLine = atoi(firstLine.c_str());
            
            //run for as many cases there are
            for(int b=0; b<convertedFirstLine; b++) //consider using while loop
            {
                list<string> steps;
                
                //cout << "Enter the cost of the items in the store separated by spaces" << endl;
                getline(myfile, spacedStrings);
                
                istringstream is( spacedStrings );
                string n;
                while( is >> n ) {
                    steps.push_back(n);
                }
                
                for (list<string>::const_iterator i = steps.begin(); i != steps.end(); ++i)
                {
                    myStack.push(*i);
                }
                
                myfile2 << "Case #" << caseNum << ": ";

                while (!myStack.empty())
                {
                    myfile2 << myStack.top() << " ";
                    myStack.pop();
                }
                myfile2 << endl;
                caseNum++;
            }
            
            
            myfile2.close();
            myfile.close();
        }
    }
    else cout << "Unable to open file";
    
    return 0;
}

