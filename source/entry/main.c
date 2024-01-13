#include <stdio.h>

#include <hal.h>

int fputc(int ch, FILE *f) 
{
  return(ITM_SendChar(ch));
}

void soc_init(void)
{

}

void device_init(void)
{
    
}

void task_init(void)
{
    
}

int main(void)
{
  // It can be A9, A53, M3, M4, x86, ...
  // It contains the CPU IPs initialize
  // cpu_init
  
  // It can be STM32, ZYNQ, iMX6, ...
  // soc_init
  
  // The devices connected to SoC
  // device_init
  
  task_init();

  printf("Hello ITM\n");
  
  // handle messages
  
  while (1)
  {
    
  }
  
  return 0;
}
