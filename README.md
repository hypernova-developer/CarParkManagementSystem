# Car Park Management System

**Developer:** `hypernova-developer`  
**License:** MIT  

## Overview
This project is a **Car Park Management System** built in C++. It allows the management of vehicle entries, exits, and billing in a parking lot. The program handles both billing for parked cars and monitoring the vehicle count in real-time.  

## Features

1. **Secure Access:**  
   - User authentication via a password system.  
   - Only authorized users can operate the system.  

2. **Billing System (Case 1):**  
   - Calculates parking fees based on the time a vehicle stays in the lot:  
     - ≤ 1 hour → Free  
     - 1–2 hours → 5 USD  
     - 2–3 hours → 7 USD  
     - 3–4 hours → 10 USD  
     - 4–5 hours → 15 USD  
     - >5 hours → 20 USD  
   - Saves a record of the vehicle plate and price to `bill.txt`.  

3. **Car Park Management (Case 2):**  
   - Tracks vehicles entering and leaving the car park for each hour of the week (7 days × 24 hours).  
   - Calculates the current number of vehicles inside the parking lot using the formula:  
     ```
     current_count = previous_count + entered - exited
     ```  
   - Monitors capacity and prints warnings:  
     - Full, almost full, half full, quarter full, or empty.  
   - Saves detailed hourly logs to `CarParkManagementSystem.txt`.  

4. **User-Friendly Interface:**  
   - Clear console outputs for real-time monitoring.  
   - Interactive prompts for entering vehicle information.  

## How to Run
1. Compile the C++ code using a compiler that supports Windows libraries (like `g++` or Visual Studio).  
2. Run the executable.
3. You can use the executable file in the repository instead of first and second steps too (Not available in extra language versions of code).
4. Enter the password when prompted.  
5. Choose the program mode:  
   - `1` → Billing system  
   - `2` → Car park management  
   - `3` → Quit
  
## Supported Languages
1. English
2. Türkçe
3. Español
4. Deutsch
5. Français

## Output Files
- `bill.txt` → Stores billing information.  
- `CarParkManagementSystem.txt` → Stores vehicle count and parking lot status.  

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.
