#pragma once
#include <vector>
#include <raylib.h>
class Grid 
{
public:
    Grid();
    void Initialize();
    int grid[20][10];
    void Print();
    void Draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int  ClearFullRows();

private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void ShiftRowsDown(int row, int numRows);
};