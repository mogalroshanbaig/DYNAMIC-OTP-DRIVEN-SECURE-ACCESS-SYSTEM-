
# 🔐 Dynamic OTP-Driven Secure Access System

## 📘 Overview  
The **Dynamic OTP-Driven Secure Access System** is a secure, GSM-based access control solution built using the **LPC2148 microcontroller**. It enhances traditional authentication by introducing **real-time OTP (One-Time Password)** verification, ensuring restricted access based on time-sensitive authorization. Ideal for use in high-security areas, labs, or personal lockers, this project showcases the integration of embedded systems with wireless communication.

## ✨ Key Features

- 🔑 **Dual-Layer Authentication**  
  - First-level verification via password stored in EEPROM  
  - Second-level verification via OTP sent to registered mobile

- 📲 **Real-Time OTP via GSM**  
  - OTP is generated on successful password entry  
  - Sent via **GSM module** using AT commands  
  - Valid only within a specific time window (RTC-controlled)

- ⏱️ **RTC-Driven Time Validation**  
  - Uses on-chip **Real-Time Clock** to timestamp OTP generation  
  - Automatically invalidates OTP after time expires

- 🔄 **Interrupt-Based Password Update**  
  - External switch (interrupt-driven) allows secure password update  
  - New password is saved to EEPROM only after successful confirmation

- 🔔 **Access Feedback**  
  - LCD clearly displays system status: Waiting, OTP Sent, Access Granted, or Error  
  - Buzzer and LED can be optionally used for success/failure indicators

- 🚫 **Robust Error Handling**  
  - GSM command acknowledgements checked before proceeding  
  - Invalid password, incorrect OTP, or timeout → Access denied

## 🧰 Technologies Used

| Component          | Description                                 |
|--------------------|---------------------------------------------|
| **Microcontroller**| LPC2148 ARM7                                |
| **Communication**  | GSM Module (M660A), UART (Interrupt-Driven) |
| **Storage**        | AT24C256 EEPROM via I2C                     |
| **Display**        | 16x2 Alphanumeric LCD                       |
| **Input**          | 4x4 Matrix Keypad, Pushbuttons              |
| **Output**         | DC Motor / Bulb (via L293D), LED, Buzzer    |
| **Languages**      | Embedded C                                  |
| **IDE/Tools**      | KEIL uVision, Flash Magic, Proteus          |

![WhatsApp Image 2025-07-29 at 9 13 23 PM](https://github.com/user-attachments/assets/c718d9da-2f0c-4bb0-9139-d27f9520f34d)


## 🚀 How It Works

1. **System Idle**: Awaits user password input via keypad  
2. **Password Validation**:  
   - Compares input with EEPROM-stored password  
   - On success → Proceeds to OTP generation  
3. **OTP Generation**:  
   - OTP generated and sent via GSM module  
   - OTP timestamp recorded using RTC  
4. **OTP Verification**:  
   - User must input OTP within valid time window  
   - Correct OTP → Access granted (e.g., motor unlocked)  
   - Wrong or late OTP → System resets  
5. **Password Change (Optional)**:  
   - Triggered via external interrupt  
   - Old password verification required  
   - New password stored in EEPROM after confirmation

## 🛠️ Setup & Requirements

### 🔧 Hardware
- LPC2148 Microcontroller Board  
- GSM Module (SIM800/660A)  
- 16x2 LCD Display  
- 4x4 Matrix Keypad  
- AT24C256 EEPROM  
- Pushbuttons (for menu and interrupt)  
- L293D Motor Driver + DC Motor / LED  
- Buzzer (optional)
- Power Supply + Common Ground

### 💻 Software
- KEIL uVision (Code Development)  
- Flash Magic (Hex Uploading)  

## 📡 AT Commands Reference (Sample)

| Command             | Purpose                          |
|---------------------|----------------------------------|
| `AT`                | Test GSM response                |
| `ATE0`              | Disable command echo             |
| `AT+CMGF=1`         | Set SMS mode to text             |
| `AT+CMGS="Number"`  | Send SMS (followed by OTP)       |

## ✅ Final Output

- LCD displays system prompts and messages  
- OTP is sent to phone and verified in real-time  
- Buzzer/LED indicates access status  
- Motor or bulb activates upon successful authentication  
- Secure password change supported via interrupt button  
