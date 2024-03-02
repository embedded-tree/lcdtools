#include "wire.h"
#include "twi.h"

void twowire::init_slave(uint8_t addr,ISR isr){
  TWAR_REG = (addr << 1);
  TWCR_REG = (1<<TWEN) | (1<<TWEA) | (1<<TWIE);
}

void twowire::write(uint8_t dat){
  TWDR_REG = dat;
  TWCR_REG = (1<<TWEN) | (1<<TWINT);
  while (!(TWCR_REG&(1<<TWINT)));
}

void twowire::onrequest(){

}

void twowire::onrecieve(){

}

void isr(void){
  switch (TWSR_REG&0xF8)
  {
  case TW_START:
  case TW_REP_START:
    TWDR_REG = (SLAVE_ADDR<<1);
    TWCR_REG = (1<<TWEN) | (1<<TWEA) | (1<<TWINT);
    break;
  case TW_MT_SLA_ACK:
  case TW_MT_DATA_ACK:
    break;
  case TW_MR_SLA_ACK:
    TWCR_REG = (1<<TWEN) | (1<<TWEA) | (1<<TWINT);
    break;
  case TW_MR_DATA_ACK:
    recieveddata = TWDR_REG;
    recieved = true;
    TWCR_REG = (1<<TWEN) | (1<<TWEA) | (1<<TWINT);
    break;
  case TW_MR_DATA_NACK:
    recieveddata = TWDR_REG;
    recieved = true;
    TWCR_REG = (1<<TWEN) | (1<<TWINT);
    break;
  default:
    break;
  }
}