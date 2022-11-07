/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __MeduimType_H
#define __MeduimType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class MeduimType: public Atomic
{
public:
	MeduimType( const string &name = "MeduimType" ) ;	 // Default constructor
	~MeduimType();					// Destructor
	virtual string className() const
		{return "MeduimType";}

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
	const Port &in1;
	const Port &in2;
	const Port &in3;
	const Port &in4;
	const Port &in5;
	const Port &in6;
	const Port &in7;
	const Port &in8;
	const Port &in9;
	const Port &in10;
	Port &forward1;
	Port &forward2;
	Port &forward3;
	Port &forward4;
	Port &forward5;
	Port &forward6;
	Port &forward7;
	Port &forward8;
	Port &forward9;
	Port &forward10;
	Port &busy0;
	Port &busy1;
	Port &busy2;
	Port &busy3;
	Port &busy4;
	Port &busy5;
	Port &busy6;
	Port &busy7;
	Port &busy8;
	Port &busy9;
	Port &busy10;
	Port &free0;
	Port &free1;
	Port &free2;
	Port &free3;
	Port &free4;
	Port &free5;
	Port &free6;
	Port &free7;
	Port &free8;
	Port &free9;
	Port &free10;
	//Port &temp;
int packet;
int from;
enum {free, t1 ,t2} stat;
	// [(!) declare common variables]
	// Lifetime programmed since the last state transition to the next planned internal transition.
	Time sigma;
	
	// Time elapsed since the last state transition until now
	Time elapsed;
	
	// Time remaining to complete the last programmed Lifetime
	Time timeLeft;	
};	// class MeduimType


#endif   //__MeduimType_H 
