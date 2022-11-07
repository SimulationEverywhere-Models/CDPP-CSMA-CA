/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __TransducerType_H
#define __TransducerType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class TransducerType: public Atomic
{
public:
	TransducerType( const string &name = "TransducerType" ) ;	 // Default constructor
	~TransducerType();					// Destructor
	virtual string className() const
		{return "TransducerType";}

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
	typedef list<Value> ElementList ;
	ElementList elements;
	typedef list<int> ElementList2 ;
	ElementList2 times;
	const Port &msg_gen ;
	const Port &msg_sent ;
	 Port &throughput ;
	 Port &latency ;
	 int t1,t2;
	int totalBytes;
	// [(!) declare common variables]
	// Lifetime programmed since the last state transition to the next planned internal transition.
	Time sigma;
	
	// Time elapsed since the last state transition until now
	Time elapsed;
	
	// Time remaining to complete the last programmed Lifetime
	Time timeLeft;	
};	// class TransducerType


#endif   //__TransducerType_H 
