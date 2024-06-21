#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Source.h"
#include "GUI.h"

#pragma warning(disable : 4996)

int main()
{
    srand(time(NULL));
    int _npc_move, _l = (rand() % 30) + 10;
    p_health = 20.0, e_health = 20.0, p_damage = 20.0, e_damage = 10.0;
    char map1[_l];
    int _prompt;
    int width = 30;
    int height = 10;
    const char *text = " [1] : NPC | [2] : BATTLE";
    clrscr();
    drawBoxWithColor(text, 30, 15, 1);
    printf("\n");
    drawBoxWithColor(text, 30, 15, 0);
    printf("\n");
    drawBoxWithColor(text, 30, 15, 2);
    while (true)
    {
        printf("\n Enter command (only int) : ");
        scanf("%d", &_prompt);
        if (_prompt == 1)
        {
            for (int i = 0; i < _l; i++)
            {
                _npc(1, 1, 1,_npc_move);
                _map(map1, _l, _l / 2, (rand() % 2 + _npc_move), 'X');
                printf("\n");
            }
        }
        else if (_prompt == 2)
        {
            int moll, _position;
            printf("Move (only 1 or -1) : ");
            scanf("%d", &moll);
            printf("Position (only 0 or %d) : ", _l);
            scanf("%d", &_position);
            _map(map1, _l, _position, _npc_move, 'O');
            _map(map1, _l, _l / 2, _npc_move, 'X');
            _damage(_position, _npc_move, moll);
        }
        else if (_prompt == 9)
        {
            break;
        }
        else
        {
            printf("\n Wrong Command \n");
        }
    }
}
