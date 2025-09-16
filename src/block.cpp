#include "block.h"

Block::Block(){
    cellSize = 30;
    rotation = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(int offsetX, int offsetY) {
     std::vector<Position> tiles = GetCellPositions();
     for (Position item : tiles) {
        int row = item.row;
        int col = item.col;
        DrawRectangle(col * cellSize + offsetX, row * cellSize + offsetY, cellSize -1, cellSize -1, colors[id]);
     }
}

void Block::Move(int rows, int cols) {
    rowOffset += rows;
    colOffset += cols;
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = cells[rotation];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPos = Position(item.row + rowOffset, item.col + colOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate() {
    rotation ++;
    if (rotation == (int)cells.size()) {
        rotation = 0;
    }
}
void Block::UndoRotate() {
    rotation --;
    if (rotation == -1) {
        rotation = cells.size() - 1;
    }
}