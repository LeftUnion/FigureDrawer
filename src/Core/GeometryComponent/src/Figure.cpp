#include <Figure.hpp>

#include <cmath>

namespace Geometry {

const size_t Figure::RADIUS = 100;

Figure::Figure(const Point &center, size_t vertexes)
{
    double sector = 2 * M_PI / vertexes;
    mCenter = center;

    /*
     * Расчёт положения точек для правильной фигуры относительно её центра.
     * Расчёт ведётся с помощью полярных координат.
     * Координаты точек записываются в вектор.
     */
    for(size_t i = 0; i < vertexes; i++)
    {
        mVertexes.push_back({(center.x + RADIUS * cos(sector * i - M_PI/2)) ,
                             (center.y + RADIUS * sin(sector * i - M_PI/2))});

    }
}

std::shared_ptr<std::vector<Point>> Figure::getPoints()
{
    return std::make_shared<std::vector<Point>>(mVertexes);
}

std::shared_ptr<Point> Figure::getCenter()
{
    return std::make_shared<Point>(mCenter);
}

bool Figure::checkInBounds(Point clickCoord)
{
    /*
     * Условие - если кликнули на область фигуры
     * Область фигуры определяется по уравнению окружности
     * Фигура вписана в эту окружность
     */
    if(pow((clickCoord.x - mCenter.x), 2) + pow((clickCoord.y - mCenter.y), 2) <= pow(RADIUS, 2))
    {
        return true;
    }

    return false;
}

}
