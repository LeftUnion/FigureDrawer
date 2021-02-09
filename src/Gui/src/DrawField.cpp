#include <DrawField.hpp>
#include <FigureDrawer.hpp>

#include <QMouseEvent>
#include <QMessageBox>

DrawField::DrawField(QWidget *parent) : QGraphicsView(parent)
{
    resize(parent->width(), parent->height());
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
}

void DrawField::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
        return;

    for(size_t i = 0; i < mFigures.size(); i++)
    {
        if(mFigures[i].checkInBounds({(double)event->x(), (double)event->y()}))
        {
            int newCountVertexes = mFigures[i].getPoints()->size() + 1;
            Geometry::Figure newFigure({mFigures[i].getCenter()->x, mFigures[i].getCenter()->y},
                                       newCountVertexes);

            mFigures.erase(mFigures.begin() + i);
            mFigures.emplace(mFigures.begin() + i, newFigure);
            refreshAll();
            return;
        }
    }

    Geometry::Figure figure({(double)event->x(), (double)event->y()});
    mFigures.push_back(figure);
    refreshAll();
}

void DrawField::keyPressEvent(QKeyEvent *event)
{
    /*
     * Удаление всех фигур при нажатии на кнопку "Del"
     * При отсутствии фигур высвечивает окно с ошибкой
     */
    if(event->key() == Qt::Key_Delete)
    {
        if(mFigures.empty())
        {
            QMessageBox errorMsg(QMessageBox::Icon::Critical, "Error!", "Figures don't exist");
            errorMsg.exec();
        }
        mFigures.clear();
        refreshAll();
    }

}

void DrawField::refreshAll()
{
    mScene.reset(new QGraphicsScene(0, 0, width(), height()));
    for(auto figure : mFigures)
    {
        FigureDrawer::drawFigure(mScene, *figure.getPoints());
    }

    setScene(mScene.get());
}
