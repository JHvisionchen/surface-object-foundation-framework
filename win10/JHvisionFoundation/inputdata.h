#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QObject>
#include "globalvariable.h"
#include "camera.h"
#include "processing.h"

class InputData : public QObject
{
    Q_OBJECT

public:
    InputData();
    void cameraInput();
    void videoInput();
    void pictureInput();
    processing *processThread;

private:
    QImage frame;
    Camera *camera;
    bool cameraStarted;

};

#endif // INPUTDATA_H
