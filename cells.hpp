/******************************************************************************
 ** Program Filename: cells.hpp 
 ** Author: Wesley Jinks
 ** Date: 1/15/2015
 ** Description: This is the header file for the cell class. It contains the 
		variables and functions for cells. The functions include checking for
		neighboring live cells, cell death, cell birth, creating a fixed simple
		oscillator, creating a glider, creating a glider gun, advancing the cells
		generation, keeping track of time for the generations, getting and setting
		cell neighbors, and getting the current generation 
 ** Input: None
 ** Output: None
 * ***************************************************************************/
#ifndef CELLS_HPP
#define CELLS_HPP
#include "world.hpp"

class World; //Cell class inherits from World class

class Cells
{
	private:
		int neighbors; //Count of the number of live: '0' neighbors a cell has
		bool currentGeneration; //Tracks generation by switching from 0 to 1...
		
	public:
		
		/********************************************************************************
		*	Function: Cells()
		*	Description: Constructor of a cell. Sets neighbors and currentGeneration to 0.
		*	Parameters: None
		*	Pre-Conditions: None
		*	Post-Conditions: Neighbors and currentGeneration are set to 0
		* ******************************************************************************/
		Cells();

		/********************************************************************************
		*	Function: countNeighbors( char[ROW][COL], int, int )
		*	Description: Counts the number of '0' neighbors for a cell
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents the column of the cell
		*	Pre-Conditions: A valid character array must be passed, row and column 
		*		variables should be in range of the max and min of the arraye
		*	Post-Conditions: neighbors is updated with the count of neighbors for the cell
		* ******************************************************************************/
		void countNeighbors( char [ROW][COL], int , int );
		
		/********************************************************************************
		*	Function: cellDeath( char[ROW][COL], int, int )
		*	Description: Changes a live cell '0' to a dead/empty cell: '.' based on the
		*		number of neighbors. 0, 1, or greater than 3 neighbors turns a living cell
		*	    to a dead cell.
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents a column of the cell.
		*	Pre-Conditions: A valid character array must be passed. row and column 
		*		variables should be within the min and max values of the array
		*	Post-Conditions: at the point determined by the row and column, the cell is
		*		changed from '0' to '.' based on the number of neighbors
		* ******************************************************************************/
		void cellDeath( char [ROW][COL], int, int );
		
		/********************************************************************************
		*	Function: cellBirth( char[ROW][COL], int, int )
		*	Description: Changes a dead/empty cell '.' to a live cell: '0' based on the
		*		number of neighbors. 3 neighbors turns a dead cell to a living cell.
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents a column of the cell.
		*	Pre-Conditions: A valid character array must be passed. row and column 
		*		variables should be within the min and max values of the array
		*	Post-Conditions: at the point determined by the row and column, the cell is
		*		changed from '.' to '0' based on the number of neighbors
		********************************************************************************/
		void cellBirth( char [ROW][COL], int, int );
		
		/********************************************************************************
		*	Function: createLFSO( char[ROW][COL], int, int )
		*	Description: Creates a fixed simple oscillator with a a middle point
		*		determined by row and column variables
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents a column of the cell.
		*	Pre-Conditions: A valid character array must be passed. row and column 
		*		variables should be within the min and max values of the array
		*	Post-Conditions: With the center point determined by the row and column,
		*		the fixed simple oscillator is created in the array
		********************************************************************************/
		void createLFSO( char [ROW][COL], int, int );
		
		/********************************************************************************
		*	Function: createGlider( char[ROW][COL], int, int )
		*	Description: Creates a glider that goes down and to the right with a middle
		*		 point determined by row and column variables
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents a column of the cell.
		*	Pre-Conditions: A valid character array must be passed, row and column 
		*		variables should be within the min and max values of the array
		*	Post-Conditions: With the center point determined by the row and column,
		*		the glider is created in the array
		********************************************************************************/
		void createGlider( char[ROW][COL], int, int );
		
		/********************************************************************************
		*	Function: createGliderGun( char[ROW][COL], int, int )
		*	Description: Creates a glider gun that sends gliders up and right with a
		*		 middle point determined by row and column variables
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents a column of the cell.
		*	Pre-Conditions: A valid character array must be passed, row and column 
		*		variables should be within the min and max values of the array
		*	Post-Conditions: With the center point determined by the row and column,
		*		the glider gun is created in the array
		********************************************************************************/
		void createGliderGun( char[ROW][COL], int, int );
		
		/********************************************************************************
		*	Function: advanceGeneration( char[ROW][COL], char[ROW][COL] )
		*	Description: Advances the generation of the cells by 1 lifespan
		*	Parameters: A character array of the world. The first int represents a row
		*		and the second represents a column of the cell.
		*	Pre-Conditions: 2 valid character array must be passed
		*	Post-Conditions: Based on countNeighbors(), cellDeath(), and cellBirth(),
		*		updates an array with the new generation of cells
		********************************************************************************/
		void advanceGeneration( char[ROW][COL], char [ROW][COL] );
		
		/********************************************************************************
		*	Function: trackGenerations( bool )
		*	Description: changes the currentGeneration from 1 to 0 or from 0 to 1
		*	Parameters: A bool value to track and change currentGeneration
		*	Pre-Conditions: a valid bool must be passed
		*	Post-Conditions: Changes bool from 0 to 1 or 1 to 0
		********************************************************************************/
		void trackGenerations( bool );

		/********************************************************************************
		*	Function: getNeighbors()
		*	Description: returns count of neighbors
		*	Parameters: None
		*	Pre-Conditions: neighbors variable must be initialized
		*	Post-Conditions: returns integer with value of neighbors
		********************************************************************************/
		int getNeighbors()
		{ return neighbors; }
		
		/********************************************************************************
		*	Function: setNeighbors( int )
		*	Description: sets count of neighbors
		*	Parameters: int representing a count
		*	Pre-Conditions: count should be within min(0) and max(8) range of neighbors
		*		for a cell
		*	Post-Conditions: neighbors is set to count
		********************************************************************************/
		void setNeighbors( int count )
		{ neighbors = count; }
		
		/********************************************************************************
		*	Function: getCurrentGeneration()
		*	Description: returns the currentGeneration: 0 or 1
		*	Parameters: None
		*	Pre-Conditions: currentGenerations variable must be initialized
		*	Post-Conditions: returns bool of currentGeneration
		********************************************************************************/
		bool getCurrentGeneration()
		{ return currentGeneration; }
};

#endif
