/*
	This file is part of Warzone 2100.
	Copyright (C) 1999-2004  Eidos Interactive
	Copyright (C) 2005-2010  Warzone 2100 Project

	Warzone 2100 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Warzone 2100 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Warzone 2100; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
/** @file
 *  Routines for managing object's memory
 */

#ifndef __INCLUDED_SRC_OBJMEM_H__
#define __INCLUDED_SRC_OBJMEM_H__

#include "objectdef.h"

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/* The lists of objects allocated */
extern DROID			*apsDroidLists[MAX_PLAYERS];
extern STRUCTURE		*apsStructLists[MAX_PLAYERS];
extern FEATURE			*apsFeatureLists[MAX_PLAYERS];
extern FLAG_POSITION		*apsFlagPosLists[MAX_PLAYERS];
extern BASE_OBJECT		*apsSensorList[1];
extern BASE_OBJECT		*apsOilList[1];

/* The list of destroyed objects */
extern BASE_OBJECT	*psDestroyedObj;

/* Initialise the object heaps */
extern BOOL objmemInitialise(void);

/* Release the object heaps */
extern void objmemShutdown(void);

/* General housekeeping for the object system */
extern void objmemUpdate(void);

/* Create a new droid */
extern DROID* createDroid(UDWORD player);

/* add the droid to the Droid Lists */
extern void addDroid(DROID *psDroidToAdd, DROID *pList[MAX_PLAYERS]);

/*destroy a droid */
void killDroid(DROID *psDel);

/* Remove all droids */
extern void freeAllDroids(void);

/*Remove a single Droid from its list*/
extern void removeDroid(DROID *psDroidToRemove, DROID *pList[MAX_PLAYERS]);

/*Removes all droids that may be stored in the mission lists*/
extern void freeAllMissionDroids(void);

/*Removes all droids that may be stored in the limbo lists*/
extern void freeAllLimboDroids(void);

/* Create a new structure */
extern STRUCTURE* createStruct(UDWORD player);

/* add the structure to the Structure Lists */
extern void addStructure(STRUCTURE *psStructToAdd);

/* Destroy a structure */
void killStruct(STRUCTURE *psDel);

/* Remove all structures */
extern void freeAllStructs(void);

/*Remove a single Structure from a list*/
extern void removeStructureFromList(STRUCTURE *psStructToRemove,
                                    STRUCTURE *pList[MAX_PLAYERS]);

/* Create a new Feature */
extern FEATURE* createFeature(void);

/* add the feature to the Feature Lists */
 extern void addFeature(FEATURE *psFeatureToAdd);

/* Destroy a feature */
void killFeature(FEATURE *psDel);

/* Remove all features */
extern void freeAllFeatures(void);

/* Create a new Flag Position */
extern BOOL createFlagPosition(FLAG_POSITION **ppsNew, UDWORD player);
/* add the Flag Position to the Flag Position Lists */
extern void addFlagPosition(FLAG_POSITION *psFlagPosToAdd);
/* Remove a Flag Position from the Lists */
extern void removeFlagPosition(FLAG_POSITION *psDel);
// free all flag positions
extern void freeAllFlagPositions(void);
extern void freeAllAssemblyPoints(void);

// Find a base object from it's id
extern BASE_OBJECT *getBaseObjFromId(UDWORD id);
extern BOOL checkValidId(UDWORD id);

extern UDWORD getRepairIdFromFlag(FLAG_POSITION *psFlag);

void objCount(int *droids, int *structures, int *features);

#ifdef DEBUG
extern void checkFactoryFlags(void);
#endif

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // __INCLUDED_SRC_OBJMEM_H__
