/*	Brent Mello
	Color Cipher
	Cipher.h
	February 26, 2013
*/

#include<ctime>
#include<cstdlib>
#include<cmath>

struct color{
	double red, blue, green;
};

color randColor(){
	color random;
	random.red = ((double) rand() / (RAND_MAX));
	random.blue = ((double) rand() / (RAND_MAX));
	random.green = ((double) rand() / (RAND_MAX));
	return random;
};

class Cipher
{
	public:
	color _key, _secret, _encrypted;

	Cipher::Cipher(color key = randColor(), color secret = randColor()):
		_key(key), _secret(secret) {
		reset_encrypted();
	};

	void reset_encrypted() {
		_encrypted.red = 1.0;
		_encrypted.blue = 1.0;
		_encrypted.green = 1.0;
	}

	void set_encryptedBlend() {
		_encrypted.red = (_key.red + _secret.red)/2;
		_encrypted.blue = (_key.blue + _secret.blue)/2;
		_encrypted.green = (_key.green + _secret.green)/2;
	}

	void set_encryptedFmod() {
		_encrypted.red = fmod(_key.red, _secret.red);
		_encrypted.blue = fmod(_key.blue, _secret.blue);
		_encrypted.green = fmod(_key.green, _secret.green);
	}
};