#include "MainWindow.h"
#include <QApplication>

#ifdef _WIN32
#include <Windows.h>

extern "C" __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;

extern "C" __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 0x00000001;
#endif // _WIN32

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle(QObject::tr("基于GPU预计算的大气层光效渲染"));
    window.show();

    return app.exec();
}
