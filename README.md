<h1 align="center">Steganography Assembly Coder-Decoder</h1>

<p align="center">
  <a href="#overview">Overview</a> •
  <a href="#features">Features</a> •
  <a href="#screenshots">Screenshots</a> •
  <a href="#system-design">System Design</a> •
  <a href="#license">License</a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/License-MIT-yellow.svg" />
  <img src="https://img.shields.io/badge/Author-SmartMatt-blue" />
</p>

## Overview
Sophisticated application designed for steganography, capable of encrypting text into BMP images and decrypting text from these images. It leverages the power of multi-threading and offers a choice between C++ and Assembly (ASM) algorithms, ensuring efficient and speedy processing.

## Features
- **Image Encryption**: Encrypt text (from .txt files) into BMP images.
- **Image Decryption**: Decrypt text hidden in BMP images, saving the output in .txt format.
- **Customizable Algorithms**: Choose between C++ or ASM for encryption and decryption algorithms.
- **Multi-threading Support**: Utilize multiple processor threads for faster execution.
- **Performance Optimization**: Configure thread count and algorithm for optimal performance.
- **Execution Time Display**: After each operation, the time taken is displayed.

## Screenshots
![GUI](https://smartmatt.pl/github/steganography-coder-decoder/steganography-gui.png)
</br>*Presentation of main panel of application.*

![Modes](https://smartmatt.pl/github/steganography-coder-decoder/steganography-modes.png)
</br>*Application allows you to encrypt and describe text from a photo.*

![Encryption](https://smartmatt.pl/github/steganography-coder-decoder/steganography-encryption.png)
</br>*Diagram of the operation of the text-to-image coding mode.*

![Decryption](https://smartmatt.pl/github/steganography-coder-decoder/steganography-decryption.png)
</br>*Diagram of the operation of the image-to-text coding mode.*

## System Design
- Developed for Windows operating system.
- Utilizes CLR for GUI development and system.threading.thread for multi-threading.

### Codebase
- **Primary Languages**: C++, C, and Assembly (with MMX).
- **Interface**: C++ with CLR (Common Language Runtime).

### Repository Contents
- Complete source code with all dependencies.
- Pre-built version of the application in the `Build` directory.
- Detailed instructions for setting up and running the application.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
&copy; 2023 Mateusz Płonka (SmartMatt). All rights reserved.
<a href="https://smartmatt.pl/">
    <img src="https://smartmatt.pl/github/smartmatt-logo.png" title="SmartMatt Logo" align="right" width="60" />
</a>

<p align="left">
  <a href="https://smartmatt.pl/">Portfolio</a> •
  <a href="https://github.com/SmartMaatt">GitHub</a> •
  <a href="https://www.linkedin.com/in/mateusz-p%C5%82onka-328a48214/">LinkedIn</a> •
  <a href="https://www.youtube.com/user/SmartHDesigner">YouTube</a> •
  <a href="https://www.tiktok.com/@smartmaatt">TikTok</a>
</p>
