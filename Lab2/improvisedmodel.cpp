#include "improvisedmodel.h"

ImprovisedModel::ImprovisedModel(QListWidget *widget): _widget(widget), _list(new QList<Timer*>) {}

void ImprovisedModel::addItem(Timer* item){
    qDebug()<<"addItem "<<item->getName();
    _list->append(item);
    _widget->addItem(item->getName());
    connect(item, SIGNAL(timeout(Timer*)), this, SLOT(onTimerTimeout(Timer*)));
}

void ImprovisedModel::removeItem(int id){
    delete _list->takeAt(id);
    _widget->takeItem(id);
}

QString ImprovisedModel::getTimerString(int id){
    return _list->at(id)->displayedString();
}

QString ImprovisedModel::getInfo(int id){
    QString res="Some info\n";
    return res;
}

ImprovisedModel::~ImprovisedModel(){
    for(auto i = _list->begin(); i!=_list->end(); i++)
        delete *i;
    delete _list;
}

void ImprovisedModel::onTimerTimeout(Timer* timer){
    int j = 0;
    qDebug()<<timer->getName();
    for(auto i = _list->begin(); i!=_list->end() && *i!=timer; i++, j++);
    removeItem(j);
}
