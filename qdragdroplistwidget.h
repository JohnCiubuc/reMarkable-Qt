#ifndef QDRAGDROPLISTWIDGET_H
#define QDRAGDROPLISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QDragMoveEvent>

#include <QDebug>
#include <QDrag>
class QDragDropListWidget : public QListWidget
{

public:
    explicit  QDragDropListWidget(QWidget * parent) :
        QListWidget(parent)
    {
//        this->setSelectionMode(QAbstractItemView::SingleSelection);
//        this->setDragEnabled(true);
//        this->setDragDropMode(QAbstractItemView::InternalMove);
//        this->viewport()->setAcceptDrops(true);
//        this->setDropIndicatorShown(true);
    }

protected:
//    void dragMoveEvent(QDragMoveEvent *e)
//    {
//        qDebug()<<"Drag";
//        if (e->source() != this)
//        {
//            e->accept();
//        }
//        else
//        {
//            e->accept();
////            e->ignore();
//        }
//    }
    void startDrag(Qt::DropActions supportedActions)
    {
        qDebug() << "STartdratg";
        QDrag *drag = new QDrag(this);
        drag->setMimeData(model()->mimeData(selectedIndexes()));
        QPixmap pixmap(viewport()->visibleRegion().boundingRect().size());
        pixmap.fill(Qt::transparent);
        drag->setPixmap(pixmap);
        drag->setHotSpot(viewport()->mapFromGlobal(QCursor::pos()));
        drag->exec(supportedActions, Qt::MoveAction);
    }
    void dropEvent(QDropEvent *e)
    {
        qDebug("Items Dropped");
        qDebug() << e->dropAction();
        qDebug() << e->source();
        qDebug() << e->proposedAction();
        e->accept();
    }
};
#endif // QDRAGDROPLISTWIDGET_H
