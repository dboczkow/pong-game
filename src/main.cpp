#include <raylib.h>
#include <iostream>

int main() {

  // Definiowanie szeroko�ci i wysko�ci okna gry
    const int screenWidth{ 800 };
    const int screenHeight{ 450 };
    const std::string windowName{ "Pong" };

  // Inicjalizowanie okna gry z podanym tytu�em
    InitWindow(screenWidth, screenHeight, windowName.c_str());

  // Lewa paletka
    Rectangle leftPaddle{ 50, screenHeight / 2 - 60, 10, 100 };

  // Prawa paletka
    Rectangle rightPaddle{ screenWidth - 60, screenHeight / 2 - 60, 10, 100 };

  // Pr�dko�� paletek
    int leftPaddleSpeed{ 5 };
    int rightPaddleSpeed{ 5 };


  // Ustawenia pi�ki
    Vector2 ballPosition{ screenWidth / 2, screenHeight / 2 }; // pozycja pocz�tkowa
    Vector2 ballSpeed{ 4.0f, 4.0f }; // pr�dko�� pi�ki
    float ballRadius{ 10.0f }; // promie� pi�ki

    // Ilo�� klatek na sekund�
    SetTargetFPS(60);

  // P�tla g�owna gry
  while (!WindowShouldClose()) {

    // Obs�uga ruchu lewej paletki g�ra/d�
    if (IsKeyDown(KEY_W) && leftPaddle.y > 0) {
        leftPaddle.y -= leftPaddleSpeed;
    }
    if (IsKeyDown(KEY_S) && leftPaddle.y + leftPaddle.height < screenHeight) {
        leftPaddle.y += leftPaddleSpeed;
    }

    // Obs�uga ruchu prawej paletki g�ra/d�
    if (IsKeyDown(KEY_UP) && rightPaddle.y > 0) {
        rightPaddle.y -= rightPaddleSpeed;
    }
    if (IsKeyDown(KEY_DOWN) && rightPaddle.y + rightPaddle.height < screenHeight) {
        rightPaddle.y += rightPaddleSpeed;
    }

    // Ruch pi�k, aktualizacja na podstawie pr�dko�ci
    ballPosition.x += ballSpeed.x;
    ballPosition.y += ballSpeed.y;

    if (ballPosition.y <= 0 || ballPosition.y >= screenHeight) {
        ballSpeed.y *= -1;
    }

    if (CheckCollisionCircleRec(ballPosition, ballRadius, leftPaddle) || 
        CheckCollisionCircleRec(ballPosition, ballRadius, rightPaddle)) {
        ballSpeed.x *= -1;
    }


    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleRec(leftPaddle, WHITE);
    DrawRectangleRec(rightPaddle, WHITE);
    DrawCircleV(ballPosition, ballRadius, WHITE);
    DrawText(windowName.c_str(), screenWidth / 2 - windowName.size(), 20, 20, WHITE);
    EndDrawing();
  }


    // Sprz�tanie, zamykanie okna i zwalaniane zasb�w
    CloseWindow();
    std::cout << "Game over\n";
  
}