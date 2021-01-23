//	Burak EKÝNCÝ
//	1306181431
//  Date : 05.12.2020
//  Development Environment : Visual Studio 2019


#include <iostream>
#include <string>
#include <math.h>

void printUI();										//prints UI

void Rectangle1(int _input);						//
void Rectangle2(int _input);						//
void Rectangle3(int _input);						//draws patterns
void Rectangle4(int _input);						//
void Rhomb(int _input);								//
void Circle(int _input);							//

bool takeInput(int &_input);						//checks input, if input is integer turns true else turns false
bool UImanager(int& _choiceInput);					//checks choice input, if input value is not in UI list turns false else turns true
bool UImanager(int& _choiceInput, int& _dimensionInput);//after proper choice checks for value input, if input is proper turns true else turns false

int main() 
{
	int choiceInput; 	
	int dimensionInput;
	bool b_choice;
	bool b_dimension;
	do 
	{
		system("cls");								//clear console
		printUI();
		std::cout << "|Enter your choice : ";

		std::cout << std::flush;
		
		b_choice = takeInput(choiceInput);			//check choiceInput is integer, if not returns false
		if (b_choice == false) continue;			//if b_choice false ask again to user for input
		b_choice = UImanager(choiceInput);			//check choiceInput is proper for UI list, if not returns false else does the management
		if (b_choice == false) continue;			//if b_choice false ask again to user for input
		
		std::cout << "|Enter your dimension : ";			//after selected pattern, wait for the dimension
		b_dimension = takeInput(dimensionInput);			//check dimensionInput is integer, if not returns false
		if (b_dimension == false) continue;					//if b_dimension false ask again to user for input
		b_dimension = UImanager(choiceInput,dimensionInput);//check dimensionInput is proper for UI list, if not returns false else does the management
		if (b_dimension == false) continue;					//if b_dimension false ask again to user for input

		system("pause");
	} while (true);
	
	return 0;
}

void printUI()
{
	std::cout << "|----------------------|\n";
	std::cout << "|         UI list      |\n";
	std::cout << "|----------------------|\n";
	std::cout << "|    1.Rectangle 1     |\n";
	std::cout << "|    2.Rectangle 2     |\n";
	std::cout << "|    3.Rectangle 3     |\n";
	std::cout << "|    4.Rectangle 4     |\n";
	std::cout << "|    5.Rhomb(odd only) |\n";
	std::cout << "|    6.Circle          |\n";
	std::cout << "|    7.Exit            |\n";
	std::cout << "|______________________|\n";
	
}

bool takeInput(int& input)
{
	std::string _strInput;
	bool isFine = false;					//is input fine?
	//check is input integer and take one integer
	do
	{
		
		std::cin >> _strInput;				//get the input
		std::cin.clear();					//clear error flag
		std::cin.ignore(INT_MAX, '\n');		//ignore until '\n'
		
		//is input integer or string
		for(unsigned int i = 0;i < _strInput.length();i++)
		{	
			if(isdigit(_strInput[i])==0)	//if isdigit returns 0 it means there is a character which is not digit so string is not integer
			{
				isFine = false;
				std::cout << "|Your input is : " << _strInput << " |\n";
				std::cout << ".......................\n" ;
				std::cout << ".Input is not correct!.\n" ;
				std::cout << ".    Integers Only    .\n" ;
				std::cout << ".......................\n" ;
				system("pause");
				return false;
			}
			else
			{
				isFine = true;	
			}
		}
		
		//converting string to integer
		if(isFine == true){input = std::stoi(_strInput);}
		else
		{
			continue;	//if input not integer ask again to user
		}
		

	}while(isFine==false);
	std::cout <<"|Your input is : "<< _strInput<<" |\n";	//prints user input
	std::cout << "|__________________|\n";
	return true;
}

bool UImanager(int& _choiceInput,int& _dimensionInput)
{
	std::cout<<"\n";
	std::cout << "===============================\n";
	bool isOkay = true;
		switch (_choiceInput)
		{
		case 1:
			Rectangle1(_dimensionInput);
			break;
		case 2:
			Rectangle2(_dimensionInput);
			break;
		case 3:
			Rectangle3(_dimensionInput);
			break;
		case 4:
			Rectangle4(_dimensionInput);
			break;
		case 5:
			//ask user to input value again if not odd
			while (_dimensionInput % 2 == 0)
			{
				std::cout << ".......................\n";
				std::cout << ".Dimension NOT correct.\n";
				std::cout << ".   Odd number only   .\n";
				std::cout << ".......................\n";
				system("pause");
				system("cls");
				printUI();
				std::cout << "|Your choice input is : "<< _choiceInput <<"\n";
				std::cout << "|__________________|\n";
				std::cout << "|Your dimension is : ";
				takeInput(_dimensionInput);
				std::cout << std::flush;
			}
			if (isOkay == false) { break; }
			Rhomb(_dimensionInput);
			break;
		case 6:
			Circle(_dimensionInput);
			break;
		default:
			break;
		}
	
	std::cout << "===============================\n";
	std::cout << "\n";
	return true;
}

bool UImanager(int& _choiceInput)
{
	if (_choiceInput == 7) 
	{
		std::cout << ".......................\n";
		std::cout << ".     Exiting app     .\n";
		std::cout << ".......................\n";
		exit(0);
	}
	while (_choiceInput < 1 || _choiceInput>7)
	{
		std::cout << ".......................\n";
		std::cout << ". Input  NOT  correct .\n";
		std::cout << ".  Between  1-7 only  .\n";
		std::cout << ".......................\n";
		system("pause");
		return false;
	}
	return true;
}

void Rectangle1(int _input)
{
	std::cout << "Rectangle 1\n";
	for (int i = 0; i < _input ; i++)	//Y-axis
	{
		for (int j = 0; j < i+1 ; j++)  //X-axis
		{
			std::cout << "*";
		}
		std::cout<<"\n";
	}
}

void Rectangle2(int _input)
{
	std::cout << "Rectangle 2\n";
	for (int i = 0; i < _input; i++)		 //Y-axis
	{
		for (int j = 0; j < _input - i; j++) //X-axis
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void Rectangle3(int _input)
{
	std::cout << "Rectangle 3\n";
	for (int i = 0; i < _input; i++)		 //Y-axis
	{
		for (int j = 0; j < _input - i-1; j++) //X axis(first part)
		{
			std::cout << " ";
		}
		for (int j = 0; j < i+1; j++)		//X axis (second part)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void Rectangle4(int _input)
{
	int n = _input / 2;
	std::cout << "Rectangle 4\n";
	for (int i = 1; i < n+2; i++)			//Y axis
	{
		for (int j = 0; j < n - i+1; j++)	//X axis(first part)
		{
			std::cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) //X axis (second part)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

}

void Rhomb(int _input)
{
	std::cout << "Rhomb\n";
	int n = _input / 2 +1;
	for (int i = 1; i <= n; i++)			//Y axis(first part)
	{
		for (int j = 1; j <= n - i; j++)	//X axis(first part)
		{
			std::cout << " ";
		}
		for (int j = 1; j <= 2*i-1; j++)	//X axis (second part)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
	for (int i = 1; i <= n -1; i++)					//Y axis(second part)
	{
		for (int j = 1; j <= i; j++)				//X axis(first part)
		{
			std::cout << " ";
		}
		for (int j = 1; j <= 2 * (n -i) - 1; j++)	//X axis (second part)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}


}

void Circle(int _input)
{
	int c = _input / 2 + 1;		//center point in coordinate system
	int r = _input - c;			//radius length
	std::cout << "Circle\n";
	for (int i = 1; i <= _input; i++)		//Y axis of coordinate system
	{
		for (int j = 1; j <= _input; j++)	//X axis of coordinate system
		{
			if (pow(c - i, 2) + pow(c - j, 2) <= pow(r, 2) + r + 1 &&	//if hypotenuse is between radius^2 + (radius +1) and radius^2 - (radius +1) 
				pow(c - i, 2) + pow(c - j, 2) >= pow(r, 2) - r + 1)		//prints '*' else prints ' '
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}