#ifndef PROCESSING_H
#define PROCESSING_H

#include "globalvariable.h"

class processing : public QThread
{
    Q_OBJECT

public:
    processing();

protected:
    void run();

signals:
    void newFrame(const QImage &frame);

private:
    QImage frame;
    Mat currentFrame;
    QMutex updateMembersMutex;
};

#endif // PROCESSING_H
