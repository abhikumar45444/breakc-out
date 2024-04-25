// #include "raylib.h"
// #include "../include/raymath.h"
// #include <iostream>
// #include <math.h>

// using namespace std;

// // const int WIDTH{1920};
// // const int HEIGHT{1080};
// int WIDTH{1500};
// int HEIGHT{700};
// // int WIDTH{400};
// // int HEIGHT{400};

// float rectWidth = 20;
// float rectHeight = 20;
// float rectPosX = WIDTH/2 - rectWidth/2;
// float rectPosY = HEIGHT/2 - rectHeight/2;
// float rectSpeedX = 50.0f;
// float rectSpeedY = 50.0f;
// int i = 10;

// int main()
// {
//     InitWindow(WIDTH, HEIGHT, "Accelaration Testing");
//     // int rectWidth = 100;
//     // int rectHeight = 100;

    
//     SetTargetFPS(60);

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(BLACK);

//         float angleInDegrees = PI/4.0f;
//         if(IsKeyDown(KEY_SPACE))
//         {
//             rectPosX += rectSpeedX * GetFrameTime() * cosf(angleInDegrees);
//             rectPosY += rectSpeedY * GetFrameTime() * -sinf(angleInDegrees);
//         }

//         if(IsKeyPressed(KEY_R))
//         {
//             rectPosX = WIDTH/2 - rectWidth/2;
//             rectPosY = HEIGHT/2 - rectHeight/2;
//         }

//         cout << sinf(angleInDegrees) << " " << cosf(angleInDegrees) << endl;
//         // cout << asinhf(90) << " " << acoshf(90) << endl;

//         DrawRectangle(rectPosX, rectPosY, rectWidth, rectHeight, RED);
//         DrawLine(rectPosX, rectPosY+20, rectPosX, -HEIGHT, WHITE);
//         DrawLine(rectPosX, rectPosY+20, WIDTH, rectPosY+20, WHITE);
//         // DrawLine(rectPosX, rectPosY+20, WIDTH, rectPosY+20, WHITE);
//         DrawLineV({rectPosX, rectPosY+20}, {rectPosX+100*cosf(angleInDegrees), rectPosY+100 * -sinf(angleInDegrees)}, GREEN);
//         // i += 10;
//         DrawFPS(0, 0);
//         EndDrawing();
//     }
//     CloseWindow();

//     return 0;
// }





// #include "raylib.h"
// #include "../include/raymath.h"
// #include <iostream>
// #include <math.h>

// using namespace std;

// // const int WIDTH{1920};
// // const int HEIGHT{1080};
// int WIDTH{1200};
// int HEIGHT{700};
// // int WIDTH{400};
// // int HEIGHT{400};

// float paddleWidth = 100.0f;
// float paddleHeight = 100.0f;
// float paddlePosX = WIDTH/2 - paddleWidth/2;
// float paddlePosY = (HEIGHT - 100) - paddleHeight/2;
// float paddleSpeed = 400.0f;
// float paddleSpeedX = paddleSpeed;
// float paddleSpeedY = paddleSpeed;
// float paddle_dx = 0.0f;
// float paddle_dy = 0.0f;
// float isCollidedHorizontally = false;
// float ballcurrentTime = 0.0f;
// float ballelapsedTime = 0.0f;
// float balldelayTime = 2.0f;
// bool resetSpeed = false;

// float ballWidth = 20;
// float ballHeight = 20;
// // float ballPosX = WIDTH/2 - ballWidth/2;
// // float ballPosY = HEIGHT/2 - ballHeight/2;
// float ballPosX = paddlePosX + paddleWidth * 0.5f - ballWidth * 0.5f;
// float ballPosY = paddlePosY - paddleHeight * 0.5f - ballHeight * 0.5f - 2.0f;
// float ballSpeed = -200.0f;
// float ballSpeedX = ballSpeed;
// float ballSpeedY = ballSpeed;
// float ball_dx = 1.0f;
// float ball_dy = 1.0f;


// bool checkIntersection(const Rectangle& rect1, const Rectangle& rect2) {
//     // Calculate the sides of each rectangle
//     float left1 = rect1.x;
//     float right1 = rect1.x + rect1.width;
//     float top1 = rect1.y;
//     float bottom1 = rect1.y + rect1.height;

//     float left2 = rect2.x;
//     float right2 = rect2.x + rect2.width;
//     float top2 = rect2.y;
//     float bottom2 = rect2.y + rect2.height;

//     // Check for intersection along both axes
//     // bool intersectX = (left1 < right2) && (right1 > left2);
//     // bool intersectY = (top1 < bottom2) && (bottom1 > top2);
//     bool intersectX = !((right1 < left2) || (right2 < left1));
//     bool intersectY = !((bottom1 < top2) || (bottom2 < top1));

//     // If both axes have intersection, then there is overall intersection
//     return intersectX && intersectY;
// }


// void DrawPaddle()
// {
//     DrawRectangle(paddlePosX, paddlePosY, paddleWidth, paddleHeight, RED);
// }

// void DrawBall()
// {
//     DrawRectangle(ballPosX, ballPosY, ballWidth, ballHeight, YELLOW);
// }

// void userInput()
// {

//     if (IsKeyDown(KEY_LEFT) /* && paddlePosX > 0 */)
//     {
//         // paddle_dx += -1.0f;
//         paddleSpeed = -1.0f;
//         paddleSpeedX += -1.0f;
//         paddlePosX -= paddleSpeedX * GetFrameTime();
//     }

//     if (IsKeyDown(KEY_RIGHT) /* && paddlePosX < WIDTH - paddleWidth */)
//     {
//         // paddle_dx += 1.0f;
//         // paddleSpeedX = -paddleSpeedX;
//         paddleSpeed = 1.0f;
//         paddleSpeedX += 1.0f;
//         paddlePosX += paddleSpeedX * GetFrameTime();
//     }

//     // cout << paddleSpeedX << endl;

//     paddlePosX = Clamp(paddlePosX, 0.0f, paddlePosX+paddleWidth);
//     paddlePosX = Clamp(paddlePosX, paddlePosX-paddleWidth, (float)WIDTH-paddleWidth);

// }

// void UpdatePaddle()
// {
//     // paddlePosX = paddlePosX + paddle_dx * paddleSpeed * GetFrameTime();

//     // paddle_dx = 0.0f;
//     // paddlePosX = Clamp(paddlePosX, 0.0f, paddlePosX+paddleWidth);
//     // paddlePosX = Clamp(paddlePosX, paddlePosX-paddleWidth, (float)WIDTH-paddleWidth);
// }

// void UpdateBall()
// {
//     // float newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     float newballPosX = ballPosX + ballSpeedX * GetFrameTime();
//     if(ballPosX < 0 || ballPosX + ballWidth > WIDTH)
//     {
//         // ball_dx *= -1.0f;
//         // newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//         ballSpeedX = -ballSpeedX;
//         newballPosX = ballPosX + ballSpeedX * GetFrameTime();
//     }

//     // float newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     float newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     if(ballPosY < 0 || ballPosY + ballHeight > HEIGHT)
//     {
//         // ball_dy *= -1.0f;
//         // newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//         ballSpeedY = -ballSpeedY;
//         newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     }

//     ballPosX = newballPosX;
//     ballPosY = newballPosY;
//     // if(isCollidedHorizontally/*  && resetSpeed */){
//     //     ballcurrentTime = ballcurrentTime + ballelapsedTime;
//     //     if (ballcurrentTime >= balldelayTime)
//     //     {
//     //         ballSpeedX = ballSpeedX / 1.55f;
//     //         ballcurrentTime = 0.0f;
//     //         resetSpeed = true;
//     //     }
//     //     if(resetSpeed)
//     //     {
//     //         isCollidedHorizontally = false;
//     //         resetSpeed = false;
//     //     }
//     // }

//         //  newballPosX = ballPosX + ballSpeedX * GetFrameTime();
//     // if(ballPosX < paddlePosX + paddleWidth || ballPosX + ballWidth > paddlePosX)
//     // {
//     //     // ball_dx *= -1.0f;
//     //     // newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     //     ballSpeedX = -ballSpeedX;
//     //     newballPosX = ballPosX + ballSpeedX * GetFrameTime();
//     // }

//     // // float newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     //  newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     // if(ballPosY < paddlePosY + paddleHeight || ballPosY + ballHeight > paddlePosY)
//     // {
//     //     // ball_dy *= -1.0f;
//     //     // newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     //     ballSpeedY = -ballSpeedY;
//     //     newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     // }


//     // if((ballPosX + ballWidth >= paddlePosX &&
//     //     ballPosX <= paddlePosX + paddleWidth &&
//     //     ballPosY + ballHeight >= paddlePosY &&
//     //     ballPosY <= paddlePosY + paddleHeight))
//     // {
//     //     // if(!(ballPosX + ballWidth < paddlePosX ||
//     //     // paddlePosX + paddleWidth < ballPosX))
//     //     // {
//     //         // cout << "hi" << endl;
//     //         ball_dx *= -1.0f;
//     //         newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     //         // return;
//     //     // }
//     // }

//     // if((ballPosX + ballWidth >= paddlePosX &&
//     //     ballPosX <= paddlePosX + paddleWidth &&
//     //     ballPosY + ballHeight >= paddlePosY &&
//     //     ballPosY <= paddlePosY + paddleHeight))
//     // {
//     //     // if(!(ballPosY + ballHeight < paddlePosY ||
//     //     // paddlePosY + paddleHeight < ballPosY))
//     //     // {
//     //         // cout << "hello" << endl;
//     //         ball_dy *= -1.0f;
//     //         newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     //         // return;
//     //     // }
//     // }




//     // Rectangle rect1, rect2;
//     // rect1.x = newballPosX;
//     // rect1.y = newballPosY;
//     // rect1.width = ballWidth;
//     // rect1.height = ballHeight;

//     // rect2.x = paddlePosX;
//     // rect2.y = paddlePosY;
//     // rect2.width = paddleWidth;
//     // rect2.height = paddleHeight;


//     // newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     // rect1.x = newballPosX;
//     // if(/* ((newballPosX + ballWidth >= paddlePosX &&
//     //    newballPosX <= paddlePosX + paddleWidth) &&
//     //    (newballPosY + ballHeight >= paddlePosY &&
//     //    newballPosY <= paddlePosY + paddleHeight)) && */ checkIntersection(rect1,rect2) && ((ballPosX + ballWidth >= paddlePosX) || (ballPosX <= paddlePosX + paddleWidth)))
//     // {
//     //     ball_dx *= -1.0f;
//     //     newballPosX = newballPosX + ball_dx * ballSpeed * GetFrameTime();
//     // }

//     // newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     // rect1.y = newballPosY;
//     // if(/* ((newballPosX + ballWidth >= paddlePosX &&
//     //    newballPosX <= paddlePosX + paddleWidth) &&
//     //    (newballPosY + ballHeight >= paddlePosY &&
//     //    newballPosY <= paddlePosY + paddleHeight)) && */ checkIntersection(rect1, rect2) && (ballPosY + ballHeight >= paddlePosY))
//     // {
//     //      ball_dy *= -1.0f;
//     //      newballPosY = newballPosY + ball_dy * ballSpeed * GetFrameTime();
//     // }




//     // Rectangle rect1, rect2;
//     // rect1.x = ballPosX;
//     // rect1.y = ballPosY;
//     // rect1.width = ballWidth;
//     // rect1.height = ballHeight;

//     // rect2.x = paddlePosX;
//     // rect2.y = paddlePosY;
//     // rect2.width = paddleWidth;
//     // rect2.height = paddleHeight;

//     // if(checkIntersection(rect1, rect2))
//     // {
//     //     ball_dy *= -1.0f;
//     //     newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     // }

//     // if(checkIntersection(rect1, rect2))
//     // {
//     //     ball_dx *= -1.0f;
//     //     newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     // }

//     // ballPosX = newballPosX;
//     // ballPosY = newballPosY;
// }

// void BallCollisionWithPaddle()
// {
//     Rectangle rect1, rect2;
//     rect1.x = ballPosX;
//     rect1.y = ballPosY;
//     rect1.width = ballWidth;
//     rect1.height = ballHeight;

//     rect2.x = paddlePosX;
//     rect2.y = paddlePosY;
//     rect2.width = paddleWidth;
//     rect2.height = paddleHeight;


//     // // float newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     // float newballPosX = ballPosX +  ballSpeedX * GetFrameTime();
//     // rect1.x = newballPosX;
//     // if(((newballPosX + ballWidth >= paddlePosX &&
//     //    newballPosX <= paddlePosX + paddleWidth) &&
//     //    (ballPosY + ballHeight >= paddlePosY &&
//     //    ballPosY <= paddlePosY + paddleHeight)) && /* checkIntersection(rect1,rect2) && */ 
//     //    ((ballPosX + ballWidth >= paddlePosX) || (ballPosX <= paddlePosX + paddleWidth)))
//     // {
//     //     // ball_dx *= -1.0f;
//     //     // ballSpeedX = -(1.55f * ballSpeedX);
//     //     // isCollidedHorizontally = true;
//     //     ballSpeedX = -(ballSpeedX);
//     //     // newballPosX = newballPosX + ball_dx * ballSpeed * GetFrameTime();
//     //     // newballPosX = ballPosX + ballSpeedX * GetFrameTime();
//     // }
//     // // float newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     // float newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     // rect1.y = newballPosY;
//     // if(((newballPosX + ballWidth >= paddlePosX &&
//     //    newballPosX <= paddlePosX + paddleWidth) &&
//     //    (newballPosY + ballHeight >= paddlePosY &&
//     //    newballPosY <= paddlePosY + paddleHeight)) && /* checkIntersection(rect1, rect2) && */ 
//     //    ((ballPosY + ballHeight >= paddlePosY) || (ballPosY <= paddlePosY + paddleHeight)))
//     // {
//     //     //  ball_dy *= -1.0f;
//     //     ballSpeedY = -ballSpeedY;
//     //     //  newballPosY = newballPosY + ball_dy * ballSpeed * GetFrameTime();
//     //     // newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     // }



//     // float newballPosX = ballPosX + ball_dx * ballSpeed * GetFrameTime();
//     float newballPosX = ballPosX +  ballSpeedX * GetFrameTime();
//     rect1.x = newballPosX;
//     if(((newballPosX + ballWidth >= paddlePosX &&
//        newballPosX <= paddlePosX + paddleWidth) &&
//        (ballPosY + ballHeight >= paddlePosY &&
//        ballPosY <= paddlePosY + paddleHeight)) && /* checkIntersection(rect1,rect2) && */ 
//        ((ballPosX + ballWidth >= paddlePosX) || (ballPosX <= paddlePosX + paddleWidth)))
//     {
//         if((!((ballSpeedX > 0 && paddleSpeed > 0) || (ballSpeedX < 0 && paddleSpeed < 0))))
//         {
//             // cout << paddleSpeed << " " << ballSpeedX << endl;
//             cout << "hello" << endl;
//             // ballSpeedX = ballSpeedX;
//             ballSpeedX = -ballSpeedX;
//             // return;
//         }
//         else
//         {
//             // cout << paddleSpeed << " " << ballSpeedX << endl;
//             cout << "hi" << endl;
//             if(ballPosX > paddlePosX + paddleWidth)
//             {
//                 paddlePosX = ballPosX - paddleWidth - ballWidth  + paddleSpeed * GetFrameTime();
//             }
//             else if((ballPosX + ballWidth < paddlePosX) /* && (ballSpeedX < 0 && paddleSpeed < 0) */)
//             {
//                 paddlePosX = ballPosX + ballWidth + paddleWidth + paddleSpeed * GetFrameTime();
//             }

//         }
//     }

//     // float newballPosY = ballPosY + ball_dy * ballSpeed * GetFrameTime();
//     float newballPosY = ballPosY + ballSpeedY * GetFrameTime();
//     rect1.y = newballPosY;
//     if(((newballPosX + ballWidth >= paddlePosX &&
//        newballPosX <= paddlePosX + paddleWidth) &&
//        (newballPosY + ballHeight >= paddlePosY &&
//        newballPosY <= paddlePosY + paddleHeight)) && /* checkIntersection(rect1, rect2) && */ 
//        ((ballPosY + ballHeight >= paddlePosY) || (ballPosY <= paddlePosY + paddleHeight)))
//     {
//         if(((ballSpeedX < 0 && paddleSpeed > 0) || (ballSpeedX > 0 && paddleSpeed < 0)))
//         {
//             // cout << paddleSpeed << " " << ballSpeedX << endl;
//             cout << "bye" << endl;
//             ballSpeedX = -ballSpeedX;
//         }
//             // cout << paddleSpeed << " " << ballSpeedX << endl;
//             cout << "world" << endl;
//         ballSpeedY = -ballSpeedY;
//     }

// }

// int main()
// {
//     InitWindow(WIDTH, HEIGHT, "Accelaration Testing");
//     // int rectWidth = 100;
//     // int rectHeight = 100;

    
//     SetTargetFPS(60);

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(BLACK);

//         userInput();

//         UpdateBall();
//         // UpdatePaddle();

//         BallCollisionWithPaddle();

//         DrawPaddle();
//         DrawBall();

//         DrawFPS(0, 0);
//         EndDrawing();
//         ballelapsedTime = GetFrameTime();
//     }
//     CloseWindow();

//     return 0;
// }




/* #include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

int main() {
    InitWindow(screenWidth, screenHeight, "Raylib Blur Filter");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);  // Clear the window with semi-transparent white
        // Draw your shapes on top (optional)
        DrawRectangle(100, 100, 200, 100, BLUE);  // Draw a red rectangle (adjust as needed)
        // SetBlendMode(BLEND_ADD);
        BlendMode(BLEND_ALPHA_PREMULTIPLY);
        // Draw multiple slightly offset, faded rectangles for a blur effect
        for (int yOffset = -4; yOffset <= 4; ++yOffset) {
            for (int xOffset = -4; xOffset <= 4; ++xOffset) {
                DrawRectangle(0, 0, screenWidth, screenHeight, Fade({200,200,200,255}, 0.1f));  // Adjust offset and alpha
            }
        }

        BlendMode(BLEND_ALPHA);
        EndDrawing();
    }

    CloseWindow();

    return 0;
} */



/* #include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;
const int rectWidth = 200;
const int rectHeight = 100;

int main() {
    InitWindow(screenWidth, screenHeight, "Raylib Simulated Blur");

    SetTargetFPS(60);

    Color rectColor = { 255, 0, 0, 128 }; // Red with some transparency (adjust alpha for desired visibility)

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLUE);  // Clear the window

        // Draw the original rectangle on top (optional)
        DrawRectangle(100, 100, rectWidth, rectHeight, rectColor);
        // Draw the rectangle with various offsets and reduced alpha for blur effect
        for (int yOffset = -2; yOffset <= 2; ++yOffset) {
            for (int xOffset = -2; xOffset <= 2; ++xOffset) {
                DrawRectangle(100 + xOffset, 100 + yOffset, rectWidth, rectHeight, Fade(rectColor, 0.1f));  // Adjust offset and alpha
            }
        }

        // DrawRectangle(100, 100, rectWidth, rectHeight, rectColor);
        // for (int yOffset = -4; yOffset <= 4; ++yOffset) {
        //     for (int xOffset = -4; xOffset <= 4; ++xOffset) {
        //         DrawRectangle(100 + xOffset, 100 + yOffset, rectWidth, rectHeight, Fade(rectColor, 0.09f));  // Adjust offset and alpha
        //     }
        // }


        EndDrawing();
    }

    CloseWindow();

    return 0;
} */





/* //!  Scaling Aniimation of ball

#include "raylib.h"
#include "../include/raymath.h"
#include <iostream>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 800;
const int rectWidth = 18.0f;
const int rectHeight = 18.0f;
// float currentTime = 0.0f;
// float delayTime = 4.0f;
float scaleSize = 10.0f;

float startingValue = 5.0f;
float endingValue = 1.0f;
float progress = 0.0f;
float timeToDecrease = 4.0f;
bool isAnimating = true;
Color color = BLACK;

bool Animation(float &startingValue,const  float &endingValue, float &progress, const float &timeToDecrease, bool &animating, float &scaleSize)
{

    progress += GetFrameTime() / timeToDecrease;
    progress = Clamp(progress, 0.0f, 1.0f);
    float currentValue = Lerp(startingValue, endingValue, progress);
    scaleSize = currentValue;
    if (progress >= 1.0f)
    {
        progress = 0.0f;
        currentValue = endingValue;
        animating = false;
        return false;
    }

    return true;
}

int main() {
    InitWindow(screenWidth, screenHeight, "Object scaling");

    SetTargetFPS(60);

    Rectangle rec = {
        screenWidth / 2 - rectWidth / 2,
        screenHeight / 2 - rectHeight / 2,
        rectWidth,
        rectHeight};

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        //     currentTime += GetFrameTime();
        // if(currentTime < delayTime)
        // {
        //     scaleSize = Lerp(currentTime, delayTime, 2.0f);
        //     // scaleSize = scaleSize / currentTime ;
        //     cout << scaleSize << endl;
        // }

        isAnimating && Animation(startingValue, endingValue, progress, timeToDecrease, isAnimating, scaleSize);
        // {
            // Vector2 scaledVec = Vector2Scale({rectWidth, rectHeight}, scaleSize);
            // DrawRectangle(screenWidth / 2 - scaledVec.x / 2, screenHeight / 2 - scaledVec.y / 2, scaledVec.x, scaledVec.y, RED);
            // scaleSize = startingValue;
        // }

        // if(IsKeyDown(KEY_SPACE))
        // {
            // DrawRectangleRounded(rec, 100.0f, 100, BLUE);
        cout << scaleSize << endl;
        Vector2 scaledVec = Vector2Scale({rectWidth, rectHeight}, scaleSize);
        DrawRectangle(screenWidth / 2 - scaledVec.x / 2, screenHeight / 2 - scaledVec.y / 2, scaledVec.x, scaledVec.y, RED);
        // }
        // else
        // {
        //     DrawRectangle(screenWidth / 2 - rectWidth / 2, screenHeight / 2 - rectHeight / 2, rectWidth, rectHeight, RED);
        // }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

*/



/* #include "raylib.h"
#include "../include/raymath.h"

using namespace std;

// const int WIDTH{1920};
// const int HEIGHT{1080};
int WIDTH{1500};
int HEIGHT{700};
// int WIDTH{400};
// int HEIGHT{400};

float rectWidth = 100;
float rectHeight = 20;
float rectPosX = WIDTH/2 - rectWidth/2;
float rectPosY = HEIGHT/2 - rectHeight/2;
float rectSpeedX = 600.0f;
float rectSpeedY = 600.0f;

int main()
{
    InitWindow(WIDTH, HEIGHT, "Accelaration Testing");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if(IsKeyDown(KEY_LEFT))
        {
            rectPosX = rectPosX - rectSpeedX * GetFrameTime();
        }

        if(IsKeyDown(KEY_RIGHT))
        {
            rectPosX = rectPosX + rectSpeedY * GetFrameTime();
        }

        if(IsKeyPressed(KEY_SPACE))
        {
            rectPosX = WIDTH / 2 - rectWidth / 2;
            rectPosY = HEIGHT / 2 - rectHeight / 2;
        }

        if(rectPosX < 0 || rectPosX + rectWidth > WIDTH)
        {
            rectPosX = Clamp(rectPosX, 0, rectPosX+rectWidth);
            rectPosX = Clamp(rectPosX, rectPosX-rectWidth, WIDTH-rectWidth);
        }

        DrawRectangle(rectPosX, rectPosY, rectWidth, rectHeight, RED);

        EndDrawing();
    }
    CloseWindow();

    return 0;
} */



/* #include "raylib.h"
#include <iostream>
#include "../include/raymath.h"

using namespace std;

int WIDTH{1500};
int HEIGHT{700};

float rectWidth = 100;
float rectHeight = 20;
float rectPosX = WIDTH / 2 - rectWidth / 2;
float rectPosY = HEIGHT / 2 - rectHeight / 2;
float rectSpeedX = 0.0f;  // Initial speed
float rectSpeedY = 0.0f;  // Initial speed
float acceleration = 500.0f;  // Acceleration rate
bool leftKeyPressed = false;
bool rightKeyPressed = false;

int main()
{
    InitWindow(WIDTH, HEIGHT, "Acceleration Testing");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Update speed based on acceleration
        if (IsKeyDown(KEY_LEFT))
        {
                // cout << "hii" << endl;
                leftKeyPressed = true;
                rectSpeedX = rectSpeedX - acceleration * GetFrameTime();
                // rectPosX -= rectSpeedX * GetFrameTime();
                // rectPosX = rectPosX + rectSpeedX*GetFrameTime() - acceleration * GetFrameTime();
        }
        
            if (leftKeyPressed && IsKeyUp(KEY_LEFT))
            {
                // cout << "hello" << endl;
                leftKeyPressed = false;
                rectSpeedX = 0.0f;
            }


        if (IsKeyDown(KEY_RIGHT))
        {
            rightKeyPressed = true;
            rectSpeedX = rectSpeedX + acceleration * GetFrameTime();
            // rectPosX += rectSpeedX * GetFrameTime();
            // rectPosX += rectSpeedX * GetFrameTime();
        }

        if (rightKeyPressed && IsKeyUp(KEY_RIGHT))
        {
            rightKeyPressed = false;
            rectSpeedX = 0.0f;
        }

        if(IsKeyPressed(KEY_SPACE))
        {
            rectPosX = WIDTH / 2 - rectWidth / 2;
            rectPosY = HEIGHT / 2 - rectHeight / 2;
        }
        

        // Apply speed limits
        if (rectSpeedX > 600.0f) rectSpeedX = 600.0f;
        if (rectSpeedX < -600.0f) rectSpeedX = -600.0f;


        // Update position
        rectPosX += rectSpeedX * GetFrameTime();

        // Boundaries check
        if (rectPosX < 0) rectPosX = 0;
        if (rectPosX + rectWidth > WIDTH) rectPosX = WIDTH - rectWidth;

        // Draw rectangle
        DrawRectangle(rectPosX, rectPosY, rectWidth, rectHeight, RED);

        EndDrawing();
    }
    CloseWindow();

    return 0;
} */



#include "raylib.h"
#include "../include/raymath.h"

using namespace std;

int WIDTH{1500};
int HEIGHT{700};

float rectWidth = 100;
float rectHeight = 20;
float rectPosX = WIDTH / 2 - rectWidth / 2;
float rectPosY = HEIGHT / 2 - rectHeight / 2;
float rectSpeedX = 0.0f;  // Initial speed
float rectSpeedY = 0.0f;  // Initial speed
float acceleration = 500.0f;  // Acceleration rate
float deceleration = 600.0f;  // Deceleration rate

int main()
{
    InitWindow(WIDTH, HEIGHT, "Acceleration Testing");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Update speed based on acceleration or deceleration
        if (IsKeyDown(KEY_LEFT))
        {
            rectSpeedX -= acceleration * GetFrameTime();
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            rectSpeedX += acceleration * GetFrameTime();
        }
        else
        {
            // If neither key is pressed, gradually decrease speed to 0
            if (rectSpeedX > 0)
            {
                rectSpeedX -= deceleration * GetFrameTime();
                if (rectSpeedX < 0) rectSpeedX = 0;
            }
            else if (rectSpeedX < 0)
            {
                rectSpeedX += deceleration * GetFrameTime();
                if (rectSpeedX > 0) rectSpeedX = 0;
            }
        }

        // Apply speed limits
        if (rectSpeedX > 600.0f) rectSpeedX = 600.0f;
        if (rectSpeedX < -600.0f) rectSpeedX = -600.0f;

        // Update position
        rectPosX += rectSpeedX * GetFrameTime();

        // Boundaries check
        if (rectPosX < 0) rectPosX = 0;
        if (rectPosX + rectWidth > WIDTH) rectPosX = WIDTH - rectWidth;

        // Draw rectangle
        DrawRectangle(rectPosX, rectPosY, rectWidth, rectHeight, RED);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

