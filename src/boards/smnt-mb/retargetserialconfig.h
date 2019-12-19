#pragma once

// Configuration for SMENETE board

#define RETARGET_UART        USART0
#define RETARGET_IRQ_NAME    USART0_RX_IRQHandler
#define RETARGET_CLK         cmuClock_USART0
#define RETARGET_IRQn        USART0_RX_IRQn
#define RETARGET_TX          USART_Tx
#define RETARGET_RX          USART_Rx
#define RETARGET_TXPORT      gpioPortF
#define RETARGET_TXPIN       1
#define RETARGET_RXPORT      gpioPortF
#define RETARGET_RXPIN       0
#define RETARGET_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC25
#define RETARGET_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC23

#define RETARGET_USART       1  // vs RETARGET_LEUART

#define RETARGET_PERIPHERAL_ENABLE()

#define LOGGER_LDMA_USART0
