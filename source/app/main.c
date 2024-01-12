#include <stdio.h>

#include <hal.h>

volatile char *g_name = "LiuJia";

int fputc(int ch, FILE *f) 
{
  return(ITM_SendChar(ch));
}

int main(void)
{
  HAL_Init();
  
  (void)g_name;
  
  printf("Hello ITM %s\n", g_name);
  
  return 0;
}
