#pragma once
class Point
{
public:
	Point(int xx = 0, int yy = 0) { x = xx; y = yy; }
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(const int xx) { x = xx; }
	void setY(const int yy) { y = yy; }
private:
	int x, y;
};

