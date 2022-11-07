/*******************************************************************
*
*  	DESCRIPTION: class BufferType
*  	Original AUTHOR: Amir Barylko & Jorge Beyoglonian
*	Modified by : Shabani and Heli
*
*******************************************************************/

/** include files **/
#include "BufferType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator



/*******************************************************************
* Function Name: BufferType
* Description: constructor
********************************************************************/
BufferType::BufferType( const string &name ): Atomic (name)
, preparationTime (0, 0, 10, 0)
, msg_in(this->addInputPort( "msg_in" ) )
, done_in(this->addInputPort( "done_in" ) )
, job_out(this->addOutputPort( "job_out" ) )
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
// ,out(addOutputPort( "out" ))
// , in(addInputPort( "in" ))
{
	//string time (MainSimulator::Instance().getParameter( description(), "preparation"));
	//if (time != "") preparationTime = time;
	// TODO: add initialization code here. (reading parameters, initializing private vars, etc)
	// Code templates for reading parameters:
	// read string parameter:
	// 		stringVar = MainSimulator::Instance().getParameter( description(), "paramName" );
	// read int parameter:
	// 		intVar = str2Int( MainSimulator::Instance().getParameter( description(), "initial" ) );
	// read time parameter:
	//		timeVar = string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
	// read distribution parameters:
	//		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );
	//		MASSERT( dist ) ;
	//		for ( register int i = 0; i < dist->varCount(); i++ )
	//		{
	//			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
	//			dist->setVar( i, str2Value( parameter ) ) ;
	//		}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &BufferType::initFunction(){
	//list<unsigned int>::iterator it1,it2;
	//elements.erace(elements.begin(), elements.end());
	elements.clear();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &BufferType::externalFunction( const ExternalMessage &msg )
{
	//[(!) update common variables]

	if (msg.port() == msg_in){
		elements.push_back(msg.value());
		if (elements.size() == 1) holdIn (active, Time::Zero);
	}

	if (msg.port() == done_in){
		elements.pop_front();
		if (!elements.empty()) holdIn(active, Time::Zero);
	}

	//TODO: implement the external function here.
 	// Remember you can use the msg object (mgs.port(), msg.value()) and you should set the next TA (you might use the holdIn method).
 	// EJ:
 	// if( msg.port() == in )
	//{
	//	// Do something
	//	holdIn( active, this->timeLeft );
	// }

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &BufferType::internalFunction( const InternalMessage & )
{
	passivate();
	//TODO: implement the internal function here


//	this->sigma = Time::Inf; // stays in passive state until an external event occurs;
	//holdIn( passive, this->sigma  );
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &BufferType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	sendOutput ( msg.time(), job_out, elements.front());
	return *this;

}


