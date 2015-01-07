/*
 * Application.c
 *
 *  Created on: Dec 1, 2014
 *      Author: JeanaTheGreat
 */

#include "Application.h"
#include "RxBuf.h"
#include "AS1.h"
 
static UART_Desc deviceData;
static UART_Desc deviceData2;
 
static void SendChar(unsigned char ch, UART_Desc *desc) {
  desc->isSent = FALSE;  /* this will be set to 1 once the block has been sent */
  while(AS1_SendBlock(desc->handle, (LDD_TData*)&ch, 1)!=ERR_OK) {} /* Send char */
  while(!desc->isSent) {} /* wait until we get the green flag from the TX interrupt */
}

static void SendChar2(unsigned char ch, UART_Desc *desc) {
  desc->isSent = FALSE;  /* this will be set to 1 once the block has been sent */
  while(AS2_SendBlock(desc->handle, (LDD_TData*)&ch, 1)!=ERR_OK) {} /* Send char */
  while(!desc->isSent) {} /* wait until we get the green flag from the TX interrupt */
}

static void SendString(const unsigned char *str,  UART_Desc *desc) {
  while(*str!='\0') {
    SendChar(*str++, desc);
  }
}

/*static void SendString2(const unsigned char *str,  UART_Desc *desc) {
  while(*str!='\0') {
    SendChar2(*str++, desc);
  }
}*/
 
static void Init(void) {
  /* initialize struct fields */
  deviceData.handle = AS1_Init(&deviceData);
  deviceData.isSent = FALSE;
  deviceData.rxChar = '\0';
  deviceData.rxPutFct = RxBuf_Put;
  /* set up to receive RX into input buffer */
  RxBuf_Init(); /* initialize RX buffer */
  /* Set up ReceiveBlock() with a single byte buffer. We will be called in OnBlockReceived() event. */
  while(AS1_ReceiveBlock(deviceData.handle, (LDD_TData *)&deviceData.rxChar, sizeof(deviceData.rxChar))!=ERR_OK) {} /* initial kick off for receiving data */
}

static void Init2(void) {
  /* initialize struct fields */
  deviceData2.handle = AS2_Init(&deviceData2);
  deviceData2.isSent = FALSE;
  deviceData2.rxChar = '\0';
  deviceData2.rxPutFct = RxBuf2_Put;
  /* set up to receive RX into input buffer */
  RxBuf2_Init(); /* initialize RX buffer */
  /* Set up ReceiveBlock() with a single byte buffer. We will be called in OnBlockReceived() event. */
  while(AS2_ReceiveBlock(deviceData2.handle, (LDD_TData *)&deviceData2.rxChar, sizeof(deviceData2.rxChar))!=ERR_OK) {} /* initial kick off for receiving data */
}
 
void APP_Run(void) {
  Init();
  Init2();
  SendString((unsigned char*)"Hello World\r\n", &deviceData);
  for(;;) {
    if (RxBuf_NofElements()!=0) {
      while (RxBuf_NofElements()!=0) {
        unsigned char ch;
 
        (void)RxBuf_Get(&ch);
        SendChar2(ch, &deviceData2);
      }
   //   SendString((unsigned char*)"\r\n", &deviceData);
    }
    if (RxBuf2_NofElements() !=0) {
        while (RxBuf2_NofElements()!=0) {
          unsigned char ch;
   
          (void)RxBuf2_Get(&ch);
          SendChar(ch, &deviceData);
        }
    }
  }
}
