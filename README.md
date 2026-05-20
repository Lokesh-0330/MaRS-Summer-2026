# MaRS Robotics Club: Summer Tasks 2026

Welcome to my central repository for the 2026 Summer Recruitment Tasks. This space documents my hands-on learning journey across ROS 2 middleware architecture, Linux systems development, and cross-language robotics deployment.

---

## 🛠️ Task 1: ROS 2 Core Architecture & Cross-Language Pipelines

### Installing ROS2
My computer has less storage so i have used wsl instead of dual boot
I have faced issue while installing ROS2 because of some ram issue so with help of AI(gemini). I have installed ROS2 in my WSL 22.04

###Things I have learned 
I have now learned what is node and how they can interact with each other with help of Topics.

I learned that ROS 2 lets us write code in both C++ and Python, but they cannot be mixed in the same folder.

C++ needs to be compiled using a tool called CMake, while Python just runs as a script using standard Python setup tools.
Because their background files are completely different, they need their own separate packages (here we have used my_cpp_pkg and my_py_pkg).

I have learnt some basic CLI commands.

I have leant what is gitignore and why we use it and how to use it.

## 📊 Telemetry and Verification Logs

### 💡 Cross-Language Runtime Verification
Below is the execution log showing the C++ Publisher streaming string sequences dynamically intercepted by the Python Subscriber node simultaneously:
<img width="1358" height="755" alt="image" src="https://github.com/user-attachments/assets/63c0ac7a-c7e6-4af7-8b3f-4da36362d3ef" />


### 🔍 Command Line Diagnostics (CLI Output)

#### Active Node Registration (`ros2 node list`)
Proves both autonomous nodes are successfully allocated inside the graph engine namespace memory:
<img width="728" height="247" alt="image" src="https://github.com/user-attachments/assets/96750d21-3d2b-464b-ae0e-9b6330a09262" />


#### Live Stream Sniffing (`ros2 topic echo /shared_topic`)
Verifies direct topic packet intercepts right from the shell pipeline:
<img width="718" height="240" alt="image" src="https://github.com/user-attachments/assets/1f88cd49-7662-4531-aeb0-c843331e6a8a" />

#### Execution Frequency Analytics (`ros2 topic hz /shared_topic`)
Validates that our wall timer loop functions accurately at the target `2 Hz` loop rate:
<img width="723" height="232" alt="image" src="https://github.com/user-attachments/assets/53636a4c-4ddb-44da-8c3d-ece72eeef9a8" />
