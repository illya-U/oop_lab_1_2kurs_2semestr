
#include <vector>;
#include <list>;


class shape
{
public:
	virtual shape& clone() = 0;
protected:
	class Center
	{
	public:
		float x;
		float y;
	};
};


class layer
{
private:
	int number;
	std::vector<std::vector<float>> matrix;
public:
	void add_figure(shape& figure) {}
	void remove_figure(shape& figure){}
};




class Rectangle : public shape
{
private:
	float wight;
	float height;
	Center center;
public:
	Rectangle(float wight,float height,float pos_x,float pos_y)
	{
		this->wight = wight;
		this->height = height;
		this->center.x = pos_x;
		this->center.y = pos_y;
	}

	Rectangle& plus_wight(float wight)
	{
		this->wight += wight;
	}

	Rectangle& plus_heigth(float height)
	{
		this->height += height;
	}

	Rectangle& plus_pos_x(float pos_x)
	{
		this->center.x += pos_x;
	}

	Rectangle& plus_pos_y(float pos_y)
	{
		this->center.y += pos_y;
	}

	Rectangle& clone()
	{
	
	}
};

class Circle : public shape
{
private:
	float radius;
	Center center;
public:
	Circle(float radius, float pos_x, float pos_y)
	{
		this->radius = radius;
		this->center.x = pos_x;
		this->center.y = pos_y;
	}

	Circle& plus_radius(float radius)
	{
		this->radius += radius;
	}

	Circle& plus_pos_x(float pos_x)
	{
		this->center.x += pos_x;
	}

	Circle& plus_pos_y(float pos_y)
	{
		this->center.y += pos_y;
	}

	Circle& clone()
	{
	
	
	}
};

class Composite : public shape
{
private:


public:
	Composite(shape& first_figure, shape& second_figure)
	{



	}

	Composite& add(shape& figure)
	{



	}

	Composite& remove(shape& figure)
	{



	}

	Composite& clone()
	{



	}

};

class layer_taker
{
private:

	std::list<layer> book;
	class iteraror{};
public:
	void add_Circle() {}
	void add_Rectangle() {}
	void create_Composite() {}
	void add_to_Composite()	{}
	void clone() {}
	void change_x(shape& figure){}
	void change_y(shape& figure){}
	shape& find_pos(float pos_x, float pos_y){}
	


};


int main()
{
	Rectangle t(5, 5, 5, 5);
}
