#define color_black     0x000000
#define color_white     0xffffff
#define color_gray      0x0e0e0e
#define color_red       0xff0000
#define color_orange    0xf58231
#define color_yellow    0xffe119
#define color_lime      0xbfef45
#define color_green     0x3cb44b
#define color_cyan      0x42d4f4
#define color_blue      0x4363d8
#define color_purple    0x911eb4
#define color_magenta   0xf032e6

#define boardSize           500
#define thickLineWidth      0.03 * boardSize
#define thinLineWidth       0.01 * boardSize
#define squareSize          (boardSize - 3*thickLineWidth - 9*thinLineWidth) / 9
#define cellContentsBorder  0.1 * squareSize

void clear_screen(size_t color)
{
    size_t* currPixel = (size_t*)gameState.memory;
    for(int y = 0; y < gameState.height; y++)
    {
        for(int x = 0; x < gameState.width; x++)
        {
            *currPixel++ = color;
        }
    }
}

void drawRectangle(int x0, int y0, int x1, int y1, int color)
{
    x0 = clamp(0, x0, gameState.width);
    y0 = clamp(0, y0, gameState.height);
    x1 = clamp(0, x1, gameState.width);
    y1 = clamp(0, y1, gameState.height);

    size_t* currPixel;
    for(int y = gameState.height - y1; y < gameState.height - y0; y++)
    {
        currPixel = (size_t*)gameState.memory + x0 + y*gameState.width;
        for(int x = x0; x < x1; x++)
        {
            *currPixel++ = color;
        }
    }
}

void drawNumber(int num, int x0, int y0, int x1, int y1, int color)
{
    int xDiff = (x0 - x1);
    int yDiff = (x0 - x1);
    switch(num)
    {
        case 1:
            drawRectangle(x0, y0, x0 - (int)(3*xDiff/5), y0 - (int)(yDiff/5), color);
            drawRectangle(x0 - (int)(2*xDiff/5), y0, x0 - (int)(3*xDiff/5), y1, color);
            drawRectangle(x0, y0 - (int)(4*yDiff/5), x1 , y1, color);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
    }
}

void updateSquares()
{
    int x = 2*thickLineWidth;
    int y = 2*thickLineWidth;
    int cellVal, cellColor;

    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            cellVal = gameState.sudokuGame.getCell(9*(i-1) + (j-1));
            switch(cellVal)
            {
                case 1:
                    cellColor = color_red;
                    break;
                case 2:
                    cellColor = color_orange;
                    break;
                case 3:
                    cellColor = color_yellow;
                    break;
                case 4:
                    cellColor = color_lime;
                    break;
                case 5:
                    cellColor = color_green;
                    break;
                case 6:
                    cellColor = color_cyan;
                    break;
                case 7:
                    cellColor = color_blue;
                    break;
                case 8:
                    cellColor = color_purple;
                    break;
                case 9:
                    cellColor = color_magenta;
                    break;
                default:
                    cellColor = color_white;
                    break;
            }

            drawRectangle(x, y, x + squareSize, y + squareSize, cellColor);
            drawNumber(1, x + cellContentsBorder, y + cellContentsBorder, x + squareSize - cellContentsBorder, y + squareSize - cellContentsBorder, color_black);
            x += squareSize;
            if(j % 3 == 0)
                x += thickLineWidth;
            else
                x += thinLineWidth;
        }

        x = 2*thickLineWidth;
        y += squareSize;
        if(i % 3 == 0)
            y += thickLineWidth;
        else
            y += thinLineWidth;
    }
}

void drawGameBoard()
{
    drawRectangle(thickLineWidth, thickLineWidth, thickLineWidth + boardSize, thickLineWidth + boardSize, color_black);
    updateSquares();
}