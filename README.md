# Arduino Stoplight v1

![arduino_stoplight_v1](https://user-images.githubusercontent.com/18668800/196553444-44c10367-c7fd-425b-a560-c31bd7fbb96d.svg)

This is a basic Arduino project I created to experiment with using switches and buttons to control LEDs in a "stoplight" pattern. The diagram shown above was created using Fritzing. The red, yellow, and green LEDs are controlled using a button with the buttons' behavior being controlled by the switch connected with the blue LED. When the switch is in the LOW state, the blue LED will not be lit, and the other LEDs will alternate between being lit and unlit depending on their current state when pressed (lit -> unlit and vice versa). When the switch is in the HIGH state, the blue LED is lit to indicate that the other LEDs will only light up while their corresponding button is being pressed. Modifying the switch's state will turn off the red, yellow, and green LEDs if lit.
