---

## Setting Up the Microservice Environment

### Prerequisites

Ensure you have a virtual machine running Ubuntu installed. The following guide assumes you have basic knowledge of using VirtualBox and Ubuntu.

### Step 1: Network Configuration

1. By default, the virtual machine is set up to browse the internet but is not directly accessible to external nodes.
2. Open VirtualBox control panel, select the virtual machine, and click on Settings > Network.
3. Change the network configuration from NAT (Network Address Translator) to "Bridged".
4. Verify that the network interface used matches the one your Host PC (real PC) is using to browse the internet.
5. To check the IP address assigned to the VM, check the network settings using the network settings button at the top right.

### Step 2: Installing SSH

1. Open a terminal in the VM's graphic interface.
2. Install SSH by running the following command:
   ```
   sudo apt install ssh
   ```
3. Verify the installation by connecting via SSH from the Host node using:
   ```
   ssh <username>@pan-ubuntu.local
   ```
   You will be prompted to enter your user password.

### Phase 3: Installing the Environment for Services: Docker

1. Install Docker by running the following commands:
   ```
   sudo apt install docker.io
   mkdir docker
   sudo apt install vim docker-compose
   ```
2. Create a Docker Compose configuration file:
   ```
   vim docker-compose.yml
   ```
3. Inside [docker-compose.yml](communication/network_setup_guide.md), add the configuration for Mosquitto, MongoDB, and Node-Red microservices. 
4. Start the services by running:
   ```
   sudo docker-compose up
   ```

### Exploring the Node-Red Environment and Installing MongoDB Palette

1. Access the Node-Red service on port 1880, MongoDB service on port 27017, and MQTT service on port 1883.
2. To install the MongoDB Palette, visit the following URL: [Node-Red MongoDB Palette](https://flows.nodered.org/node/node-red-node-mongodb).
3. Install the `node-red-node-mongodb v0.2.5` palette.

---

This guide assumes you have a basic understanding of networking concepts, VirtualBox, Ubuntu, and Docker. Please adjust the commands and configurations as needed for your specific environment.
