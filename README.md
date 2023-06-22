# PCF8523 I2C For the Rpi Pico RP2040

A library to support the PCF8523 over I2C when using a pico. Comes with a very basic live test.
Currently, it only supports the bare minimum to get the RTC up and running. 

### Supported features

- [x] Reset
- [x] RTC Start
- [x] Enable battery switchover
- [x] Set datetime
- [x] Get datetime (with trust flag)
- [ ] Alarms
- [ ] Low voltage mode
- [ ] Low battery detection
- [ ] Interupts

### Goals

- Probably support the rest of the features someday. 
- Model check my implementation against an i2c state machine for testing.