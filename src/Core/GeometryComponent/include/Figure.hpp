#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <vector>
#include <memory>

namespace Geometry {

/*!
 * \brief The Point struct - структура, хранящая координаты точек (x, y)
 */
struct Point
{
    double x, y;
};

/*!
 * \brief The Figure class - класс, определяющий геометрическую фигуру
 */
class Figure
{
  public:
    /*!
     * \brief Figure - конструктор, расчитывающий положение точек фигуры
     * \param center - координаты центра фигуры
     * \param vertexes - кол-во вершин фигуры
     */
    Figure(const Point &center, size_t vertexes = 3);

    /*!
     * \brief getPoints - возвращает указатель на вектор координат вершин фигуры
     * \return - указатель на вектор координат вершин фигуры
     */
    std::shared_ptr<std::vector<Point>> getPoints();

    /*!
     * \brief getCenter - возвращает указатель на координаты центра фигуры
     * \return - указатель на координаты центра фигуры
     */
    std::shared_ptr<Point> getCenter();

    /*!
     * \brief checkInBounds - проверяет был ли клик внутри фигуры
     * \param clickCoord - координаты клика ЛКМ
     * \return - возвращает true, если клик произошёл внутри фигуры
     */
    bool checkInBounds(Point clickCoord);

  private:
    /*!
     * \brief RADIUS - (константа) радиус расположения точек от центра фигуры
     */
    static const size_t RADIUS;

    /*!
     * \brief mCenter - объект структуры Point, хранящий координаты центра фигуры
     */
    Point mCenter;

    /*!
     * \brief mVertexes - вектор точек вершин фигуры
     */
    std::vector<Point> mVertexes;
};

}
#endif // FIGURE_HPP
