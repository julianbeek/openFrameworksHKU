#include "ofApp.h"

#define PIN_LED 12
#define PIN 13
#define PIN_BUTTON 2
#define PIN_POTMETER 0

void ofApp::setup() {
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("/dev/tty.usbmodem1421");
    arduino.sendFirmwareVersionRequest(); // workaround for ofArduino/firmata bug
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
}

void ofApp::update() {
    arduino.update();
}

void ofApp::draw() {
}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // print firmware name and version to the console
    ofLogNotice() << "Arduino firmware found: " << arduino.getFirmwareName()
                  << " v" << arduino.getMajorFirmwareVersion() << "."  << arduino.getMinorFirmwareVersion();

    arduino.sendDigitalPinMode(PIN_LED, ARD_OUTPUT);
    arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
    arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);

    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
    ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
    ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
}


void ofApp::mousePressed(int x, int y, int button) {
    // switch the LED on
    arduino.sendDigital(PIN, ARD_HIGH);
}

void ofApp::mouseReleased(int x, int y, int button) {
    // switch the LED off
    arduino.sendDigital(PIN, ARD_LOW);
}
