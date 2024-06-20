#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int _length;

static float sigmoid(float input, float weight, float bias)
{
	return 1 / (1 + exp(-((weight * input) + bias)));
}

int hide_neuron(float _input, float _weight, float _bias)
{
	float w, b;
	float result;
	int res;
	w = 0; b = 0;
	result = sigmoid(_input, _weight, _bias);
	if (fabs(result - 1.0) < 0.000001)
	{
		res = 1;
	}
	else
	{
		for (int j = 0; j < _length; j++)
		{
			result = sigmoid(_input, _weight + j, _bias + j);
			if (fabs(result - 1.0) < 0.000001)
			{
				res = 1;
				w = _weight + j;
				b = _bias - j;
				break;
			}
			else
			{
				res = 0;
			}
		}
	}
	return res;
}

#endif