#ifndef BITS_H
#define BITS_H
/** 
 * \file bits.h
 * \defgroup Bits Bits
 * \code #include <bits.h> @endcode
 * 
 * \brief Bit manipulation Library.
 *
 * Library of bit manipulation macros to simplify single bit operations.
 *
 * Most efficient avr bit type: \p uint8_t
 *
 * Input "binary" can be any integer type
 *
 * \note Examples are for ATMega avr micro controllers.
 * \author Oozenthor
 */

/**\{*/
//////////////////////////////////////////////////////////////////////////
// ********* Bit shift **********
/**
 * \brief  Bit shift macro
 * \param  bit select which bit to set
 *
 * Bit Value macro defined for avr in sfr_defs.h (part of include io.h)
 *
 * \code #define _BV(bit) (1 << (bit)) \endcode
 *
 * \em i.e. \c _BV(2) will give \c 0b00000100
 *
 * As an alternative \c b(2) gives \c 0b00000100 as well
 *
 */
#define b(bit) (1 << (bit))
	
//////////////////////////////////////////////////////////////////////////
// ********* Set routines **********
/**
 * \brief  Set a bit to 1
 * \param  binary data to modify
 * \param  bit select which bit to set
 * 
 * To set bit 4 of output port PORTB: \code bSet(PORTB, PB4); \endcode
 */
#define bSet(binary,bit) ((binary) |= (1 << (bit)))

/**
 * \brief  Set a bit to 0 (clear)
 * \param  binary data to modify
 * \param  bit select which bit to set
 * 
 * To clear bit 2 of output port PORTC: \code bClear(PORTC, PC2); \endcode
 */
#define bClear(binary,bit) ((binary) &= ~(1 << (bit)))

/**
 * \brief  Flip a bit
 * \param  binary data to modify
 * \param  bit select which bit to set
 * 
 * To flip bit 3 of output port PORTD: \code bflip(PORTD, PD3); \endcode
 */
#define bFlip(binary,bit) ((binary) ^= (1 << (bit)))

/**
 * \brief  Write a value (1 or 0) to a bit
 * \param  binary data to modify
 * \param  bit select which bit to set
 * 
 * Writes a 1 to bit 6 of output port PORTD: \code bWrite(PORTD, PD6, 1); \endcode
 * Writes "Variable" (0 or 1) to bit 7 of output port PORTD: \code bWrite(PORTD, PD7, Variable); \endcode
 */
#define bWrite(binary,bit,value) (value ? ((binary) |= (1 << (bit))) : ((binary) &= ~(1 << (bit))))

//////////////////////////////////////////////////////////////////////////
// ********** Get routines **********

/**
 * \brief  Get the current value of an input (not bit shifted)
 * \param  binary data to scan
 * \param  bit select which bit to test
 * 
 * Gets bit 5 of input port PORTB (true as 0b00100000)
 * \code
 * uint8_t result;
 * result=bGet(PINB,PINB5);
 * \endcode
 */
#define bGet(binary,bit) ((binary) & (1 << (bit)))

/**
 * \brief  Get the current value of an input as a 1 or 0
 * \param  binary data to scan
 * \param  bit select which bit to test
 * 
 * Gets bit 6 of input port PORTB (true as 0b00000001)
 * \code
 * uint8_t result;
 * result=bTrue(PINB,PINB6);
 * \endcode
 */
#define bTrue(binary,bit) (((binary) >> (bit)) & 1)

/**\}*/

#endif //BITS_H