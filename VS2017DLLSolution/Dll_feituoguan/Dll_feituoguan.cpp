// Dll_feituoguan.cpp: 定义 DLL 应用程序的导出函数。
// 模块定义方式导出，使用了*.def文件

#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979;

double MAX(double x, double y)
{
	return x > y ? x : y;
}

double MIN(double x, double y)
{
	return x < y ? x : y;
}

double ND(double x)
{
	return 1 / sqrt(2 * PI)*exp(-pow(x, 2) / 2);
}

double CND(double x)
{
	double L = 0;
	double K = 0;
	const double a1 = 0.31938153;
	const double a2 = -0.356563782;
	const double a3 = 1.781477937;
	const double a4 = -1.821255978;
	const double a5 = 1.330274429;

	L = fabs(x);
	K = 1 / (1 + 0.2316419*L);
	double CND = 1 - 1 / sqrt(2 * PI)*exp(-pow(L, 2) / 2)*(a1*K + a2 * pow(K, 2) + a3 * pow(K, 3) + a4 * pow(K, 4) + a5 * pow(K, 5));
	if (x < 0)
		CND = 1 - CND;
	return CND;
}

int sgn(double x)
{
	return x > 0 ? 1 : (x < 0 ? -1 : 0);
}
double CBND(double a, double b, double rho)
{
	double x[5] = { 0.24840615, 0.39233107, 0.21141819, 0.03324666, 0.00082485334 };
	double y[5] = { 0.10024215, 0.48281397, 1.0609498, 1.7797294, 2.6697604 };
	double rho1 = 0;
	double rho2 = 0;
	double delta = 0;
	double a1 = 0, b1 = 0, sum = 0;
	int i = 0, j = 0;
	double rtn_CBND = 0;
	a1 = a / sqrt(2 * (1 - pow(rho, 2)));
	b1 = b / sqrt(2 * (1 - pow(rho, 2)));
	if (a <= 0 && b <= 0 && rho <= 0)
	{
		sum = 0;
		while (i <= 4)
		{
			while (j <= 4)
			{
				sum = sum + x[i] * x[j] * exp(a1*(2 * y[i] - a1) + b1 * (2 * y[j] - b1) + 2 * rho*(y[i] - a1)*(y[j] - b1));
				j++;
			}
			i++;
		}
		rtn_CBND = sqrt(1 - pow(rho, 2)) / PI * sum;
	}
	else if (a <= 0 && b >= 0 && rho >= 0)
	{
		rtn_CBND = CND(a) - CBND(a, -b, -rho);
	}
	else if (a >= 0 && b <= 0 && rho >= 0)
	{
		rtn_CBND = CND(b) - CBND(-a, b, -rho);
	}
	else if (a >= 0 && b >= 0 && rho <= 0)
	{
		rtn_CBND = CND(a) + CND(b) - 1 + CBND(-a, -b, rho);
	}
	else if (a*b*rho > 0)
	{
		rho1 = (rho*a - b)*sgn(a) / sqrt(pow(a, 2) - 2 * rho*a*b + pow(b, 2));
		rho2 = (rho*b - a)*sgn(b) / sqrt(pow(a, 2) - 2 * rho*a*b + pow(b, 2));
		delta = (1 - sgn(a)*sgn(b)) / 4;
		rtn_CBND = CBND(a, 0, rho1) + CBND(b, 0, rho2) - delta;
	}
	return rtn_CBND;
}


//plainvanilla
//
//
//
//

double BlackScholes(char CallPutFlag, double S, double X, double T, double r, double v)
{
	double d1, d2;
	double rtn_value;
	d1 = (log(S / X) + (r + pow(v, 2) / 2)*T) / (v*sqrt(T));
	d2 = d1 - v * sqrt(T);
	if (CallPutFlag == 'C' || CallPutFlag == 'c')
	{
		rtn_value = S * CND(d1) - X * exp(-r * T)*CND(d2);
	}
	else if (CallPutFlag == 'P' || CallPutFlag == 'p')
	{
		rtn_value = S * exp(-r * T)*CND(-d2) - S * CND(-d1);
	}
	return rtn_value;
}


// Merton (1973) Options on stock indices
double Merton73(char CallPutFlag, double S, double X, double T, double r, double q, double v)
{
	double d1, d2;

	double rtn_value;
	d1 = (log(S / X) + (r - q + pow(v, 2) / 2)*T) / (v * sqrt(T));
	d2 = d1 - v * sqrt(T);
	if (CallPutFlag == 'c' || CallPutFlag == 'C') {
		rtn_value = S * exp(-q * T) * CND(d1) - X * exp(-r * T) * CND(d2);
	}
	else if (CallPutFlag == 'p')
	{
		rtn_value = X * exp(-r * T) * CND(-d2) - S * exp(-q * T) * CND(-d1);
	}
	return rtn_value;
}


// Black (1977) Options on futures/forwards
double Black76(char CallPutFlag, double F, double X, double T, double r, double v)
{
	double d1, d2;
	double rtn_value;
	d1 = (log(F / X) + (pow(v, 2) / 2) * T) / (v * sqrt(T));
	d2 = d1 - v * sqrt(T);
	if (CallPutFlag == 'c' || CallPutFlag == 'C') {
		rtn_value = exp(-r * T) * (F * CND(d1) - X * CND(d2));
	}
	else if (CallPutFlag == 'p' || CallPutFlag == 'P')
	{
		rtn_value = exp(-r * T) * (X * CND(-d2) - F * CND(-d1));
	}
	return rtn_value;
}


// Garman and Kohlhagen (1983) Currency options
double GarmanKolhagen(char CallPutFlag, double S, double X, double T, double r, double rf, double v)
{
	double d1, d2;
	double rtn_value;
	d1 = (log(S / X) + (r - rf + pow(v, 2) / 2) * T) / (v * sqrt(T));
	d2 = d1 - v * sqrt(T);
	if (CallPutFlag == 'c' || CallPutFlag == 'C')
	{
		rtn_value = S * exp(-rf * T) * CND(d1) - X * exp(-r * T) * CND(d2);
	}
	else if (CallPutFlag == 'p' || CallPutFlag == 'p')
	{
		rtn_value = X * exp(-r * T) * CND(-d2) - S * exp(-rf * T) * CND(-d1);
	}
	return rtn_value;
}


// The generalized Black and Scholes formula
double GBlackScholes(char CallPutFlag, double S, double X, double T, double r, double b, double v)
{
	double d1, d2;
	double rtn_value;
	d1 = (log(S / X) + (b + pow(v, 2) / 2) * T) / (v * sqrt(T));
	d2 = d1 - v * sqrt(T);

	if (CallPutFlag == 'C' || CallPutFlag == 'c')
	{
		rtn_value = S * exp((b - r) * T) * CND(d1) - X * exp(-r * T) * CND(d2);
	}
	else if (CallPutFlag == 'p' || CallPutFlag == 'P')
	{
		rtn_value = X * exp(-r * T) * CND(-d2) - S * exp((b - r) * T) * CND(-d1);
	}
	return rtn_value;
}

// Delta for the generalized Black and Scholes formula
double GDelta(char CallPutFlag, double S, double X, double T, double r, double b, double v)
{

	double d1;
	double rtn_value;

	d1 = (log(S / X) + (b + pow(v, 2) / 2) * T) / (v * sqrt(T));

	if (CallPutFlag == 'c' || CallPutFlag == 'C')
	{
		rtn_value = exp((b - r) * T) * CND(d1);
	}
	else if (CallPutFlag == 'p' || CallPutFlag == 'P')
	{
		rtn_value = exp((b - r) * T) * (CND(d1) - 1);
	}
	return rtn_value;
}

// Gamma for the generalized Black and Scholes formula
double GGamma(double S, double X, double T, double r, double b, double v)
{
	double d1;
	double rtn_value;

	d1 = (log(S / X) + (b + pow(v, 2) / 2) * T) / (v * sqrt(T));
	rtn_value = exp((b - r) * T) * ND(d1) / (S * v * sqrt(T));
	return rtn_value;
}

// Theta for the generalized Black and Scholes formula
double GTheta(char CallPutFlag, double S, double X, double T, double r, double b, double v)
{
	double d1, d2;
	double rtn_value;
	d1 = (log(S / X) + (b + pow(v, 2) / 2) * T) / (v * sqrt(T));
	d2 = d1 - v * sqrt(T);

	if (CallPutFlag == 'c' || CallPutFlag == 'C')
	{
		rtn_value = -S * exp((b - r) * T) * ND(d1) * v / (2 * sqrt(T)) - (b - r) * S * exp((b - r) * T) * CND(d1) - r * X * exp(-r * T) * CND(d2);
	}
	else if (CallPutFlag == 'p' || CallPutFlag == 'P')
	{
		rtn_value = -S * exp((b - r) * T) * ND(d1) * v / (2 * sqrt(T)) + (b - r) * S * exp((b - r) * T) * CND(-d1) + r * X * exp(-r * T) * CND(-d2);
	}
	return rtn_value;
}

// Vega for the generalized Black and Scholes formula
double GVega(double S, double X, double T, double r, double b, double v)
{
	double d1;
	double rtn_value;
	d1 = (log(S / X) + (b + pow(v, 2) / 2) * T) / (v * sqrt(T));
	rtn_value = S * exp((b - r) * T) * ND(d1) * sqrt(T);
	return rtn_value;
}

double ImpVol(char CallOrPut, double S, double K, double T, double r, double q, double OptionValue)
{
	double vol_1;
	int maxIter;
	double Value_1;
	int i;
	double upper;
	double lower;
	double initial;
	double diff;
	double dx;
	double rtn_value;

	upper = 2;
	lower = 0.000000001;
	initial = 0.15;
	diff = 0.000001;
	maxIter = 10000;
	vol_1 = initial;

	i = 1;
	while (true) {
		Value_1 = GBlackScholes(CallOrPut, S, K, T, r, q, vol_1);
		dx = OptionValue - Value_1;

		if (abs(dx) < diff || i == maxIter) {
			break;
		}
		if (dx > 0)
		{
			lower = vol_1;
			vol_1 = vol_1 + 0.5 * (upper - lower);
		}
		else if (dx < 0)
		{
			upper = vol_1;
			vol_1 = vol_1 - 0.5 * (upper - lower);
		}
		i = i + 1;
	}
	if (i == maxIter)
	{
		vol_1 = -0.1;
	}
	return vol_1;
}

