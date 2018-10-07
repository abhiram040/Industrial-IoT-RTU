This project deals with collecting sensor data like humidity, temperature and pressure at various locations in the industry using Remote terminal units(RTU). The sensor data collected at various locations by the RTUs are sent to common IoT gateway. The data at the IoT gateway 
is pushed to cloud using MQTT protocol. The data in the cloud is continiously monitored using mobile phone and the data is also fetched by IoT enabled coolant pumping systems. When the temperature reaches its threshold, the smart pumps turn on automatically and also turn of by themselves so then electricity is saved. In this project prototype, Arduino is used as remote terminal unit and Raspberry Pi is used as common IoT gateway. The data is transfered from rtu to gateway using RS-485 protocol and MODBUS protocol. The data which is monitored in real-time can be used for data analytics. 
