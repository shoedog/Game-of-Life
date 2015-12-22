/******************************************************************************
 ** Program Filename: world.cpp 
 ** Author: Wesley Jinks
 ** Date: 1/11/2015
 ** Description: This is the World implementation file
 ** Input: None
 ** Output: 
 * ***************************************************************************/
#include "world.hpp"

/********************************************************************************
*	Function: World()
*	Description: Constructor of world object, initializes array with '.'
*	Parameters: None
*	Pre-Conditions: None
*	Post-Conditions: Initializes array value to '.'
* ******************************************************************************/
World::World()
{
	for(int i = 0; i < ROW; i++)
	{
		for( int j = 0; j < COL; j++ )
			world[i][j] = '.';
	}
}


/********************************************************************************
*	Function: createWorld( char[ROW][COL] )
*	Description: Sets array values to '.'
*	Parameters: character array
*	Pre-Conditions: The array passed must be a valid character array with row
*		and column set according to the defined constant
*	Post-Conditions: The array is updated to have values of '.' in each position
* ***************************************************************************/
void World::createWorld( char world[ROW][COL] )
{
	for(int i = 0; i < ROW; i++)
	{
		for( int j = 0; j < COL; j++ )
			world[i][j] = '.';
	}
}

/********************************************************************************
*	Function: copyWorldState( char[ROW][COL], char[ROW][COL] )
*	Description: Copies world of one array to another'
*	Parameters: 2 character arrays. The first being the one copied. The second 
*		one holding the values that were in the first
*	Pre-Conditions: 2 valid character arrays must be passed, they should have the
*		same size
*	Post-Conditions: the second array holds the same values as the first
* ******************************************************************************/
void World::copyWorldState( char world1[ROW][COL], char world2[ROW][COL] )
{
	for( int i = 0; i < ROW; i++ )
	{
		for( int j = 0; j < COL; j++ )
			world2[i][j] = world1[i][j];
	}
}

/********************************************************************************
*	Function: addLife( char[ROW][COL], int, int )
*	Description: adds a '0' at a point to represent a cell.
*	Parameters: character array, 2 ints representing first a row coordinate,
*		 and a then a column coordinate
*	Pre-Conditions: a valid character array must be passed, the ints must be
*		bound by the maximum and minimum values of the array 
*	Post-Conditions: Adds a '0' to array at point determined by coordinates 
* ***************************************************************************/
void World::addLife( char world[ROW][COL], int rCoord, int cCoord )
{
	world[rCoord][cCoord] = '0';
}


