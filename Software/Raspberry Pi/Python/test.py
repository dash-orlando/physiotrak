'''
test
'''

# import modules
'''
    sudo pip install paho-mqtt
'''
import paho.mqtt.client as mqtt
from    time                        import  sleep, clock    # Sleep for stability, clock for profiling
from    time                        import  time            # Time for timing (like duh!)

# setup
# Error handling in case MQTT communcation setup fails (1/2)
try:
    # Setup MQTT
    addr = "192.168.4.1"
    client = mqtt.Client()
    client.max_inflight_messages_set( 60 )                  # Max number of messages that can be part of network flow at once
    client.max_queued_messages_set( 0 )                     # Size 0 == unlimited
    client.will_set( "general", "CONENCTION LOST",          # "Last Will" message. Sent when connection is
                     qos=1, retain=True )                   # ...lost (aka, disconnect was not called)
    client.reconnect_delay_set( min_delay=1, max_delay=2)   # Min/max wait time in case of reconnection

    #client.on_connect = on_connect                          # Assign callback functions
    #client.on_message = on_message                          # ...
    
    client.connect( addr, port=1883, keepalive=60 )         # Connect to MQTT network
    client.loop_start()                                     # Start loop
    sleep( 1.0 )                                            # Allow some time for data to be published

# Error handling in case MQTT communcation setup fails (2/2)
except Exception as e:
    print( "Could NOT setup MQTT communications" )
    print( "Error Type      : {}".format(type(e)))
    print( "Error Arguments : {}".format(e.args) )
    sleep( 1.5 )
    quit()  

