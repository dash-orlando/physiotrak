# physiotrak
Repo. for the development of the physio. tracking project

## Installation
### ESP32 (Arduino)
### Raspberry Pi
-. setup pi as a NAT as in [1]
```
sudo apt-get install dnsmasq hostapd
```
Since the configuration files are not ready yet, turn the new software off as follows:
```
sudo systemctl stop dnsmasq
sudo systemctl stop hostapd
```

1. download mosquitto
2. download mosquitto clients
```
sudo apt-get install mosquitto
sudo apt-get install mosquitto-clients
```


#### References
1. [**Setting up a Raspberry Pi as an access point in a standalone network (NAT)**](https://www.raspberrypi.org/documentation/configuration/wireless/access-point.md)

