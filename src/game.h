#pragma once
#include "grid.h" 
#include "blocks.cpp"

class Game
{
public:
    Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;
    ~Game();
private:
    Block GetRandomBlock();
    std::vector<Block> GetBlocks(); \
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    void MoveBlockLeft();
    void MoveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    bool BlockFits();
    void LockBlock();
    void Reset();
    void UpdateScore(int linesCleared, int Move); 
};