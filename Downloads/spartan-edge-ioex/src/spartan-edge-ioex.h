/*
 * spartan-edge-ioex - ioex library for spi2gpio bitstream
 */
 
// ensure this library description is only included once
#ifndef SPARTAN_EDGE_IOEX_H
#define SPARTAN_EDGE_IOEX_H 

#include <SPI.h>

enum {
  GPA_OE = 0x00,
  GPA_ODATA,
  GPA_IDATA,

  GPB_OE = 0x04,
  GPB_ODATA,
  GPB_IDATA,

  GPC_OE = 0x08,
  GPC_ODATA,
  GPC_IDATA,
  #define GPC_ALT_UART_TX   0x01
  #define GPC_ALT_UART_RX   0x02
  #define GPC_ALT_UART_MASK (GPC_ALT_UART_TX | GPC_ALT_UART_RX)
  GPC_ALT,

  GPD_OE = 0x0C,
  GPD_ODATA,
  GPD_IDATA,

  GPE_OE = 0x10,
  GPE_ODATA,
  GPE_IDATA,

  SK6805_CTRL = 0x14,
  SK6805_DATA,

  DAC_DATA0 = 0x16,
  DAC_DATA1,

  UART_DATA = 0x18,
  #define UART_STAT_TX_BUSY  0x10
  #define UART_STAT_RX_DV    0x01
  UART_STAT,

  GPZ_OE = 0x1C,
  GPZ_ODATA,
  GPZ_IDATA,
 
  ADC_DATA = 0x1F,

  GPF_OE = 0x20,
  GPF_ODATA,
  GPF_IDATA,
 };

/* GPIO_PORT define*/
#define GPIO_PORT_A GPA_OE
#define GPIO_PORT_B GPB_OE
#define GPIO_PORT_C GPC_OE
#define GPIO_PORT_D GPD_OE
#define GPIO_PORT_E GPE_OE
#define GPIO_PORT_Z GPZ_OE
#define GPIO_PORT_F GPF_OE

/* button define */
#define BTN_USER1       0x10
#define BTN_USER2       0x20
#define BTN_FPGA_RST    0x40
#define SWITCH_K1       0x01
#define SWITCH_K2       0x02
#define SWITCH_K3       0x04
#define SWITCH_K4       0x08

/* led define */
#define LED1 6
#define LED2 7
#define LED_ENABLE 0xC0
#define LED_DISABLE 0x00

/* RGBled define */
#define RGB_LED0 0
#define RGB_LED1 1

// library interface description
class spartan_edge_ioex {
  public:
    // constructors:
	spartan_edge_ioex();
	unsigned regRead(int address);
	unsigned regWrite(int address, int value);

	// GPIO control
	unsigned getGpioDir(unsigned GPIO_Port);
	void setGpioDir(unsigned GPIO_Port, unsigned Dirs);
	unsigned readGpioInputDataBit(unsigned GPIO_Port, unsigned GPIO_Pin);
	unsigned readGpioInputData(unsigned GPIO_Port);	
	unsigned readGpioOutputDataBit(unsigned GPIO_Port, unsigned GPIO_Pin);
	unsigned readGpioOutputData(unsigned GPIO_Port);
	void setGpioBits(unsigned GPIO_Port, unsigned GPIO_Pin);
	void resetGpioBits(unsigned GPIO_Port, unsigned GPIO_Pin);
	void writeGpioBit(unsigned GPIO_Port, unsigned GPIO_Pin, unsigned BitVal);
	void writeGpio(unsigned GPIO_Port, unsigned PortVal);

	// set RGBLed1/2 val 
	void setRGBLed(unsigned index, unsigned char red, unsigned char green, unsigned char blue);

	// ADC and DAC control 
	void enableAdc(void);
	unsigned long readAdcData(void);
	void writeDacData(unsigned voltVal);

	// read button status
	unsigned readButtonData(unsigned btnNum);

	// read switch status
	unsigned readSwithData(unsigned switchNum);

	// led1/2 control
	void enableLed(bool en);
	void setLed(unsigned ledNum);
	void clearLed(unsigned ledNum);
	void toggleLed(unsigned ledNum);

  private:
	// SPI2GPIO write
	const byte WRITE = 0b10000000;

	// set pin 10 as the slave select for the digital pot:
	int slaveSelectPin = 10;
	int resetPin = 9;
};

#endif
