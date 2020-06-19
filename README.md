Hello World!
This is a project I did a while back when I woke up late for work. Never again! I thought. So I spite-programmed this with an Arduino Uno and Adafruit NeoPixel (60 LEDs).

Lights fade from black (off) to red, added in green (makes yellow), and add in blue (makes white). This simulates a sunrise to gently wake you up from a dead sleep. Since Arduino works in milliseconds, there is math in the comments of the code to help convert from X minutes to Y milliseconds needed.

Please make sure to plug in the NeoPixel to analog Pin 6 and ground.
Please note: this uses a secondary, external wall timer which turns on the Arduino at a specified, custom time. Code runs automatically. Ideally, this would be plugged into a raspberry pi which would take care of everything - haven't gotten there yet.

Enjoy!
