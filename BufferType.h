/*******************************************************************
*
*  	DESCRIPTION: class BufferType
*  	Original AUTHOR: Amir Barylko & Jorge Beyoglonian
*	Modified by : Shabani and Heli
*
*******************************************************************/

#ifndef __BufferType_H
#define __BufferType_H



/** include files **/
#include <list>
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class BufferType: public Atomic
{
public:
	BufferType(const string &name = "BufferType") ;	 // Default constructor
	virtual string className() const;


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
	const Port &msg_in;
	const Port &done_in;
	Port &job_out;
	//Port &temp;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements;
	Time timeLeft;
};	//class BufferType

inline
string BufferType::className() const
{
	return "BufferType" ;
}

#endif   //__BufferType_H
