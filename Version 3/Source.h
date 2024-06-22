#ifndef SOURCE_H
#define SOURCE_H

#include <stdio.h>
#include <stdlib.h>
#include "Intelligence.h"

float p_health, p_damage, e_health, e_damage;

void _map(char *map, int length, int position, int move, char _char) 
{
    // Move only -1 , 1
    for (int i = 0; i < length; i++)
    {
        if (i == (position + move) % 10) map[i] = _char;
        else map[i] = '.';
    }
    for (int i = 0; i < length; i++)
    {
        printf("%c", map[i]);
    }
    printf(" -> Position : %d  ,  Move : %d\n", (position + move) % 10, move % 10);
}

void _damage(int p_position, int e_position, int move)
{
    if (move == 1)
    {
        if ((p_position - e_position) < 2)
        {
            e_health = e_health / 2;
            p_health-= e_damage;
        }
        else
        {
            p_health = p_health / 2;
            e_health-= p_damage;
        }
    }
    else if (move == 0)
    {
        if ((p_position - e_position) < 2)
        {
            p_health = p_health / 2;
            e_health-= p_damage;
        }
        else
        {
            e_health = e_health / 2;
            p_health-= e_damage;
        }
    }
    else
    { /* Your extended code */ }
    printf("\n STATE -> Player Health : %1f, Enemy Health : %1f", p_health, e_health);
    if (p_health <= 0)
    {
        printf("\n You dead \n");
    }
    else if (e_health <= 0)
    {
        printf("\n Enemy dead \n");
    }
    else 
    { /* Your extended code */ }
}

int _npc(float _weight, float _bias, float _input, int _output_direction) 
{
    _output_direction = hide_neuron(_input, _weight, _bias);
    return _output_direction;
}

#endif