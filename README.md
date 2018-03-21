# Garagebot

An internet connected, open source, garage door opener

## Usage

### Hardware requirements:
- Particle Photon
- Particle RelayShield
- 4 wires (2 x 2ft, 2 x 30 ft)
- 12V Power Supply - 1A
- Reed Switch (magnetic)

### Flash the Photon

1. Go to the release section of this repo: https://github.com/alan707/garagebot/releases
2. Download the pre-compiled firmware of the latest release available
3. Connect Photon to your computer via USB
4. Hold down the _setup_ button until it blinks blue
4. From the command line run:
```sh
cd ~/path-to-your-directory/garagebot
particle flash --usb photon_firmware_1517971714989.bin 
```

#### ```/src``` folder:  
This is the source folder that contains the all the key files for your project. It should *not* be renamed. Anything that is in this folder when you compile your project will be sent to Particle's compile service and compiled into a firmware binary for the Particle device that you have targeted.

#### ```.ino``` file:
This file is the firmware that will run as the primary application on your Particle device. It contains a `setup()` and `loop()` function, and can be written in Wiring or C/C++. For more information about using the Particle firmware API to create firmware for your Particle device, refer to the [Firmware Reference](https://docs.particle.io/reference/firmware/) section of the Particle documentation.

#### ```project.properties``` file:  
This is the file that specifies the name and version number of the libraries that your project depends on. Dependencies are added automatically to your `project.properties` file when you add a library to a project using the `particle library add` command in the CLI or add a library in the Desktop IDE.

### Compiling this project

If you make any changes to this project, make sure you start the compilation at the root of the directory (i.e. garagebot). 
