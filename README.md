# Arduino Smart Dustbin with Ultrasonic Sensors and LCD

 📖 Overview
An Arduino-based smart dustbin system that uses ultrasonic sensors, a servo motor, and an LCD display to automate waste disposal and monitor bin capacity. The lid opens automatically when someone approaches, while a second sensor measures fill level and displays the remaining capacity percentage on the LCD.

---

 ✨ Features
- Hands-free lid opening using ultrasonic proximity detection  
- Real-time bin capacity monitoring with percentage display  
- LCD interface for user-friendly feedback  
- Servo motor control for automatic lid movement  
- Serial output for debugging and monitoring  

---

 🛠️ Hardware Used
- Arduino Uno (or compatible board)  
- Ultrasonic Sensor HC-SR04 (x2)  
- Servo Motor (SG90 or similar)  
- 16x2 LCD with I2C module  
- Jumper wires and breadboard  
- Power supply  


 ⚙️ Circuit Connections
- **Ultrasonic Sensor 1 (proximity):** Trigger → Pin 10, Echo → Pin 9  
- **Ultrasonic Sensor 2 (capacity):** Trigger → Pin 13, Echo → Pin 12  
- **Servo Motor:** Signal → Pin 3  
- **LCD Display (I2C):** SDA → A4, SCL → A5 (default for Arduino Uno)  

---

 💻 Code Explanation
- **Ultrasonic Sensor 1:** Detects user presence near the bin. If distance ≤ 10 cm, the servo opens the lid.  
- **Ultrasonic Sensor 2:** Measures bin fill level and calculates remaining capacity.  
- **LCD Display:** Shows “Waste Dustbin” and “Volume Level: XX%”.  
- **Servo Motor:** Controls lid position (0° open, 180° closed).  
- **Serial Monitor:** Prints sensor readings for debugging.  

---

 🚀 Future Improvements
- Add IoT integration (Wi-Fi/ESP32) for remote monitoring  
- Mobile app notifications when bin is full  
- Solar-powered system for energy efficiency  
- Voice or gesture control for enhanced usability  
