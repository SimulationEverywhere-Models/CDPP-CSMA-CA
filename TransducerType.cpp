/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "TransducerType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: TransducerType
* Description: constructor
********************************************************************/
TransducerType::TransducerType( const string &name )
: Atomic( name )
, msg_gen( addInputPort( "msg_gen" ) )
, msg_sent( addInputPort( "msg_sent" ) )
, latency( addOutputPort( "latency" ) )
, throughput( addOutputPort( "throughput" ) )
,t2(0)
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
// ,out(addOutputPort( "out" ))
// , in(addInputPort( "in" ))
{
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
Model &TransducerType::initFunction()
{
	// [(!) Initialize common variables]
	this->elapsed = Time::Zero;
 	this->timeLeft = Time::Inf;
 	// this->sigma = Time::Inf; // stays in active state until an external event occurs;
 	this->sigma = Time::Zero; // force an internal transition in t=0;



 	elements.clear();
 	times.clear();
 	totalBytes=0;
 	t1=0;
 	t2=0;
 	holdIn(passive, Time::Inf);

 	// TODO: add init code here. (setting first state, etc)
 	
 	// set next transition
 	//holdIn( active, this->sigma  ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &TransducerType::externalFunction( const ExternalMessage &msg )
{
	//[(!) update common variables]	
	this->sigma = nextChange();	
	this->elapsed = msg.time()-lastChange();	
 	this->timeLeft = this->sigma - this->elapsed; 
	


	//TODO: implement the external function here.
 	// Remember you can use the msg object (mgs.port(), msg.value()) and you should set the next TA (you might use the holdIn method).
 	// EJ:
 	// if( msg.port() == in )
	//{
	//	// Do something
	//	holdIn( active, this->timeLeft );
	// }
	



		if (msg.port()== msg_gen){
			t1 =msg.time().asMsecs();
		elements.push_back(msg.value());
		times.push_back(t1);
			// carrier *x = (carrier *)malloc(sizeof(carrier));
			 //x->length = msg.value();
			 //x->time = t1;
			// elements.push_back(x);
			holdIn(passive, Time::Inf);
		}else
	{
		if (msg.port()== msg_sent){
	t2  = msg.time().asMsecs();

			holdIn(active, Time::Zero);
		}
	}


	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &TransducerType::internalFunction( const InternalMessage & )
{
	//TODO: implement the internal function here


	this->sigma = Time::Inf; // stays in passive state until an external event occurs;
	holdIn( passive, this->sigma  );
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &TransducerType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	
if (elements.size()>0){
	int x =  elements.front(); elements.pop_front();
			int L = times.front();times.pop_front();
			totalBytes+=x;
			L = t2-L;

			int tp = (int)((double)totalBytes*1000000/((double)t2)); // in bytes/second average of node
			sendOutput( msg.time(), latency, L ) ;
		sendOutput( msg.time(), throughput, tp)  ;
}

	return *this;

}

TransducerType::~TransducerType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
