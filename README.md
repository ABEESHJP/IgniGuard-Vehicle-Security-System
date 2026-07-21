# IgniGuard - RFID & GSM Vehicle Security System

An embedded vehicle security system developed using the **LPC2129 ARM7 Microcontroller**. IgniGuard uses **RFID authentication** to control vehicle ignition and **GSM communication** to send SMS alerts during unauthorized access attempts, enhancing vehicle security and theft prevention.

---

## 📌 Features

- 🔐 RFID-based user authentication
- 🚗 Vehicle ignition control
- 🚫 Engine lock for unauthorized users
- 📱 GSM SMS alert notification
- 📟 Real-time status display on 16×2 LCD
- ⚡ Developed using Embedded C on LPC2129

---

## 🛠️ Hardware Components

- LPC2129 ARM7 Microcontroller
- EM-18 RFID Reader
- GSM Module (SIM800/SIM900)
- L293D Motor Driver
- DC Motor (Vehicle Engine Simulation)
- 16×2 LCD Display
- Power Supply

---

## 💻 Software Used

- Embedded C
- Keil uVision
- Flash Magic

---

## ⚙️ Working Principle

1. Power ON the system.
2. LCD displays **"Scan RFID Card"**.
3. EM-18 RFID reader reads the RFID card.
4. LPC2129 compares the scanned RFID with the stored authorized ID.
5. If the card is valid:
   - LCD displays **Access Granted**
   - DC motor starts (Engine ON)
6. If the card is invalid:
   - LCD displays **Access Denied**
   - Engine remains locked
   - GSM module sends an SMS alert to the owner

---

## 📡 Communication

- **UART0 → EM-18 RFID Reader**
- **UART1 → GSM Module**

---

## 📂 Project Structure

```
main.c
lcd_header.h
delay.h
uart0.h
uart1.h
gsm.h
README.md
```

---

## 🚀 Applications

- Smart Vehicle Security
- Anti-Theft Systems
- Fleet Management
- Access Control Systems

---

## 🔮 Future Enhancements

- GPS Tracking
- Mobile App Integration
- Fingerprint Authentication
- Cloud Monitoring
- IoT-Based Vehicle Tracking

---

## 👨‍💻 Author

**JP ABEESH**

Electronics and Communication Engineering (ECE)

Embedded Systems Enthusiast

GitHub: https://github.com/ABEESHJP

---

⭐ If you found this project useful, consider giving it a **Star**.
