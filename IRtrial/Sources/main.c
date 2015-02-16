/* ###################################################################
**     Filename    : main.c
**     Project     : IRtrial
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-12-10, 00:40, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**Main module.
**This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "SERVO2.h"
#include "SERVO1.h"
#include "IRsensor.h"
#include "WAIT1.h"
#include "BUTTON.h"
#include "ACTUATOR2.h"
#include "ACTUATOR1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* DEFINE VARIABLES */
#define WAITbutton_STATE 0
#define VISIT_STATE 1
#define WAITtrash_STATE 2
#define WHEREtogo_STATE 3
#define TRAV_STATE 4
#define PUSH_STATE 5
#define HOME_STATE 6



int count = 0;
int pos = 0;
int state = 0;

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */

/**********************FUNCTIONS****************************/

void rotate_ccw(){
	
	SERVO2_ClrVal(SERVO2_DeviceData);
	SERVO1_SetVal(SERVO1_DeviceData);
}

void rotate_clk(){
	
	SERVO2_SetVal(SERVO2_DeviceData);
	SERVO1_ClrVal(SERVO1_DeviceData);
}

void stop_servo(){
	
	SERVO2_ClrVal(SERVO2_DeviceData);
	SERVO1_ClrVal(SERVO1_DeviceData);
	WAIT1_Waitms(3000);
}

void push_actuator(){
	ACTUATOR1_SetVal(ACTUATOR1_DeviceData);
	ACTUATOR2_ClrVal(ACTUATOR2_DeviceData);
	WAIT1_Waitms(3000);
}

void pull_actuator(){
	ACTUATOR2_SetVal(ACTUATOR2_DeviceData);
	ACTUATOR1_ClrVal(ACTUATOR1_DeviceData);
	WAIT1_Waitms(3000);
}

void stop_actuator(){
	  					
	ACTUATOR2_ClrVal(ACTUATOR2_DeviceData);
	ACTUATOR1_ClrVal(ACTUATOR1_DeviceData);
}

void visit(){
	
	int flag = 0;
	
	//rotate_ccw();
	
	while(count != 2)
	{
		/*if(IRsensor_GetVal(IRsensor_DeviceData)==0){
			while (IRsensor_GetVal(IRsensor_DeviceData)==0); 
				flag = 1; 
				
		}else if (IRsensor_GetVal(IRsensor_DeviceData)== 0 && flag){			
			while (IRsensor_GetVal(IRsensor_DeviceData)== 0);
			
				count++;
				flag = 0;

			if(count == 1)
				at_pos = 1;
		}*/
		
		if(IRsensor_GetVal(IRsensor_DeviceData) == 0 && !flag)
		{
			count++;
			flag = 1;
			rotate_ccw();
		}
		
		if(IRsensor_GetVal(IRsensor_DeviceData) == 1)flag = 0;
	}
	count = 0;
	stop_servo();
}

void position(int pos){
	
	int flag = 0;
	
	//rotate_ccw();
	
	while(count != pos)
	{
		/*if(IRsensor_GetVal(IRsensor_DeviceData)==1){
			while (IRsensor_GetVal(IRsensor_DeviceData)==1); 
				flag = 1; 
				
		}else if (IRsensor_GetVal(IRsensor_DeviceData)== 0 && flag){			
			while (IRsensor_GetVal(IRsensor_DeviceData)== 0);
				
				count++;
				flag = 0;

			if(count == pos)
				at_pos = 1;
		}*/
		
		if(IRsensor_GetVal(IRsensor_DeviceData)== 0 && !flag)
		{
			count++;
			flag = 1;
			rotate_ccw();
			
		}	
		
		if(IRsensor_GetVal(IRsensor_DeviceData)== 1)flag = 0;
	}
	stop_servo();
}



void home(){
	
	int flag = 0;
	
	//rotate_clk();
	
	while(count != 0){
		
		/*if(IRsensor_GetVal(IRsensor_DeviceData)== 1){
			while (IRsensor_GetVal(IRsensor_DeviceData)== 1);
				flag = 1;
			
		}else if (IRsensor_GetVal(IRsensor_DeviceData)== 0 && flag){
			while (IRsensor_GetVal(IRsensor_DeviceData)== 0);
			
				count--;
				flag = 0;
		}*/
		
		if(IRsensor_GetVal(IRsensor_DeviceData)==0 && !flag)
		{
				
				count--;
				
				rotate_clk();
				flag = 1;
					
		}	
				
		if(IRsensor_GetVal(IRsensor_DeviceData)== 1)flag = 0;
	}
	
	stop_servo();
}

/**************************************************/


int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
  {
  /* Write your local variable definition here */
	
	
	
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  
  for(;;)
  {
	  while(1)
	  	{
	  		switch(state)		
	  		{
	  			case WAITbutton_STATE: 					
	  					 
	  					if(BUTTON_GetVal(BUTTON_DeviceData)){
	  						while(BUTTON_GetVal(BUTTON_DeviceData));
	  							state = 1;
	  					}
	  					break;
	  					
	  			case VISIT_STATE:
	  				
	  				visit();
	  				state = 2;
	  				
	  				break;
	  				
	  			  			
	  			case WAITtrash_STATE: 					// just wait for data from UART
	  					pos = 3;
	  					if(pos <=  4)
	  						state = 3; 
	  					break;
	  					
	  			case WHEREtogo_STATE:
	  				
	  				/*if (pos == 1){
	  					push_actuator();
	  					pull_actuator();
	  					stop_actuator();
	  					
	  					state = 6;
	  						
	  				}
	  				
	  				else*/
	  				if (pos == 0){
	  					count += 1;
	  					state = 6;
	  					
	  				}
	  				
	  				else if (pos > 0){
	  					state = 4;
	  				}
	  				break;
	  				
	  			case TRAV_STATE: 
	  					position(pos);
	  					state = 5;
	  					break;

	  			case PUSH_STATE: 
	  				
	  					push_actuator();
	  					pull_actuator();
	  					stop_actuator();

	  					state = 6;
	  					break;

	  			case HOME_STATE:
	  				
	  				
	  					count += 1;
	  					home(count);
	  					
	  				if(count == 0)
	  					state = 0;
	  				
	  					break;
	  		}
	  		
	  	}
  }
  


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
  /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
 }
/* END main */
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
