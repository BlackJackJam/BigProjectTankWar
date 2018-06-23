#include "RandomP.h"
#include "stdafx.h"

using namespace std;

int RandomP::poisson(double rate) const//ʹ��inverse CDF������cumulative distribution function����poisson�ֲ��ķ����������ͨ�����ȷֲ���������ó�possion�ֲ������
									  //ֻҪ����һ��0��1֮����������Ȼ�󿴲��ɷֲ���ǰ����͸պô����������������ˡ�(��ν��inverse CDF����)
{
	double u, p1;
	int i = 0, s;
	u = uniform();
	p1 = 0;
	while (p1<u)
	{
		s = fac(i);//�׳�
		p1 += (exp(-rate)*pow(rate, i)) / s;//�ӺͲ��ɷֲ�
		i++;
	}
	return i - 1;
}
/*
�������ԣ������ɷֲ�ģ�⺯��������ֵ�������ϲ��ɷֲ�Ҫ�󣬵��ǲ�����Χ�ϴ���������ʵ��С��rate
*/

double RandomP::uniform() const//0~1֮����ȷֲ���������������������0~1֮���������Ϊpoisson�ֲ������ĸ���P(x=k)�������Ӧ��k��ֵ�����ο�C11���������ȷֲ�ģ��
{
	LARGE_INTEGER nFrequency;
	if (::QueryPerformanceFrequency(&nFrequency))
	{
		LARGE_INTEGER nStartCounter;
		::QueryPerformanceCounter(&nStartCounter);
		std::default_random_engine random(nStartCounter.LowPart);
		std::uniform_real_distribution<double> dis2(0.0, 1.0);
		return dis2(random);
	}//��ȡCPUʱ�䣬���Ծ�ȷ��΢�룬��˲��������������Ӽ���ʵ�����µ���ʱ������ͬ�����
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