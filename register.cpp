/*******************************************************************
*
*  Auto Generated File
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  This registration file is used to describe the atomic models that can be used to compose coupled models.
*
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "MeduimType.h"	// class MeduimType
#include "GeneratorType.h"
#include "TransducerType.h"
#include "TransducerType.h"	// class TransducerType

//#include "ggad.h"       // DEVS-Graphs interpreter
#include "TxRxControllerType.h"        // class TxRxControllerTypeType
#include "BufferType.h"
void MainSimulator::registerNewAtomics()
{
	// Register Built-in models

	// Register custom models
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TxRxControllerType>(), "TxRxControllerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MeduimType>() , "MeduimType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BufferType>() , "BufferType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<GeneratorType>() , "GeneratorType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TransducerType>() , "TransducerType" ) ;

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TransducerType>() , "TransducerType" ) ;
}
