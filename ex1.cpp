/******************************************************************************
 ** Program Filename: Ex1.cpp 
 ** Author: Wesley Jinks
 ** Date: 1/11/2015
 ** Description: The main file to implement a Game of Life. Has a menu with options
			to input a cell/cells, view world, insert a glider, insert a glider gun, 
			insert a fixed simple oscillator, choose and watch number of generations
			pass, clear the worlf and start over, and exit.
 ** Input: The option in the menu, location to insert life in the world, and number
		of generations to watch pass and options to continue.
 ** Output: The game board, prompts for input, iterations of generations on the board.
 * ***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cctype>
#include "world.hpp"
#include "cells.hpp"

/****************************************************************************************
 * Function: outputWorld( char[ROW][COL] )
 * Description: loops through array, printing a 22 Row and 80 Column array to the screen
 * Parameters: a character array
 * Pre-Conditions: a character array must be passed
 * Post-Conditions: a 22 row and 80 column array is printed to the screen
 * *************************************************************************************/
void outputWorld( char[ROW][COL] );

/****************************************************************************************
 * Function: inputCoords( World & )
 * Description: Prompts for and gets input for row and column coordinatesn
 * Parameters: a world object passed by reference
 * Pre-Conditions: a world object must be passed
 * Post-Conditions: world objects row and column coordinates are updated
****************************************************************************************/
void inputCoords( World & );

/****************************************************************************************
 * Function: passTime( char[ROW][COL], char[ROW][COL], Cells & )
 * Description: Prompts for and gets input for number of generations to pass.
 * Parameters: 2 character arrays to update between generations and a Cells object
 * Pre-Conditions: 2 character arrays must be passed, a Cells object must be passed
 * Post-Conditions: character arrays are updated as generations change
****************************************************************************************/
void passTime( char[ROW][COL], char[ROW][COL], Cells & );

/****************************************************************************************
 * Function: displayMenu()
 * Description: Outputs menu
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: A menu is output to the screen
****************************************************************************************/
void displayMenu();

int main()
{
	World world1;				//Creates a world object
	Cells cell;					//Creates a cell object
	char display1[ROW][COL];   //Creates an array to display a world
	char display2[ROW][COL];   //Creates a second array to display a world
	int option;				  //Menu option variable
	char YN;				  //Yes or No option variable
	
	// Initialize first and second world display arrays, clear screen, and output world
	world1.createWorld( display1 ); 
	world1.createWorld( display2 );
	system("clear");
	outputWorld( display1 );

	/*Displays menu while choice does not equal 8(exit).
	 Case 1: output world. 
	 Case 2: Add cell/cells
	 Case 3: Add fixed simple oscillator
	 Case 4: Add glider
	 Case 5: Add glider gun
	 Case 6: Choose and watch an amount of generations to pass
	 Case 7: Clear world and start over
	 Case 8: Exit     
	*/
	do
	{
		std::cout << std::endl << std::endl << std::endl;
		displayMenu();
		std::cout << std::endl << "Enter your choice from the menu 1-8: ";
		std::cin >> option;
	
		switch(option)
		{
			case 1: 
				outputWorld(display1);
				break;
			case 2:
				outputWorld(display1);
				do
				{
					std::cout << std::endl;
					inputCoords( world1 );
					world1.addLife( display1, world1.getRCoord(), world1.getCCoord() );
					world1.copyWorldState( display1, display2 );
					outputWorld( display1 );
					std::cout << std::endl << "Add another cell (Y/N)? ";
					std::cin >> YN;
					YN = toupper(YN);
				}while( YN == 'Y' );
				break;
			case 3:
				std::cout << std::endl;
				inputCoords( world1 );
				cell.createLFSO( display1, world1.getRCoord(), world1.getCCoord() );
				outputWorld( display1 ); 
				world1.copyWorldState( display1, display2 );
				break;	
			case 4:
				std::cout << std::endl;
				inputCoords( world1 );
				cell.createGlider( display1, world1.getRCoord(), world1.getCCoord() );
				world1.copyWorldState( display1, display2 );
				outputWorld( display1 );
				break;
			case 5:
				std::cout << std::endl;
				inputCoords( world1 );
				cell.createGliderGun( display1, world1.getRCoord(), world1.getCCoord() );
				world1.copyWorldState( display1, display2);
				outputWorld( display1 );
				break;
			case 6:
				if( cell.getCurrentGeneration() == 0 )  
					world1.copyWorldState( display1, display2 );
				else if( cell.getCurrentGeneration() == 1 )
					world1.copyWorldState( display1, display2 );
				passTime( display1, display2, cell );
				break;
			case 7:
				std::cout << std::endl << "World Cleared. " << std::endl;
				world1.createWorld( display1 );
				world1.createWorld( display2 );
				outputWorld( display1 );
				break;
			case 8:
				std::cout << "Exiting..." << std::endl;
				break;
			default:
				std::cout << "You did not enter a valid choice. Enter option 1-8. " << std::endl;
		}

	}while( option != 8 );

	return 0;
}

/****************************************************************************************
 * Function: displayMenu()
 * Description: Outputs menu
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: A menu is output to the screen
****************************************************************************************/
void displayMenu()
{
	std::cout << "********* Welcome to the Game of Life *********" << std::endl;
	std::cout << "*                                             *" << std::endl;
	std::cout << "*      ** Menu **                             *" << std::endl;
	std::cout << "*                                             *" << std::endl;
	std::cout << "* 1: See World                                *" << std::endl;
	std::cout << "* 2: Add Cell/Cells                           *" << std::endl;
	std::cout << "* 3: Add Fixed Simple Oscillator              *" << std::endl;
	std::cout << "* 4: Add Glider                               *" << std::endl;
	std::cout << "* 5: Add Glider Gun                           *" << std::endl;
	std::cout << "* 6: Watch Time Pass                          *" << std::endl;
	std::cout << "* 7: Clear World and Start Over               *" << std::endl;
	std::cout << "* 8: Exit	                              *" << std::endl;
	std::cout << "*	                                      *" << std::endl;
	std::cout << "***********************************************" << std::endl;
}

/****************************************************************************************
 * Function: outputWorld( char[ROW][COL] )
 * Description: loops through array, printing a 22 Row and 80 Column array to the screen
 * Parameters: a character array
 * Pre-Conditions: a character array must be passed
 * Post-Conditions: a 22 row and 80 column array is printed to the screen
 * *************************************************************************************/
void outputWorld( char arr[ROW][COL] )
{
	system("clear");	
	for( int i = 21; i < ROW-23; i++ )
	{
		std::cout << std::endl;
		for( int j = 79; j < COL-81; j++ )
			std::cout << arr[i][j];
	}

}

/****************************************************************************************
 * Function: inputCoords( World & )
 * Description: Prompts for and gets input for row and column coordinatesn
 * Parameters: a world object passed by reference
 * Pre-Conditions: a world object must be passed
 * Post-Conditions: world objects row and column coordinates are updated
****************************************************************************************/
void inputCoords( World &view )
{
	int row;		 //row coordinate
	int col;		 //column coordinate
	bool rowFlag = 1; //Tests to see if coordinates are within range
	bool colFlag = 1; //Tests to see if coordinates are within range

	//Prompt for, get input, and validate input.
	do
	{
		std::cout << "Enter coordinates for a cell. " << std::endl;
		std::cout << "Enter Row Number 1-22: ";
		std::cin >> row;
		std::cout << "Enter Column Number 1-80: ";
		std::cin >> col;

		if( row < 1 || row > 22 )
		{
			rowFlag = 0;
			std::cout << "Row input must be between 1 and 22." << std::endl;
		}
		else
			rowFlag = 1;

		if( col < 1 || col > 80 )
		{
			colFlag = 0;
			std::cout << "Column input must be between 1 and 80." << std::endl;
		}
		else
			colFlag = 1;

	}while( rowFlag == 0 || colFlag == 0 ); 

	//Shifts row and column input to be in visible 22 Row and 80 Column display
	row += 20;
	col += 78;

	view.setRCoord( row );
	view.setCCoord( col );	
}

/****************************************************************************************
 * Function: passTime( char[ROW][COL], char[ROW][COL], Cells & )
 * Description: Prompts for and gets input for number of generations to pass, outputs
 *		the changes in generations to the screen
 * Parameters: 2 character arrays to update between generations and a Cells object
 * Pre-Conditions: 2 character arrays must be passed, a Cells object must be passed
 * Post-Conditions: character arrays are updated as generations change and output to
 *		the screen
****************************************************************************************/
void passTime( char world1[ROW][COL], char world2[ROW][COL], Cells &cell )
{
	char YN;
	int speed;

	/*
	* Prompts for, gets, and validates input for the number of generations and the speed
	*		to watch them pass.
	* Pauses based on user input between each generation. Update world based on cell
	*		newGeneration() function and outputs new world to screen. 
	* Gives option to input and watch more generations
	*/
	do
	{
		int generations = 0;
		
		std::cout << "How many generations would you like to pass? ";
		std::cin >> generations;

		while( generations <= 0 )
		{
			std::cout << "The number of generations must be a positive integer. "
					  << std::endl;
			std::cout << "How many generations would you like to pass? ";
			std::cin >> generations;
		}

		std::cout << std::endl;
		std::cout << "How fast would you like to see them change? Enter 1 for slow, "
				  << "2 for medium, and 3 for fast: ";
		std::cin >> speed;
		std::cout << std::endl;

		while( speed < 1 || speed > 3 )
		{
			std::cout << "Speed can only be slow, medium, or fast. Enter 1 for slow, "
					  << "2 for medium, or 3 for fast. " << std::endl << "Enter speed:  ";
			std::cin >> speed;
		} 
	
		for( int i = 0; i < generations; i++ )
		{
			if( speed == 1 )
				usleep(100000);
			else if( speed == 2 )
				usleep(70000);
			else if( speed == 3 )
				usleep(40000);

			cell.advanceGeneration( world1, world2 );
		//	cell.newGeneration( world1, world2 );
			if( cell.getCurrentGeneration() == 1 )  
			{
				outputWorld( world2 );
			//	std::cout << "World2";  //Test for which array is output
			}
			else if( cell.getCurrentGeneration() == 0 )
			{
				outputWorld( world1 );
			//	std::cout << "World1";   //Test for which array is output
			}
		//	std::cout << cell.getWorldCheck(); //Test to see if worlds are switchin
			std::cout << std::endl;
		}

		std::cout << std::endl << "Would you like to see more generations (Y/N)? ";
		std::cin >> YN;
		YN = toupper( YN );
	}while( YN != 'N' ); 
}

	

