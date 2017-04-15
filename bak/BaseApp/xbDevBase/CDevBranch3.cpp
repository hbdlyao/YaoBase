///////////////////////////////////////////////////////////
//  CDevBranch3.cpp
//  Implementation of the Class CxbDevBranch3
//  Created on:      05-4月-2017 18:06:38
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CDevBranch3.h"





/**
 * 3P的等效电导
 */
double CDevBranch3::GetYg(){

	return Yg;
}


/**
 * 3P的等效电导
 */
void CDevBranch3::SetYg(double newVal){

	Yg = newVal;
}


/**
 * 3P的等效电纳
 */
double CDevBranch3::GetYb(){

	return Yb;
}


/**
 * 3P的等效电纳
 */
void CDevBranch3::SetYb(double newVal){

	Yb = newVal;
}