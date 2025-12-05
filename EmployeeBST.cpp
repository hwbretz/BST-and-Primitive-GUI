/*************************************************
Harris Bretz
Lab 4 - COSC 2436 Prog. III, Summer 2024
EmployeeBST.cpp
Driver application to manage Employee data
**************************************************/

//includes
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <fstream>
#include "BinarySearchTree.h"
#include "EmployeeInfo.h"

//using namespace std;

const int SEARCH = 0;
const int DISPLAY = 1;
const int ADD_EMP = 2;
const int REMOVE_EMP = 3;
const int EXIT_PROG = 4;

const int DOWN = 0x28;
const int UP = 0x26;
const int ENTER = 0x0D;

//PROTOTYPES
void setCoordinates(int x, int y);
void plantTree(BinarySearchTree<EmployeeInfo> &tree, std::string fileName);

// for handling arrow key menu interaction
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


int main()
{



  // ints for menu interaction
  int menuItem = 0;
  int run;
  int yCoord = 7;

  BinarySearchTree<EmployeeInfo> empBST;
  plantTree(empBST,"Employees.txt");



  setCoordinates(10,4);
  std::cout<<"Welcome to the Employee ID Tool.";
  setCoordinates(10,5);
  std::cout<<"Use the arrow keys to navigate the menu and press Enter to select an option.";
  setCoordinates(20,7);
  std::cout<<">>";

  // sentinel boolean
  bool keepGoing = true;

  // loop for interface
  while(keepGoing)
  {
    setCoordinates(20,7);
    std::cout<<"Search for Employee by ID";
    setCoordinates(20,8);
    std::cout<<"Display Employees";
    setCoordinates(20,9);
    std::cout<<"Add New Employee";
    setCoordinates(20,10);
    std::cout<<"Remove Employee";
    setCoordinates(20,11);
    std::cout<<"Exit";

    // >nul prints no message
    system("pause>nul");

    // down arrow pressed
    if(GetAsyncKeyState(DOWN)&& yCoord != 11)
    {
      setCoordinates(18,yCoord);
      std::cout<<"  ";
      yCoord++;
      setCoordinates(18,yCoord);
      std::cout<<">>";
      menuItem++;
      continue;
    }

    // up arrow pressed
    if(GetAsyncKeyState(UP) && yCoord != 7)
    {
      setCoordinates(18,yCoord);
      std::cout<<"  ";
      yCoord--;
      setCoordinates(18,yCoord);
      std::cout<<">>";
      menuItem--;
      continue;
    }

    // enter pressed
    if(GetAsyncKeyState(ENTER))
    {
    	
      // clear screen to pin cursor? or clear screen and just use standard i/o?
      switch(menuItem)
      {
        case SEARCH:
        {
          setCoordinates(20,13);
          std::string searchTxt = "Employee ID:  ";
          std::cout<<searchTxt;
          setCoordinates(20 + searchTxt.length(),13);
          std::string strID;
          std::cin>> strID;
          int iD = std::stoi(strID);
          EmployeeInfo test(" ", iD);
          EmployeeInfo empSearched = empBST.getEntry(test);
          if(empSearched.getID() == -1)
          {
          	std::cout<<"No employee found \n";
		  }
		  else
		  {
		  	std::cout<<"Employee ID: "<< iD<<"\n";
		  	std::cout<<"Name: "<<empSearched.getName() <<"\n";
		  }
          
          break;
        }

        case DISPLAY:
        {
          setCoordinates(20,13);
          std::cout<<"Display Employees  ";
          break;
        }

        case ADD_EMP:
        {
          setCoordinates(20,13);
          std::cout<<"Add new Employee  ";
          break;
        }

        case REMOVE_EMP:
        {
          setCoordinates(20,13);
          std::cout<<"Remove Employee via ID:  ";
          break;
        }
        case EXIT_PROG:
        {
          setCoordinates(20,13);
          std::cout<<"EXITING PROGRAM                         ";
          exit(0);
        }
        default:
        {
          std::cout<<"Error try again.                    ";
          break;
        }
      }
    }
  }
}

// set x and y setCoordinates and output cursor
void setCoordinates(int xPos, int yPos)
{
  CursorPosition.X = xPos;
  CursorPosition.Y = yPos;
  SetConsoleCursorPosition(console, CursorPosition);
}

void plantTree(BinarySearchTree<EmployeeInfo> &tree, std::string fileName)
{
  std::ifstream textFile(fileName);

  if (textFile.is_open())
  {
    std::string txtLine = "";

    while(getline(textFile, txtLine))
    {
      //std::string intRead = getline(textFile, txtLine);
      int empID = std::stoi(txtLine);
      std::string name = "";
	  getline(textFile, name);
      EmployeeInfo employee(name, empID);
      tree.add(employee);
    }

    std::cout<<"Employees loaded from file.";
  }
  else
  {
    std::cout<<"Employees.txt not detected. No employees loaded.";
  }
}
