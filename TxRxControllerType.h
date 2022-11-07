/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __TxRxControllerType_H
#define __TxRxControllerType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class TxRxControllerType: public Atomic
{
public:
	TxRxControllerType( const string &name = "TxRxControllerType" ) ;	 // Default constructor
	~TxRxControllerType();					// Destructor
	virtual string className() const
		{return "TxRxControllerType";}

protected:

	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	// const Port &in;	// this is an input port named 'in'
	// Port &out ;   	// this is an output port named 'out'
	// Distribution *dist ;
	// Distribution &distribution()	{ return *dist; }
	/**************************************************************************/
 const Port &free;
 const Port &busy;
 const Port &receive;
 const Port &dataIn;
 Port &send;
 Port &done;
 Port &msgSent;
 Port &debug;
 int timeSlot;
 int MsgRX;
 Time DIFS;
 Time SIFS;
 Time BOT;
 Time temp;
 int ack;
	enum {idle,waitingForFreeChannel, waitingDIFS, waitForAck,receiving, rcvAck,transmit, sendAck,waitSIFS} stat;
int currMsg;
bool chanFree;
	// [(!) declare common variables]
	// Lifetime programmed since the last state transition to the next planned internal transition.
	Time sigma;
	
	// Time elapsed since the last state transition until now
	Time elapsed;
	
	// Time remaining to complete the last programmed Lifetime
	Time timeLeft;	
};	// class TxRxControllerType


#endif   //__TxRxControllerType_H 
