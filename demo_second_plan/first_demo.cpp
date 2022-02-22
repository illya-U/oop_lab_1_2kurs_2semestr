

#include <vector>
#include <list>
#include <tuple>
#include<algorithm>



class shape
{
protected:
    class Center
    {
    public:
        float x;
        float y;
        Center(float x, float y) { this->x = x; this->y = y; }
        Center(){}
    };
public:
    virtual shape& clone() = 0;
    virtual shape& add(shape& figure) = 0;
    float max_x;
    float min_x;
    float max_y;
    float min_y;
    Center center;
    /*
     * |/////////////|
     * |    max_y    |
     * |max_x c min_x|
     * |    min_y    |
     * |/////////////|
     */
};


class Realese
{
public:
    class Rectangle : public shape
    {
    public:
        ////////
        Rectangle(const Rectangle &rec){}
        ////////
        Rectangle(float wight, float height, float pos_x, float pos_y)
        {
            max_x = pos_x + wight/2;
            min_x = pos_x - wight/2;
            max_y = pos_y + height/2;
            min_y = pos_y -height/2;
            center.x = pos_x;
            center.y = pos_y;
        }
        Rectangle& clone()
        {

        }
        shape& add(shape& figure){throw(std::exception());}
    };


    class Circle : public shape
    {
    public:
        Circle(float radius, float pos_x, float pos_y)
        {
            max_x = pos_x + radius/2;
            min_x = pos_x - radius/2;
            max_y = pos_y + radius/2;
            min_y = pos_y - radius/2;
            center.x = pos_x;
            center.y = pos_y;
        }
        Circle& clone()
        {


        }
        shape& add(shape& figure){throw(std::exception());}
    };

    class Composite : public shape
    {

    private:
        void calculate_size_of_composite(shape& first_figure)
        {
            if(first_figure.max_x>max_x){max_x=first_figure.max_x;}
            if(first_figure.min_x<min_x){min_x=first_figure.min_x;}
            if(first_figure.max_y>max_y){max_y=first_figure.max_y;}
            if(first_figure.min_y<min_y){min_y=first_figure.min_y;}
        }
        void empty_compasite(shape& first_figure)
        {
            max_x = first_figure.max_x;
            min_x = first_figure.min_x;
            max_y = first_figure.max_y;
            min_y = first_figure.min_y;
        }
    public:
        std::vector<shape*> set;
        Composite(shape& first_figure)
        {
            set.push_back(&first_figure);
            empty_compasite(first_figure);
        }
        Composite() = default;

        shape& add(shape& figure)
        {
            set.push_back(&figure);
            if(set.empty())
            {
                empty_compasite(figure);
            }
            else
            {
                calculate_size_of_composite(figure);
            }
            return figure;
        }

        shape& remove(shape& figure)
        {
            std::remove(set.begin(),set.end(),&figure);
            return figure;
        }

        Composite& clone()
        {



        }

    };
public:

    static Composite create_Composite(shape& first_figure)
    {
         return Composite(first_figure);
    }

    static void add_to_composite(Composite& compos,shape& figure)
    {
        compos.add(figure);
    }

    static Rectangle* create_Rectangle(float wight, float height, float pos_x, float pos_y)
    {
       return new Rectangle(wight,height,pos_x,pos_y);
    }

    static Circle create_Circle(float radius, float pos_x, float pos_y)
    {
       return Circle(radius,pos_x,pos_y);
    }


    Composite global;






};










int main()
{
    Realese world;
    world.add_to_composite(world.global,*(Realese::create_Rectangle(4,3,2,1)));

}
