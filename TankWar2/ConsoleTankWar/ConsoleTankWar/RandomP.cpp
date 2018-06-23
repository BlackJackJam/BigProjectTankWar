#include "RandomP.h"
#include "stdafx.h"

using namespace std;

int RandomP::poisson(double rate) const//使用inverse CDF方法（cumulative distribution function）将poisson分布的反函数求出，通过均匀分布随机数，得出possion分布随机数
									  //只要生成一个0到1之间的随机数，然后看泊松分布的前几项和刚好大于这个随机数就行了。(所谓的inverse CDF方法)
{
	double u, p1;
	int i = 0, s;
	u = uniform();
	p1 = 0;
	while (p1<u)
	{
		s = fac(i);//阶乘
		p1 += (exp(-rate)*pow(rate, i)) / s;//加和泊松分布
		i++;
	}
	return i - 1;
}
/*
经过测试，本泊松分布模拟函数产生数值基本符合泊松分布要求，但是波动范围较大，且倾向于实际小于rate
*/

double RandomP::uniform() const//0~1之间均匀分布随机函数，均匀随机生成0~1之间的数（作为poisson分布函数的概率P(x=k)，反求对应的k数值），参考C11浮点数均匀分布模板
{
	LARGE_INTEGER nFrequency;
	if (::QueryPerformanceFrequency(&nFrequency))
	{
		LARGE_INTEGER nStartCounter;
		::QueryPerformanceCounter(&nStartCounter);
		std::default_random_engine random(nStartCounter.LowPart);
		std::uniform_real_distribution<double> dis2(0.0, 1.0);
		return dis2(random);
	}//调取CPU时间，可以精确到微秒，因此不用重新制作种子即可实现重新调用时产生不同随机数
}

int RandomP::fac(int n) const
{
	if (n == 0) return 1;
	else
	{
		int k, n1 = 1;
		for (k = 1; k <= n; k++)
		{
			n1 *= k;
		}
		return n1;
	}
}