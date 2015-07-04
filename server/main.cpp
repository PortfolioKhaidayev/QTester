#include <QCoreApplication>

#include "network/networkmanager.h"
#include "../common/ParametrParser/parametrparser.h"

struct CommandLineArgs{
    QString port = "3434";
};
CommandLineArgs parseCommandLineArgs( int argc, char* argv[] ){
    CommandLineArgs args;

    ParametrParser parser(argc, argv);

    parser.setOption( "p", "port", [&](std::string arg){
        args.port = QString::fromStdString( arg );
    } );

    try {
        parser.exec();
    } catch ( ParametrParser::UnknownOption e ) {
        qWarning() << "Unknown option: " << QString::fromStdString( e.optionName );
    }

    return args;
}

namespace ReturnCodes {
    enum ReturnCodes{
        success = 0,
        invalidPort
    };
}

int main( int argc, char *argv[] )
{
    setlocale( LC_ALL, "Russian" );
    QCoreApplication a( argc, argv );
    CommandLineArgs args = parseCommandLineArgs(argc, argv);

    a.setApplicationName("QTester_server");
    a.setApplicationVersion("0.1.2 PreAlpha");
    a.setOrganizationName("Slavjan");

    bool toIntSuccess = false;
    int port = args.port.toInt( &toIntSuccess );
    if( ! toIntSuccess ){
        qCritical() << "Invalid Port";
        return ReturnCodes::invalidPort;
    }

    NetworkManager netMan( port );

    return a.exec();
}
