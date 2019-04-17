// Sanket Patil and Sagar Bhatnagar final project i2c driver.

#include "i2c.h"
#include <MKL25Z4.h>
#include <stdint.h>
#include <stdbool.h>


static void i2c0_do_start()

{
	I2C0->C1 |= I2C_C1_MST_MASK;
}

static void i2c0_do_stop()
{
	I2C0->C1 &= ~I2C_C1_MST_MASK;
}

static void i2c0_do_repeat_start()
{
	I2C0->C1 |= I2C_C1_RSTA_MASK;
}

static void i2c0_config_transmit()
{
	I2C0->C1 |= I2C_C1_TX_MASK;
}

static void i2c0_config_receive()
{
	I2C0->C1 &= ~I2C_C1_TX_MASK;
}
static _Bool i2c0_is_busy()
{
	return I2C0->S & I2C_S_BUSY_MASK;
}

static _Bool i2c0_last_transmission_is_complete()
{
	return (I2C0->S & I2C_S_IICIF_MASK);
}

static void i2c0_wait_for_transmission_is_complete()
{
	while (!i2c0_last_transmission_is_complete());
	I2C0->S |= I2C_S_IICIF_MASK;
}

static void i2c0_put_data( uint8_t data)
{
	I2C0->D = data;
}

static void i2c0_next_read_nack()
{
	I2C0->C1 |= I2C_C1_TXAK_MASK;
}

static void i2c0_next_read_ack()
{
	I2C0->C1 &= ~I2C_C1_TXAK_MASK;
}

static void i2c0_start_tansfer ( uint8_t dev , uint8_t reg )
{

	while( i2c0_is_busy() );
	i2c0_config_transmit();
	i2c0_do_start();
	i2c0_put_data(dev);
	i2c0_wait_for_transmission_is_complete();
	i2c0_put_data(reg);
	i2c0_wait_for_transmission_is_complete();
}

void i2c0_write_bytes( uint8_t dev, uint8_t reg, uint8_t data)
{
	i2c0_start_tansfer (dev , reg );
	i2c0_put_data(data);
	i2c0_wait_for_transmission_is_complete();
	i2c0_do_stop();
}

static uint8_t get_i2c0_data_register()
{
	return I2C0->D;
}

void i2c0_read_bytes( uint8_t dev, uint8_t reg, uint8_t count, uint8_t *buf)
{
	unsigned i;
	i2c0_start_tansfer (dev , reg );
	i2c0_do_repeat_start();
	i2c0_put_data(dev | 0x1);
	i2c0_wait_for_transmission_is_complete();
	i2c0_config_receive();
	get_i2c0_data_register();
	for( i=0; i < count-1 ; i=i+1)
	{
		i2c0_next_read_ack();
		i2c0_wait_for_transmission_is_complete();
		*buf = get_i2c0_data_register();
		buf= buf+1;
	}
	i2c0_next_read_nack();
	i2c0_wait_for_transmission_is_complete();
	i2c0_do_stop();
	*buf= get_i2c0_data_register();
}

uint8_t i2c0_read_byte( uint8_t dev , uint8_t reg)
{
	uint8_t x;
	i2c0_read_bytes(dev, reg, 1, &x);
	return x;
}

void initialize_i2c0()
{
	SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	PORTE->PCR[24] |= PORT_PCR_MUX(5);
	PORTE->PCR[25] |= PORT_PCR_MUX(5);

	I2C0->F = I2C_F_ICR(0x0F) | I2C_F_ICR(0x0);

	I2C0->C1 |= I2C_C1_IICEN_MASK;
	I2C0->C2 |= I2C_C2_HDRS_MASK;

	
}
	
