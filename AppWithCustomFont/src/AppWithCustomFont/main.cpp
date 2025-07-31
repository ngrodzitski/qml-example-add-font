#include <AppWithCustomFont/version.hpp>

#include <iostream>
#include <filesystem>
#include <stdexcept>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QObject>
#include <QDebug>
#include <QFile>

#include <fmt/format.h>

namespace AppWithCustomFont
{

namespace fs = std::filesystem;

//
// main()
//

int main(int argc, char** argv)
{
    // TODO: Insert your logic here.


    std::cout << fmt::format( "{} v{}.{}.{}",
                              fs::path( argv[ 0 ] ).filename().string(),
                              APP_WITH_CUSTOM_FONT_VERSION_MAJOR,
                              APP_WITH_CUSTOM_FONT_VERSION_MINOR,
                              APP_WITH_CUSTOM_FONT_VERSION_PATCH ) << std::endl;

    for( int i=1; i < argc; ++i )
    {
        std::cout << fmt::format("argv[{}]: {}", i, argv[i] ) << std::endl;
    }

    QGuiApplication qtApp( argc, argv );
    QQmlApplicationEngine engine;

    const QUrl url(
        QStringLiteral( "qrc:/AppWithCustomFont/qml/MyMainWindow.qml" ) );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &qtApp,
        [ url ]( QObject * obj, const QUrl & objUrl ) {
            if( !obj && url == objUrl ) QCoreApplication::exit( -1 );
        },
        Qt::QueuedConnection );
    engine.load( url );

    const auto retValue = qtApp.exec();
    if( 0 != retValue )
    {
        qWarning() << "Application finished with error...";
    }

    return 0;
}

}  // namespace AppWithCustomFont
