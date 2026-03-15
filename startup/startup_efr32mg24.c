/// @file startup_efr32mg24.c
/// @brief ARM Cortex-M33 startup code and vector table for EFR32MG24.
///
/// Defines the reset handler that copies initialized data from flash to RAM,
/// zeroes the BSS segment, and then calls the C runtime and application
/// entry point. All peripheral interrupt handlers are provided as weak
/// aliases to Default_Handler so they can be overridden by application code.

#include <stdint.h>

extern uint32_t _sidata;  ///< Start of initialized data image in flash.
extern uint32_t _sdata;   ///< Start of .data section in RAM.
extern uint32_t _edata;   ///< End of .data section in RAM.
extern uint32_t _sbss;    ///< Start of .bss section in RAM.
extern uint32_t _ebss;    ///< End of .bss section in RAM.
extern uint32_t _estack;  ///< Top of the main stack (provided by linker).

extern void SystemInit(void);
extern void __libc_init_array(void);
extern int  main(void);

/// @brief Default interrupt handler.
///
/// Invoked by any unhandled exception or interrupt. Spins forever to allow
/// a debugger to identify the unexpected interrupt source.
void Default_Handler(void) __attribute__((weak, noreturn));
void Default_Handler(void) {
  while (1) {}
}

/// @defgroup cortex_m33_exceptions ARM Cortex-M33 exception handlers
/// @brief Weak aliases to Default_Handler; override by defining the symbol.
/// @{
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SecureFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)      __attribute__((weak, alias("Default_Handler")));
/// @}

/// @defgroup efr32mg24_irq_handlers EFR32MG24 peripheral IRQ handlers
/// @brief Weak aliases to Default_Handler; override by defining the symbol.
/// @{
void CRYPTOACC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TRNG_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void PKE_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void SMU_SECURE_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SMU_S_PRIVILEGED_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void SMU_NS_PRIVILEGED_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EMU_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TIMER0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIMER1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIMER2_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIMER3_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIMER4_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void USART0_RX_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void USART0_TX_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void EUSART0_RX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EUSART0_TX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EUSART1_RX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EUSART1_TX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EUSART2_RX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EUSART2_TX_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void ICACHE0_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void BURTC_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void LETIMER0_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void SYSCFG_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void MPAHBRAM_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void LDMA_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void LFXO_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void LFRCO_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void ULFRCO_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void GPIO_ODD_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void GPIO_EVEN_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void I2C0_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EMUDG_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void AGC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void BUFC_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void FRC_PRI_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void FRC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void MODEM_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void PROTIMER_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void RAC_RSM_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void RAC_SEQ_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void RDMAILBOX_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void RFSENSE_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PRORTC_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void SYNTH_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void WDOG0_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void WDOG1_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void HFXO0_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void HFRCO0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void HFRCOEM23_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void CMU_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void AES_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void IADC_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void MSC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void DMEM_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EUART0_RX_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void EUART0_TX_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void VDAC_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void PCNT0_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void SW0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void SW1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void SW2_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void SW3_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void KERNEL0_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void KERNEL1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void M33CTI0_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void M33CTI1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void FPUEXH_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void SETAMPERHOST_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void SEMBRX_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void SEMBTX_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void SYSRTC_APP_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SYSRTC_SEQ_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void KEYSCAN_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void RFECA0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void RFECA1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
/// @}

/// @brief ARM reset handler; first code executed after power-on or reset.
///
/// Copies the .data section from flash to RAM, zeroes the .bss section,
/// then calls SystemInit(), the C++ static constructors via
/// __libc_init_array(), and finally main(). The trailing spin loop
/// prevents undefined behavior if main() returns.
void Reset_Handler(void) __attribute__((noreturn));
void Reset_Handler(void) {
  uint32_t *src = &_sidata;
  uint32_t *dst = &_sdata;

  while (dst < &_edata) {
    *dst++ = *src++;
  }

  dst = &_sbss;
  while (dst < &_ebss) {
    *dst++ = 0u;
  }

  SystemInit();
  __libc_init_array();
  main();

  while (1) {}
}

/// @brief Function pointer type used to populate the vector table.
typedef void (*VectorEntry)(void);

/// @brief EFR32MG24 interrupt vector table.
///
/// Placed in the `.vectors` section by the linker script. The first entry
/// is the initial stack pointer; subsequent entries are exception and
/// peripheral interrupt handlers in the order defined by the CMSIS
/// specification for the EFR32MG24.
__attribute__((section(".vectors"), used))
const VectorEntry __Vectors[] = {
    (VectorEntry)&_estack,   /* Initial stack pointer          */
    Reset_Handler,           /* Reset                          */
    NMI_Handler,             /* NMI                            */
    HardFault_Handler,       /* HardFault                      */
    MemManage_Handler,       /* MemManage                      */
    BusFault_Handler,        /* BusFault                       */
    UsageFault_Handler,      /* UsageFault                     */
    SecureFault_Handler,     /* SecureFault                    */
    0,                       /* Reserved                       */
    0,                       /* Reserved                       */
    0,                       /* Reserved                       */
    SVC_Handler,             /* SVCall                         */
    DebugMon_Handler,        /* DebugMonitor                   */
    0,                       /* Reserved                       */
    PendSV_Handler,          /* PendSV                         */
    SysTick_Handler,         /* SysTick                        */
    CRYPTOACC_IRQHandler,
    TRNG_IRQHandler,
    PKE_IRQHandler,
    SMU_SECURE_IRQHandler,
    SMU_S_PRIVILEGED_IRQHandler,
    SMU_NS_PRIVILEGED_IRQHandler,
    EMU_IRQHandler,
    TIMER0_IRQHandler,
    TIMER1_IRQHandler,
    TIMER2_IRQHandler,
    TIMER3_IRQHandler,
    TIMER4_IRQHandler,
    USART0_RX_IRQHandler,
    USART0_TX_IRQHandler,
    EUSART0_RX_IRQHandler,
    EUSART0_TX_IRQHandler,
    EUSART1_RX_IRQHandler,
    EUSART1_TX_IRQHandler,
    EUSART2_RX_IRQHandler,
    EUSART2_TX_IRQHandler,
    ICACHE0_IRQHandler,
    BURTC_IRQHandler,
    LETIMER0_IRQHandler,
    SYSCFG_IRQHandler,
    MPAHBRAM_IRQHandler,
    LDMA_IRQHandler,
    LFXO_IRQHandler,
    LFRCO_IRQHandler,
    ULFRCO_IRQHandler,
    GPIO_ODD_IRQHandler,
    GPIO_EVEN_IRQHandler,
    I2C0_IRQHandler,
    I2C1_IRQHandler,
    EMUDG_IRQHandler,
    AGC_IRQHandler,
    BUFC_IRQHandler,
    FRC_PRI_IRQHandler,
    FRC_IRQHandler,
    MODEM_IRQHandler,
    PROTIMER_IRQHandler,
    RAC_RSM_IRQHandler,
    RAC_SEQ_IRQHandler,
    RDMAILBOX_IRQHandler,
    RFSENSE_IRQHandler,
    PRORTC_IRQHandler,
    SYNTH_IRQHandler,
    WDOG0_IRQHandler,
    WDOG1_IRQHandler,
    HFXO0_IRQHandler,
    HFRCO0_IRQHandler,
    HFRCOEM23_IRQHandler,
    CMU_IRQHandler,
    AES_IRQHandler,
    IADC_IRQHandler,
    MSC_IRQHandler,
    DMEM_IRQHandler,
    EUART0_RX_IRQHandler,
    EUART0_TX_IRQHandler,
    VDAC_IRQHandler,
    PCNT0_IRQHandler,
    SW0_IRQHandler,
    SW1_IRQHandler,
    SW2_IRQHandler,
    SW3_IRQHandler,
    KERNEL0_IRQHandler,
    KERNEL1_IRQHandler,
    M33CTI0_IRQHandler,
    M33CTI1_IRQHandler,
    FPUEXH_IRQHandler,
    SETAMPERHOST_IRQHandler,
    SEMBRX_IRQHandler,
    SEMBTX_IRQHandler,
    SYSRTC_APP_IRQHandler,
    SYSRTC_SEQ_IRQHandler,
    KEYSCAN_IRQHandler,
    RFECA0_IRQHandler,
    RFECA1_IRQHandler,
};
