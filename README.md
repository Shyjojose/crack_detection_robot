# crack_detection_robot
Railway Track Crack Detection System
Overview
This project is an IoT-based system designed to detect cracks and obstacles on railway tracks. It uses ultrasonic sensors, infrared (IR) sensors, and a GSM module to monitor the tracks in real-time. When a crack or obstacle is detected, the system sends an SMS alert to a predefined mobile number and displays the information on an LCD screen. The system also includes a motor control mechanism to stop the movement of the railway inspection vehicle upon detection of any anomalies.

Features
Ultrasonic Sensor: Detects obstacles on the railway tracks.

Infrared (IR) Sensors: Detect cracks on the left and right sides of the railway tracks.

GSM Module: Sends SMS alerts to a predefined mobile number when a crack or obstacle is detected.

LCD Display: Displays real-time information about the system status, and detected cracks, and obstacles.

Motor Control: Controls the movement of the railway inspection vehicle (forward and reverse).

Buzzer: Alerts the operator with a sound when a crack or obstacle is detected.

Hardware Components
Arduino Uno: The main microcontroller unit.

Ultrasonic Sensor (HC-SR04): For obstacle detection.

Infrared (IR) Sensors: For crack detection.

GSM Module (SIM800L): For sending SMS alerts.

Liquid Crystal Display (LCD): For displaying system status and alerts.

Relay Modules: For controlling the motors.

Buzzer: For audible alerts.

Push Buttons: For manual control of the vehicle (forward, reverse, and start).

Software Components
Arduino IDE: For programming the Arduino Uno.

LiquidCrystal Library: For interfacing with the LCD display.

GSM Library: For sending SMS alerts via the GSM module.

Setup Instructions
Hardware Setup:

Connect the ultrasonic sensor to pins A4 (echo) and A5 (trigger).

Connect the IR sensors to pins 8 and 9.

Connect the GSM module to the Arduino's serial pins (TX, RX).

Connect the LCD display to pins 2, 3, 4, 5, 6, and 7.

Connect the relay modules to pins 10, 11, 12, and 13.

Connect the buzzer to pin A0.

Connect the push buttons to pins A1, A2, and A3.

Software Setup:

Install the Arduino IDE on your computer.

Install the necessary libraries (LiquidCrystal, GSM).

Upload the provided code to the Arduino Uno.

Operation:

Power on the system.

The LCD will display "RAILWAY TRACK CRACK DETECTION" and initialize the GSM module.

Press the appropriate push button to start the vehicle's movement (forward or reverse).

The system will continuously monitor the tracks for cracks and obstacles.

If a crack or obstacle is detected, the system will stop the vehicle, activate the buzzer, and send an SMS alert.

Code Overview
Initialization: The system initializes the GSM module, LCD display, and sensors.

Main Loop: The system continuously checks the status of the sensors and controls the vehicle's movement based on the input from the push buttons.

Obstacle Detection: The ultrasonic sensor measures the distance to any obstacle. If an obstacle is detected within a certain range, the system stops the vehicle and sends an SMS alert.

Crack Detection: The IR sensors detect cracks on the tracks. If a crack is detected, the system stops the vehicle, activates the buzzer, and sends an SMS alert.

Future Enhancements
GPS Integration: Add GPS functionality to provide the exact location of the detected crack or obstacle.

Cloud Integration: Send sensor data to a cloud platform for real-time monitoring and analysis.

Automated Reporting: Generate automated reports based on the detected anomalies for maintenance purposes.

Conclusion
This IoT-based railway track crack detection system provides a reliable and efficient solution for monitoring railway tracks. By integrating various sensors and a GSM module, the system ensures timely detection and alerting of any anomalies, thereby enhancing the safety and maintenance of railway infrastructure.

Note: Replace the placeholder mobile number +91.........8 in the code with the actual mobile number where you want to receive the SMS alerts.
