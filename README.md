Color-Cipher
============

Demonstrates basic Diffie-Hellman Key exchange using colors.
Adam and Bob agree on a secret color, let's say blue. Now Adam wants to send Bob a new color, red, but he's worried about color pirates. To keep the color pirates from learning this new color, Adam mixes it with the secret color, blue, and sends Bob purple. Bob then subtracts the secret color from purple, and discerns that Adam sent him the color red. In addition to color blending, the cipher can also use the fmod function, which accomplishes the same result.
