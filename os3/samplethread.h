#ifndef SAMPLETHREAD_H
#define SAMPLETHREAD_H
#include <QObject>
class SampleThread :QObject
{
    Q_OBJECT
public:
    SampleThread();
    void doWork(int n= 20 );;
};

#endif // SAMPLETHREAD_H
