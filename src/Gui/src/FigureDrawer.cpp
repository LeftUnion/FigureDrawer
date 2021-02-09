#include <FigureDrawer.hpp>

void FigureDrawer::drawFigure(std::shared_ptr<QGraphicsScene> scene,
                              std::vector<Geometry::Point>    vertexes)
{
    QPen myPen = QPen(Qt::blue);
    for(size_t i = 0; i < vertexes.size() - 1; i++)
    {
        scene->addLine(vertexes[i].x, vertexes[i].y, vertexes[i+1].x, vertexes[i+1].y, myPen);
    }

    scene->addLine(vertexes[0].x, vertexes[0].y, vertexes[vertexes.size() - 1].x, vertexes[vertexes.size() - 1].y, myPen);
}
