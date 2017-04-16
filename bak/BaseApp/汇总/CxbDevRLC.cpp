///////////////////////////////////////////////////////////
//  CxbDevRLC.cpp
//  Implementation of the Class CxbDevRLC
//  Created on:      13-4ÔÂ-2017 13:54:52
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevRLC.h"




void CxbDevRLC::Add(Component component){

}


void CxbDevRLC::Remove(Component component){

}




void CxbDevRLC_Leaf::Add(Component component){

	//// cannot add to a leaf


	//// cannot add to a leaf
}


void CxbDevRLC_Leaf::Remove(Component component){

	//// cannot remove from a leaf


	//// cannot remove from a leaf
}




void CxbDevRLC_Composite::Add(Component component){

	//children.addElement( component );


	//children.addElement( component );
}


void CxbDevRLC_Composite::Remove(Component component){

	//children.removeElement( component );


	//children.removeElement( component );
}