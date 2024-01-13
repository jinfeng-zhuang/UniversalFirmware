//
// Refer to ARMv7-M TRM
// Refer to CMSIS
//
// Jinfeng Zhuang, 2024.Week2
//_____________________________________________________________________________

#ifndef _DT_ARMV7M_H_
#define _DT_ARMV7M_H_

/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address */
#define DWT_BASE            (0xE0001000UL)                            /*!< DWT Base Address */
#define TPI_BASE            (0xE0040000UL)                            /*!< TPI Base Address */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */
#define FPU_BASE            (SCS_BASE +  0x0F30UL)                    /*!< Floating Point Unit */

#endif
