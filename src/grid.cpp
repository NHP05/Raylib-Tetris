#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}
void Grid::Initialize()
{
    for (int row = 0; row <numRows; row++) \
    {
        for (int col = 0; col <numCols; col++) 
        {
            grid[row][col] = 0; 
        }
    }
}

void Grid::Print() 
{
    for (int row = 0; row < numRows; row++) 
    {
        for (int col = 0; col < numCols; col++) 
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for ( int row = 0; row < numRows; row++) 
    {
        for (int col = 0; col < numCols; col++) 
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize -1, cellSize -1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int col) 
{
    if(row >= 0 && row < numRows && col >= 0 && col < numCols){
        return false; // Cell is inside the grid
    } 
    return true; // Cell is outside the grid
}

bool Grid::IsCellEmpty(int row, int col) 
{
    if (grid[row][col] == 0) {
        return true; // Cell is empty
    } 
    return false; // Cell is not empty
}

bool Grid::IsRowFull(int row) 
{
    for (int col = 0; col < numCols; col++) 
    {
        if (grid[row][col] == 0) {
            return false; // Row is not full
        }
    }
    return true; // Row is full
}

void Grid::ClearRow(int row) 
{
    for (int col = 0; col < numCols; col++) 
    {
        grid[row][col] = 0; // Clear the cell
    }
}

void Grid::ShiftRowsDown(int row, int numRows) 
{
    for (int col = 0; col < numCols; col++) 
    {
        grid[row + numRows][col] = grid[row][col]; // Shift the row down
        grid[row][col] = 0; // Clear the original cell
    }
}

int Grid::ClearFullRows() 
{
    int Completed = 0;
    for (int row = numRows - 1; row >= 0; row--) 
    {
        if (IsRowFull(row)) 
        {
            ClearRow(row); // Clear the full row
            Completed++; // Increment the completed rows count
        } else if (Completed > 0){
            ShiftRowsDown(row, Completed); // Shift the rows down
        }
    }
    return Completed; // Return the number of cleared rows
}