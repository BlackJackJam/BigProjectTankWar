#pragma once
#ifndef __RANDOMP_H__
#define __RANDOMP_H__

#include <time.h>
#include <Windows.h>
#include <cmath>
#include <random>

class RandomP
{
public:
	int poisson(double rate) const;
	double uniform() const;
private:
	int fac(int n) const;
};

#endif