#Integrated Control and distributed lamps

The functional requirements of the system could be the following:
- Allow the lamp to subscribe by entering its ID and the services it performs (intensity control of each color, etc.) to a server, and know when it is already registered on this server. This should allow it to subsequently receive messages with commands.
- Through incoming messages, control the color and the brightness of a lamp LED RGB (using PWM hardware), making these fixed intensities or changing with time
- Through incoming messages, registering a color setting and intensities for each possible user and apply this setting when a user is present (information received via message)
- Allow the received command message, if it is not for this light, to be forwarded to other smart objects

As a non-functional requirements, I think times, mainly:
- To be implemented with EPOS 1.1 on board EposMotesII

I think you need 3 EposMotesII: Two different fixtures to control and to act as a gateway or to indicate the presence of a person.



#Installation

1. After to install EPOS as explained at the first section
[INE5412_EposMotesII_SmartObjects](../), just use our project installer to compile and install your application:
```
./compile_and_install.sh PROGRAM_NAME.cc
```

The './compile_and_install.sh' parameters are:
```
The './compile_and_install.sh' parameters are:
1) The FIRST parameter is the file name to install.
2) The SECOND parameter is the USB port number to install, or the keyword 'notsend' 
   to skip the last part and do not send the application to the EPOSMotes2 board.
3) The THIRD parameter is the optional value clean for a 'make veryclean' all.

Examples:
./compile_and_install.sh PROGRAM_NAME.cc 0 clean
./compile_and_install.sh PROGRAM_NAME.cc notsend
./compile_and_install.sh PROGRAM_NAME.cc 1
```

The 'compile_and_install.sh' is a wrapper which calls the following programs to perform
the program required steps. These steps must to be performed run in following order:
```
REMENBER, run in order these sub-installers:
./_copy.sh    PROGRAM_NAME.cc
./_make.sh    PROGRAM_NAME.cc OPTION_NAME         Use 'clean' as 2nd parameter to perform a make veryclean all.
./_process.sh PROGRAM_NAME.cc
./_install.sh PROGRAM_NAME.cc USB_PORT_NUMBER     If not provided, default is 0. If passed more than 2 parameters,
                                                  to install the program to the RAM memory, instead of the flash
                                                  memory.
```



##Cutecom

Install/use cutecom to read the EPOSMotes2 cout stream output.
To install it, use:
```
sudo apt-get install cutecom
```
To run it, use:
```
sudo cutecom /dev/ttyUSB0 &
```
After open cutecom, click on the open button then press the EPOSMotes2 reset
button, otherwise it will not work, to send commands to the EPOSMotes2
by USB device. As:
```
echo :R100 > /dev/ttyUSB0
```



###Cutecom Configuration

1. Device: /dev/ttyUSB0
1. Baud rate: 9600
1. Data bits: 8
1. Stop bits: 1
1. Parity: None
1. Handshake: (x)Software, (x)Hardware
1. Open for: (x)Reading, (x)Writing, (x)Apply settings when opening

Serial Linux Permissions setserial dialout groups usermod. *Restart you computer to this command to apply.
```
sudo usermod -a -G dialout $USER
```

![Cutecom Config](http://i.imgur.com/w51H2Up.png)



##Course Scheduling

The first step is to get the given functioning codes by the teacher (They only control part of
the system). Some of activities can be performed at the same time. Next steps to get the MotesII
device set up:

1. * 1.1) Control the color and the brightness of a LED RGB lamp, making these fixed
    intensities or changing with time.
   * 1.2) Make the PWM hardware to be fully functional.

1. * 2.1) To allow the lamp (EposMotesII) to receive messages/commands by USB bus.
   * 2.2) To allow the lamp (EposMotesII) to send/receive messages by the radio board to others lamps devices.

2. * 3.1) Make the lamp regularly search for a new server to register and control itself.
   * 3.2) To create a lamp server to register and control and lamps through messages.

3. * 4.1) If the received command message is not for this light, allow it to be forwarded to
    other smart objects.
   * 4.2) Through incoming messages, register color settings and intensities for each possible
    user and apply this setting when that user is present (information received via message).

4. * 5.1) Allow the lamp to subscribe to a server by entering its ID and the services it performs
    (intensity control of each color etc.)
   * 5.2) Allow the lamp to know when it has already been registered on this server. This should
    allow it to subsequently receive messages with commands.

5. * 6.1) Create one device (another EposMotesII device) to indicate the presence of a person.
   * 6.2) Allow the lamps to detect a "person detecting" device proximity.



#####Glossary:

1. A server is another EposMotesII which connected by USB to a computer, which receives commands to
    control its registered lamps (another EposMotesII devices).
2. A person presence indicator is another EposMotesII which communicates with the lamps
    (another EposMotesII).



