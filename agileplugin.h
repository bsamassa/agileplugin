#ifndef AGILEPLUGIN_H
#define AGILEPLUGIN_H

#include <QObject>
#include <iostream>
#include "qgisplugin.h" // Plugin interface

//#include "Qgis_tools.h"
#include "qgsmaptoolemitpoint.h"

// Forward declarations
class QAction;
class QgisInterface;

// Declaration of the AgilePlugin class
class AgilePlugin: public QObject, public QgisPlugin
{
Q_OBJECT

public:
    // Constructor (interface is passed at construction)
    explicit AgilePlugin(QgisInterface * interface);

    // Called when the plugin is enabled
    void initGui() override;

    // Called when the plugin is disabled
    void unload() override;

public slots:
    // Slot called when the plugin is launched
    void run();

    void onClicked(const QgsPoint &point, Qt::MouseButton button);
    void onDoubleclicked(const QgsPoint &point, Qt::MouseButton button);
    void DrawOverlay(QPainter* painter);

private:
    QgisInterface * m_GISInterface; // GIS interface
    QAction * m_action; // Action in the menu bar

    QgsMapToolEmitPoint * mpMapTool ;
    double x=-1;
    double y=-1;
};

#endif
