'''
mqtt_template

The purpose of this script is to serve as a template
for mqtt implementation within a Pi

Fluvio L Lobo Fenoglietto
02/26/2019
'''

# Import libraries and modules
'''
    sudo pip install paho-mqtt
'''
import paho.mqtt.client             as mqtt
import paho.mqtt.subscribe          as sub
from    time                        import  sleep, clock    # Sleep for stability, clock for profiling
from    time                        import  time            # Time for timing (like duh!)


# FUNCTIONS ============================================================ #

def on_connect( client, userdata, flags, rc):
    if rc == 0:
        print(" Connection Successful!")
    else:
        print(" Connection ERROR = ", rc)

def on_log( client, userdata, level, buff):
    print(" log: " + buff)

def on_message( client, userdata, msg):
    topic = msg.topic
    m_decode = str( msg.payload.decode("utf-8","ignore"))
    print(" Message received: ", m_decode)  

def on_disconnect( client, userdata, flags, rc=0):
    print(" Disconnect result code " + str(rc))

'''
def on_message():
    print("%s, %s" % (message.topic, message.payload) )
'''
# setup
# Error handling in case MQTT communcation setup fails (1/2)
try:
    # Setup MQTT
    addr = "192.168.4.1"
    client = mqtt.Client()
    topic = "test_channel"
    #client.max_inflight_messages_set( 60 )                  # Max number of messages that can be part of network flow at once
    #client.max_queued_messages_set( 0 )                     # Size 0 == unlimited
    #client.will_set( "general", "CONENCTION LOST",          # "Last Will" message. Sent when connection is
    #                 qos=1, retain=True )                   # ...lost (aka, disconnect was not called)
    #client.reconnect_delay_set( min_delay=1, max_delay=2)   # Min/max wait time in case of reconnection

    client.on_connect = on_connect                          # Assign callback functions
    #client.on_log = on_log
    client.on_message = on_message
    client.on_disconnect = on_disconnect
    #client.on_message = on_message                          # ...

    print(" Connecting to Broker...")
    
    client.connect( addr, port=1883, keepalive=60 )         # Connect to MQTT network
    client.loop_start()                                     # Start loop
    client.subscribe(topic)
    sleep( 4.0 )                                            # Allow some time for data to be published

    client.loop_stop()
    client.disconnect()

# Error handling in case MQTT communcation setup fails (2/2)
except Exception as e:
    print( "Could NOT setup MQTT communications" )
    print( "Error Type      : {}".format(type(e)))
    print( "Error Arguments : {}".format(e.args) )
    sleep( 1.5 )
    quit()



