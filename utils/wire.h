#ifndef WIRE_H
#define WIRE_H
#include <stdint.h>
#define SLAVE_ADDR 0x10
typedef void (*ISR)(void);

volatile uint8_t recieveddata;
volatile bool recieved = false;
void isr(void);

class twowire
{
  private:
    
  public:
    void init_slave(uint8_t addr,ISR isr);
    void begin();
    void write(uint8_t dat);
    void onrecieve();
    void onrequest();
    ~twowire();
};

extern twowire wire;
#endif