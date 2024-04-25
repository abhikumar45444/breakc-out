// #include "raylib.h"
// #include <iostream>

// using namespace std;

// // const int WIDTH{1920};
// // const int HEIGHT{1080};
// int WIDTH{1500};
// int HEIGHT{700};
// // int WIDTH{400};
// // int HEIGHT{400};

// int main()
// {
//     InitWindow(WIDTH, HEIGHT, "Accelaration Testing");
//     int rectWidth = 100;
//     int rectHeight = 10;

//     float x = GetScreenWidth() / 2 - rectWidth / 2;
//     float y = GetScreenHeight() / 2 - rectHeight / 2;

//     float Accelaration = 0.0f;
//     float leftvelocity = 10.0f;
//     float rightvelocity = 10.0f;
//     float leftincrementFactor = 0.1f;
//     float rightincrementFactor = 0.1f;

//     SetTargetFPS(60);

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(BLACK);

//         if (IsKeyDown(KEY_LEFT))
//         {
//             Accelaration = leftvelocity * GetFrameTime();
//             leftvelocity = leftvelocity + 2.0f * leftincrementFactor;
//             x = x - Accelaration;
//             rightvelocity = 0.0f;
//             leftincrementFactor += 0.2f;
//             rightincrementFactor = 0.1f;
//         }

//         if (IsKeyDown(KEY_RIGHT))
//         {
//             Accelaration = rightvelocity * GetFrameTime();
//             rightvelocity = rightvelocity - 2.0f * rightincrementFactor;
//             x = x - Accelaration;
//             leftvelocity = 0.0f;
//             rightincrementFactor += 0.2f;
//             leftincrementFactor = 0.1f;
//         }

//         if (IsKeyDown(KEY_SPACE))
//         {
//             x = GetScreenWidth() / 2 - rectWidth / 2;
//             y = GetScreenHeight() / 2 - rectHeight / 2;
//         }

//         if(IsKeyUp(KEY_RIGHT))
//         {
//             rightvelocity = rightvelocity - 2.0f ;
//             rightincrementFactor = 0.1f;
//         }

//         if(IsKeyUp(KEY_LEFT))
//         {
//             leftvelocity = 0.0f;
//             leftincrementFactor = 0.1f;
//         }

//         DrawRectangle(x, y, rectWidth, rectHeight, RED);
//         DrawFPS(0, 0);
//         EndDrawing();
//     }

//     CloseWindow();

//     return 0;
// }




/* #include "raylib.h"
#include <iostream>
#include <math.h>

using namespace std;

// const int WIDTH{1920};
// const int HEIGHT{1080};
int WIDTH{1500};
int HEIGHT{700};
// int WIDTH{400};
// int HEIGHT{400};

#define FLT_EPSILON 1.192092896e-07F

int main()
{
    InitWindow(WIDTH, HEIGHT, "Accelaration Testing");
    int rectWidth = 100;
    int rectHeight = 100;

    float x = 0;
    float y = GetScreenHeight() / 2 - rectHeight / 2;

    float speed = 100.0f;
    float dx = speed;
    // float maxdx = 500.0f;
    // float dy = speed;
    // float step = 0.1f;

    InitAudioDevice();

    Sound fxOgg = LoadSound("../Resources/tilebreaker.ogg");

    IsSoundReady(fxOgg) ? cout << "Ready" : cout << "not ready";
    cout << endl;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK); 

        if(IsKeyReleased(KEY_LEFT))
        {
            dx = speed;
            // step = 0.1f;

        }

        if(IsKeyReleased(KEY_RIGHT))
        {
            dx = speed;
            // step = 0.1f;
        }

        if(IsKeyPressed(KEY_P))
        {
            // if(IsSoundPlaying(fxOgg))
            // {
            //     // cout << "playing..." << endl;
            // }
            // else
            //     // cout << "not playing..." << endl;

            PlaySound(fxOgg);
        }

        if (IsKeyDown(KEY_LEFT))
        {
            dx *= 1.07f;
            float displacement = -dx * GetFrameTime();
            x = x + displacement;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            dx *= 1.07f;
            float displacement = dx * GetFrameTime();
            x = x + displacement;
            // PlaySound(fxOgg);
        }

        if (IsKeyDown(KEY_SPACE))
        {
            x = GetScreenWidth() / 2 - rectWidth / 2;
            y = GetScreenHeight() / 2 - rectHeight / 2;
        }

        DrawRectangle(x, y, rectWidth, rectHeight, RED);
        DrawFPS(0, 0);
        EndDrawing();
    }

    UnloadSound(fxOgg);     // Unload sound data

    CloseAudioDevice();

    CloseWindow();

    return 0;
}
 */


#include <raylib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <time.h>
#include <filesystem>
// #include <sys/types.h>
// #include <dirent.h>
#include "../include/raymath.h"

using namespace std;

#define TILESROW 5
#define TILESCOL 3

//! constants
int WIDTH = 1000;
int HEIGHT = 650;
const char *TITLE = "BREAKOUT";

//! variables
Color backgroundColor = BLACK;
int newWidth = GetScreenWidth();
int newHeight = GetScreenHeight();
bool isGameStarted = false;
bool isGameEnded = false;
bool isGameOver = false;
bool isGameWon = false;
int highscore = 0;
bool generateParticles = false;

//! Player lifes
int livesLeft = 4;
struct LifeRects
{
    Vector2 pos;
    Color color;
};

vector<LifeRects> livesrects;

bool ballReset = false;
float delayTime = 3.0f;
float elapsedTime = 0.0f;
float currentTime = 0.0f;

//! paddle variables
float paddleWidth = 100.0f;
float paddleHeight = /* 100.0f */ 15.0f;
float paddlePosX = WIDTH * 0.5f - paddleWidth * 0.5f;
float paddlePosY = HEIGHT - 60;
Color paddleColor = DARKBLUE;
float paddleSpeed = 400.0f;
bool isPaddleDirLeft = false;
bool isPaddleDirRight = false;
// Color paddleColorStart =  { 180, 180, 180, 255 }  /* { 255, 20, 30, 255 } */;
// Color paddleColorEnd = { 255, 20, 30, 255 } /* { 10, 10, 10, 255 } */;
Color paddleColorFirst = { 255, 20, 30, 255 } /* { 10, 10, 10, 255 } */;
Color paddleColorSecond = BLACK /* { 10, 10, 10, 255 } */;
Color paddleColorThird = { 255, 20, 30, 255 } /* { 10, 10, 10, 255 } */;
Color paddleColorFourth = { 180, 180, 180, 255 } /* { 10, 10, 10, 255 } */;


//! ball variables
float ballGap = 3.0f;
float ballWidth = 18.0f;
float ballHeight = 18.0f;
float ballPosX = paddlePosX + paddleWidth * 0.5f - ballWidth * 0.5f;
float ballPosY = paddlePosY - paddleHeight * 0.5f - ballHeight * 0.5f - ballGap;
Color ballColor = GOLD;
float ballSpeed = -300.0f;
float ballSpeedX = ballSpeed;
float ballSpeedY = ballSpeed;
float isCollidedHorizontally = false;
float ballcurrentTime = 0.0f;
float ballelapsedTime = 0.0f;
float balldelayTime = 0.1f;
float speedIncreasedFactor = 1.90f;
bool resetSpeed = false;
int ballMinAngle = -45;
int ballMaxAngle = -150;
float ballAngle = 0;

//! Tiles variables
struct Tile
{
    bool isAlive;
    Vector2 pos;
    Color color;
    int hitsLeft;
};

vector<vector<Tile>> tiles(TILESROW);
vector<Color> brickRowColor;
float tileWidth = 70.0f;
float tileHeight = 12.0f;

//! Game Score
int score = 0;

//! Game Sounds 
Sound tileBreakSound;
Sound tileHitSound;
Sound ballBreakSound;
Sound paddleHitSound;
Sound gameWonSound;
Sound gameOverSound;
Music gameMusic;

//! Game Font
Font font;

//! Particle system
struct Size
{
    int w;
    int h;
};

const int minLifetimeValue = 1;
const int maxLifetimeValue = 2;
const int minSizeValue = 3;
const int maxSizeValue = 9;
const int particleMinAngle = 40;
const int particleMaxAngle = 150;
const int particleMinSpeed = 100;
const int particleMaxSpeed = 250;
int maxParticles = 30;

struct Particle
{
    float lifetime;
    Vector2 speed;
    Vector2 pos;
    Size size;
    Color color;
    float angle;
    bool isAlive;
    float currentLifeTime;
};

vector<Particle> particles;
//! Particle system ends


bool isAnimating = true;
bool gameStartScreenAnimation = true;
bool gameStartScreenAnimationText = true;
bool gameStartedFirstTime = true;
bool isAnimationCancelled = false;
bool isGameWonAnimationCompleted = false;
bool gameWonScreenAnimation = true;
bool gameWonScreenAnimationText = true;
bool isGameOverAnimationCompleted = false;
bool gameOverScreenAnimation = true;
bool gameOverScreenAnimationText = true;


//! Level text strings starts

struct LevelTextStr
{
    string levelTextStr;
    const char *levelText;
    int textWidth;
};

vector<LevelTextStr> levelTextStr;

//! Level text strings ends  

RenderTexture2D target;
Vector2 touchPosition = {-1, -1};
int gesture = GESTURE_NONE;

//!  function declarations - starts
void ScreenResized();
void userInput();
void Paddle();
void BallReset();
void Ball();
void BallMovement();
void BallCollisionWithPaddle();
void BallCollisionWithTiles();
void InitializeTiles();
void InitializeBrickColors();
void DrawTiles();
void UpdateDrawFrame(void);
void RenderScore();
void RenderHighScore();
void GameState();
void ResetGameState();
void GameStartScreen();
void GameOverScreen();
void GameWonScreen();
void IsGameWon();
void GameReset();
void Lives();
void InitializeLifeRects();
void DrawLiveRects();
Vector4 Vector4Lerp(Vector4 a, Vector4 b, float t);
Vector4 srgb_to_linear(Vector4 color);
Vector4 linear_to_srgb(Vector4 color);
bool checkIntersectionX(const Rectangle &rect1, const Rectangle &rect2);
bool checkIntersectionY(const Rectangle &rect1, const Rectangle &rect2);
bool checkIntersection(const Rectangle &rect1, const Rectangle &rect2);
Color GetLerpedGradientColor(Color start, Color end, float t);
float randomFloat();
int randomInt(int a, int b);
float randomFloat(int a, int b);
void ParticleInit();
void DrawParticles();
void MoveParticles();
void GenerateParticles(Color tileColor, Vector2 tilePos, bool direction, int noOfParticles);
void ParticleCollisionWithTiles();
bool Animation(float &startingValue, const float &endingValue, float &progress, const float &timeToDecrease, bool &animating, Color &animColor);
void GameGradientBackground();
void BlurEffect(float posX, float posY, float width, float height, Color color);
void BlurEffect(float posX, float posY, float width, float height, Color color1, Color color2, Color color3, Color color4);
void BlurEffect(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
bool GameWonAnimation(bool fullAnimNotCompleted);
bool GameOverAnimation(bool fullAnimNotCompleted);
bool TouchStartGameInput();
void InitializeLevels();
//!  function declarations - ends


int main()
{
    srand(time(0));
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetGesturesEnabled(GESTURE_DOUBLETAP | GESTURE_DRAG | GESTURE_TAP);

    //* Window initialization
    InitWindow(WIDTH, HEIGHT, TITLE);

    //* Initialize Sound
    InitAudioDevice();

    tileBreakSound = LoadSound("../resources/tilebreaknew3.ogg");
    tileHitSound = LoadSound("../resources/tilehit3.ogg");
    ballBreakSound = LoadSound("../resources/ballbreak.ogg");
    paddleHitSound = LoadSound("../resources/paddlehit.ogg");
    gameWonSound = LoadSound("../resources/gamewon1.ogg");
    gameOverSound = LoadSound("../resources/gameover.ogg");
    // gameMusic = LoadSound("../resources/gamemusic.ogg");
    gameMusic = LoadMusicStream("../resources/gamemusic.mp3");
    // AudioStream audiostm;
    // LoadAudioStream()
    gameMusic.looping = true;
    // gameMusic.stream = 

    // SetSoundVolume(tileBreakSound, 0.1f);
    // SetSoundVolume(tileHitSound, 0.1f);
    // SetSoundVolume(ballBreakSound, 0.1f);
    // SetSoundVolume(paddleHitSound, 0.1f);
    // SetSoundVolume(gameMusic, 0.4f);
    SetMusicVolume(gameMusic, 0.2f);

    const char *filename = "../resources/font.ttf";
    font = LoadFontEx(filename, 50, 0, 250);

    //* set Frames per second
    const int FPS = 60;
    SetTargetFPS(FPS);

    // InitializeLevels();
    InitializeBrickColors();
    InitializeTiles();
    InitializeLifeRects();
    ParticleInit();

    ballAngle = randomFloat(ballMinAngle, ballMaxAngle);
    if(GetRandomValue(0,1))
    {
        ballSpeedX = -ballSpeedX;
    }

    target = LoadRenderTexture(WIDTH, HEIGHT);

    //* game loop
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    //* freeing up resources
    UnloadFont(font);
    UnloadSound(tileBreakSound);
    UnloadSound(tileHitSound);
    UnloadSound(ballBreakSound);
    UnloadSound(paddleHitSound);
    UnloadSound(gameWonSound);
    UnloadSound(gameOverSound);
    UnloadMusicStream(gameMusic);
    CloseAudioDevice();
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}


bool TouchStartGameInput()
{
    touchPosition = GetTouchPosition(0);
    bool touchStartGameInput = false;
    gesture = GetGestureDetected();

    cout << "gesture: " << gesture << endl;
    cout << "touch pos x: " << touchPosition.x<<"    "<< "touch pos y: " << touchPosition.y << endl;

    if (gesture == GESTURE_DOUBLETAP && touchPosition.x > 0 && touchPosition.y > 0)
    {
        touchStartGameInput = touchPosition.x > 0 && touchPosition.x < WIDTH && touchPosition.y > 0 && touchPosition.y < HEIGHT;
    }

    return touchStartGameInput;
}

/* void InitializeLevels()
{
    // int counter = 0;
    // WIN32_FIND_DATA ffd;
    // HANDLE hFind = INVALID_HANDLE_VALUE;

    // // Start iterating over the files in the path directory.
    // hFind = ::FindFirstFileA (path.c_str(), &ffd);
    // if (hFind != INVALID_HANDLE_VALUE)
    // {
    //     do // Managed to locate and create an handle to that folder.
    //     { 
    //         counter++;
    //     } while (::FindNextFile(hFind, &ffd) == TRUE);
    //     ::FindClose(hFind);
    // } else {
    //     printf("Failed to find path: %s", path.c_str());
    // }

    // return counter;

    const std::filesystem::path levels{"E:\\Programming\\C-CPP\\RAYLIB\\BreakOut\\resources\\levels"};
    // auto dirIter = std::filesystem::directory_iterator(levels);
    int fileCount = 0;

    for (auto& p : std::filesystem::directory_iterator(levels))
    {
       ++fileCount;
    }

    // for (auto const& dir_entry : std::filesystem::directory_iterator{levels}) 
    //     std::cout << dir_entry.path() << '\n';

    // for (auto &entry : dirIter)
    // {
    //     if (entry.is_regular_file())
    //     {
    //         ++fileCount;
    //     }
    // }

    cout << endl<< endl<< fileCount << endl<< endl<< endl<< endl;
}
 */


void InitializeBrickColors()
{
    for (int row = 0; row < TILESROW; row++) 
    {
        Vector4 red = srgb_to_linear(Vector4{1, 0.18f, 0.18f, 1});
        Vector4 green = srgb_to_linear(Vector4{0.18f, 1, 0.18f, 1});
        Vector4 blue = srgb_to_linear(Vector4{0.18f, 0.18f, 1, 1});
        float level = 0.5f;
        float t = (float)row / TILESROW;
        float c = (t < level) ? 1.0f : 0.0f;
        Vector4 g1 = Vector4Lerp(red, green, t / level);
        Vector4 g2 = Vector4Lerp(green, blue, (t - level) / (1 - level));

        Vector4 colorVec = linear_to_srgb(
            Vector4{
                c*g1.x+(1-c)*g2.x,
                c*g1.y+(1-c)*g2.y,
                c*g1.z+(1-c)*g2.z,
                c*g1.w+(1-c)*g2.w
            }
        );
        Color color = ColorFromNormalized(colorVec);
        brickRowColor.push_back(color);
    }
}


void BlurEffect(float posX, float posY, float width, float height, Color color)
{
    for (int yOffset = -2; yOffset <= 2; ++yOffset)
    {
        for (int xOffset = -2; xOffset <= 2; ++xOffset)
        {
            DrawRectangle(posX + xOffset, posY + yOffset, width, height, Fade(color, 0.1f));
        }
    }
}

void BlurEffect(float posX, float posY, float width, float height, Color color1, Color color2, Color color3, Color color4)
{
    for (int yOffset = -2; yOffset <= 2; ++yOffset)
    {
        for (int xOffset = -2; xOffset <= 2; ++xOffset)
        {
            DrawRectangleGradientEx({posX + xOffset, posY + yOffset, width, height}, Fade(paddleColorFirst, 0.1f), Fade(paddleColorSecond, 0.1f), Fade(paddleColorThird, 0.1f), Fade(paddleColorFourth, 0.1f));
        }
    }
}

void BlurEffect(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{
    for (int yOffset = -2; yOffset <= 2; ++yOffset)
    {
        for (int xOffset = -2; xOffset <= 2; ++xOffset)
        {
            DrawTextEx(font,text,{position.x + xOffset, position.y + yOffset}, fontSize, spacing, Fade(tint, 0.1f));
        }
    }
}

void GameGradientBackground()
{
    DrawRectangleGradientV(0, 0, WIDTH, HEIGHT, {50, 50, 230, 30}, {200, 122, 240, 150});
}

bool Animation(float &startingValue,const  float &endingValue, float &progress, const float &timeToDecrease, bool &animating, Color &animColor)
{

    progress += GetFrameTime() / timeToDecrease;
    progress = Clamp(progress, 0.0f, 1.0f);
    float currentValue = Lerp(startingValue, endingValue, progress);
    animColor.a = (unsigned char)(currentValue);
    if (progress >= 1.0f)
    {
        progress = 0.0f;
        currentValue = endingValue;
        animating = false;
        return false;
    }

    return true;
}

bool Delay(float &currentTime_, const float &delayTime_)
{
    currentTime_ += GetFrameTime();
    if(currentTime_ <= delayTime_)
    {
        return false;
    }

    return true;
}

bool GameWonAnimation(bool fullAnimNotCompleted)
{
    static Color color =  {220, 220, 220, 255};
    static float startingValue = color.a;
    static float endingValue = 160.0f;
    static float timeToDecrease = 3.0f;
    static float progress = 0.0f;
    // static bool isAnimating = true;

    static Color animColorGW = {220, 220, 220, 255};
    static float startingValueGW = animColorGW.a;
    static float endingValueGW = 160.0f;
    static float timeToDecreaseGW = 3.0f;
    static float progressGW = 0.0f;
    
    static Color textColorGW = {230, 41, 55, 0};
    static float textstartingValueGW = textColorGW.a;
    static float textendingValueGW = 255.0f;
    static float texttimeToDecreaseGW = 2.0f;
    static float textprogressGW = 0.0f;

    static string textStrGW = "CONGRATULATIONS !! YOU WON ....";
    static const char *textGW = textStrGW.c_str();
    static int textWidthGW = MeasureText(textGW, 40);

    if(gameWonScreenAnimation || isAnimating || gameWonScreenAnimationText || fullAnimNotCompleted)
    {
        if (gameWonScreenAnimation && Animation(startingValueGW, endingValueGW, progressGW, timeToDecreaseGW, gameWonScreenAnimation, animColorGW))
        {
            DrawRectangle(0, 0, WIDTH, HEIGHT, animColorGW);
            return true;
        }
        else
        {
            DrawRectangle(0, 0, WIDTH, HEIGHT, animColorGW);
            if (isAnimating && Animation(startingValue, endingValue, progress, timeToDecrease, isAnimating, color))
            {
                if(!IsSoundPlaying(gameWonSound))
                    PlaySound(gameWonSound);
                int randomIndex = GetRandomValue(0, brickRowColor.size() - 1);
                Color particleColor = brickRowColor[randomIndex];
                int padding = 200;
                Vector2 pos = {randomFloat(padding, WIDTH - padding), randomFloat(padding, HEIGHT - padding)};
                if (particles.size() < 600)
                    GenerateParticles(particleColor, pos, (bool)randomInt(0, 1), maxParticles);

                return true;
            }

            if (gameWonScreenAnimationText && Animation(textstartingValueGW, textendingValueGW, textprogressGW, texttimeToDecreaseGW, gameWonScreenAnimationText, textColorGW))
            {
                DrawTextEx(font, TextFormat(textGW), {WIDTH * 0.5f - textWidthGW * 0.5f, HEIGHT * 0.5f}, 40, 0, textColorGW);
                return true;
            }
            else
            {
                textColorGW.a = 255;
                DrawTextEx(font, TextFormat(textGW), {WIDTH * 0.5f - textWidthGW * 0.5f, HEIGHT * 0.5f}, 40, 0, textColorGW);
                return false;
            }
        }
        return false;
    }
    return false;
}


bool GameOverAnimation(bool fullAnimNotCompleted)
{
    static Color animColorGO = /* RED */ { 230, 41, 55, 220 };
    static float startingValueGO = animColorGO.a;
    static float endingValueGO = 130.0f;
    static float timeToDecreaseGO = 3.0f;
    static float progressGO = 0.0f;
    
    static Color textColorGO = { 0, 121, 241, 0 } /* {230, 41, 55, 0} */;
    static float textstartingValueGO = textColorGO.a;
    static float textendingValueGO = 255.0f;
    static float texttimeToDecreaseGO = 2.0f;
    static float textprogressGO = 0.0f;

    static string textStrGO = "HAHA !! YOU LOSE .. TRY AGAIN ...";
    static const char *textGO = textStrGO.c_str();
    static int textWidthGO = MeasureText(textGO, 40);
    
    if(gameOverScreenAnimation || gameOverScreenAnimationText || fullAnimNotCompleted)
    {
        if (gameOverScreenAnimation && Animation(startingValueGO, endingValueGO, progressGO, timeToDecreaseGO, gameOverScreenAnimation, animColorGO))
        {
            DrawRectangle(0, 0, WIDTH, HEIGHT, animColorGO);
            return true;
        }
        else
        {
            DrawRectangle(0, 0, WIDTH, HEIGHT, animColorGO);
            if (gameOverScreenAnimationText && Animation(textstartingValueGO, textendingValueGO, textprogressGO, texttimeToDecreaseGO, gameOverScreenAnimationText, textColorGO))
            {
                if(!IsSoundPlaying(gameOverSound))
                    PlaySound(gameOverSound);
                DrawTextEx(font, TextFormat(textGO), {WIDTH * 0.5f - textWidthGO * 0.5f, HEIGHT * 0.5f}, 40, 0, textColorGO);
                return true;
            }
            else
            {
                textColorGO.a = 255;
                DrawTextEx(font, TextFormat(textGO), {WIDTH * 0.5f - textWidthGO * 0.5f, HEIGHT * 0.5f}, 40, 0, textColorGO);
                return false;
            }
        }
        return false;
    }
    return false;
}

void ResetGameState()
{
    
    maxParticles = 30;
    isGameStarted = false;
    isGameEnded = false;
    isGameWon = false;
    isGameOver = false;
    generateParticles = false;
    ballReset = true;
    gameStartScreenAnimation = true;
    gameStartScreenAnimationText = true;
    isAnimating = true;
    isAnimationCancelled = false;
    isGameWonAnimationCompleted = false;
    gameWonScreenAnimation = true;
    gameWonScreenAnimationText = true;
    isGameOverAnimationCompleted = false;
    gameOverScreenAnimation = true;
    gameOverScreenAnimationText = true;
    gesture = GESTURE_NONE;
}

void GameState()
{
    bool touchStartGameInput = TouchStartGameInput();

    if(gameStartedFirstTime)
    {
        if((IsKeyPressed(KEY_SPACE) || touchStartGameInput)  && !gameStartScreenAnimation && !gameStartScreenAnimationText)
        {
            PlayMusicStream(gameMusic);
            isGameStarted = !isGameStarted;
            gameStartedFirstTime = false;
        }
    }
    else
    {
        PlayMusicStream(gameMusic);
        if((IsKeyPressed(KEY_SPACE) || touchStartGameInput) && !isAnimationCancelled)
        {
            isGameStarted = !isGameStarted;
            isAnimationCancelled = true;
        }
        else if(IsKeyPressed(KEY_SPACE) || touchStartGameInput)
        {
            isGameStarted = !isGameStarted;
        }
    }
}


void userInput()
{
    // if (IsKeyDown(KEY_LEFT) )
    // {
    //     paddlePosX -= paddleSpeed * GetFrameTime();
    //     isPaddleDirLeft = true;
    //     isPaddleDirRight = false;
    // }
    // else
    // {
    //     isPaddleDirLeft = false;
    // }

    // if (IsKeyDown(KEY_RIGHT))
    // {
    //     paddlePosX += paddleSpeed * GetFrameTime();
    //     isPaddleDirLeft = false;
    //     isPaddleDirRight = true;
    // }
    // else
    // {
    //     isPaddleDirRight = false;
    // }

    bool gestureDetected = false;

    if(IsGestureDetected(GESTURE_DRAG))
    {
        gestureDetected = true;
    }

    if (IsKeyDown(KEY_LEFT) || (gestureDetected && GetTouchPosition(0).x < paddlePosX))
    {
        paddlePosX -= paddleSpeed * GetFrameTime();

        // if(gestureDetected)
        // {
        //     // paddlePosX = (GetTouchPosition(0).x - paddleWidth * 0.5f) - paddleSpeed * GetFrameTime();
        //     // paddlePosX = (paddlePosX - paddleWidth * 0.5f) - paddleSpeed * GetFrameTime();
        //     // paddlePosX = paddlePosX - paddleWidth * 0.5f;
        //     paddlePosX -= paddleSpeed * GetFrameTime();
        // }
        // else
        // {
        //     paddlePosX -= paddleSpeed * GetFrameTime();
        // }

        isPaddleDirLeft = true;
        isPaddleDirRight = false;
    }
    else
    {
        isPaddleDirLeft = false;
    }

    if (IsKeyDown(KEY_RIGHT) || (gestureDetected && GetTouchPosition(0).x > paddlePosX))
    {
        paddlePosX += paddleSpeed * GetFrameTime();

        // if(gestureDetected)
        // {
        //     // paddlePosX = (GetTouchPosition(0).x - paddleWidth * 0.5f) + paddleSpeed * GetFrameTime();
        //     // paddlePosX = (paddlePosX - paddleWidth * 0.5f) + paddleSpeed * GetFrameTime();
        //     // paddlePosX = paddlePosX - paddleWidth * 0.5f;
        //     paddlePosX += paddleSpeed * GetFrameTime();
        // }
        // else
        // {
        //     paddlePosX += paddleSpeed * GetFrameTime();
        // }

        isPaddleDirLeft = false;
        isPaddleDirRight = true;
    }
    else
    {
        isPaddleDirRight = false;
    }

    // // bool isTouched = FloatEquals(paddlePosX, (GetTouchPosition(0)).x);
    // bool isTouched = abs(paddlePosX - (GetTouchPosition(0)).x) < 5.0f;
    // cout << "paddleposx: " << paddlePosX <<"    "<<"touch pos x: "<< (GetTouchPosition(0)).x <<"   "<< "istouched: "<< isTouched <<endl;
    // // cout << gestureDetected << endl;
    // // if(((GetGestureHoldDuration() / 1000.0f) > 1.0f) && isTouched)
    // if(GetGestureDetected() == GESTURE_DRAG && isTouched && !((GetGestureHoldDuration() / 1000.0f) > 1.0f))
    // {
    //     cout << "hi" << endl;
    //     // paddlePosX = paddlePosX - paddleWidth * 0.5f;
    //     paddlePosX = GetTouchPosition(0).x - paddleWidth * 0.5f;
    // }
    // else
    // {
    //     // cout << "hello" << endl;
    // }

    paddlePosX = Clamp(paddlePosX, 0.0f, paddlePosX+paddleWidth);
    paddlePosX = Clamp(paddlePosX, paddlePosX-paddleWidth, (float)WIDTH-paddleWidth);
}

void Paddle()
{
    if(isGameStarted && !isGameEnded)
    {
        DrawRectangleGradientEx({paddlePosX, paddlePosY, paddleWidth, paddleHeight}, paddleColorFirst, paddleColorSecond, paddleColorThird, paddleColorFourth);
        return;
    }
  
    BlurEffect(paddlePosX, paddlePosY, paddleWidth, paddleHeight, paddleColorFirst, paddleColorSecond, paddleColorThird, paddleColorFourth);
}

void BallReset()
{
    if (ballReset)
    {
        ballPosX = paddlePosX + paddleWidth * 0.5f - ballWidth * 0.5f;
        ballPosY = paddlePosY - paddleHeight * 0.5f - ballHeight * 0.5f - ballGap;
        ballAngle = randomFloat(ballMinAngle, ballMaxAngle);
        ballSpeedX = ballSpeed;

        if ((isPaddleDirLeft && ballSpeedX > 0) || (isPaddleDirRight && ballSpeedX < 0))
        {
            ballSpeedX = -ballSpeedX;
        }

        if (!isGameStarted)
        {
            return;
        }

        currentTime = currentTime + elapsedTime;
        if (currentTime >= delayTime)
        {
            if (GetRandomValue(0, 1))
            {
                ballSpeedX = -ballSpeedX;
            }
            ballReset = false;
            currentTime = 0.0f;
        }
    }
    else
    {
        if(!isGameStarted)
            return;
        
        BallMovement();
    }
}

void Ball()
{
    if(isGameStarted && !isGameEnded)
    {
        // DrawRectangleRounded({ballPosX, ballPosY, ballWidth, ballHeight}, 100.0f, 100, ballColor);
        DrawRectangle(ballPosX, ballPosY, ballWidth, ballHeight, ballColor);
        return;
    }

    BlurEffect(ballPosX, ballPosY, ballWidth, ballHeight, ballColor);
}

void BallMovement()
{
    if (isCollidedHorizontally)
    {
        ballcurrentTime = ballcurrentTime + ballelapsedTime;
        if (ballcurrentTime >= balldelayTime)
        {
            ballSpeedX = ballSpeedX / speedIncreasedFactor;
            ballSpeedY = ballSpeedY / speedIncreasedFactor;
            ballcurrentTime = 0.0f;
            resetSpeed = true;
        }
        else if(abs(ballSpeedX) >= 500.0f && ballSpeedX > 0)
        {
            ballSpeedX = abs(ballSpeed);
            ballSpeedY = abs(ballSpeed);
            ballcurrentTime = 0.0f;
            resetSpeed = true;
        }

        else if(abs(ballSpeedX) >= 500.0f && ballSpeedX < 0)
        {
            ballSpeedX = ballSpeed;
            ballSpeedY = abs(ballSpeed);
            ballcurrentTime = 0.0f;
            resetSpeed = true;
        }

        if (resetSpeed)
        {
            isCollidedHorizontally = false;
            resetSpeed = false;
        }
    }
    
    float newballPosX = ballPosX + ballSpeedX * GetFrameTime();
    // float newballPosX = ballPosX + ballSpeedX * GetFrameTime() * cosf(ballAngle * DEG2RAD);
    if (ballPosX < 0 || ballPosX + ballWidth > WIDTH)
    {
        ballPosX = Clamp(ballPosX, 0.0f, ballPosX + ballWidth);
        ballPosX = Clamp(ballPosX, ballPosX - ballWidth, (float)WIDTH - ballWidth);
        ballSpeedX = -ballSpeedX;
        newballPosX = ballPosX + ballSpeedX * GetFrameTime();
        // newballPosX = ballPosX + ballSpeedX * GetFrameTime() * cosf(ballAngle * DEG2RAD);
    }
    ballPosX = newballPosX;

    float newballPosY = ballPosY + ballSpeedY * GetFrameTime();
    // float newballPosY = ballPosY + ballSpeedY * GetFrameTime() * sinf(ballAngle * DEG2RAD);
    if (ballPosY < 0 || ballPosY + ballHeight > HEIGHT)
    {
        ballPosY = Clamp(ballPosY, 0.0f, ballPosY + ballHeight);
        ballPosY = Clamp(ballPosY, ballPosY - ballHeight, (float)HEIGHT - ballHeight);
        ballSpeedY = -ballSpeedY;
        newballPosY = ballPosY + ballSpeedY * GetFrameTime();
        // newballPosY = ballPosY + ballSpeedY * GetFrameTime() * sinf(ballAngle * DEG2RAD);
    }
    ballPosY = newballPosY;

    // GenerateParticles(ballColor, {ballPosX, ballPosY}, false, 2);

    if (ballPosY + ballHeight >= HEIGHT /*paddlePosY + paddleHeight + 50*/)
    {
        livesLeft--;
        GenerateParticles(ballColor, {ballPosX, ballPosY}, false, maxParticles);
        if (!IsSoundPlaying(ballBreakSound))
        {
            PlaySound(ballBreakSound);
        }

        if(livesLeft > 0)
        {
            livesrects.pop_back();
            ballReset = true;
            ballPosX = (paddlePosX + paddleWidth * 0.5f - ballWidth * 0.5f);
            ballPosY = (paddlePosY - paddleHeight * 0.5f - ballHeight * 0.5f) - ballGap;
            ballSpeedX = ballSpeedY = ballSpeed;
        }
        else
        {
            isGameOver = true;
            isGameEnded = true;
        }
    }
}


//! Checking rectangles intersections function - collision detection (AABB) - STARTS
bool checkIntersectionX(const Rectangle& rect1, const Rectangle& rect2) {
    float left1 = rect1.x;
    float right1 = rect1.x + rect1.width;

    float left2 = rect2.x;
    float right2 = rect2.x + rect2.width;

    bool intersectX = !((right1 < left2) || (right2 < left1));

    return intersectX ;
}

bool checkIntersectionY(const Rectangle& rect1, const Rectangle& rect2) {
    float top1 = rect1.y;
    float bottom1 = rect1.y + rect1.height;

    float top2 = rect2.y;
    float bottom2 = rect2.y + rect2.height;

    bool intersectY = !((bottom1 < top2) || (bottom2 < top1));

    return intersectY;
}


bool checkIntersection(const Rectangle& rect1, const Rectangle& rect2) {
    float left1 = rect1.x;
    float right1 = rect1.x + rect1.width;
    float top1 = rect1.y;
    float bottom1 = rect1.y + rect1.height;

    float left2 = rect2.x;
    float right2 = rect2.x + rect2.width;
    float top2 = rect2.y;
    float bottom2 = rect2.y + rect2.height;

    // Check for intersection along both axes
    bool intersectX = !((right1 < left2) || (right2 < left1));
    bool intersectY = !((bottom1 < top2) || (bottom2 < top1));

    // If both axes have intersection, then there is overall intersection
    return intersectX && intersectY;
}

//! Checking rectangles intersections function - collision detection (AABB) - ENDS


void BallCollisionWithPaddle()
{
    Rectangle rect1, rect2;
    rect1.x = ballPosX;
    rect1.y = ballPosY;
    rect1.width = ballWidth;
    rect1.height = ballHeight;

    rect2.x = paddlePosX;
    rect2.y = paddlePosY;
    rect2.width = paddleWidth;
    rect2.height = paddleHeight;

    float newballPosX = ballPosX + ballSpeedX * GetFrameTime();
    // float newballPosX = ballPosX + ballSpeedX * GetFrameTime() * cosf(ballAngle * DEG2RAD);
    rect1.x = newballPosX;
    if(checkIntersection(rect1,rect2) && checkIntersectionX(rect1, rect2) 
       /* ((ballPosX + ballWidth > paddlePosX) || 
        (ballPosX < paddlePosX + paddleWidth)) */)
    {
        if((isPaddleDirLeft && ballSpeedX > 0) || (isPaddleDirRight && ballSpeedX < 0))
        {
            ballSpeedX = -(speedIncreasedFactor * ballSpeedX);
        }
        else if((isPaddleDirLeft && ballSpeedX < 0) || (isPaddleDirRight && ballSpeedX > 0))
        {
            ballSpeedX = (speedIncreasedFactor * ballSpeedX);
        }
        else
        {
            ballSpeedX = -(speedIncreasedFactor * ballSpeedX);
        }
        // ballSpeedX = -(speedIncreasedFactor * ballSpeedX);
        ballSpeedY = speedIncreasedFactor * ballSpeedY;
        isCollidedHorizontally = true;
        Color particleGradientColor = GetLerpedGradientColor(paddleColorFirst, paddleColorSecond, 0.12f);
        GenerateParticles(particleGradientColor, {paddlePosX, paddlePosY}, true, maxParticles);
        
        if (!IsSoundPlaying(paddleHitSound))
        {
            PlaySound(paddleHitSound);
        }

        // return;
    }

    float newballPosY = ballPosY + ballSpeedY * GetFrameTime();
    // float newballPosY = ballPosY + ballSpeedY * GetFrameTime() * sinf(ballAngle * DEG2RAD);
    rect1.y = newballPosY;
    if(checkIntersection(rect1, rect2) && checkIntersectionY(rect1, rect2)
       /* ((ballPosY + ballHeight > paddlePosY) || 
        (ballPosY < paddlePosY + paddleHeight)) */)
    {
        if ((isPaddleDirLeft && ballSpeedX > 0) || (isPaddleDirRight && ballSpeedX < 0))
        {
            ballSpeedX = -ballSpeedX;
        }

        ballSpeedY = -ballSpeedY;
        Color particleGradientColor = GetLerpedGradientColor(paddleColorFirst, paddleColorSecond, 0.12f);
        GenerateParticles(particleGradientColor, {paddlePosX, paddlePosY}, true, maxParticles);

        if (!IsSoundPlaying(paddleHitSound))
        {
            PlaySound(paddleHitSound);
        }
    }
}

void BallCollisionWithTiles()
{
    for (int i = 0; i < TILESROW; i++)
    {
        for (int j = 0; j < TILESCOL; j++)
        {
            bool isCollided = false;

            if (tiles[i][j].isAlive)
            {
                Vector2 tilePos = tiles[i][j].pos;

                Rectangle rect1, rect2;
                rect1.x = ballPosX;
                rect1.y = ballPosY;
                rect1.width = ballWidth;
                rect1.height = ballHeight;

                rect2.x = tilePos.x;
                rect2.y = tilePos.y;
                rect2.width = tileWidth;
                rect2.height = tileHeight;

                float newballPosX = ballPosX + ballSpeedX * GetFrameTime();
                rect1.x = newballPosX;
                if (checkIntersection(rect1,rect2) && 
                ((ballPosX + ballWidth > tilePos.x) || 
                 (ballPosX < tilePos.x + tileWidth)))
                {
                    ballSpeedX = -ballSpeedX;
                    isCollided = true;
                }

                float newballPosY = ballPosY + ballSpeedY * GetFrameTime();
                rect1.y = newballPosY;
                if (checkIntersection(rect1, rect2) && 
                ((ballPosY + ballHeight > tilePos.y) || 
                 (ballPosY < tilePos.y + tileHeight)))
                {
                    ballSpeedY = -ballSpeedY;
                    isCollided = true;
                }
                

                if (isCollided)
                {
                    if (tiles[i][j].hitsLeft < 2)
                    {
                        // direction -> true means downwards and false means upwards... 
                        bool direction = ballSpeedY > 0 ? false : true;
                        tiles[i][j].isAlive = false;
                        Color tileColor = tiles[i][j].color;
                        tileColor.a = 255;
                        if (!IsSoundPlaying(tileBreakSound))
                        {
                            PlaySound(tileBreakSound);
                        }
                        // Generate Particles
                        GenerateParticles(tileColor, tilePos, direction, maxParticles);

                        if (i >= 0 && i <= 2)
                            score += 300;
                        else if (i >= 3 && i <= 6)
                            score += 200;
                        else
                            score += 100;
                    }
                    else
                    {
                        if (!IsSoundPlaying(tileHitSound))
                        {
                            PlaySound(tileHitSound);
                        }
                    }

                    
                    tiles[i][j].color.a -= 55;
                    tiles[i][j].hitsLeft--;
                }


                if(isCollided)
                {
                    return;
                }
            }
        }
    }

}

void InitializeTiles()
{
    float posX = (WIDTH - ((tileWidth * TILESCOL) + 30.0f * (TILESCOL - 1))) * 0.5f;
    float posY = 50.0f;
    
    for (int i = 0; i < TILESROW; i++)
    {
        for (int j = 0; j < TILESCOL; j++)
        {
            Vector2 tilePos = {posX, posY};
            bool tilePresent = true;
            int hits = 0;
            if (i >= 0 && i <= 2)
            {
                hits = 3;
            }
            else if (i >= 3 && i <= 6)
            {
                hits = 2;
            }
            else
            {
                hits = 1;
            }
            Tile tile = {tilePresent, tilePos, brickRowColor[i], hits};
            tiles[i].push_back(tile);
            posX += tileWidth + 30.0f;
        }

        posX = (WIDTH - ((tileWidth * TILESCOL) + 30.0f * (TILESCOL - 1))) * 0.5f;
        posY += tileHeight + 15.0f;
    }
}

void DrawTiles()
{
    if(isGameStarted && !isGameEnded)
    {
        for (int i = 0; i < TILESROW; i++)
        {
            for (int j = 0; j < TILESCOL; j++)
            {
                if (tiles[i][j].isAlive)
                {
                    DrawRectangle(tiles[i][j].pos.x, tiles[i][j].pos.y, tileWidth, tileHeight, tiles[i][j].color);
                }
            }
        }
        return;
    }

    if(!gameStartedFirstTime)
    {
        for (int i = 0; i < TILESROW; i++)
        {
            for (int j = 0; j < TILESCOL; j++)
            {
                if (tiles[i][j].isAlive)
                {
                    BlurEffect(tiles[i][j].pos.x, tiles[i][j].pos.y, tileWidth, tileHeight, tiles[i][j].color);
                }
            }
        }
    }
}

void ScreenResized()
{
    if (IsWindowResized() && GetScreenWidth() >= 700)
    {
        int newWidth = GetScreenWidth();
        int newHeight = GetScreenHeight();

        paddlePosX = paddlePosX / WIDTH * newWidth;
        paddlePosY = paddlePosY / HEIGHT * newHeight;

        ballPosX = ballPosX / WIDTH * newWidth;
        ballPosY = ballPosY / HEIGHT * newHeight;

        for (int i = 0; i < TILESROW; i++)
        {
            for (int j = 0; j < TILESCOL; j++)
            {
                if (tiles[i][j].isAlive)
                {
                    tiles[i][j].pos.x = tiles[i][j].pos.x / WIDTH * newWidth;
                    tiles[i][j].pos.y = tiles[i][j].pos.y / HEIGHT * newHeight;
                }
            }
        }

        for (int i = 0; i < livesrects.size(); i++)
        {
            livesrects[i].pos.x = livesrects[i].pos.x / WIDTH * newWidth;
            livesrects[i].pos.y = livesrects[i].pos.y / HEIGHT * newHeight;
        }

        WIDTH = newWidth;
        HEIGHT = newHeight;
    }
}


void RenderScore()
{
    const char *text = "Score: ";
    int textWidth =  MeasureText(text, 30);
    if(isGameStarted && !isGameEnded)
    {
        // DrawText(TextFormat("Score: %i", score), 10, 10, 20, RED);
        DrawTextEx(font,TextFormat("%s%i", text, score),{20.0f, 10.0f}, 25.0f, 0, RED);
        return;
    }

    BlurEffect(font,TextFormat("%s%i", text, score),{20.0f, 10.0f}, 25.0f, 0, RED);
}

void RenderHighScore()
{
    const char *text = "Highscore: ";
    int textWidth =  MeasureText(text, 30);
    if(isGameStarted && !isGameEnded)
    {
        // DrawText(TextFormat("%s%i", text, highscore), WIDTH - textWidth - 60, 10, 20, YELLOW);
        DrawTextEx(font, TextFormat("%s%i", text, highscore), {(float)(WIDTH - textWidth - 90), 10}, 25, 0, YELLOW);
        return;
    }

    BlurEffect(font, TextFormat("%s%i", text, highscore), {(float)(WIDTH - textWidth - 90), 10.0f}, 25, 0, YELLOW);
}


void GameStartScreen()
{
    static Color animColor = /* { 40, 40, 40, 255 } */ {220, 220, 220, 255};
    static float startingValue = animColor.a;
    static float endingValue = 160.0f /* 200.0f */;
    static float currentValue = startingValue;
    static float timeToDecrease = 3.0f;
    static float progress = 0.0f;

    static Color textColor = {230, 41, 55, 0};
    static float textstartingValue = textColor.a;
    static float textendingValue = 255.0f;
    static float textcurrentValue = startingValue;
    static float texttimeToDecrease = 2.0f;
    static float textprogress = 0.0f;

    static string textStr = "Please select a level";
    // static char *text = "Press Space Key to Start";
    static const char *text = textStr.c_str();
    static int textWidth = MeasureText(text, 40);

    // levels strings
    // static string level1TextStr = "Level 1";
    // static const char *level1Text = level1TextStr.c_str();
    // static int textWidth = MeasureText(text, 40);



    


    if(!isAnimationCancelled)
    {
        if (gameStartScreenAnimation && Animation(startingValue, endingValue, progress, timeToDecrease, gameStartScreenAnimation, animColor))
        {
            DrawRectangle(0, 0, WIDTH, HEIGHT, animColor);
        }
        else
        {
            DrawRectangle(0, 0, WIDTH, HEIGHT, animColor);
            // DrawText(TextFormat(text), WIDTH * 0.5f-textWidth * 0.5f, HEIGHT * 0.5f, 40, RED);
            if (gameStartScreenAnimationText && Animation(textstartingValue, textendingValue, textprogress, texttimeToDecrease, gameStartScreenAnimationText, textColor))
            {
                // DrawTextEx(font, TextFormat(text), {WIDTH * 0.5f - textWidth * 0.5f, HEIGHT * 0.5f}, 40, 0, textColor);
                DrawTextEx(font, TextFormat(text), {WIDTH * 0.5f - textWidth * 0.5f, HEIGHT * 0.10f}, 40, 0, textColor);

                DrawRectangle(WIDTH * 0.5f - 270.0f * 0.5f, HEIGHT * 0.25f, 200, 50, WHITE);
                DrawTextEx(font, TextFormat(text), {WIDTH * 0.5f - textWidth * 0.5f, HEIGHT * 0.10f}, 40, 0, textColor);
            }
            else
            {
                textColor.a = 255;
                DrawTextEx(font, TextFormat(text), {WIDTH * 0.5f - textWidth * 0.5f, HEIGHT * 0.10f}, 40, 0, textColor);
                DrawRectangle(WIDTH * 0.5f - 270.0f * 0.5f, HEIGHT * 0.25f, 200, 50, WHITE);
            }
        }
    }
    else
    {
        animColor.a = 160 /* 200 */;
        DrawRectangle(0, 0, WIDTH, HEIGHT, animColor);
        textColor.a = 255;
        DrawTextEx(font, TextFormat(text), {WIDTH * 0.5f - textWidth * 0.5f, HEIGHT * 0.5f}, 40, 0, textColor); 
    }
}


void GameOverScreen()
{  
    DrawRectangleGradientV(0, 0, WIDTH, HEIGHT, {50, 50, 230, 50}, {200, 122, 255, 255});
    const char *gameOverText = "Game Over";
    int gameOverTextWidth =  MeasureText(gameOverText, 40);
    // DrawText(TextFormat(gameOverText), WIDTH * 0.5f-gameOverTextWidth * 0.5f, HEIGHT * 0.5f - 200, 40, RED);
    DrawTextEx(font, TextFormat(gameOverText), {WIDTH * 0.5f-gameOverTextWidth * 0.5f, HEIGHT * 0.5f - 200}, 40, 0, RED);
    const char *scoreText = "Your Score :";
    int scoreTextWidth =  MeasureText(scoreText, 40);
    int scoreWidth = MeasureText(to_string(score).c_str(), 40);
    // DrawText(TextFormat("%s %d", scoreText, score), WIDTH * 0.5f-scoreTextWidth * 0.5f - scoreWidth * 0.5f, HEIGHT * 0.5f - 100, 40, RED);
    DrawTextEx(font, TextFormat("%s %d", scoreText, score), {WIDTH * 0.5f-scoreTextWidth * 0.5f - scoreWidth * 0.5f, HEIGHT * 0.5f - 100}, 40, 0, RED);
    const char *restartText = "Press 'Enter' Key to Restart Game";
    int restartTextWidth =  MeasureText(restartText, 40);
    // DrawText(TextFormat(restartText), WIDTH * 0.5f-restartTextWidth * 0.5f, HEIGHT * 0.5f, 40, RED);
    DrawTextEx(font, TextFormat(restartText), {WIDTH * 0.5f-restartTextWidth * 0.5f, HEIGHT * 0.5f}, 40, 0, RED);
}

void GameWonScreen()
{  
    DrawRectangleGradientV(0, 0, WIDTH, HEIGHT, {50, 50, 230, 50}, {200, 122, 255, 255});
    const char *gameOverText = "YOU WIN";
    int gameOverTextWidth =  MeasureText(gameOverText, 40);
    // DrawText(TextFormat(gameOverText), WIDTH * 0.5f-gameOverTextWidth * 0.5f, HEIGHT * 0.5f - 200, 40, RED);
    DrawTextEx(font, TextFormat(gameOverText), {WIDTH * 0.5f-gameOverTextWidth * 0.5f, HEIGHT * 0.5f - 200}, 40, 0, RED);
    const char *scoreText = "Your Score :";
    int scoreTextWidth =  MeasureText(scoreText, 40);
    int scoreWidth = MeasureText(to_string(score).c_str(), 40);
    // DrawText(TextFormat("%s %d", scoreText, score), WIDTH * 0.5f-scoreTextWidth * 0.5f - scoreWidth * 0.5f, HEIGHT * 0.5f - 100, 40, RED);
    DrawTextEx(font, TextFormat("%s %d", scoreText, score), {WIDTH * 0.5f-scoreTextWidth * 0.5f - scoreWidth * 0.5f, HEIGHT * 0.5f - 100}, 40, 0, RED);
    const char *restartText = "Press 'Enter' Key to Restart Game";
    int restartTextWidth =  MeasureText(restartText, 40);
    // DrawText(TextFormat(restartText), WIDTH * 0.5f-restartTextWidth * 0.5f, HEIGHT * 0.5f, 40, RED);
    DrawTextEx(font, TextFormat(restartText), {WIDTH * 0.5f-restartTextWidth * 0.5f, HEIGHT * 0.5f}, 40, 0, RED);
}


void IsGameWon()
{
    for (int i = 0; i < TILESROW; i++)
    {
        for (int j = 0; j < TILESCOL; j++)
        {
            if (tiles[i][j].isAlive)
            {
                isGameWon = false;
                return;
            }
        }
    }

    gameWonScreenAnimation = gameWonScreenAnimationText = true;
    isGameEnded = true;
    isGameWon = true;
}


void GameReset()
{
    livesLeft = 4;

    if(highscore < score)
    {
        highscore = score;
    }

    score = 0;

    ballPosX = paddlePosX + paddleWidth * 0.5f - ballWidth * 0.5f;
    ballPosY = paddlePosY - paddleHeight * 0.5f - ballHeight * 0.5f - ballGap;
    ballSpeedX = ballSpeedY = ballSpeed;
    if(GetRandomValue(0,1))
        ballSpeedX = -ballSpeedX;

    livesrects.clear();
    particles.clear();
    brickRowColor.clear();

    for (int i = 0; i < TILESROW; i++)
    {
        tiles[i].clear();
    }

    InitializeBrickColors();
    InitializeTiles();
    InitializeLifeRects();
    ParticleInit();
    ResetGameState();
}

void Lives()
{
    int fontSize = 22;
    const char *text = "Lives : ";
    const int textWidth = MeasureText(text, fontSize);
    float textPosX = (320 + ballWidth - ((ballWidth * 3) + 15.0f * (3 - 1))) * 0.5f;
    float textPosY = HEIGHT - 30.0f;
    if(livesrects.size() > 1)
    {
        textPosX = livesrects[0].pos.x;
        textPosY = livesrects[0].pos.y;
    }
    
    if(isGameStarted && !isGameEnded)
    {
        // DrawText(TextFormat(text), 20, HEIGHT - 30, fontSize, MAROON);
        DrawTextEx(font, TextFormat(text), {textPosX - textWidth - 20.0f, textPosY}, fontSize, 2.0f, ORANGE);
        DrawLiveRects();
        return;
    }

    BlurEffect(font, TextFormat(text), {textPosX - textWidth - 20.0f, textPosY}, fontSize, 2.0f, ORANGE);
    DrawLiveRects();
}

void InitializeLifeRects()
{
    float posX = (320 + ballWidth - ((ballWidth * 3) + 15.0f * (3 - 1))) * 0.5f;
    float posY = HEIGHT - 30;

    for (int i = 0; i < 3; i++)
    {
        Vector2 liveRectPos = {posX, posY};
        LifeRects liveRect = {liveRectPos, BLACK};
        livesrects.push_back(liveRect);
        posX += ballWidth + 15.0f;
    }
}

void DrawLiveRects()
{
    if(isGameStarted && !isGameEnded)
    {
        for (int i = 0; i < livesrects.size(); i++)
        {
            DrawRectangle(livesrects[i].pos.x, livesrects[i].pos.y, ballWidth, ballHeight, livesrects[i].color);
        }
        return;
    }

    for (int i = 0; i < livesrects.size(); i++)
    {
        BlurEffect(livesrects[i].pos.x, livesrects[i].pos.y, ballWidth, ballHeight, livesrects[i].color);
    }
}


// --------------------------------------------------------------------------------------------------------------
// ! Functions for creating Color lerp to provide smoother transition of colors between tiles - starts 

Vector4 Vector4Lerp(Vector4 a, Vector4 b, float t) {
    return Vector4{
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t,
        a.w + (b.w - a.w) * t
    };
}


Vector4 srgb_to_linear(Vector4 color) {
    return Vector4{
        (color.x <= 0.04045f) ? (color.x / 12.92f) : pow((color.x + 0.055f) / 1.055f, 2.4f),
        (color.y <= 0.04045f) ? (color.y / 12.92f) : pow((color.y + 0.055f) / 1.055f, 2.4f),
        (color.z <= 0.04045f) ? (color.z / 12.92f) : pow((color.z + 0.055f) / 1.055f, 2.4f),
        color.w
    };
}

Vector4 linear_to_srgb(Vector4 color) {
    return Vector4{
        (color.x <= 0.0031308f) ? (color.x * 12.92f) : (1.055f * pow(color.x, 1.0f / 2.4f) - 0.055f),
        (color.y <= 0.0031308f) ? (color.y * 12.92f) : (1.055f * pow(color.y, 1.0f / 2.4f) - 0.055f),
        (color.z <= 0.0031308f) ? (color.z * 12.92f) : (1.055f * pow(color.z, 1.0f / 2.4f) - 0.055f),
        color.w
    };
}

Color GetLerpedGradientColor(Color start, Color end, float t)
{
    Vector4 ColorStart = ColorNormalize(start);
    Vector4 ColorEnd = ColorNormalize(end);
    Vector4 gradientColorVec4 = Vector4Lerp(ColorStart, ColorEnd, t);
    gradientColorVec4 = srgb_to_linear(gradientColorVec4);
    Color gradientColor = ColorFromNormalized(gradientColorVec4);
    return gradientColor;
}

// ! Functions for creating Color lerp to provide smoother transition of colors between tiles - ends

// --------------------------------------------------------------------------------------------------------------

//! Particle system functions - starts
float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}
 
int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}
 
float randomFloat(int a, int b)
{
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;
 
    return (float)randomInt(a, b) + randomFloat();
}


void ParticleInit()
{
    int size = maxParticles;
    for (int i = 0; i < size; i++)
    {
        Vector2 pos = {50, 50};
        Size size = {GetRandomValue(minSizeValue,maxSizeValue), GetRandomValue(minSizeValue,maxSizeValue)};
        Color color = RED;
        float lifeTime = randomFloat(minLifetimeValue, maxLifetimeValue);
        Vector2 speed = {randomFloat(particleMinSpeed, particleMaxSpeed), randomFloat(particleMinSpeed, particleMaxSpeed)};
        float angle = 0;
        bool isAlive = false;
        Particle particle = {
            lifeTime,
            speed,
            pos,
            size,
            color,
            angle,
            isAlive,
            0.0f,
        };

        particles.push_back(particle);
    }

    particles.reserve(1024);
}

void DrawParticles()
{
    if(isGameStarted && !isGameEnded)
    {
        for (int i = 0; i < particles.size(); i++)
        {
            if(particles[i].isAlive)
            {
                DrawRectangle(particles[i].pos.x, particles[i].pos.y, particles[i].size.w, particles[i].size.h, particles[i].color);
                // DrawRectangleRounded({particles[i].pos.x, particles[i].pos.y, (float)particles[i].size.w, (float)particles[i].size.h},100.0f, 10, particles[i].color);
            }
        }
        return;
    }

    for (int i = 0; i < particles.size(); i++)
    {
        if (particles[i].isAlive)
        {
            DrawRectangle(particles[i].pos.x, particles[i].pos.y, particles[i].size.w, particles[i].size.h, particles[i].color);
        }
    }
}

void MoveParticles()
{
    if(generateParticles)
    {
        if(isGameStarted)
        {
            for (int i = 0; i < particles.size(); i++)
            {
            
                if(particles[i].isAlive && particles[i].currentLifeTime < particles[i].lifetime /* particles[i].lifetime >= 0 */)
                {
                    particles[i].currentLifeTime += GetFrameTime();
                    float alpha = particles[i].currentLifeTime / particles[i].lifetime;
                    // float easedAlpha = 1.0f - (alpha - 1.0f) * (alpha - 1.0f);
                    float easedAlpha =  /* (alpha - 1.0f) * */ 1.0f - (alpha - 1.0f) * (alpha - 1.0f) /* + 1.0f */ ;
                    
                    particles[i].color.a = (unsigned char)(255 * (1.0f - easedAlpha));

                    float newparticlesPosX = particles[i].pos.x + particles[i].speed.x * GetFrameTime() * cosf(particles[i].angle * DEG2RAD);
                    if (particles[i].pos.x < 0 || particles[i].pos.x + particles[i].size.w > WIDTH)
                    {
                        particles[i].speed.x = -particles[i].speed.x;
                        newparticlesPosX = particles[i].pos.x + particles[i].speed.x * GetFrameTime() * cosf(particles[i].angle * DEG2RAD);
                    }

                    float newparticlesPosY = particles[i].pos.y + particles[i].speed.y * GetFrameTime() * sinf(particles[i].angle * DEG2RAD);
                    if (particles[i].pos.y < 0 || particles[i].pos.y + particles[i].size.h > HEIGHT)
                    {
                        particles[i].speed.y = -particles[i].speed.y;
                        newparticlesPosY = particles[i].pos.y + particles[i].speed.y * GetFrameTime() * sinf(particles[i].angle * DEG2RAD);
                    }

                    particles[i].pos.x = newparticlesPosX;
                    particles[i].pos.y = newparticlesPosY;
                }
                else
                {
                    particles.erase(particles.begin() + i);
                }
            }
        }

        DrawParticles();
    }
}


void GenerateParticles(Color tileColor, Vector2 tilePos, bool direction, int noOfParticles)
{
    generateParticles = true;
    int totalParticles = min(noOfParticles, maxParticles);

    for (int i = 0; i < totalParticles; i++)
    {
        Vector2 pos = tilePos;
        pos.x += 3.0f;
        pos.y += 3.0f;
        int particleSide = GetRandomValue(minSizeValue, maxSizeValue);
        Size size = {particleSide, particleSide};
        Color color = tileColor;
        float lifeTime = randomFloat(minLifetimeValue, maxLifetimeValue);
        float particleSpeed = randomFloat(particleMinSpeed, particleMaxSpeed);
        Vector2 speed = {randomFloat(particleMinSpeed, particleMaxSpeed), randomFloat(particleMinSpeed, particleMaxSpeed)};
        float angle;
        if(direction)
        {
            int random = GetRandomValue(1, 4);
            switch (random)
            {
            case 1:
                angle = randomFloat(particleMinAngle, particleMaxAngle);
                break;
            case 2:
                angle = randomFloat(-particleMinAngle, particleMaxAngle);
                break;
            case 3:
                angle = randomFloat(particleMinAngle, -particleMaxAngle);
                break;
            case 4:
                angle = randomFloat(-particleMinAngle, -particleMaxAngle);
                break;
            } 
        }
        else
        {
            int random = GetRandomValue(1, 4);
            switch (random)
            {
            case 1:
                angle = randomFloat(particleMinAngle, particleMaxAngle);
                break;
            case 2:
                angle = randomFloat(-particleMinAngle, particleMaxAngle);
                break;
            case 3:
                angle = randomFloat(particleMinAngle, -particleMaxAngle);
                break;
            case 4:
                angle = randomFloat(-particleMinAngle, -particleMaxAngle);
                break;
            } 
        }
        bool isAlive = true;

        Particle particle = {
            lifeTime,
            speed,
            pos,
            size,
            color,
            angle,
            isAlive,
            0.0f
        };

        particles.push_back(particle);
    }
}


void ParticleCollisionWithTiles()
{
    Rectangle rect1, rect2, rect3;
    for (int k = 0; k < particles.size(); k++)
    {
        for (int i = 0; i < TILESROW; i++)
        {
            for (int j = 0; j < TILESCOL; j++)
            {
                if (tiles[i][j].isAlive)
                {
                    Vector2 tilePos = tiles[i][j].pos;

                    rect1.x = particles[k].pos.x;
                    rect1.y = particles[k].pos.y;
                    rect1.width = particles[k].size.w;
                    rect1.height = particles[k].size.h;

                    rect2.x = tilePos.x;
                    rect2.y = tilePos.y;
                    rect2.width = tileWidth;
                    rect2.height = tileHeight;

                    float newparticlesPosX = particles[k].pos.x + particles[k].speed.x * GetFrameTime() * cosf(particles[k].angle * DEG2RAD);
                    rect1.x = newparticlesPosX;
                    if(checkIntersection(rect1,rect2) &&
                    ((particles[k].pos.x + particles[k].size.w > tilePos.x) ||
                    (particles[k].pos.x < tilePos.x + tileWidth)))
                    {
                        particles[k].speed.x = -particles[k].speed.x;
                    }


                    float newparticlesPosY = particles[k].pos.y + particles[k].speed.y * GetFrameTime() * sinf(particles[k].angle * DEG2RAD);
                    rect1.y = newparticlesPosY;
                    if(checkIntersection(rect1,rect2) &&
                    ((particles[k].pos.y + particles[k].size.h > tilePos.y) ||
                    (particles[k].pos.y < tilePos.y + tileHeight)))
                    {
                        particles[k].speed.y = -particles[k].speed.y;
                    }
                }
            }
        }
    }
    
}

//! Particle system functions - ends

// --------------------------------------------------------------------------------------------------------------

//! Game main loop - starts 

void UpdateDrawFrame(void)
{
    UpdateMusicStream(gameMusic);
    BeginDrawing();

    ClearBackground(backgroundColor);

    if(!isGameOver && !isGameWon)
        GameState();

    if(isGameOver)
    {
        maxParticles = 40;
        static float delayGO = 2.0f;
        static float currentTimeGO = 0.0f;

        static float fullAnimNotCompletedGO = true;

        if(IsMusicStreamPlaying(gameMusic))
            StopMusicStream(gameMusic);

        if(gameOverScreenAnimation || gameOverScreenAnimationText || fullAnimNotCompletedGO)
        {
            GameGradientBackground();
            ScreenResized();
            RenderScore();
            RenderHighScore();
            Ball();
            Paddle();
            MoveParticles();
            DrawTiles();
            DrawParticles();
            Lives();
            DrawFPS(WIDTH - 75, HEIGHT - 20);
        }

        if(!GameOverAnimation(fullAnimNotCompletedGO))
        {
            fullAnimNotCompletedGO = !(Delay(currentTimeGO, delayGO));
            if(!fullAnimNotCompletedGO)
            {
                GameOverScreen();
                bool touchStartGameInput = TouchStartGameInput();

                if (IsKeyPressed(KEY_ENTER) || touchStartGameInput)
                {
                    currentTimeGO = 0.0f;
                    fullAnimNotCompletedGO = true;
                    isGameWon = false;
                    GameReset();
                }
            }
        }
        EndDrawing();
        return;
    }
    
    if(isGameWon)
    {
        maxParticles = 40;
        static float delayGW = 2.0f;
        static float currentTimeGW = 0.0f;

        static float fullAnimNotCompletedGW = true;

        if(IsMusicStreamPlaying(gameMusic))
            StopMusicStream(gameMusic);

        if(gameWonScreenAnimation || gameWonScreenAnimationText || fullAnimNotCompletedGW)
        {
            GameGradientBackground();
            ScreenResized();
            RenderScore();
            RenderHighScore();
            Ball();
            Paddle();
            MoveParticles();
            DrawTiles();
            DrawParticles();
            Lives();
            DrawFPS(WIDTH - 75, HEIGHT - 20);
        }

        if(!GameWonAnimation(fullAnimNotCompletedGW))
        {
            fullAnimNotCompletedGW = !(Delay(currentTimeGW, delayGW));
            if(!fullAnimNotCompletedGW)
            {
                if(IsSoundPlaying(gameWonSound))
                    StopSound(gameWonSound);
                GameWonScreen();
                bool touchStartGameInput = TouchStartGameInput();

                if (IsKeyPressed(KEY_ENTER) || touchStartGameInput)
                {
                    currentTimeGW = 0.0f;
                    fullAnimNotCompletedGW = true;
                    isGameWon = false;
                    GameReset();
                }
            }
        }
    
        EndDrawing();
        return;
    }

    if (isGameStarted)
    {
        // if(IsSoundReady(gameMusic) && !IsSoundPlaying(gameMusic))
            // ResumeSound(gameMusic);

        ResumeMusicStream(gameMusic);

        // DrawRectangleGradientV(0, 0, WIDTH, HEIGHT, BLACK, {100,100,100,100});
        GameGradientBackground();
        IsGameWon();
        ScreenResized();
        userInput();
        BallReset(); //* BallReset() function is calling BallMovement() function
        BallCollisionWithPaddle();
        BallCollisionWithTiles();
        ParticleCollisionWithTiles();
        RenderScore();
        RenderHighScore();
        Ball();
        Paddle();
        MoveParticles();
        DrawTiles();
        DrawParticles();
        Lives();
        DrawFPS(WIDTH - 75, HEIGHT - 20);
        // GameStartScreen();
    }
    else
    {
        // if(IsSoundPlaying(gameMusic))
            // PauseSound(gameMusic);

        PauseMusicStream(gameMusic);

        // DrawRectangleGradientV(0, 0, WIDTH, HEIGHT, BLACK, {100,100,100,100});
        GameGradientBackground();
        ScreenResized();
        BallReset(); //* BallReset() function is calling BallMovement() function
        RenderScore();
        RenderHighScore();
        Ball();
        Paddle();
        MoveParticles();
        DrawTiles();
        DrawParticles();
        Lives();
        DrawFPS(WIDTH - 75, HEIGHT - 20);
        GameStartScreen();
    }

    EndDrawing();
    elapsedTime = GetFrameTime();
    ballelapsedTime = GetFrameTime();
}

//! Game main loop - ends