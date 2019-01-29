/**
 * \file cryptography.h
 * \brief Various cryptography functions.
 * 
 * This file contains the declaration of various cryptographic functions.
 * They are used in order to prevent the player from looking into the 
 * resources files getting an insight on the story behind the game.
 */
#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <string>

/**
 * \namespace cryptography
 * \brief Various cryptography functions.
 * 
 * This namespace contains some useful cryptographic functions.
 */
namespace cryptography
{
	/**
	 * \brief Decrypts a string.
	 *
	 * This function decrypts a string that was encrypted 
	 * using the Caesar Cypher.
	 * The string will be saved in the same object where the 
	 * encrypted string is saved.
	 * 
	 * \param[in] str The original string that will be decrypted.
	 * It's the same string where the result will be saved.
	 * \param[in] key The key that will be used to decrypt the string (_optional_).
	 */
	std::string& decrypt(std::string& str, int key = 5);
}

#endif //_CRYPTO_H