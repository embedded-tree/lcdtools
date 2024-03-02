/*
  This header file contains adrresses and bits from the ATmega8A Datasheet.
  https://onlinedocs.microchip.com/pr/GUID-80B1922D-872B-40C8-A8A5-0CBE009FD908-en-US-3/index.html?GUID-84ECADDB-90D3-4957-A78C-2FF8F2EFA639
*/
#ifndef TWI_H
#define TWI_H

#define TWBR_REG (*(volatile uint8_t*)0x20)   //Bit rate register
#define TWSR_REG (*(volatile uint8_t*)0x21)   //Status register
#define TWAR_REG (*(volatile uint8_t*)0x22)   //Addr register
#define TWDR_REG (*(volatile uint8_t*)0x23)   //Data register
#define TWCR_REG (*(volatile uint8_t*)0x56)   //Control register

#define TWINT (1<<7)    //Interrupt flag
#define TWEA (1<<6)   //ACK generation
#define TWSTA (1<<5)    //START condition
#define TWSTO (1<<4)    //STOP condition
#define TWWC (1<<3)   //Write collision
#define TWEN (1<<2)   //Enables TWI module
#define TWIE (1<<0)   //Enables TWI interrupt

#define TW_START         0x08   //Start condition
#define TW_REP_START     0x10   //Repeated start condition
#define TW_MT_SLA_ACK    0x18   //SLA+W transmitted, ACK recieved
#define TW_MT_DATA_ACK   0x28   //Data transmitted, ACK recieved
#define TW_MR_SLA_ACK    0x40   //SLA+R transmiteed, ACK recieved
#define TW_MR_DATA_ACK   0x50   //Data recieved, ACK returned
#define TW_MR_DATA_NACK  0x58   //Data recieved, NACK returned

#endif