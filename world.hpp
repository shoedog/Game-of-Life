/******************************************************************************
 ** Program Filename: world.hpp 
 ** Author: Wesley Jinks
 ** Date: 1/11/2015
 ** Description: This is the world class header file. It displays a visible
			world of 80 X 22 cells of an "infinite" world. It has functions
			to create a world, add life to the world, initialize a world state,
			and to set and return coordinates for a point in the world. 
 ** Input: None 
 ** Output: None
 * ***************************************************************************/
#ifndef WORLD_HPP
#define WORLD_HPP

#define ROW 66      //Set Row size for use in arrays
#define COL 240   //Set Column size for use in arrays

//World Class Declaration
class World
{
	private:		
		char world[ROW][COL];  //Array to hold the world of cells
		int rCoord;		       //Row coordinate
		int cCoord;			   //Column coordinate
	
	public:	
		/********************************************************************************
		*	Function: World()
		*	Description: Constructor of world object, initializes array with '.'
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: None
		* ******************************************************************************/
		World();	

		/********************************************************************************
		*	Function: createWorld( char[ROW][COL] )
		*	Description: Sets array values to '.'
		*	Parameters: character array
		*	Pre-Conditions: The array passed must be a valid character array with row
		*		and column set according to the defined constant
		*	Post-Conditions: The array is updated to have values of '.' in each position
		* ******************************************************************************/
		void createWorld( char[ROW][COL] );

		/********************************************************************************
		*	Function: addLife( char[ROW][COL], int, int )
		*	Description: adds a '0' at a point to represent a cell.
		*	Parameters: character array, 2 ints representing first a row coordinate,
		*		 and a then a column coordinate
		*	Pre-Conditions: a valid character array must be passed, the ints must be
		*		bound by the maximum and minimum values of the array 
		*	Post-Conditions: the array is updated to represent the position of the
		*		row and column variables with a '0'
		* ******************************************************************************/
		void addLife( char[ROW][COL], int, int );
		
		/********************************************************************************
		*	Function: copyWorldState( char[ROW][COL], char[ROW][COL] )
		*	Description: Copies world of one array to another'
		*	Parameters: 2 character arrays. The first being the one copied. The second 
		*		one holding the values that were in the first
		*	Pre-Conditions: 2 valid character arrays must be passed, they should have the
		*		same size
		*	Post-Conditions: the second array holds the same values as the first
		* ******************************************************************************/
		void copyWorldState( char[ROW][COL], char[ROW][COL] );
		
		/********************************************************************************
		*	Function: getRCoord()
		*	Description: Returns the coordinate of the row point
		*	Parameters: None
		*	Pre-Conditions: row coordinate must be initialized
		*	Post-Conditions: returns the location of the row coordinate
		* ******************************************************************************/
		int getRCoord()
		{ return rCoord; }
		
		/********************************************************************************
		*	Function: getCCoord()
		*	Description: Returns the coordinate of the Column point
		*	Parameters: None
		*	Pre-Conditions: Column coordinate must be initialized
		*	Post-Conditions: returns the location of the column coordinate
		* ******************************************************************************/
		int getCCoord()
		{ return cCoord; }
		
		/********************************************************************************
		*	Function: setRCoord( int row )
		*	Description: Set the value of the row point
		*	Parameters: int representing a row location
		*	Pre-Conditions: Int passed must be in the min and max range of the ROW values 
		*	Post-Conditions: Sets the rCoord to the int row value passed
		* ******************************************************************************/
		void setRCoord( int row )
		{ rCoord = row; }
		
		/********************************************************************************
		*	Function: setCCoord( int col )
		*	Description: Set the value of the column point
		*	Parameters: int representing a column location
		*	Pre-Conditions: Int passed must be in the min and max range of the COL values 
		*	Post-Conditions: Sets the cCoord to the int row value passed
		* ******************************************************************************/
		void setCCoord( int col )
		{ cCoord = col; }
};
#endif
