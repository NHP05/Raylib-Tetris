#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdatetime = 0;

bool EventTriggered(double interval) {
    double time = GetTime();
    if (time - lastUpdatetime >= interval) {
        lastUpdatetime = time;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while(WindowShouldClose() == false) 
    {   
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.335)) {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", { 355, 15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 365, 175 }, 38, 2, WHITE);
        if (game.gameOver) {
            DrawTextEx(font, "Ngu", { 375, 450 }, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60},0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);


        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x)/2, 65 }, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180},0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();

    }
    CloseWindow();

}