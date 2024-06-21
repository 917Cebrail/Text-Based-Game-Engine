#ifndef GUI_H
#define GUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "Text.h"

void drawBox(int width, int height) 
{
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            if (i == 0 || i == height - 1) 
            {
                printf("-");
            } 
            else 
            {
                if (j == 0 || j == width - 1) 
                {
                    printf("|");
                } 
                else 
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void drawTextInBox(const char *text, int boxWidth, int boxHeight)
 {
    int textLen = strlen(text);
    int startX = (boxWidth - textLen) / 2;
    int startY = boxHeight / 2;

    for (int i = 0; i < boxHeight; i++) 
    {
        for (int j = 0; j < boxWidth; j++) 
        {
            if (i == 0 || i == boxHeight - 1) 
            {
                printf("-");
            } 
            else 
            {
                if (j == 0 || j == boxWidth - 1) 
                {
                    printf("|");
                } 
                else if (i == startY && j >= startX && j < startX + textLen) 
                {
                    printf("%c", text[j - startX]);
                } 
                else 
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void drawBoxWithColor(const char *text, int boxWidth, int boxHeight, int colorOperation) {
    if (colorOperation == 1)
    {
        textcolor(GREEN);
        textbackground(DARKGRAY);
    }
    else if (colorOperation == 0)
    {
        textcolor(WHITE);
        textbackground(BLACK);
    }
    else
    {
        textcolor(WHITE);
        textbackground(BROWN);
    }
    int textLen = strlen(text);
    int startX = (boxWidth - textLen) / 2;
    int startY = boxHeight / 2;

    for (int i = 0; i < boxHeight; i++) 
    {
        for (int j = 0; j < boxWidth; j++) 
        {
            if (i == 0 || i == boxHeight - 1) 
            {
                printf("-");
            } 
            else 
            {
                if (j == 0 || j == boxWidth - 1) 
                {
                    printf("|");
                } 
                else if (i == startY && j >= startX && j < startX + textLen) 
                {
                    printf("%c", text[j - startX]);
                } 
                else 
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

#endif