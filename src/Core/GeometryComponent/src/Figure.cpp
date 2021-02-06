#include <Figure.hpp>
#include <cmath>

namespace Geometry {

const size_t Figure::RADIUS = 100;

Figure::Figure(const Point &center, size_t vertexes)
{
    double sector = 2 * M_PI / vertexes;

    for(size_t i = 0; i < vertexes; i++)
    {
        mVertexes.push_back({(size_t)round(center.x + RADIUS * cos(sector * i)) ,
                             (size_t)round(center.y + RADIUS * sin(sector * i))});

    }
}

std::shared_ptr<std::vector<Point>> Figure::getPoints()
{
    return std::make_shared<std::vector<Point>>(mVertexes);
}

}
