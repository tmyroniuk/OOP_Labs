#include "improvisedmodel.h"

ImprovisedModel::ImprovisedModel(QListWidget *widget): _widget(widget), _list(new QList<Timer*>) {}

void ImprovisedModel::addItem(Timer* timer){

    QListWidgetItem* item;
    if(timer->type() == Timer::alarm_t)
        item = new QListWidgetItem(QIcon(":/res/Icons/AlarmIcon64.png"), timer->getName());
    else
        item = new QListWidgetItem(QIcon(":/res/Icons/TimerIcon64.png"), timer->getName());
    item->setBackground(Qt::gray);
    item->setForeground(QColor("#FFA500"));
    item->setFont(QFont("Helvetica", 16));
    _widget->addItem(item);

    _list->append(timer);
    connect(timer, SIGNAL(timeout(Timer*)), this, SIGNAL(timeout(Timer*)));
}

void ImprovisedModel::removeItem(int id){
    delete _list->takeAt(id);
    _widget->takeItem(id);
}

void ImprovisedModel::removeItem(Timer* timer){
    int j = 0;
    auto i = _list->begin();
    for(; i!=_list->end() && (*i)!=timer; i++, j++);
    if(i!=_list->end() && !(*i)->repeated()) removeItem(j);
}

void ImprovisedModel::shownItems(Timer::TimerType type){
    int j = 0;
    for(auto i = _list->begin(); i!=_list->end(); i++, j++)
        _widget->item(j)->setHidden(type!=Timer::other_t && (*i)->type()!=type);
}

QString ImprovisedModel::getTimerString(int id){
    return _list->at(id)->displayedString();
}

QString ImprovisedModel::getInfo(int id){
    QString res="<h2>";
    res.append(_list->at(id)->getName());
    res.append("</h2>\n\n");
    res.append(_list->at(id)->getNote());
    return res;
}

void ImprovisedModel::save(){
    QFile qfile("save.txt");
    if (qfile.open(QIODevice::WriteOnly)) {
        QTextStream out(&qfile);
        for(auto i = _list->begin(); i!=_list->end(); i++){
            out<<(*i)->getName().toUtf8()<<'\n';
            out<<(*i)->getNote().toUtf8()<<'\n';
            out<<QString::number((*i)->type()).toUtf8()<<'\n';
            out<<QString::number((*i)->asNum()).toUtf8()<<'\n';
            out<<QString::number((*i)->repeated()).toUtf8()<<'\n';
        }
        qfile.close();
    }
}

void ImprovisedModel::load(){
    QFile qfile("save.txt");
    if (qfile.open(QIODevice::ReadOnly)) {
        QString name, note, type, time, repeated;
        int msec;
        QDateTime date_time;
        QTextStream in(&qfile);
        while(!in.atEnd()){
            name = in.readLine();
            note = in.readLine();
            type = in.readLine();
            time = in.readLine();
            repeated = in.readLine();
            msec = time.toInt();
            if(type.toInt()==Timer::timer_t){
                addItem(new TimerClock(name, note, std::chrono::milliseconds(msec)));
            }
            else{
                date_time = QDateTime::currentDateTime();
                date_time.setTime(QTime().addMSecs(msec));
                if(date_time<=QDateTime::currentDateTime()) date_time = date_time.addDays(1);
                addItem(new AlarmClock(name, note, date_time, repeated.toInt()));
            }
        }
        qfile.close();
    }
}

ImprovisedModel::~ImprovisedModel(){
    for(auto i = _list->begin(); i!=_list->end(); i++)
        delete *i;
    delete _list;
}
