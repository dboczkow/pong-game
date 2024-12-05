#include <raylib.h>
#include <iostream>

int main() {

  // Definiowanie szerokoœci i wyskoœci okna gry
    const int screenWidth{ 800 };
    const int screenHeight{ 450 };
    const std::string windowName{ "Pong" };

  // Inicjalizowanie okna gry z podanym tytu³em
    InitWindow(screenWidth, screenHeight, windowName.c_str());

  // Lewa paletka
    Rectangle leftPaddle{ 50, screenHeight / 2 - 60, 10, 100 };

  // Prawa paletka
    Rectangle rightPaddle{ screenWidth - 60, screenHeight / 2 - 60, 10, 100 };

  // Prêdkoœæ paletek
    int leftPaddleSpeed{ 5 };
    int rightPaddleSpeed{ 5 };


  // Ustawenia pi³ki
    Vector2 ballPosition{ screenWidth / 2, screenHeight / 2 }; // pozycja pocz¹tkowa
    Vector2 ballSpeed{ 4.0f, 4.0f }; // prêdkoœæ pi³ki
    float ballRadius{ 10.0f }; // promieñ pi³ki

    // Iloœæ klatek na sekundê
    SetTargetFPS(60);

  // Pêtla g³owna gry
  while (!WindowShouldClose()) {

    // Obs³uga ruchu lewej paletki góra/dó³
    if (IsKeyDown(KEY_W) && leftPaddle.y > 0) {
        leftPaddle.y -= leftPaddleSpeed;
    }
    if (IsKeyDown(KEY_S) && leftPaddle.y + leftPaddle.height < screenHeight) {
        leftPaddle.y += leftPaddleSpeed;
    }

    // Obs³uga ruchu prawej paletki góra/dó³
    if (IsKeyDown(KEY_UP) && rightPaddle.y > 0) {
        rightPaddle.y -= rightPaddleSpeed;
    }
    if (IsKeyDown(KEY_DOWN) && rightPaddle.y + rightPaddle.height < screenHeight) {
        rightPaddle.y += rightPaddleSpeed;
    }

    // Ruch pi³k, aktualizacja na podstawie prêdkoœci
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


    // Sprz¹tanie, zamykanie okna i zwalaniane zasbów
    CloseWindow();
    std::cout << "Game over\n";
  
}