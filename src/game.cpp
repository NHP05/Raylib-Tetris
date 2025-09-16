#include "game.h"
#include <random>

Game::Game() {
    grid = Grid();
    blocks = GetBlocks(); // Initialize the blocks
    currentBlock = GetRandomBlock(); // Get a random block
    nextBlock = GetRandomBlock(); // Get the next random block
    gameOver = false; // Initialize game over state
    score = 0; // Initialize score
    InitAudioDevice(); // Initialize audio device
    music = LoadMusicStream("Sounds/Tetris.mp3"); // Load music
    PlayMusicStream(music); // Play music
}

Game::~Game()
{
    UnloadMusicStream(music); // Unload music
    CloseAudioDevice(); // Close audio device
    // Add any other cleanup code if necessary
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetBlocks(); // Reset the blocks if empty
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetBlocks() {
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
    grid.Draw(); // Draw the grid
    currentBlock.Draw(11, 11); // Draw the current block
    switch(nextBlock.id){
        case1:
            nextBlock.Draw(270, 270); // Draw the next block
            break;
        case 2:
            nextBlock.Draw(280, 270); // Draw the next block
            break;
        case 3:
            nextBlock.Draw(260, 290); // Draw the next block
            break;
        case 4:
            nextBlock.Draw(260, 270); // Draw the next block
            break;
        case 5:
            nextBlock.Draw(270, 270); // Draw the next block
            break; 
        case 6:
            nextBlock.Draw(245, 270); // Draw the next block
            break;
        default:
            nextBlock.Draw(270, 270); // Draw the next block
            break; 
    }
}

void Game::HandleInput() {
    int key = GetKeyPressed();
    if(gameOver && key != 0){
        gameOver = false; // Reset game over state
        Reset(); // Reset the game
    }
    switch (key) // Replace with actual key handling logic
    {
        case KEY_LEFT:
            MoveBlockLeft(); // Move block left
            break;
        case KEY_RIGHT:
            MoveBlockRight(); // Move block right
            break;
        case KEY_DOWN:
            MoveBlockDown(); // Move block down
            UpdateScore(0, 1); // Update score for move down
            break;
        case KEY_UP:
            RotateBlock(); // Rotate block 
            break;
    }
}

void Game::MoveBlockLeft() {
    if (!gameOver) {
        currentBlock.Move(0, -1); // Move the block left
        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(0, 1); // Move back if outside
        }
    }
}

void Game::MoveBlockRight() {
    if (!gameOver) {
        currentBlock.Move(0, 1); // Move the block right
        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(0, -1); // Move back if outside
        }
    }
}

void Game::MoveBlockDown() {
    if (!gameOver){
        currentBlock.Move(1, 0); // Move the block down
        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(-1, 0); // Move back if outside
            // Add logic to lock the block in place and generate a new block
            LockBlock(); // Lock the block in place
        }
    }
}


bool Game::IsBlockOutside() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        if (grid.IsCellOutside(item.row, item.col)) {
            return true; // Block is outside the grid
        }
    }
    return false; // Block is inside the grid
}

void Game::RotateBlock() {
    if (!gameOver){
        currentBlock.Rotate(); // Rotate the block
        if (IsBlockOutside() || BlockFits() == false) {
            currentBlock.UndoRotate(); // Move back if outside
        }
    }
}

void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        grid.grid[item.row][item.col] = currentBlock.id; // Lock the block in the grid
    }
    currentBlock = nextBlock; // Set the next block as the current block
    if (BlockFits() == false) {
        // Game over logic here
        gameOver = true; // Set game over state
    }
    nextBlock = GetRandomBlock(); // Get a new random block
    int rowsCleared = grid.ClearFullRows(); // Clear full rows in the grid
    UpdateScore(rowsCleared, 0); // Update score based on cleared rows
}

bool Game::BlockFits() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        if (grid.IsCellEmpty(item.row, item.col) == false) {
            return false; // Block does not fit in the grid
        }
    }
    return true; // Block fits in the grid
}

void Game::Reset() {
    grid.Initialize(); // Initialize the grid
    blocks = GetBlocks(); // Reset the blocks
    currentBlock = GetRandomBlock(); // Get a random block
    nextBlock = GetRandomBlock(); // Get the next random block
    score = 0; // Reset score
}

void Game::UpdateScore(int linesCleared, int Move) {
    switch (linesCleared) {
        case 1:
            score += 100; // Increment score for 1 line cleared
            break;
        case 2:
            score += 300; // Increment score for 2 lines cleared
            break;
        case 3:
            score += 500; // Increment score for 3 lines cleared
            break;
        case 4:
            score += 800; // Increment score for 4 lines cleared
            break;
        default:
            break; // No score increment for other cases
    }
    score += Move * 10; // Increment score for moves
}