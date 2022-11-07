	/********************************************************************
	*																	*
	*      				 Auto Generated File                            *
	*                     												*
	*********************************************************************/

	/** include files **/
	#include "TxRxControllerType.h"           // base header
	#include "message.h"       // InternalMessage ....
	#include "distri.h"        // class Distribution
	#include "mainsimu.h"      // class MainSimulator



	/*******************************************************************
	* Function Name: TxRxControllerType dataIn( addInputPort( "dataIn" ) ),
	* Description: constructor
	********************************************************************/
	TxRxControllerType::TxRxControllerType( const string &name ) : Atomic( name )
	, free( addInputPort( "free" ) )
	, busy( addInputPort( "busy" ) )
	, receive( addInputPort( "receive" ) )
	, dataIn( addInputPort( "dataIn" ) )
	, send( addOutputPort( "send" ) )
	,msgSent( addOutputPort( "msgSent" ) )
	,  done( addOutputPort( "done" ) )
	,  debug( addOutputPort( "debug" ) )
	,BOT(Time::Inf)
	,timeSlot(020)
	,temp(0,0,0,0)
	,ack(10)
	,DIFS(0,0,0,050)
	,SIFS(0,0,0,010)
	,currMsg(NULL)
	,chanFree(false)
	, stat(idle)
	// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
	// Ej:
	// ,out(addOutputPort( "out" ))
	// , in(addInputPort( "in" ))
	{//fprintf(stderr,"sdasad");
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
	Model &TxRxControllerType::initFunction()
	{
		// [(!) Initialize common variables]
		this->elapsed = Time::Zero;
		this->timeLeft = Time::Inf;
		this->sigma = Time::Inf; // stays in active state until an external event occurs;
		SIFS =*(new Time(0,0,0,20));
		DIFS =*(new Time(0,0,0,50));
		temp =*(new Time(0,0,0,50));
		ack = 10;
	//	this->sigma = Time::Zero; // force an internal transition in t=0;
stat = idle;
chanFree = true;
timeSlot = 5;
holdIn(passive,this->sigma);
		// TODO: add init code here. (setting first state, etc)
		this-> passivate();
			return *this ;
		// set next transition
		//holdIn( passive, this->sigma  ) ;
		//return *this ;
	}

	/*******************************************************************
	* Function Name: externalFunction
	* Description: This method executes when an external event is received.
	********************************************************************/
	Model &TxRxControllerType::externalFunction( const ExternalMessage &msg )
	{
		//[(!) update common variables]
		this->sigma = nextChange();
		this->elapsed = msg.time()-lastChange();
		this->timeLeft = this->sigma - this->elapsed;

	/*	//TODO: implement the external function here.
		// Remember you can use the msg object (mgs.port(), msg.value()) and you should set the next TA (you might use the holdIn method).
		// EJ:
		// if( msg.port() == in ) this->state()
		//{
		//	// Do something
		//	holdIn( active, this->timeLeft );
		// }*/
		if( msg.port() == dataIn ){
			currMsg = msg.value();
			int t = (rand()%5)*timeSlot;
			sendOutput( msg.time(), debug, t+5000) ;
			BOT =*(new Time(0,0,0,t));
			temp =msg.time();

			if (this->stat== idle){
	//int length  = (unsigned int)((byte) msg.value());

			if (chanFree){

				stat = waitingDIFS;
				this->sigma = DIFS+BOT;
				holdIn(active,this->sigma );}
			else
			{
				stat = waitingForFreeChannel;
				passivate();//holdIn(active,Time::Inf);
			}
			}else {
				//holdIn(active,this->elapsed);
			}


		}
if ( msg.port() == receive){
	if (this->stat == idle ||this->stat == waitingDIFS){
		stat = receiving;
		MsgRX = msg.value();
		int rx = MsgRX;
		int extra= rx / 1000;
		extra = extra*1000;
		rx = rx-extra;
		sendOutput( msg.time(), debug, rx+2000) ;
		sendOutput( msg.time(), debug, MsgRX) ;
		this ->sigma =*(new Time(0,0,0,rx));
		holdIn(active, this->sigma);

	}else{
	if (this->stat == waitForAck){
					stat = rcvAck;

					int rx = msg.value();
						int extra= rx / 1000;
						extra = extra*1000;
						rx = rx-extra;
						sendOutput( msg.time(), debug, rx+1000) ;
						this ->sigma =*(new Time(0,0,0,rx));
								holdIn(active, this->sigma);
				}else {
					//error
					sendOutput( msg.time(), debug, 111000) ;
				}

	}

}
		if ( msg.port() == free ){
			chanFree = true;
		if( this->stat== waitingForFreeChannel){
			stat=waitingDIFS;
		//	if (BOT == Time::Inf){
		//		BOT =*(new Time(0,0,0,(rand()%5)*timeSlot));}

			this->sigma = DIFS+BOT;
							holdIn(active,this->sigma );
		}
		else
		{
if (stat == idle){
	//holdIn(active,Time::Inf);
} else {
	//sendOutput( msg.time(), debug, 3000) ;
			//holdIn( active,	this->timeLeft ) ;
	}

		}}
		if ( msg.port() == busy ){
				chanFree = false;

			if( this->stat== waitingDIFS){
				stat= waitingForFreeChannel;
	//BOT = BOT - this->elapsed + DIFS;
			//	BOT = BOT - (msg.time()-temp) + DIFS;
	//if BOT = 0?
	sendOutput( msg.time(), debug, 4000) ;
	//sendOutput( msg.time(), debug, this->elapsed.currentTime()) ;
	holdIn( passive, Time::Inf) ;
			}else
			{
				if (stat == idle){
				//	holdIn(active,Time::Inf);
				} else{
				//holdIn( active,	this->timeLeft ) ;
				}}
		}

		return *this ;
	}

	/*******************************************************************
	* Function Name: internalFunction
	* Description: This method executes when the TA has expired, right after the outputFunction has finished.
	* 			   The new state and TA should be set.
	********************************************************************/
	Model &TxRxControllerType::internalFunction( const InternalMessage & )
	{
		//TODO: implement the internal function here


		//this->sigma = Time::Inf; // stays in passive state until an external event occurs;
		//holdIn( passive, this->sigma  );
			if( this->stat== waitingDIFS){

				stat = transmit;
				//BOT = Time::Inf;
						//holdIn for the length of the message
				int r = currMsg;
						int extra= r / 1000;
						extra = extra*1000;
						r = r-extra;
						this ->sigma =*(new Time(0,0,0,r));
						//this->sigma = (0,0,0,r);
						holdIn(active, this->sigma);


			}
			else {
				if( this->stat== transmit){

					stat = waitForAck;
					this->sigma = Time::Inf;
						holdIn(passive,this->sigma);	//holdIn for the length of the message
				}
				else {
					if(this->stat==rcvAck){
						//currMsg = NULL;
						stat = idle;
						this->sigma = Time::Inf;
																holdIn(passive,this->sigma);
					}
					else {

						if (this->stat==receiving){
							stat = waitSIFS;
							//holdin SIFS time
							this->sigma = SIFS;
							holdIn(active, this->sigma);
						}
						else {
							if (this->stat==waitSIFS){
								stat = sendAck;
								// holdIn for short ack time
								this ->sigma =*(new Time(0,0,0,ack));
								//this->sigma = (0,0,0,ack);
															holdIn(active, this->sigma);
							}
							else {
								if (this->stat==sendAck){
									if (currMsg == NULL ) {
										stat = idle;
										this->sigma = Time::Inf;
																holdIn(passive,this->sigma);
									}
									else
									{
										stat = waitingDIFS;
									//	BOT =*(new Time(0,0,0,(rand()%5)*timeSlot));
										this->sigma = DIFS+BOT;
										temp =*(new Time(0,0,0,0));
																	holdIn(active,this->sigma );

									}
								} else{

								/*	if (stat == rcvAck){
										stat = idle;
										//currMsg=NULL;
										this->sigma = Time::Inf;
										holdIn(passive,this->sigma);

									}*/

								}
							}

						}

					}

				}
			}
		return *this;

	}

	/*******************************************************************
	* Function Name: outputFunction
	* Description: This method executes when the TA has expired. After this method the internalFunction is called.
	*              Output values can be send through output ports
	********************************************************************/
	Model &TxRxControllerType::outputFunction( const InternalMessage &msg )
	{
		//TODO: implement the output function here
		// remember you can use sendOutput(time, outputPort, value) function.
		// sendOutput( msg.time(), out, 1) ;
		// sendOutput( msg.time(), out, 1) ;
		if (stat == waitingDIFS){
			sendOutput( msg.time(), send, currMsg) ;


		}
		else
		{
			if(stat == transmit){
				int x = currMsg/1000000;
				sendOutput( msg.time(), msgSent, currMsg) ;
				currMsg = NULL;
			}else
			{
				if(stat == rcvAck){

					sendOutput( msg.time(), done, 1) ;

						}else
						{
							if(stat == waitSIFS){
								int ackpacket = ack+ (MsgRX/1000)*1000;
										sendOutput( msg.time(), send, ackpacket) ;


						}

			}
		}}
		return *this;
	
	}
	
	TxRxControllerType::~TxRxControllerType()
	{
		//TODO: add destruction code here. Free distribution memory, etc.
	}
