#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <vector>
#include <memory>

namespace Geometry {

struct Point
{
    size_t x, y;
};

class Figure
{
  public:
    Figure(const Point& center, size_t vertexes = 3);
    std::shared_ptr<std::vector<Point>> getPoints();

  private:
    std::vector<Point> mVertexes;
    static const size_t RADIUS;
};

}
#endif // FIGURE_HPP
