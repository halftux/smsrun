
#include <QtCore/QCoreApplication>
#include <QTimer>
#include <QTextStream>
#include "mainclass.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	bool showhelp=false;

	// create the main class
	MainClass myMain;

	// connect up the signals
	QObject::connect(&myMain, SIGNAL(finished()),
	                 &app, SLOT(quit()));
	QObject::connect(&app, SIGNAL(aboutToQuit()),
	                 &myMain, SLOT(aboutToQuitApp()));

	//get arguments
	showhelp  = qApp->arguments().contains("--help");


	// This code will show the help and in
	// 10ms it will quit the MainClass routine;
	if (showhelp)
	{
		QTextStream cout(stdout);
		cout << endl;
        cout << "smsrun v0.0.1 by halftux" << endl << endl;

        cout << "It listen on following org.ofono.MessageManager dbus signal" << endl;
        cout << "IncomingMessage looks for phone number and command to run." << endl;

		QTimer::singleShot(10, &myMain, SLOT(quit()));
	}
	else
	{
		// This code will start the messaging engine in QT and in
		// 10ms it will start the execution in the MainClass.run routine;
		QTimer::singleShot(10, &myMain, SLOT(run()));
	}

	return app.exec();
}
