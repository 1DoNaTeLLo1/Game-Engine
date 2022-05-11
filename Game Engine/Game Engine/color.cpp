#include "color.h"

Color::Color()
{
	this->red = 1.F;
	this->green = 1.F;
	this->blue = 1.F;
	this->alpha = 1.F;
}

Color::Color(float red, float green, float blue, float alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}

float Color::GetRed()
{
	return this->red;
}

void Color::SetRed(float red)
{
	this->red = red;
}

int Color::GetRedInt()
{
	return (int)(this->red * (float)this->DEPTH);
}

float Color::GetGreen()
{
	return this->green;
}

void Color::SetGreen(float green)
{
	this->green = green;
}

int Color::GetGreenInt()
{
	return (int)(this->green * (float)this->DEPTH);
}

float Color::GetBlue()
{
	return this->blue;
}

void Color::SetBlue(float blue)
{
	this->blue = blue;
}

int Color::GetBlueInt()
{
	return (int)(this->blue * (float)this->DEPTH);
}

float Color::GetAlpha()
{
	return this->alpha;
}

void Color::SetAlpha(float alpha)
{
	this->alpha = alpha;
}

int Color::GetAlphaInt()
{
	return (int)(this->alpha * (float)this->DEPTH);
}