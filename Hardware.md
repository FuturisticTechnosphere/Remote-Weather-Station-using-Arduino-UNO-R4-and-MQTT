## Hardware

- **DHT11 Sensor:** Connected to digital pin 7 for measuring humidity and temperature.
- **16x2 LCD Screen:** Connected as follows:
  - RS: 12
  - EN: 11
  - D4: 5
  - D5: 4
  - D6: 10
  - D7: 9
- **External LED:** Connected to digital pin 8 for temperature alert indication.
- **Rotary Encoder:** DATA (DT) pin connected to arduino interrupt pin 3 and CLOCK (CLK) pin connected to arduino interrupt pin 2.
- **Trimmer or Potentiometer:** Variable pin connected to the V0 pin of the LCD screen.
- **Two 220 Ω resistors:** Both used as Pull-up resistors, one connected between the LED+ pin of the LCD display and Vcc and one connected between external LED and Digital pin 7. 

## Schematics and Circuit Diagram

![Schematics](https://github.com/FuturisticTechnosphere/Remote-Weather-Station-using-Arduino-UNO-R4-and-MQTT/assets/138108581/b1fcb759-a521-4a8c-a775-3161c661a943)
![Schematics 2](https://github.com/FuturisticTechnosphere/Remote-Weather-Station-using-Arduino-UNO-R4-and-MQTT/assets/138108581/2cc4eef8-1293-4f13-8e25-9fd11c2ef3d7)
**N.B 1:** I used the KY-015 DHT11 module and the Rotary Encoder KY-040 module.

**N.B 2:** Pay attention to the schematics to know how to connect every component to Vcc and GND 
## License

- Hardware: CERN Open Hardware Licence
