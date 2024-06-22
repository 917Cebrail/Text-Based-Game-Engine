#ifndef EXECODEENGINE_H
#define EXECODEENGINE_H
typedef char *__char_c;
typedef int __int_t;

#include <stdio.h>
#include <stdlib.h>
#include "Source.h"
#include "GUI.h"

// MAIN DECLARES (VARIABLES)
__int_t A = 0; // INT VAR 1 
__int_t B = 0; // INT VAR 2
__int_t C = 0; // INT VAR 3
__int_t O = 0; // Output or Opertion code
__int_t PH = 0; // Player Health
__int_t PD = 0; // Player Damage
__int_t EH = 0; // Enemy Health
__int_t ED = 0; // Enemy Damage
__int_t PP = 0; // Player Position
__int_t EP = 0; // Enemy Position
__int_t MOVE = 0; // Move Direction
__char_c M = ""; // Map
__char_c T = ""; // Text

void Executive(char *code)
{
    if (strncmp(code, "NPC", 3) == 0)
    {
        sscanf(code, "NPC %d , %d, %d, %d", &A, &B, &C, &O);
        _npc(A, B, C, O);
    }
    else if (strncmp(code, "GUI", 3) == 0)
    {                                        // 10 : Width, 10 : Height, 1 : Opration Code
        sscanf(code, "GUI %d , %d, %d", &A, &B, &O); // Example : GUI 10, 10, 1
        if (O == 1) drawBox(A, B);
        else if (O == 2) drawTextInBox(T, A, B);
        else if (O == 3) drawBoxWithColor(T, A, B, C);
        else printf("\n");
    }
    else if (strncmp(code, "BATTLE", 6) == 0)
    {
        sscanf(code, "BATTLE %d", &MOVE);
        PH = p_health, PD = p_damage;
        EH = e_health, ED = e_damage;
        _damage(PP, EP, MOVE);
    }
    else if (strncmp(code, "MAP", 3) == 0)
    {
        char cs;                                         //   MAP : Char , O : Player, 10 : Length, 1 : Move
        sscanf(code, "MAP %c , %d, %d", &cs, &A, &MOVE); // Example : MAP O , 10, 1
        _map(M, A, PP, MOVE, cs);
    }
    else
    {
        printf("\n %c : Undefined code . Please enter a only defined code. If you unknown the code(s), enter a HELP.", code);
    }
}

#endif