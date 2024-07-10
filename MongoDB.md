### MongoDB Configuration and Usage

![image (1)](https://github.com/FuturisticTechnosphere/Remote-Weather-Station-using-Arduino-UNO-R4-and-MQTT/assets/138108581/3acf2d53-f6f4-477a-a47a-6ae325c9fea1)
1. **New Connection by Importing MongoDB URL**: This interface allows you to create a new connection to a MongoDB server by entering the connection string.
2. **Connection String Field**: Here, you input the MongoDB connection string, which in this case is `mongodb://192.168.0.114:27017/database`.
3. **Buttons and Options**:
   - **Test Connection**: This button tests the connection to the MongoDB server to ensure that the provided connection string is correct.
   - **Create a Deployment**: This option allows you to create a deployment if you do not have an existing one.
   - **OK/Cancel**: These buttons confirm or cancel the setup.

![image (43](https://github.com/FuturisticTechnosphere/Remote-Weather-Station-using-Arduino-UNO-R4-and-MQTT/assets/138108581/49a6944d-c75c-4e0e-a8cf-9b40e5d2236f)
1. **Document Fields**:
   - **_id**: This is the unique identifier for the document.
   - **topic**: This field contains the topic name `/192.168.0.113/env` to which the data is related.
   - **payload**: This is a nested object that includes:
     - **Temperatura**: The temperature value, which is 21.4°C in this example.
     - **Umidità**: The humidity value, which is 64%.
   - **qos**: Quality of Service level for the MQTT message, which is 0 in this case.
   - **retain**: This indicates whether the MQTT message is retained, which is false here.
   - **_msgid**: The message ID associated with this document.

### Summary
- **Setting up MongoDB Connection**: Using the interface shown in Photo 1, you can establish a connection to your MongoDB server by entering the appropriate connection string and verifying it using the "Test Connection" button.
- **Viewing and Managing Data**: Photo 2 demonstrates how you can view and manage the documents stored in your MongoDB database, with detailed information about each field within the documents.

These steps provide a clear guide on how to configure and use MongoDB for storing and accessing data collected from your IoT devices. The connection setup ensures secure and reliable communication with the MongoDB server, while the document view allows for easy data management and monitoring.
