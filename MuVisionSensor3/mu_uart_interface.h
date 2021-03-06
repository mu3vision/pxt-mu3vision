/*
 * morpx_uart_interface.h
 *
 *  Created on: 2019年9月4日
 *      Author: ysq
 */

#ifndef PRODUCTS_MORPXPROTOCOLANALYSIS_MORPX_UART_INTERFACE_H_
#define PRODUCTS_MORPXPROTOCOLANALYSIS_MORPX_UART_INTERFACE_H_

#include "pxt.h"

#if MICROBIT_CODAL
class MuUart {
 public:
  typedef NRF52Serial* hw_port_t;

  MuUart(hw_port_t hw_port);
  virtual ~MuUart();
  MuUart(const MuUart&) = delete;
  MuUart& operator=(const MuUart &) = delete;

  virtual size_t available(void);
  virtual size_t read(uint8_t* buf, size_t length);
  virtual size_t write(uint8_t* buf, size_t length);

 private:
 protected:
  hw_port_t hw_port_;
};
#else
class MuUart {
 public:
  typedef MicroBitSerial* hw_port_t;

  MuUart(hw_port_t hw_port);
  virtual ~MuUart();
  MuUart(const MuUart&) = delete;
  MuUart& operator=(const MuUart &) = delete;

  virtual size_t available(void);
  virtual size_t read(uint8_t* buf, size_t length);
  virtual size_t write(uint8_t* buf, size_t length);

 private:
 protected:
  hw_port_t hw_port_;
};
#endif
#endif /* PRODUCTS_MORPXPROTOCOLANALYSIS_MORPX_UART_INTERFACE_H_ */
