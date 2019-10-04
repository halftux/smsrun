
#include "smsrun.h"
#include "mainclass.h"
//#include <QDebug>
MainClass::MainClass(QObject *parent) :
	QObject(parent)
{
	// get the instance of the main application
	app = QCoreApplication::instance();
	// setup everything here
	// create any global objects
	// setup debug and warning mode
}

// 10ms after the application starts this method will run
// all QT messaging is running at this point so threads, signals and slots
// will all work as expected.
void MainClass::run()
{
	// Add your main code here
	//qDebug() << "MainClass.Run is executing";(

        m_run = new SmsRun(this);
        //connect(m_run, SIGNAL(finished()),this, SLOT(quit()));


	// you must call quit when complete or the program will stay in the
	// messaging loop
	//quit();
}

// call this routine to quit the application
void MainClass::quit()
{
	// you can do some cleanup here
	// then do emit finished to signal CoreApplication to quit
	emit finished();
}

// shortly after quit is called the CoreApplication will signal this routine
// this is a good place to delete any objects that were created in the
// constructor and/or to stop any threads
void MainClass::aboutToQuitApp()
{
	// stop threads
	//sleep(1);   // wait for threads to stop.
	// delete any objects
}
