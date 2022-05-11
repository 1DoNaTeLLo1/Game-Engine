#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	Color();
	Color(float red, float green, float blue, float alpha = 1.F);
	float GetRed();
	void SetRed(float red);
	int GetRedInt();
	float GetGreen();
	void SetGreen(float green);
	int GetGreenInt();
	float GetBlue();
	void SetBlue(float blue);
	int GetBlueInt();
	float GetAlpha();
	void SetAlpha(float alpha);
	int GetAlphaInt();

private:
	float red;
	float green;
	float blue;
	float alpha;
	static const int DEPTH = 255;
};

#endif