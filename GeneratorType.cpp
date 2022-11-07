/*******************************************************************
*
*  	DESCRIPTION: class GeneratorType
*  	Original AUTHOR: Amir Barylko & Jorge Beyoglonian
*	Modified by : Shabani and Heli
*
*******************************************************************/

/** include files **/
#include "GeneratorType.h"       // base header
#include "message.h"       // class InternalMessage
#include "mainsimu.h"      // class Simulator
#include "distri.h"        // class Distribution
#include "strutil.h"       // str2Value( ... )

/*******************************************************************
* Function Name: GeneratorType
* Description: constructor
********************************************************************/
GeneratorType::GeneratorType( const string &name )
: Atomic( name )
, out( addOutputPort( "out" ) )
, msgCreated(addOutputPort("msgCreated"))
{
me = str2Int( MainSimulator::Instance().getParameter( description(), "ME" ) );
max = str2Int( MainSimulator::Instance().getParameter( description(), "MAX" ) );
	/* try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );
		MASSERT( dist ) ;
		for ( register int i = 0; i < dist->varCount(); i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
			dist->setVar( i, str2Value( parameter ) ) ;
		}

		if( MainSimulator::Instance().existsParameter( description(), "initial" ) )
			initial = str2Int( MainSimulator::Instance().getParameter( description(), "initial" ) );
		else
			initial = 0;

		if( MainSimulator::Instance().existsParameter( description(), "increment" ) )
			increment = str2Int( MainSimulator::Instance().getParameter( description(), "increment" ) );
		else
			increment = 1;

	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}*/
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &GeneratorType::initFunction()
{
	pid = 0;
	holdIn( active, Time::Zero ) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &GeneratorType::internalFunction( const InternalMessage & )
{
	//holdIn( active, Time( static_cast< float >( fabs( distribution().get() ) ) ) ) ;
	holdIn( active, *(new Time(0,0,0,500 ) )) ;
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &GeneratorType::outputFunction( const InternalMessage &msg )
{
	int length = 20 + rand()%130;
	int to = 1+rand()%max;
	while (to==me ){to = 1+rand()%max;}
	sendOutput( msg.time(), out, pid*1000+length+to*1000000 ) ;
	sendOutput( msg.time(), msgCreated, length ) ;
	pid= (pid+1)%1000;
	return *this ;
}

GeneratorType::~GeneratorType(){
	delete dist;
}
