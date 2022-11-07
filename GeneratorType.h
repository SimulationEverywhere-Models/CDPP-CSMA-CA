/*******************************************************************
*
*  	DESCRIPTION: class GeneratorType
*	Original AUTHOR: Amir Barylko & Jorge Beyoglonian
*	Modified by : Shabani and Heli
*
*******************************************************************/

#ifndef __GeneratorType_H
#define __GeneratorType_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** forward declarations **/
class Distribution ;

/** declarations **/
class GeneratorType : public Atomic
{
public:
	GeneratorType( const string &name = "GeneratorType" );				  // Default constructor
	~GeneratorType();

	virtual string className() const
		{return "GeneratorType";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & )
			{throw InvalidMessageException();}

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	int pid;
	int me;
	int max;
	int initial, increment;
	Port &out ;
	Port &msgCreated ;
	Distribution *dist ;

	Distribution &distribution()
			{return *dist;}

};	// class GeneratorType


#endif   //__GeneratorType
