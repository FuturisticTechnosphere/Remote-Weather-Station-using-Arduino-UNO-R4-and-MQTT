---

# Smart Weather Station

## Project Overview

Developed collaboratively by Salvatore Zuccaro, Luigi Emiliano Basso, and Rosario Pipitone as part of the IoT (Internet of Things) course at the University of Palermo under the guidance of Professor Giuliano Fabrizio, the Smart Weather Station is designed to provide real-time weather data with interactive features.

### Key Features

1. **Live Temperature and Humidity Updates:**
   - Continuous monitoring of temperature and humidity levels at user-adjustable intervals (1 to 60 seconds) through an intuitive Rotary encoder interface.

2. **Interactive LCD Display:**
   - 16x2 LCD display showcasing real-time temperature and humidity data.

3. **Temperature Alerts with Visual Feedback:**
   - When the temperature exceeds a predefined threshold, an external LED signals critical temperature events accompanied by alert messages showed on the 16x2 LCD display.
   - Implementation of a 1°C hysteresis for smooth transitions.

4. **Data in JSON Format:**
   - Streamlined JSON message formatting for easy integration with other systems.

5. **Seamless Connectivity:**
   - Effortless connection to a pre-configured WiFi network using the IEEE-802.11 protocol.
   - Instant feedback on the assigned IP address via the serial interface.

6. **Efficient MQTT Messaging:**
   - Sending formatted weather data through the MQTT protocol to a designated topic (/\<IP-device>/env), with \<IP-Device> representing the dynamically assigned IP address.

7. **User-Friendly Node-Red Integration:**
   - Seamless integration with Node-Red, allowing users to effortlessly visualize and interact with the transmitted weather data.

8. **Smart Data Storage in MongoDB:**
   - Intelligent data storage in MongoDB, ensuring that each data entry is saved as a JSON object for enhanced query capabilities.

### Easy Setup and Demonstration

To showcase the project's capabilities:

- Implement MQTT, MongoDB, and Node-Red services on a local PC (using Virtualbox, VMWare, Docker, etc.).
- For effective data storage visualization, consider using the NOSQL booster application.

### Materials Needed

- Breadboard
- Jumper wires
- Arduino UNO R4
- Rotary Encoder
- DHT11 Temperature and Humidity Sensor
- RED Led

### Connectivity

- Utilizes the IEEE802.11 protocol for seamless wireless communication.

---
