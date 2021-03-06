/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : RxBuf2.h
**     Project     : FRDM_HelloWorld
**     Processor   : MKL25Z128VLK4
**     Component   : RingBufferUInt8
**     Version     : Component 01.003, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-12-01, 23:39, # CodeGen: 3
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         Put             - byte RxBuf2_Put(byte elem);
**         Get             - byte RxBuf2_Get(byte *elemP);
**         NofElements     - byte RxBuf2_NofElements(void);
**         NofFreeElements - byte RxBuf2_NofFreeElements(void);
**         Init            - void RxBuf2_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file RxBuf2.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup RxBuf2_module RxBuf2 module documentation
**  @{
*/         

#ifndef __RxBuf2_H
#define __RxBuf2_H

/* MODULE RxBuf2. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"


#define RxBuf2_BUF_SIZE   64  /* number of elements in the buffer */


byte RxBuf2_Put(byte elem);
/*
** ===================================================================
**     Method      :  RxBuf2_Put (component RingBufferUInt8)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RxBuf2_Get(byte *elemP);
/*
** ===================================================================
**     Method      :  RxBuf2_Get (component RingBufferUInt8)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

byte RxBuf2_NofElements(void);
/*
** ===================================================================
**     Method      :  RxBuf2_NofElements (component RingBufferUInt8)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

void RxBuf2_Init(void);
/*
** ===================================================================
**     Method      :  RxBuf2_Init (component RingBufferUInt8)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte RxBuf2_NofFreeElements(void);
/*
** ===================================================================
**     Method      :  RxBuf2_NofFreeElements (component RingBufferUInt8)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/

/* END RxBuf2. */

#endif
/* ifndef __RxBuf2_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
