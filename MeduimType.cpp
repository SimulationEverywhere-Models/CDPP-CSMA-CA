/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "MeduimType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: MeduimType
* Description: constructor
********************************************************************/
MeduimType::MeduimType( const string &name )
: Atomic( name )
, in1( addInputPort( "in1" ) )
, in2( addInputPort( "in2" ) )
, in3( addInputPort( "in3" ) )
, in4( addInputPort( "in4" ) )
, in5( addInputPort( "in5" ) )
, in6( addInputPort( "in6" ) )
, in7( addInputPort( "in7" ) )
, in8( addInputPort( "in8" ) )
, in9( addInputPort( "in9" ) )
, in10( addInputPort( "in10" ) )

, forward1( addOutputPort( "forward1" ) )
, forward2( addOutputPort( "forward2" ) )
, forward3( addOutputPort( "forward3" ) )
, forward4( addOutputPort( "forward4" ) )
, forward5( addOutputPort( "forward5" ) )
, forward6( addOutputPort( "forward6" ) )
, forward7( addOutputPort( "forward7" ) )
, forward8( addOutputPort( "forward8" ) )
, forward9( addOutputPort( "forward9" ) )
, forward10( addOutputPort( "forward10" ) )
, free0( addOutputPort( "free0" ) )
, free1( addOutputPort( "free1" ) )
, free2( addOutputPort( "free2" ) )
, free3( addOutputPort( "free3" ) )
, free4( addOutputPort( "free4" ) )
, free5( addOutputPort( "free5" ) )
, free6( addOutputPort( "free6" ) )
, free7( addOutputPort( "free7" ) )
, free8( addOutputPort( "free8" ) )
, free9( addOutputPort( "free9" ) )
, free10( addOutputPort( "free10" ) )
, busy0( addOutputPort( "busy0" ) )
, busy1( addOutputPort( "busy1" ) )
, busy2( addOutputPort( "busy2" ) )
, busy3( addOutputPort( "busy3" ) )
, busy4( addOutputPort( "busy4" ) )
, busy5( addOutputPort( "busy5" ) )
, busy6( addOutputPort( "busy6" ) )
, busy7( addOutputPort( "busy7" ) )
, busy8( addOutputPort( "busy8" ) )
, busy9( addOutputPort( "busy9" ) )
, busy10( addOutputPort( "busy10" ) )
,packet(0),from(0)
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
// ,out(addOutputPort( "out" ))
// , in(addInputPort( "in" ))
{packet = 0;
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
Model &MeduimType::initFunction()
{
	// [(!) Initialize common variables]
	this->elapsed = Time::Zero;
 	this->timeLeft = Time::Inf;
 	 this->sigma = Time::Inf; // stays in active state until an external event occurs;
 	//this->sigma = Time::Zero; // force an internal transition in t=0;

 	// TODO: add init code here. (setting first state, etc)
 	stat = free;
 	// set next transition
 	holdIn( passive, this->sigma  ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &MeduimType::externalFunction( const ExternalMessage &msg )
{
	//[(!) update common variables]	
	this->sigma = nextChange();	
	this->elapsed = msg.time()-lastChange();	
 	this->timeLeft = this->sigma - this->elapsed; 
 	bool in = msg.port()==in1 || msg.port()==in2|| msg.port()==in3 ||msg.port()==in4 ||msg.port()==in5 ||msg.port()==in6 ||msg.port()==in7 ||msg.port()==in8 ||msg.port()==in9 ||msg.port()==in10;
if (msg.port()==in1){from = 1;}
if (msg.port()==in2){from = 2;}
if (msg.port()==in3){from = 3;}
if (msg.port()==in4){from = 4;}
if (msg.port()==in5){from = 5;}
if (msg.port()==in6){from = 6;}
if (msg.port()==in7){from = 7;}
if (msg.port()==in8){from = 8;}
if (msg.port()==in9){from = 9;}
if (msg.port()==in10){from = 10;}
 	if (in){
		if (stat ==free){
			stat = t1;
		packet = msg.value();

		/*int extra = packet/1000;
			extra =extra*1000;

			sendOutput( msg.time(), busy5, packet - extra) ;*/
		this->sigma=Time::Zero;
		holdIn(active,this ->sigma);
	}else{
		//error?
		sendOutput( msg.time(), busy5, 111000) ;
	}}
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
Model &MeduimType::internalFunction( const InternalMessage & )
{
	//TODO: implement the internal function here

if(stat==t1){stat = t2;
	int extra = packet/1000;
	extra =extra*1000;
	//

			this ->sigma =*(new Time(0,0,0,packet - extra));
	holdIn(active,this ->sigma );
}else{
	if(stat==t2){

		stat = free;
		this ->sigma = Time::Inf;
			holdIn(passive,this ->sigma);
	}

}
//	this->sigma = Time::Inf; // stays in passive state until an external event occurs;
	//holdIn( passive, this->sigma  );
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &MeduimType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	if (stat==t1){
		/*switch(packet/1000000){
			case 1: temp = forward1; break;
			case 2: temp = forward2; break;
			case i3: temp = forward3; break;
			case 4: temp = forward4; break;
			case 5: temp = forward5; break;
			case 6: temp = forward6; break;
			case 7: temp = forward7; break;
			case 8: temp = forward8; break;
			case 9: temp = forward9; break;
			case 10: temp = forward10; break;


			}*/
int to = packet/1000000;
packet = packet + 1000000*(-to+from);
		switch(to){
					case 1: sendOutput( msg.time(), forward1, packet) ; break;
					case 2: sendOutput( msg.time(), forward2, packet) ; break;
					case 3: sendOutput( msg.time(), forward3, packet) ; break;
					case 4: sendOutput( msg.time(), forward4, packet) ; break;
					case 5: sendOutput( msg.time(), forward5, packet) ; break;
					case 6: sendOutput( msg.time(), forward6, packet) ; break;
					case 7:sendOutput( msg.time(), forward7, packet) ; break;
					case 8: sendOutput( msg.time(), forward8, packet) ; break;
					case 9: sendOutput( msg.time(), forward9, packet) ; break;
					case 10: sendOutput( msg.time(), forward10, packet) ; break;


					}
		sendOutput( msg.time(), busy0, 1) ;
		sendOutput( msg.time(), busy1, 1) ;
		sendOutput( msg.time(), busy2, 1) ;
		sendOutput( msg.time(), busy3, 1) ;
		sendOutput( msg.time(), busy4, 1) ;
		sendOutput( msg.time(), busy5, 1) ;
		sendOutput( msg.time(), busy6, 1) ;
		sendOutput( msg.time(), busy7, 1) ;
		sendOutput( msg.time(), busy8, 1) ;
		sendOutput( msg.time(), busy9, 1) ;
		sendOutput( msg.time(), busy10, 1) ;

	}else
	{
		if (stat == t2)
		{sendOutput( msg.time(), free0, 1) ;
			sendOutput( msg.time(), free1, 1) ;
					sendOutput( msg.time(), free2, 1) ;
					sendOutput( msg.time(), free3, 1) ;
					sendOutput( msg.time(), free4, 1) ;
					sendOutput( msg.time(), free5, 1) ;
					sendOutput( msg.time(), free6, 1) ;
					sendOutput( msg.time(), free7, 1) ;
					sendOutput( msg.time(), free8, 1) ;
					sendOutput( msg.time(), free9, 1) ;
					sendOutput( msg.time(), free10, 1) ;

		}

	}
	return *this;

}

MeduimType::~MeduimType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
