#include <windows.h>
#include "utilities.cpp"
#include "Sudoku.h"
#include <iostream>

struct GameState
{
    bool running;
    int height, width, size;
    int xPos, yPos;
    void* memory;
    BITMAPINFO bitmap_info;
    Sudoku sudokuGame = Sudoku();
};
GameState gameState;

#include "renderer.cpp"

LRESULT CALLBACK SudokuGameProcedure(HWND hWindowHandle, UINT Message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch(Message)
    {
        case WM_CREATE:
        {
            gameState.sudokuGame.startGame();
            break;
        }

        case WM_MOUSEMOVE:
        {
            gameState.xPos = (int)(short)LOWORD(lParam);
            gameState.xPos = (int)(short)HIWORD(lParam);
            break;
        }

        case WM_KEYDOWN:
        {
            break;
        }

        case WM_SIZE:
        {
            RECT rect;
            GetClientRect(hWindowHandle, &rect);
            gameState.width = rect.right - rect.left;
            gameState.height = rect.bottom - rect.top;
            gameState.size = gameState.width * gameState.height * sizeof(size_t);

            if(gameState.memory)
                VirtualFree(gameState.memory, 0, MEM_RELEASE);
            gameState.memory = VirtualAlloc(0, gameState.size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            
            gameState.bitmap_info.bmiHeader.biSize = sizeof(gameState.bitmap_info.bmiHeader);
            gameState.bitmap_info.bmiHeader.biWidth = gameState.width;
            gameState.bitmap_info.bmiHeader.biHeight = gameState.height;
            gameState.bitmap_info.bmiHeader.biPlanes = 1;
            gameState.bitmap_info.bmiHeader.biBitCount = 32;
            gameState.bitmap_info.bmiHeader.biCompression = BI_RGB;
            break;
        }

        case WM_DESTROY:
        {
            gameState.running = false;
            PostQuitMessage(0);
            break;
        }

        default:
            result = DefWindowProcW(hWindowHandle, Message, wParam, lParam);
    }
    return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int ncmdshow)
{
    WNDCLASSW SudokuGameWindow = {};
    SudokuGameWindow.style = CS_HREDRAW | CS_VREDRAW;
    SudokuGameWindow.lpszClassName = L"Sudoku Game";
    SudokuGameWindow.lpfnWndProc = SudokuGameProcedure;

    RegisterClassW(&SudokuGameWindow);

    HWND gameWindow = CreateWindowW(SudokuGameWindow.lpszClassName, L"Sudoku", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 600, 600, 0, 0, hInstance, 0);
    HDC hdc = GetDC(gameWindow);
    
    gameState.running = true;

    MSG message;
    while(gameState.running)
    {
        //  Input
        while(PeekMessage(&message, gameWindow, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        //  Simulate
        clear_screen(color_white);
        drawGameBoard();


        //  Render
        StretchDIBits(hdc, 0, 0, gameState.width, gameState.height, 0, 0, gameState.width, gameState.height, gameState.memory, &gameState.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
    }
    return 0;
}