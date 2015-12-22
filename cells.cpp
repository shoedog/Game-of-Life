/******************************************************************************
 ** Program Filename: cells.cpp 
 ** Author: Wesley Jinks
 ** Date: 1/15/2015
 ** Description: This is the Cells class function implementation file
 ** Input: None
 ** Output: None 
 * ***************************************************************************/
#include "cells.hpp"

/********************************************************************************
*	Function: Cells()
*	Description: Constructor of a cell. Sets neighbors and currentGeneration to 0.
*	Parameters: None
*	Pre-Conditions: None
*	Post-Conditions: Neighbors and currentGeneration are set to 0
* ******************************************************************************/
Cells::Cells()
{
	neighbors = 0;
	currentGeneration = 0;
}

/********************************************************************************
*	Function: countNeighbors( char[ROW][COL], int, int )
*	Description: Counts the number of '0' neighbors for a cell
*	Parameters: A character array of the world. The first int represents a row
*		and the second represents the column of the cell
*	Pre-Conditions: A valid character array must be passed, row and column 
*		variables should be in range of the max and min of the arraye
*	Post-Conditions: neighbors is updated with the count of neighbors for the cell
* ******************************************************************************/
void Cells::countNeighbors( char world[ROW][COL], int rowVar, int colVar )
{
	neighbors = 0; //initialies neighbors to 0

	//Check each cell around the target cell. If a cell is '0', add 1 to neighbors
	if( world[rowVar-1][colVar-1] == '0' )
		neighbors++;
	if( world[rowVar-1][colVar] == '0' )
		neighbors++;
	if( world[rowVar-1][colVar+1] == '0' )
		neighbors++;
	if( world[rowVar][colVar+1] == '0' )
		neighbors++;
	if( world[rowVar][colVar-1] == '0' )
		neighbors++;
	if( world[rowVar+1][colVar-1] == '0' )
		neighbors++;
	if( world[rowVar+1][colVar] == '0' )
		neighbors++;
	if( world[rowVar+1][colVar+1] == '0' )
		neighbors++;
}

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
void Cells::cellDeath( char world[ROW][COL], int rowVar, int colVar )
{
	//If target cell has 0, 1 or greater than 3 neighbors, change target cell to '.'
	if( neighbors == 0 )
		world[rowVar][colVar] = '.';
	else if( neighbors == 1 )
		world[rowVar][colVar] = '.';
	else if( neighbors > 3 )
		world[rowVar][colVar] = '.';			
}

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
void Cells::cellBirth( char world[ROW][COL], int rowVar, int colVar )
{
	if( neighbors == 3 )
		world[rowVar][colVar] = '0';
}


/********************************************************************************
*	Function: advanceGeneration( char[ROW][COL], char[ROW][COL] )
*	Description: Advances the generation of the cells by 1 lifespan
*	Parameters: A character array of the world. The first int represents a row
*		and the second represents a column of the cell.
*	Pre-Conditions: 2 valid character array must be passed
*	Post-Conditions: Based on countNeighbors(), cellDeath(), and cellBirth(),
*		updates an array with the new generation of cells
********************************************************************************/
void Cells::advanceGeneration( char world1[ROW][COL], char world2[ROW][COL] )
{
	//Based on currentGeneration, iterates through array, counting neighbors for
	//	each cell, copying current world to the next world, then implementing
	//	cell birth and cell death on the new world. It then changes the currentGeneration
	if( currentGeneration == 0 )
	{
		for( int i = 0; i < ROW; i++ )
			for( int j = 0; j < COL; j++)
			{
				countNeighbors( world1, i, j );
				world2[i][j] = world1[i][j];
				cellBirth( world2, i, j );
				cellDeath( world2, i, j );			
			}

		currentGeneration = 1;
	}
	else if( currentGeneration == 1 )
	{
		for( int i = 0; i < ROW; i++ )
			for( int j = 0; j < COL; j++)
			{
				countNeighbors( world2, i, j );
				world1[i][j] = world2[i][j];
				cellBirth( world1, i, j );
				cellDeath( world1, i, j );			
			}

		currentGeneration = 0;
	}
	
}

/********************************************************************************
*	Function: trackGenerations( bool )
*	Description: changes the currentGeneration from 1 to 0 or from 0 to 1
*	Parameters: A bool value to track and change currentGeneration
*	Pre-Conditions: a valid bool must be passed
*	Post-Conditions: Changes bool from 0 to 1 or 1 to 0
********************************************************************************/
void Cells::trackGenerations( bool currentGeneration )
{
	if( currentGeneration == 0 )
		currentGeneration = 1;
	else if( currentGeneration == 1)
		currentGeneration = 0;
}

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
void Cells::createLFSO( char world[ROW][COL], int rowVar, int colVar )
{
	world[rowVar-1][colVar] = '0';
	world[rowVar][colVar] = '0';
	world[rowVar+1][colVar] = '0';
}

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
void Cells::createGlider( char world[ROW][COL] , int rowVar, int colVar )
{
	world[rowVar-1][colVar-1] = '0';
	world[rowVar][colVar] = '0';
	world[rowVar][colVar+1] = '0';
	world[rowVar+1][colVar-1] = '0';
	world[rowVar+1][colVar] = '0';
}

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
void Cells::createGliderGun( char world[ROW][COL], int rowVar, int colVar )
{
	world[rowVar][colVar] = '0';
	world[rowVar][colVar-1] = '0';
	world[rowVar-1][colVar-1] = '0';
	world[rowVar+1][colVar-1] = '0';
	world[rowVar+2][colVar-2] = '0';
	world[rowVar-2][colVar-2] = '0';
	world[rowVar][colVar-3] = '0';
	world[rowVar-3][colVar-4] = '0';
	world[rowVar+3][colVar-4] = '0';
	world[rowVar-3][colVar-5] = '0';
	world[rowVar+3][colVar-5] = '0';
	world[rowVar-2][colVar-6] = '0';
	world[rowVar+2][colVar-6] = '0';
	world[rowVar+1][colVar-7] = '0';
	world[rowVar-1][colVar-7] = '0';
	world[rowVar][colVar-7] = '0';
	world[rowVar][colVar-16] = '0';
	world[rowVar-1][colVar-16] = '0';
	world[rowVar][colVar-17] = '0';
	world[rowVar-1][colVar-17] = '0';
	world[rowVar+1][colVar+3] = '0';
	world[rowVar+2][colVar+3] = '0';
	world[rowVar+3][colVar+3] = '0';
	world[rowVar+1][colVar+4] = '0';
	world[rowVar+2][colVar+4] = '0';
	world[rowVar+3][colVar+4] = '0';
	world[rowVar][colVar+5] = '0';
	world[rowVar+4][colVar+5] = '0';
	world[rowVar][colVar+7] = '0';
	world[rowVar-1][colVar+7] = '0';
	world[rowVar+4][colVar+7] = '0';
	world[rowVar+5][colVar+7] = '0';
	world[rowVar+2][colVar+17] = '0';
	world[rowVar+3][colVar+17] = '0';
	world[rowVar+2][colVar+18] = '0';
	world[rowVar+3][colVar+18] = '0';
}
