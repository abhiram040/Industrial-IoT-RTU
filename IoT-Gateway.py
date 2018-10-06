import paho.mqtt.client as mqtt
import time
import serial

humidity = ''
temperature = ''
coolant_temp = ''

ser = serial.Serial(
    
    port='/dev/ttyUSB0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=3
    )
while 1:
        x=ser.readline().decode('ascii')
        #print(x)
        t=[]
        h=[]
        ct=[]
        index=0
        for c in x:
                if c!=':':
                       ct.append(c)
                       index=index+1
                else:
                       coolant_temp=''.join(ct)
                       print('Coolant Temperature = ' + coolant_temp)
                       break
                
        
        y=x[index+1:]
        for c in y:
                if c!= ':':
                        h.append(c)
                        index=index+1
                        
                else:
                        humidity=''.join(h)
                        print('Humidity = ' + humidity)
                        break
        #print('Index:' + str(index))
        z=x[index+1:]
        
        z=z[1:]
        
        for c in z:
                if c!= ':':
                        t.append(c)
                        #index=index+1
                        
                else:
                        temperature=''.join(t)
                        print('Temperature = ' + temperature)
                        break
        #print('Index:' + str(index))
        #print(z)

                        
        client=mqtt.Client()
        client.username_pw_set("qspuplfk","k7PCbGMopLrk")
        client.connect("m13.cloudmqtt.com",11973,60)
        client.publish("ct",coolant_temp)
        client.publish("h",humidity)
        client.publish("t",temperature)
        time.sleep(1)