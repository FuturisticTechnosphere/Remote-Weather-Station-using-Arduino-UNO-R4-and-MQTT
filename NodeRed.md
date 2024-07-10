### Node-RED Flow Description

1. **Ottone (MQTT Input Node):**
   - This node is responsible for receiving messages from an MQTT broker. It subscribes to a specific topic and receives the published messages.
   - In this setup, the node is labeled "Ottone" and is connected, indicating it is currently receiving messages.

2. **Meteo ArduinoR4 (MongoDB Output Node):**
   - This node is responsible for saving data to a MongoDB database. It inserts the incoming data into the specified database and collection.
   - Here, it is labeled "Meteo ArduinoR4" and shows a connection, indicating it is actively saving data to MongoDB.

3. **debug 1 (Debug Node):**
   - This node outputs messages to the debug pane, allowing you to see the messages passing through your flow.
   - It is connected to the "Ottone" node, which means it displays the incoming messages from the MQTT broker.

### Debug Pane (Right Sidebar)

- **Debug Output:**
  - The right sidebar displays the messages received and processed in real-time. It shows the temperature and humidity readings sent from the Arduino device.
  - The messages are formatted as JSON objects with fields for temperature ("Temperatura") and humidity ("Umidità").

### Connection Flow

- **Flow Connections:**
  - The "Ottone" node is connected to the "debug 1" node, which means the messages received from the MQTT topic are directly displayed in the debug pane.
  - The "Ottone" node is also connected to the "Meteo ArduinoR4" node, which implies that the messages received are being saved to a MongoDB database.

---

This flow illustrates the reception, monitoring, and storage of environmental data (temperature and humidity) from an Arduino device using MQTT in a Node-RED environment. The debug node helps in verifying the data flow, and the MongoDB node ensures the data is stored in the database for further analysis or retrieval.
