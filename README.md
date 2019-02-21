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
To ensure that an updated kernel is configured correctly after install, reboot:
```
sudo reboot
```
#### Configuring a Static IP
We are configuring a standalone network to act as a server, so the Raspberry Pi needs to have a static IP address assigned to the wireless port. This documentation assumes that we are using the standard 192.168.x.x IP addresses for our wireless network, so we will assign the server the IP address 192.168.4.1. It is also assumed that the wireless device being used is `wlan0`

To configure the static IP address, edit the dhcpcd configuration file with:
```
sudo nano /etc/dhcpcd.conf
```
Go to the end of the file and edit it so that it looks like the following:
```
interface wlan0
    static ip_address=192.168.4.1/24
    nohook wpa_supplicant
```
Now restart the dhcpcd daemon and set up the new `wlan0` configuration:
```
sudo service dhcpcd restart
```
#### Configuring the DHCP server (dnsmasq)
The DHCP service is provided by dnsmasq. By default, the configuration file contains a lot of information that is not needed, and it is easier to start from scratch. Rename this configuration file, and edit a new one:
```
sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.orig  
sudo nano /etc/dnsmasq.conf
```
Type or copy the following information into the dnsmasq configuration file and save it:
```
interface=wlan0      # Use the require wireless interface - usually wlan0
  dhcp-range=192.168.4.2,192.168.4.20,255.255.255.0,24h
```
So for `wlan0`, we are going to provide IP addresses between 192.168.4.2 and 192.168.4.20, with a lease time of 24 hours. If you are providing DHCP services for other network devices (e.g. eth0), you could add more sections with the appropriate interface header, with the range of addresses you intend to provide to that interface.


1. download mosquitto
2. download mosquitto clients
```
sudo apt-get install mosquitto
sudo apt-get install mosquitto-clients
```


#### References
1. [**Setting up a Raspberry Pi as an access point in a standalone network (NAT)**](https://www.raspberrypi.org/documentation/configuration/wireless/access-point.md)

