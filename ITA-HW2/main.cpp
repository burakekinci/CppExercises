// Burak EKÝNCÝ
// 1306181431
// Date: 15.01.2021
// Development Environment: Visual Studio2019
#include <iostream>
#include <vector>
#include <sstream>              //need for "getline","stod"...
#include <fstream>
#include <map>
#include <stack>
#include <algorithm>            //need for "remove_if"...
using namespace std;

//Declarations of functions
void myfile();
void fileprocess(string filename);                                        //reads file and gives output
void lineprocess(string line, map<char,double>& _variables,string fname); //reads lines and make processes
void printOut(double result, string fname);                               //prints given result to given output filename
string cleanWhiteSpacesS(string str);                                     //removes white spaces from line
int prec(char c);                                                         //get from geeksforgeeks stack|set2
double postfixCalculation(string& postfix, map<char, double> _variables); //idea get from geeksforgeeks stack|set4
bool isRightDataExpression(const string& _rightData);                     //check the right data of seperated line
vector<string> lineSeperate(string str);                                  //seperates the given line according to "=" operator
string infixToPostFix(string s);                                          //get from geeksforgeeks stack|set2

int main()
{
    //giving input files
    fileprocess("Challange1.inp");
    fileprocess("Challange2.inp");
    fileprocess("Challange3.inp");
    fileprocess("Challange4.inp");
    fileprocess("Challange5.inp");
    fileprocess("Challange6.inp");
    myfile();
    fileprocess("myfile.inp");
}

//Definitions of functions
void fileprocess(string filename)
{
    map<char, double> variables;                                          //variable-value map declaration                                           
    string line;
    ifstream myfile(filename);
    if (myfile)                                                           //file opened successfully
    {
        while (getline(myfile, line))                                     //read all lines sequentially
        {
            lineprocess(line,variables,filename);                         //do line processes
        }
    }
    else                                                                  //file couldn't open
    {
        cout << "dosya acilamadi" << endl;
    }
    myfile.close();                                                       //closing file
}

void lineprocess(string line, map<char, double>& _variables,string fname)
{
    string cleanLine = cleanWhiteSpacesS(line);                          //line with removed white spaces
    vector<string> seperatedLine;                                        //declaration of seperated line
    
    if (line.find("OUT") != std::string::npos)                           //if there is a "OUT" keyword writes result to the output file
    {
        string output = line.substr(4, line.length());
        printOut(_variables[output[0]],fname);
    }
    else                                                                 //if theres is no keyword do processes
    {
        seperatedLine = lineSeperate(cleanLine);                         //seperating "cleanline" according to "=" operator
        string variableName = seperatedLine[0];                          //setting variable name
        
        if (isRightDataExpression(seperatedLine[1]))                     //check right data of seperatedline if it's an expression do processess
        {
            string postFix = infixToPostFix(seperatedLine[1]);           //convert seperatedline's right data to postfix
            double result = postfixCalculation(postFix, _variables);     //calculate postfix
            _variables.insert({ variableName[0],result  });              //insert variable name and value in the variable-value map
        }
        else                                                             //if it's not an expression do process
        {
            _variables.insert({ variableName[0],stod(seperatedLine[1]) }); //it means right data of seperatedline is a value
                                                                           //so directly insert variable name and value in the variable-value map
        }
    }


}

string infixToPostFix(string s)                                           //converting given infix string to postfix string
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for (int i = 0; i < l; i++)                                          
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
        {
            ns += s[i];
        }
        else if (s[i] == '(')                                             
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if (st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        else
        {
            while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    while (st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    return ns;
}

int prec(char c)                                                         //setting operator precedence
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

double postfixCalculation(string& postfix, map<char, double> _variables) //calculation of postfix
{
    stack<double> numbers;                                               //declaration of numbers stack
    for (int i = 0; i < postfix.length(); i++)                           //check all indexes of postfix
    {
        if (isalpha(postfix[i]) && (postfix[i] !='*' && postfix[i] != '/'     //if index is alphabetic and not an operator then push value of index 
                                    && postfix[i] != '-' && postfix[i] != '+')//from variable-value map into the numbers stack
        )
        {
            numbers.push(_variables[postfix[i]]);
        }
        else if (postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')//if index is an operator then do processes
        {
            double number1 = numbers.top(); numbers.pop();               //set number1 stack's top value and remove it from stack
            double number2 = numbers.top(); numbers.pop();               //set number2 stack's top value and remove it from stack
            
            if (postfix[i] == '*')
            {
                numbers.push(number2 * number1);                         //if index is "*" operator multiply two numbers and push result into numbers stack
            }
            else if (postfix[i] == '/')
            {
                 numbers.push(number2 / number1);                        //if index is "/" operator divide two numbers and push result into numbers stack
            }
            else if (postfix[i] == '+')
            {
                numbers.push(number2 + number1);                         //if index is "+" operator divide two numbers and push result into numbers stack
            }
            else if (postfix[i] == '-')
            {
                numbers.push(number2 - number1);                         //if index is "-" operator divide two numbers and push result into numbers stack
            }
        }
    }
    return numbers.top();                                               //return the top value of stack
}

void printOut(double result, string fname)
{
    int size = fname.length();                                         //set size to the length of input filename
    string outFilename;
    switch (fname[size-5])                                             //set output filename according to input filename's number
    {
    case 49:
        outFilename = "challange1.out";
        break;
    case 50:
        outFilename = "challange2.out";
        break;
    case 51:
        outFilename = "challange3.out";
        break;
    case 52:
        outFilename = "challange4.out";
        break;
    case 53:
        outFilename = "challange5.out";
        break;
    case 54:
        outFilename = "challange6.out";
        break;
    default:
        break;
    }
    if (fname == "myfile.inp") {
        ofstream outfile{ "myfile.out" };
        outfile << result;
        outfile.close();
    }
    else
    {
        ofstream outfile{ outFilename };
        if (!outfile)
        {
            cout << "out dosyasi acilamadi" << endl;
        }
        else
        {
            outfile << result;                                              //write result to the output file
            outfile.close();
        }
    }
    
}

vector<string> lineSeperate(string str)
{
    vector<string> seperatedVector;
    string leftData;
    string rightData;
    for (int i = 0; i < str.length(); i++)                               //find "=" operator and set leftdata from index0 to "=",and set rest of to the rightdata 
    {                                                                    //push back leftdata and rightdata into the seperatedVector
        if (str[i] == '=')
        {
            leftData = str.substr(0, i);
            rightData = str.substr(i + 1);
            seperatedVector.push_back(leftData);
            seperatedVector.push_back(rightData);
            break;
        }
    }
    return seperatedVector;
}

string cleanWhiteSpacesS(string str)
{
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), str.end());//remove white spaces from given string
    return str;
}

bool isRightDataExpression(const string& _rightData)
{
    try
    {
        double value = stod(_rightData);
        return false;      //if _rightData can convert to double it means it is not expression
    }
    catch (const std::exception&)
    {
        return true;        //if _rightData cant convert to double it means it's expression
    }
}

void myfile()
{
    ofstream outfile{ "myfile.inp" };
    if (outfile)
    {
        outfile << "A = 8\n";
        outfile << "B = 5\n";
        outfile << "C = A - B\n";
        outfile << "D = C * ( A - B)\n";
        outfile << "OUT D\n";

    }
}